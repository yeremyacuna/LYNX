#pragma once
#pragma comment(lib, "user32.lib")
#include "PassengerMenuForm.h"
#include "DriverMenuForm.h"
#include "AdminMenuForm.h"
#include "LoginPassengerForm.h"
#include "RegisterPassengerForm.h"
#include "../library/FormsStatus.h"	

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

			// CENTRAR TODO
			this->CenterToScreen();

			// ACTIVAR F11
			this->KeyPreview = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false; // quitar maximizar
			// this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainMenuForm::MainMenuForm_KeyDown);

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
		}

		// OBJETOS
	private:
		LoginPassengerForm^ formlg = gcnew LoginPassengerForm();
		RegisterPassengerForm^ formrg = gcnew RegisterPassengerForm();
		PassengerMenuForm^ formpm = gcnew PassengerMenuForm();
	

		// COMPONENTES
	private: System::Windows::Forms::Label^ lblLYNX;
	private: System::Windows::Forms::Panel^ pnlTopBar;
	private: System::Windows::Forms::Panel^ pnlOpciones;
	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ lblPnlOpciones;
	private: System::Windows::Forms::Label^ lblInfo;
	private: System::Windows::Forms::Button^ btnAbrirPasajero;
	private: System::Windows::Forms::Button^ btnAbrirConductor;
	private: System::Windows::Forms::Button^ btnAbrirAdmin;
	private: System::Windows::Forms::Panel^ pnlVistaPrincipal;
	private: System::Windows::Forms::Label^ lblPnlVistaPrincipal;
	private: System::Windows::Forms::Panel^ pnlVerPantallaPasajero;
	private: System::Windows::Forms::Label^ lblPasajero;
	private: System::Windows::Forms::Label^ lblTextPasajero;
	private: System::Windows::Forms::Button^ btnPnlPasajeroVer;
	private: System::Windows::Forms::Panel^ pnlVerPantallaConductor;
	private: System::Windows::Forms::Label^ lblConductor;
	private: System::Windows::Forms::Label^ lblTextConductor;
	private: System::Windows::Forms::Button^ btnPnlConductorVer;
	private: System::Windows::Forms::Panel^ pnlVerPantallaAdministrador;
	private: System::Windows::Forms::Label^ lblAdministrador;
	private: System::Windows::Forms::Label^ lblTextAdministrador;
	private: System::Windows::Forms::Button^ btnPnlAdministradorVer;
	private: System::Windows::Forms::Panel^ pnlBackBar;
	private: System::Windows::Forms::Label^ lblPnlBackBar;
	private: System::Windows::Forms::Label^ lblInfoBackBar;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblMarco2;
	private: System::Windows::Forms::Label^ lblMarco1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBoxIcon;
	private: System::Windows::Forms::Panel^ pnlDecoration2;
	private: System::Windows::Forms::Panel^ pnlDecoration3;
	private: System::Windows::Forms::Panel^ pnlDecoration1;	
	private: System::ComponentModel::IContainer^ components;

		// WINDOWS INITIALIZE
	private:
		#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
			this->lblLYNX = (gcnew System::Windows::Forms::Label());
			this->pnlOpciones = (gcnew System::Windows::Forms::Panel());
			this->btnAbrirAdmin = (gcnew System::Windows::Forms::Button());
			this->btnAbrirConductor = (gcnew System::Windows::Forms::Button());
			this->btnAbrirPasajero = (gcnew System::Windows::Forms::Button());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->lblPnlOpciones = (gcnew System::Windows::Forms::Label());
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->pnlVistaPrincipal = (gcnew System::Windows::Forms::Panel());
			this->lblPnlVistaPrincipal = (gcnew System::Windows::Forms::Label());
			this->pnlVerPantallaPasajero = (gcnew System::Windows::Forms::Panel());
			this->pnlDecoration1 = (gcnew System::Windows::Forms::Panel());
			this->btnPnlPasajeroVer = (gcnew System::Windows::Forms::Button());
			this->lblTextPasajero = (gcnew System::Windows::Forms::Label());
			this->lblPasajero = (gcnew System::Windows::Forms::Label());
			this->pnlVerPantallaConductor = (gcnew System::Windows::Forms::Panel());
			this->pnlDecoration2 = (gcnew System::Windows::Forms::Panel());
			this->btnPnlConductorVer = (gcnew System::Windows::Forms::Button());
			this->lblTextConductor = (gcnew System::Windows::Forms::Label());
			this->lblConductor = (gcnew System::Windows::Forms::Label());
			this->pnlVerPantallaAdministrador = (gcnew System::Windows::Forms::Panel());
			this->pnlDecoration3 = (gcnew System::Windows::Forms::Panel());
			this->btnPnlAdministradorVer = (gcnew System::Windows::Forms::Button());
			this->lblTextAdministrador = (gcnew System::Windows::Forms::Label());
			this->lblAdministrador = (gcnew System::Windows::Forms::Label());
			this->pnlBackBar = (gcnew System::Windows::Forms::Panel());
			this->lblInfoBackBar = (gcnew System::Windows::Forms::Label());
			this->lblPnlBackBar = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblMarco2 = (gcnew System::Windows::Forms::Label());
			this->lblMarco1 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pnlTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->pnlOpciones->SuspendLayout();
			this->pnlVistaPrincipal->SuspendLayout();
			this->pnlVerPantallaPasajero->SuspendLayout();
			this->pnlVerPantallaConductor->SuspendLayout();
			this->pnlVerPantallaAdministrador->SuspendLayout();
			this->pnlBackBar->SuspendLayout();
			this->SuspendLayout();
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
			this->lblLYNX->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblLYNX->Location = System::Drawing::Point(91, 18);
			this->lblLYNX->Name = L"lblLYNX";
			this->lblLYNX->Size = System::Drawing::Size(84, 40);
			this->lblLYNX->TabIndex = 0;
			this->lblLYNX->Text = L"LYNX";
			// 
			// pnlOpciones
			// 
			this->pnlOpciones->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlOpciones->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->pnlOpciones->Controls->Add(this->btnAbrirAdmin);
			this->pnlOpciones->Controls->Add(this->btnAbrirConductor);
			this->pnlOpciones->Controls->Add(this->btnAbrirPasajero);
			this->pnlOpciones->Controls->Add(this->lblInfo);
			this->pnlOpciones->Controls->Add(this->lblPnlOpciones);
			this->pnlOpciones->Controls->Add(this->lblBienvenida);
			this->pnlOpciones->Location = System::Drawing::Point(25, 108);
			this->pnlOpciones->Name = L"pnlOpciones";
			this->pnlOpciones->Size = System::Drawing::Size(892, 356);
			this->pnlOpciones->TabIndex = 1;
			// 
			// btnAbrirAdmin
			// 
			this->btnAbrirAdmin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnAbrirAdmin->AutoSize = true;
			this->btnAbrirAdmin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->btnAbrirAdmin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAbrirAdmin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnAbrirAdmin->ForeColor = System::Drawing::Color::White;
			this->btnAbrirAdmin->Location = System::Drawing::Point(594, 264);
			this->btnAbrirAdmin->MaximumSize = System::Drawing::Size(295, 46);
			this->btnAbrirAdmin->Name = L"btnAbrirAdmin";
			this->btnAbrirAdmin->Size = System::Drawing::Size(264, 46);
			this->btnAbrirAdmin->TabIndex = 5;
			this->btnAbrirAdmin->Text = L"Abrir administrador";
			this->btnAbrirAdmin->UseVisualStyleBackColor = false;
			this->btnAbrirAdmin->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenAdminForm);
			// 
			// btnAbrirConductor
			// 
			this->btnAbrirConductor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnAbrirConductor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->btnAbrirConductor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAbrirConductor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnAbrirConductor->ForeColor = System::Drawing::Color::White;
			this->btnAbrirConductor->Location = System::Drawing::Point(313, 264);
			this->btnAbrirConductor->MaximumSize = System::Drawing::Size(275, 46);
			this->btnAbrirConductor->Name = L"btnAbrirConductor";
			this->btnAbrirConductor->Size = System::Drawing::Size(261, 46);
			this->btnAbrirConductor->TabIndex = 4;
			this->btnAbrirConductor->Text = L"Abrir conductor";
			this->btnAbrirConductor->UseVisualStyleBackColor = false;
			this->btnAbrirConductor->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenDriverForm);
			// 
			// btnAbrirPasajero
			// 
			this->btnAbrirPasajero->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnAbrirPasajero->AutoSize = true;
			this->btnAbrirPasajero->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->btnAbrirPasajero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAbrirPasajero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnAbrirPasajero->ForeColor = System::Drawing::Color::White;
			this->btnAbrirPasajero->Location = System::Drawing::Point(35, 264);
			this->btnAbrirPasajero->MaximumSize = System::Drawing::Size(272, 46);
			this->btnAbrirPasajero->Name = L"btnAbrirPasajero";
			this->btnAbrirPasajero->Size = System::Drawing::Size(261, 46);
			this->btnAbrirPasajero->TabIndex = 3;
			this->btnAbrirPasajero->Text = L"Abrir pasajero";
			this->btnAbrirPasajero->UseVisualStyleBackColor = false;
			this->btnAbrirPasajero->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenPassengerForm);
			// 
			// lblInfo
			// 
			this->lblInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)));
			this->lblInfo->Location = System::Drawing::Point(32, 190);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(826, 46);
			this->lblInfo->TabIndex = 2;
			this->lblInfo->Text = L"Agregar info";
			// 
			// lblPnlOpciones
			// 
			this->lblPnlOpciones->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblPnlOpciones->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 28, System::Drawing::FontStyle::Bold));
			this->lblPnlOpciones->ForeColor = System::Drawing::Color::White;
			this->lblPnlOpciones->Location = System::Drawing::Point(32, 84);
			this->lblPnlOpciones->Name = L"lblPnlOpciones";
			this->lblPnlOpciones->Size = System::Drawing::Size(826, 92);
			this->lblPnlOpciones->TabIndex = 1;
			this->lblPnlOpciones->Text = L"Inicio para abrir pasajero, conductor y administrador. ( Agregar texto )";
			// 
			// lblBienvenida
			// 
			this->lblBienvenida->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblBienvenida->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(56)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblBienvenida->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->lblBienvenida->Location = System::Drawing::Point(32, 28);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(826, 34);
			this->lblBienvenida->TabIndex = 0;
			this->lblBienvenida->Text = L"Bienvenido!";
			this->lblBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlVistaPrincipal
			// 
			this->pnlVistaPrincipal->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pnlVistaPrincipal->BackColor = System::Drawing::Color::White;
			this->pnlVistaPrincipal->Controls->Add(this->lblPnlVistaPrincipal);
			this->pnlVistaPrincipal->Location = System::Drawing::Point(959, 108);
			this->pnlVistaPrincipal->Name = L"pnlVistaPrincipal";
			this->pnlVistaPrincipal->Size = System::Drawing::Size(493, 356);
			this->pnlVistaPrincipal->TabIndex = 2;
			// 
			// lblPnlVistaPrincipal
			// 
			this->lblPnlVistaPrincipal->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblPnlVistaPrincipal->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblPnlVistaPrincipal->Location = System::Drawing::Point(28, 28);
			this->lblPnlVistaPrincipal->Name = L"lblPnlVistaPrincipal";
			this->lblPnlVistaPrincipal->Size = System::Drawing::Size(220, 34);
			this->lblPnlVistaPrincipal->TabIndex = 0;
			this->lblPnlVistaPrincipal->Text = L"Vista principal";
			// 
			// pnlVerPantallaPasajero
			// 
			this->pnlVerPantallaPasajero->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlVerPantallaPasajero->BackColor = System::Drawing::Color::White;
			this->pnlVerPantallaPasajero->Controls->Add(this->pnlDecoration1);
			this->pnlVerPantallaPasajero->Controls->Add(this->btnPnlPasajeroVer);
			this->pnlVerPantallaPasajero->Controls->Add(this->lblTextPasajero);
			this->pnlVerPantallaPasajero->Controls->Add(this->lblPasajero);
			this->pnlVerPantallaPasajero->Location = System::Drawing::Point(25, 480);
			this->pnlVerPantallaPasajero->MaximumSize = System::Drawing::Size(473, 500);
			this->pnlVerPantallaPasajero->MinimumSize = System::Drawing::Size(444, 217);
			this->pnlVerPantallaPasajero->Name = L"pnlVerPantallaPasajero";
			this->pnlVerPantallaPasajero->Size = System::Drawing::Size(444, 217);
			this->pnlVerPantallaPasajero->TabIndex = 3;
			// 
			// pnlDecoration1
			// 
			this->pnlDecoration1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlDecoration1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->pnlDecoration1->Location = System::Drawing::Point(24, 18);
			this->pnlDecoration1->Name = L"pnlDecoration1";
			this->pnlDecoration1->Size = System::Drawing::Size(391, 10);
			this->pnlDecoration1->TabIndex = 2;
			// 
			// btnPnlPasajeroVer
			// 
			this->btnPnlPasajeroVer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnPnlPasajeroVer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->btnPnlPasajeroVer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPnlPasajeroVer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnPnlPasajeroVer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnPnlPasajeroVer->Location = System::Drawing::Point(27, 152);
			this->btnPnlPasajeroVer->Name = L"btnPnlPasajeroVer";
			this->btnPnlPasajeroVer->Size = System::Drawing::Size(389, 44);
			this->btnPnlPasajeroVer->TabIndex = 3;
			this->btnPnlPasajeroVer->Text = L"Ver pantalla";
			this->btnPnlPasajeroVer->UseVisualStyleBackColor = false;
			this->btnPnlPasajeroVer->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenPassengerForm);
			// 
			// lblTextPasajero
			// 
			this->lblTextPasajero->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblTextPasajero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTextPasajero->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblTextPasajero->Location = System::Drawing::Point(25, 79);
			this->lblTextPasajero->Name = L"lblTextPasajero";
			this->lblTextPasajero->Size = System::Drawing::Size(391, 46);
			this->lblTextPasajero->TabIndex = 2;
			this->lblTextPasajero->Text = L"Solicitud de viajes, estado activo, historial y perfil visual del pasajero.";
			this->lblTextPasajero->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblPasajero
			// 
			this->lblPasajero->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblPasajero->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblPasajero->Location = System::Drawing::Point(24, 44);
			this->lblPasajero->Name = L"lblPasajero";
			this->lblPasajero->Size = System::Drawing::Size(391, 34);
			this->lblPasajero->TabIndex = 1;
			this->lblPasajero->Text = L"Pasajero";
			// 
			// pnlVerPantallaConductor
			// 
			this->pnlVerPantallaConductor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlVerPantallaConductor->BackColor = System::Drawing::Color::White;
			this->pnlVerPantallaConductor->Controls->Add(this->pnlDecoration2);
			this->pnlVerPantallaConductor->Controls->Add(this->btnPnlConductorVer);
			this->pnlVerPantallaConductor->Controls->Add(this->lblTextConductor);
			this->pnlVerPantallaConductor->Controls->Add(this->lblConductor);
			this->pnlVerPantallaConductor->Location = System::Drawing::Point(517, 480);
			this->pnlVerPantallaConductor->MaximumSize = System::Drawing::Size(470, 500);
			this->pnlVerPantallaConductor->Name = L"pnlVerPantallaConductor";
			this->pnlVerPantallaConductor->Size = System::Drawing::Size(444, 217);
			this->pnlVerPantallaConductor->TabIndex = 4;
			// 
			// pnlDecoration2
			// 
			this->pnlDecoration2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlDecoration2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->pnlDecoration2->Location = System::Drawing::Point(24, 18);
			this->pnlDecoration2->Name = L"pnlDecoration2";
			this->pnlDecoration2->Size = System::Drawing::Size(398, 10);
			this->pnlDecoration2->TabIndex = 1;
			// 
			// btnPnlConductorVer
			// 
			this->btnPnlConductorVer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnPnlConductorVer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->btnPnlConductorVer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPnlConductorVer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnPnlConductorVer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnPnlConductorVer->Location = System::Drawing::Point(24, 152);
			this->btnPnlConductorVer->Name = L"btnPnlConductorVer";
			this->btnPnlConductorVer->Size = System::Drawing::Size(398, 44);
			this->btnPnlConductorVer->TabIndex = 3;
			this->btnPnlConductorVer->Text = L"Ver pantalla";
			this->btnPnlConductorVer->UseVisualStyleBackColor = false;
			this->btnPnlConductorVer->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenDriverForm);
			// 
			// lblTextConductor
			// 
			this->lblTextConductor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblTextConductor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTextConductor->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblTextConductor->Location = System::Drawing::Point(24, 79);
			this->lblTextConductor->Name = L"lblTextConductor";
			this->lblTextConductor->Size = System::Drawing::Size(391, 45);
			this->lblTextConductor->TabIndex = 2;
			this->lblTextConductor->Text = L"Centro visual del conductor con estado, solicitudes, vehiculo e historial.";
			this->lblTextConductor->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblConductor
			// 
			this->lblConductor->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblConductor->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblConductor->Location = System::Drawing::Point(24, 44);
			this->lblConductor->Name = L"lblConductor";
			this->lblConductor->Size = System::Drawing::Size(391, 34);
			this->lblConductor->TabIndex = 1;
			this->lblConductor->Text = L"Conductor";
			// 
			// pnlVerPantallaAdministrador
			// 
			this->pnlVerPantallaAdministrador->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlVerPantallaAdministrador->BackColor = System::Drawing::Color::White;
			this->pnlVerPantallaAdministrador->Controls->Add(this->pnlDecoration3);
			this->pnlVerPantallaAdministrador->Controls->Add(this->btnPnlAdministradorVer);
			this->pnlVerPantallaAdministrador->Controls->Add(this->lblTextAdministrador);
			this->pnlVerPantallaAdministrador->Controls->Add(this->lblAdministrador);
			this->pnlVerPantallaAdministrador->Location = System::Drawing::Point(1008, 480);
			this->pnlVerPantallaAdministrador->Name = L"pnlVerPantallaAdministrador";
			this->pnlVerPantallaAdministrador->Size = System::Drawing::Size(444, 217);
			this->pnlVerPantallaAdministrador->TabIndex = 5;
			// 
			// pnlDecoration3
			// 
			this->pnlDecoration3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlDecoration3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->pnlDecoration3->Location = System::Drawing::Point(24, 18);
			this->pnlDecoration3->Name = L"pnlDecoration3";
			this->pnlDecoration3->Size = System::Drawing::Size(400, 10);
			this->pnlDecoration3->TabIndex = 2;
			// 
			// btnPnlAdministradorVer
			// 
			this->btnPnlAdministradorVer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnPnlAdministradorVer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->btnPnlAdministradorVer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPnlAdministradorVer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnPnlAdministradorVer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnPnlAdministradorVer->Location = System::Drawing::Point(24, 152);
			this->btnPnlAdministradorVer->Name = L"btnPnlAdministradorVer";
			this->btnPnlAdministradorVer->Size = System::Drawing::Size(400, 44);
			this->btnPnlAdministradorVer->TabIndex = 3;
			this->btnPnlAdministradorVer->Text = L"Ver pantalla";
			this->btnPnlAdministradorVer->UseVisualStyleBackColor = false;
			this->btnPnlAdministradorVer->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenAdminForm);
			// 
			// lblTextAdministrador
			// 
			this->lblTextAdministrador->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblTextAdministrador->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTextAdministrador->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)),
				static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblTextAdministrador->Location = System::Drawing::Point(24, 78);
			this->lblTextAdministrador->Name = L"lblTextAdministrador";
			this->lblTextAdministrador->Size = System::Drawing::Size(391, 46);
			this->lblTextAdministrador->TabIndex = 2;
			this->lblTextAdministrador->Text = L"Vista administrativa con metricas, usuarios, viajes y acciones de control.";
			this->lblTextAdministrador->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblAdministrador
			// 
			this->lblAdministrador->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblAdministrador->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblAdministrador->Location = System::Drawing::Point(24, 44);
			this->lblAdministrador->Name = L"lblAdministrador";
			this->lblAdministrador->Size = System::Drawing::Size(391, 34);
			this->lblAdministrador->TabIndex = 1;
			this->lblAdministrador->Text = L"Administrador";
			// 
			// pnlBackBar
			// 
			this->pnlBackBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlBackBar->BackColor = System::Drawing::Color::White;
			this->pnlBackBar->Controls->Add(this->lblInfoBackBar);
			this->pnlBackBar->Controls->Add(this->lblPnlBackBar);
			this->pnlBackBar->Location = System::Drawing::Point(25, 714);
			this->pnlBackBar->Name = L"pnlBackBar";
			this->pnlBackBar->Size = System::Drawing::Size(1427, 169);
			this->pnlBackBar->TabIndex = 6;
			// 
			// lblInfoBackBar
			// 
			this->lblInfoBackBar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblInfoBackBar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblInfoBackBar->Location = System::Drawing::Point(24, 66);
			this->lblInfoBackBar->Name = L"lblInfoBackBar";
			this->lblInfoBackBar->Size = System::Drawing::Size(1040, 40);
			this->lblInfoBackBar->TabIndex = 1;
			this->lblInfoBackBar->Text = L"Agregar texto";
			// 
			// lblPnlBackBar
			// 
			this->lblPnlBackBar->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->lblPnlBackBar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblPnlBackBar->Location = System::Drawing::Point(24, 24);
			this->lblPnlBackBar->Name = L"lblPnlBackBar";
			this->lblPnlBackBar->Size = System::Drawing::Size(310, 32);
			this->lblPnlBackBar->TabIndex = 0;
			this->lblPnlBackBar->Text = L"TEXTO";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainMenuForm::timer1_Tick);
			// 
			// lblMarco2
			// 
			this->lblMarco2->BackColor = System::Drawing::Color::Red;
			this->lblMarco2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->lblMarco2->Location = System::Drawing::Point(1452, 74);
			this->lblMarco2->Name = L"lblMarco2";
			this->lblMarco2->Size = System::Drawing::Size(28, 850);
			this->lblMarco2->TabIndex = 6;
			this->lblMarco2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblMarco2->Visible = false;
			// 
			// lblMarco1
			// 
			this->lblMarco1->BackColor = System::Drawing::Color::Red;
			this->lblMarco1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->lblMarco1->Location = System::Drawing::Point(-3, 74);
			this->lblMarco1->Name = L"lblMarco1";
			this->lblMarco1->Size = System::Drawing::Size(28, 850);
			this->lblMarco1->TabIndex = 7;
			this->lblMarco1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblMarco1->Visible = false;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Red;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->label1->Location = System::Drawing::Point(25, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1443, 34);
			this->label1->TabIndex = 8;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Red;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->label2->Location = System::Drawing::Point(19, 443);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(1443, 34);
			this->label2->TabIndex = 9;
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Red;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->label3->Location = System::Drawing::Point(25, 679);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(1443, 34);
			this->label3->TabIndex = 10;
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Red;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->label4->Location = System::Drawing::Point(19, 886);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(1443, 34);
			this->label4->TabIndex = 11;
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Visible = false;
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(223)));
			this->ClientSize = System::Drawing::Size(1480, 920);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblMarco1);
			this->Controls->Add(this->lblMarco2);
			this->Controls->Add(this->pnlBackBar);
			this->Controls->Add(this->pnlVerPantallaAdministrador);
			this->Controls->Add(this->pnlVerPantallaConductor);
			this->Controls->Add(this->pnlVerPantallaPasajero);
			this->Controls->Add(this->pnlVistaPrincipal);
			this->Controls->Add(this->pnlOpciones);
			this->Controls->Add(this->pnlTopBar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimumSize = System::Drawing::Size(1280, 820);
			this->Name = L"MainMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LYNX | Inicio";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainMenuForm::MainMenuForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainMenuForm::MainMenuForm_KeyDown);
			this->pnlTopBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
			this->pnlOpciones->ResumeLayout(false);
			this->pnlOpciones->PerformLayout();
			this->pnlVistaPrincipal->ResumeLayout(false);
			this->pnlVerPantallaPasajero->ResumeLayout(false);
			this->pnlVerPantallaConductor->ResumeLayout(false);
			this->pnlVerPantallaAdministrador->ResumeLayout(false);
			this->pnlBackBar->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		// LOGICA
		#pragma endregion
		private:

		//
		// Load Form
		// 
			System::Void MainMenuForm_Load(System::Object^ sender, System::EventArgs^ e) {

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
		// Botones functions
		// 
			// btnAbrirPasajeroClick
			System::Void OpenPassengerForm(System::Object^ sender, System::EventArgs^ e)
			{
				if (formlg == nullptr || formlg->IsDisposed) {
					delete formlg;
					formlg = gcnew LoginPassengerForm();
				}
				FormsStatus::SaveWindow(this);
				FormsStatus::ApplyWindow(formlg);
				formlg->Show();
				formlg->BringToFront();
				this->Hide(); // ocultar MainMenu

				
			}

			// btnAbrirConductorClick
			System::Void OpenDriverForm(System::Object^ sender, System::EventArgs^ e)
			{
				DriverMenuForm^ form = gcnew DriverMenuForm();
				FormsStatus::SaveWindow(this);
				FormsStatus::ApplyWindow(form);
				form->Show();
				form->BringToFront();
				this->Hide(); // ocultar MainMenu
			}

			// btnAbrirAdministradorClick
			System::Void OpenAdminForm(System::Object^ sender, System::EventArgs^ e)
			{
				AdminMenuForm^ form = gcnew AdminMenuForm();
				FormsStatus::SaveWindow(this);
				FormsStatus::ApplyWindow(form);
				form->Show();
				form->BringToFront();
				this->Hide(); // ocultar MainMenu
			}

		//
		// Timer functions
		// 
			System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

			
				if (formlg->switchToRegister) {
					formlg->switchToRegister = false;
					if (formrg == nullptr || formrg->IsDisposed) {
						formrg = gcnew RegisterPassengerForm();
					}
					FormsStatus::ApplyWindow(formrg);
					formrg->Show();
				}

				if (formrg->switchToLogin) {
					formrg->switchToLogin = false;
					if (formlg == nullptr || formlg->IsDisposed) {
						formlg = gcnew LoginPassengerForm();
					}
					FormsStatus::ApplyWindow(formlg);
					formlg->Show();
				}
				if (formlg->passengerScreen || formrg->passengerScreen) {
					if (formpm == nullptr || formpm->IsDisposed) {
						delete formpm;
						formpm = gcnew PassengerMenuForm();
					}
					FormsStatus::ApplyWindow(formpm);
					formpm->name = formlg->names;
					formpm->dni = formlg->dnis;
					formpm->password = formlg->passwords;
					formpm->Show();
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
						InitButtonsStyle();
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
					InitButtonsStyle();
					this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
				}
			}

			System::Void MainMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
				System::Windows::Forms::Application::Exit();
			}
		

			System::Void pictureBoxIcon_Click(System::Object^ sender, System::EventArgs^ e) {
				this->Show();
				this->BringToFront();
			}


			System::Void InitButtonsStyle()
			{
				// BTN PASAJERO
				btnAbrirPasajero->Size = System::Drawing::Size(261, 46);
				btnAbrirPasajero->Location = System::Drawing::Point(35, 264);
				btnAbrirPasajero->BackColor = System::Drawing::Color::FromArgb(33, 181, 109);
				btnAbrirPasajero->ForeColor = System::Drawing::Color::White;
				btnAbrirPasajero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				btnAbrirPasajero->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold);
				btnAbrirPasajero->Text = L"Abrir pasajero";
				btnAbrirPasajero->Visible = true;
				btnAbrirPasajero->Enabled = true;

				// BTN CONDUCTOR
				btnAbrirConductor->Size = System::Drawing::Size(261, 46);
				btnAbrirConductor->Location = System::Drawing::Point(313, 264);
				btnAbrirConductor->BackColor = System::Drawing::Color::FromArgb(39, 50, 120);
				btnAbrirConductor->ForeColor = System::Drawing::Color::White;
				btnAbrirConductor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				btnAbrirConductor->Font = gcnew System::Drawing::Font( L"Segoe UI", 10, System::Drawing::FontStyle::Bold);
				btnAbrirConductor->Text = L"Abrir conductor";
				btnAbrirConductor->Visible = true;
				btnAbrirConductor->Enabled = true;

				// BTN ADMIN
				btnAbrirAdmin->Size = System::Drawing::Size(264, 46);
				btnAbrirAdmin->Location = System::Drawing::Point(594, 264);
				btnAbrirAdmin->BackColor = System::Drawing::Color::FromArgb(57, 107, 239);
				btnAbrirAdmin->ForeColor = System::Drawing::Color::White;
				btnAbrirAdmin->FlatStyle =System::Windows::Forms::FlatStyle::Flat;
				btnAbrirAdmin->Font = gcnew System::Drawing::Font(L"Segoe UI", 10,System::Drawing::FontStyle::Bold);
				btnAbrirAdmin->Text = L"Abrir administrador";
				btnAbrirAdmin->Visible = true;
				btnAbrirAdmin->Enabled = true;
			}
};

}
