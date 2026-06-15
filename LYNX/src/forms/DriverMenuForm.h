#pragma once
#include <windows.h>
#include "../library/FormsStatus.h"
#include "../AuthManager.h"
#include "../TripManager.h"
#include <msclr/marshal_cppstd.h>

class AuthManager;
class TripManager;

namespace LYNX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DriverMenuForm : public System::Windows::Forms::Form
	{
	public:
		DriverMenuForm(void)
		{
			InitializeComponent();
			ConfigureForm();

			
		}

		DriverMenuForm(AuthManager* auth, TripManager* trips, String^ driverDni, FileManager* file)
		{
			this->authManager = auth;
			this->tripManager = trips;
			this->fileManager = file;
			this->loggedDriverDni = driverDni;

			
			InitializeComponent();
			ConfigureForm();
		}

	protected:
		~DriverMenuForm()
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
		FileManager* fileManager = nullptr;

		String^ loggedDriverDni = "";

		

		// COMPONENTES
	private: System::Windows::Forms::Panel^ topPanel;
	private: System::Windows::Forms::Label^ topTitle;
	private: System::Windows::Forms::Label^ topText;
	private: System::Windows::Forms::Label^ onlineChip;
	private: System::Windows::Forms::Button^ statusButton;
	private: System::Windows::Forms::Button^ earningsButton;
	private: System::Windows::Forms::Panel^ profilePanel;
	private: System::Windows::Forms::Label^ profileTitle;
	private: System::Windows::Forms::Label^ profileName;
	private: System::Windows::Forms::Label^ profileInfo;
	private: System::Windows::Forms::Panel^ metric1;
	private: System::Windows::Forms::Label^ metric1Value;
	private: System::Windows::Forms::Label^ metric1Text;
	private: System::Windows::Forms::Panel^ metric2;
	private: System::Windows::Forms::Label^ metric2Value;
	private: System::Windows::Forms::Label^ metric2Text;
	private: System::Windows::Forms::Panel^ lastTripPanel;
	private: System::Windows::Forms::Panel^ lastTripDot;
	private: System::Windows::Forms::Label^ lastTripTitle;
	private: System::Windows::Forms::Label^ lastTripText;
	private: System::Windows::Forms::Panel^ queuePanel;
	private: System::Windows::Forms::Label^ queueTitle;
	private: System::Windows::Forms::Panel^ queueItem1;
	private: System::Windows::Forms::Panel^ q1Dot;
	private: System::Windows::Forms::Label^ q1Title;
	private: System::Windows::Forms::Label^ q1Text;
	private: System::Windows::Forms::Panel^ queueItem2;
	private: System::Windows::Forms::Panel^ q2Dot;
	private: System::Windows::Forms::Label^ q2Title;
	private: System::Windows::Forms::Label^ q2Text;
	private: System::Windows::Forms::Panel^ queueItem3;
	private: System::Windows::Forms::Panel^ q3Dot;
	private: System::Windows::Forms::Label^ q3Title;
	private: System::Windows::Forms::Label^ q3Text;
	private: System::Windows::Forms::Button^ acceptButton;
	private: System::Windows::Forms::Button^ finishButton;
	private: System::Windows::Forms::Panel^ vehiclePanel;
	private: System::Windows::Forms::Label^ vehicleTitle;
	private: System::Windows::Forms::Label^ vehicleName;
	private: System::Windows::Forms::Label^ vehicleText;
	private: System::Windows::Forms::Panel^ maintenancePanel;
	private: System::Windows::Forms::Label^ maintenanceTitle;
	private: System::Windows::Forms::Label^ maintenanceText;
	private: System::Windows::Forms::Button^ updateVehicleButton;
	private: System::Windows::Forms::Panel^ manualPanel;
	private: System::Windows::Forms::Label^ manualTitle;
	private: System::Windows::Forms::Label^ manualStartLabel;
	private: System::Windows::Forms::TextBox^ manualStartBox;
	private: System::Windows::Forms::Label^ manualEndLabel;
	private: System::Windows::Forms::TextBox^ manualEndBox;
	private: System::Windows::Forms::Label^ manualTypeLabel;
	private: System::Windows::Forms::ComboBox^ manualTypeCombo;
	private: System::Windows::Forms::Label^ manualKmLabel;
	private: System::Windows::Forms::TextBox^ manualKmBox;
	private: System::Windows::Forms::Button^ registerButton;
	private: System::Windows::Forms::Panel^ historyPanel;
	private: System::Windows::Forms::Label^ historyTitle;
	private: System::Windows::Forms::ListView^ historyListView;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblMarco1;
	private: System::Windows::Forms::Label^ lblMarco2;
	private: System::Windows::Forms::PictureBox^ pictureBoxIcon;
	private: System::Windows::Forms::Label^ lblLYNX;
	private: System::Windows::Forms::Panel^ pnlTopBar;
	private:  System::ComponentModel::Container^ components;

		// WINDOWS INITIALIZE
	private:
	#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->earningsButton = (gcnew System::Windows::Forms::Button());
			this->statusButton = (gcnew System::Windows::Forms::Button());
			this->onlineChip = (gcnew System::Windows::Forms::Label());
			this->topText = (gcnew System::Windows::Forms::Label());
			this->topTitle = (gcnew System::Windows::Forms::Label());
			this->profilePanel = (gcnew System::Windows::Forms::Panel());
			this->lastTripPanel = (gcnew System::Windows::Forms::Panel());
			this->lastTripText = (gcnew System::Windows::Forms::Label());
			this->lastTripTitle = (gcnew System::Windows::Forms::Label());
			this->lastTripDot = (gcnew System::Windows::Forms::Panel());
			this->metric2 = (gcnew System::Windows::Forms::Panel());
			this->metric2Text = (gcnew System::Windows::Forms::Label());
			this->metric2Value = (gcnew System::Windows::Forms::Label());
			this->metric1 = (gcnew System::Windows::Forms::Panel());
			this->metric1Text = (gcnew System::Windows::Forms::Label());
			this->metric1Value = (gcnew System::Windows::Forms::Label());
			this->profileInfo = (gcnew System::Windows::Forms::Label());
			this->profileName = (gcnew System::Windows::Forms::Label());
			this->profileTitle = (gcnew System::Windows::Forms::Label());
			this->queuePanel = (gcnew System::Windows::Forms::Panel());
			this->finishButton = (gcnew System::Windows::Forms::Button());
			this->acceptButton = (gcnew System::Windows::Forms::Button());
			this->queueItem3 = (gcnew System::Windows::Forms::Panel());
			this->q3Text = (gcnew System::Windows::Forms::Label());
			this->q3Title = (gcnew System::Windows::Forms::Label());
			this->q3Dot = (gcnew System::Windows::Forms::Panel());
			this->queueItem2 = (gcnew System::Windows::Forms::Panel());
			this->q2Text = (gcnew System::Windows::Forms::Label());
			this->q2Title = (gcnew System::Windows::Forms::Label());
			this->q2Dot = (gcnew System::Windows::Forms::Panel());
			this->queueItem1 = (gcnew System::Windows::Forms::Panel());
			this->q1Text = (gcnew System::Windows::Forms::Label());
			this->q1Title = (gcnew System::Windows::Forms::Label());
			this->q1Dot = (gcnew System::Windows::Forms::Panel());
			this->queueTitle = (gcnew System::Windows::Forms::Label());
			this->vehiclePanel = (gcnew System::Windows::Forms::Panel());
			this->updateVehicleButton = (gcnew System::Windows::Forms::Button());
			this->maintenancePanel = (gcnew System::Windows::Forms::Panel());
			this->maintenanceText = (gcnew System::Windows::Forms::Label());
			this->maintenanceTitle = (gcnew System::Windows::Forms::Label());
			this->vehicleText = (gcnew System::Windows::Forms::Label());
			this->vehicleName = (gcnew System::Windows::Forms::Label());
			this->vehicleTitle = (gcnew System::Windows::Forms::Label());
			this->manualPanel = (gcnew System::Windows::Forms::Panel());
			this->registerButton = (gcnew System::Windows::Forms::Button());
			this->manualKmBox = (gcnew System::Windows::Forms::TextBox());
			this->manualKmLabel = (gcnew System::Windows::Forms::Label());
			this->manualTypeCombo = (gcnew System::Windows::Forms::ComboBox());
			this->manualTypeLabel = (gcnew System::Windows::Forms::Label());
			this->manualEndBox = (gcnew System::Windows::Forms::TextBox());
			this->manualEndLabel = (gcnew System::Windows::Forms::Label());
			this->manualStartBox = (gcnew System::Windows::Forms::TextBox());
			this->manualStartLabel = (gcnew System::Windows::Forms::Label());
			this->manualTitle = (gcnew System::Windows::Forms::Label());
			this->historyPanel = (gcnew System::Windows::Forms::Panel());
			this->historyListView = (gcnew System::Windows::Forms::ListView());
			this->historyTitle = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblMarco1 = (gcnew System::Windows::Forms::Label());
			this->lblMarco2 = (gcnew System::Windows::Forms::Label());
			this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
			this->lblLYNX = (gcnew System::Windows::Forms::Label());
			this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
			this->topPanel->SuspendLayout();
			this->profilePanel->SuspendLayout();
			this->lastTripPanel->SuspendLayout();
			this->metric2->SuspendLayout();
			this->metric1->SuspendLayout();
			this->queuePanel->SuspendLayout();
			this->queueItem3->SuspendLayout();
			this->queueItem2->SuspendLayout();
			this->queueItem1->SuspendLayout();
			this->vehiclePanel->SuspendLayout();
			this->maintenancePanel->SuspendLayout();
			this->manualPanel->SuspendLayout();
			this->historyPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->pnlTopBar->SuspendLayout();
			this->SuspendLayout();
			// 
			// topPanel
			// 
			this->topPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(39)));
			this->topPanel->Controls->Add(this->earningsButton);
			this->topPanel->Controls->Add(this->statusButton);
			this->topPanel->Controls->Add(this->onlineChip);
			this->topPanel->Controls->Add(this->topText);
			this->topPanel->Controls->Add(this->topTitle);
			this->topPanel->Location = System::Drawing::Point(28, 131);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(1422, 164);
			this->topPanel->TabIndex = 0;
			// 
			// earningsButton
			// 
			this->earningsButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(39)));
			this->earningsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->earningsButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->earningsButton->ForeColor = System::Drawing::Color::White;
			this->earningsButton->Location = System::Drawing::Point(1212, 102);
			this->earningsButton->Name = L"earningsButton";
			this->earningsButton->Size = System::Drawing::Size(170, 40);
			this->earningsButton->TabIndex = 4;
			this->earningsButton->Text = L"Ver ganancias";
			this->earningsButton->UseVisualStyleBackColor = false;
			// 
			// statusButton
			// 
			this->statusButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->statusButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->statusButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->statusButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->statusButton->Location = System::Drawing::Point(1036, 102);
			this->statusButton->Name = L"statusButton";
			this->statusButton->Size = System::Drawing::Size(170, 40);
			this->statusButton->TabIndex = 3;
			this->statusButton->Text = L"Cambiar estado";
			this->statusButton->UseVisualStyleBackColor = false;
			// 
			// onlineChip
			// 
			this->onlineChip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(54)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->onlineChip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->onlineChip->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->onlineChip->Location = System::Drawing::Point(1192, 24);
			this->onlineChip->Name = L"onlineChip";
			this->onlineChip->Size = System::Drawing::Size(190, 34);
			this->onlineChip->TabIndex = 2;
			this->onlineChip->Text = L"Online";
			this->onlineChip->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// topText
			// 
			this->topText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->topText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(201)),
				static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->topText->Location = System::Drawing::Point(28, 74);
			this->topText->Name = L"topText";
			this->topText->Size = System::Drawing::Size(620, 36);
			this->topText->TabIndex = 1;
			this->topText->Text = L"Disponibilidad, ganancias, viajes activos y vehiculo.";
			// 
			// topTitle
			// 
			this->topTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->topTitle->ForeColor = System::Drawing::Color::White;
			this->topTitle->Location = System::Drawing::Point(28, 28);
			this->topTitle->Name = L"topTitle";
			this->topTitle->Size = System::Drawing::Size(360, 38);
			this->topTitle->TabIndex = 0;
			this->topTitle->Text = L"Centro de control del driver";
			// 
			// profilePanel
			// 
			this->profilePanel->BackColor = System::Drawing::Color::White;
			this->profilePanel->Controls->Add(this->lastTripPanel);
			this->profilePanel->Controls->Add(this->metric2);
			this->profilePanel->Controls->Add(this->metric1);
			this->profilePanel->Controls->Add(this->profileInfo);
			this->profilePanel->Controls->Add(this->profileName);
			this->profilePanel->Controls->Add(this->profileTitle);
			this->profilePanel->Location = System::Drawing::Point(28, 224);
			this->profilePanel->Name = L"profilePanel";
			this->profilePanel->Size = System::Drawing::Size(426, 342);
			this->profilePanel->TabIndex = 1;
			// 
			// lastTripPanel
			// 
			this->lastTripPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->lastTripPanel->Controls->Add(this->lastTripText);
			this->lastTripPanel->Controls->Add(this->lastTripTitle);
			this->lastTripPanel->Controls->Add(this->lastTripDot);
			this->lastTripPanel->Location = System::Drawing::Point(22, 248);
			this->lastTripPanel->Name = L"lastTripPanel";
			this->lastTripPanel->Size = System::Drawing::Size(382, 58);
			this->lastTripPanel->TabIndex = 5;
			// 
			// lastTripText
			// 
			this->lastTripText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lastTripText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lastTripText->Location = System::Drawing::Point(34, 28);
			this->lastTripText->Name = L"lastTripText";
			this->lastTripText->Size = System::Drawing::Size(280, 18);
			this->lastTripText->TabIndex = 2;
			this->lastTripText->Text = L"Lima -> Callao | S/ 31.0";
			// 
			// lastTripTitle
			// 
			this->lastTripTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lastTripTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->lastTripTitle->Location = System::Drawing::Point(34, 8);
			this->lastTripTitle->Name = L"lastTripTitle";
			this->lastTripTitle->Size = System::Drawing::Size(120, 18);
			this->lastTripTitle->TabIndex = 1;
			this->lastTripTitle->Text = L"Ultimo viaje";
			// 
			// lastTripDot
			// 
			this->lastTripDot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->lastTripDot->Location = System::Drawing::Point(14, 22);
			this->lastTripDot->Name = L"lastTripDot";
			this->lastTripDot->Size = System::Drawing::Size(10, 10);
			this->lastTripDot->TabIndex = 0;
			// 
			// metric2
			// 
			this->metric2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->metric2->Controls->Add(this->metric2Text);
			this->metric2->Controls->Add(this->metric2Value);
			this->metric2->Location = System::Drawing::Point(224, 162);
			this->metric2->Name = L"metric2";
			this->metric2->Size = System::Drawing::Size(180, 70);
			this->metric2->TabIndex = 4;
			// 
			// metric2Text
			// 
			this->metric2Text->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->metric2Text->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->metric2Text->Location = System::Drawing::Point(14, 42);
			this->metric2Text->Name = L"metric2Text";
			this->metric2Text->Size = System::Drawing::Size(90, 18);
			this->metric2Text->TabIndex = 1;
			this->metric2Text->Text = L"rating";
			// 
			// metric2Value
			// 
			this->metric2Value->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->metric2Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->metric2Value->Location = System::Drawing::Point(14, 12);
			this->metric2Value->Name = L"metric2Value";
			this->metric2Value->Size = System::Drawing::Size(120, 26);
			this->metric2Value->TabIndex = 0;
			this->metric2Value->Text = L"1.2";
			// 
			// metric1
			// 
			this->metric1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->metric1->Controls->Add(this->metric1Text);
			this->metric1->Controls->Add(this->metric1Value);
			this->metric1->Location = System::Drawing::Point(22, 162);
			this->metric1->Name = L"metric1";
			this->metric1->Size = System::Drawing::Size(180, 70);
			this->metric1->TabIndex = 3;
			// 
			// metric1Text
			// 
			this->metric1Text->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->metric1Text->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->metric1Text->Location = System::Drawing::Point(14, 42);
			this->metric1Text->Name = L"metric1Text";
			this->metric1Text->Size = System::Drawing::Size(100, 18);
			this->metric1Text->TabIndex = 1;
			this->metric1Text->Text = L"ganado hoy";
			// 
			// metric1Value
			// 
			this->metric1Value->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->metric1Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->metric1Value->Location = System::Drawing::Point(14, 12);
			this->metric1Value->Name = L"metric1Value";
			this->metric1Value->Size = System::Drawing::Size(120, 26);
			this->metric1Value->TabIndex = 0;
			this->metric1Value->Text = L"S/ 0.00";
			// 
			// profileInfo
			// 
			this->profileInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->profileInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->profileInfo->Location = System::Drawing::Point(22, 104);
			this->profileInfo->Name = L"profileInfo";
			this->profileInfo->Size = System::Drawing::Size(240, 36);
			this->profileInfo->TabIndex = 2;
			this->profileInfo->Text = L"Driver ID D-0921 | Lima metropolitana";
			// 
			// profileName
			// 
			this->profileName->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->profileName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->profileName->Location = System::Drawing::Point(22, 62);
			this->profileName->Name = L"profileName";
			this->profileName->Size = System::Drawing::Size(430, 36);
			this->profileName->TabIndex = 1;
			this->profileName->Text = L"Salvador Rivera Chavez";
			// 
			// profileTitle
			// 
			this->profileTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->profileTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->profileTitle->Location = System::Drawing::Point(22, 20);
			this->profileTitle->Name = L"profileTitle";
			this->profileTitle->Size = System::Drawing::Size(180, 28);
			this->profileTitle->TabIndex = 0;
			this->profileTitle->Text = L"Perfil activo";
			// 
			// queuePanel
			// 
			this->queuePanel->BackColor = System::Drawing::Color::White;
			this->queuePanel->Controls->Add(this->finishButton);
			this->queuePanel->Controls->Add(this->acceptButton);
			this->queuePanel->Controls->Add(this->queueItem3);
			this->queuePanel->Controls->Add(this->queueItem2);
			this->queuePanel->Controls->Add(this->queueItem1);
			this->queuePanel->Controls->Add(this->queueTitle);
			this->queuePanel->Location = System::Drawing::Point(486, 224);
			this->queuePanel->Name = L"queuePanel";
			this->queuePanel->Size = System::Drawing::Size(560, 342);
			this->queuePanel->TabIndex = 2;
			// 
			// finishButton
			// 
			this->finishButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->finishButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->finishButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->finishButton->ForeColor = System::Drawing::Color::White;
			this->finishButton->Location = System::Drawing::Point(206, 296);
			this->finishButton->Name = L"finishButton";
			this->finishButton->Size = System::Drawing::Size(170, 34);
			this->finishButton->TabIndex = 5;
			this->finishButton->Text = L"Finalizar viaje";
			this->finishButton->UseVisualStyleBackColor = false;
			// 
			// acceptButton
			// 
			this->acceptButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->acceptButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->acceptButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->acceptButton->ForeColor = System::Drawing::Color::White;
			this->acceptButton->Location = System::Drawing::Point(22, 296);
			this->acceptButton->Name = L"acceptButton";
			this->acceptButton->Size = System::Drawing::Size(170, 34);
			this->acceptButton->TabIndex = 4;
			this->acceptButton->Text = L"Aceptar solicitud";
			this->acceptButton->UseVisualStyleBackColor = false;
			// 
			// queueItem3
			// 
			this->queueItem3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->queueItem3->Controls->Add(this->q3Text);
			this->queueItem3->Controls->Add(this->q3Title);
			this->queueItem3->Controls->Add(this->q3Dot);
			this->queueItem3->Location = System::Drawing::Point(22, 216);
			this->queueItem3->Name = L"queueItem3";
			this->queueItem3->Size = System::Drawing::Size(512, 58);
			this->queueItem3->TabIndex = 3;
			// 
			// q3Text
			// 
			this->q3Text->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->q3Text->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->q3Text->Location = System::Drawing::Point(34, 28);
			this->q3Text->Name = L"q3Text";
			this->q3Text->Size = System::Drawing::Size(340, 18);
			this->q3Text->TabIndex = 2;
			this->q3Text->Text = L"-";
			// 
			// q3Title
			// 
			this->q3Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->q3Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->q3Title->Location = System::Drawing::Point(34, 8);
			this->q3Title->Name = L"q3Title";
			this->q3Title->Size = System::Drawing::Size(160, 18);
			this->q3Title->TabIndex = 1;
			this->q3Title->Text = L"Viaje economico";
			// 
			// q3Dot
			// 
			this->q3Dot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->q3Dot->Location = System::Drawing::Point(14, 22);
			this->q3Dot->Name = L"q3Dot";
			this->q3Dot->Size = System::Drawing::Size(10, 10);
			this->q3Dot->TabIndex = 0;
			// 
			// queueItem2
			// 
			this->queueItem2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->queueItem2->Controls->Add(this->q2Text);
			this->queueItem2->Controls->Add(this->q2Title);
			this->queueItem2->Controls->Add(this->q2Dot);
			this->queueItem2->Location = System::Drawing::Point(22, 142);
			this->queueItem2->Name = L"queueItem2";
			this->queueItem2->Size = System::Drawing::Size(512, 58);
			this->queueItem2->TabIndex = 2;
			// 
			// q2Text
			// 
			this->q2Text->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->q2Text->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->q2Text->Location = System::Drawing::Point(34, 28);
			this->q2Text->Name = L"q2Text";
			this->q2Text->Size = System::Drawing::Size(340, 18);
			this->q2Text->TabIndex = 2;
			this->q2Text->Text = L"-";
			// 
			// q2Title
			// 
			this->q2Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->q2Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->q2Title->Location = System::Drawing::Point(34, 8);
			this->q2Title->Name = L"q2Title";
			this->q2Title->Size = System::Drawing::Size(160, 18);
			this->q2Title->TabIndex = 1;
			this->q2Title->Text = L"Viaje estandar";
			// 
			// q2Dot
			// 
			this->q2Dot->BackColor = System::Drawing::Color::Red;
			this->q2Dot->Location = System::Drawing::Point(14, 22);
			this->q2Dot->Name = L"q2Dot";
			this->q2Dot->Size = System::Drawing::Size(10, 10);
			this->q2Dot->TabIndex = 0;
			// 
			// queueItem1
			// 
			this->queueItem1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->queueItem1->Controls->Add(this->q1Text);
			this->queueItem1->Controls->Add(this->q1Title);
			this->queueItem1->Controls->Add(this->q1Dot);
			this->queueItem1->Location = System::Drawing::Point(22, 66);
			this->queueItem1->Name = L"queueItem1";
			this->queueItem1->Size = System::Drawing::Size(512, 58);
			this->queueItem1->TabIndex = 1;
			// 
			// q1Text
			// 
			this->q1Text->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->q1Text->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->q1Text->Location = System::Drawing::Point(34, 28);
			this->q1Text->Name = L"q1Text";
			this->q1Text->Size = System::Drawing::Size(340, 18);
			this->q1Text->TabIndex = 2;
			this->q1Text->Text = L"-";
			// 
			// q1Title
			// 
			this->q1Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->q1Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->q1Title->Location = System::Drawing::Point(34, 8);
			this->q1Title->Name = L"q1Title";
			this->q1Title->Size = System::Drawing::Size(160, 18);
			this->q1Title->TabIndex = 1;
			this->q1Title->Text = L"Viaje premium";
			// 
			// q1Dot
			// 
			this->q1Dot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->q1Dot->Location = System::Drawing::Point(14, 22);
			this->q1Dot->Name = L"q1Dot";
			this->q1Dot->Size = System::Drawing::Size(10, 10);
			this->q1Dot->TabIndex = 0;
			// 
			// queueTitle
			// 
			this->queueTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->queueTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->queueTitle->Location = System::Drawing::Point(22, 20);
			this->queueTitle->Name = L"queueTitle";
			this->queueTitle->Size = System::Drawing::Size(220, 28);
			this->queueTitle->TabIndex = 0;
			this->queueTitle->Text = L"Cola de solicitudes";
			// 
			// vehiclePanel
			// 
			this->vehiclePanel->BackColor = System::Drawing::Color::White;
			this->vehiclePanel->Controls->Add(this->updateVehicleButton);
			this->vehiclePanel->Controls->Add(this->maintenancePanel);
			this->vehiclePanel->Controls->Add(this->vehicleText);
			this->vehiclePanel->Controls->Add(this->vehicleName);
			this->vehiclePanel->Controls->Add(this->vehicleTitle);
			this->vehiclePanel->Location = System::Drawing::Point(1078, 224);
			this->vehiclePanel->Name = L"vehiclePanel";
			this->vehiclePanel->Size = System::Drawing::Size(372, 342);
			this->vehiclePanel->TabIndex = 3;
			// 
			// updateVehicleButton
			// 
			this->updateVehicleButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->updateVehicleButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->updateVehicleButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->updateVehicleButton->ForeColor = System::Drawing::Color::White;
			this->updateVehicleButton->Location = System::Drawing::Point(22, 264);
			this->updateVehicleButton->Name = L"updateVehicleButton";
			this->updateVehicleButton->Size = System::Drawing::Size(170, 34);
			this->updateVehicleButton->TabIndex = 4;
			this->updateVehicleButton->Text = L"Actualizar vehiculo";
			this->updateVehicleButton->UseVisualStyleBackColor = false;
			// 
			// maintenancePanel
			// 
			this->maintenancePanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->maintenancePanel->Controls->Add(this->maintenanceText);
			this->maintenancePanel->Controls->Add(this->maintenanceTitle);
			this->maintenancePanel->Location = System::Drawing::Point(22, 172);
			this->maintenancePanel->Name = L"maintenancePanel";
			this->maintenancePanel->Size = System::Drawing::Size(326, 70);
			this->maintenancePanel->TabIndex = 3;
			// 
			// maintenanceText
			// 
			this->maintenanceText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->maintenanceText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->maintenanceText->Location = System::Drawing::Point(16, 38);
			this->maintenanceText->Name = L"maintenanceText";
			this->maintenanceText->Size = System::Drawing::Size(220, 18);
			this->maintenanceText->TabIndex = 1;
			this->maintenanceText->Text = L"-----";
			// 
			// maintenanceTitle
			// 
			this->maintenanceTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->maintenanceTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->maintenanceTitle->Location = System::Drawing::Point(16, 14);
			this->maintenanceTitle->Name = L"maintenanceTitle";
			this->maintenanceTitle->Size = System::Drawing::Size(200, 18);
			this->maintenanceTitle->TabIndex = 0;
			this->maintenanceTitle->Text = L"-----";
			// 
			// vehicleText
			// 
			this->vehicleText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->vehicleText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->vehicleText->Location = System::Drawing::Point(22, 108);
			this->vehicleText->Name = L"vehicleText";
			this->vehicleText->Size = System::Drawing::Size(280, 42);
			this->vehicleText->TabIndex = 2;
			this->vehicleText->Text = L"Placa B4Q-129 | Sedan | Azul oscuro";
			// 
			// vehicleName
			// 
			this->vehicleName->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 22, System::Drawing::FontStyle::Bold));
			this->vehicleName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->vehicleName->Location = System::Drawing::Point(22, 66);
			this->vehicleName->Name = L"vehicleName";
			this->vehicleName->Size = System::Drawing::Size(260, 34);
			this->vehicleName->TabIndex = 1;
			this->vehicleName->Text = L"McClaren";
			// 
			// vehicleTitle
			// 
			this->vehicleTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->vehicleTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->vehicleTitle->Location = System::Drawing::Point(22, 20);
			this->vehicleTitle->Name = L"vehicleTitle";
			this->vehicleTitle->Size = System::Drawing::Size(180, 28);
			this->vehicleTitle->TabIndex = 0;
			this->vehicleTitle->Text = L"Vehiculo";
			// 
			// manualPanel
			// 
			this->manualPanel->BackColor = System::Drawing::Color::White;
			this->manualPanel->Controls->Add(this->registerButton);
			this->manualPanel->Controls->Add(this->manualKmBox);
			this->manualPanel->Controls->Add(this->manualKmLabel);
			this->manualPanel->Controls->Add(this->manualTypeCombo);
			this->manualPanel->Controls->Add(this->manualTypeLabel);
			this->manualPanel->Controls->Add(this->manualEndBox);
			this->manualPanel->Controls->Add(this->manualEndLabel);
			this->manualPanel->Controls->Add(this->manualStartBox);
			this->manualPanel->Controls->Add(this->manualStartLabel);
			this->manualPanel->Controls->Add(this->manualTitle);
			this->manualPanel->Location = System::Drawing::Point(28, 598);
			this->manualPanel->Name = L"manualPanel";
			this->manualPanel->Size = System::Drawing::Size(728, 264);
			this->manualPanel->TabIndex = 4;
			// 
			// registerButton
			// 
			this->registerButton->BackColor = System::Drawing::Color::YellowGreen;
			this->registerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->registerButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->registerButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->registerButton->Location = System::Drawing::Point(458, 174);
			this->registerButton->Name = L"registerButton";
			this->registerButton->Size = System::Drawing::Size(178, 34);
			this->registerButton->TabIndex = 9;
			this->registerButton->Text = L"Registrar";
			this->registerButton->UseVisualStyleBackColor = false;
			// 
			// manualKmBox
			// 
			this->manualKmBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)));
			this->manualKmBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->manualKmBox->Location = System::Drawing::Point(262, 182);
			this->manualKmBox->Name = L"manualKmBox";
			this->manualKmBox->Size = System::Drawing::Size(118, 20);
			this->manualKmBox->TabIndex = 8;
			this->manualKmBox->Text = L"12";
			// 
			// manualKmLabel
			// 
			this->manualKmLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->manualKmLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->manualKmLabel->Location = System::Drawing::Point(262, 156);
			this->manualKmLabel->Name = L"manualKmLabel";
			this->manualKmLabel->Size = System::Drawing::Size(130, 22);
			this->manualKmLabel->TabIndex = 7;
			this->manualKmLabel->Text = L"Kilometros";
			// 
			// manualTypeCombo
			// 
			this->manualTypeCombo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)));
			this->manualTypeCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->manualTypeCombo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->manualTypeCombo->FormattingEnabled = true;
			this->manualTypeCombo->Location = System::Drawing::Point(24, 182);
			this->manualTypeCombo->Name = L"manualTypeCombo";
			this->manualTypeCombo->Size = System::Drawing::Size(210, 21);
			this->manualTypeCombo->TabIndex = 6;
			// 
			// manualTypeLabel
			// 
			this->manualTypeLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->manualTypeLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->manualTypeLabel->Location = System::Drawing::Point(24, 156);
			this->manualTypeLabel->Name = L"manualTypeLabel";
			this->manualTypeLabel->Size = System::Drawing::Size(130, 22);
			this->manualTypeLabel->TabIndex = 5;
			this->manualTypeLabel->Text = L"Tipo";
			// 
			// manualEndBox
			// 
			this->manualEndBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)));
			this->manualEndBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->manualEndBox->Location = System::Drawing::Point(346, 102);
			this->manualEndBox->Name = L"manualEndBox";
			this->manualEndBox->Size = System::Drawing::Size(290, 20);
			this->manualEndBox->TabIndex = 4;
			this->manualEndBox->Text = L"Cuzco";
			// 
			// manualEndLabel
			// 
			this->manualEndLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->manualEndLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->manualEndLabel->Location = System::Drawing::Point(346, 76);
			this->manualEndLabel->Name = L"manualEndLabel";
			this->manualEndLabel->Size = System::Drawing::Size(130, 22);
			this->manualEndLabel->TabIndex = 3;
			this->manualEndLabel->Text = L"Destino";
			// 
			// manualStartBox
			// 
			this->manualStartBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)));
			this->manualStartBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->manualStartBox->Location = System::Drawing::Point(24, 102);
			this->manualStartBox->Name = L"manualStartBox";
			this->manualStartBox->Size = System::Drawing::Size(290, 20);
			this->manualStartBox->TabIndex = 2;
			this->manualStartBox->Text = L"Madrid";
			// 
			// manualStartLabel
			// 
			this->manualStartLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->manualStartLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->manualStartLabel->Location = System::Drawing::Point(24, 76);
			this->manualStartLabel->Name = L"manualStartLabel";
			this->manualStartLabel->Size = System::Drawing::Size(130, 22);
			this->manualStartLabel->TabIndex = 1;
			this->manualStartLabel->Text = L"Origen";
			// 
			// manualTitle
			// 
			this->manualTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->manualTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->manualTitle->Location = System::Drawing::Point(24, 20);
			this->manualTitle->Name = L"manualTitle";
			this->manualTitle->Size = System::Drawing::Size(260, 28);
			this->manualTitle->TabIndex = 0;
			this->manualTitle->Text = L"Registrar viaje manual";
			// 
			// historyPanel
			// 
			this->historyPanel->BackColor = System::Drawing::Color::White;
			this->historyPanel->Controls->Add(this->historyListView);
			this->historyPanel->Controls->Add(this->historyTitle);
			this->historyPanel->Location = System::Drawing::Point(788, 598);
			this->historyPanel->Name = L"historyPanel";
			this->historyPanel->Size = System::Drawing::Size(662, 264);
			this->historyPanel->TabIndex = 5;
			// 
			// historyListView
			// 
			this->historyListView->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)));
			this->historyListView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->historyListView->HideSelection = false;
			this->historyListView->Location = System::Drawing::Point(24, 68);
			this->historyListView->Name = L"historyListView";
			this->historyListView->Size = System::Drawing::Size(610, 164);
			this->historyListView->TabIndex = 1;
			this->historyListView->UseCompatibleStateImageBehavior = false;
			this->historyListView->View = System::Windows::Forms::View::List;
			// 
			// historyTitle
			// 
			this->historyTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->historyTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->historyTitle->Location = System::Drawing::Point(24, 20);
			this->historyTitle->Name = L"historyTitle";
			this->historyTitle->Size = System::Drawing::Size(283, 28);
			this->historyTitle->TabIndex = 0;
			this->historyTitle->Text = L"Historial del conductor";
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Red;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->label4->Location = System::Drawing::Point(21, 884);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(1443, 34);
			this->label4->TabIndex = 16;
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Visible = false;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Red;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->label1->Location = System::Drawing::Point(27, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1443, 34);
			this->label1->TabIndex = 15;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Visible = false;
			// 
			// lblMarco1
			// 
			this->lblMarco1->BackColor = System::Drawing::Color::Red;
			this->lblMarco1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->lblMarco1->Location = System::Drawing::Point(-1, 72);
			this->lblMarco1->Name = L"lblMarco1";
			this->lblMarco1->Size = System::Drawing::Size(28, 850);
			this->lblMarco1->TabIndex = 14;
			this->lblMarco1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblMarco1->Visible = false;
			// 
			// lblMarco2
			// 
			this->lblMarco2->BackColor = System::Drawing::Color::Red;
			this->lblMarco2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMarco2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->lblMarco2->Location = System::Drawing::Point(1454, 72);
			this->lblMarco2->Name = L"lblMarco2";
			this->lblMarco2->Size = System::Drawing::Size(28, 850);
			this->lblMarco2->TabIndex = 13;
			this->lblMarco2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblMarco2->Visible = false;
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
			this->pictureBoxIcon->Click += gcnew System::EventHandler(this, &DriverMenuForm::pictureBoxIcon_Click);
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
			this->pnlTopBar->TabIndex = 17;
			// 
			// DriverMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->ClientSize = System::Drawing::Size(1480, 920);
			this->Controls->Add(this->pnlTopBar);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblMarco1);
			this->Controls->Add(this->lblMarco2);
			this->Controls->Add(this->historyPanel);
			this->Controls->Add(this->manualPanel);
			this->Controls->Add(this->vehiclePanel);
			this->Controls->Add(this->queuePanel);
			this->Controls->Add(this->profilePanel);
			this->Controls->Add(this->topPanel);
			this->MinimumSize = System::Drawing::Size(1280, 818);
			this->Name = L"DriverMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LYNX | Conductor";
			this->Activated += gcnew System::EventHandler(this, &DriverMenuForm::DriverMenuForm_Activated);
			this->Load += gcnew System::EventHandler(this, &DriverMenuForm::DriverMenuForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DriverMenuForm::DriverMenuForm_KeyDown);
			this->topPanel->ResumeLayout(false);
			this->profilePanel->ResumeLayout(false);
			this->lastTripPanel->ResumeLayout(false);
			this->metric2->ResumeLayout(false);
			this->metric1->ResumeLayout(false);
			this->queuePanel->ResumeLayout(false);
			this->queueItem3->ResumeLayout(false);
			this->queueItem2->ResumeLayout(false);
			this->queueItem1->ResumeLayout(false);
			this->vehiclePanel->ResumeLayout(false);
			this->maintenancePanel->ResumeLayout(false);
			this->manualPanel->ResumeLayout(false);
			this->manualPanel->PerformLayout();
			this->historyPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
			this->pnlTopBar->ResumeLayout(false);
			this->ResumeLayout(false);

		}

	#pragma endregion
		// DATOS PUBLICOS DEL PASAJERO LOGUEADO
		public:
			String^ dni = "";
			String^ name = "";
			String^ password = "";


		// LOGICA y PUBLIC
		#pragma endregion
		public:


		private:
		//
		// Configuracion global de form
		//
			void ConfigureForm()
			{
				this->CenterToScreen();
				this->KeyPreview = true;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;

				try { this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico"); }
				catch (...) {}
			}

		//
		// Load Form
		//
			System::Void DriverMenuForm_Load(System::Object^ sender, System::EventArgs^ e)
			{
				normalSize = this->Size;
				normalLocation = this->Location;
				normalState = this->WindowState;

				try {
					this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
					this->pictureBoxIcon->Image = System::Drawing::Image::FromFile("resources/LYNX_image.png");
					this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				}
				catch (...) {}

				// RefreshDriverPanel();

				FormsStatus::SaveWindow(this);

				if (FormsStatus::isFullscreen)
				{
					FormsStatus::ApplyWindow(this);
				}
			}

		//
		// Full screen function
		//
			System::Drawing::Size normalSize;
			System::Drawing::Point normalLocation;
			System::Windows::Forms::FormWindowState normalState;

			System::Void DriverMenuForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
			{
				if (e->KeyCode == System::Windows::Forms::Keys::F11)
				{
					if (!FormsStatus::isFullscreen)
					{
						normalSize = this->Size;
						normalLocation = this->Location;
						normalState = this->WindowState;
						FormsStatus::SaveWindow(this);

						this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
						this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
						FormsStatus::isFullscreen = true;
					}
					else
					{
						this->WindowState = System::Windows::Forms::FormWindowState::Normal;
						this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
						this->Size = FormsStatus::normalSize;
						this->Location = FormsStatus::normalLocation;
						FormsStatus::isFullscreen = false;
					}
				}

				if (e->KeyCode == System::Windows::Forms::Keys::Escape && FormsStatus::isFullscreen)
				{
					this->WindowState = System::Windows::Forms::FormWindowState::Normal;
					this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
					this->Size = FormsStatus::normalSize;
					this->Location = FormsStatus::normalLocation;
					FormsStatus::isFullscreen = false;
				}
			}

		//
		// Click functions
		//
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
		// Actived Component: se refresca cuando vuelve a primer plano
		//
		System::Void DriverMenuForm_Activated(System::Object^ sender, System::EventArgs^ e)
		{
			// RefreshDriverPanel();
		}



};
}
