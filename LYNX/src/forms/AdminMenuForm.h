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

	public ref class AdminMenuForm : public System::Windows::Forms::Form
	{
	public:
		AdminMenuForm(void)
		{
			InitializeComponent();
			ConfigureForm();
		}

		AdminMenuForm(AuthManager* auth, TripManager* trips)
		{
			this->authManager = auth;
			this->tripManager = trips;
			InitializeComponent();
			ConfigureForm();
		}

	protected:
		~AdminMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ headerPanel;
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::Label^ subtitleLabel;
	private: System::Windows::Forms::Panel^ statsPanel;
	private: System::Windows::Forms::Panel^ card1;
	private: System::Windows::Forms::Panel^ card2;
	private: System::Windows::Forms::Panel^ card3;
	private: System::Windows::Forms::Label^ card1Title;
	private: System::Windows::Forms::Label^ card1Value;
	private: System::Windows::Forms::Label^ card2Title;
	private: System::Windows::Forms::Label^ card2Value;
	private: System::Windows::Forms::Label^ card3Title;
	private: System::Windows::Forms::Label^ card3Value;
	private: System::Windows::Forms::Panel^ usersPanel;
	private: System::Windows::Forms::Label^ usersTitle;
	private: System::Windows::Forms::ListView^ usersList;
	private: System::Windows::Forms::Panel^ tripsPanel;
	private: System::Windows::Forms::Label^ tripsTitle;
	private: System::Windows::Forms::ListView^ tripsList;
	private: System::Windows::Forms::Button^ previewButton;
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
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->headerPanel = (gcnew System::Windows::Forms::Panel());
			this->subtitleLabel = (gcnew System::Windows::Forms::Label());
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->statsPanel = (gcnew System::Windows::Forms::Panel());
			this->card3 = (gcnew System::Windows::Forms::Panel());
			this->card3Value = (gcnew System::Windows::Forms::Label());
			this->card3Title = (gcnew System::Windows::Forms::Label());
			this->card2 = (gcnew System::Windows::Forms::Panel());
			this->card2Value = (gcnew System::Windows::Forms::Label());
			this->card2Title = (gcnew System::Windows::Forms::Label());
			this->card1 = (gcnew System::Windows::Forms::Panel());
			this->card1Value = (gcnew System::Windows::Forms::Label());
			this->card1Title = (gcnew System::Windows::Forms::Label());
			this->usersPanel = (gcnew System::Windows::Forms::Panel());
			this->usersList = (gcnew System::Windows::Forms::ListView());
			this->usersTitle = (gcnew System::Windows::Forms::Label());
			this->tripsPanel = (gcnew System::Windows::Forms::Panel());
			this->tripsList = (gcnew System::Windows::Forms::ListView());
			this->tripsTitle = (gcnew System::Windows::Forms::Label());
			this->previewButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblMarco1 = (gcnew System::Windows::Forms::Label());
			this->lblMarco2 = (gcnew System::Windows::Forms::Label());
			this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
			this->lblLYNX = (gcnew System::Windows::Forms::Label());
			this->headerPanel->SuspendLayout();
			this->statsPanel->SuspendLayout();
			this->card3->SuspendLayout();
			this->card2->SuspendLayout();
			this->card1->SuspendLayout();
			this->usersPanel->SuspendLayout();
			this->tripsPanel->SuspendLayout();
			this->pnlTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
			this->SuspendLayout();
			// 
			// headerPanel
			// 
			this->headerPanel->BackColor = System::Drawing::Color::White;
			this->headerPanel->Controls->Add(this->subtitleLabel);
			this->headerPanel->Controls->Add(this->titleLabel);
			this->headerPanel->Location = System::Drawing::Point(63, 95);
			this->headerPanel->Name = L"headerPanel";
			this->headerPanel->Size = System::Drawing::Size(1330, 120);
			this->headerPanel->TabIndex = 0;
			// 
			// subtitleLabel
			// 
			this->subtitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->subtitleLabel->ForeColor = System::Drawing::Color::Gray;
			this->subtitleLabel->Location = System::Drawing::Point(28, 70);
			this->subtitleLabel->Name = L"subtitleLabel";
			this->subtitleLabel->Size = System::Drawing::Size(600, 25);
			this->subtitleLabel->TabIndex = 1;
			this->subtitleLabel->Text = L"Control de usuarios, conductores y viajes.";
			// 
			// titleLabel
			// 
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->titleLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->titleLabel->Location = System::Drawing::Point(25, 20);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(500, 40);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"Panel Administrativo";
			// 
			// statsPanel
			// 
			this->statsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->statsPanel->Controls->Add(this->card3);
			this->statsPanel->Controls->Add(this->card2);
			this->statsPanel->Controls->Add(this->card1);
			this->statsPanel->Location = System::Drawing::Point(25, 170);
			this->statsPanel->Name = L"statsPanel";
			this->statsPanel->Size = System::Drawing::Size(1330, 140);
			this->statsPanel->TabIndex = 1;
			// 
			// card3
			// 
			this->card3->BackColor = System::Drawing::Color::White;
			this->card3->Controls->Add(this->card3Value);
			this->card3->Controls->Add(this->card3Title);
			this->card3->Location = System::Drawing::Point(580, 0);
			this->card3->Name = L"card3";
			this->card3->Size = System::Drawing::Size(250, 120);
			this->card3->TabIndex = 2;
			// 
			// card3Value
			// 
			this->card3Value->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->card3Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->card3Value->Location = System::Drawing::Point(20, 50);
			this->card3Value->Name = L"card3Value";
			this->card3Value->Size = System::Drawing::Size(150, 40);
			this->card3Value->TabIndex = 1;
			this->card3Value->Text = L"9";
			// 
			// card3Title
			// 
			this->card3Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->card3Title->Location = System::Drawing::Point(20, 20);
			this->card3Title->Name = L"card3Title";
			this->card3Title->Size = System::Drawing::Size(150, 25);
			this->card3Title->TabIndex = 0;
			this->card3Title->Text = L"Viajes Activos";
			// 
			// card2
			// 
			this->card2->BackColor = System::Drawing::Color::White;
			this->card2->Controls->Add(this->card2Value);
			this->card2->Controls->Add(this->card2Title);
			this->card2->Location = System::Drawing::Point(290, 0);
			this->card2->Name = L"card2";
			this->card2->Size = System::Drawing::Size(250, 120);
			this->card2->TabIndex = 1;
			// 
			// card2Value
			// 
			this->card2Value->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->card2Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->card2Value->Location = System::Drawing::Point(20, 50);
			this->card2Value->Name = L"card2Value";
			this->card2Value->Size = System::Drawing::Size(150, 40);
			this->card2Value->TabIndex = 1;
			this->card2Value->Text = L"48";
			// 
			// card2Title
			// 
			this->card2Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->card2Title->Location = System::Drawing::Point(20, 20);
			this->card2Title->Name = L"card2Title";
			this->card2Title->Size = System::Drawing::Size(150, 25);
			this->card2Title->TabIndex = 0;
			this->card2Title->Text = L"Conductores";
			// 
			// card1
			// 
			this->card1->BackColor = System::Drawing::Color::White;
			this->card1->Controls->Add(this->card1Value);
			this->card1->Controls->Add(this->card1Title);
			this->card1->Location = System::Drawing::Point(0, 0);
			this->card1->Name = L"card1";
			this->card1->Size = System::Drawing::Size(250, 120);
			this->card1->TabIndex = 0;
			// 
			// card1Value
			// 
			this->card1Value->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
			this->card1Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(220)));
			this->card1Value->Location = System::Drawing::Point(20, 50);
			this->card1Value->Name = L"card1Value";
			this->card1Value->Size = System::Drawing::Size(150, 40);
			this->card1Value->TabIndex = 1;
			this->card1Value->Text = L"128";
			// 
			// card1Title
			// 
			this->card1Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->card1Title->Location = System::Drawing::Point(20, 20);
			this->card1Title->Name = L"card1Title";
			this->card1Title->Size = System::Drawing::Size(150, 25);
			this->card1Title->TabIndex = 0;
			this->card1Title->Text = L"Usuarios";
			// 
			// usersPanel
			// 
			this->usersPanel->BackColor = System::Drawing::Color::White;
			this->usersPanel->Controls->Add(this->usersList);
			this->usersPanel->Controls->Add(this->usersTitle);
			this->usersPanel->Location = System::Drawing::Point(25, 350);
			this->usersPanel->Name = L"usersPanel";
			this->usersPanel->Size = System::Drawing::Size(640, 420);
			this->usersPanel->TabIndex = 2;
			// 
			// usersList
			// 
			this->usersList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->usersList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->usersList->HideSelection = false;
			this->usersList->Location = System::Drawing::Point(20, 70);
			this->usersList->Name = L"usersList";
			this->usersList->Size = System::Drawing::Size(590, 280);
			this->usersList->TabIndex = 1;
			this->usersList->UseCompatibleStateImageBehavior = false;
			this->usersList->View = System::Windows::Forms::View::List;
			// 
			// usersTitle
			// 
			this->usersTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->usersTitle->Location = System::Drawing::Point(20, 20);
			this->usersTitle->Name = L"usersTitle";
			this->usersTitle->Size = System::Drawing::Size(200, 30);
			this->usersTitle->TabIndex = 0;
			this->usersTitle->Text = L"Usuarios";
			// 
			// tripsPanel
			// 
			this->tripsPanel->BackColor = System::Drawing::Color::White;
			this->tripsPanel->Controls->Add(this->tripsList);
			this->tripsPanel->Controls->Add(this->tripsTitle);
			this->tripsPanel->Location = System::Drawing::Point(715, 350);
			this->tripsPanel->Name = L"tripsPanel";
			this->tripsPanel->Size = System::Drawing::Size(640, 420);
			this->tripsPanel->TabIndex = 3;
			// 
			// tripsList
			// 
			this->tripsList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->tripsList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tripsList->HideSelection = false;
			this->tripsList->Location = System::Drawing::Point(20, 70);
			this->tripsList->Name = L"tripsList";
			this->tripsList->Size = System::Drawing::Size(590, 280);
			this->tripsList->TabIndex = 1;
			this->tripsList->UseCompatibleStateImageBehavior = false;
			this->tripsList->View = System::Windows::Forms::View::List;
			// 
			// tripsTitle
			// 
			this->tripsTitle->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->tripsTitle->Location = System::Drawing::Point(20, 20);
			this->tripsTitle->Name = L"tripsTitle";
			this->tripsTitle->Size = System::Drawing::Size(200, 30);
			this->tripsTitle->TabIndex = 0;
			this->tripsTitle->Text = L"Viajes";
			// 
			// previewButton
			// 
			this->previewButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(220)));
			this->previewButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->previewButton->ForeColor = System::Drawing::Color::White;
			this->previewButton->Location = System::Drawing::Point(25, 790);
			this->previewButton->Name = L"previewButton";
			this->previewButton->Size = System::Drawing::Size(200, 40);
			this->previewButton->TabIndex = 4;
			this->previewButton->Text = L"Mostrar Preview";
			this->previewButton->UseVisualStyleBackColor = false;
			this->previewButton->Click += gcnew System::EventHandler(this, &AdminMenuForm::previewButton_Click);
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
			this->pnlTopBar->Location = System::Drawing::Point(2, -2);
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
			// AdminMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->ClientSize = System::Drawing::Size(1480, 920);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblMarco1);
			this->Controls->Add(this->lblMarco2);
			this->Controls->Add(this->pnlTopBar);
			this->Controls->Add(this->previewButton);
			this->Controls->Add(this->tripsPanel);
			this->Controls->Add(this->usersPanel);
			this->Controls->Add(this->statsPanel);
			this->Controls->Add(this->headerPanel);
			this->Name = L"AdminMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LYNX | Admin";
			this->Load += gcnew System::EventHandler(this, &AdminMenuForm::AdminMenuForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AdminMenuForm::AdminMenuForm_KeyDown);
			this->headerPanel->ResumeLayout(false);
			this->statsPanel->ResumeLayout(false);
			this->card3->ResumeLayout(false);
			this->card2->ResumeLayout(false);
			this->card1->ResumeLayout(false);
			this->usersPanel->ResumeLayout(false);
			this->tripsPanel->ResumeLayout(false);
			this->pnlTopBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		void ConfigureForm()
		{
			// CENTRAR TODO
			this->CenterToScreen();

			// ACTIVAR F11
			this->KeyPreview = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
		}

		System::Void previewButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			System::Windows::Forms::MessageBox::Show(
				L"Panel administrativo funcionando correctamente.",
				L"LYNX"
			);
		}

		//
		// Full screen function
		//
		System::Drawing::Size normalSize;
		System::Drawing::Point normalLocation;
		System::Windows::Forms::FormWindowState normalState;

		System::Void AdminMenuForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
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

private: System::Void AdminMenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
	normalSize = this->Size;
	normalLocation = this->Location;
	normalState = this->WindowState;
	FormsStatus::SaveWindow(this);

	if (FormsStatus::isFullscreen)
	{
		FormsStatus::ApplyWindow(this);
	}
}
};
}
