#pragma once
#include "Function.h"
namespace SuperPoint
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class MyForm : public Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            f = gcnew Function();
            FillControlsFromFunction();
            ShowFieldsForRange(false);
        }

    protected:
        ~MyForm()
        {
            if (components) delete components;
        }
    private: System::Windows::Forms::GroupBox^ groupBoxFunctionType;
    protected:

    private: System::Windows::Forms::RadioButton^ rbQuadratic;
    protected:

    private: System::Windows::Forms::RadioButton^ rbLinear;
    private: System::Windows::Forms::GroupBox^ groupBoxCoeffs;
    private: System::Windows::Forms::TextBox^ txtA;


    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ txtB;
    private: System::Windows::Forms::TextBox^ txtC;


    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::GroupBox^ groupBoxArg;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::CheckBox^ chkRange;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::TextBox^ txtStep;
    private: System::Windows::Forms::TextBox^ txtTo;
    private: System::Windows::Forms::TextBox^ txtFrom;
    private: System::Windows::Forms::TextBox^ txtX;
    private: System::Windows::Forms::Button^ btnCompute;
    private: System::Windows::Forms::Label^ lblResult;
    private: System::Windows::Forms::DataGridView^ dgvTable;
    private: System::Windows::Forms::ErrorProvider^ errorProvider1;
    private: System::ComponentModel::IContainer^ components;

    Function^ f;               // объект функции
    bool rangeMode = false;    // режим таблицы
    void ResetErrors();        // очистка errorProvider
    bool ParseDouble(TextBox^ tb, double% value, String^ fieldName);
    void ShowFieldsForRange(bool on);
    void FillControlsFromFunction();



    private:


        // ───────── Designer ─────────
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->groupBoxFunctionType = (gcnew System::Windows::Forms::GroupBox());
            this->rbQuadratic = (gcnew System::Windows::Forms::RadioButton());
            this->rbLinear = (gcnew System::Windows::Forms::RadioButton());
            this->groupBoxCoeffs = (gcnew System::Windows::Forms::GroupBox());
            this->txtC = (gcnew System::Windows::Forms::TextBox());
            this->txtB = (gcnew System::Windows::Forms::TextBox());
            this->txtA = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->groupBoxArg = (gcnew System::Windows::Forms::GroupBox());
            this->chkRange = (gcnew System::Windows::Forms::CheckBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->txtStep = (gcnew System::Windows::Forms::TextBox());
            this->txtTo = (gcnew System::Windows::Forms::TextBox());
            this->txtFrom = (gcnew System::Windows::Forms::TextBox());
            this->txtX = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->btnCompute = (gcnew System::Windows::Forms::Button());
            this->lblResult = (gcnew System::Windows::Forms::Label());
            this->dgvTable = (gcnew System::Windows::Forms::DataGridView());
            this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
            this->groupBoxFunctionType->SuspendLayout();
            this->groupBoxCoeffs->SuspendLayout();
            this->groupBoxArg->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTable))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
            this->SuspendLayout();
            // 
            // groupBoxFunctionType
            // 
            resources->ApplyResources(this->groupBoxFunctionType, L"groupBoxFunctionType");
            this->groupBoxFunctionType->Controls->Add(this->rbQuadratic);
            this->groupBoxFunctionType->Controls->Add(this->rbLinear);
            this->errorProvider1->SetError(this->groupBoxFunctionType, resources->GetString(L"groupBoxFunctionType.Error"));
            this->errorProvider1->SetIconAlignment(this->groupBoxFunctionType, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"groupBoxFunctionType.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->groupBoxFunctionType, (cli::safe_cast<System::Int32>(resources->GetObject(L"groupBoxFunctionType.IconPadding"))));
            this->groupBoxFunctionType->Name = L"groupBoxFunctionType";
            this->groupBoxFunctionType->TabStop = false;
            // 
            // rbQuadratic
            // 
            resources->ApplyResources(this->rbQuadratic, L"rbQuadratic");
            this->errorProvider1->SetError(this->rbQuadratic, resources->GetString(L"rbQuadratic.Error"));
            this->errorProvider1->SetIconAlignment(this->rbQuadratic, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"rbQuadratic.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->rbQuadratic, (cli::safe_cast<System::Int32>(resources->GetObject(L"rbQuadratic.IconPadding"))));
            this->rbQuadratic->Name = L"rbQuadratic";
            this->rbQuadratic->UseVisualStyleBackColor = true;
            this->rbQuadratic->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbFunction_CheckedChanged);
            // 
            // rbLinear
            // 
            resources->ApplyResources(this->rbLinear, L"rbLinear");
            this->rbLinear->Checked = true;
            this->errorProvider1->SetError(this->rbLinear, resources->GetString(L"rbLinear.Error"));
            this->errorProvider1->SetIconAlignment(this->rbLinear, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"rbLinear.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->rbLinear, (cli::safe_cast<System::Int32>(resources->GetObject(L"rbLinear.IconPadding"))));
            this->rbLinear->Name = L"rbLinear";
            this->rbLinear->TabStop = true;
            this->rbLinear->UseVisualStyleBackColor = true;
            this->rbLinear->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbFunction_CheckedChanged);
            // 
            // groupBoxCoeffs
            // 
            resources->ApplyResources(this->groupBoxCoeffs, L"groupBoxCoeffs");
            this->groupBoxCoeffs->Controls->Add(this->txtC);
            this->groupBoxCoeffs->Controls->Add(this->txtB);
            this->groupBoxCoeffs->Controls->Add(this->txtA);
            this->groupBoxCoeffs->Controls->Add(this->label3);
            this->groupBoxCoeffs->Controls->Add(this->label2);
            this->groupBoxCoeffs->Controls->Add(this->label1);
            this->errorProvider1->SetError(this->groupBoxCoeffs, resources->GetString(L"groupBoxCoeffs.Error"));
            this->errorProvider1->SetIconAlignment(this->groupBoxCoeffs, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"groupBoxCoeffs.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->groupBoxCoeffs, (cli::safe_cast<System::Int32>(resources->GetObject(L"groupBoxCoeffs.IconPadding"))));
            this->groupBoxCoeffs->Name = L"groupBoxCoeffs";
            this->groupBoxCoeffs->TabStop = false;
            this->groupBoxCoeffs->Enter += gcnew System::EventHandler(this, &MyForm::groupBoxCoeffs_Enter);
            // 
            // txtC
            // 
            resources->ApplyResources(this->txtC, L"txtC");
            this->errorProvider1->SetError(this->txtC, resources->GetString(L"txtC.Error"));
            this->errorProvider1->SetIconAlignment(this->txtC, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"txtC.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->txtC, (cli::safe_cast<System::Int32>(resources->GetObject(L"txtC.IconPadding"))));
            this->txtC->Name = L"txtC";
            this->txtC->ShortcutsEnabled = false;
            this->txtC->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_TextChanged);
            this->txtC->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::txt_KeyDown);
            this->txtC->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txt_KeyPress);
            // 
            // txtB
            // 
            resources->ApplyResources(this->txtB, L"txtB");
            this->errorProvider1->SetError(this->txtB, resources->GetString(L"txtB.Error"));
            this->errorProvider1->SetIconAlignment(this->txtB, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"txtB.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->txtB, (cli::safe_cast<System::Int32>(resources->GetObject(L"txtB.IconPadding"))));
            this->txtB->Name = L"txtB";
            this->txtB->ShortcutsEnabled = false;
            this->txtB->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_TextChanged);
            this->txtB->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::txt_KeyDown);
            this->txtB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txt_KeyPress);
            // 
            // txtA
            // 
            resources->ApplyResources(this->txtA, L"txtA");
            this->errorProvider1->SetError(this->txtA, resources->GetString(L"txtA.Error"));
            this->errorProvider1->SetIconAlignment(this->txtA, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"txtA.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->txtA, (cli::safe_cast<System::Int32>(resources->GetObject(L"txtA.IconPadding"))));
            this->txtA->Name = L"txtA";
            this->txtA->ShortcutsEnabled = false;
            this->txtA->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_TextChanged);
            this->txtA->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::txt_KeyDown);
            this->txtA->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txt_KeyPress);
            // 
            // label3
            // 
            resources->ApplyResources(this->label3, L"label3");
            this->errorProvider1->SetError(this->label3, resources->GetString(L"label3.Error"));
            this->errorProvider1->SetIconAlignment(this->label3, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"label3.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->label3, (cli::safe_cast<System::Int32>(resources->GetObject(L"label3.IconPadding"))));
            this->label3->Name = L"label3";
            this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
            // 
            // label2
            // 
            resources->ApplyResources(this->label2, L"label2");
            this->errorProvider1->SetError(this->label2, resources->GetString(L"label2.Error"));
            this->errorProvider1->SetIconAlignment(this->label2, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"label2.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->label2, (cli::safe_cast<System::Int32>(resources->GetObject(L"label2.IconPadding"))));
            this->label2->Name = L"label2";
            // 
            // label1
            // 
            resources->ApplyResources(this->label1, L"label1");
            this->errorProvider1->SetError(this->label1, resources->GetString(L"label1.Error"));
            this->errorProvider1->SetIconAlignment(this->label1, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"label1.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->label1, (cli::safe_cast<System::Int32>(resources->GetObject(L"label1.IconPadding"))));
            this->label1->Name = L"label1";
            // 
            // groupBoxArg
            // 
            resources->ApplyResources(this->groupBoxArg, L"groupBoxArg");
            this->groupBoxArg->Controls->Add(this->chkRange);
            this->groupBoxArg->Controls->Add(this->label6);
            this->groupBoxArg->Controls->Add(this->txtStep);
            this->groupBoxArg->Controls->Add(this->txtTo);
            this->groupBoxArg->Controls->Add(this->txtFrom);
            this->groupBoxArg->Controls->Add(this->txtX);
            this->groupBoxArg->Controls->Add(this->label5);
            this->groupBoxArg->Controls->Add(this->label7);
            this->groupBoxArg->Controls->Add(this->label4);
            this->errorProvider1->SetError(this->groupBoxArg, resources->GetString(L"groupBoxArg.Error"));
            this->errorProvider1->SetIconAlignment(this->groupBoxArg, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"groupBoxArg.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->groupBoxArg, (cli::safe_cast<System::Int32>(resources->GetObject(L"groupBoxArg.IconPadding"))));
            this->groupBoxArg->Name = L"groupBoxArg";
            this->groupBoxArg->TabStop = false;
            this->groupBoxArg->Enter += gcnew System::EventHandler(this, &MyForm::groupBoxArg_Enter);
            // 
            // chkRange
            // 
            resources->ApplyResources(this->chkRange, L"chkRange");
            this->errorProvider1->SetError(this->chkRange, resources->GetString(L"chkRange.Error"));
            this->errorProvider1->SetIconAlignment(this->chkRange, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"chkRange.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->chkRange, (cli::safe_cast<System::Int32>(resources->GetObject(L"chkRange.IconPadding"))));
            this->chkRange->Name = L"chkRange";
            this->chkRange->UseVisualStyleBackColor = true;
            this->chkRange->CheckedChanged += gcnew System::EventHandler(this, &MyForm::chkRange_CheckedChanged);
            // 
            // label6
            // 
            resources->ApplyResources(this->label6, L"label6");
            this->errorProvider1->SetError(this->label6, resources->GetString(L"label6.Error"));
            this->errorProvider1->SetIconAlignment(this->label6, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"label6.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->label6, (cli::safe_cast<System::Int32>(resources->GetObject(L"label6.IconPadding"))));
            this->label6->Name = L"label6";
            this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
            // 
            // txtStep
            // 
            resources->ApplyResources(this->txtStep, L"txtStep");
            this->errorProvider1->SetError(this->txtStep, resources->GetString(L"txtStep.Error"));
            this->errorProvider1->SetIconAlignment(this->txtStep, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"txtStep.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->txtStep, (cli::safe_cast<System::Int32>(resources->GetObject(L"txtStep.IconPadding"))));
            this->txtStep->Name = L"txtStep";
            this->txtStep->ShortcutsEnabled = false;
            this->txtStep->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_TextChanged);
            this->txtStep->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::txt_KeyDown);
            this->txtStep->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txt_KeyPress);
            // 
            // txtTo
            // 
            resources->ApplyResources(this->txtTo, L"txtTo");
            this->errorProvider1->SetError(this->txtTo, resources->GetString(L"txtTo.Error"));
            this->errorProvider1->SetIconAlignment(this->txtTo, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"txtTo.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->txtTo, (cli::safe_cast<System::Int32>(resources->GetObject(L"txtTo.IconPadding"))));
            this->txtTo->Name = L"txtTo";
            this->txtTo->ShortcutsEnabled = false;
            this->txtTo->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_TextChanged);
            this->txtTo->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::txt_KeyDown);
            this->txtTo->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txt_KeyPress);
            // 
            // txtFrom
            // 
            resources->ApplyResources(this->txtFrom, L"txtFrom");
            this->errorProvider1->SetError(this->txtFrom, resources->GetString(L"txtFrom.Error"));
            this->errorProvider1->SetIconAlignment(this->txtFrom, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"txtFrom.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->txtFrom, (cli::safe_cast<System::Int32>(resources->GetObject(L"txtFrom.IconPadding"))));
            this->txtFrom->Name = L"txtFrom";
            this->txtFrom->ShortcutsEnabled = false;
            this->txtFrom->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_TextChanged);
            this->txtFrom->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::txt_KeyDown);
            this->txtFrom->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txt_KeyPress);
            // 
            // txtX
            // 
            resources->ApplyResources(this->txtX, L"txtX");
            this->errorProvider1->SetError(this->txtX, resources->GetString(L"txtX.Error"));
            this->errorProvider1->SetIconAlignment(this->txtX, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"txtX.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->txtX, (cli::safe_cast<System::Int32>(resources->GetObject(L"txtX.IconPadding"))));
            this->txtX->Name = L"txtX";
            this->txtX->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_TextChanged);
            this->txtX->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::txt_KeyDown);
            this->txtX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txt_KeyPress);
            // 
            // label5
            // 
            resources->ApplyResources(this->label5, L"label5");
            this->errorProvider1->SetError(this->label5, resources->GetString(L"label5.Error"));
            this->errorProvider1->SetIconAlignment(this->label5, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"label5.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->label5, (cli::safe_cast<System::Int32>(resources->GetObject(L"label5.IconPadding"))));
            this->label5->Name = L"label5";
            // 
            // label7
            // 
            resources->ApplyResources(this->label7, L"label7");
            this->errorProvider1->SetError(this->label7, resources->GetString(L"label7.Error"));
            this->errorProvider1->SetIconAlignment(this->label7, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"label7.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->label7, (cli::safe_cast<System::Int32>(resources->GetObject(L"label7.IconPadding"))));
            this->label7->Name = L"label7";
            this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
            // 
            // label4
            // 
            resources->ApplyResources(this->label4, L"label4");
            this->errorProvider1->SetError(this->label4, resources->GetString(L"label4.Error"));
            this->errorProvider1->SetIconAlignment(this->label4, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"label4.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->label4, (cli::safe_cast<System::Int32>(resources->GetObject(L"label4.IconPadding"))));
            this->label4->Name = L"label4";
            // 
            // btnCompute
            // 
            resources->ApplyResources(this->btnCompute, L"btnCompute");
            this->errorProvider1->SetError(this->btnCompute, resources->GetString(L"btnCompute.Error"));
            this->errorProvider1->SetIconAlignment(this->btnCompute, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"btnCompute.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->btnCompute, (cli::safe_cast<System::Int32>(resources->GetObject(L"btnCompute.IconPadding"))));
            this->btnCompute->Name = L"btnCompute";
            this->btnCompute->UseVisualStyleBackColor = true;
            this->btnCompute->Click += gcnew System::EventHandler(this, &MyForm::btnCompute_Click);
            // 
            // lblResult
            // 
            resources->ApplyResources(this->lblResult, L"lblResult");
            this->errorProvider1->SetError(this->lblResult, resources->GetString(L"lblResult.Error"));
            this->errorProvider1->SetIconAlignment(this->lblResult, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"lblResult.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->lblResult, (cli::safe_cast<System::Int32>(resources->GetObject(L"lblResult.IconPadding"))));
            this->lblResult->Name = L"lblResult";
            this->lblResult->Click += gcnew System::EventHandler(this, &MyForm::lblResult_Click);
            // 
            // dgvTable
            // 
            resources->ApplyResources(this->dgvTable, L"dgvTable");
            this->dgvTable->AllowUserToAddRows = false;
            this->dgvTable->AllowUserToDeleteRows = false;
            this->dgvTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->errorProvider1->SetError(this->dgvTable, resources->GetString(L"dgvTable.Error"));
            this->errorProvider1->SetIconAlignment(this->dgvTable, (cli::safe_cast<System::Windows::Forms::ErrorIconAlignment>(resources->GetObject(L"dgvTable.IconAlignment"))));
            this->errorProvider1->SetIconPadding(this->dgvTable, (cli::safe_cast<System::Int32>(resources->GetObject(L"dgvTable.IconPadding"))));
            this->dgvTable->Name = L"dgvTable";
            this->dgvTable->ReadOnly = true;
            // 
            // errorProvider1
            // 
            this->errorProvider1->ContainerControl = this;
            resources->ApplyResources(this->errorProvider1, L"errorProvider1");
            // 
            // MyForm
            // 
            this->AcceptButton = this->btnCompute;
            resources->ApplyResources(this, L"$this");
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->dgvTable);
            this->Controls->Add(this->lblResult);
            this->Controls->Add(this->btnCompute);
            this->Controls->Add(this->groupBoxArg);
            this->Controls->Add(this->groupBoxCoeffs);
            this->Controls->Add(this->groupBoxFunctionType);
            this->Name = L"MyForm";
            this->groupBoxFunctionType->ResumeLayout(false);
            this->groupBoxFunctionType->PerformLayout();
            this->groupBoxCoeffs->ResumeLayout(false);
            this->groupBoxCoeffs->PerformLayout();
            this->groupBoxArg->ResumeLayout(false);
            this->groupBoxArg->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTable))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
        // ───────────────────────────

private:
    // Прототипы обработчиков — без тел { … }
    System::Void txt_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);

    System::Void chkRange_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
    System::Void rbFunction_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
    System::Void btnCompute_Click(System::Object^ sender, System::EventArgs^ e);
    System::Void txt_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
    System::Void txt_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void lblResult_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBoxCoeffs_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBoxArg_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
};  // конец класса MyForm

}  // конец namespace SuperPoint

