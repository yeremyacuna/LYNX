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
		~PassengerMenuForm()
		{
			if (components) delete components;
		}

		// OBJETOS
	private:
		AuthManager* authManager = nullptr;
		TripManager* tripManager = nullptr;
		String^ loggedPassengerDni = "";

		// COMPONENTES
	private: System::Windows::Forms::Label^ ActualTripTitle;
	private: System::Windows::Forms::Panel^ vehiclePanel;
	private: System::Windows::Forms::Panel^ manualPanel;
	private: System::Windows::Forms::Panel^ topPanel;
	private: System::Windows::Forms::Button^ statusButton;
	private: System::Windows::Forms::Label^ onlineChip;
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
	private: System::Windows::Forms::Label^ RequestTripTitle;
	private: System::Windows::Forms::Label^ ProfileTitle;
	private: System::Windows::Forms::Label^ HistoryTitle;
	private: System::Windows::Forms::TextBox^ tbDestination;
	private: System::Windows::Forms::TextBox^ tbOrigin;
	private: System::Windows::Forms::TextBox^ tbDistance;
	private: System::Windows::Forms::Label^ lblDestination;
	private: System::Windows::Forms::Label^ lblOrigin;
	private: System::Windows::Forms::Button^ btnPremium;
	private: System::Windows::Forms::Button^ btnStandard;
	private: System::Windows::Forms::Button^ btnEconomic;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::Label^ lblTripType;
	private: System::Windows::Forms::Label^ lblDistance;
	private: System::Windows::Forms::Label^ lblTrips;
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Label^ lblNumSpent;
	private: System::Windows::Forms::Label^ lblNumTrips;
	private: System::Windows::Forms::Label^ lblSpent;
	private: System::Windows::Forms::Label^ lblID;
	private: System::Windows::Forms::Label^ lblRating;

	private: System::Windows::Forms::Label^ lblDni;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ lblUpdateProfile;
	private: System::Windows::Forms::TextBox^ tbNewPassword;
	private: System::Windows::Forms::TextBox^ tbNewName;
	private: System::Windows::Forms::TextBox^ tbPastPassword;
	private: System::Windows::Forms::Label^ lblPastPassword;
	private: System::Windows::Forms::Label^ lblNewPassword;
	private: System::Windows::Forms::Label^ lblNewName;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::ComponentModel::Container^ components;

		   // WINDOWS INITIALIZE
	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->ActualTripTitle = (gcnew System::Windows::Forms::Label());
			this->vehiclePanel = (gcnew System::Windows::Forms::Panel());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->tbPastPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblPastPassword = (gcnew System::Windows::Forms::Label());
			this->lblNewPassword = (gcnew System::Windows::Forms::Label());
			this->lblNewName = (gcnew System::Windows::Forms::Label());
			this->tbNewPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbNewName = (gcnew System::Windows::Forms::TextBox());
			this->lblUpdateProfile = (gcnew System::Windows::Forms::Label());
			this->lblRating = (gcnew System::Windows::Forms::Label());
			this->lblDni = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lblNumSpent = (gcnew System::Windows::Forms::Label());
			this->lblNumTrips = (gcnew System::Windows::Forms::Label());
			this->lblSpent = (gcnew System::Windows::Forms::Label());
			this->lblID = (gcnew System::Windows::Forms::Label());
			this->lblTrips = (gcnew System::Windows::Forms::Label());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->ProfileTitle = (gcnew System::Windows::Forms::Label());
			this->manualPanel = (gcnew System::Windows::Forms::Panel());
			this->HistoryTitle = (gcnew System::Windows::Forms::Label());
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->statusButton = (gcnew System::Windows::Forms::Button());
			this->onlineChip = (gcnew System::Windows::Forms::Label());
			this->topTitle = (gcnew System::Windows::Forms::Label());
			this->profilePanel = (gcnew System::Windows::Forms::Panel());
			this->lblTripType = (gcnew System::Windows::Forms::Label());
			this->lblDistance = (gcnew System::Windows::Forms::Label());
			this->btnPremium = (gcnew System::Windows::Forms::Button());
			this->btnStandard = (gcnew System::Windows::Forms::Button());
			this->btnEconomic = (gcnew System::Windows::Forms::Button());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->tbDistance = (gcnew System::Windows::Forms::TextBox());
			this->lblDestination = (gcnew System::Windows::Forms::Label());
			this->lblOrigin = (gcnew System::Windows::Forms::Label());
			this->tbDestination = (gcnew System::Windows::Forms::TextBox());
			this->tbOrigin = (gcnew System::Windows::Forms::TextBox());
			this->RequestTripTitle = (gcnew System::Windows::Forms::Label());
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
			this->manualPanel->SuspendLayout();
			this->topPanel->SuspendLayout();
			this->profilePanel->SuspendLayout();
			this->queuePanel->SuspendLayout();
			this->queueItem3->SuspendLayout();
			this->pnlTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->SuspendLayout();
			// 
			// ActualTripTitle
			// 
			this->ActualTripTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->ActualTripTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->ActualTripTitle->Location = System::Drawing::Point(9, 8);
			this->ActualTripTitle->Name = L"ActualTripTitle";
			this->ActualTripTitle->Size = System::Drawing::Size(220, 28);
			this->ActualTripTitle->TabIndex = 0;
			this->ActualTripTitle->Text = L"Viaje Actual";
			// 
			// vehiclePanel
			// 
			this->vehiclePanel->BackColor = System::Drawing::Color::White;
			this->vehiclePanel->Controls->Add(this->btnConfirm);
			this->vehiclePanel->Controls->Add(this->tbPastPassword);
			this->vehiclePanel->Controls->Add(this->lblPastPassword);
			this->vehiclePanel->Controls->Add(this->lblNewPassword);
			this->vehiclePanel->Controls->Add(this->lblNewName);
			this->vehiclePanel->Controls->Add(this->tbNewPassword);
			this->vehiclePanel->Controls->Add(this->tbNewName);
			this->vehiclePanel->Controls->Add(this->lblUpdateProfile);
			this->vehiclePanel->Controls->Add(this->lblRating);
			this->vehiclePanel->Controls->Add(this->lblDni);
			this->vehiclePanel->Controls->Add(this->label8);
			this->vehiclePanel->Controls->Add(this->lblNumSpent);
			this->vehiclePanel->Controls->Add(this->lblNumTrips);
			this->vehiclePanel->Controls->Add(this->lblSpent);
			this->vehiclePanel->Controls->Add(this->lblID);
			this->vehiclePanel->Controls->Add(this->lblTrips);
			this->vehiclePanel->Controls->Add(this->lblName);
			this->vehiclePanel->Controls->Add(this->btnUpdate);
			this->vehiclePanel->Controls->Add(this->ProfileTitle);
			this->vehiclePanel->Location = System::Drawing::Point(1074, 213);
			this->vehiclePanel->Name = L"vehiclePanel";
			this->vehiclePanel->Size = System::Drawing::Size(377, 342);
			this->vehiclePanel->TabIndex = 9;
			// 
			// btnConfirm
			// 
			this->btnConfirm->BackColor = System::Drawing::Color::Black;
			this->btnConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnConfirm->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->btnConfirm->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnConfirm->Location = System::Drawing::Point(111, 275);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(154, 44);
			this->btnConfirm->TabIndex = 27;
			this->btnConfirm->Text = L"Confirmar";
			this->btnConfirm->UseVisualStyleBackColor = false;
			this->btnConfirm->Visible = false;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &PassengerMenuForm::btnConfirm_Click);
			// 
			// tbPastPassword
			// 
			this->tbPastPassword->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbPastPassword->Location = System::Drawing::Point(14, 183);
			this->tbPastPassword->Name = L"tbPastPassword";
			this->tbPastPassword->PasswordChar = '*';
			this->tbPastPassword->Size = System::Drawing::Size(345, 27);
			this->tbPastPassword->TabIndex = 38;
			this->tbPastPassword->Visible = false;
			// 
			// lblPastPassword
			// 
			this->lblPastPassword->AutoSize = true;
			this->lblPastPassword->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblPastPassword->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblPastPassword->Location = System::Drawing::Point(12, 162);
			this->lblPastPassword->Name = L"lblPastPassword";
			this->lblPastPassword->Size = System::Drawing::Size(126, 17);
			this->lblPastPassword->TabIndex = 37;
			this->lblPastPassword->Text = L"Contrasena Previa";
			this->lblPastPassword->Visible = false;
			// 
			// lblNewPassword
			// 
			this->lblNewPassword->AutoSize = true;
			this->lblNewPassword->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblNewPassword->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblNewPassword->Location = System::Drawing::Point(13, 102);
			this->lblNewPassword->Name = L"lblNewPassword";
			this->lblNewPassword->Size = System::Drawing::Size(125, 17);
			this->lblNewPassword->TabIndex = 27;
			this->lblNewPassword->Text = L"Nueva Contrasena";
			this->lblNewPassword->Visible = false;
			// 
			// lblNewName
			// 
			this->lblNewName->AutoSize = true;
			this->lblNewName->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblNewName->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblNewName->Location = System::Drawing::Point(12, 45);
			this->lblNewName->Name = L"lblNewName";
			this->lblNewName->Size = System::Drawing::Size(105, 17);
			this->lblNewName->TabIndex = 27;
			this->lblNewName->Text = L"Nuevo Nombre";
			this->lblNewName->Visible = false;
			// 
			// tbNewPassword
			// 
			this->tbNewPassword->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbNewPassword->Location = System::Drawing::Point(14, 124);
			this->tbNewPassword->Name = L"tbNewPassword";
			this->tbNewPassword->PasswordChar = '*';
			this->tbNewPassword->Size = System::Drawing::Size(345, 27);
			this->tbNewPassword->TabIndex = 36;
			this->tbNewPassword->Visible = false;
			// 
			// tbNewName
			// 
			this->tbNewName->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbNewName->Location = System::Drawing::Point(14, 65);
			this->tbNewName->Name = L"tbNewName";
			this->tbNewName->Size = System::Drawing::Size(345, 27);
			this->tbNewName->TabIndex = 27;
			this->tbNewName->Visible = false;
			// 
			// lblUpdateProfile
			// 
			this->lblUpdateProfile->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->lblUpdateProfile->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->lblUpdateProfile->Location = System::Drawing::Point(13, 4);
			this->lblUpdateProfile->Name = L"lblUpdateProfile";
			this->lblUpdateProfile->Size = System::Drawing::Size(220, 28);
			this->lblUpdateProfile->TabIndex = 27;
			this->lblUpdateProfile->Text = L"Actualizar Perfil";
			this->lblUpdateProfile->Visible = false;
			// 
			// lblRating
			// 
			this->lblRating->AutoSize = true;
			this->lblRating->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblRating->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblRating->Location = System::Drawing::Point(309, 4);
			this->lblRating->Name = L"lblRating";
			this->lblRating->Size = System::Drawing::Size(50, 33);
			this->lblRating->TabIndex = 35;
			this->lblRating->Text = L"5.0";
			// 
			// lblDni
			// 
			this->lblDni->AutoSize = true;
			this->lblDni->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13, System::Drawing::FontStyle::Bold));
			this->lblDni->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->lblDni->Location = System::Drawing::Point(11, 83);
			this->lblDni->Name = L"lblDni";
			this->lblDni->Size = System::Drawing::Size(40, 22);
			this->lblDni->TabIndex = 34;
			this->lblDni->Text = L"DNI";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->label8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(12, 88);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 33);
			this->label8->TabIndex = 33;
			// 
			// lblNumSpent
			// 
			this->lblNumSpent->AutoSize = true;
			this->lblNumSpent->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblNumSpent->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblNumSpent->Location = System::Drawing::Point(245, 183);
			this->lblNumSpent->Name = L"lblNumSpent";
			this->lblNumSpent->Size = System::Drawing::Size(62, 33);
			this->lblNumSpent->TabIndex = 32;
			this->lblNumSpent->Text = L"S/.0";
			// 
			// lblNumTrips
			// 
			this->lblNumTrips->AutoSize = true;
			this->lblNumTrips->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblNumTrips->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblNumTrips->Location = System::Drawing::Point(77, 183);
			this->lblNumTrips->Name = L"lblNumTrips";
			this->lblNumTrips->Size = System::Drawing::Size(30, 33);
			this->lblNumTrips->TabIndex = 31;
			this->lblNumTrips->Text = L"0";
			// 
			// lblSpent
			// 
			this->lblSpent->AutoSize = true;
			this->lblSpent->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblSpent->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblSpent->Location = System::Drawing::Point(219, 150);
			this->lblSpent->Name = L"lblSpent";
			this->lblSpent->Size = System::Drawing::Size(113, 33);
			this->lblSpent->TabIndex = 30;
			this->lblSpent->Text = L"Gastado";
			// 
			// lblID
			// 
			this->lblID->AutoSize = true;
			this->lblID->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblID->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->lblID->Location = System::Drawing::Point(12, 45);
			this->lblID->Name = L"lblID";
			this->lblID->Size = System::Drawing::Size(21, 17);
			this->lblID->TabIndex = 29;
			this->lblID->Text = L"ID";
			// 
			// lblTrips
			// 
			this->lblTrips->AutoSize = true;
			this->lblTrips->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblTrips->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblTrips->Location = System::Drawing::Point(47, 150);
			this->lblTrips->Name = L"lblTrips";
			this->lblTrips->Size = System::Drawing::Size(87, 33);
			this->lblTrips->TabIndex = 28;
			this->lblTrips->Text = L"Viajes";
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->lblName->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblName->Location = System::Drawing::Point(8, 55);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(113, 33);
			this->lblName->TabIndex = 27;
			this->lblName->Text = L"Nombre";
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::Black;
			this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->btnUpdate->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnUpdate->Location = System::Drawing::Point(111, 275);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(154, 44);
			this->btnUpdate->TabIndex = 27;
			this->btnUpdate->Text = L"Actualizar";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &PassengerMenuForm::btnUpdate_Click);
			this->btnUpdate->MouseEnter += gcnew System::EventHandler(this, &PassengerMenuForm::btnUpdate_MouseEnter);
			this->btnUpdate->MouseLeave += gcnew System::EventHandler(this, &PassengerMenuForm::btnUpdate_MouseLeave);
			// 
			// ProfileTitle
			// 
			this->ProfileTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->ProfileTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->ProfileTitle->Location = System::Drawing::Point(9, 7);
			this->ProfileTitle->Name = L"ProfileTitle";
			this->ProfileTitle->Size = System::Drawing::Size(220, 28);
			this->ProfileTitle->TabIndex = 6;
			this->ProfileTitle->Text = L"Perfil";
			// 
			// manualPanel
			// 
			this->manualPanel->BackColor = System::Drawing::Color::White;
			this->manualPanel->Controls->Add(this->HistoryTitle);
			this->manualPanel->Location = System::Drawing::Point(33, 580);
			this->manualPanel->Name = L"manualPanel";
			this->manualPanel->Size = System::Drawing::Size(1418, 301);
			this->manualPanel->TabIndex = 10;
			// 
			// HistoryTitle
			// 
			this->HistoryTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->HistoryTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->HistoryTitle->Location = System::Drawing::Point(10, 12);
			this->HistoryTitle->Name = L"HistoryTitle";
			this->HistoryTitle->Size = System::Drawing::Size(220, 28);
			this->HistoryTitle->TabIndex = 17;
			this->HistoryTitle->Text = L"Historial de Viajes";
			// 
			// topPanel
			// 
			this->topPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(39)));
			this->topPanel->Controls->Add(this->statusButton);
			this->topPanel->Controls->Add(this->onlineChip);
			this->topPanel->Controls->Add(this->topTitle);
			this->topPanel->Location = System::Drawing::Point(24, 108);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(1422, 103);
			this->topPanel->TabIndex = 6;
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
			this->onlineChip->Location = System::Drawing::Point(1187, 32);
			this->onlineChip->Name = L"onlineChip";
			this->onlineChip->Size = System::Drawing::Size(190, 34);
			this->onlineChip->TabIndex = 2;
			this->onlineChip->Text = L"Online";
			this->onlineChip->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// topTitle
			// 
			this->topTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 30, System::Drawing::FontStyle::Bold));
			this->topTitle->ForeColor = System::Drawing::Color::White;
			this->topTitle->Location = System::Drawing::Point(11, 25);
			this->topTitle->Name = L"topTitle";
			this->topTitle->Size = System::Drawing::Size(1145, 52);
			this->topTitle->TabIndex = 0;
			this->topTitle->Text = L"Bienvenido";
			// 
			// profilePanel
			// 
			this->profilePanel->BackColor = System::Drawing::Color::White;
			this->profilePanel->Controls->Add(this->lblTripType);
			this->profilePanel->Controls->Add(this->lblDistance);
			this->profilePanel->Controls->Add(this->btnPremium);
			this->profilePanel->Controls->Add(this->btnStandard);
			this->profilePanel->Controls->Add(this->btnEconomic);
			this->profilePanel->Controls->Add(this->btnSearch);
			this->profilePanel->Controls->Add(this->tbDistance);
			this->profilePanel->Controls->Add(this->lblDestination);
			this->profilePanel->Controls->Add(this->lblOrigin);
			this->profilePanel->Controls->Add(this->tbDestination);
			this->profilePanel->Controls->Add(this->tbOrigin);
			this->profilePanel->Controls->Add(this->RequestTripTitle);
			this->profilePanel->Location = System::Drawing::Point(33, 213);
			this->profilePanel->Name = L"profilePanel";
			this->profilePanel->Size = System::Drawing::Size(426, 342);
			this->profilePanel->TabIndex = 7;
			// 
			// lblTripType
			// 
			this->lblTripType->AutoSize = true;
			this->lblTripType->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblTripType->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblTripType->Location = System::Drawing::Point(153, 131);
			this->lblTripType->Name = L"lblTripType";
			this->lblTripType->Size = System::Drawing::Size(90, 17);
			this->lblTripType->TabIndex = 26;
			this->lblTripType->Text = L"Tipo de Viaje";
			// 
			// lblDistance
			// 
			this->lblDistance->AutoSize = true;
			this->lblDistance->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDistance->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblDistance->Location = System::Drawing::Point(18, 130);
			this->lblDistance->Name = L"lblDistance";
			this->lblDistance->Size = System::Drawing::Size(99, 17);
			this->lblDistance->TabIndex = 25;
			this->lblDistance->Text = L"Distancia (km)";
			// 
			// btnPremium
			// 
			this->btnPremium->BackColor = System::Drawing::Color::White;
			this->btnPremium->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnPremium->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
			this->btnPremium->Location = System::Drawing::Point(324, 150);
			this->btnPremium->Name = L"btnPremium";
			this->btnPremium->Size = System::Drawing::Size(75, 33);
			this->btnPremium->TabIndex = 24;
			this->btnPremium->Text = L"Premium";
			this->btnPremium->UseVisualStyleBackColor = false;
			this->btnPremium->Click += gcnew System::EventHandler(this, &PassengerMenuForm::btnPremium_Click);
			// 
			// btnStandard
			// 
			this->btnStandard->BackColor = System::Drawing::Color::White;
			this->btnStandard->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStandard->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
			this->btnStandard->Location = System::Drawing::Point(240, 150);
			this->btnStandard->Name = L"btnStandard";
			this->btnStandard->Size = System::Drawing::Size(75, 33);
			this->btnStandard->TabIndex = 23;
			this->btnStandard->Text = L"Standard";
			this->btnStandard->UseVisualStyleBackColor = false;
			this->btnStandard->Click += gcnew System::EventHandler(this, &PassengerMenuForm::btnStandard_Click);
			// 
			// btnEconomic
			// 
			this->btnEconomic->BackColor = System::Drawing::Color::White;
			this->btnEconomic->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnEconomic->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
			this->btnEconomic->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnEconomic->Location = System::Drawing::Point(155, 150);
			this->btnEconomic->Name = L"btnEconomic";
			this->btnEconomic->Size = System::Drawing::Size(75, 33);
			this->btnEconomic->TabIndex = 22;
			this->btnEconomic->Text = L"Economico";
			this->btnEconomic->UseVisualStyleBackColor = false;
			this->btnEconomic->Click += gcnew System::EventHandler(this, &PassengerMenuForm::btnEconomic_Click);
			// 
			// btnSearch
			// 
			this->btnSearch->BackColor = System::Drawing::Color::Black;
			this->btnSearch->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSearch->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->btnSearch->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSearch->Location = System::Drawing::Point(138, 264);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(154, 44);
			this->btnSearch->TabIndex = 21;
			this->btnSearch->Text = L"Buscar";
			this->btnSearch->UseVisualStyleBackColor = false;
			this->btnSearch->Click += gcnew System::EventHandler(this, &PassengerMenuForm::btnSearch_Click);
			this->btnSearch->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PassengerMenuForm::btnSearch_MouseDown);
			this->btnSearch->MouseLeave += gcnew System::EventHandler(this, &PassengerMenuForm::btnSearch_MouseLeave);
			this->btnSearch->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PassengerMenuForm::btnSearch_MouseMove);
			// 
			// tbDistance
			// 
			this->tbDistance->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbDistance->Location = System::Drawing::Point(18, 150);
			this->tbDistance->Name = L"tbDistance";
			this->tbDistance->Size = System::Drawing::Size(97, 27);
			this->tbDistance->TabIndex = 20;
			// 
			// lblDestination
			// 
			this->lblDestination->AutoSize = true;
			this->lblDestination->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblDestination->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblDestination->Location = System::Drawing::Point(223, 55);
			this->lblDestination->Name = L"lblDestination";
			this->lblDestination->Size = System::Drawing::Size(57, 17);
			this->lblDestination->TabIndex = 19;
			this->lblDestination->Text = L"Destino";
			// 
			// lblOrigin
			// 
			this->lblOrigin->AutoSize = true;
			this->lblOrigin->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
			this->lblOrigin->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblOrigin->Location = System::Drawing::Point(15, 55);
			this->lblOrigin->Name = L"lblOrigin";
			this->lblOrigin->Size = System::Drawing::Size(51, 17);
			this->lblOrigin->TabIndex = 17;
			this->lblOrigin->Text = L"Origen";
			// 
			// tbDestination
			// 
			this->tbDestination->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbDestination->Location = System::Drawing::Point(226, 75);
			this->tbDestination->Name = L"tbDestination";
			this->tbDestination->Size = System::Drawing::Size(185, 27);
			this->tbDestination->TabIndex = 18;
			// 
			// tbOrigin
			// 
			this->tbOrigin->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->tbOrigin->Location = System::Drawing::Point(15, 75);
			this->tbOrigin->Name = L"tbOrigin";
			this->tbOrigin->Size = System::Drawing::Size(182, 27);
			this->tbOrigin->TabIndex = 17;
			// 
			// RequestTripTitle
			// 
			this->RequestTripTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->RequestTripTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->RequestTripTitle->Location = System::Drawing::Point(8, 7);
			this->RequestTripTitle->Name = L"RequestTripTitle";
			this->RequestTripTitle->Size = System::Drawing::Size(220, 28);
			this->RequestTripTitle->TabIndex = 6;
			this->RequestTripTitle->Text = L"Solicitar Viaje";
			// 
			// queuePanel
			// 
			this->queuePanel->BackColor = System::Drawing::Color::White;
			this->queuePanel->Controls->Add(this->finishButton);
			this->queuePanel->Controls->Add(this->acceptButton);
			this->queuePanel->Controls->Add(this->queueItem3);
			this->queuePanel->Controls->Add(this->ActualTripTitle);
			this->queuePanel->Location = System::Drawing::Point(483, 213);
			this->queuePanel->Name = L"queuePanel";
			this->queuePanel->Size = System::Drawing::Size(560, 342);
			this->queuePanel->TabIndex = 8;
			this->queuePanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PassengerMenuForm::queuePanel_Paint);
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
			this->label4->Location = System::Drawing::Point(21, 884);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(1443, 34);
			this->label4->TabIndex = 16;
			this->label4->Visible = false;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(21, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1443, 14);
			this->label1->TabIndex = 15;
			this->label1->Visible = false;
			// 
			// lblMarco1
			// 
			this->lblMarco1->BackColor = System::Drawing::Color::Red;
			this->lblMarco1->Location = System::Drawing::Point(-1, 72);
			this->lblMarco1->Name = L"lblMarco1";
			this->lblMarco1->Size = System::Drawing::Size(28, 850);
			this->lblMarco1->TabIndex = 14;
			this->lblMarco1->Visible = false;
			// 
			// lblMarco2
			// 
			this->lblMarco2->BackColor = System::Drawing::Color::Red;
			this->lblMarco2->Location = System::Drawing::Point(1454, 72);
			this->lblMarco2->Name = L"lblMarco2";
			this->lblMarco2->Size = System::Drawing::Size(28, 850);
			this->lblMarco2->TabIndex = 13;
			this->lblMarco2->Visible = false;
			// 
			// pnlTopBar
			// 
			this->pnlTopBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->pnlTopBar->Controls->Add(this->pictureBoxIcon);
			this->pnlTopBar->Controls->Add(this->lblLYNX);
			this->pnlTopBar->Location = System::Drawing::Point(0, 0);
			this->pnlTopBar->Name = L"pnlTopBar";
			this->pnlTopBar->Size = System::Drawing::Size(1517, 78);
			this->pnlTopBar->TabIndex = 12;
			// 
			// pictureBoxIcon
			// 
			this->pictureBoxIcon->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxIcon->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBoxIcon->Location = System::Drawing::Point(22, -27);
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
			this->lblLYNX->Location = System::Drawing::Point(91, 18);
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
			this->Controls->Add(this->manualPanel);
			this->Controls->Add(this->topPanel);
			this->Controls->Add(this->profilePanel);
			this->Controls->Add(this->queuePanel);
			this->Name = L"PassengerMenuForm";
			this->Text = L"LYNX | Pasajero";
			this->Activated += gcnew System::EventHandler(this, &PassengerMenuForm::PassengerMenuForm_Activated);
			this->Load += gcnew System::EventHandler(this, &PassengerMenuForm::PassengerMenuForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PassengerMenuForm::PassengerMenuForm_KeyDown);
			this->vehiclePanel->ResumeLayout(false);
			this->vehiclePanel->PerformLayout();
			this->manualPanel->ResumeLayout(false);
			this->topPanel->ResumeLayout(false);
			this->profilePanel->ResumeLayout(false);
			this->profilePanel->PerformLayout();
			this->queuePanel->ResumeLayout(false);
			this->queueItem3->ResumeLayout(false);
			this->pnlTopBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// DATOS PUBLICOS DEL PASAJERO LOGUEADO
	public:
		String^ dni = "";
		String^ name = "";
		String^ password = "";

		// ESTADO INTERNO
	private:
		System::Drawing::Size normalSize;
		System::Drawing::Point normalLocation;
		System::Windows::Forms::FormWindowState normalState;

		//
		// Configuracion global del form
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
		// Helpers internos
		//
		// Carga los datos del pasajero desde authManager usando el DNI logueado
		void LoadPassengerData()
		{
			if (authManager == nullptr || String::IsNullOrEmpty(loggedPassengerDni)) 
				return;

			String^ passengerDni = loggedPassengerDni;
			std::string dniStr = msclr::interop::marshal_as<std::string>(passengerDni);

			Passenger p = authManager->getUserByDni(dniStr);

			if (p.getDni() == "") 
				return;

			this->dni = gcnew String(p.getDni().c_str());
			this->name = gcnew String(p.getName().c_str());
			this->password = gcnew String(p.getPassword().c_str());

			// Actualizar UI de perfil
			this->lblName->Text = name;
			this->lblDni->Text = dni;
			this->lblID->Text = gcnew String(p.getPassengerId().c_str());
			this->lblRating->Text = String::Format("{0:F1}", p.getRating());
			this->lblNumTrips->Text = gcnew String(std::to_string(p.getTotalTrips()).c_str());
			this->lblNumSpent->Text = String::Format("S/.{0:F2}", p.getTotalSpent());
			this->topTitle->Text = L"Bienvenido " + name;
		}

		// Muestra el panel de perfil y oculta el de edicion
		void ShowProfilePanel()
		{
			this->lblDni->Visible = true;
			this->lblName->Visible = true;
			this->ProfileTitle->Visible = true;
			this->lblID->Visible = true;
			this->lblNumSpent->Visible = true;
			this->lblNumTrips->Visible = true;
			this->lblSpent->Visible = true;
			this->lblTrips->Visible = true;
			this->lblRating->Visible = true;
			this->btnUpdate->Visible = true;

			this->lblUpdateProfile->Visible = false;
			this->lblNewName->Visible = false;
			this->tbNewName->Visible = false;
			this->lblNewPassword->Visible = false;
			this->tbNewPassword->Visible = false;
			this->lblPastPassword->Visible = false;
			this->tbPastPassword->Visible = false;
			this->btnConfirm->Visible = false;
		}

		// Muestra el panel de edicion y oculta el de perfil
		void ShowEditPanel()
		{
			this->lblDni->Visible = false;
			this->lblName->Visible = false;
			this->ProfileTitle->Visible = false;
			this->lblID->Visible = false;
			this->lblNumSpent->Visible = false;
			this->lblNumTrips->Visible = false;
			this->lblSpent->Visible = false;
			this->lblTrips->Visible = false;
			this->lblRating->Visible = false;
			this->btnUpdate->Visible = false;

			this->lblUpdateProfile->Visible = true;
			this->lblNewName->Visible = true;
			this->tbNewName->Visible = true;
			this->lblNewPassword->Visible = true;
			this->tbNewPassword->Visible = true;
			this->lblPastPassword->Visible = true;
			this->tbPastPassword->Visible = true;
			this->btnConfirm->Visible = true;
		}

		//
		// Load Form
		//
		System::Void PassengerMenuForm_Load(System::Object^ sender, System::EventArgs^ e)
		{
			normalSize = this->Size;
			normalLocation = this->Location;
			normalState = this->WindowState;

			// Cargar imagen de la barra LYNX
			try {
				this->pictureBoxIcon->Image = System::Drawing::Image::FromFile("resources/LYNX_image.png");
				this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			}
			catch (...) {}

			// Cargar datos del pasajero desde authManager
			LoadPassengerData();

			FormsStatus::SaveWindow(this);
			if (FormsStatus::isFullscreen) FormsStatus::ApplyWindow(this);
		}

		//
		// Tipo de viaje: seleccion de boton
		//
		System::Void btnEconomic_Click(System::Object^ sender, System::EventArgs^ e) {
			this->btnEconomic->BackColor = System::Drawing::Color::Black;
			this->btnEconomic->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnStandard->BackColor = System::Drawing::Color::White;
			this->btnStandard->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnPremium->BackColor = System::Drawing::Color::White;
			this->btnPremium->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
		}

		System::Void btnStandard_Click(System::Object^ sender, System::EventArgs^ e) {
			this->btnStandard->BackColor = System::Drawing::Color::Black;
			this->btnStandard->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnEconomic->BackColor = System::Drawing::Color::White;
			this->btnEconomic->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnPremium->BackColor = System::Drawing::Color::White;
			this->btnPremium->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
		}

		System::Void btnPremium_Click(System::Object^ sender, System::EventArgs^ e) {
			this->btnPremium->BackColor = System::Drawing::Color::Black;
			this->btnPremium->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnStandard->BackColor = System::Drawing::Color::White;
			this->btnStandard->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnEconomic->BackColor = System::Drawing::Color::White;
			this->btnEconomic->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
		}

		//
		// Buscar viaje
		//
		System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
			this->tbOrigin->Text = "";
			this->tbDestination->Text = "";
			this->tbDistance->Text = "";
		}

		System::Void btnSearch_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->btnSearch->BackColor = System::Drawing::Color::White;
			this->btnSearch->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
		}

		System::Void btnSearch_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->btnSearch->BackColor = System::Drawing::Color::SeaGreen;
			this->btnSearch->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnSearch->Location = System::Drawing::Point(138, 261);
		}

		System::Void btnSearch_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			this->btnSearch->BackColor = System::Drawing::Color::Black;
			this->btnSearch->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSearch->Location = System::Drawing::Point(138, 264);
		}

		//
		// Perfil: mostrar / editar
		//
		System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
			ShowEditPanel();
		}

		System::Void btnUpdate_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			this->btnUpdate->BackColor = System::Drawing::Color::SeaGreen;
			this->btnUpdate->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnUpdate->Location = System::Drawing::Point(111, 272);
		}

		System::Void btnUpdate_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			this->btnUpdate->BackColor = System::Drawing::Color::Black;
			this->btnUpdate->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnUpdate->Location = System::Drawing::Point(111, 275);
		}

		// btnConfirm: valida, actualiza en authManager y refresca UI
		System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ newname = this->tbNewName->Text->Trim();
			String^ newpassword = this->tbNewPassword->Text;
			String^ pastpassword = this->tbPastPassword->Text;

			// Validar campos vacios
			if (newname->Length == 0 || newpassword->Length == 0 || pastpassword->Length == 0) {
				MessageBox::Show("Por favor llene todos los campos", "Actualizar Perfil", MessageBoxButtons::OK);
				return;
			}

			// Validar contrasena anterior
			if (pastpassword != password) {
				MessageBox::Show("Contrasena anterior incorrecta", "Actualizar Perfil", MessageBoxButtons::OK);
				return;
			}

			// Actualizar en authManager (persiste en archivo)
			if (authManager != nullptr) {
				String^ currentDni = dni;
				std::string dniStr = msclr::interop::marshal_as<std::string>(currentDni);
				std::string newNameStr = msclr::interop::marshal_as<std::string>(newname);
				std::string newPassStr = msclr::interop::marshal_as<std::string>(newpassword);
				authManager->updatePassengerData(dniStr, newNameStr, newPassStr);
			}

			// Actualizar variables locales
			name = newname;
			password = newpassword;  // contrasena NUEVA, no la vieja

			// Refrescar UI
			this->lblName->Text = name;
			this->topTitle->Text = L"Bienvenido " + name;

			// Limpiar campos de edicion
			this->tbNewName->Text = "";
			this->tbNewPassword->Text = "";
			this->tbPastPassword->Text = "";

			ShowProfilePanel();
			MessageBox::Show("Perfil actualizado correctamente", "Actualizar Perfil", MessageBoxButtons::OK);
		}

		//
		// Viaje actual: paint, aceptar, finalizar
		//
		System::Void queuePanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}

		//
		// Fullscreen: F11 activa/desactiva, ESC sale si esta en fullscreen
		//
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

		//
		// Click functions
		//
		// pictureBoxIcon: volver al menu principal
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
		// Actived Component: es un evento de Windows Forms que se dispara cada vez que el form se convierte en la ventana activa
		//
		System::Void PassengerMenuForm_Activated(System::Object^ sender, System::EventArgs^ e) {
			if (authManager != nullptr)
				authManager->reloadPassengers();
			LoadPassengerData();
		}
};
}
