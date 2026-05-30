#pragma once
#include <windows.h>
#include "../library/FormsStatus.h"	
#include "../AuthManager.h"
#include "../TripManager.h"
#include <msclr/marshal_cppstd.h>
#include <iostream>

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
			ConfigureForm();
		}

		LoginPassengerForm(AuthManager* auth, TripManager* trips)
		{
			this->authManager = auth;
			this->tripManager = trips;
			InitializeComponent();
			ConfigureForm();
		}
	
	protected:
		~LoginPassengerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
		// OBJETOS
	private:
		AuthManager* authManager = nullptr;
		TripManager* tripManager = nullptr;
		
		// COMPONENTES
	private: System::Windows::Forms::Label^ lblIniciarSesion;
	private: System::Windows::Forms::Label^ lblDatoDNI;
	private: System::Windows::Forms::Label^ lblDatoNombre;
	private: System::Windows::Forms::Label^ lblDatoContrasena;
	private: System::Windows::Forms::TextBox^ tbDni;
	private: System::Windows::Forms::TextBox^ tbNombre;
	private: System::Windows::Forms::TextBox^ tbContrasena;
	private: System::Windows::Forms::Button^ btnEnter;
	private: System::Windows::Forms::Label^ lblAviso1;
	private: System::Windows::Forms::LinkLabel^ llblAviso2;
	private: System::Windows::Forms::Panel^ pnlTopBar;
	private: System::Windows::Forms::PictureBox^ pictureBoxIcon;
	private: System::Windows::Forms::Label^ lblLYNX;
	private: System::Windows::Forms::Label^ lblMarco1;
	private: System::Windows::Forms::Label^ lblMarco2;
	private: System::Windows::Forms::Label^ lblMarco4;
	private: System::Windows::Forms::Label^ lblMarco3;
	private: System::Windows::Forms::TableLayoutPanel^ tlpOptions;
	private: System::Windows::Forms::Label^ lblBorrar;
	private: System::ComponentModel::Container^ components;
		
		// WINDOWS INITIALIZE
	private:
		#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblIniciarSesion = (gcnew System::Windows::Forms::Label());
			this->lblDatoDNI = (gcnew System::Windows::Forms::Label());
			this->lblDatoNombre = (gcnew System::Windows::Forms::Label());
			this->lblDatoContrasena = (gcnew System::Windows::Forms::Label());
			this->tbDni = (gcnew System::Windows::Forms::TextBox());
			this->tbNombre = (gcnew System::Windows::Forms::TextBox());
			this->tbContrasena = (gcnew System::Windows::Forms::TextBox());
			this->btnEnter = (gcnew System::Windows::Forms::Button());
			this->lblAviso1 = (gcnew System::Windows::Forms::Label());
			this->llblAviso2 = (gcnew System::Windows::Forms::LinkLabel());
			this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
			this->lblLYNX = (gcnew System::Windows::Forms::Label());
			this->lblMarco1 = (gcnew System::Windows::Forms::Label());
			this->lblMarco2 = (gcnew System::Windows::Forms::Label());
			this->lblMarco4 = (gcnew System::Windows::Forms::Label());
			this->lblMarco3 = (gcnew System::Windows::Forms::Label());
			this->tlpOptions = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lblBorrar = (gcnew System::Windows::Forms::Label());
			this->pnlTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->tlpOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblIniciarSesion
			// 
			this->lblIniciarSesion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblIniciarSesion->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 28, System::Drawing::FontStyle::Bold));
			this->lblIniciarSesion->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblIniciarSesion->Location = System::Drawing::Point(511, 348);
			this->lblIniciarSesion->Name = L"lblIniciarSesion";
			this->lblIniciarSesion->Size = System::Drawing::Size(466, 46);
			this->lblIniciarSesion->TabIndex = 0;
			this->lblIniciarSesion->Text = L"Iniciar Sesion";
			this->lblIniciarSesion->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lblDatoDNI
			// 
			this->lblDatoDNI->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDatoDNI->AutoSize = true;
			this->lblDatoDNI->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDatoDNI->ForeColor = System::Drawing::SystemColors::Control;
			this->lblDatoDNI->Location = System::Drawing::Point(508, 401);
			this->lblDatoDNI->Name = L"lblDatoDNI";
			this->lblDatoDNI->Size = System::Drawing::Size(31, 17);
			this->lblDatoDNI->TabIndex = 1;
			this->lblDatoDNI->Text = L"DNI";
			// 
			// lblDatoNombre
			// 
			this->lblDatoNombre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDatoNombre->AutoSize = true;
			this->lblDatoNombre->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDatoNombre->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblDatoNombre->Location = System::Drawing::Point(508, 454);
			this->lblDatoNombre->Name = L"lblDatoNombre";
			this->lblDatoNombre->Size = System::Drawing::Size(60, 17);
			this->lblDatoNombre->TabIndex = 2;
			this->lblDatoNombre->Text = L"Nombre";
			// 
			// lblDatoContrasena
			// 
			this->lblDatoContrasena->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDatoContrasena->AutoSize = true;
			this->lblDatoContrasena->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDatoContrasena->ForeColor = System::Drawing::SystemColors::Control;
			this->lblDatoContrasena->Location = System::Drawing::Point(508, 509);
			this->lblDatoContrasena->Name = L"lblDatoContrasena";
			this->lblDatoContrasena->Size = System::Drawing::Size(81, 17);
			this->lblDatoContrasena->TabIndex = 3;
			this->lblDatoContrasena->Text = L"Contrasena";
			// 
			// tbDni
			// 
			this->tbDni->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbDni->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbDni->Location = System::Drawing::Point(511, 421);
			this->tbDni->Name = L"tbDni";
			this->tbDni->Size = System::Drawing::Size(466, 27);
			this->tbDni->TabIndex = 4;
			// 
			// tbNombre
			// 
			this->tbNombre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbNombre->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbNombre->Location = System::Drawing::Point(511, 474);
			this->tbNombre->Name = L"tbNombre";
			this->tbNombre->Size = System::Drawing::Size(466, 27);
			this->tbNombre->TabIndex = 5;
			// 
			// tbContrasena
			// 
			this->tbContrasena->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbContrasena->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbContrasena->Location = System::Drawing::Point(511, 529);
			this->tbContrasena->Name = L"tbContrasena";
			this->tbContrasena->PasswordChar = '*';
			this->tbContrasena->Size = System::Drawing::Size(466, 27);
			this->tbContrasena->TabIndex = 6;
			// 
			// btnEnter
			// 
			this->btnEnter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnEnter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->btnEnter->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnEnter->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->btnEnter->Location = System::Drawing::Point(650, 572);
			this->btnEnter->Name = L"btnEnter";
			this->btnEnter->Size = System::Drawing::Size(191, 44);
			this->btnEnter->TabIndex = 7;
			this->btnEnter->Text = L"Ingresar";
			this->btnEnter->UseVisualStyleBackColor = false;
			this->btnEnter->Click += gcnew System::EventHandler(this, &LoginPassengerForm::btnEnter_Click);
			// 
			// lblAviso1
			// 
			this->lblAviso1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblAviso1->ForeColor = System::Drawing::SystemColors::Control;
			this->lblAviso1->Location = System::Drawing::Point(20, 0);
			this->lblAviso1->Name = L"lblAviso1";
			this->lblAviso1->Size = System::Drawing::Size(211, 13);
			this->lblAviso1->TabIndex = 8;
			this->lblAviso1->Text = L"No tienes cuenta\?";
			this->lblAviso1->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// llblAviso2
			// 
			this->llblAviso2->LinkColor = System::Drawing::Color::White;
			this->llblAviso2->Location = System::Drawing::Point(237, 0);
			this->llblAviso2->Name = L"llblAviso2";
			this->llblAviso2->Size = System::Drawing::Size(189, 13);
			this->llblAviso2->TabIndex = 9;
			this->llblAviso2->TabStop = true;
			this->llblAviso2->Text = L"Registrarse";
			this->llblAviso2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginPassengerForm::llRegister_LinkClicked);
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
			this->pnlTopBar->Size = System::Drawing::Size(1517, 78);
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
			this->pictureBoxIcon->Click += gcnew System::EventHandler(this, &LoginPassengerForm::pictureBoxIcon_Click);
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
			// lblMarco1
			// 
			this->lblMarco1->BackColor = System::Drawing::Color::Red;
			this->lblMarco1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->lblMarco1->Location = System::Drawing::Point(1, 79);
			this->lblMarco1->Name = L"lblMarco1";
			this->lblMarco1->Size = System::Drawing::Size(458, 850);
			this->lblMarco1->TabIndex = 11;
			this->lblMarco1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblMarco1->Visible = false;
			// 
			// lblMarco2
			// 
			this->lblMarco2->BackColor = System::Drawing::Color::Red;
			this->lblMarco2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->lblMarco2->Location = System::Drawing::Point(1022, 79);
			this->lblMarco2->Name = L"lblMarco2";
			this->lblMarco2->Size = System::Drawing::Size(458, 850);
			this->lblMarco2->TabIndex = 12;
			this->lblMarco2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblMarco2->Visible = false;
			// 
			// lblMarco4
			// 
			this->lblMarco4->BackColor = System::Drawing::Color::Red;
			this->lblMarco4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->lblMarco4->Location = System::Drawing::Point(450, 79);
			this->lblMarco4->Name = L"lblMarco4";
			this->lblMarco4->Size = System::Drawing::Size(595, 213);
			this->lblMarco4->TabIndex = 13;
			this->lblMarco4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblMarco4->Visible = false;
			// 
			// lblMarco3
			// 
			this->lblMarco3->BackColor = System::Drawing::Color::Red;
			this->lblMarco3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->lblMarco3->Location = System::Drawing::Point(450, 707);
			this->lblMarco3->Name = L"lblMarco3";
			this->lblMarco3->Size = System::Drawing::Size(595, 213);
			this->lblMarco3->TabIndex = 14;
			this->lblMarco3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblMarco3->Visible = false;
			// 
			// tlpOptions
			// 
			this->tlpOptions->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->tlpOptions->ColumnCount = 2;
			this->tlpOptions->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 54.61692F)));
			this->tlpOptions->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 45.38308F)));
			this->tlpOptions->Controls->Add(this->lblAviso1, 0, 0);
			this->tlpOptions->Controls->Add(this->llblAviso2, 1, 0);
			this->tlpOptions->Location = System::Drawing::Point(530, 635);
			this->tlpOptions->Name = L"tlpOptions";
			this->tlpOptions->RowCount = 1;
			this->tlpOptions->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tlpOptions->Size = System::Drawing::Size(429, 21);
			this->tlpOptions->TabIndex = 15;
			// 
			// lblBorrar
			// 
			this->lblBorrar->AutoSize = true;
			this->lblBorrar->ForeColor = System::Drawing::Color::Red;
			this->lblBorrar->Location = System::Drawing::Point(596, 315);
			this->lblBorrar->Name = L"lblBorrar";
			this->lblBorrar->Size = System::Drawing::Size(248, 13);
			this->lblBorrar->TabIndex = 19;
			this->lblBorrar->Text = L"Esto es logear para pasajero por ahora (lbl invisible)";
			this->lblBorrar->Visible = false;
			// 
			// LoginPassengerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->ClientSize = System::Drawing::Size(1480, 920);
			this->Controls->Add(this->lblBorrar);
			this->Controls->Add(this->tlpOptions);
			this->Controls->Add(this->lblMarco3);
			this->Controls->Add(this->lblMarco4);
			this->Controls->Add(this->lblMarco2);
			this->Controls->Add(this->lblMarco1);
			this->Controls->Add(this->pnlTopBar);
			this->Controls->Add(this->btnEnter);
			this->Controls->Add(this->tbContrasena);
			this->Controls->Add(this->tbNombre);
			this->Controls->Add(this->tbDni);
			this->Controls->Add(this->lblDatoContrasena);
			this->Controls->Add(this->lblDatoNombre);
			this->Controls->Add(this->lblDatoDNI);
			this->Controls->Add(this->lblIniciarSesion);
			this->Name = L"LoginPassengerForm";
			this->Text = L"LYNX | Iniciar Sesion";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LoginPassengerForm::LoginPassengerForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &LoginPassengerForm::LoginPassengerForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginPassengerForm::LoginPassengerForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &LoginPassengerForm::LoginPassengerForm_Resize);
			this->pnlTopBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
			this->tlpOptions->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		// LOGICA y PUBLIC
		#pragma endregion
		public: 
			bool passengerScreen = false;
			bool switchToRegister = false;
			String^ loggedPassengerDni = "";

			String^ dnis;
			String^ names;
			String^ passwords;

		private:

		//
		// Configuracion global de form
		//
			void ConfigureForm()
			{
				// CENTRAR TODO
				this->CenterToScreen();

				// ACTIVAR F11
				this->KeyPreview = true;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false; // quitar maximizar

				// QUITAR COSITAS
				this->MinimizeBox = false;
				HWND hWnd = static_cast<HWND>(this->Handle.ToPointer());
				HMENU hMenu = ::GetSystemMenu(hWnd, FALSE);
				::EnableMenuItem(hMenu, SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
				::DrawMenuBar(hWnd);

				// CARGAR ICONO
				try
				{
					this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
				}
				catch (...)
				{
					// empty	
				}
			}

		//
		// Load Form
		// 
			System::Void LoginPassengerForm_Load(System::Object^ sender, System::EventArgs^ e) {

				// Para Picture Box LYNX
				this->pictureBoxIcon->Image = System::Drawing::Image::FromFile("resources/LYNX_image.png");
				this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;

				// Para Pantalla Completa
				normalSize = this->Size;
				normalLocation = this->Location;
				normalState = this->WindowState;
				FormsStatus::SaveWindow(this);

				if (FormsStatus::isFullscreen)
				{
					FormsStatus::ApplyWindow(this);
				}
			}

		//
		// Click functions
		// 
			bool _internalClose = false;

			// btnEntrarCLICK
			System::Void btnEnter_Click(System::Object^ sender, System::EventArgs^ e) {

				// Guardar los txt box como Strings^
				String^ dniText = this->tbDni->Text->Trim();
				String^ nameText = this->tbNombre->Text->Trim();
				String^ passwordText = this->tbContrasena->Text;

				// Verificar que los espacios no esten vacios
				if (dniText->Length == 0 || passwordText->Length == 0 || nameText->Length == 0) {
					MessageBox::Show("Por favor llene todos los campos", "Iniciar Sesion", MessageBoxButtons::OK);
					return;
				}

				//Verificar si se pudo o no acceder al gestionador de archivos
				if (authManager == nullptr) {
					MessageBox::Show("No se pudo acceder al gestor de usuarios", "Iniciar Sesion", MessageBoxButtons::OK);
					return;
				}

				// Converitr con marshal as al tipo de dato que quiero segun un String^
				std::string dni = msclr::interop::marshal_as<std::string>(dniText);
				std::string name = msclr::interop::marshal_as<std::string>(nameText);
				std::string password = msclr::interop::marshal_as<std::string>(passwordText);

				// Hacer validacion de los digitos del dni en el caso no tenga 8 o no sea int
				if (!authManager->validateDni(dni)) {
					MessageBox::Show("DNI invalido. Debe tener 8 digitos numericos.", "Iniciar Sesion", MessageBoxButtons::OK);
					return;
				}

				// Validar que el usuario exista con el auth managern login user valid
				if (!authManager->loginUserValid(dni, password)) {
					MessageBox::Show("Datos incorrectos", "Iniciar Sesion", MessageBoxButtons::OK);
					this->tbContrasena->Clear();
					return;
				}

				// Validar si los datos coinciden con un pasajero existente
				Passenger passenger = authManager->getUserByDni(dni);
				if (passenger.getDni() == "" || passenger.getName() != name) {
					MessageBox::Show("Datos incorrectos", "Iniciar Sesion", MessageBoxButtons::OK);
					this->tbContrasena->Clear();
					return;
				}

				// variables de recuerdo e informacion para la prox pantalla (check)
				dnis = dniText;
				names = nameText;
				passwords = passwordText;

				loggedPassengerDni = dniText;
				passengerScreen = true;
				FormsStatus::SaveWindow(this);
				_internalClose = true;  // marcar como cierre 
				this->Close();
			}

			// linkerlabelClick
			System::Void llRegister_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
				this->switchToRegister = true;
				FormsStatus::SaveWindow(this);
				_internalClose = true;  // marcar como cierre 
				this->Close();
			}

			// pictureLYNXClick
			System::Void pictureBoxIcon_Click(System::Object^ sender, System::EventArgs^ e) {
				if (FormsStatus::mainMenu != nullptr && !FormsStatus::mainMenu->IsDisposed)
				{
					FormsStatus::SaveWindow(this);
					FormsStatus::ApplyWindow(FormsStatus::mainMenu);
					FormsStatus::mainMenu->Show();
					FormsStatus::mainMenu->BringToFront();
					this->Hide();
				}
			}
		  
		//
		// Full screen function
		// 
			System::Drawing::Size normalSize;
			System::Drawing::Point normalLocation;
			System::Windows::Forms::FormWindowState normalState;

			System::Void LoginPassengerForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
			{

				if (e->KeyCode == System::Windows::Forms::Keys::F11)
				{
					if (!FormsStatus::isFullscreen)
					{
						// Guardar estado actual
						normalSize = this->Size;
						normalLocation = this->Location;
						normalState = this->WindowState;

						FormsStatus::SaveWindow(this);

						// Entrar a fullscreen
						this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
						this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

						FormsStatus::isFullscreen = true;
					}
					else
					{
						// Restaurar volver a fixedSingle, no sizable
						this->WindowState = System::Windows::Forms::FormWindowState::Normal;
						this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
						this->Size = FormsStatus::normalSize;
						this->Location = FormsStatus::normalLocation;

						FormsStatus::isFullscreen  = false;

						// DESACTIVAR CLOSE BOTTON
						HWND hWnd = static_cast<HWND>(this->Handle.ToPointer());
						HMENU hMenu = ::GetSystemMenu(hWnd, FALSE);
						::EnableMenuItem(hMenu, SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
						::DrawMenuBar(hWnd);

						this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
					}
				}

				// ESC sale del fullscreen
				if (e->KeyCode == System::Windows::Forms::Keys::Escape && FormsStatus::isFullscreen)
				{
					this->WindowState = System::Windows::Forms::FormWindowState::Normal;
					this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
					this->Size = FormsStatus::normalSize;
					this->Location = FormsStatus::normalLocation;

					FormsStatus::isFullscreen = false;

					// DESACTIVAR CLOSE BOTTON
					HWND hWnd = static_cast<HWND>(this->Handle.ToPointer());
					HMENU hMenu = ::GetSystemMenu(hWnd, FALSE);
					::EnableMenuItem(hMenu, SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
					::DrawMenuBar(hWnd);

					this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
				}
			}

		//
		// Login resize
		// 
			System::Void LoginPassengerForm_Resize(System::Object^ sender, System::EventArgs^ e) {

				HWND hWnd = static_cast<HWND>(this->Handle.ToPointer());
				HMENU hMenu = ::GetSystemMenu(hWnd, FALSE);
				::EnableMenuItem(hMenu, SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
				::DrawMenuBar(hWnd);
			}


		//
		// Login cerrado closing
		// 
			System::Void LoginPassengerForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
				if (!_internalClose)
				{
					// cerrar todo
					System::Windows::Forms::Application::Exit();
				}

				// si es interno, dejar cerrar normalmente
				_internalClose = false;
			}
};
}
