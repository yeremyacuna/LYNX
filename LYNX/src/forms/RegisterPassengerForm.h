#pragma once

namespace LYNX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class RegisterPassengerForm : public System::Windows::Forms::Form
	{
	public:
		RegisterPassengerForm(void)
		{
			InitializeComponent();
			
			// icon
			try
			{
				this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
			}
			catch (System::Exception^ ex)
			{
				// empty	
			}

			this->CenterToScreen();
		}

	protected:
		~RegisterPassengerForm()
		{
			if (components)
			{
				delete components;
			}
		}

		// OBJETOS
	private:

		// COMPONENTES
	private: 
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::TextBox^ tbDni;
		System::Windows::Forms::TextBox^ tbName;
		System::Windows::Forms::TextBox^ tbPassword;
		System::Windows::Forms::Button^ btnSignin;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::TextBox^ tbConfirmPassword;
		System::Windows::Forms::LinkLabel^ llLogin;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Label^ label7;
		System::ComponentModel::Container ^components;

	private:
		#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterPassengerForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbDni = (gcnew System::Windows::Forms::TextBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnSignin = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->llLogin = (gcnew System::Windows::Forms::LinkLabel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 28, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(131, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(218, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Registrarse";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"DNI";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Nombre";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 185);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Contrasena";
			// 
			// tbDni
			// 
			this->tbDni->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->tbDni->Location = System::Drawing::Point(25, 89);
			this->tbDni->Name = L"tbDni";
			this->tbDni->Size = System::Drawing::Size(452, 26);
			this->tbDni->TabIndex = 4;
			// 
			// tbName
			// 
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->tbName->Location = System::Drawing::Point(26, 146);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(452, 26);
			this->tbName->TabIndex = 5;
			// 
			// tbPassword
			// 
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->tbPassword->Location = System::Drawing::Point(26, 201);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(452, 26);
			this->tbPassword->TabIndex = 6;
			// 
			// btnSignin
			// 
			this->btnSignin->Location = System::Drawing::Point(203, 284);
			this->btnSignin->Name = L"btnSignin";
			this->btnSignin->Size = System::Drawing::Size(75, 23);
			this->btnSignin->TabIndex = 7;
			this->btnSignin->Text = L"Registrar";
			this->btnSignin->UseVisualStyleBackColor = true;
			this->btnSignin->Click += gcnew System::EventHandler(this, &RegisterPassengerForm::btnSignin_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(23, 230);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(108, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Confirmar Contrasena";
			// 
			// tbConfirmPassword
			// 
			this->tbConfirmPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->tbConfirmPassword->Location = System::Drawing::Point(25, 246);
			this->tbConfirmPassword->Name = L"tbConfirmPassword";
			this->tbConfirmPassword->PasswordChar = '*';
			this->tbConfirmPassword->Size = System::Drawing::Size(452, 26);
			this->tbConfirmPassword->TabIndex = 9;
			// 
			// llLogin
			// 
			this->llLogin->AutoSize = true;
			this->llLogin->Location = System::Drawing::Point(259, 321);
			this->llLogin->Name = L"llLogin";
			this->llLogin->Size = System::Drawing::Size(68, 13);
			this->llLogin->TabIndex = 10;
			this->llLogin->TabStop = true;
			this->llLogin->Text = L"Iniciar sesion";
			this->llLogin->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterPassengerForm::llLogin_LinkClicked);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(267, 329);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(159, 321);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(94, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Ya tienes Cuenta\?";
			// 
			// RegisterPassengerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(503, 354);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->llLogin);
			this->Controls->Add(this->tbConfirmPassword);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnSignin);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->tbDni);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			//this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RegisterPassengerForm";
			this->Text = L"RegisterPassengerForm";
			this->Load += gcnew System::EventHandler(this, &RegisterPassengerForm::RegisterPassengerForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		// LOGIC
		#pragma endregion
		public:
			bool passengerScreen = false;

		private:
			System::Void btnSignin_Click(System::Object^ sender, System::EventArgs^ e) {
				String^ dni = this->tbDni->Text;
				String^ name = this->tbName->Text;
				String^ password = this->tbPassword->Text;
				String^ confirmPassword = this->tbConfirmPassword->Text;

				if (dni->Length == 0 || password->Length == 0 || name->Length == 0 || confirmPassword->Length == 0) {
					MessageBox::Show("Porfavor llene todos los campos", "Error DNI, Nombre o Contrasena", MessageBoxButtons::OK);
					return;
				}

				if (String::Compare(password, confirmPassword) != 0) {
					MessageBox::Show("Incompatibilidad de Contrasenas", "Error Contrasena", MessageBoxButtons::OK);
					return;
				}
				this->switchToLogin = true;
				this->Close();
			}

		public:
			bool switchToLogin = false;

		private:
			System::Void llLogin_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
				this->switchToLogin = true;
				this->Close();
			}

		private: 
			System::Void RegisterPassengerForm_Load(System::Object^ sender, System::EventArgs^ e) {

			}
};
}
