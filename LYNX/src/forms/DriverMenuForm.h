#pragma once
#include <windows.h>
#include "../library/FormsStatus.h"
#include "../AuthManager.h"
#include "../TripManager.h"
#include <msclr/marshal_cppstd.h>
#include <iomanip>
#include <sstream>
#include <ctime>

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
	private: System::Windows::Forms::Label^ onlineChip;
	private: System::Windows::Forms::Button^ statusButton;
	private: System::Windows::Forms::Button^ earningsButton;
	private: System::Windows::Forms::Panel^ profilePanel;
	private: System::Windows::Forms::Label^ profileTitle;
	private: System::Windows::Forms::Label^ profileName;
	private: System::Windows::Forms::Label^ profileInfo;



	private: System::Windows::Forms::Panel^ metric2;
	private: System::Windows::Forms::Label^ metric2Value;
	private: System::Windows::Forms::Label^ metric2Text;
	private: System::Windows::Forms::Panel^ lastTripPanel;
	private: System::Windows::Forms::Panel^ lastTripDot;
	private: System::Windows::Forms::Label^ lastTripTitle;
	private: System::Windows::Forms::Label^ lastTripText;
	private: System::Windows::Forms::Panel^ queuePanel;
	private: System::Windows::Forms::Label^ gainsTitle;















	private: System::Windows::Forms::Panel^ vehiclePanel;
	private: System::Windows::Forms::Label^ vehicleTitle;
	private: System::Windows::Forms::Label^ vehicleName;
	private: System::Windows::Forms::Label^ vehicleText;
	private: System::Windows::Forms::Panel^ maintenancePanel;
	private: System::Windows::Forms::Label^ maintenanceTitle;
	private: System::Windows::Forms::Label^ maintenanceText;
	private: System::Windows::Forms::Button^ btnUpdateVehicle;

	private: System::Windows::Forms::Panel^ manualPanel;
	private: System::Windows::Forms::Label^ manualTitle;
	private: System::Windows::Forms::Label^ manualStartLabel;
	private: System::Windows::Forms::TextBox^ tbOrigin;

	private: System::Windows::Forms::Label^ manualEndLabel;
	private: System::Windows::Forms::TextBox^ tbDestination;

	private: System::Windows::Forms::Label^ manualTypeLabel;

	private: System::Windows::Forms::Label^ manualKmLabel;
	private: System::Windows::Forms::TextBox^ tbDistance;
	private: System::Windows::Forms::Button^ btnRegister;


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
private: System::Windows::Forms::Button^ btnPremium;
private: System::Windows::Forms::Button^ btnStandard;
private: System::Windows::Forms::Button^ btnEconomic;
private: System::Windows::Forms::Label^ lblGains;
private: System::Windows::Forms::Label^ lblTrips;
private: System::Windows::Forms::Label^ lblNetGainsNumber;

private: System::Windows::Forms::Label^ lblGainsNumber;
private: System::Windows::Forms::Label^ lblComisionNumber;



private: System::Windows::Forms::Label^ lblTripsNumber;
private: System::Windows::Forms::Label^ lblComision;
private: System::Windows::Forms::Label^ lblNetGains;
private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::Button^ btnLeft;
private: System::Windows::Forms::Button^ btnRight;
private: System::Windows::Forms::Label^ lbltipes;

private: System::Windows::Forms::Label^ lblOtoD;
private: System::Windows::Forms::Label^ lblprice;

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
			this->topTitle = (gcnew System::Windows::Forms::Label());
			this->profilePanel = (gcnew System::Windows::Forms::Panel());
			this->lastTripPanel = (gcnew System::Windows::Forms::Panel());
			this->lastTripText = (gcnew System::Windows::Forms::Label());
			this->lastTripTitle = (gcnew System::Windows::Forms::Label());
			this->lastTripDot = (gcnew System::Windows::Forms::Panel());
			this->metric2 = (gcnew System::Windows::Forms::Panel());
			this->metric2Text = (gcnew System::Windows::Forms::Label());
			this->metric2Value = (gcnew System::Windows::Forms::Label());
			this->profileInfo = (gcnew System::Windows::Forms::Label());
			this->profileName = (gcnew System::Windows::Forms::Label());
			this->profileTitle = (gcnew System::Windows::Forms::Label());
			this->queuePanel = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->lblTrips = (gcnew System::Windows::Forms::Label());
			this->lblTripsNumber = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->lblGainsNumber = (gcnew System::Windows::Forms::Label());
			this->lblGains = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblNetGains = (gcnew System::Windows::Forms::Label());
			this->lblNetGainsNumber = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblComision = (gcnew System::Windows::Forms::Label());
			this->lblComisionNumber = (gcnew System::Windows::Forms::Label());
			this->gainsTitle = (gcnew System::Windows::Forms::Label());
			this->vehiclePanel = (gcnew System::Windows::Forms::Panel());
			this->btnUpdateVehicle = (gcnew System::Windows::Forms::Button());
			this->maintenancePanel = (gcnew System::Windows::Forms::Panel());
			this->maintenanceText = (gcnew System::Windows::Forms::Label());
			this->maintenanceTitle = (gcnew System::Windows::Forms::Label());
			this->vehicleText = (gcnew System::Windows::Forms::Label());
			this->vehicleName = (gcnew System::Windows::Forms::Label());
			this->vehicleTitle = (gcnew System::Windows::Forms::Label());
			this->manualPanel = (gcnew System::Windows::Forms::Panel());
			this->btnPremium = (gcnew System::Windows::Forms::Button());
			this->btnStandard = (gcnew System::Windows::Forms::Button());
			this->btnEconomic = (gcnew System::Windows::Forms::Button());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->tbDistance = (gcnew System::Windows::Forms::TextBox());
			this->manualKmLabel = (gcnew System::Windows::Forms::Label());
			this->manualTypeLabel = (gcnew System::Windows::Forms::Label());
			this->tbDestination = (gcnew System::Windows::Forms::TextBox());
			this->manualEndLabel = (gcnew System::Windows::Forms::Label());
			this->tbOrigin = (gcnew System::Windows::Forms::TextBox());
			this->manualStartLabel = (gcnew System::Windows::Forms::Label());
			this->manualTitle = (gcnew System::Windows::Forms::Label());
			this->historyPanel = (gcnew System::Windows::Forms::Panel());
			this->lblprice = (gcnew System::Windows::Forms::Label());
			this->lbltipes = (gcnew System::Windows::Forms::Label());
			this->lblOtoD = (gcnew System::Windows::Forms::Label());
			this->btnRight = (gcnew System::Windows::Forms::Button());
			this->btnLeft = (gcnew System::Windows::Forms::Button());
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
			this->queuePanel->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
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
			this->topPanel->Controls->Add(this->topTitle);
			this->topPanel->Location = System::Drawing::Point(28, 108);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(1422, 97);
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
			// topTitle
			// 
			this->topTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->topTitle->ForeColor = System::Drawing::Color::White;
			this->topTitle->Location = System::Drawing::Point(25, 24);
			this->topTitle->Name = L"topTitle";
			this->topTitle->Size = System::Drawing::Size(517, 38);
			this->topTitle->TabIndex = 0;
			this->topTitle->Text = L"Centro de control ";
			// 
			// profilePanel
			// 
			this->profilePanel->BackColor = System::Drawing::Color::White;
			this->profilePanel->Controls->Add(this->lastTripPanel);
			this->profilePanel->Controls->Add(this->metric2);
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
			this->lastTripText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->lastTripText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lastTripText->Location = System::Drawing::Point(34, 26);
			this->lastTripText->Name = L"lastTripText";
			this->lastTripText->Size = System::Drawing::Size(345, 24);
			this->lastTripText->TabIndex = 2;
			this->lastTripText->Text = L"Lima -> Callao | S/ 31.0";
			this->lastTripText->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
			this->metric2->Location = System::Drawing::Point(25, 162);
			this->metric2->Name = L"metric2";
			this->metric2->Size = System::Drawing::Size(379, 70);
			this->metric2->TabIndex = 4;
			// 
			// metric2Text
			// 
			this->metric2Text->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->metric2Text->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->metric2Text->Location = System::Drawing::Point(8, 29);
			this->metric2Text->Name = L"metric2Text";
			this->metric2Text->Size = System::Drawing::Size(51, 18);
			this->metric2Text->TabIndex = 1;
			this->metric2Text->Text = L"rating";
			// 
			// metric2Value
			// 
			this->metric2Value->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 26, System::Drawing::FontStyle::Bold));
			this->metric2Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->metric2Value->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->metric2Value->Location = System::Drawing::Point(51, 10);
			this->metric2Value->Name = L"metric2Value";
			this->metric2Value->Size = System::Drawing::Size(325, 52);
			this->metric2Value->TabIndex = 0;
			this->metric2Value->Text = L"1.2";
			this->metric2Value->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
			this->profileName->Size = System::Drawing::Size(401, 36);
			this->profileName->TabIndex = 1;
			this->profileName->Text = L"Salvador Rivera Chavez";
			// 
			// profileTitle
			// 
			this->profileTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->profileTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->profileTitle->Location = System::Drawing::Point(5, 7);
			this->profileTitle->Name = L"profileTitle";
			this->profileTitle->Size = System::Drawing::Size(180, 28);
			this->profileTitle->TabIndex = 0;
			this->profileTitle->Text = L"Perfil";
			// 
			// queuePanel
			// 
			this->queuePanel->BackColor = System::Drawing::Color::White;
			this->queuePanel->Controls->Add(this->panel4);
			this->queuePanel->Controls->Add(this->panel3);
			this->queuePanel->Controls->Add(this->panel2);
			this->queuePanel->Controls->Add(this->panel1);
			this->queuePanel->Controls->Add(this->gainsTitle);
			this->queuePanel->Location = System::Drawing::Point(486, 224);
			this->queuePanel->Name = L"queuePanel";
			this->queuePanel->Size = System::Drawing::Size(560, 342);
			this->queuePanel->TabIndex = 2;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->panel4->Controls->Add(this->lblTrips);
			this->panel4->Controls->Add(this->lblTripsNumber);
			this->panel4->Location = System::Drawing::Point(38, 34);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(242, 134);
			this->panel4->TabIndex = 18;
			// 
			// lblTrips
			// 
			this->lblTrips->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblTrips->ForeColor = System::Drawing::Color::White;
			this->lblTrips->Location = System::Drawing::Point(7, 9);
			this->lblTrips->Name = L"lblTrips";
			this->lblTrips->Size = System::Drawing::Size(130, 22);
			this->lblTrips->TabIndex = 13;
			this->lblTrips->Text = L"Viajes";
			// 
			// lblTripsNumber
			// 
			this->lblTripsNumber->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->lblTripsNumber->ForeColor = System::Drawing::Color::White;
			this->lblTripsNumber->Location = System::Drawing::Point(13, 32);
			this->lblTripsNumber->Name = L"lblTripsNumber";
			this->lblTripsNumber->Size = System::Drawing::Size(177, 36);
			this->lblTripsNumber->TabIndex = 6;
			this->lblTripsNumber->Text = L"0";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel3->Controls->Add(this->lblGainsNumber);
			this->panel3->Controls->Add(this->lblGains);
			this->panel3->Location = System::Drawing::Point(286, 34);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(242, 134);
			this->panel3->TabIndex = 17;
			// 
			// lblGainsNumber
			// 
			this->lblGainsNumber->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->lblGainsNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblGainsNumber->Location = System::Drawing::Point(9, 31);
			this->lblGainsNumber->Name = L"lblGainsNumber";
			this->lblGainsNumber->Size = System::Drawing::Size(219, 36);
			this->lblGainsNumber->TabIndex = 8;
			this->lblGainsNumber->Text = L"S/0";
			// 
			// lblGains
			// 
			this->lblGains->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblGains->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->lblGains->Location = System::Drawing::Point(3, 9);
			this->lblGains->Name = L"lblGains";
			this->lblGains->Size = System::Drawing::Size(130, 22);
			this->lblGains->TabIndex = 14;
			this->lblGains->Text = L"Ganancia bruta";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->panel2->Controls->Add(this->lblNetGains);
			this->panel2->Controls->Add(this->lblNetGainsNumber);
			this->panel2->Location = System::Drawing::Point(286, 178);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(242, 145);
			this->panel2->TabIndex = 16;
			// 
			// lblNetGains
			// 
			this->lblNetGains->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblNetGains->ForeColor = System::Drawing::Color::White;
			this->lblNetGains->Location = System::Drawing::Point(3, 6);
			this->lblNetGains->Name = L"lblNetGains";
			this->lblNetGains->Size = System::Drawing::Size(130, 22);
			this->lblNetGains->TabIndex = 16;
			this->lblNetGains->Text = L"Ganancia neta";
			// 
			// lblNetGainsNumber
			// 
			this->lblNetGainsNumber->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->lblNetGainsNumber->ForeColor = System::Drawing::Color::White;
			this->lblNetGainsNumber->Location = System::Drawing::Point(9, 32);
			this->lblNetGainsNumber->Name = L"lblNetGainsNumber";
			this->lblNetGainsNumber->Size = System::Drawing::Size(242, 36);
			this->lblNetGainsNumber->TabIndex = 9;
			this->lblNetGainsNumber->Text = L"S/0";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel1->Controls->Add(this->lblComision);
			this->panel1->Controls->Add(this->lblComisionNumber);
			this->panel1->Location = System::Drawing::Point(38, 178);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(242, 145);
			this->panel1->TabIndex = 5;
			// 
			// lblComision
			// 
			this->lblComision->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblComision->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->lblComision->Location = System::Drawing::Point(7, 6);
			this->lblComision->Name = L"lblComision";
			this->lblComision->Size = System::Drawing::Size(130, 22);
			this->lblComision->TabIndex = 15;
			this->lblComision->Text = L"Comision (20%)";
			// 
			// lblComisionNumber
			// 
			this->lblComisionNumber->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->lblComisionNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblComisionNumber->Location = System::Drawing::Point(3, 32);
			this->lblComisionNumber->Name = L"lblComisionNumber";
			this->lblComisionNumber->Size = System::Drawing::Size(208, 36);
			this->lblComisionNumber->TabIndex = 7;
			this->lblComisionNumber->Text = L"S/0";
			// 
			// gainsTitle
			// 
			this->gainsTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->gainsTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->gainsTitle->Location = System::Drawing::Point(3, 7);
			this->gainsTitle->Name = L"gainsTitle";
			this->gainsTitle->Size = System::Drawing::Size(220, 28);
			this->gainsTitle->TabIndex = 0;
			this->gainsTitle->Text = L"Ganancias";
			// 
			// vehiclePanel
			// 
			this->vehiclePanel->BackColor = System::Drawing::Color::White;
			this->vehiclePanel->Controls->Add(this->btnUpdateVehicle);
			this->vehiclePanel->Controls->Add(this->maintenancePanel);
			this->vehiclePanel->Controls->Add(this->vehicleText);
			this->vehiclePanel->Controls->Add(this->vehicleName);
			this->vehiclePanel->Controls->Add(this->vehicleTitle);
			this->vehiclePanel->Location = System::Drawing::Point(1078, 224);
			this->vehiclePanel->Name = L"vehiclePanel";
			this->vehiclePanel->Size = System::Drawing::Size(372, 342);
			this->vehiclePanel->TabIndex = 3;
			// 
			// btnUpdateVehicle
			// 
			this->btnUpdateVehicle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->btnUpdateVehicle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUpdateVehicle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnUpdateVehicle->ForeColor = System::Drawing::Color::White;
			this->btnUpdateVehicle->Location = System::Drawing::Point(22, 264);
			this->btnUpdateVehicle->Name = L"btnUpdateVehicle";
			this->btnUpdateVehicle->Size = System::Drawing::Size(170, 34);
			this->btnUpdateVehicle->TabIndex = 4;
			this->btnUpdateVehicle->Text = L"Actualizar vehiculo";
			this->btnUpdateVehicle->UseVisualStyleBackColor = false;
			this->btnUpdateVehicle->Click += gcnew System::EventHandler(this, &DriverMenuForm::btnUpdateVehicle_Click);
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
			this->manualPanel->Controls->Add(this->btnPremium);
			this->manualPanel->Controls->Add(this->btnStandard);
			this->manualPanel->Controls->Add(this->btnEconomic);
			this->manualPanel->Controls->Add(this->btnRegister);
			this->manualPanel->Controls->Add(this->tbDistance);
			this->manualPanel->Controls->Add(this->manualKmLabel);
			this->manualPanel->Controls->Add(this->manualTypeLabel);
			this->manualPanel->Controls->Add(this->tbDestination);
			this->manualPanel->Controls->Add(this->manualEndLabel);
			this->manualPanel->Controls->Add(this->tbOrigin);
			this->manualPanel->Controls->Add(this->manualStartLabel);
			this->manualPanel->Controls->Add(this->manualTitle);
			this->manualPanel->Location = System::Drawing::Point(28, 598);
			this->manualPanel->Name = L"manualPanel";
			this->manualPanel->Size = System::Drawing::Size(728, 264);
			this->manualPanel->TabIndex = 4;
			// 
			// btnPremium
			// 
			this->btnPremium->BackColor = System::Drawing::Color::White;
			this->btnPremium->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnPremium->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
			this->btnPremium->Location = System::Drawing::Point(191, 178);
			this->btnPremium->Name = L"btnPremium";
			this->btnPremium->Size = System::Drawing::Size(75, 33);
			this->btnPremium->TabIndex = 12;
			this->btnPremium->Text = L"Premium";
			this->btnPremium->UseVisualStyleBackColor = false;
			this->btnPremium->Click += gcnew System::EventHandler(this, &DriverMenuForm::btnPremium_Click);
			// 
			// btnStandard
			// 
			this->btnStandard->BackColor = System::Drawing::Color::White;
			this->btnStandard->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStandard->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
			this->btnStandard->Location = System::Drawing::Point(110, 178);
			this->btnStandard->Name = L"btnStandard";
			this->btnStandard->Size = System::Drawing::Size(75, 33);
			this->btnStandard->TabIndex = 11;
			this->btnStandard->Text = L"Standard";
			this->btnStandard->UseVisualStyleBackColor = false;
			this->btnStandard->Click += gcnew System::EventHandler(this, &DriverMenuForm::btnStandard_Click);
			// 
			// btnEconomic
			// 
			this->btnEconomic->BackColor = System::Drawing::Color::White;
			this->btnEconomic->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnEconomic->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
			this->btnEconomic->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnEconomic->Location = System::Drawing::Point(29, 177);
			this->btnEconomic->Name = L"btnEconomic";
			this->btnEconomic->Size = System::Drawing::Size(75, 33);
			this->btnEconomic->TabIndex = 10;
			this->btnEconomic->Text = L"Economico";
			this->btnEconomic->UseVisualStyleBackColor = false;
			this->btnEconomic->Click += gcnew System::EventHandler(this, &DriverMenuForm::btnEconomic_Click);
			// 
			// btnRegister
			// 
			this->btnRegister->BackColor = System::Drawing::Color::Black;
			this->btnRegister->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->btnRegister->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnRegister->Location = System::Drawing::Point(516, 167);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(154, 44);
			this->btnRegister->TabIndex = 9;
			this->btnRegister->Text = L"Registrar";
			this->btnRegister->UseVisualStyleBackColor = false;
			this->btnRegister->Click += gcnew System::EventHandler(this, &DriverMenuForm::btnRegister_Click);
			this->btnRegister->Leave += gcnew System::EventHandler(this, &DriverMenuForm::btnRegister_Leave);
			this->btnRegister->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &DriverMenuForm::btnRegister_MouseDown);
			this->btnRegister->MouseLeave += gcnew System::EventHandler(this, &DriverMenuForm::btnRegister_MouseLeave);
			this->btnRegister->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &DriverMenuForm::btnRegister_MouseMove);
			// 
			// tbDistance
			// 
			this->tbDistance->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbDistance->Location = System::Drawing::Point(349, 178);
			this->tbDistance->Name = L"tbDistance";
			this->tbDistance->Size = System::Drawing::Size(97, 27);
			this->tbDistance->TabIndex = 8;
			// 
			// manualKmLabel
			// 
			this->manualKmLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->manualKmLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->manualKmLabel->Location = System::Drawing::Point(346, 156);
			this->manualKmLabel->Name = L"manualKmLabel";
			this->manualKmLabel->Size = System::Drawing::Size(130, 22);
			this->manualKmLabel->TabIndex = 7;
			this->manualKmLabel->Text = L"Kilometros";
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
			// tbDestination
			// 
			this->tbDestination->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbDestination->Location = System::Drawing::Point(349, 101);
			this->tbDestination->Name = L"tbDestination";
			this->tbDestination->Size = System::Drawing::Size(237, 27);
			this->tbDestination->TabIndex = 4;
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
			// tbOrigin
			// 
			this->tbOrigin->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbOrigin->Location = System::Drawing::Point(25, 101);
			this->tbOrigin->Name = L"tbOrigin";
			this->tbOrigin->Size = System::Drawing::Size(221, 27);
			this->tbOrigin->TabIndex = 2;
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
			this->manualTitle->Text = L"Registrar viaje";
			// 
			// historyPanel
			// 
			this->historyPanel->BackColor = System::Drawing::Color::White;
			this->historyPanel->Controls->Add(this->lblprice);
			this->historyPanel->Controls->Add(this->lbltipes);
			this->historyPanel->Controls->Add(this->lblOtoD);
			this->historyPanel->Controls->Add(this->btnRight);
			this->historyPanel->Controls->Add(this->btnLeft);
			this->historyPanel->Controls->Add(this->historyListView);
			this->historyPanel->Controls->Add(this->historyTitle);
			this->historyPanel->Location = System::Drawing::Point(788, 598);
			this->historyPanel->Name = L"historyPanel";
			this->historyPanel->Size = System::Drawing::Size(662, 264);
			this->historyPanel->TabIndex = 5;
			// 
			// lblprice
			// 
			this->lblprice->BackColor = System::Drawing::Color::Transparent;
			this->lblprice->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 25, System::Drawing::FontStyle::Bold));
			this->lblprice->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblprice->Location = System::Drawing::Point(36, 137);
			this->lblprice->Name = L"lblprice";
			this->lblprice->Size = System::Drawing::Size(238, 68);
			this->lblprice->TabIndex = 7;
			this->lblprice->Text = L"S/ 0";
			this->lblprice->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbltipes
			// 
			this->lbltipes->BackColor = System::Drawing::Color::WhiteSmoke;
			this->lbltipes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 22, System::Drawing::FontStyle::Bold));
			this->lbltipes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lbltipes->Location = System::Drawing::Point(384, 156);
			this->lbltipes->Name = L"lbltipes";
			this->lbltipes->Size = System::Drawing::Size(238, 34);
			this->lbltipes->TabIndex = 6;
			this->lbltipes->Text = L"predaresu";
			this->lbltipes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblOtoD
			// 
			this->lblOtoD->BackColor = System::Drawing::Color::Transparent;
			this->lblOtoD->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 22, System::Drawing::FontStyle::Bold));
			this->lblOtoD->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblOtoD->Location = System::Drawing::Point(36, 76);
			this->lblOtoD->Name = L"lblOtoD";
			this->lblOtoD->Size = System::Drawing::Size(586, 34);
			this->lblOtoD->TabIndex = 5;
			this->lblOtoD->Text = L"0 --- 0";
			this->lblOtoD->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnRight
			// 
			this->btnRight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnRight->Location = System::Drawing::Point(636, 137);
			this->btnRight->Name = L"btnRight";
			this->btnRight->Size = System::Drawing::Size(24, 23);
			this->btnRight->TabIndex = 3;
			this->btnRight->Text = L">";
			this->btnRight->UseVisualStyleBackColor = false;
			this->btnRight->Click += gcnew System::EventHandler(this, &DriverMenuForm::btnRight_Click);
			// 
			// btnLeft
			// 
			this->btnLeft->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnLeft->Location = System::Drawing::Point(1, 137);
			this->btnLeft->Name = L"btnLeft";
			this->btnLeft->Size = System::Drawing::Size(24, 23);
			this->btnLeft->TabIndex = 2;
			this->btnLeft->Text = L"<";
			this->btnLeft->UseVisualStyleBackColor = false;
			this->btnLeft->Click += gcnew System::EventHandler(this, &DriverMenuForm::btnLeft_Click);
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
			this->BackColor = System::Drawing::SystemColors::Control;
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
			this->queuePanel->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
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
		// DATOS PUBLICOS DEL CONDUCTOR LOGUEADO
		public:
			String^ dni = "";
			String^ name = "";
			String^ password = "";


		// LOGICA y PUBLIC
		#pragma endregion
		public:


		private:

			String^ toManagedString(const std::string& value)
			{
				return gcnew System::String(value.c_str());
			}

			String^ formatNumber(int value)
			{
				return toManagedString(std::to_string(value));
			}

			String^ formatNumber(float value)
			{
				std::ostringstream oss;
				oss << std::fixed << std::setprecision(2) << value;
				return toManagedString(oss.str());
			}

			String^ formatCurrency(float value)
			{
				return System::String::Concat(L"S/ ", formatNumber(value));
			}

			String^ tripTypeText(int type)
			{
				switch (type) {
				case 1: return L"ECONOMICO";
				case 2: return L"STANDARD";
				case 3: return L"PREMIUM";
				default: return L"NINGUNO";
				}
			}

			void paintTripType(int type)
			{
				switch (type) {
				case 1:
					this->lastTripDot->BackColor = System::Drawing::Color::LightGreen;
					this->lbltipes->BackColor = System::Drawing::Color::LightGreen;
					break;
				case 2:
					this->lastTripDot->BackColor = System::Drawing::Color::LightSteelBlue;
					this->lbltipes->BackColor = System::Drawing::Color::LightSteelBlue;
					break;
				case 3:
					this->lastTripDot->BackColor = System::Drawing::Color::Goldenrod;
					this->lbltipes->BackColor = System::Drawing::Color::Goldenrod;
					break;
				default:
					this->lastTripDot->BackColor = System::Drawing::Color::DarkGray;
					this->lbltipes->BackColor = System::Drawing::SystemColors::Control;
					break;
				}
			}

			std::vector<Trip> getDriverHistory(const std::string& driverDni)
			{
				std::vector<Trip> historial = exportarHistoryTrips(*tripManager);
				std::vector<Trip> historialDriver;

				for (int i = 0; i < historial.size(); i++) {
					if (historial[i].getDriverDni() == driverDni) {
						historialDriver.push_back(historial[i]);
					}
				}

				return historialDriver;
			}

			void updateDriverStats(const Driver& current)
			{
				this->lblTripsNumber->Text = formatNumber(current.getTotalTrips());
				this->lblGainsNumber->Text = formatCurrency(current.getTotalEarnings());
				this->lblComisionNumber->Text = formatCurrency(current.getTotalEarnings() * 0.20f);
				this->lblNetGainsNumber->Text = formatCurrency(current.getNetEarnings());
			}

			void showNoTrips()
			{
				this->lastTripText->Text = L"No hay viajes registrados";
				this->lblOtoD->Text = L"-";
				this->lblprice->Text = L"S/ 0.00";
				this->lbltipes->Text = L"NINGUNO";
				paintTripType(0);
			}

			void showTripAtIndex(const std::vector<Trip>& historialDriver, int requestedIndex)
			{
				if (historialDriver.empty()) {
					index = 0;
					showNoTrips();
					return;
				}

				if (requestedIndex < 0) requestedIndex = 0;
				if (requestedIndex >= historialDriver.size()) requestedIndex = historialDriver.size() - 1;
				index = requestedIndex;

				const Trip& trip = historialDriver[index];
				String^ ori = toManagedString(trip.getOrigin());
				String^ desti = toManagedString(trip.getDestination());
				String^ price = formatCurrency(trip.getPrice());
				String^ typeText = tripTypeText(trip.getTipe());

				this->lastTripText->Text = System::String::Concat(gcnew array<System::String^>{ ori, L" -> ", desti, L" | ", price, L" ", typeText });
				this->lblOtoD->Text = System::String::Concat(ori, L" --- ", desti);
				this->lblprice->Text = price;
				this->lbltipes->Text = typeText;
				paintTripType(trip.getTipe());
			}

			
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
			// Cuando cargue el formulario
			System::Void DriverMenuForm_Load(System::Object^ sender, System::EventArgs^ e)
			{
				normalSize = this->Size;
				normalLocation = this->Location;
				normalState = this->WindowState;

				if (authManager == nullptr || String::IsNullOrEmpty(loggedDriverDni))
					return;

				String^ driverDni = loggedDriverDni;
				std::string dniStr = msclr::interop::marshal_as<std::string>(driverDni);


				Driver d = authManager->getDriverByDni(dniStr);
				String^ n= gcnew System::String(d.getName().c_str());
				String^ id = gcnew System::String(d.getDriverId().c_str());
				float profit = d.getNetEarnings();
				float rating=d.getRating();
				String^ model = gcnew System::String(d.getVehicle().getModel().c_str());
				String^ brand = gcnew System::String(d.getVehicle().getBrand().c_str());
				String^ plate = gcnew System::String(d.getVehicle().getPlate().c_str());
				String^ colour = gcnew System::String(d.getVehicle().getColor().c_str());
				int year = d.getVehicle().getYear();

				this->profileName->Text = n;
				this->profileInfo->Text = System::String::Concat(L"Driver ID: ", id, L" | Lima metropolitana");
				this->metric2Value->Text = formatNumber(rating);
				this->vehicleName->Text = brand;
				this->vehicleText->Text = System::String::Concat(gcnew array<System::String^>{ L"Placa ", plate, L" | ", model, L" | ", colour, L" | ", formatNumber(year) });

				Driver current = authManager->getDriverByDni(dniStr);
				
				updateDriverStats(current);
				showTripAtIndex(getDriverHistory(dniStr), 0);

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



private: System::Void btnPremium_Click(System::Object^ sender, System::EventArgs^ e) {
	this->btnPremium->BackColor = System::Drawing::Color::Black;
	this->btnPremium->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->btnStandard->BackColor = System::Drawing::Color::White;
	this->btnStandard->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->btnEconomic->BackColor = System::Drawing::Color::White;
	this->btnEconomic->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	type = 3;
}
	   String^ origin;
	   String^ destination;
	   String^ driverName;
	   String^ driverDni;
	   int type = 0;
	   int originalType = 0;
	   float distance = 0;

	   bool isNaNString(const std::string& str) {
		   std::istringstream iss(str);
		   double num;
		   return !(iss >> num && iss.eof());
	   }
	   string generarTripId(TripManager& tripMgr)
	   {
		   return tripMgr.previewNextTripId();
	   }
	   string fechaActual()
	   {
		   std::time_t now = std::time(nullptr);
		   std::tm localTime{};
		   localtime_s(&localTime, &now);
		   char buffer[16];
		   std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", &localTime);
		   return buffer;
	   }
	   void guardarDatos(FileManager& fileManager, AuthManager& authMgr, TripManager& tripMgr)
	   {
		   authMgr.saveAll();
		   fileManager.guardarTripsTXT(exportarTodosLosTrips(tripMgr));
	   }
	   vector<Trip> exportarTodosLosTrips(TripManager& tripMgr)
	   {
		   vector<Trip> total = exportarWaitingTrips(tripMgr);
		   vector<Trip> activos = exportarActiveTrips(tripMgr);
		   vector<Trip> historial = exportarHistoryTrips(tripMgr);
		   total.insert(total.end(), activos.begin(), activos.end());
		   total.insert(total.end(), historial.begin(), historial.end());
		   return total;
	   }
	   vector<Trip> exportarWaitingTrips(TripManager& tripMgr)
	   {
		   vector<Trip> lista;
		   auto waitingQueue = tripMgr.getWaitingQueue();

		   while (!waitingQueue.isEmpty()) {
			   Trip t = waitingQueue.getFront();
			   lista.push_back(t);
			   waitingQueue.dequeue();
		   }
		   return lista;
	   }
	   vector<Trip> exportarActiveTrips(TripManager& tripMgr)
	   {
		   vector<Trip> lista;
		   for (int i = 0; i < tripMgr.getActiveTrips().getSize(); i++) {
			   lista.push_back(tripMgr.getActiveTrips().get(i));
		   }
		   return lista;
	   }
	   vector<Trip> exportarHistoryTrips(TripManager& tripMgr)
	   {
		   vector<Trip> lista;
		   ::Stack<Trip>& history = tripMgr.getHistory();
		   ::Stack<Trip> temp;
		   while (!history.isEmpty()) {
			   Trip t = history.peek();
			   lista.push_back(t);
			   temp.push(t);
			   history.pop();
		   }
		   while (!temp.isEmpty()) {
			   history.push(temp.peek());
			   temp.pop();
		   }
		   return lista;
	   }

private: System::Void btnStandard_Click(System::Object^ sender, System::EventArgs^ e) {
	this->btnStandard->BackColor = System::Drawing::Color::Black;
	this->btnStandard->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->btnEconomic->BackColor = System::Drawing::Color::White;
	this->btnEconomic->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->btnPremium->BackColor = System::Drawing::Color::White;
	this->btnPremium->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	type = 2;
}
private: System::Void btnEconomic_Click(System::Object^ sender, System::EventArgs^ e) {
	this->btnEconomic->BackColor = System::Drawing::Color::Black;
	this->btnEconomic->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->btnStandard->BackColor = System::Drawing::Color::White;
	this->btnStandard->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->btnPremium->BackColor = System::Drawing::Color::White;
	this->btnPremium->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	type = 1;
}
private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
	origin = this->tbOrigin->Text->Trim();
	destination = this->tbDestination->Text->Trim();

	

	//si esta vacio retorna y muestra una alerta
	if (this->tbDistance->Text == "" || this->tbDestination->Text == "" || this->tbOrigin->Text == "" || type == 0) {
		MessageBox::Show("Por favor llene todos los campos", "Solicitar Viaje", MessageBoxButtons::OK);
		return;
	}

	// Verifica si la distancia es contiene alguna letra o caracter que no sea numero
	if (isNaNString(msclr::interop::marshal_as<std::string>(this->tbDistance->Text->Trim()))) {
		MessageBox::Show("La distancia debe ser un numero", "Solicitar Viaje", MessageBoxButtons::OK);
		return;
	}
	originalType = type;
	type = 0;
	distance = std::stof(msclr::interop::marshal_as<std::string>(this->tbDistance->Text->Trim()));

	String^ dnii = loggedDriverDni;
	String^ o = origin;
	String^ d = destination;

	string dniii = msclr::interop::marshal_as<std::string>(dnii);
	Driver current = authManager->getDriverByDni(dniii);
	Trip nuevo;
	nuevo.setTripId(generarTripId(*tripManager));
	nuevo.setOrigin(msclr::interop::marshal_as<std::string>(o)); nuevo.setDestination(msclr::interop::marshal_as<std::string>(d));
	nuevo.setTipe(originalType); nuevo.setPassengerDni("");
	nuevo.setDriverName(current.getName()); nuevo.setDriverDni(msclr::interop::marshal_as<std::string>(dnii)); nuevo.setDate(fechaActual());
	nuevo.setPrice(nuevo.calcPrice(originalType, distance)); nuevo.setStatus("completado");

	authManager->driverAcceptRide(dniii, nuevo.getPrice());
	authManager->driverFinishRide(dniii);
	tripManager->getHistory().push(nuevo);
	guardarDatos(*fileManager, *authManager, *tripManager);
	
	
	current = authManager->getDriverByDni(dniii);
	//limpia el apartado de solicitar viaje
	this->tbOrigin->Text = "";
	this->tbDestination->Text = "";
	this->tbDistance->Text = "";

	
	//Todos los botones a su color predeterminado
	this->btnStandard->BackColor = System::Drawing::Color::White;
	this->btnStandard->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->btnEconomic->BackColor = System::Drawing::Color::White;
	this->btnEconomic->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->btnPremium->BackColor = System::Drawing::Color::White;
	this->btnPremium->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;




	updateDriverStats(current);


	std::vector<Trip> historial = exportarHistoryTrips(*tripManager);


	std::vector<Trip> historialDriver;
	

	for (int i = 0; i < historial.size(); i++) {
		
		if (historial[i].getDriverDni() == msclr::interop::marshal_as<std::string>(dnii)) {
			historialDriver.push_back(historial[i]);
		}
	}
	if (!historialDriver.empty()) {
		int ultimoIdx = historialDriver.size() - 1;

		String^ ori = gcnew System::String((historialDriver[0].getOrigin()).c_str());
		String^ desti = gcnew System::String((historialDriver[0].getDestination()).c_str());

		this->lastTripText->Text = System::String::Concat(gcnew array<System::String^>{ ori, L" -> ", desti, L" | ", formatCurrency(historialDriver[0].getPrice()), L" ", tripTypeText(historialDriver[0].getTipe()) });

		switch (historialDriver[0].getTipe()) {
		case 1: this->lastTripDot->BackColor = System::Drawing::Color::LightGreen; break;
		case 2: this->lastTripDot->BackColor = System::Drawing::Color::LightSteelBlue; break;
		case 3: this->lastTripDot->BackColor = System::Drawing::Color::Goldenrod; break;
		}

		this->lblOtoD->Text = System::String::Concat(ori, L" --- ", desti);
		this->lblprice->Text = formatCurrency(historialDriver[0].getPrice());

		switch (historialDriver[0].getTipe()) {
		case 1: 
			this->lbltipes->BackColor = System::Drawing::Color::LightGreen;
			this->lbltipes->Text = "ECONOMICO";
			break;
		case 2:
			this->lbltipes->BackColor = System::Drawing::Color::LightSteelBlue;
			this->lbltipes->Text = "STANDARD";
			break;
		case 3:
			this->lbltipes->BackColor = System::Drawing::Color::Goldenrod;
			this->lbltipes->Text = "PREMIUM";
			break;
		}
	}
	else {
		// En caso de que el historial por alguna razón se quede vacío, limpias las etiquetas
		this->lastTripText->Text = "No hay viajes registrados";
		this->lblOtoD->Text = "-";
		this->lblprice->Text = "S/ 0.00";
		this->lbltipes->Text = "NINGUNO";
	}
}
private: System::Void btnRegister_Leave(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnRegister_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void btnRegister_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void btnRegister_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
}
	   int index = 0;
private: System::Void btnLeft_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<Trip> historial = exportarHistoryTrips(*tripManager);
	std::vector<Trip> historialDriver;
	String^ dnii = loggedDriverDni;

	for (int i = 0; i < historial.size(); i++) {
		// Solo mostramos en el historial los viajes que le pertenecen al DNI del pasajero logueado
		if (historial[i].getDriverDni() == msclr::interop::marshal_as<std::string>(dnii)) {
			historialDriver.push_back(historial[i]);
		}
	}
	if (index > 0) {
		index--;
	}
	if (historialDriver.empty()) {
		showNoTrips();
		return;
	}
	String^ ori = gcnew System::String((historialDriver[index].getOrigin()).c_str());
	String^ desti = gcnew System::String((historialDriver[index].getDestination()).c_str());
	this->lblOtoD->Text = System::String::Concat(ori, L" --- ", desti);
	this->lblprice->Text = formatCurrency(historialDriver[index].getPrice());

	switch (historialDriver[index].getTipe()) {
	case 1:
		this->lbltipes->BackColor = System::Drawing::Color::LightGreen;
		this->lbltipes->Text = "ECONOMICO";
		break;
	case 2:
		this->lbltipes->BackColor = System::Drawing::Color::LightSteelBlue;
		this->lbltipes->Text = "STANDARD";
		break;
	case 3:
		this->lbltipes->BackColor = System::Drawing::Color::Goldenrod;
		this->lbltipes->Text = "PREMIUM";
		break;
	}

}
private: System::Void btnRight_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<Trip> historial = exportarHistoryTrips(*tripManager);
	std::vector<Trip> historialDriver;
	String^ dnii = loggedDriverDni;

	for (int i = 0; i < historial.size(); i++) {
		// Solo mostramos en el historial los viajes que le pertenecen al DNI del pasajero logueado
		if (historial[i].getDriverDni() == msclr::interop::marshal_as<std::string>(dnii)) {
			historialDriver.push_back(historial[i]);
		}
	}
	if (historialDriver.empty()) {
		showNoTrips();
		return;
	}
	if (index < historialDriver.size() - 1) {
		index++;
	}
	String^ ori = gcnew System::String((historialDriver[index].getOrigin()).c_str());
	String^ desti = gcnew System::String((historialDriver[index].getDestination()).c_str());
	this->lblOtoD->Text = System::String::Concat(ori, L" --- ", desti);
	this->lblprice->Text = formatCurrency(historialDriver[index].getPrice());

	switch (historialDriver[index].getTipe()) {
	case 1:
		this->lbltipes->BackColor = System::Drawing::Color::LightGreen;
		this->lbltipes->Text = "ECONOMICO";
		break;
	case 2:
		this->lbltipes->BackColor = System::Drawing::Color::LightSteelBlue;
		this->lbltipes->Text = "STANDARD";
		break;
	case 3:
		this->lbltipes->BackColor = System::Drawing::Color::Goldenrod;
		this->lbltipes->Text = "PREMIUM";
		break;
	}
}
private: System::Void btnUpdateVehicle_Click(System::Object^ sender, System::EventArgs^ e) {
	

}
};
}
