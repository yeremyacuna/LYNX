#pragma once
#include <windows.h>
#include "../library/FormsStatus.h"	
#include "../AuthManager.h"
#include "../TripManager.h"
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal_cppstd.h>

namespace LYNX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class VehicleRegisterForm : public System::Windows::Forms::Form
	{
	public:
		VehicleRegisterForm(void)
		{

			InitializeComponent();
			ConfigureForm();
		}

		VehicleRegisterForm(AuthManager* auth, TripManager* trips)
		{
			this->authManager = auth;
			this->tripManager = trips;
			
			InitializeComponent();
			ConfigureForm();
		}

	protected:
		~VehicleRegisterForm()
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
	private: System::Windows::Forms::Label^ lblVehicle;
	private: System::Windows::Forms::Label^ lblDataPlate;
	private: System::Windows::Forms::Label^ lblDataBrand;
	private: System::Windows::Forms::Label^ lblDataModel;
	private: System::Windows::Forms::Label^ lblDataColour;
	private: System::Windows::Forms::Label^ lblDataYear;
	private: System::Windows::Forms::TextBox^ tbBrand;
	private: System::Windows::Forms::TextBox^ tbPlate;
	private: System::Windows::Forms::TextBox^ tbModel;
	private: System::Windows::Forms::TextBox^ tbColour;
	private: System::Windows::Forms::TextBox^ tbYear;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Label^ lblFrame2;
	private: System::Windows::Forms::Label^ lblFrame1;
	private: System::Windows::Forms::Label^ lblFrame4;
	private: System::Windows::Forms::Label^ lblFrame3;
	private: System::Windows::Forms::Panel^ pnlTopBar;

	private: System::Windows::Forms::Label^ lblLYNX;
	private: System::Windows::Forms::PictureBox^ pictureBoxIcon;
	private: System::ComponentModel::Container^ components;
		   
		   // WINDOWS INITIALIZE
	private:
		#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblVehicle = (gcnew System::Windows::Forms::Label());
			this->lblDataPlate = (gcnew System::Windows::Forms::Label());
			this->lblDataBrand = (gcnew System::Windows::Forms::Label());
			this->lblDataModel = (gcnew System::Windows::Forms::Label());
			this->lblDataColour = (gcnew System::Windows::Forms::Label());
			this->lblDataYear = (gcnew System::Windows::Forms::Label());
			this->tbBrand = (gcnew System::Windows::Forms::TextBox());
			this->tbPlate = (gcnew System::Windows::Forms::TextBox());
			this->tbModel = (gcnew System::Windows::Forms::TextBox());
			this->tbColour = (gcnew System::Windows::Forms::TextBox());
			this->tbYear = (gcnew System::Windows::Forms::TextBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->lblFrame2 = (gcnew System::Windows::Forms::Label());
			this->lblFrame1 = (gcnew System::Windows::Forms::Label());
			this->lblFrame4 = (gcnew System::Windows::Forms::Label());
			this->lblFrame3 = (gcnew System::Windows::Forms::Label());
			this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
			this->lblLYNX = (gcnew System::Windows::Forms::Label());
			this->pnlTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->SuspendLayout();
			// 
			// lblVehicle
			// 
			this->lblVehicle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblVehicle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 28, System::Drawing::FontStyle::Bold));
			this->lblVehicle->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblVehicle->Location = System::Drawing::Point(524, 320);
			this->lblVehicle->Name = L"lblVehicle";
			this->lblVehicle->Size = System::Drawing::Size(429, 46);
			this->lblVehicle->TabIndex = 0;
			this->lblVehicle->Text = L"Vehiculo";
			this->lblVehicle->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lblDataPlate
			// 
			this->lblDataPlate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDataPlate->AutoSize = true;
			this->lblDataPlate->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDataPlate->ForeColor = System::Drawing::SystemColors::Control;
			this->lblDataPlate->Location = System::Drawing::Point(521, 373);
			this->lblDataPlate->Name = L"lblDataPlate";
			this->lblDataPlate->Size = System::Drawing::Size(42, 17);
			this->lblDataPlate->TabIndex = 1;
			this->lblDataPlate->Text = L"Placa";
			// 
			// lblDataBrand
			// 
			this->lblDataBrand->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDataBrand->AutoSize = true;
			this->lblDataBrand->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDataBrand->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblDataBrand->Location = System::Drawing::Point(521, 426);
			this->lblDataBrand->Name = L"lblDataBrand";
			this->lblDataBrand->Size = System::Drawing::Size(46, 17);
			this->lblDataBrand->TabIndex = 2;
			this->lblDataBrand->Text = L"Marca";
			// 
			// lblDataModel
			// 
			this->lblDataModel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDataModel->AutoSize = true;
			this->lblDataModel->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDataModel->ForeColor = System::Drawing::SystemColors::Control;
			this->lblDataModel->Location = System::Drawing::Point(521, 479);
			this->lblDataModel->Name = L"lblDataModel";
			this->lblDataModel->Size = System::Drawing::Size(55, 17);
			this->lblDataModel->TabIndex = 3;
			this->lblDataModel->Text = L"Modelo";
			// 
			// lblDataColour
			// 
			this->lblDataColour->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDataColour->AutoSize = true;
			this->lblDataColour->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDataColour->ForeColor = System::Drawing::SystemColors::Control;
			this->lblDataColour->Location = System::Drawing::Point(521, 533);
			this->lblDataColour->Name = L"lblDataColour";
			this->lblDataColour->Size = System::Drawing::Size(43, 17);
			this->lblDataColour->TabIndex = 4;
			this->lblDataColour->Text = L"Color";
			// 
			// lblDataYear
			// 
			this->lblDataYear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblDataYear->AutoSize = true;
			this->lblDataYear->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDataYear->ForeColor = System::Drawing::SystemColors::Control;
			this->lblDataYear->Location = System::Drawing::Point(521, 585);
			this->lblDataYear->Name = L"lblDataYear";
			this->lblDataYear->Size = System::Drawing::Size(37, 17);
			this->lblDataYear->TabIndex = 5;
			this->lblDataYear->Text = L"Anio";
			// 
			// tbBrand
			// 
			this->tbBrand->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbBrand->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbBrand->Location = System::Drawing::Point(524, 446);
			this->tbBrand->Name = L"tbBrand";
			this->tbBrand->Size = System::Drawing::Size(429, 27);
			this->tbBrand->TabIndex = 7;
			// 
			// tbPlate
			// 
			this->tbPlate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbPlate->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbPlate->Location = System::Drawing::Point(524, 393);
			this->tbPlate->Name = L"tbPlate";
			this->tbPlate->Size = System::Drawing::Size(429, 27);
			this->tbPlate->TabIndex = 6;
			// 
			// tbModel
			// 
			this->tbModel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbModel->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbModel->Location = System::Drawing::Point(524, 499);
			this->tbModel->Name = L"tbModel";
			this->tbModel->Size = System::Drawing::Size(429, 27);
			this->tbModel->TabIndex = 8;
			// 
			// tbColour
			// 
			this->tbColour->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbColour->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbColour->Location = System::Drawing::Point(524, 553);
			this->tbColour->Name = L"tbColour";
			this->tbColour->Size = System::Drawing::Size(429, 27);
			this->tbColour->TabIndex = 9;
			// 
			// tbYear
			// 
			this->tbYear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbYear->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbYear->Location = System::Drawing::Point(524, 605);
			this->tbYear->Name = L"tbYear";
			this->tbYear->Size = System::Drawing::Size(429, 27);
			this->tbYear->TabIndex = 10;
			// 
			// btnRegister
			// 
			this->btnRegister->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRegister->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->btnRegister->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->btnRegister->Location = System::Drawing::Point(624, 643);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(230, 44);
			this->btnRegister->TabIndex = 11;
			this->btnRegister->Text = L"Crear Cuenta";
			this->btnRegister->UseVisualStyleBackColor = false;
			this->btnRegister->Click += gcnew System::EventHandler(this, &VehicleRegisterForm::btnRegister_Click);
			// 
			// lblFrame2
			// 
			this->lblFrame2->BackColor = System::Drawing::Color::Red;
			this->lblFrame2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblFrame2->Location = System::Drawing::Point(1, 79);
			this->lblFrame2->Name = L"lblFrame2";
			this->lblFrame2->Size = System::Drawing::Size(458, 850);
			this->lblFrame2->TabIndex = 13;
			this->lblFrame2->Visible = false;
			// 
			// lblFrame1
			// 
			this->lblFrame1->BackColor = System::Drawing::Color::Red;
			this->lblFrame1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblFrame1->Location = System::Drawing::Point(1022, 79);
			this->lblFrame1->Name = L"lblFrame1";
			this->lblFrame1->Size = System::Drawing::Size(458, 850);
			this->lblFrame1->TabIndex = 14;
			this->lblFrame1->Visible = false;
			// 
			// lblFrame4
			// 
			this->lblFrame4->BackColor = System::Drawing::Color::Red;
			this->lblFrame4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblFrame4->Location = System::Drawing::Point(450, 79);
			this->lblFrame4->Name = L"lblFrame4";
			this->lblFrame4->Size = System::Drawing::Size(595, 213);
			this->lblFrame4->TabIndex = 15;
			this->lblFrame4->Visible = false;
			// 
			// lblFrame3
			// 
			this->lblFrame3->BackColor = System::Drawing::Color::Red;
			this->lblFrame3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblFrame3->Location = System::Drawing::Point(450, 707);
			this->lblFrame3->Name = L"lblFrame3";
			this->lblFrame3->Size = System::Drawing::Size(595, 213);
			this->lblFrame3->TabIndex = 16;
			this->lblFrame3->Visible = false;
			// 
			// pnlTopBar
			// 
			this->pnlTopBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlTopBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->pnlTopBar->Controls->Add(this->pictureBoxIcon);
			this->pnlTopBar->Location = System::Drawing::Point(0, 0);
			this->pnlTopBar->Name = L"pnlTopBar";
			this->pnlTopBar->Size = System::Drawing::Size(1480, 78);
			this->pnlTopBar->TabIndex = 19;
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
			this->pictureBoxIcon->TabIndex = 4;
			this->pictureBoxIcon->TabStop = false;
			this->pictureBoxIcon->Click += gcnew System::EventHandler(this, &VehicleRegisterForm::pictureBoxIcon_Click);
			// 
			// lblLYNX
			// 
			this->lblLYNX->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->lblLYNX->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 22, System::Drawing::FontStyle::Bold));
			this->lblLYNX->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblLYNX->Location = System::Drawing::Point(91, 18);
			this->lblLYNX->Name = L"lblLYNX";
			this->lblLYNX->Size = System::Drawing::Size(84, 40);
			this->lblLYNX->TabIndex = 17;
			this->lblLYNX->Text = L"LYNX";
			// 
			// VehicleRegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->ClientSize = System::Drawing::Size(1480, 920);
			this->Controls->Add(this->lblLYNX);
			this->Controls->Add(this->pnlTopBar);
			this->Controls->Add(this->lblFrame3);
			this->Controls->Add(this->lblFrame4);
			this->Controls->Add(this->lblFrame1);
			this->Controls->Add(this->lblFrame2);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->tbYear);
			this->Controls->Add(this->tbColour);
			this->Controls->Add(this->tbModel);
			this->Controls->Add(this->tbPlate);
			this->Controls->Add(this->tbBrand);
			this->Controls->Add(this->lblDataYear);
			this->Controls->Add(this->lblDataColour);
			this->Controls->Add(this->lblDataModel);
			this->Controls->Add(this->lblDataBrand);
			this->Controls->Add(this->lblDataPlate);
			this->Controls->Add(this->lblVehicle);
			this->Name = L"VehicleRegisterForm";
			this->Text = L"LYNX | Registrar Vehiculo";
			this->Load += gcnew System::EventHandler(this, &VehicleRegisterForm::VehicleRegisterForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &VehicleRegisterForm::VehicleRegisterForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &VehicleRegisterForm::VehicleRegisterForm_Resize);
			this->pnlTopBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		// LOGICA y PUBLIC
		#pragma endregion
		public:
			//Variables para ir al Login o al Register
			bool switchToLogin = false;
			bool switchToRegister = false;

			//Campos del Register
			String^ name;
			String^ pass;
			String^ dni;

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
			System::Void VehicleRegisterForm_Load(System::Object^ sender, System::EventArgs^ e) {

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

		// funcion que verifica si un string es un numero (true: no es un numero / false: es un numero) (ejm: "5234" = true / "a321s" = false)
		   bool isNaNString(const std::string& str) {
			   std::istringstream iss(str);
			   double num;
			   // Check if a double can be read AND if it consumes the entire string
			   return !(iss >> num && iss.eof());
		   }

		 //
		 // Click functions
		 //
		   System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
			   // Guardar los txt box como Strings^
			   String^ plateText = this->tbPlate->Text->Trim();
			   String^ brandText = this->tbBrand->Text->Trim();
			   String^ modelText = this->tbModel->Text;
			   String^ colourText = this->tbColour->Text;
			   String^ yearText = this->tbYear->Text;
			   // ===============================================================================================
			   // ===============================================================================================
			   // ===============================================================================================
			   // ===============================================================================================
			   Vehicle vehicle;

			   // Verificar que los espacios no esten vacios
			   if (plateText->Length == 0 || brandText->Length == 0 || modelText->Length == 0 || colourText->Length == 0 || yearText->Length == 0) {
				   MessageBox::Show("Por favor llene todos los campos", "Registro", MessageBoxButtons::OK);
				   return;
			   }

			   //Verificar si se pudo o no acceder al gestionador de archivos
			   if (authManager == nullptr) {
				   MessageBox::Show("No se pudo acceder al gestor de usuarios", "Registro", MessageBoxButtons::OK);
				   return;
			   }

			   if (isNaNString(msclr::interop::marshal_as<std::string>(yearText))) {
				   MessageBox::Show("Anio invalido. Debe ser un numero entero", "Registro", MessageBoxButtons::OK);
				   return;
			   }

			   // Converitr con marshal as al tipo de dato que quiero segun un String^
			   std::string plate = msclr::interop::marshal_as<std::string>(plateText);
			   std::string brand = msclr::interop::marshal_as<std::string>(brandText);
			   std::string model = msclr::interop::marshal_as<std::string>(modelText);
			   std::string colour = msclr::interop::marshal_as<std::string>(colourText);
			   int year = std::stoi(msclr::interop::marshal_as<std::string>(yearText));

			 

				//Vaciar los campos
				this->tbBrand->Text = "";
				this->tbYear->Text = "";
				this->tbModel->Text = "";
				this->tbPlate->Text = "";
				this->tbColour->Text = "";
		

				// Hacer validacion del anio si es un numero o es mayor al 2000 o menor al actual ( 2026 )
				if (year<2000 || year >2026) {
					MessageBox::Show("Anio invalido. El anio del vehiculo debe ser despues del 2000 y antes del anio actual", "Registro", MessageBoxButtons::OK);
					return;
				}

		//guarda los valores en el objeto vehiculo
		vehicle.setPlate(plate);
		vehicle.setBrand(brand);
		vehicle.setModel(model);
		vehicle.setColor(colour);
		vehicle.setYear(year);

		//obtiene los campos del register para guardarlos
		String^ n = name;
		String^ d = dni;
		String^ p = pass;


			   // Validar si el DNI ya se encuentra registrado con dni nombre y contraseña pass en la funcion de authmanager
			   if (!authManager->registerDriver(msclr::interop::marshal_as<std::string>(n), msclr::interop::marshal_as<std::string>(d), msclr::interop::marshal_as<std::string>(p), vehicle)) {
				   MessageBox::Show("El DNI ya esta registrado.", "Registro", MessageBoxButtons::OK);
				   FormsStatus::SaveWindow(this);
				   //this->Close();
				   this->Hide();
				   switchToRegister = true;
				   return;
			   }

			   // Validar si la cuenta fue creada correctamente y se guardo todo correctamente o no , con save a password binary q devuelve true or false de guardar binario d fmanager
			   if (!authManager->savePasswordsBinary()) {
				   MessageBox::Show("La cuenta fue creada, pero no se pudo actualizar passwords.bin.", "Registro", MessageBoxButtons::OK);
			   }
			   else {
				   MessageBox::Show("Cuenta creada correctamente.", "Registro", MessageBoxButtons::OK);
			   }

			   FormsStatus::SaveWindow(this);
			   //this->Close();
			   this->Hide();
			   switchToLogin = true;
		   }

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

		   System::Void VehicleRegisterForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
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
		   System::Void VehicleRegisterForm_Resize(System::Object^ sender, System::EventArgs^ e) {
			   // DESACTIVAR CLOSE BUTTON
			   HWND hWnd = static_cast<HWND>(this->Handle.ToPointer());
			   HMENU hMenu = ::GetSystemMenu(hWnd, FALSE);
			   ::EnableMenuItem(hMenu, SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
			   ::DrawMenuBar(hWnd);
		   }
			
};
}
