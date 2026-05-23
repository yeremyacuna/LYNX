#pragma once
#include "PassengerMenuForm.h"
#include "DriverMenuForm.h"
#include "AdminMenuForm.h"

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
		}

	protected:
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ topBar;
	private: System::Windows::Forms::Label^ brandLabel;
	private: System::Windows::Forms::Label^ subtitleLabel;
	private: System::Windows::Forms::Label^ liveChip;
	private: System::Windows::Forms::Panel^ heroPanel;
	private: System::Windows::Forms::Label^ heroChip;
	private: System::Windows::Forms::Label^ heroTitle;
	private: System::Windows::Forms::Label^ heroText;
	private: System::Windows::Forms::Button^ openPassengerButton;
	private: System::Windows::Forms::Button^ openDriverButton;
	private: System::Windows::Forms::Button^ openAdminButton;
	private: System::Windows::Forms::Panel^ previewPanel;
	private: System::Windows::Forms::Label^ previewTitle;
	private: System::Windows::Forms::Panel^ previewBand;


	private: System::Windows::Forms::Panel^ metricA;





	private: System::Windows::Forms::Panel^ metricC;


	private: System::Windows::Forms::Panel^ passengerCard;
	private: System::Windows::Forms::Panel^ passengerAccent;
	private: System::Windows::Forms::Label^ passengerTitle;
	private: System::Windows::Forms::Label^ passengerText;
	private: System::Windows::Forms::Button^ passengerButton;
	private: System::Windows::Forms::Panel^ driverCard;
	private: System::Windows::Forms::Panel^ driverAccent;
	private: System::Windows::Forms::Label^ driverTitle;
	private: System::Windows::Forms::Label^ driverText;
	private: System::Windows::Forms::Button^ driverButton;
	private: System::Windows::Forms::Panel^ adminCard;
	private: System::Windows::Forms::Panel^ adminAccent;
	private: System::Windows::Forms::Label^ adminTitle;
	private: System::Windows::Forms::Label^ adminText;
	private: System::Windows::Forms::Button^ adminButton;
	private: System::Windows::Forms::Panel^ footerPanel;
	private: System::Windows::Forms::Label^ footerTitle;
	private: System::Windows::Forms::Label^ footerText;
	private: System::Windows::Forms::Panel^ metricB;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->topBar = (gcnew System::Windows::Forms::Panel());
			this->liveChip = (gcnew System::Windows::Forms::Label());
			this->subtitleLabel = (gcnew System::Windows::Forms::Label());
			this->brandLabel = (gcnew System::Windows::Forms::Label());
			this->heroPanel = (gcnew System::Windows::Forms::Panel());
			this->openAdminButton = (gcnew System::Windows::Forms::Button());
			this->openDriverButton = (gcnew System::Windows::Forms::Button());
			this->openPassengerButton = (gcnew System::Windows::Forms::Button());
			this->heroText = (gcnew System::Windows::Forms::Label());
			this->heroTitle = (gcnew System::Windows::Forms::Label());
			this->heroChip = (gcnew System::Windows::Forms::Label());
			this->previewPanel = (gcnew System::Windows::Forms::Panel());
			this->metricC = (gcnew System::Windows::Forms::Panel());
			this->metricA = (gcnew System::Windows::Forms::Panel());
			this->previewBand = (gcnew System::Windows::Forms::Panel());
			this->previewTitle = (gcnew System::Windows::Forms::Label());
			this->passengerCard = (gcnew System::Windows::Forms::Panel());
			this->passengerButton = (gcnew System::Windows::Forms::Button());
			this->passengerText = (gcnew System::Windows::Forms::Label());
			this->passengerTitle = (gcnew System::Windows::Forms::Label());
			this->passengerAccent = (gcnew System::Windows::Forms::Panel());
			this->driverCard = (gcnew System::Windows::Forms::Panel());
			this->driverButton = (gcnew System::Windows::Forms::Button());
			this->driverText = (gcnew System::Windows::Forms::Label());
			this->driverTitle = (gcnew System::Windows::Forms::Label());
			this->driverAccent = (gcnew System::Windows::Forms::Panel());
			this->adminCard = (gcnew System::Windows::Forms::Panel());
			this->adminButton = (gcnew System::Windows::Forms::Button());
			this->adminText = (gcnew System::Windows::Forms::Label());
			this->adminTitle = (gcnew System::Windows::Forms::Label());
			this->adminAccent = (gcnew System::Windows::Forms::Panel());
			this->footerPanel = (gcnew System::Windows::Forms::Panel());
			this->footerText = (gcnew System::Windows::Forms::Label());
			this->footerTitle = (gcnew System::Windows::Forms::Label());
			this->metricB = (gcnew System::Windows::Forms::Panel());
			this->topBar->SuspendLayout();
			this->heroPanel->SuspendLayout();
			this->previewPanel->SuspendLayout();
			this->passengerCard->SuspendLayout();
			this->driverCard->SuspendLayout();
			this->adminCard->SuspendLayout();
			this->footerPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// topBar
			// 
			this->topBar->BackColor = System::Drawing::Color::White;
			this->topBar->Controls->Add(this->liveChip);
			this->topBar->Controls->Add(this->subtitleLabel);
			this->topBar->Controls->Add(this->brandLabel);
			this->topBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->topBar->Location = System::Drawing::Point(0, 0);
			this->topBar->Name = L"topBar";
			this->topBar->Size = System::Drawing::Size(1480, 78);
			this->topBar->TabIndex = 0;
			// 
			// liveChip
			// 
			this->liveChip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->liveChip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->liveChip->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(131)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->liveChip->Location = System::Drawing::Point(1262, 22);
			this->liveChip->Name = L"liveChip";
			this->liveChip->Size = System::Drawing::Size(180, 34);
			this->liveChip->TabIndex = 2;
			this->liveChip->Text = L"HELLOOO";
			this->liveChip->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// subtitleLabel
			// 
			this->subtitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->subtitleLabel->ForeColor = System::Drawing::Color::ForestGreen;
			this->subtitleLabel->Location = System::Drawing::Point(126, 24);
			this->subtitleLabel->Name = L"subtitleLabel";
			this->subtitleLabel->Size = System::Drawing::Size(198, 26);
			this->subtitleLabel->TabIndex = 1;
			this->subtitleLabel->Text = L"MainMenuForm";
			// 
			// brandLabel
			// 
			this->brandLabel->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 22, System::Drawing::FontStyle::Bold));
			this->brandLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->brandLabel->Location = System::Drawing::Point(34, 18);
			this->brandLabel->Name = L"brandLabel";
			this->brandLabel->Size = System::Drawing::Size(84, 40);
			this->brandLabel->TabIndex = 0;
			this->brandLabel->Text = L"LYNX";
			// 
			// heroPanel
			// 
			this->heroPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->heroPanel->Controls->Add(this->openAdminButton);
			this->heroPanel->Controls->Add(this->openDriverButton);
			this->heroPanel->Controls->Add(this->openPassengerButton);
			this->heroPanel->Controls->Add(this->heroText);
			this->heroPanel->Controls->Add(this->heroTitle);
			this->heroPanel->Controls->Add(this->heroChip);
			this->heroPanel->Location = System::Drawing::Point(36, 108);
			this->heroPanel->Name = L"heroPanel";
			this->heroPanel->Size = System::Drawing::Size(892, 356);
			this->heroPanel->TabIndex = 1;
			// 
			// openAdminButton
			// 
			this->openAdminButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->openAdminButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->openAdminButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->openAdminButton->ForeColor = System::Drawing::Color::White;
			this->openAdminButton->Location = System::Drawing::Point(436, 276);
			this->openAdminButton->Name = L"openAdminButton";
			this->openAdminButton->Size = System::Drawing::Size(184, 46);
			this->openAdminButton->TabIndex = 5;
			this->openAdminButton->Text = L"Abrir administrador";
			this->openAdminButton->UseVisualStyleBackColor = false;
			this->openAdminButton->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenAdminForm);
			// 
			// openDriverButton
			// 
			this->openDriverButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->openDriverButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->openDriverButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->openDriverButton->ForeColor = System::Drawing::Color::White;
			this->openDriverButton->Location = System::Drawing::Point(234, 276);
			this->openDriverButton->Name = L"openDriverButton";
			this->openDriverButton->Size = System::Drawing::Size(184, 46);
			this->openDriverButton->TabIndex = 4;
			this->openDriverButton->Text = L"Abrir conductor";
			this->openDriverButton->UseVisualStyleBackColor = false;
			this->openDriverButton->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenDriverForm);
			// 
			// openPassengerButton
			// 
			this->openPassengerButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->openPassengerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->openPassengerButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->openPassengerButton->ForeColor = System::Drawing::Color::White;
			this->openPassengerButton->Location = System::Drawing::Point(32, 276);
			this->openPassengerButton->Name = L"openPassengerButton";
			this->openPassengerButton->Size = System::Drawing::Size(184, 46);
			this->openPassengerButton->TabIndex = 3;
			this->openPassengerButton->Text = L"Abrir pasajero";
			this->openPassengerButton->UseVisualStyleBackColor = false;
			this->openPassengerButton->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenPassengerForm);
			// 
			// heroText
			// 
			this->heroText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->heroText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)));
			this->heroText->Location = System::Drawing::Point(32, 190);
			this->heroText->Name = L"heroText";
			this->heroText->Size = System::Drawing::Size(720, 46);
			this->heroText->TabIndex = 2;
			this->heroText->Text = L"---------";
			// 
			// heroTitle
			// 
			this->heroTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 28, System::Drawing::FontStyle::Bold));
			this->heroTitle->ForeColor = System::Drawing::Color::White;
			this->heroTitle->Location = System::Drawing::Point(32, 84);
			this->heroTitle->Name = L"heroTitle";
			this->heroTitle->Size = System::Drawing::Size(760, 92);
			this->heroTitle->TabIndex = 1;
			this->heroTitle->Text = L"Inicio para abrir pasajero, conductor y administrador.";
			// 
			// heroChip
			// 
			this->heroChip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(56)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->heroChip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->heroChip->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->heroChip->Location = System::Drawing::Point(32, 28);
			this->heroChip->Name = L"heroChip";
			this->heroChip->Size = System::Drawing::Size(180, 34);
			this->heroChip->TabIndex = 0;
			this->heroChip->Text = L"Empezar";
			this->heroChip->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// previewPanel
			// 
			this->previewPanel->BackColor = System::Drawing::Color::White;
			this->previewPanel->Controls->Add(this->metricC);
			this->previewPanel->Controls->Add(this->metricB);
			this->previewPanel->Controls->Add(this->metricA);
			this->previewPanel->Controls->Add(this->previewBand);
			this->previewPanel->Controls->Add(this->previewTitle);
			this->previewPanel->Location = System::Drawing::Point(956, 108);
			this->previewPanel->Name = L"previewPanel";
			this->previewPanel->Size = System::Drawing::Size(488, 356);
			this->previewPanel->TabIndex = 2;
			// 
			// metricC
			// 
			this->metricC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->metricC->Location = System::Drawing::Point(332, 222);
			this->metricC->Name = L"metricC";
			this->metricC->Size = System::Drawing::Size(126, 96);
			this->metricC->TabIndex = 4;
			// 
			// metricA
			// 
			this->metricA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->metricA->Location = System::Drawing::Point(28, 222);
			this->metricA->Name = L"metricA";
			this->metricA->Size = System::Drawing::Size(126, 96);
			this->metricA->TabIndex = 2;
			// 
			// previewBand
			// 
			this->previewBand->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->previewBand->Location = System::Drawing::Point(28, 84);
			this->previewBand->Name = L"previewBand";
			this->previewBand->Size = System::Drawing::Size(430, 108);
			this->previewBand->TabIndex = 1;
			// 
			// previewTitle
			// 
			this->previewTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->previewTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->previewTitle->Location = System::Drawing::Point(28, 28);
			this->previewTitle->Name = L"previewTitle";
			this->previewTitle->Size = System::Drawing::Size(220, 34);
			this->previewTitle->TabIndex = 0;
			this->previewTitle->Text = L"Vista principal";
			// 
			// passengerCard
			// 
			this->passengerCard->BackColor = System::Drawing::Color::White;
			this->passengerCard->Controls->Add(this->passengerButton);
			this->passengerCard->Controls->Add(this->passengerText);
			this->passengerCard->Controls->Add(this->passengerTitle);
			this->passengerCard->Controls->Add(this->passengerAccent);
			this->passengerCard->Location = System::Drawing::Point(36, 498);
			this->passengerCard->Name = L"passengerCard";
			this->passengerCard->Size = System::Drawing::Size(444, 178);
			this->passengerCard->TabIndex = 3;
			// 
			// passengerButton
			// 
			this->passengerButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->passengerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->passengerButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->passengerButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->passengerButton->Location = System::Drawing::Point(24, 136);
			this->passengerButton->Name = L"passengerButton";
			this->passengerButton->Size = System::Drawing::Size(150, 34);
			this->passengerButton->TabIndex = 3;
			this->passengerButton->Text = L"Ver pantalla";
			this->passengerButton->UseVisualStyleBackColor = false;
			this->passengerButton->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenPassengerForm);
			// 
			// passengerText
			// 
			this->passengerText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->passengerText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->passengerText->Location = System::Drawing::Point(24, 88);
			this->passengerText->Name = L"passengerText";
			this->passengerText->Size = System::Drawing::Size(300, 42);
			this->passengerText->TabIndex = 2;
			this->passengerText->Text = L"Solicitud de viajes, estado activo, historial y perfil visual del pasajero.";
			// 
			// passengerTitle
			// 
			this->passengerTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->passengerTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->passengerTitle->Location = System::Drawing::Point(24, 44);
			this->passengerTitle->Name = L"passengerTitle";
			this->passengerTitle->Size = System::Drawing::Size(220, 34);
			this->passengerTitle->TabIndex = 1;
			this->passengerTitle->Text = L"Passenger";
			// 
			// passengerAccent
			// 
			this->passengerAccent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->passengerAccent->Location = System::Drawing::Point(24, 22);
			this->passengerAccent->Name = L"passengerAccent";
			this->passengerAccent->Size = System::Drawing::Size(66, 6);
			this->passengerAccent->TabIndex = 0;
			// 
			// driverCard
			// 
			this->driverCard->BackColor = System::Drawing::Color::White;
			this->driverCard->Controls->Add(this->driverButton);
			this->driverCard->Controls->Add(this->driverText);
			this->driverCard->Controls->Add(this->driverTitle);
			this->driverCard->Controls->Add(this->driverAccent);
			this->driverCard->Location = System::Drawing::Point(518, 498);
			this->driverCard->Name = L"driverCard";
			this->driverCard->Size = System::Drawing::Size(444, 178);
			this->driverCard->TabIndex = 4;
			// 
			// driverButton
			// 
			this->driverButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->driverButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->driverButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->driverButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->driverButton->Location = System::Drawing::Point(24, 136);
			this->driverButton->Name = L"driverButton";
			this->driverButton->Size = System::Drawing::Size(150, 34);
			this->driverButton->TabIndex = 3;
			this->driverButton->Text = L"Ver pantalla";
			this->driverButton->UseVisualStyleBackColor = false;
			this->driverButton->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenDriverForm);
			// 
			// driverText
			// 
			this->driverText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->driverText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->driverText->Location = System::Drawing::Point(24, 88);
			this->driverText->Name = L"driverText";
			this->driverText->Size = System::Drawing::Size(300, 42);
			this->driverText->TabIndex = 2;
			this->driverText->Text = L"Centro visual del conductor con estado, solicitudes, vehiculo e historial.";
			// 
			// driverTitle
			// 
			this->driverTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->driverTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->driverTitle->Location = System::Drawing::Point(24, 44);
			this->driverTitle->Name = L"driverTitle";
			this->driverTitle->Size = System::Drawing::Size(220, 34);
			this->driverTitle->TabIndex = 1;
			this->driverTitle->Text = L"Driver";
			// 
			// driverAccent
			// 
			this->driverAccent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->driverAccent->Location = System::Drawing::Point(24, 22);
			this->driverAccent->Name = L"driverAccent";
			this->driverAccent->Size = System::Drawing::Size(66, 6);
			this->driverAccent->TabIndex = 0;
			// 
			// adminCard
			// 
			this->adminCard->BackColor = System::Drawing::Color::White;
			this->adminCard->Controls->Add(this->adminButton);
			this->adminCard->Controls->Add(this->adminText);
			this->adminCard->Controls->Add(this->adminTitle);
			this->adminCard->Controls->Add(this->adminAccent);
			this->adminCard->Location = System::Drawing::Point(1000, 498);
			this->adminCard->Name = L"adminCard";
			this->adminCard->Size = System::Drawing::Size(444, 178);
			this->adminCard->TabIndex = 5;
			// 
			// adminButton
			// 
			this->adminButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->adminButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->adminButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->adminButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->adminButton->Location = System::Drawing::Point(24, 136);
			this->adminButton->Name = L"adminButton";
			this->adminButton->Size = System::Drawing::Size(150, 34);
			this->adminButton->TabIndex = 3;
			this->adminButton->Text = L"Ver pantalla";
			this->adminButton->UseVisualStyleBackColor = false;
			this->adminButton->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenAdminForm);
			// 
			// adminText
			// 
			this->adminText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->adminText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->adminText->Location = System::Drawing::Point(24, 88);
			this->adminText->Name = L"adminText";
			this->adminText->Size = System::Drawing::Size(320, 42);
			this->adminText->TabIndex = 2;
			this->adminText->Text = L"Vista administrativa con metricas, usuarios, viajes y acciones de control.";
			// 
			// adminTitle
			// 
			this->adminTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 20, System::Drawing::FontStyle::Bold));
			this->adminTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->adminTitle->Location = System::Drawing::Point(24, 44);
			this->adminTitle->Name = L"adminTitle";
			this->adminTitle->Size = System::Drawing::Size(220, 34);
			this->adminTitle->TabIndex = 1;
			this->adminTitle->Text = L"Admin";
			// 
			// adminAccent
			// 
			this->adminAccent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->adminAccent->Location = System::Drawing::Point(24, 22);
			this->adminAccent->Name = L"adminAccent";
			this->adminAccent->Size = System::Drawing::Size(66, 6);
			this->adminAccent->TabIndex = 0;
			// 
			// footerPanel
			// 
			this->footerPanel->BackColor = System::Drawing::Color::White;
			this->footerPanel->Controls->Add(this->footerText);
			this->footerPanel->Controls->Add(this->footerTitle);
			this->footerPanel->Location = System::Drawing::Point(36, 714);
			this->footerPanel->Name = L"footerPanel";
			this->footerPanel->Size = System::Drawing::Size(1408, 146);
			this->footerPanel->TabIndex = 6;
			// 
			// footerText
			// 
			this->footerText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->footerText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->footerText->Location = System::Drawing::Point(24, 66);
			this->footerText->Name = L"footerText";
			this->footerText->Size = System::Drawing::Size(1040, 40);
			this->footerText->TabIndex = 1;
			this->footerText->Text = L"TEXTO";
			// 
			// footerTitle
			// 
			this->footerTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->footerTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->footerTitle->Location = System::Drawing::Point(24, 24);
			this->footerTitle->Name = L"footerTitle";
			this->footerTitle->Size = System::Drawing::Size(310, 32);
			this->footerTitle->TabIndex = 0;
			this->footerTitle->Text = L"TEXT";
			// 
			// metricB
			// 
			this->metricB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->metricB->Location = System::Drawing::Point(180, 222);
			this->metricB->Name = L"metricB";
			this->metricB->Size = System::Drawing::Size(126, 96);
			this->metricB->TabIndex = 3;
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->ClientSize = System::Drawing::Size(1480, 920);
			this->Controls->Add(this->footerPanel);
			this->Controls->Add(this->adminCard);
			this->Controls->Add(this->driverCard);
			this->Controls->Add(this->passengerCard);
			this->Controls->Add(this->previewPanel);
			this->Controls->Add(this->heroPanel);
			this->Controls->Add(this->topBar);
			this->MinimumSize = System::Drawing::Size(1280, 820);
			this->Name = L"MainMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LYNX | Inicio";
			this->topBar->ResumeLayout(false);
			this->heroPanel->ResumeLayout(false);
			this->previewPanel->ResumeLayout(false);
			this->passengerCard->ResumeLayout(false);
			this->driverCard->ResumeLayout(false);
			this->adminCard->ResumeLayout(false);
			this->footerPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void OpenPassengerForm(System::Object^ sender, System::EventArgs^ e)
		{
			PassengerMenuForm^ form = gcnew PassengerMenuForm();
			form->Show();
		}

		System::Void OpenDriverForm(System::Object^ sender, System::EventArgs^ e)
		{
			DriverMenuForm^ form = gcnew DriverMenuForm();
			form->Show();
		}

		System::Void OpenAdminForm(System::Object^ sender, System::EventArgs^ e)
		{
			AdminMenuForm^ form = gcnew AdminMenuForm();
			form->Show();
		}
	

};
}