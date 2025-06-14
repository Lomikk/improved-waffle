# Task
Введение в визуальное проектирование на основе шаблона Windows Forms
В работе необходимо
1. Создать проект на основе Windows Forms.
2. Описать собственный объект.
Объект должен иметь свойства properties, чтобы открыть данные.
Объект должен иметь метод ToString() для вывода полей.
3. Внедрить объект в приложение:
в области данных формы объявить дескриптор объекта;
в конструкторе формы распределить память для объекта утилитой gcnew.
3. На форме должны быть метки с Text-ами, содержащими пояснения по смыслу выводимой информации, текстовые поля для ввода и вывода данных объекта. Для управления
вводом и выводом − две кнопки с надписями «Присвоить» и «Показать». Выровнять все элементы управления и применить единообразное оформление.
4. Написать управление объектом из модуля формы. Здесь интерфейс зависит от задачи.
Минимальная функциональность, это ввод значений полей и присваивание их объекту, а также вывод объекта на форму. Соответственно, должны быть обработчики событий кнопок
«Присвоить» и «Показать», и обработчики KeyDown текстовых полей, в которых вводятся данные.
Проверять содержимое полей при вводе: если в поле пусто, то значение свойства должно
быть равно 0. Для кнопки «Показать» добавить на форму текстовое поле, в которое выводить значение объекта с использованием метода ToString().
Чтобы при вводе данных в поля пересылать их объекту, минуя кнопку «Присвоить», написать обработчики события KeyDown текстовых полей. Параметр ^ e позволит определить код нажатой клавиши. Если e->KeyValue = = 13 (нажата Enter), то выполняются действия, как для кнопки «Присвоить».
Работа с приложением должна быть удобной, поэтому объект должен активно реагировать на события, которые возникают на форме.
Бонус. Можно использовать иллюстрации, размещая подходящие картинки в PictureBo-xах.


Условие:
1. Опишите управляемый класс «Функция». Пусть функция может быть линейной y=ax+b или квадратичной y=a x2+b x+c.
Данные класса:
аргумент, параметры, значение функции.
Свойства property класса:
обеспечивают доступ к закрытым данным.
Конструкторы класса:
конструктор функции по умолчанию y=x, конструктор функции вида y=a*x+b, конструктор функции вида y=a*x2+b*x+c.
2. Определите методы:
определение корректности данных, определение значения функции, получение таблицы значений функции в указанном диапазоне.
3. Опишите дескриптор объекта в классе формы и создайте объект по умолчанию в конструкторе формы.
4. Добавьте на форму текстовые поля для визуализации данных объекта. При открытии формы в полях должны отображаться данные объекта по умолчанию.
5. Добавьте кнопки для управления вводом значений (кнопка «Присвоить») и выводом (кнопка «Показать»), напишите обработчики событий кнопок. Изменение значений полей объекта должно отражаться на форме.
6. Напишите методы KeyDown для текстовых полей, позволяющие ввести данные, минуя кнопку «Присвоить».

Ps.
Поля ввода только для ввода, не редактировать программно.
Для визуализации объекта отдельное поле.
Верифицировать поля ввода так:
if (String::IsNullOrEmpty(tbox1->Text) || !(Int32::TryParse(tbox1->Text, x)))
На Form_Load уже вывести, если есть.
Обновлять вывод при любом изменении.
Хорошо, если для визуализации написать отдельный метод класса формы.
