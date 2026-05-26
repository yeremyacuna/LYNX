#pragma once
#include "PassengerMenuForm.h"

namespace LYNX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class LoginPassengerForm : public System::Windows::Forms::Form
	{
	public:
		LoginPassengerForm(void) 
			
		{
			InitializeComponent();
			this->CenterToScreen();

			// ACTIVAR F11
			this->KeyPreview = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false; // quitar maximizar
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginPassengerForm::LoginPassengerForm_KeyDown);

			// CARGAR ICONO
			try
			{
				this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
			}
			catch (System::Exception^ ex)
			{
				// empty	
			}
			
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
	private: System::Windows::Forms::Panel^ pnlTopBar;
	private: System::Windows::Forms::PictureBox^ pictureBoxIcon;
	private: System::Windows::Forms::Label^ lblLYNX;

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
			this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
			this->lblLYNX = (gcnew System::Windows::Forms::Label());
			this->pnlTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 28, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(627, 386);
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
			this->label2->Location = System::Drawing::Point(539, 439);
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
			this->label3->Location = System::Drawing::Point(539, 492);
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
			this->label4->Location = System::Drawing::Point(539, 547);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Contrasena";
			// 
			// tbDni
			// 
			this->tbDni->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbDni->Location = System::Drawing::Point(542, 459);
			this->tbDni->Name = L"tbDni";
			this->tbDni->Size = System::Drawing::Size(429, 27);
			this->tbDni->TabIndex = 4;
			// 
			// tbName
			// 
			this->tbName->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbName->Location = System::Drawing::Point(542, 512);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(429, 27);
			this->tbName->TabIndex = 5;
			// 
			// tbPassword
			// 
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbPassword->Location = System::Drawing::Point(542, 567);
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
			this->btnEnter->Location = System::Drawing::Point(672, 616);
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
			this->label5->Location = System::Drawing::Point(662, 679);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"No tienes cuenta\?";
			// 
			// llRegister
			// 
			this->llRegister->AutoSize = true;
			this->llRegister->LinkColor = System::Drawing::Color::White;
			this->llRegister->Location = System::Drawing::Point(762, 679);
			this->llRegister->Name = L"llRegister";
			this->llRegister->Size = System::Drawing::Size(60, 13);
			this->llRegister->TabIndex = 9;
			this->llRegister->TabStop = true;
			this->llRegister->Text = L"Registrarse";
			this->llRegister->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginPassengerForm::llRegister_LinkClicked);
			// 
			// pnlTopBar
			// 
			this->pnlTopBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlTopBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->pnlTopBar->Controls->Add(this->pictureBoxIcon);
			this->pnlTopBar->Controls->Add(this->lblLYNX);
			this->pnlTopBar->Location = System::Drawing::Point(0, 0);
			this->pnlTopBar->Name = L"pnlTopBar";
			this->pnlTopBar->Size = System::Drawing::Size(1480, 78);
			this->pnlTopBar->TabIndex = 10;
			// 
			// pictureBoxIcon
			// 
			this->pictureBoxIcon->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxIcon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBoxIcon->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBoxIcon->Location = System::Drawing::Point(22, -27);
			this->pictureBoxIcon->Name = L"pictureBoxIcon";
			this->pictureBoxIcon->Size = System::Drawing::Size(75, 129);
			this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBoxIcon->TabIndex = 3;
			this->pictureBoxIcon->TabStop = false;
			// 
			// lblLYNX
			// 
			this->lblLYNX->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 22, System::Drawing::FontStyle::Bold));
			this->lblLYNX->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblLYNX->Location = System::Drawing::Point(91, 18);
			this->lblLYNX->Name = L"lblLYNX";
			this->lblLYNX->Size = System::Drawing::Size(84, 40);
			this->lblLYNX->TabIndex = 0;
			this->lblLYNX->Text = L"LYNX";
			// 
			// LoginPassengerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->ClientSize = System::Drawing::Size(1480, 920);
			this->Controls->Add(this->pnlTopBar);
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
			this->Text = L"LYNX | Iniciar Sesion";
			this->Load += gcnew System::EventHandler(this, &LoginPassengerForm::LoginPassengerForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginPassengerForm::LoginPassengerForm_KeyDown);
			this->pnlTopBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		// LOGICA
		#pragma endregion

		private:

		//
		// Load Form
		// 
			System::Void LoginPassengerForm_Load(System::Object^ sender, System::EventArgs^ e) {

				this->pictureBoxIcon->Image = System::Drawing::Image::FromFile("resources/LYNX_image.png");
				this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			}

		









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
		  











	//
	// Full screen function
	// 
	   bool isFullscreen = false;
	   System::Drawing::Size normalSize;
	   System::Drawing::Point normalLocation;
	   System::Windows::Forms::FormWindowState normalState;

	   System::Void LoginPassengerForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	   {
		   if (e->KeyCode == System::Windows::Forms::Keys::F11)
		   {
			   if (!isFullscreen)
			   {
				   // Guardar estado actual
				   normalSize = this->Size;
				   normalLocation = this->Location;
				   normalState = this->WindowState;

				   // Entrar a fullscreen
				   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
				   isFullscreen = true;
			   }
			   else
			   {
				   // Restaurar — CRÍTICO: volver a FixedSingle, no Sizable
				   this->WindowState = System::Windows::Forms::FormWindowState::Normal;
				   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				   this->Size = normalSize;
				   this->Location = normalLocation;
				   isFullscreen = false;
			   }
		   }

		   // ESC también sale del fullscreen
		   if (e->KeyCode == System::Windows::Forms::Keys::Escape && isFullscreen)
		   {
			   this->WindowState = System::Windows::Forms::FormWindowState::Normal;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Size = normalSize;
			   this->Location = normalLocation;
			   isFullscreen = false;
		   }
	   }
};
}
