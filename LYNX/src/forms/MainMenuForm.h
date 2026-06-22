#pragma once
#pragma comment(lib, "user32.lib")

#include "PassengerMenuForm.h"
#include "DriverMenuForm.h"
#include "AdminMenuForm.h"
#include "LoginPassengerForm.h"
#include "RegisterPassengerForm.h"
#include "../library/FormsStatus.h"	
#include "../AuthManager.h"
#include "../TripManager.h"

#include <vector>
#include <string>

namespace LYNX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		MainMenuForm(void)
		{
			InitializeComponent();

			// CONSTRUIR OBJETOS DE MANEJO USERS Y TRIPS
			authManager = new AuthManager();
			tripManager = new TripManager();
			fileManager = new FileManager();

			// CARGAR TODOS LOS VIAJES
			LoadTripsFromFile();

			formlg = gcnew LoginPassengerForm(authManager, tripManager, 1);
			formrg = gcnew RegisterPassengerForm(authManager, tripManager, 1);
			formvr = gcnew VehicleRegisterForm(authManager, tripManager);

			// CENTRAR TODO
			this->CenterToScreen();

			// ACTIVAR F11
			this->KeyPreview = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false; // quitar maximizar

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

	protected:
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
			delete authManager;
			delete tripManager;
			delete fileManager;
		}

		// OBJETOS
	private:
		AuthManager* authManager = nullptr;
		TripManager* tripManager = nullptr;
		FileManager* fileManager = nullptr;

		LoginPassengerForm^ formlg = nullptr;
		RegisterPassengerForm^ formrg = nullptr;

		PassengerMenuForm^ formpm = nullptr;
		DriverMenuForm^ formdrimenu = nullptr;
		AdminMenuForm^ formadminmenu = nullptr;
		VehicleRegisterForm^ formvr = nullptr;

		int currentLoginStyle = 1;
		int currentRegisterStyle = 1;

		// COMPONENTES
			// Barra superior LYNX
	private: System::Windows::Forms::Panel^ pnlTopBar;
	private: System::Windows::Forms::PictureBox^ pictureBoxIcon;
	private: System::Windows::Forms::Label^ lblLYNX;

		   // Panel de presentacion
	private: System::Windows::Forms::Panel^ pnlPresentacion;
	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ lblDescripcion;
	private: System::Windows::Forms::Label^ lblSubDesc;

		   // Tarjeta Pas
	private: System::Windows::Forms::Panel^ pnlTarjetaPasajero;
	private: System::Windows::Forms::Panel^ pnlDecoPasajero;
	private: System::Windows::Forms::Label^ lblTitPasajero;
	private: System::Windows::Forms::Label^ lblDescPasajero;
	private: System::Windows::Forms::Button^ btnIngresarPasajero;

		   // Tarjeta Cond
	private: System::Windows::Forms::Panel^ pnlTarjetaConductor;
	private: System::Windows::Forms::Panel^ pnlDecoConductor;
	private: System::Windows::Forms::Label^ lblTitConductor;
	private: System::Windows::Forms::Label^ lblDescConductor;
	private: System::Windows::Forms::Button^ btnIngresarConductor;

		   // Tarjeta Admin
	private: System::Windows::Forms::Panel^ pnlTarjetaAdmin;
	private: System::Windows::Forms::Panel^ pnlDecoAdmin;
	private: System::Windows::Forms::Label^ lblTitAdmin;
	private: System::Windows::Forms::Label^ lblDescAdmin;
	private: System::Windows::Forms::Button^ btnIngresarAdmin;

		   // Barra inferior con info del proyecto
	private: System::Windows::Forms::Panel^ pnlBarraInferior;
	private: System::Windows::Forms::Label^ lblNombreProyecto;
	private: System::Windows::Forms::Label^ lblInfoProyecto;

		   // Timer para detectar cambios entre formularios
	private: System::Windows::Forms::Timer^ timer1;

	private: System::ComponentModel::IContainer^ components;

		   // WINDOWS INITIALIZE
	private:
	#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());

			// Instanciar todos los controles
			this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
			this->lblLYNX = (gcnew System::Windows::Forms::Label());
			// pnlPresentacion reemplaza a pnlOpciones
			this->pnlPresentacion = (gcnew System::Windows::Forms::Panel());
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->lblDescripcion = (gcnew System::Windows::Forms::Label());
			this->lblSubDesc = (gcnew System::Windows::Forms::Label());
			// Tarjetas
			this->pnlTarjetaPasajero = (gcnew System::Windows::Forms::Panel());
			this->pnlDecoPasajero = (gcnew System::Windows::Forms::Panel());
			this->lblTitPasajero = (gcnew System::Windows::Forms::Label());
			this->lblDescPasajero = (gcnew System::Windows::Forms::Label());
			this->btnIngresarPasajero = (gcnew System::Windows::Forms::Button());
			this->pnlTarjetaConductor = (gcnew System::Windows::Forms::Panel());
			this->pnlDecoConductor = (gcnew System::Windows::Forms::Panel());
			this->lblTitConductor = (gcnew System::Windows::Forms::Label());
			this->lblDescConductor = (gcnew System::Windows::Forms::Label());
			this->btnIngresarConductor = (gcnew System::Windows::Forms::Button());
			this->pnlTarjetaAdmin = (gcnew System::Windows::Forms::Panel());
			this->pnlDecoAdmin = (gcnew System::Windows::Forms::Panel());
			this->lblTitAdmin = (gcnew System::Windows::Forms::Label());
			this->lblDescAdmin = (gcnew System::Windows::Forms::Label());
			this->btnIngresarAdmin = (gcnew System::Windows::Forms::Button());

			this->pnlBarraInferior = (gcnew System::Windows::Forms::Panel());
			this->lblNombreProyecto = (gcnew System::Windows::Forms::Label());
			this->lblInfoProyecto = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));

			this->pnlTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->pnlPresentacion->SuspendLayout();
			this->pnlTarjetaPasajero->SuspendLayout();
			this->pnlTarjetaConductor->SuspendLayout();
			this->pnlTarjetaAdmin->SuspendLayout();
			this->pnlBarraInferior->SuspendLayout();
			this->SuspendLayout();

			// 
			// pnlTopBar
			// 
			this->pnlTopBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlTopBar->BackColor = System::Drawing::Color::FromArgb(6, 98, 70);
			this->pnlTopBar->Controls->Add(this->pictureBoxIcon);
			this->pnlTopBar->Controls->Add(this->lblLYNX);
			this->pnlTopBar->Location = System::Drawing::Point(0, 0);
			this->pnlTopBar->Name = L"pnlTopBar";
			this->pnlTopBar->Size = System::Drawing::Size(1480, 78);
			this->pnlTopBar->TabIndex = 0;

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
			this->pictureBoxIcon->Click += gcnew System::EventHandler(this, &MainMenuForm::pictureBoxIcon_Click);

			// 
			// lblLYNX
			// 
			this->lblLYNX->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 22, System::Drawing::FontStyle::Bold));
			this->lblLYNX->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
			this->lblLYNX->Location = System::Drawing::Point(91, 18);
			this->lblLYNX->Name = L"lblLYNX";
			this->lblLYNX->Size = System::Drawing::Size(120, 40);
			this->lblLYNX->TabIndex = 0;
			this->lblLYNX->Text = L"LYNX";

			// 
			// pnlPresentacion-> reemplaza pnlOpciones
			// 
			this->pnlPresentacion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlPresentacion->BackColor = System::Drawing::Color::FromArgb(24, 28, 34);
			this->pnlPresentacion->Controls->Add(this->lblBienvenida);
			this->pnlPresentacion->Controls->Add(this->lblDescripcion);
			this->pnlPresentacion->Controls->Add(this->lblSubDesc);
			this->pnlPresentacion->Location = System::Drawing::Point(0, 78);
			this->pnlPresentacion->Name = L"pnlPresentacion";
			this->pnlPresentacion->Size = System::Drawing::Size(1480, 380);
			this->pnlPresentacion->TabIndex = 1;

			// 
			// lblBienvenida
			// 
			this->lblBienvenida->BackColor = System::Drawing::Color::FromArgb(39, 56, 43);
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblBienvenida->ForeColor = System::Drawing::Color::FromArgb(194, 239, 113);
			this->lblBienvenida->Location = System::Drawing::Point(50, 38);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(300, 32);
			this->lblBienvenida->TabIndex = 0;
			this->lblBienvenida->Text = L"  Bienvenido a LYNX  ";
			this->lblBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// lblDescripcion-> reemplaza lblPnlOpciones
			// 
			this->lblDescripcion->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 28, System::Drawing::FontStyle::Bold));
			this->lblDescripcion->ForeColor = System::Drawing::Color::White;
			this->lblDescripcion->Location = System::Drawing::Point(48, 84);
			this->lblDescripcion->Name = L"lblDescripcion";
			this->lblDescripcion->Size = System::Drawing::Size(1100, 156);
			this->lblDescripcion->TabIndex = 1;
			this->lblDescripcion->Text = L"Solo dinos donde.\nNosotros nos encargamos del resto.";

			// 
			// lblSubDesc -> reemplaza lblInfo
			// 
			this->lblSubDesc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->lblSubDesc->ForeColor = System::Drawing::Color::FromArgb(160, 175, 168);
			this->lblSubDesc->Location = System::Drawing::Point(52, 254);
			this->lblSubDesc->Name = L"lblSubDesc";
			this->lblSubDesc->Size = System::Drawing::Size(1100, 80);
			this->lblSubDesc->TabIndex = 2;
			this->lblSubDesc->Text = L"Selecciona tu perfil para comenzar. Puedes ingresar como pasajero, conductor o ad"
				L"ministrador del sistema.";

			// 
			// pnlTarjetaPasajero
			// 
			this->pnlTarjetaPasajero->BackColor = System::Drawing::Color::White;
			this->pnlTarjetaPasajero->Controls->Add(this->pnlDecoPasajero);
			this->pnlTarjetaPasajero->Controls->Add(this->lblTitPasajero);
			this->pnlTarjetaPasajero->Controls->Add(this->lblDescPasajero);
			this->pnlTarjetaPasajero->Controls->Add(this->btnIngresarPasajero);
			this->pnlTarjetaPasajero->Location = System::Drawing::Point(33, 490);
			this->pnlTarjetaPasajero->Name = L"pnlTarjetaPasajero";
			this->pnlTarjetaPasajero->Size = System::Drawing::Size(444, 290);
			this->pnlTarjetaPasajero->TabIndex = 3;

			// 
			// pnlDecoPasajero
			// 
			this->pnlDecoPasajero->BackColor = System::Drawing::Color::FromArgb(33, 181, 109);
			this->pnlDecoPasajero->Location = System::Drawing::Point(24, 22);
			this->pnlDecoPasajero->Name = L"pnlDecoPasajero";
			this->pnlDecoPasajero->Size = System::Drawing::Size(396, 8);
			this->pnlDecoPasajero->TabIndex = 0;

			// 
			// lblTitPasajero
			// 
			this->lblTitPasajero->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblTitPasajero->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
			this->lblTitPasajero->Location = System::Drawing::Point(24, 46);
			this->lblTitPasajero->Name = L"lblTitPasajero";
			this->lblTitPasajero->Size = System::Drawing::Size(396, 40);
			this->lblTitPasajero->TabIndex = 1;
			this->lblTitPasajero->Text = L"Pasajero";

			// 
			// lblDescPasajero
			// 
			this->lblDescPasajero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->lblDescPasajero->ForeColor = System::Drawing::Color::FromArgb(96, 102, 110);
			this->lblDescPasajero->Location = System::Drawing::Point(24, 96);
			this->lblDescPasajero->Name = L"lblDescPasajero";
			this->lblDescPasajero->Size = System::Drawing::Size(396, 76);
			this->lblDescPasajero->TabIndex = 2;
			this->lblDescPasajero->Text = L"Solicita tu viaje, consulta tu historial y gestiona tu perfil personal.";

			// 
			// btnIngresarPasajero
			// 
			this->btnIngresarPasajero->BackColor = System::Drawing::Color::FromArgb(245, 247, 243);
			this->btnIngresarPasajero->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(33, 181, 109);
			this->btnIngresarPasajero->FlatAppearance->BorderSize = 1;
			this->btnIngresarPasajero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIngresarPasajero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnIngresarPasajero->ForeColor = System::Drawing::Color::FromArgb(31, 36, 42);
			this->btnIngresarPasajero->Location = System::Drawing::Point(24, 226);
			this->btnIngresarPasajero->Name = L"btnIngresarPasajero";
			this->btnIngresarPasajero->Size = System::Drawing::Size(396, 44);
			this->btnIngresarPasajero->TabIndex = 3;
			this->btnIngresarPasajero->Text = L"Ingresar como pasajero";
			this->btnIngresarPasajero->UseVisualStyleBackColor = false;
			this->btnIngresarPasajero->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenPassengerForm);
			this->btnIngresarPasajero->MouseEnter += gcnew System::EventHandler(this, &MainMenuForm::btnPasajero_MouseEnter);
			this->btnIngresarPasajero->MouseLeave += gcnew System::EventHandler(this, &MainMenuForm::btnPasajero_MouseLeave);

			// 
			// pnlTarjetaConductor
			// 
			this->pnlTarjetaConductor->BackColor = System::Drawing::Color::White;
			this->pnlTarjetaConductor->Controls->Add(this->pnlDecoConductor);
			this->pnlTarjetaConductor->Controls->Add(this->lblTitConductor);
			this->pnlTarjetaConductor->Controls->Add(this->lblDescConductor);
			this->pnlTarjetaConductor->Controls->Add(this->btnIngresarConductor);
			this->pnlTarjetaConductor->Location = System::Drawing::Point(517, 490);
			this->pnlTarjetaConductor->Name = L"pnlTarjetaConductor";
			this->pnlTarjetaConductor->Size = System::Drawing::Size(444, 290);
			this->pnlTarjetaConductor->TabIndex = 4;

			// 
			// pnlDecoConductor
			// 
			this->pnlDecoConductor->BackColor = System::Drawing::Color::FromArgb(39, 50, 120);
			this->pnlDecoConductor->Location = System::Drawing::Point(24, 22);
			this->pnlDecoConductor->Name = L"pnlDecoConductor";
			this->pnlDecoConductor->Size = System::Drawing::Size(396, 8);
			this->pnlDecoConductor->TabIndex = 0;

			// 
			// lblTitConductor
			// 
			this->lblTitConductor->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblTitConductor->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
			this->lblTitConductor->Location = System::Drawing::Point(24, 46);
			this->lblTitConductor->Name = L"lblTitConductor";
			this->lblTitConductor->Size = System::Drawing::Size(396, 40);
			this->lblTitConductor->TabIndex = 1;
			this->lblTitConductor->Text = L"Conductor";

			// 
			// lblDescConductor
			// 
			this->lblDescConductor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->lblDescConductor->ForeColor = System::Drawing::Color::FromArgb(96, 102, 110);
			this->lblDescConductor->Location = System::Drawing::Point(24, 96);
			this->lblDescConductor->Name = L"lblDescConductor";
			this->lblDescConductor->Size = System::Drawing::Size(396, 76);
			this->lblDescConductor->TabIndex = 2;
			this->lblDescConductor->Text = L"Revisa tus solicitudes y ganancias, gestiona tu disponibilidad y vehiculo, y ve tu historial.";

			// 
			// btnIngresarConductor
			// 
			this->btnIngresarConductor->BackColor = System::Drawing::Color::FromArgb(245, 247, 253);
			this->btnIngresarConductor->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(39, 50, 120);
			this->btnIngresarConductor->FlatAppearance->BorderSize = 1;
			this->btnIngresarConductor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIngresarConductor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnIngresarConductor->ForeColor = System::Drawing::Color::FromArgb(31, 36, 42);
			this->btnIngresarConductor->Location = System::Drawing::Point(24, 226);
			this->btnIngresarConductor->Name = L"btnIngresarConductor";
			this->btnIngresarConductor->Size = System::Drawing::Size(396, 44);
			this->btnIngresarConductor->TabIndex = 3;
			this->btnIngresarConductor->Text = L"Ingresar como conductor";
			this->btnIngresarConductor->UseVisualStyleBackColor = false;
			this->btnIngresarConductor->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenDriverForm);
			this->btnIngresarConductor->MouseEnter += gcnew System::EventHandler(this, &MainMenuForm::btnConductor_MouseEnter);
			this->btnIngresarConductor->MouseLeave += gcnew System::EventHandler(this, &MainMenuForm::btnConductor_MouseLeave);

			// 
			// pnlTarjetaAdmin
			// 
			this->pnlTarjetaAdmin->BackColor = System::Drawing::Color::White;
			this->pnlTarjetaAdmin->Controls->Add(this->pnlDecoAdmin);
			this->pnlTarjetaAdmin->Controls->Add(this->lblTitAdmin);
			this->pnlTarjetaAdmin->Controls->Add(this->lblDescAdmin);
			this->pnlTarjetaAdmin->Controls->Add(this->btnIngresarAdmin);
			this->pnlTarjetaAdmin->Location = System::Drawing::Point(1001, 490);
			this->pnlTarjetaAdmin->Name = L"pnlTarjetaAdmin";
			this->pnlTarjetaAdmin->Size = System::Drawing::Size(444, 290);
			this->pnlTarjetaAdmin->TabIndex = 5;

			// 
			// pnlDecoAdmin
			// 
			this->pnlDecoAdmin->BackColor = System::Drawing::Color::FromArgb(57, 107, 239);
			this->pnlDecoAdmin->Location = System::Drawing::Point(24, 22);
			this->pnlDecoAdmin->Name = L"pnlDecoAdmin";
			this->pnlDecoAdmin->Size = System::Drawing::Size(396, 8);
			this->pnlDecoAdmin->TabIndex = 0;

			// 
			// lblTitAdmin
			// 
			this->lblTitAdmin->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblTitAdmin->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
			this->lblTitAdmin->Location = System::Drawing::Point(24, 46);
			this->lblTitAdmin->Name = L"lblTitAdmin";
			this->lblTitAdmin->Size = System::Drawing::Size(396, 40);
			this->lblTitAdmin->TabIndex = 1;
			this->lblTitAdmin->Text = L"Administrador";

			// 
			// lblDescAdmin
			// 
			this->lblDescAdmin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->lblDescAdmin->ForeColor = System::Drawing::Color::FromArgb(96, 102, 110);
			this->lblDescAdmin->Location = System::Drawing::Point(24, 96);
			this->lblDescAdmin->Name = L"lblDescAdmin";
			this->lblDescAdmin->Size = System::Drawing::Size(396, 76);
			this->lblDescAdmin->TabIndex = 2;
			this->lblDescAdmin->Text = L"Accede al panel de control: usuarios, viajes, estadisticas y el control general del sistema.";

			// 
			// btnIngresarAdmin
			// 
			this->btnIngresarAdmin->BackColor = System::Drawing::Color::FromArgb(242, 245, 253);
			this->btnIngresarAdmin->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(57, 107, 239);
			this->btnIngresarAdmin->FlatAppearance->BorderSize = 1;
			this->btnIngresarAdmin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIngresarAdmin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnIngresarAdmin->ForeColor = System::Drawing::Color::FromArgb(31, 36, 42);
			this->btnIngresarAdmin->Location = System::Drawing::Point(24, 226);
			this->btnIngresarAdmin->Name = L"btnIngresarAdmin";
			this->btnIngresarAdmin->Size = System::Drawing::Size(396, 44);
			this->btnIngresarAdmin->TabIndex = 3;
			this->btnIngresarAdmin->Text = L"Ingresar como administrador";
			this->btnIngresarAdmin->UseVisualStyleBackColor = false;
			this->btnIngresarAdmin->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenAdminForm);
			this->btnIngresarAdmin->MouseEnter += gcnew System::EventHandler(this, &MainMenuForm::btnAdmin_MouseEnter);
			this->btnIngresarAdmin->MouseLeave += gcnew System::EventHandler(this, &MainMenuForm::btnAdmin_MouseLeave);

			// 
			// pnlBarraInferior
			// 
			this->pnlBarraInferior->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlBarraInferior->BackColor = System::Drawing::Color::White;
			this->pnlBarraInferior->Controls->Add(this->lblNombreProyecto);
			this->pnlBarraInferior->Controls->Add(this->lblInfoProyecto);
			this->pnlBarraInferior->Location = System::Drawing::Point(0, 820);
			this->pnlBarraInferior->Name = L"pnlBarraInferior";
			this->pnlBarraInferior->Size = System::Drawing::Size(1480, 110);
			this->pnlBarraInferior->TabIndex = 6;

			// 
			// lblNombreProyecto
			// 
			this->lblNombreProyecto->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 14, System::Drawing::FontStyle::Bold));
			this->lblNombreProyecto->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
			this->lblNombreProyecto->Location = System::Drawing::Point(32, 20);
			this->lblNombreProyecto->Name = L"lblNombreProyecto";
			this->lblNombreProyecto->AutoSize = true;
			this->lblNombreProyecto->TabIndex = 0;
			this->lblNombreProyecto->Text = L"LYNX  |  Sistema de gestion de transporte";

			// 
			// lblInfoProyecto
			// 
			this->lblInfoProyecto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblInfoProyecto->ForeColor = System::Drawing::Color::FromArgb(120, 130, 125);
			this->lblInfoProyecto->Location = System::Drawing::Point(34, 56);
			this->lblInfoProyecto->Name = L"lblInfoProyecto";
			this->lblInfoProyecto->AutoSize = true;
			this->lblInfoProyecto->TabIndex = 1;
			this->lblInfoProyecto->Text = L"LYNX  |  Sistema de optimización de rutas y asignación de conductores  |  Presion"
				L"a F11 para pantalla completa";

			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainMenuForm::timer1_Tick);

			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(245, 247, 245);
			this->ClientSize = System::Drawing::Size(1480, 930);
			this->Controls->Add(this->pnlTopBar);
			this->Controls->Add(this->pnlPresentacion);
			this->Controls->Add(this->pnlTarjetaPasajero);
			this->Controls->Add(this->pnlTarjetaConductor);
			this->Controls->Add(this->pnlTarjetaAdmin);
			this->Controls->Add(this->pnlBarraInferior);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimumSize = System::Drawing::Size(1280, 820);
			this->Name = L"MainMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LYNX | Inicio";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainMenuForm::MainMenuForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainMenuForm::MainMenuForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_Resize);

			this->pnlTopBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
			this->pnlPresentacion->ResumeLayout(false);
			this->pnlTarjetaPasajero->ResumeLayout(false);
			this->pnlTarjetaConductor->ResumeLayout(false);
			this->pnlTarjetaAdmin->ResumeLayout(false);
			this->pnlBarraInferior->ResumeLayout(false);
			this->pnlBarraInferior->PerformLayout();
			this->ResumeLayout(false);
		}

		// LOGICA
	#pragma endregion
	private:

		//
		// Load Trips from file
		//
		void LoadTripsFromFile()
		{
			if (fileManager == nullptr || tripManager == nullptr) return; 
			if (fileManager == nullptr) return;
			std::vector<Trip> trips = fileManager->leerTripsTXT(); 
			
			for (int i = 0; i < (int)trips.size(); i++)
			{
				std::string status = trips[i].getStatus();

				if (status == "pendiente")
				{
					tripManager->getWaitingQueue().enqueue(trips[i]);
				}
				else if (status == "en_curso")
				{
					tripManager->getActiveTrips().pushBack(trips[i]);
				}
				else
				{
					tripManager->getHistory().push(trips[i]);
				}
			}

			tripManager->rebuildTripCounter();
		}

		//
		// Load Form
		// 
		System::Void MainMenuForm_Load(System::Object^ sender, System::EventArgs^ e)
		{
			// Para Picture Box LYNX
			try
			{
				this->pictureBoxIcon->Image = System::Drawing::Image::FromFile("resources/LYNX_image.png");
				this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			}
			catch (...) {}

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
		// Botones functions
		// 

		// btnAbrirPasajeroClick
		System::Void OpenPassengerForm(System::Object^ sender, System::EventArgs^ e)
		{
			menuLoginOptions(1);
		}

		// btnAbrirConductorClick
		System::Void OpenDriverForm(System::Object^ sender, System::EventArgs^ e)
		{
			menuLoginOptions(2);
		}

		// btnAbrirAdministradorClick
		System::Void OpenAdminForm(System::Object^ sender, System::EventArgs^ e)
		{
			menuLoginOptions(3);
		}

		//
		// Funcion General
		//
		void menuLoginOptions(int style)
		{
			if (style < 1 || style > 3)
			{
				style = 1;
			}

			currentLoginStyle = style;
			currentRegisterStyle = currentLoginStyle;

			if (formlg != nullptr && !formlg->IsDisposed)
			{
				delete formlg;
			}

			formlg = gcnew LoginPassengerForm(authManager, tripManager, currentLoginStyle);
			FormsStatus::SaveWindow(this);
			FormsStatus::ApplyWindow(formlg);
			formlg->Show();
			formlg->BringToFront();
			this->Hide(); // ocultar MainMenu
		}
		
		//
		// Hover functions: cambia color del boton al pasar el mouse
		//

		// Pas
		System::Void btnPasajero_MouseEnter(System::Object^ sender, System::EventArgs^ e)
		{
			btnIngresarPasajero->BackColor = System::Drawing::Color::FromArgb(33, 181, 109);
			btnIngresarPasajero->ForeColor = System::Drawing::Color::White;
			btnIngresarPasajero->FlatAppearance->BorderSize = 0;
		}
		System::Void btnPasajero_MouseLeave(System::Object^ sender, System::EventArgs^ e)
		{
			btnIngresarPasajero->BackColor = System::Drawing::Color::FromArgb(245, 247, 243);
			btnIngresarPasajero->ForeColor = System::Drawing::Color::FromArgb(31, 36, 42);
			btnIngresarPasajero->FlatAppearance->BorderSize = 1;
		}

		// Cond
		System::Void btnConductor_MouseEnter(System::Object^ sender, System::EventArgs^ e)
		{
			btnIngresarConductor->BackColor = System::Drawing::Color::FromArgb(39, 50, 120);
			btnIngresarConductor->ForeColor = System::Drawing::Color::White;
			btnIngresarConductor->FlatAppearance->BorderSize = 0;
		}
		System::Void btnConductor_MouseLeave(System::Object^ sender, System::EventArgs^ e)
		{
			btnIngresarConductor->BackColor = System::Drawing::Color::FromArgb(245, 247, 253);
			btnIngresarConductor->ForeColor = System::Drawing::Color::FromArgb(31, 36, 42);
			btnIngresarConductor->FlatAppearance->BorderSize = 1;
		}

		// Admin
		System::Void btnAdmin_MouseEnter(System::Object^ sender, System::EventArgs^ e)
		{
			btnIngresarAdmin->BackColor = System::Drawing::Color::FromArgb(57, 107, 239);
			btnIngresarAdmin->ForeColor = System::Drawing::Color::White;
			btnIngresarAdmin->FlatAppearance->BorderSize = 0;
		}
		System::Void btnAdmin_MouseLeave(System::Object^ sender, System::EventArgs^ e)
		{
			btnIngresarAdmin->BackColor = System::Drawing::Color::FromArgb(242, 245, 253);
			btnIngresarAdmin->ForeColor = System::Drawing::Color::FromArgb(31, 36, 42);
			btnIngresarAdmin->FlatAppearance->BorderSize = 1;
		}

		//
		// Timer functions
		// 
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			// Revisa si el form de login existe, no fue destruido, y pidio cambiar a pantalla de registro
			if (formlg != nullptr && !formlg->IsDisposed && formlg->switchToRegister) {
				formlg->switchToRegister = false; // apaga la bandera para no repetir esta accion en el siguiente tick

				// Siempre recrear con el estilo actual
				// Si ya existia un form de registro previo (no destruido), lo elimina antes de crear uno nuevo
				if (formrg != nullptr && !formrg->IsDisposed)
					delete formrg;

				// Crea el form de registro nuevo con el estilo de registro actual (pasajero/conductor/admin)
				formrg = gcnew RegisterPassengerForm(authManager, tripManager, currentRegisterStyle);
				FormsStatus::ApplyWindow(formrg); // aplica el estado de ventana (normal o pantalla completa) guardado
				formrg->Show();
				// Nota: aqui no se oculta el form de login ni se hace BringToFront, a diferencia de otros bloques
			}

			// Revisa si el form de register existe, no fue destruido, y pidio volver a login
			if (formrg != nullptr && !formrg->IsDisposed && formrg->switchToLogin) {
				formrg->switchToLogin = false;

				if (formlg == nullptr || formlg->IsDisposed) {
					formlg = gcnew LoginPassengerForm(authManager, tripManager, currentLoginStyle); // Verifica y crea
				}

				FormsStatus::ApplyWindow(formlg);
				formlg->Show();  // Muestra
			}

			// Revisa si el form de register existe, no fue destruido, y pidio cambiar a pantalla de vehicle
			if (formrg != nullptr && !formrg->IsDisposed && formrg->switchToVehicle) {
				formrg->switchToVehicle = false;

				if (formvr == nullptr || formvr->IsDisposed) {
					formvr = gcnew VehicleRegisterForm(authManager, tripManager); // Verifica y crea
				}

				// Copia los datos ya ingresados en el registro de pasajero (nombre, dni, password)
				// hacia el form de vehiculo, para no pedirlos de nuevo
				formvr->name = formrg->name;
				formvr->dni = formrg->dni;
				formvr->pass = formrg->pass;
				FormsStatus::ApplyWindow(formvr);  // aplica el estado de ventana guardado
				formvr->Show();  // Muestra
			}

			// Revisa si el form de vehiculo existe, no fue destruido, y pidio volver al registro
			if (formvr != nullptr && !formvr->IsDisposed && formvr->switchToRegister) {
				formvr->switchToRegister = false;
				
				// Solo crea el form de login si no existe uno valido
				if (formrg == nullptr || formrg->IsDisposed) {
					formrg = gcnew RegisterPassengerForm(authManager, tripManager, currentLoginStyle); // Verifica y crea
				}

				FormsStatus::ApplyWindow(formrg);  // aplica el estado de ventana guardado
				formrg->Show();  // Muestra
			}

			// Revisa si el form de vehiculo existe, no fue destruido, y pidio volver a login
			if (formvr != nullptr && !formvr->IsDisposed && formvr->switchToLogin) {
				formvr->switchToLogin = false;

				// Solo crea el form de registro si no existe uno valido
				if (formlg == nullptr || formlg->IsDisposed) {
					formlg = gcnew LoginPassengerForm(authManager, tripManager, currentLoginStyle); // Verifica y crea
				}

				FormsStatus::ApplyWindow(formlg);   // aplica el estado de ventana guardado
				formlg->Show();  // Muestra
			}

			// Revisa si el form de login existe, no fue destruido, y el login de pasajero fue exitoso
			if (formlg != nullptr && !formlg->IsDisposed && formlg->passengerScreen)
			{
				formlg->passengerScreen = false;

				String^ passengerDni = formlg->loggedPassengerDni; // recupera el dni del pasajero que inicio sesion
				
				// Si ya existia un menu de pasajero previo (no destruido), lo elimina antes de crear uno nuevo
				if (formpm != nullptr && !formpm->IsDisposed) delete formpm;

				// Crea el menu de pasajero pasandole el dni que inicio sesion
				formpm = gcnew PassengerMenuForm(authManager, tripManager, passengerDni, fileManager);
				FormsStatus::ApplyWindow(formpm);// aplica el estado de ventana guardado

				// Copia nombre, dni y password recordados desde el form de login hacia el menu de pasajero
				formpm->name = formlg->names;
				formpm->dni = formlg->dnis;
				formpm->password = formlg->passwords;
				formpm->Show();

				formpm->BringToFront(); 
				formlg->Hide();         
			}

			// Revisa si el form de login existe, no fue destruido, y el login de conductor fue exitoso
			if (formlg != nullptr && !formlg->IsDisposed && formlg->driverScreen)
			{
				formlg->driverScreen = false;

				String^ driverDni = formlg->loggedDriverDni; // recupera el dni del driver que inicio sesion

				if (formdrimenu != nullptr && !formdrimenu->IsDisposed) delete formdrimenu;

				// Crea el menu de conductor pasandole el dni que inicio sesion
				formdrimenu = gcnew DriverMenuForm(authManager, tripManager, driverDni, fileManager);
				FormsStatus::ApplyWindow(formdrimenu);// aplica el estado de ventana guardado

				// Copia nombre, dni y password recordados desde el form de login hacia el menu de conductor
				formdrimenu->name = formlg->names;
				formdrimenu->dni = formlg->dnis;
				formdrimenu->password = formlg->passwords;
				formdrimenu->Show();

				formdrimenu->BringToFront();
				formlg->Hide();
			}

			// Revisa si el form de login existe, no fue destruido, y el login de admin fue exitoso
			if (formlg != nullptr && !formlg->IsDisposed && formlg->adminScreen)
			{
				formlg->adminScreen = false;

				if (formadminmenu != nullptr && !formadminmenu->IsDisposed) delete formadminmenu;

				// Crea el menu de admin
				formadminmenu = gcnew AdminMenuForm(authManager, tripManager);
				FormsStatus::ApplyWindow(formadminmenu);

				//formadminmenu->
				//formadminmenu->
				formadminmenu->Show();

				formadminmenu->BringToFront();
				formlg->Hide();
			}
		}

		//
		// Full screen function
		// 
		System::Drawing::Size normalSize;
		System::Drawing::Point normalLocation;
		System::Windows::Forms::FormWindowState normalState;

		System::Void MainMenuForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
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
					try { this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico"); }
					catch (...) {}
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
				try { this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico"); }
				catch (...) {}
			}
		}

		//
		// Closing de Form function
		// 
		System::Void MainMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			System::Windows::Forms::Application::Exit();
		}

		//
		// Click functions
		// 
		System::Void pictureBoxIcon_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Show();
			this->BringToFront();
		}

		//
		// Resize function: reposiciona y redimensiona las 3 tarjetas segun el ancho del form
		//
		System::Void MainMenuForm_Resize(System::Object^ sender, System::EventArgs^ e)
		{
			int formW = this->ClientSize.Width;
			int formH = this->ClientSize.Height;

			// Barra LYNX y panel presentacion: forzar alto fijo
			this->pnlTopBar->Size = System::Drawing::Size(formW, 78);
			this->pnlPresentacion->Size = System::Drawing::Size(formW, 380);

			// Margen lateral y separacion entre tarjetas
			int margen = 33;
			int gap = 40;
			int tarjetas = 3;

			// Ancho disponible para las 3 tarjetas
			int totalGaps = margen * 2 + gap * (tarjetas - 1);
			int cardW = (formW - totalGaps) / tarjetas;
			int cardH = 290;

			// Posicion "Y" a 490 del tope original
			int cardY = 490;

			// Reubicar tarjeta Pas
			this->pnlTarjetaPasajero->Location = System::Drawing::Point(margen, cardY);
			this->pnlTarjetaPasajero->Size = System::Drawing::Size(cardW, cardH);

			// Ajustar info de Pas
			this->pnlDecoPasajero->Size = System::Drawing::Size(cardW - 48, 8);
			this->lblTitPasajero->Size = System::Drawing::Size(cardW - 48, 40);
			this->lblDescPasajero->Size = System::Drawing::Size(cardW - 48, 76);
			this->btnIngresarPasajero->Size = System::Drawing::Size(cardW - 48, 44);

			// Reubicar Cond
			int x2 = margen + cardW + gap;
			this->pnlTarjetaConductor->Location = System::Drawing::Point(x2, cardY);
			this->pnlTarjetaConductor->Size = System::Drawing::Size(cardW, cardH);

			// Ajustar info de Cond
			this->pnlDecoConductor->Size = System::Drawing::Size(cardW - 48, 8);
			this->lblTitConductor->Size = System::Drawing::Size(cardW - 48, 40);
			this->lblDescConductor->Size = System::Drawing::Size(cardW - 48, 76);
			this->btnIngresarConductor->Size = System::Drawing::Size(cardW - 48, 44);

			// Reubicar Admin
			int x3 = margen + (cardW + gap) * 2;
			this->pnlTarjetaAdmin->Location = System::Drawing::Point(x3, cardY);
			this->pnlTarjetaAdmin->Size = System::Drawing::Size(cardW, cardH);

			// Ajustar info de Admin
			this->pnlDecoAdmin->Size = System::Drawing::Size(cardW - 48, 8);
			this->lblTitAdmin->Size = System::Drawing::Size(cardW - 48, 40);
			this->lblDescAdmin->Size = System::Drawing::Size(cardW - 48, 76);
			this->btnIngresarAdmin->Size = System::Drawing::Size(cardW - 48, 44);

			// Barra inferior: fijada abajo
			this->pnlBarraInferior->Location = System::Drawing::Point(0, formH - pnlBarraInferior->Height);
		}
	};
}