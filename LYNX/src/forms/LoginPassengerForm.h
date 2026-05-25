#pragma once
#include "PassengerMenuForm.h"

namespace LYNX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginPassengerForm
	/// </summary>
	public ref class LoginPassengerForm : public System::Windows::Forms::Form
	{
	public:
		LoginPassengerForm(void) 
			
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginPassengerForm()
		{
			if (components)
			{
				delete components;
			}
		}
		
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbDni;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::Button^ btnEnter;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::LinkLabel^ llRegister;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		/// 
		System::ComponentModel::Container^ components;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbDni = (gcnew System::Windows::Forms::TextBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnEnter = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->llRegister = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 28, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(121, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(251, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Iniciar Sesion";
			this->label1->Click += gcnew System::EventHandler(this, &LoginPassengerForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(33, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"DNI";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(33, 134);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Nombre";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(33, 189);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Contrasena";
			// 
			// tbDni
			// 
			this->tbDni->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbDni->Location = System::Drawing::Point(36, 101);
			this->tbDni->Name = L"tbDni";
			this->tbDni->Size = System::Drawing::Size(429, 27);
			this->tbDni->TabIndex = 4;
			// 
			// tbName
			// 
			this->tbName->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbName->Location = System::Drawing::Point(36, 154);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(429, 27);
			this->tbName->TabIndex = 5;
			// 
			// tbPassword
			// 
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbPassword->Location = System::Drawing::Point(36, 209);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(429, 27);
			this->tbPassword->TabIndex = 6;
			// 
			// btnEnter
			// 
			this->btnEnter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->btnEnter->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnEnter->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->btnEnter->Location = System::Drawing::Point(166, 258);
			this->btnEnter->Name = L"btnEnter";
			this->btnEnter->Size = System::Drawing::Size(150, 44);
			this->btnEnter->TabIndex = 7;
			this->btnEnter->Text = L"Ingresar";
			this->btnEnter->UseVisualStyleBackColor = false;
			this->btnEnter->Click += gcnew System::EventHandler(this, &LoginPassengerForm::btnEnter_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::SystemColors::Control;
			this->label5->Location = System::Drawing::Point(156, 321);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"No tienes cuenta\?";
			// 
			// llRegister
			// 
			this->llRegister->AutoSize = true;
			this->llRegister->LinkColor = System::Drawing::Color::White;
			this->llRegister->Location = System::Drawing::Point(256, 321);
			this->llRegister->Name = L"llRegister";
			this->llRegister->Size = System::Drawing::Size(60, 13);
			this->llRegister->TabIndex = 9;
			this->llRegister->TabStop = true;
			this->llRegister->Text = L"Registrarse";
			this->llRegister->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginPassengerForm::llRegister_LinkClicked);
			// 
			// LoginPassengerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->ClientSize = System::Drawing::Size(503, 354);
			this->Controls->Add(this->llRegister);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnEnter);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->tbDni);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LoginPassengerForm";
			this->Text = L"LoginPassengerForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   public: bool passengerScreen = false;
	private: System::Void btnEnter_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = this->tbDni->Text;
		String^ name = this->tbName->Text;
		String^ password = this->tbPassword->Text;

		

		if (dni->Length == 0 || password->Length == 0 || name->Length == 0) {
			MessageBox::Show("Porfavor llene todos los campos", "Error DNI, Nombre o Contrasena", MessageBoxButtons::OK);
			return;
		}

		

		passengerScreen = true;
		this->Close();
	}
	public: bool switchToRegister = false;
	private: System::Void llRegister_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->switchToRegister = true;
		this->Close();
	}
		  
};
}
