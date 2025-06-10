/* Домашняя работа№6. Вариант 18 
Тема: визуальная разработка приложения на основе Windows Forms 
1. Опишите управляемый класс «Функция». Пусть функция может быть линейной  y=a 
x+b или квадратичной y=a x2+b x+c. 
Данные класса: 
аргумент, параметры, значение функции. 
Свойства property класса: 
обеспечивают доступ к закрытым данным.  
Конструкторы класса: 
конструктор функции по умолчанию y=x, конструктор функции вида y=a*x+b, кон
структор функции вида y=a*x2+b*x+c. 
2. Определите методы: 
определение корректности данных, определение значения функции, получение таблицы 
значений функции в указанном диапазоне.  
3. Опишите дескриптор объекта в классе формы и создайте объект по умолчанию в кон
структоре формы. 
4. Добавьте на форму текстовые поля для визуализации данных объекта. При открытии 
формы в полях должны отображаться данные объекта по умолчанию. 
5. Добавьте кнопки для управления вводом значений (кнопка «Присвоить») и выводом 
(кнопка «Показать»), напишите обработчики событий кнопок. Изменение значений полей 
объекта должно отражаться на форме. 
6. Напишите методы KeyDown для текстовых полей, позволяющие ввести данные, минуя 
кнопку «Присвоить».  */

#include "MyForm.h"
#include "Function.h"
#include <cliext\utility>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Globalization;

namespace SuperPoint
{

    /* ----------  ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ  ---------- */

    void MyForm::txt_KeyPress(Object^ sender, KeyPressEventArgs^ e)
    {
        TextBox^ tb = safe_cast<TextBox^>(sender);

        // Разрешаем только: цифры, Backspace, минус, точку и запятую
        bool isDigit = Char::IsDigit(e->KeyChar);
        bool isControl = Char::IsControl(e->KeyChar);   // например Backspace
        bool isMinusAt0 = e->KeyChar == '-' && tb->SelectionStart == 0 && !tb->Text->Contains("-");
        bool isSeparator = (e->KeyChar == '.' || e->KeyChar == ',') &&
            !tb->Text->Contains(".") && !tb->Text->Contains(",");

        if (!(isDigit || isControl || isMinusAt0 || isSeparator))
        {
            e->Handled = true;  // отбрасываем любой другой символ
        }
    }




    void MyForm::ResetErrors()
    {
        this->errorProvider1->Clear();
    }

    bool MyForm::ParseDouble(TextBox^ tb, double% value, String^ fieldName)
    {
        // Заменяем все точки на запятые, чтобы работало в русской культуре
        String^ text = tb->Text->Replace('.', ',');

        // Пробуем распарсить с учётом текущей культуры
        if (Double::TryParse(text, NumberStyles::Float, CultureInfo::CurrentCulture, value))
            return true;

        // Ещё пробуем в InvariantCulture (на случай, если пользователь всё же ввёл точку)
        if (Double::TryParse(tb->Text, NumberStyles::Float, CultureInfo::InvariantCulture, value))
            return true;

        this->errorProvider1->SetError(tb, fieldName + " должно быть числом");
        return false;
    }

    void MyForm::ShowFieldsForRange(bool on)
    {
        // From / To / Step
        this->txtFrom->Visible = on;
        this->txtTo->Visible = on;
        this->txtStep->Visible = on;
        this->label4->Visible = on;
        this->label5->Visible = on;
        this->label6->Visible = on;
        // одиночный X
        this->txtX->Visible = !on;
        this->label7->Visible = !on;

        // Прячем или показываем метку результата
        this->lblResult->Visible = !on;

        // Прячем таблицу
        this->dgvTable->Visible = false;
    }


    void MyForm::FillControlsFromFunction()
    {
        this->txtA->Text = this->f->A.ToString();
        this->txtB->Text = this->f->B.ToString();
        this->txtC->Text = this->f->C.ToString();

        this->txtX->Text = "0";
        this->txtFrom->Text = "-5";
        this->txtTo->Text = "5";
        this->txtStep->Text = "1";
    }

    /* ----------  ОБРАБОТЧИКИ  ---------- */

    void MyForm::rbFunction_CheckedChanged(Object^, EventArgs^)
    {
        bool quad = this->rbQuadratic->Checked;
        this->txtC->Enabled = quad;
        if (!quad) this->errorProvider1->SetError(this->txtC, "");
    }

    void MyForm::chkRange_CheckedChanged(Object^, EventArgs^)
    {
        this->rangeMode = this->chkRange->Checked;
        this->ShowFieldsForRange(this->rangeMode);
    }

    void MyForm::txt_TextChanged(Object^ sender, EventArgs^)
    {
        TextBox^ tb = safe_cast<TextBox^>(sender);
        this->errorProvider1->SetError(tb, "");
    }

    void MyForm::txt_KeyDown(Object^, KeyEventArgs^ e)
    {
        if (e->KeyCode == Keys::Enter)
            this->btnCompute_Click(nullptr, nullptr);
    }

    void MyForm::btnCompute_Click(Object^, EventArgs^)
    {
        this->ResetErrors();

        double a = 0, b = 0, c = 0;
        if (!this->ParseDouble(this->txtA, a, "A") ||
            !this->ParseDouble(this->txtB, b, "B") ||
            (this->rbQuadratic->Checked && !this->ParseDouble(this->txtC, c, "C")))
            return;

        // создаём/обновляем объект функции
        this->f = this->rbQuadratic->Checked ? gcnew Function(a, b, c)
            : gcnew Function(a, b);

        if (!this->rangeMode)   // одиночное x
        {
            double x = 0;
            if (!this->ParseDouble(this->txtX, x, "X")) return;

            this->lblResult->Text = "y = " + this->f->Value(x).ToString();
            this->dgvTable->Visible = false;
        }
        else                    // диапазон
        {
            double xFrom = 0, xTo = 0, xStep = 0;
            if (!this->ParseDouble(this->txtFrom, xFrom, "От") ||
                !this->ParseDouble(this->txtTo, xTo, "До") ||
                !this->ParseDouble(this->txtStep, xStep, "Шаг"))
                return;

            if (xStep <= 0)
            {
                this->errorProvider1->SetError(this->txtStep, "Шаг должен быть > 0");
                return;
            }
            if (xFrom > xTo)
            {
                this->errorProvider1->SetError(this->txtFrom, "Начало должно быть <= концу");
                return;
            }

            this->dgvTable->DataSource = this->f->GetTable(xFrom, xTo, xStep);
            this->dgvTable->Visible = true;
            this->lblResult->Text = "y =";
        }
    }

} // конец namespace SuperPoint

/* ----------  Точка входа приложения  ---------- */
[STAThread]
void Main(array<String^>^)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    SuperPoint::MyForm form;
    Application::Run(% form);

}