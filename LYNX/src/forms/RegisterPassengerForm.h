#pragma once
#include <windows.h>
#include "../library/FormsStatus.h"	
#include "../AuthManager.h"
#include "../TripManager.h"
#include <msclr/marshal_cppstd.h>
#include "VehicleRegisterForm.h"

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
			ConfigureForm();
		}

		RegisterPassengerForm(AuthManager* auth, TripManager* trips, int style)
		{
			this->authManager = auth;
			this->tripManager = trips;
			this->registerStyle = NormalizeRegisterStyle(style);
			InitializeComponent();
			ApplyRegisterStyle();
			
			// ok
			ConfigureForm();
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
		AuthManager* authManager = nullptr;
		TripManager* tripManager = nullptr;
		int registerStyle = 1;

		
		// COMPONENTES
	private: System::Windows::Forms::Label^ lblRegistrarse;
	private: System::Windows::Forms::Label^ lblDatoDNI;
	private: System::Windows::Forms::Label^ lblDatoNombre;
	private: System::Windows::Forms::Label^ lblDatoContrasena;
	private: System::Windows::Forms::Label^ lblDatoConfirmar;
	private: System::Windows::Forms::TextBox^ tbDni;
	private: System::Windows::Forms::TextBox^ tbNombre;
	private: System::Windows::Forms::TextBox^ tbContrasena;
	private: System::Windows::Forms::TextBox^ tbConfirmarContrasena;
	private: System::Windows::Forms::Button^ btnRegistrar;
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
	private: System::ComponentModel::Container^ components;

		   // WINDOWS INITIALIZE
	private:
		#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblRegistrarse = (gcnew System::Windows::Forms::Label());
			this->lblDatoDNI = (gcnew System::Windows::Forms::Label());
			this->lblDatoNombre = (gcnew System::Windows::Forms::Label());
			this->lblDatoContrasena = (gcnew System::Windows::Forms::Label());
			this->lblDatoConfirmar = (gcnew System::Windows::Forms::Label());
			this->tbDni = (gcnew System::Windows::Forms::TextBox());
			this->tbNombre = (gcnew System::Windows::Forms::TextBox());
			this->tbContrasena = (gcnew System::Windows::Forms::TextBox());
			this->tbConfirmarContrasena = (gcnew System::Windows::Forms::TextBox());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
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
			this->pnlTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->tlpOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblRegistrarse
			// 
			this->lblRegistrarse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblRegistrarse->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 28, System::Drawing::FontStyle::Bold));
			this->lblRegistrarse->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblRegistrarse->Location = System::Drawing::Point(524, 320);
			this->lblRegistrarse->Name = L"lblRegistrarse";
			this->lblRegistrarse->Size = System::Drawing::Size(429, 46);
			this->lblRegistrarse->TabIndex = 0;
			this->lblRegistrarse->Text = L"Registrarse";
			this->lblRegistrarse->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lblDatoDNI
			// 
			this->lblDatoDNI->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDatoDNI->AutoSize = true;
			this->lblDatoDNI->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDatoDNI->ForeColor = System::Drawing::SystemColors::Control;
			this->lblDatoDNI->Location = System::Drawing::Point(521, 373);
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
			this->lblDatoNombre->Location = System::Drawing::Point(521, 426);
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
			this->lblDatoContrasena->Location = System::Drawing::Point(521, 479);
			this->lblDatoContrasena->Name = L"lblDatoContrasena";
			this->lblDatoContrasena->Size = System::Drawing::Size(81, 17);
			this->lblDatoContrasena->TabIndex = 3;
			this->lblDatoContrasena->Text = L"Contrasena";
			// 
			// lblDatoConfirmar
			// 
			this->lblDatoConfirmar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDatoConfirmar->AutoSize = true;
			this->lblDatoConfirmar->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDatoConfirmar->ForeColor = System::Drawing::SystemColors::Control;
			this->lblDatoConfirmar->Location = System::Drawing::Point(521, 533);
			this->lblDatoConfirmar->Name = L"lblDatoConfirmar";
			this->lblDatoConfirmar->Size = System::Drawing::Size(149, 17);
			this->lblDatoConfirmar->TabIndex = 4;
			this->lblDatoConfirmar->Text = L"Confirmar Contrasena";
			// 
			// tbDni
			// 
			this->tbDni->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbDni->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbDni->Location = System::Drawing::Point(524, 393);
			this->tbDni->Name = L"tbDni";
			this->tbDni->Size = System::Drawing::Size(429, 27);
			this->tbDni->TabIndex = 5;
			// 
			// tbNombre
			// 
			this->tbNombre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbNombre->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbNombre->Location = System::Drawing::Point(524, 446);
			this->tbNombre->Name = L"tbNombre";
			this->tbNombre->Size = System::Drawing::Size(429, 27);
			this->tbNombre->TabIndex = 6;
			// 
			// tbContrasena
			// 
			this->tbContrasena->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbContrasena->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbContrasena->Location = System::Drawing::Point(524, 499);
			this->tbContrasena->Name = L"tbContrasena";
			this->tbContrasena->PasswordChar = '*';
			this->tbContrasena->Size = System::Drawing::Size(429, 27);
			this->tbContrasena->TabIndex = 7;
			// 
			// tbConfirmarContrasena
			// 
			this->tbConfirmarContrasena->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbConfirmarContrasena->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbConfirmarContrasena->Location = System::Drawing::Point(524, 553);
			this->tbConfirmarContrasena->Name = L"tbConfirmarContrasena";
			this->tbConfirmarContrasena->PasswordChar = '*';
			this->tbConfirmarContrasena->Size = System::Drawing::Size(429, 27);
			this->tbConfirmarContrasena->TabIndex = 8;
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRegistrar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->btnRegistrar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRegistrar->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->btnRegistrar->Location = System::Drawing::Point(624, 598);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(230, 44);
			this->btnRegistrar->TabIndex = 9;
			this->btnRegistrar->Text = L"Crear Cuenta";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &RegisterPassengerForm::btnRegistrar_Click);
			// 
			// lblAviso1
			// 
			this->lblAviso1->ForeColor = System::Drawing::SystemColors::Control;
			this->lblAviso1->Location = System::Drawing::Point(3, 0);
			this->lblAviso1->Name = L"lblAviso1";
			this->lblAviso1->Size = System::Drawing::Size(221, 13);
			this->lblAviso1->TabIndex = 10;
			this->lblAviso1->Text = L"Ya tienes cuenta\?";
			this->lblAviso1->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// llblAviso2
			// 
			this->llblAviso2->LinkColor = System::Drawing::Color::White;
			this->llblAviso2->Location = System::Drawing::Point(230, 0);
			this->llblAviso2->Name = L"llblAviso2";
			this->llblAviso2->Size = System::Drawing::Size(189, 13);
			this->llblAviso2->TabIndex = 11;
			this->llblAviso2->TabStop = true;
			this->llblAviso2->Text = L"Iniciar Sesion";
			this->llblAviso2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterPassengerForm::llblAviso2_LinkClicked);
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
			this->pnlTopBar->TabIndex = 12;
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
			this->pictureBoxIcon->Click += gcnew System::EventHandler(this, &RegisterPassengerForm::pictureBoxIcon_Click);
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
			this->lblMarco1->Location = System::Drawing::Point(1, 79);
			this->lblMarco1->Name = L"lblMarco1";
			this->lblMarco1->Size = System::Drawing::Size(458, 850);
			this->lblMarco1->TabIndex = 13;
			this->lblMarco1->Visible = false;
			// 
			// lblMarco2
			// 
			this->lblMarco2->BackColor = System::Drawing::Color::Red;
			this->lblMarco2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco2->Location = System::Drawing::Point(1022, 79);
			this->lblMarco2->Name = L"lblMarco2";
			this->lblMarco2->Size = System::Drawing::Size(458, 850);
			this->lblMarco2->TabIndex = 14;
			this->lblMarco2->Visible = false;
			// 
			// lblMarco4
			// 
			this->lblMarco4->BackColor = System::Drawing::Color::Red;
			this->lblMarco4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco4->Location = System::Drawing::Point(450, 79);
			this->lblMarco4->Name = L"lblMarco4";
			this->lblMarco4->Size = System::Drawing::Size(595, 213);
			this->lblMarco4->TabIndex = 15;
			this->lblMarco4->Visible = false;
			// 
			// lblMarco3
			// 
			this->lblMarco3->BackColor = System::Drawing::Color::Red;
			this->lblMarco3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco3->Location = System::Drawing::Point(450, 707);
			this->lblMarco3->Name = L"lblMarco3";
			this->lblMarco3->Size = System::Drawing::Size(595, 213);
			this->lblMarco3->TabIndex = 16;
			this->lblMarco3->Visible = false;
			// 
			// tlpOptions
			// 
			this->tlpOptions->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->tlpOptions->ColumnCount = 2;
			this->tlpOptions->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 53.02772F)));
			this->tlpOptions->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 46.97228F)));
			this->tlpOptions->Controls->Add(this->lblAviso1, 0, 0);
			this->tlpOptions->Controls->Add(this->llblAviso2, 1, 0);
			this->tlpOptions->Location = System::Drawing::Point(524, 657);
			this->tlpOptions->Name = L"tlpOptions";
			this->tlpOptions->RowCount = 1;
			this->tlpOptions->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tlpOptions->Size = System::Drawing::Size(429, 21);
			this->tlpOptions->TabIndex = 17;
			// 
			// RegisterPassengerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->ClientSize = System::Drawing::Size(1480, 920);
			this->Controls->Add(this->tlpOptions);
			this->Controls->Add(this->lblMarco3);
			this->Controls->Add(this->lblMarco4);
			this->Controls->Add(this->lblMarco2);
			this->Controls->Add(this->lblMarco1);
			this->Controls->Add(this->pnlTopBar);
			this->Controls->Add(this->btnRegistrar);
			this->Controls->Add(this->tbConfirmarContrasena);
			this->Controls->Add(this->tbContrasena);
			this->Controls->Add(this->tbNombre);
			this->Controls->Add(this->tbDni);
			this->Controls->Add(this->lblDatoConfirmar);
			this->Controls->Add(this->lblDatoContrasena);
			this->Controls->Add(this->lblDatoNombre);
			this->Controls->Add(this->lblDatoDNI);
			this->Controls->Add(this->lblRegistrarse);
			this->Name = L"RegisterPassengerForm";
			this->Text = L"LYNX | Registrarse";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &RegisterPassengerForm::RegisterPassengerForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &RegisterPassengerForm::RegisterPassengerForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterPassengerForm::RegisterPassengerForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &RegisterPassengerForm::RegisterPassengerForm_Resize);
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
			bool driverScreen = false;

			bool switchToVehicle = false;
			bool switchToLogin = false;

			String^ name;
			String^ dni;
			String^ pass;

			int GetRegisterStyle()
			{
				return registerStyle;
			}

		private:

		//
		// Style register: 1 pasajero, 2 conductor, 3 administrador
		//
			int NormalizeRegisterStyle(int style)
			{
				if (style < 1 || style > 3)
				{
					return 1;
				}

				return style;
			}

			// names de registers change
			void ApplyRegisterStyle()
			{
				if (registerStyle == 2)
				{
					this->Text = L"LYNX | Registarse Conductor";
				}
				else if (registerStyle == 3)
				{
					this->Text = L"LYNX | Registarse Administrador";
				}
				else
				{
					this->Text = L"LYNX | Registarse Pasajero";
				}
			}
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
				this->MaximizeBox = false;

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
			System::Void RegisterPassengerForm_Load(System::Object^ sender, System::EventArgs^ e)
			{

				this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
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

			// btnRegistrarseCLICK
			System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e)
			{
				if (registerStyle == 1)
				{
					RegisterPassenger();
					return;
				}
				
				if (registerStyle == 2)
				{
					RegisterDriver();
					return;
				}

				if (registerStyle == 3)
				{
					// admins nuevos no se pueden registrar :p
					RegisterAdmin();
					return;
				}
			}








			void RegisterPassenger() {
				// Guardar los txt box como Strings^
				String^ dniText = this->tbDni->Text->Trim();
				String^ nombreText = this->tbNombre->Text->Trim();
				String^ passText = this->tbContrasena->Text;
				String^ confirmText = this->tbConfirmarContrasena->Text;

				// Verificar que los espacios no esten vacios
				if (dniText->Length == 0 || nombreText->Length == 0 || passText->Length == 0 || confirmText->Length == 0) {
					MessageBox::Show("Por favor llene todos los campos", "Registro", MessageBoxButtons::OK);
					return;
				}

				//Verificar si las contraseñas coinciden
				if (String::Compare(passText, confirmText) != 0) {
					MessageBox::Show("Las contrasenas no coinciden", "Registro", MessageBoxButtons::OK);
					return;
				}

				//Verificar si se pudo o no acceder al gestionador de archivos
				if (authManager == nullptr) {
					MessageBox::Show("No se pudo acceder al gestor de usuarios", "Registro", MessageBoxButtons::OK);
					return;
				}

				// Converitr con marshal as al tipo de dato que quiero segun un String^
				std::string dni = msclr::interop::marshal_as<std::string>(dniText);
				std::string nombre = msclr::interop::marshal_as<std::string>(nombreText);
				std::string pass = msclr::interop::marshal_as<std::string>(passText);

				// Hacer validacion de los digitos del dni en el caso no tenga 8 o no sea int
				if (!authManager->validateDni(dni)) {
					MessageBox::Show("DNI invalido. Debe tener 8 digitos numericos.", "Registro", MessageBoxButtons::OK);
					return;
				}

				// Validar si elk DNI ya se encuentra registrado con dni nombre y contraseña pass en la funcion de authmanager
				if (!authManager->registerPassenger(nombre, dni, pass)) {
					MessageBox::Show("El DNI ya esta registrado.", "Registro", MessageBoxButtons::OK);
					return;
				}

				// Validar si la cuenta fue creada correctamente y se guardo todo correctamente o no , con save a password binary q devuelve true or false de guardar binario d fmanager
				if (!authManager->savePasswordsBinary()) {
					MessageBox::Show("La cuenta fue creada, pero no se pudo actualizar passwords.bin.", "Registro", MessageBoxButtons::OK);
				}
				else {
					MessageBox::Show("Cuenta creada correctamente.", "Registro", MessageBoxButtons::OK);
				}

				switchToLogin = true;
				FormsStatus::SaveWindow(this);
				_internalClose = true;
				//this->Close();
				this->Hide();
			}


			void RegisterDriver() {
				// Guardar los txt box como Strings^
				String^ dniText = this->tbDni->Text->Trim();
				String^ nombreText = this->tbNombre->Text->Trim();
				String^ passText = this->tbContrasena->Text;
				String^ confirmText = this->tbConfirmarContrasena->Text;
				// ===============================================================================================
				// ===============================================================================================
				// ===============================================================================================
				// ===============================================================================================
				Vehicle vehicle;

				// Verificar que los espacios no esten vacios
				if (dniText->Length == 0 || nombreText->Length == 0 || passText->Length == 0 || confirmText->Length == 0) {
					MessageBox::Show("Por favor llene todos los campos", "Registro", MessageBoxButtons::OK);
					return;
				}

				//Verificar si las contraseñas coinciden
				if (String::Compare(passText, confirmText) != 0) {
					MessageBox::Show("Las contrasenas no coinciden", "Registro", MessageBoxButtons::OK);
					return;
				}

				//Verificar si se pudo o no acceder al gestionador de archivos
				if (authManager == nullptr) {
					MessageBox::Show("No se pudo acceder al gestor de usuarios", "Registro", MessageBoxButtons::OK);
					return;
				}

				// Converitr con marshal as al tipo de dato que quiero segun un String^
				std::string dnii = msclr::interop::marshal_as<std::string>(dniText);
				std::string nombre = msclr::interop::marshal_as<std::string>(nombreText);
				std::string passs = msclr::interop::marshal_as<std::string>(passText);

				// Hacer validacion de los digitos del dni en el caso no tenga 8 o no sea int
				if (!authManager->validateDni(dnii)) {
					MessageBox::Show("DNI invalido. Debe tener 8 digitos numericos.", "Registro", MessageBoxButtons::OK);
					return;
				}

				// Validar si el DNI ya se encuentra registrado con dni nombre y contraseña pass en la funcion de authmanager
				//if (!authManager->registerDriver(nombre, dni, pass, vehicle)) {
				//	MessageBox::Show("El DNI ya esta registrado.", "Registro", MessageBoxButtons::OK);
				//	return;
				//}

				// Validar si la cuenta fue creada correctamente y se guardo todo correctamente o no , con save a password binary q devuelve true or false de guardar binario d fmanager
				
				if (!authManager->savePasswordsBinary()) {
					MessageBox::Show("La cuenta fue creada, pero no se pudo actualizar passwords.bin.", "Registro", MessageBoxButtons::OK);
				}
				else {
					MessageBox::Show("Cuenta creada correctamente.", "Registro", MessageBoxButtons::OK);
				}
				
				switchToVehicle = true;
				
				FormsStatus::SaveWindow(this);
				_internalClose = true;
				//this->Close();

				name = nombreText;
				dni = dniText;
				pass = passText;
				
				this->Hide(); // ocultar MainMenu
			}


			void RegisterAdmin() {}


			// linkerlabelClick
			System::Void llblAviso2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
			{
				this->switchToLogin = true;
				FormsStatus::SaveWindow(this);
				_internalClose = true;
				//this->Close();
				this->Hide();
			}

			// pictureLYNXClick
			System::Void pictureBoxIcon_Click(System::Object^ sender, System::EventArgs^ e)
			{
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

			System::Void RegisterPassengerForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
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

						FormsStatus::isFullscreen = false;

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
		// Register resize
		// 
			System::Void RegisterPassengerForm_Resize(System::Object^ sender, System::EventArgs^ e)
			{
				// DESACTIVAR CLOSE BUTTON
				HWND hWnd = static_cast<HWND>(this->Handle.ToPointer());
				HMENU hMenu = ::GetSystemMenu(hWnd, FALSE);
				::EnableMenuItem(hMenu, SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
				::DrawMenuBar(hWnd);
			}


		//
		// Register cerrado closing
		// 
			System::Void RegisterPassengerForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
			{
				if (!_internalClose)
				{
				
					System::Windows::Forms::Application::Exit();
				}
				
				_internalClose = false;
			}
		
		
		
};
}
