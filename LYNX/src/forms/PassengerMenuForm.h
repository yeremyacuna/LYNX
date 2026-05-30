#pragma once
#include "../library/FormsStatus.h"	

class AuthManager;
class TripManager;

namespace LYNX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class PassengerMenuForm : public System::Windows::Forms::Form
	{
	public:
		PassengerMenuForm(void)
		{
			InitializeComponent();
			ConfigureForm();
		}

		PassengerMenuForm(AuthManager* auth, TripManager* trips, String^ passengerDni)
		{
			this->authManager = auth;
			this->tripManager = trips;
			this->loggedPassengerDni = passengerDni;
			InitializeComponent();
			ConfigureForm();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PassengerMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ historyListView;
	protected:
	private: System::Windows::Forms::Label^ queueTitle;
	private: System::Windows::Forms::Panel^ vehiclePanel;
	private: System::Windows::Forms::Button^ updateVehicleButton;
	private: System::Windows::Forms::Panel^ maintenancePanel;
	private: System::Windows::Forms::Label^ maintenanceText;
	private: System::Windows::Forms::Label^ maintenanceTitle;













	private: System::Windows::Forms::Panel^ historyPanel;

	private: System::Windows::Forms::Panel^ manualPanel;
	private: System::Windows::Forms::Panel^ topPanel;
	private: System::Windows::Forms::Button^ earningsButton;
	private: System::Windows::Forms::Button^ statusButton;
	private: System::Windows::Forms::Label^ onlineChip;
	private: System::Windows::Forms::Label^ topText;
	private: System::Windows::Forms::Label^ topTitle;
	private: System::Windows::Forms::Panel^ profilePanel;
	private: System::Windows::Forms::Panel^ queuePanel;
	private: System::Windows::Forms::Button^ finishButton;
	private: System::Windows::Forms::Button^ acceptButton;
	private: System::Windows::Forms::Panel^ queueItem3;
	private: System::Windows::Forms::Label^ q3Text;
	private: System::Windows::Forms::Label^ q3Title;
	private: System::Windows::Forms::Panel^ q3Dot;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblMarco1;
	private: System::Windows::Forms::Label^ lblMarco2;
	private: System::Windows::Forms::Panel^ pnlTopBar;
	private: System::Windows::Forms::PictureBox^ pictureBoxIcon;
	private: System::Windows::Forms::Label^ lblLYNX;

	private:
		AuthManager* authManager = nullptr;
		TripManager* tripManager = nullptr;
		String^ loggedPassengerDni = "";

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->historyListView = (gcnew System::Windows::Forms::ListView());
			this->queueTitle = (gcnew System::Windows::Forms::Label());
			this->vehiclePanel = (gcnew System::Windows::Forms::Panel());
			this->updateVehicleButton = (gcnew System::Windows::Forms::Button());
			this->maintenancePanel = (gcnew System::Windows::Forms::Panel());
			this->maintenanceText = (gcnew System::Windows::Forms::Label());
			this->maintenanceTitle = (gcnew System::Windows::Forms::Label());
			this->historyPanel = (gcnew System::Windows::Forms::Panel());
			this->manualPanel = (gcnew System::Windows::Forms::Panel());
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->earningsButton = (gcnew System::Windows::Forms::Button());
			this->statusButton = (gcnew System::Windows::Forms::Button());
			this->onlineChip = (gcnew System::Windows::Forms::Label());
			this->topText = (gcnew System::Windows::Forms::Label());
			this->topTitle = (gcnew System::Windows::Forms::Label());
			this->profilePanel = (gcnew System::Windows::Forms::Panel());
			this->queuePanel = (gcnew System::Windows::Forms::Panel());
			this->finishButton = (gcnew System::Windows::Forms::Button());
			this->acceptButton = (gcnew System::Windows::Forms::Button());
			this->queueItem3 = (gcnew System::Windows::Forms::Panel());
			this->q3Text = (gcnew System::Windows::Forms::Label());
			this->q3Title = (gcnew System::Windows::Forms::Label());
			this->q3Dot = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblMarco1 = (gcnew System::Windows::Forms::Label());
			this->lblMarco2 = (gcnew System::Windows::Forms::Label());
			this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
			this->lblLYNX = (gcnew System::Windows::Forms::Label());
			this->vehiclePanel->SuspendLayout();
			this->maintenancePanel->SuspendLayout();
			this->historyPanel->SuspendLayout();
			this->topPanel->SuspendLayout();
			this->queuePanel->SuspendLayout();
			this->queueItem3->SuspendLayout();
			this->pnlTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->SuspendLayout();
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
			this->vehiclePanel->Location = System::Drawing::Point(1098, 213);
			this->vehiclePanel->Name = L"vehiclePanel";
			this->vehiclePanel->Size = System::Drawing::Size(372, 342);
			this->vehiclePanel->TabIndex = 9;
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
			// historyPanel
			// 
			this->historyPanel->BackColor = System::Drawing::Color::White;
			this->historyPanel->Controls->Add(this->historyListView);
			this->historyPanel->Location = System::Drawing::Point(808, 587);
			this->historyPanel->Name = L"historyPanel";
			this->historyPanel->Size = System::Drawing::Size(662, 264);
			this->historyPanel->TabIndex = 11;
			// 
			// manualPanel
			// 
			this->manualPanel->BackColor = System::Drawing::Color::White;
			this->manualPanel->Location = System::Drawing::Point(48, 587);
			this->manualPanel->Name = L"manualPanel";
			this->manualPanel->Size = System::Drawing::Size(728, 264);
			this->manualPanel->TabIndex = 10;
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
			this->topPanel->Location = System::Drawing::Point(24, 55);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(1422, 164);
			this->topPanel->TabIndex = 6;
			// 
			// earningsButton
			// 
			this->earningsButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(39)));
			this->earningsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->earningsButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->earningsButton->ForeColor = System::Drawing::Color::White;
			this->earningsButton->Location = System::Drawing::Point(1190, 102);
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
			this->statusButton->Location = System::Drawing::Point(1000, 102);
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
			this->onlineChip->Text = L"Online preview";
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
			this->topText->Text = L"Disponibilidad, ganancias, viajes activos y vehiculo en una sola cabina visual.";
			// 
			// topTitle
			// 
			this->topTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->topTitle->ForeColor = System::Drawing::Color::White;
			this->topTitle->Location = System::Drawing::Point(28, 28);
			this->topTitle->Name = L"topTitle";
			this->topTitle->Size = System::Drawing::Size(360, 38);
			this->topTitle->TabIndex = 0;
			this->topTitle->Text = L"Pasajerito";
			// 
			// profilePanel
			// 
			this->profilePanel->BackColor = System::Drawing::Color::White;
			this->profilePanel->Location = System::Drawing::Point(48, 213);
			this->profilePanel->Name = L"profilePanel";
			this->profilePanel->Size = System::Drawing::Size(426, 342);
			this->profilePanel->TabIndex = 7;
			// 
			// queuePanel
			// 
			this->queuePanel->BackColor = System::Drawing::Color::White;
			this->queuePanel->Controls->Add(this->finishButton);
			this->queuePanel->Controls->Add(this->acceptButton);
			this->queuePanel->Controls->Add(this->queueItem3);
			this->queuePanel->Controls->Add(this->queueTitle);
			this->queuePanel->Location = System::Drawing::Point(506, 213);
			this->queuePanel->Name = L"queuePanel";
			this->queuePanel->Size = System::Drawing::Size(560, 342);
			this->queuePanel->TabIndex = 8;
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
			// pnlTopBar
			// 
			this->pnlTopBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlTopBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->pnlTopBar->Controls->Add(this->pictureBoxIcon);
			this->pnlTopBar->Controls->Add(this->lblLYNX);
			this->pnlTopBar->Location = System::Drawing::Point(0, -2);
			this->pnlTopBar->Name = L"pnlTopBar";
			this->pnlTopBar->Size = System::Drawing::Size(1480, 78);
			this->pnlTopBar->TabIndex = 12;
			// 
			// pictureBoxIcon
			// 
			this->pictureBoxIcon->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxIcon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBoxIcon->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBoxIcon->Location = System::Drawing::Point(20, -27);
			this->pictureBoxIcon->Name = L"pictureBoxIcon";
			this->pictureBoxIcon->Size = System::Drawing::Size(75, 129);
			this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBoxIcon->TabIndex = 3;
			this->pictureBoxIcon->TabStop = false;
			this->pictureBoxIcon->Click += gcnew System::EventHandler(this, &PassengerMenuForm::pictureBoxIcon_Click);
			// 
			// lblLYNX
			// 
			this->lblLYNX->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 22, System::Drawing::FontStyle::Bold));
			this->lblLYNX->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblLYNX->Location = System::Drawing::Point(89, 18);
			this->lblLYNX->Name = L"lblLYNX";
			this->lblLYNX->Size = System::Drawing::Size(84, 40);
			this->lblLYNX->TabIndex = 0;
			this->lblLYNX->Text = L"LYNX";
			// 
			// PassengerMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1480, 920);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblMarco1);
			this->Controls->Add(this->lblMarco2);
			this->Controls->Add(this->pnlTopBar);
			this->Controls->Add(this->vehiclePanel);
			this->Controls->Add(this->historyPanel);
			this->Controls->Add(this->manualPanel);
			this->Controls->Add(this->topPanel);
			this->Controls->Add(this->profilePanel);
			this->Controls->Add(this->queuePanel);
			this->Name = L"PassengerMenuForm";
			this->Text = L"PassengerMenuForm";
			this->Load += gcnew System::EventHandler(this, &PassengerMenuForm::PassengerMenuForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PassengerMenuForm::PassengerMenuForm_KeyDown);
			this->vehiclePanel->ResumeLayout(false);
			this->maintenancePanel->ResumeLayout(false);
			this->historyPanel->ResumeLayout(false);
			this->topPanel->ResumeLayout(false);
			this->queuePanel->ResumeLayout(false);
			this->queueItem3->ResumeLayout(false);
			this->pnlTopBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void q3Title_Click(System::Object^ sender, System::EventArgs^ e) {	}
		void ConfigureForm()
		{
			// CENTRAR TODO
			this->CenterToScreen();

			// ACTIVAR F11
			this->KeyPreview = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;

			// icon
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
		// Full screen function
		//
		System::Drawing::Size normalSize;
		System::Drawing::Point normalLocation;
		System::Windows::Forms::FormWindowState normalState;

		System::Void PassengerMenuForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
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

private: System::Void PassengerMenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
	normalSize = this->Size;
	normalLocation = this->Location;
	normalState = this->WindowState;
	FormsStatus::SaveWindow(this);

	// Para Picture Box LYNX
	this->pictureBoxIcon->Image = System::Drawing::Image::FromFile("resources/LYNX_image.png");
	this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;

	if (FormsStatus::isFullscreen)
	{
		FormsStatus::ApplyWindow(this);
	}
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
};
}
