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

	public ref class AdminMenuForm : public System::Windows::Forms::Form
	{
	public:
		AdminMenuForm(void)
		{
			InitializeComponent();
			ConfigureForm();
		}

       
		AdminMenuForm(AuthManager* auth, TripManager* trips, String^ adminId, String^ adminUsername)
		{
			this->authManager = auth;
			this->tripManager = trips;
            this->adminId = adminId;
            this->adminUsername = adminUsername;
			InitializeComponent();
			ConfigureForm();
		}

    protected:
        ~AdminMenuForm()
        {
            if (components) delete components;
        }

        // OBJETOS
	private:
		AuthManager* authManager = nullptr;
		TripManager* tripManager = nullptr;

        String^ adminId = "";
        String^ adminUsername = "";
		

        // COMPONENTES
           // Cuadros de conteo
    private: System::Windows::Forms::Panel^ pnlTarjetaViajes;
    private: System::Windows::Forms::Label^ lblTitViajes;
    private: System::Windows::Forms::Label^ lblNumViajes;

           // Panel busqueda
    private: System::Windows::Forms::Panel^ pnlBusqueda;
    private: System::Windows::Forms::Label^ lblTitBusqueda;
    private: System::Windows::Forms::Button^ btnTabPasajero;
    private: System::Windows::Forms::Button^ btnTabConductor;
    private: System::Windows::Forms::TextBox^ txtDniBuscar;
    private: System::Windows::Forms::Button^ btnBuscar;
    private: System::Windows::Forms::Panel^ pnlResultado;
    private: System::Windows::Forms::Label^ lblResultadoTit;


           // Panel listados con ordenamiento
    private: System::Windows::Forms::Panel^ pnlListados;
    private: System::Windows::Forms::Label^ lblTitListados;
    private: System::Windows::Forms::Button^ btnListPasajeros;
    private: System::Windows::Forms::Button^ btnListConductores;
    private: System::Windows::Forms::Button^ btnListViajes;
    private: System::Windows::Forms::Label^ lblOrdenarPor;
    private: System::Windows::Forms::Button^ btnOrden1;
    private: System::Windows::Forms::Button^ btnOrden2;
    private: System::Windows::Forms::RichTextBox^ rtbListado;

           // Panel passwords en binario
           // Panel estadisticas generales
    private: System::Windows::Forms::Panel^ pnlTopBar;
    private: System::Windows::Forms::PictureBox^ pictureBoxIcon;
    private: System::Windows::Forms::Label^ lblLYNX;
    private: System::Windows::Forms::Label^ lblInvisible1;
    private: System::Windows::Forms::Panel^ topPanel;
    private: System::Windows::Forms::Button^ statusButton;
    private: System::Windows::Forms::Label^ onlineChip;
    private: System::Windows::Forms::Label^ topTitle;
    private: System::Windows::Forms::Panel^ pnlPasswords;
    private: System::Windows::Forms::Label^ lblTitPasswords;
    private: System::Windows::Forms::Button^ btnCargarPasswords;
    private: System::Windows::Forms::RichTextBox^ rtbPasswords;
    private: System::Windows::Forms::Panel^ pnlEstadisticas;
    private: System::Windows::Forms::Label^ lblTitEstadisticas;
    private: System::Windows::Forms::Label^ lblEstPasajerosReg;
    private: System::Windows::Forms::Label^ lblEstConductoresReg;
    private: System::Windows::Forms::Label^ lblEstConductoresDisp;
    private: System::Windows::Forms::Label^ lblEstViajesCancelados;
    private: System::Windows::Forms::Label^ lblEstViajesCompletados;
    private: System::Windows::Forms::Panel^ pnlTarjetaPasajeros;
    private: System::Windows::Forms::Label^ lblTitPasajeros;
    private: System::Windows::Forms::Label^ lblNumPasajeros;
    private: System::Windows::Forms::Panel^ pnlTarjetaConductores;
    private: System::Windows::Forms::Label^ lblTitConductores;
    private: System::Windows::Forms::Label^ lblNumConductores;
    private: System::Windows::Forms::Label^ lblEstViajesHistorial;
    private: System::Windows::Forms::Label^ lblEstGanancias;
    private: System::Windows::Forms::Label^ lblEstMontoCola;
    private: System::Windows::Forms::Label^ lblEstViajesCurso;
    private: System::Windows::Forms::Label^ lblEstCola;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
    private: System::Windows::Forms::Label^ lblInvisible4;
    private: System::Windows::Forms::Label^ lblInvisible3;
    private: System::Windows::Forms::Label^ lblInvisible6;
    private: System::Windows::Forms::Label^ lblInvisible5;
    private: System::Windows::Forms::Label^ lblEstIngresosFact;
private: System::Windows::Forms::RichTextBox^ lblResultadoInfo;
private: System::Windows::Forms::Button^ btnMinimo;
private: System::Windows::Forms::Button^ btnMaximo;
private: System::Windows::Forms::Button^ btnBuscarDeListado;

private: System::Windows::Forms::TextBox^ txtIDViajeBuscar;



    private: System::ComponentModel::Container^ components;

        // WINDOWS INITIALIZE
    private:
    #pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->pnlTarjetaViajes = (gcnew System::Windows::Forms::Panel());
            this->lblTitViajes = (gcnew System::Windows::Forms::Label());
            this->lblNumViajes = (gcnew System::Windows::Forms::Label());
            this->pnlBusqueda = (gcnew System::Windows::Forms::Panel());
            this->lblTitBusqueda = (gcnew System::Windows::Forms::Label());
            this->btnTabPasajero = (gcnew System::Windows::Forms::Button());
            this->btnTabConductor = (gcnew System::Windows::Forms::Button());
            this->txtDniBuscar = (gcnew System::Windows::Forms::TextBox());
            this->btnBuscar = (gcnew System::Windows::Forms::Button());
            this->pnlResultado = (gcnew System::Windows::Forms::Panel());
            this->lblResultadoInfo = (gcnew System::Windows::Forms::RichTextBox());
            this->lblResultadoTit = (gcnew System::Windows::Forms::Label());
            this->pnlListados = (gcnew System::Windows::Forms::Panel());
            this->btnBuscarDeListado = (gcnew System::Windows::Forms::Button());
            this->txtIDViajeBuscar = (gcnew System::Windows::Forms::TextBox());
            this->btnMinimo = (gcnew System::Windows::Forms::Button());
            this->btnMaximo = (gcnew System::Windows::Forms::Button());
            this->lblTitListados = (gcnew System::Windows::Forms::Label());
            this->btnListPasajeros = (gcnew System::Windows::Forms::Button());
            this->btnListConductores = (gcnew System::Windows::Forms::Button());
            this->btnListViajes = (gcnew System::Windows::Forms::Button());
            this->lblOrdenarPor = (gcnew System::Windows::Forms::Label());
            this->btnOrden1 = (gcnew System::Windows::Forms::Button());
            this->btnOrden2 = (gcnew System::Windows::Forms::Button());
            this->rtbListado = (gcnew System::Windows::Forms::RichTextBox());
            this->lblInvisible1 = (gcnew System::Windows::Forms::Label());
            this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
            this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
            this->lblLYNX = (gcnew System::Windows::Forms::Label());
            this->topPanel = (gcnew System::Windows::Forms::Panel());
            this->statusButton = (gcnew System::Windows::Forms::Button());
            this->onlineChip = (gcnew System::Windows::Forms::Label());
            this->topTitle = (gcnew System::Windows::Forms::Label());
            this->pnlPasswords = (gcnew System::Windows::Forms::Panel());
            this->lblTitPasswords = (gcnew System::Windows::Forms::Label());
            this->btnCargarPasswords = (gcnew System::Windows::Forms::Button());
            this->rtbPasswords = (gcnew System::Windows::Forms::RichTextBox());
            this->pnlEstadisticas = (gcnew System::Windows::Forms::Panel());
            this->lblEstIngresosFact = (gcnew System::Windows::Forms::Label());
            this->lblTitEstadisticas = (gcnew System::Windows::Forms::Label());
            this->lblEstPasajerosReg = (gcnew System::Windows::Forms::Label());
            this->lblEstConductoresReg = (gcnew System::Windows::Forms::Label());
            this->lblEstConductoresDisp = (gcnew System::Windows::Forms::Label());
            this->lblEstViajesCancelados = (gcnew System::Windows::Forms::Label());
            this->lblEstViajesCompletados = (gcnew System::Windows::Forms::Label());
            this->lblEstViajesHistorial = (gcnew System::Windows::Forms::Label());
            this->lblEstGanancias = (gcnew System::Windows::Forms::Label());
            this->lblEstMontoCola = (gcnew System::Windows::Forms::Label());
            this->lblEstViajesCurso = (gcnew System::Windows::Forms::Label());
            this->lblEstCola = (gcnew System::Windows::Forms::Label());
            this->pnlTarjetaConductores = (gcnew System::Windows::Forms::Panel());
            this->lblTitConductores = (gcnew System::Windows::Forms::Label());
            this->lblNumConductores = (gcnew System::Windows::Forms::Label());
            this->pnlTarjetaPasajeros = (gcnew System::Windows::Forms::Panel());
            this->lblTitPasajeros = (gcnew System::Windows::Forms::Label());
            this->lblNumPasajeros = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->lblInvisible4 = (gcnew System::Windows::Forms::Label());
            this->lblInvisible3 = (gcnew System::Windows::Forms::Label());
            this->lblInvisible6 = (gcnew System::Windows::Forms::Label());
            this->lblInvisible5 = (gcnew System::Windows::Forms::Label());
            this->pnlTarjetaViajes->SuspendLayout();
            this->pnlBusqueda->SuspendLayout();
            this->pnlResultado->SuspendLayout();
            this->pnlListados->SuspendLayout();
            this->pnlTopBar->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
            this->topPanel->SuspendLayout();
            this->pnlPasswords->SuspendLayout();
            this->pnlEstadisticas->SuspendLayout();
            this->pnlTarjetaConductores->SuspendLayout();
            this->pnlTarjetaPasajeros->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            this->tableLayoutPanel2->SuspendLayout();
            this->SuspendLayout();
            // 
            // pnlTarjetaViajes
            // 
            this->pnlTarjetaViajes->BackColor = System::Drawing::Color::White;
            this->pnlTarjetaViajes->Controls->Add(this->lblTitViajes);
            this->pnlTarjetaViajes->Controls->Add(this->lblNumViajes);
            this->pnlTarjetaViajes->Location = System::Drawing::Point(399, 3);
            this->pnlTarjetaViajes->Name = L"pnlTarjetaViajes";
            this->pnlTarjetaViajes->Size = System::Drawing::Size(194, 89);
            this->pnlTarjetaViajes->TabIndex = 4;
            // 
            // lblTitViajes
            // 
            this->lblTitViajes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11, System::Drawing::FontStyle::Bold));
            this->lblTitViajes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->lblTitViajes->Location = System::Drawing::Point(7, 5);
            this->lblTitViajes->Name = L"lblTitViajes";
            this->lblTitViajes->Size = System::Drawing::Size(180, 26);
            this->lblTitViajes->TabIndex = 0;
            this->lblTitViajes->Text = L"Viajes";
            this->lblTitViajes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lblNumViajes
            // 
            this->lblNumViajes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 26, System::Drawing::FontStyle::Bold));
            this->lblNumViajes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
                static_cast<System::Int32>(static_cast<System::Byte>(239)));
            this->lblNumViajes->Location = System::Drawing::Point(7, 33);
            this->lblNumViajes->Name = L"lblNumViajes";
            this->lblNumViajes->Size = System::Drawing::Size(180, 44);
            this->lblNumViajes->TabIndex = 1;
            this->lblNumViajes->Text = L"0";
            this->lblNumViajes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pnlBusqueda
            // 
            this->pnlBusqueda->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->pnlBusqueda->BackColor = System::Drawing::Color::White;
            this->pnlBusqueda->Controls->Add(this->lblTitBusqueda);
            this->pnlBusqueda->Controls->Add(this->btnTabPasajero);
            this->pnlBusqueda->Controls->Add(this->btnTabConductor);
            this->pnlBusqueda->Controls->Add(this->txtDniBuscar);
            this->pnlBusqueda->Controls->Add(this->btnBuscar);
            this->pnlBusqueda->Controls->Add(this->pnlResultado);
            this->pnlBusqueda->Location = System::Drawing::Point(0, 318);
            this->pnlBusqueda->Name = L"pnlBusqueda";
            this->pnlBusqueda->Size = System::Drawing::Size(593, 346);
            this->pnlBusqueda->TabIndex = 5;
            // 
            // lblTitBusqueda
            // 
            this->lblTitBusqueda->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblTitBusqueda->AutoSize = true;
            this->lblTitBusqueda->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13, System::Drawing::FontStyle::Bold));
            this->lblTitBusqueda->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->lblTitBusqueda->Location = System::Drawing::Point(15, 14);
            this->lblTitBusqueda->Name = L"lblTitBusqueda";
            this->lblTitBusqueda->Size = System::Drawing::Size(135, 22);
            this->lblTitBusqueda->TabIndex = 0;
            this->lblTitBusqueda->Text = L"Buscar usuario";
            // 
            // btnTabPasajero
            // 
            this->btnTabPasajero->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->btnTabPasajero->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
                static_cast<System::Int32>(static_cast<System::Byte>(109)));
            this->btnTabPasajero->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnTabPasajero->FlatAppearance->BorderSize = 0;
            this->btnTabPasajero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnTabPasajero->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            this->btnTabPasajero->ForeColor = System::Drawing::Color::White;
            this->btnTabPasajero->Location = System::Drawing::Point(15, 50);
            this->btnTabPasajero->Name = L"btnTabPasajero";
            this->btnTabPasajero->Size = System::Drawing::Size(160, 32);
            this->btnTabPasajero->TabIndex = 1;
            this->btnTabPasajero->Text = L"Pasajero  (DNI)";
            this->btnTabPasajero->UseVisualStyleBackColor = false;
            this->btnTabPasajero->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnTabPasajero_Click);
            // 
            // btnTabConductor
            // 
            this->btnTabConductor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->btnTabConductor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)));
            this->btnTabConductor->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnTabConductor->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)),
                static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
            this->btnTabConductor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnTabConductor->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->btnTabConductor->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
                static_cast<System::Int32>(static_cast<System::Byte>(120)));
            this->btnTabConductor->Location = System::Drawing::Point(185, 50);
            this->btnTabConductor->Name = L"btnTabConductor";
            this->btnTabConductor->Size = System::Drawing::Size(175, 32);
            this->btnTabConductor->TabIndex = 2;
            this->btnTabConductor->Text = L"Conductor  (Rating)";
            this->btnTabConductor->UseVisualStyleBackColor = false;
            this->btnTabConductor->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnTabConductor_Click);
            // 
            // txtDniBuscar
            // 
            this->txtDniBuscar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtDniBuscar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txtDniBuscar->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10));
            this->txtDniBuscar->ForeColor = System::Drawing::Color::Gray;
            this->txtDniBuscar->Location = System::Drawing::Point(15, 98);
            this->txtDniBuscar->Name = L"txtDniBuscar";
            this->txtDniBuscar->Size = System::Drawing::Size(400, 24);
            this->txtDniBuscar->TabIndex = 3;
            this->txtDniBuscar->Text = L"Ingresa el DNI del pasajero...";
            this->txtDniBuscar->Enter += gcnew System::EventHandler(this, &AdminMenuForm::txtDni_Enter);
            this->txtDniBuscar->Leave += gcnew System::EventHandler(this, &AdminMenuForm::txtDni_Leave);
            // 
            // btnBuscar
            // 
            this->btnBuscar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->btnBuscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
                static_cast<System::Int32>(static_cast<System::Byte>(109)));
            this->btnBuscar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnBuscar->FlatAppearance->BorderSize = 0;
            this->btnBuscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            this->btnBuscar->ForeColor = System::Drawing::Color::White;
            this->btnBuscar->Location = System::Drawing::Point(425, 97);
            this->btnBuscar->Name = L"btnBuscar";
            this->btnBuscar->Size = System::Drawing::Size(130, 28);
            this->btnBuscar->TabIndex = 4;
            this->btnBuscar->Text = L"Buscar";
            this->btnBuscar->UseVisualStyleBackColor = false;
            this->btnBuscar->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnBuscar_Click);
            // 
            // pnlResultado
            // 
            this->pnlResultado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->pnlResultado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)));
            this->pnlResultado->Controls->Add(this->lblResultadoInfo);
            this->pnlResultado->Controls->Add(this->lblResultadoTit);
            this->pnlResultado->Location = System::Drawing::Point(15, 140);
            this->pnlResultado->Name = L"pnlResultado";
            this->pnlResultado->Size = System::Drawing::Size(568, 190);
            this->pnlResultado->TabIndex = 5;
            // 
            // lblResultadoInfo
            // 
            this->lblResultadoInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->lblResultadoInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(246)));
            this->lblResultadoInfo->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->lblResultadoInfo->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblResultadoInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->lblResultadoInfo->Location = System::Drawing::Point(11, 34);
            this->lblResultadoInfo->Name = L"lblResultadoInfo";
            this->lblResultadoInfo->ReadOnly = true;
            this->lblResultadoInfo->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
            this->lblResultadoInfo->Size = System::Drawing::Size(545, 144);
            this->lblResultadoInfo->TabIndex = 8;
            this->lblResultadoInfo->Text = L"Ingresa un DNI y presiona Buscar.";
            // 
            // lblResultadoTit
            // 
            this->lblResultadoTit->AutoSize = true;
            this->lblResultadoTit->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblResultadoTit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
                static_cast<System::Int32>(static_cast<System::Byte>(70)));
            this->lblResultadoTit->Location = System::Drawing::Point(8, 8);
            this->lblResultadoTit->Name = L"lblResultadoTit";
            this->lblResultadoTit->Size = System::Drawing::Size(68, 16);
            this->lblResultadoTit->TabIndex = 0;
            this->lblResultadoTit->Text = L"Resultado:";
            // 
            // pnlListados
            // 
            this->pnlListados->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->pnlListados->BackColor = System::Drawing::Color::White;
            this->pnlListados->Controls->Add(this->btnBuscarDeListado);
            this->pnlListados->Controls->Add(this->txtIDViajeBuscar);
            this->pnlListados->Controls->Add(this->btnMinimo);
            this->pnlListados->Controls->Add(this->btnMaximo);
            this->pnlListados->Controls->Add(this->lblTitListados);
            this->pnlListados->Controls->Add(this->btnListPasajeros);
            this->pnlListados->Controls->Add(this->btnListConductores);
            this->pnlListados->Controls->Add(this->btnListViajes);
            this->pnlListados->Controls->Add(this->lblOrdenarPor);
            this->pnlListados->Controls->Add(this->btnOrden1);
            this->pnlListados->Controls->Add(this->btnOrden2);
            this->pnlListados->Controls->Add(this->rtbListado);
            this->pnlListados->Location = System::Drawing::Point(609, 208);
            this->pnlListados->Name = L"pnlListados";
            this->pnlListados->Size = System::Drawing::Size(871, 456);
            this->pnlListados->TabIndex = 6;
            // 
            // btnBuscarDeListado
            // 
            this->btnBuscarDeListado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->btnBuscarDeListado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)),
                static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(239)));
            this->btnBuscarDeListado->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnBuscarDeListado->FlatAppearance->BorderSize = 0;
            this->btnBuscarDeListado->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnBuscarDeListado->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            this->btnBuscarDeListado->Location = System::Drawing::Point(459, 93);
            this->btnBuscarDeListado->Name = L"btnBuscarDeListado";
            this->btnBuscarDeListado->Size = System::Drawing::Size(75, 24);
            this->btnBuscarDeListado->TabIndex = 6;
            this->btnBuscarDeListado->Text = L"Buscar";
            this->btnBuscarDeListado->UseVisualStyleBackColor = false;
            this->btnBuscarDeListado->Visible = false;
            this->btnBuscarDeListado->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnBuscarDeListado_Click);
            // 
            // txtIDViajeBuscar
            // 
            this->txtIDViajeBuscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)),
                static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->txtIDViajeBuscar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txtIDViajeBuscar->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10));
            this->txtIDViajeBuscar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
                static_cast<System::Int32>(static_cast<System::Byte>(239)));
            this->txtIDViajeBuscar->Location = System::Drawing::Point(215, 93);
            this->txtIDViajeBuscar->Name = L"txtIDViajeBuscar";
            this->txtIDViajeBuscar->Size = System::Drawing::Size(234, 24);
            this->txtIDViajeBuscar->TabIndex = 6;
            this->txtIDViajeBuscar->Text = L"Ingresa N de ID de viaje...";
            this->txtIDViajeBuscar->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->txtIDViajeBuscar->Visible = false;
            this->txtIDViajeBuscar->Enter += gcnew System::EventHandler(this, &AdminMenuForm::txtIDViajeBuscar_Enter);
            this->txtIDViajeBuscar->Leave += gcnew System::EventHandler(this, &AdminMenuForm::txtIDViajeBuscar_Leave);
            // 
            // btnMinimo
            // 
            this->btnMinimo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
                static_cast<System::Int32>(static_cast<System::Byte>(109)));
            this->btnMinimo->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnMinimo->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnMinimo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnMinimo->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
            this->btnMinimo->ForeColor = System::Drawing::Color::White;
            this->btnMinimo->Location = System::Drawing::Point(421, 92);
            this->btnMinimo->Name = L"btnMinimo";
            this->btnMinimo->Size = System::Drawing::Size(112, 26);
            this->btnMinimo->TabIndex = 9;
            this->btnMinimo->Text = L"Minimo";
            this->btnMinimo->UseVisualStyleBackColor = false;
            this->btnMinimo->Visible = false;
            this->btnMinimo->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnMinimo_Click);
            // 
            // btnMaximo
            // 
            this->btnMaximo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
                static_cast<System::Int32>(static_cast<System::Byte>(109)));
            this->btnMaximo->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnMaximo->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnMaximo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnMaximo->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
            this->btnMaximo->ForeColor = System::Drawing::Color::White;
            this->btnMaximo->Location = System::Drawing::Point(299, 92);
            this->btnMaximo->Name = L"btnMaximo";
            this->btnMaximo->Size = System::Drawing::Size(112, 26);
            this->btnMaximo->TabIndex = 8;
            this->btnMaximo->Text = L"Maximo";
            this->btnMaximo->UseVisualStyleBackColor = false;
            this->btnMaximo->Visible = false;
            this->btnMaximo->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnMaximo_Click);
            // 
            // lblTitListados
            // 
            this->lblTitListados->AutoSize = true;
            this->lblTitListados->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13, System::Drawing::FontStyle::Bold));
            this->lblTitListados->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->lblTitListados->Location = System::Drawing::Point(15, 12);
            this->lblTitListados->Name = L"lblTitListados";
            this->lblTitListados->Size = System::Drawing::Size(238, 22);
            this->lblTitListados->TabIndex = 0;
            this->lblTitListados->Text = L"Listado de usuarios y viajes";
            // 
            // btnListPasajeros
            // 
            this->btnListPasajeros->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
                static_cast<System::Int32>(static_cast<System::Byte>(109)));
            this->btnListPasajeros->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnListPasajeros->FlatAppearance->BorderSize = 0;
            this->btnListPasajeros->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnListPasajeros->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            this->btnListPasajeros->ForeColor = System::Drawing::Color::White;
            this->btnListPasajeros->Location = System::Drawing::Point(15, 50);
            this->btnListPasajeros->Name = L"btnListPasajeros";
            this->btnListPasajeros->Size = System::Drawing::Size(115, 32);
            this->btnListPasajeros->TabIndex = 1;
            this->btnListPasajeros->Text = L"Pasajeros";
            this->btnListPasajeros->UseVisualStyleBackColor = false;
            this->btnListPasajeros->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnListPasajeros_Click);
            // 
            // btnListConductores
            // 
            this->btnListConductores->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
                static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(252)));
            this->btnListConductores->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnListConductores->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)),
                static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
            this->btnListConductores->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnListConductores->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->btnListConductores->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)),
                static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
            this->btnListConductores->Location = System::Drawing::Point(140, 50);
            this->btnListConductores->Name = L"btnListConductores";
            this->btnListConductores->Size = System::Drawing::Size(115, 32);
            this->btnListConductores->TabIndex = 2;
            this->btnListConductores->Text = L"Conductores";
            this->btnListConductores->UseVisualStyleBackColor = false;
            this->btnListConductores->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnListConductores_Click);
            // 
            // btnListViajes
            // 
            this->btnListViajes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnListViajes->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnListViajes->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)),
                static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(239)));
            this->btnListViajes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnListViajes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->btnListViajes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
                static_cast<System::Int32>(static_cast<System::Byte>(239)));
            this->btnListViajes->Location = System::Drawing::Point(265, 50);
            this->btnListViajes->Name = L"btnListViajes";
            this->btnListViajes->Size = System::Drawing::Size(95, 32);
            this->btnListViajes->TabIndex = 3;
            this->btnListViajes->Text = L"Viajes";
            this->btnListViajes->UseVisualStyleBackColor = false;
            this->btnListViajes->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnListViajes_Click);
            // 
            // lblOrdenarPor
            // 
            this->lblOrdenarPor->AutoSize = true;
            this->lblOrdenarPor->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblOrdenarPor->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(80)));
            this->lblOrdenarPor->Location = System::Drawing::Point(15, 96);
            this->lblOrdenarPor->Name = L"lblOrdenarPor";
            this->lblOrdenarPor->Size = System::Drawing::Size(80, 16);
            this->lblOrdenarPor->TabIndex = 4;
            this->lblOrdenarPor->Text = L"Ordenar por:";
            // 
            // btnOrden1
            // 
            this->btnOrden1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
                static_cast<System::Int32>(static_cast<System::Byte>(34)));
            this->btnOrden1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnOrden1->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnOrden1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnOrden1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
            this->btnOrden1->ForeColor = System::Drawing::Color::White;
            this->btnOrden1->Location = System::Drawing::Point(120, 92);
            this->btnOrden1->Name = L"btnOrden1";
            this->btnOrden1->Size = System::Drawing::Size(75, 26);
            this->btnOrden1->TabIndex = 5;
            this->btnOrden1->Text = L"ID";
            this->btnOrden1->UseVisualStyleBackColor = false;
            this->btnOrden1->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnOrden1_Click);
            // 
            // btnOrden2
            // 
            this->btnOrden2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
                static_cast<System::Int32>(static_cast<System::Byte>(34)));
            this->btnOrden2->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnOrden2->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnOrden2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnOrden2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
            this->btnOrden2->ForeColor = System::Drawing::Color::White;
            this->btnOrden2->Location = System::Drawing::Point(205, 92);
            this->btnOrden2->Name = L"btnOrden2";
            this->btnOrden2->Size = System::Drawing::Size(75, 26);
            this->btnOrden2->TabIndex = 6;
            this->btnOrden2->Text = L"Gasto";
            this->btnOrden2->UseVisualStyleBackColor = false;
            this->btnOrden2->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnOrden2_Click);
            // 
            // rtbListado
            // 
            this->rtbListado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->rtbListado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(249)));
            this->rtbListado->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtbListado->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
            this->rtbListado->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->rtbListado->Location = System::Drawing::Point(15, 130);
            this->rtbListado->Name = L"rtbListado";
            this->rtbListado->ReadOnly = true;
            this->rtbListado->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
            this->rtbListado->Size = System::Drawing::Size(837, 313);
            this->rtbListado->TabIndex = 7;
            this->rtbListado->Text = L"";
            // 
            // lblInvisible1
            // 
            this->lblInvisible1->BackColor = System::Drawing::Color::Red;
            this->lblInvisible1->Location = System::Drawing::Point(0, 77);
            this->lblInvisible1->Name = L"lblInvisible1";
            this->lblInvisible1->Size = System::Drawing::Size(1480, 14);
            this->lblInvisible1->TabIndex = 21;
            this->lblInvisible1->Visible = false;
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
            this->pnlTopBar->TabIndex = 9;
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
            this->pictureBoxIcon->Click += gcnew System::EventHandler(this, &AdminMenuForm::pictureBoxIcon_Click);
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
            // topPanel
            // 
            this->topPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->topPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
                static_cast<System::Int32>(static_cast<System::Byte>(39)));
            this->topPanel->Controls->Add(this->statusButton);
            this->topPanel->Controls->Add(this->onlineChip);
            this->topPanel->Controls->Add(this->topTitle);
            this->topPanel->Location = System::Drawing::Point(0, 91);
            this->topPanel->Name = L"topPanel";
            this->topPanel->Size = System::Drawing::Size(1480, 103);
            this->topPanel->TabIndex = 20;
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
            this->onlineChip->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->onlineChip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(54)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->onlineChip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->onlineChip->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(239)),
                static_cast<System::Int32>(static_cast<System::Byte>(113)));
            this->onlineChip->Location = System::Drawing::Point(1271, 32);
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
            this->topTitle->Text = L"Panel Administrativo";
            // 
            // pnlPasswords
            // 
            this->pnlPasswords->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->pnlPasswords->BackColor = System::Drawing::Color::White;
            this->pnlPasswords->Controls->Add(this->lblTitPasswords);
            this->pnlPasswords->Controls->Add(this->btnCargarPasswords);
            this->pnlPasswords->Controls->Add(this->rtbPasswords);
            this->pnlPasswords->Location = System::Drawing::Point(3, 3);
            this->pnlPasswords->Name = L"pnlPasswords";
            this->pnlPasswords->Size = System::Drawing::Size(591, 232);
            this->pnlPasswords->TabIndex = 8;
            // 
            // lblTitPasswords
            // 
            this->lblTitPasswords->AutoSize = true;
            this->lblTitPasswords->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13, System::Drawing::FontStyle::Bold));
            this->lblTitPasswords->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->lblTitPasswords->Location = System::Drawing::Point(15, 14);
            this->lblTitPasswords->Name = L"lblTitPasswords";
            this->lblTitPasswords->Size = System::Drawing::Size(188, 22);
            this->lblTitPasswords->TabIndex = 0;
            this->lblTitPasswords->Text = L"Passwords en binario";
            // 
            // btnCargarPasswords
            // 
            this->btnCargarPasswords->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->btnCargarPasswords->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
                static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
            this->btnCargarPasswords->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnCargarPasswords->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnCargarPasswords->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCargarPasswords->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            this->btnCargarPasswords->ForeColor = System::Drawing::Color::White;
            this->btnCargarPasswords->Location = System::Drawing::Point(500, 10);
            this->btnCargarPasswords->Name = L"btnCargarPasswords";
            this->btnCargarPasswords->Size = System::Drawing::Size(83, 28);
            this->btnCargarPasswords->TabIndex = 1;
            this->btnCargarPasswords->Text = L"Cargar";
            this->btnCargarPasswords->UseVisualStyleBackColor = false;
            this->btnCargarPasswords->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnCargarPasswords_Click);
            // 
            // rtbPasswords
            // 
            this->rtbPasswords->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->rtbPasswords->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(249)));
            this->rtbPasswords->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtbPasswords->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->rtbPasswords->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->rtbPasswords->Location = System::Drawing::Point(15, 52);
            this->rtbPasswords->Name = L"rtbPasswords";
            this->rtbPasswords->ReadOnly = true;
            this->rtbPasswords->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
            this->rtbPasswords->Size = System::Drawing::Size(565, 160);
            this->rtbPasswords->TabIndex = 2;
            this->rtbPasswords->Text = L"Presiona \'Cargar\' para leer el archivo binario de passwords.";
            // 
            // pnlEstadisticas
            // 
            this->pnlEstadisticas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->pnlEstadisticas->BackColor = System::Drawing::Color::White;
            this->pnlEstadisticas->Controls->Add(this->lblEstIngresosFact);
            this->pnlEstadisticas->Controls->Add(this->lblTitEstadisticas);
            this->pnlEstadisticas->Controls->Add(this->lblEstPasajerosReg);
            this->pnlEstadisticas->Controls->Add(this->lblEstConductoresReg);
            this->pnlEstadisticas->Controls->Add(this->lblEstConductoresDisp);
            this->pnlEstadisticas->Controls->Add(this->lblEstViajesCancelados);
            this->pnlEstadisticas->Controls->Add(this->lblEstViajesCompletados);
            this->pnlEstadisticas->Controls->Add(this->lblEstViajesHistorial);
            this->pnlEstadisticas->Controls->Add(this->lblEstGanancias);
            this->pnlEstadisticas->Controls->Add(this->lblEstMontoCola);
            this->pnlEstadisticas->Controls->Add(this->lblEstViajesCurso);
            this->pnlEstadisticas->Controls->Add(this->lblEstCola);
            this->pnlEstadisticas->Location = System::Drawing::Point(609, 3);
            this->pnlEstadisticas->Name = L"pnlEstadisticas";
            this->pnlEstadisticas->Size = System::Drawing::Size(868, 232);
            this->pnlEstadisticas->TabIndex = 9;
            // 
            // lblEstIngresosFact
            // 
            this->lblEstIngresosFact->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstIngresosFact->AutoSize = true;
            this->lblEstIngresosFact->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstIngresosFact->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
            this->lblEstIngresosFact->Location = System::Drawing::Point(434, 166);
            this->lblEstIngresosFact->Name = L"lblEstIngresosFact";
            this->lblEstIngresosFact->Size = System::Drawing::Size(217, 19);
            this->lblEstIngresosFact->TabIndex = 11;
            this->lblEstIngresosFact->Text = L"Ingresos facturados:  S/ 0.00";
            this->lblEstIngresosFact->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblTitEstadisticas
            // 
            this->lblTitEstadisticas->AutoSize = true;
            this->lblTitEstadisticas->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13, System::Drawing::FontStyle::Bold));
            this->lblTitEstadisticas->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
                static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->lblTitEstadisticas->Location = System::Drawing::Point(15, 14);
            this->lblTitEstadisticas->Name = L"lblTitEstadisticas";
            this->lblTitEstadisticas->Size = System::Drawing::Size(196, 22);
            this->lblTitEstadisticas->TabIndex = 0;
            this->lblTitEstadisticas->Text = L"Estadisticas generales";
            // 
            // lblEstPasajerosReg
            // 
            this->lblEstPasajerosReg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstPasajerosReg->AutoSize = true;
            this->lblEstPasajerosReg->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstPasajerosReg->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->lblEstPasajerosReg->Location = System::Drawing::Point(17, 51);
            this->lblEstPasajerosReg->Name = L"lblEstPasajerosReg";
            this->lblEstPasajerosReg->Size = System::Drawing::Size(195, 18);
            this->lblEstPasajerosReg->TabIndex = 1;
            this->lblEstPasajerosReg->Text = L"Pasajeros registrados:       0";
            this->lblEstPasajerosReg->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblEstConductoresReg
            // 
            this->lblEstConductoresReg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstConductoresReg->AutoSize = true;
            this->lblEstConductoresReg->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstConductoresReg->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->lblEstConductoresReg->Location = System::Drawing::Point(17, 78);
            this->lblEstConductoresReg->Name = L"lblEstConductoresReg";
            this->lblEstConductoresReg->Size = System::Drawing::Size(199, 18);
            this->lblEstConductoresReg->TabIndex = 2;
            this->lblEstConductoresReg->Text = L"Conductores registrados:    0";
            this->lblEstConductoresReg->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblEstConductoresDisp
            // 
            this->lblEstConductoresDisp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstConductoresDisp->AutoSize = true;
            this->lblEstConductoresDisp->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstConductoresDisp->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->lblEstConductoresDisp->Location = System::Drawing::Point(17, 105);
            this->lblEstConductoresDisp->Name = L"lblEstConductoresDisp";
            this->lblEstConductoresDisp->Size = System::Drawing::Size(198, 18);
            this->lblEstConductoresDisp->TabIndex = 3;
            this->lblEstConductoresDisp->Text = L"Conductores disponibles:    0";
            this->lblEstConductoresDisp->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblEstViajesCancelados
            // 
            this->lblEstViajesCancelados->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstViajesCancelados->AutoSize = true;
            this->lblEstViajesCancelados->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstViajesCancelados->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->lblEstViajesCancelados->Location = System::Drawing::Point(433, 108);
            this->lblEstViajesCancelados->Name = L"lblEstViajesCancelados";
            this->lblEstViajesCancelados->Size = System::Drawing::Size(182, 18);
            this->lblEstViajesCancelados->TabIndex = 4;
            this->lblEstViajesCancelados->Text = L"Viajes cancelados:           0";
            this->lblEstViajesCancelados->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblEstViajesCompletados
            // 
            this->lblEstViajesCompletados->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstViajesCompletados->AutoSize = true;
            this->lblEstViajesCompletados->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstViajesCompletados->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->lblEstViajesCompletados->Location = System::Drawing::Point(432, 56);
            this->lblEstViajesCompletados->Name = L"lblEstViajesCompletados";
            this->lblEstViajesCompletados->Size = System::Drawing::Size(183, 19);
            this->lblEstViajesCompletados->TabIndex = 7;
            this->lblEstViajesCompletados->Text = L"Viajes completados:     0";
            this->lblEstViajesCompletados->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblEstViajesHistorial
            // 
            this->lblEstViajesHistorial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstViajesHistorial->AutoSize = true;
            this->lblEstViajesHistorial->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstViajesHistorial->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->lblEstViajesHistorial->Location = System::Drawing::Point(433, 133);
            this->lblEstViajesHistorial->Name = L"lblEstViajesHistorial";
            this->lblEstViajesHistorial->Size = System::Drawing::Size(155, 19);
            this->lblEstViajesHistorial->TabIndex = 8;
            this->lblEstViajesHistorial->Text = L"Viajes en historial: 0";
            this->lblEstViajesHistorial->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblEstGanancias
            // 
            this->lblEstGanancias->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstGanancias->AutoSize = true;
            this->lblEstGanancias->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstGanancias->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
                static_cast<System::Int32>(static_cast<System::Byte>(70)));
            this->lblEstGanancias->Location = System::Drawing::Point(433, 191);
            this->lblEstGanancias->Name = L"lblEstGanancias";
            this->lblEstGanancias->Size = System::Drawing::Size(224, 19);
            this->lblEstGanancias->TabIndex = 10;
            this->lblEstGanancias->Text = L"Ganancia plataforma:  S/ 0.00";
            this->lblEstGanancias->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblEstMontoCola
            // 
            this->lblEstMontoCola->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstMontoCola->AutoSize = true;
            this->lblEstMontoCola->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstMontoCola->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
                static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->lblEstMontoCola->Location = System::Drawing::Point(17, 165);
            this->lblEstMontoCola->Name = L"lblEstMontoCola";
            this->lblEstMontoCola->Size = System::Drawing::Size(191, 18);
            this->lblEstMontoCola->TabIndex = 5;
            this->lblEstMontoCola->Text = L"Monto total en cola:  S/ 0.00";
            this->lblEstMontoCola->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblEstViajesCurso
            // 
            this->lblEstViajesCurso->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstViajesCurso->AutoSize = true;
            this->lblEstViajesCurso->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstViajesCurso->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->lblEstViajesCurso->Location = System::Drawing::Point(432, 82);
            this->lblEstViajesCurso->Name = L"lblEstViajesCurso";
            this->lblEstViajesCurso->Size = System::Drawing::Size(152, 19);
            this->lblEstViajesCurso->TabIndex = 9;
            this->lblEstViajesCurso->Text = L"Viajes en curso:     0";
            this->lblEstViajesCurso->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lblEstCola
            // 
            this->lblEstCola->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblEstCola->AutoSize = true;
            this->lblEstCola->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEstCola->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
                static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->lblEstCola->Location = System::Drawing::Point(17, 192);
            this->lblEstCola->Name = L"lblEstCola";
            this->lblEstCola->Size = System::Drawing::Size(205, 18);
            this->lblEstCola->TabIndex = 6;
            this->lblEstCola->Text = L"Cola: [--] Sin viajes en espera";
            this->lblEstCola->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // pnlTarjetaConductores
            // 
            this->pnlTarjetaConductores->BackColor = System::Drawing::Color::White;
            this->pnlTarjetaConductores->Controls->Add(this->lblTitConductores);
            this->pnlTarjetaConductores->Controls->Add(this->lblNumConductores);
            this->pnlTarjetaConductores->Location = System::Drawing::Point(201, 3);
            this->pnlTarjetaConductores->Name = L"pnlTarjetaConductores";
            this->pnlTarjetaConductores->Size = System::Drawing::Size(192, 89);
            this->pnlTarjetaConductores->TabIndex = 3;
            // 
            // lblTitConductores
            // 
            this->lblTitConductores->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11, System::Drawing::FontStyle::Bold));
            this->lblTitConductores->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
                static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->lblTitConductores->Location = System::Drawing::Point(7, 5);
            this->lblTitConductores->Name = L"lblTitConductores";
            this->lblTitConductores->Size = System::Drawing::Size(180, 26);
            this->lblTitConductores->TabIndex = 0;
            this->lblTitConductores->Text = L"Conductores";
            this->lblTitConductores->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lblNumConductores
            // 
            this->lblNumConductores->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 26, System::Drawing::FontStyle::Bold));
            this->lblNumConductores->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)),
                static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
            this->lblNumConductores->Location = System::Drawing::Point(8, 33);
            this->lblNumConductores->Name = L"lblNumConductores";
            this->lblNumConductores->Size = System::Drawing::Size(180, 44);
            this->lblNumConductores->TabIndex = 1;
            this->lblNumConductores->Text = L"0";
            this->lblNumConductores->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pnlTarjetaPasajeros
            // 
            this->pnlTarjetaPasajeros->BackColor = System::Drawing::Color::White;
            this->pnlTarjetaPasajeros->Controls->Add(this->lblTitPasajeros);
            this->pnlTarjetaPasajeros->Controls->Add(this->lblNumPasajeros);
            this->pnlTarjetaPasajeros->Location = System::Drawing::Point(3, 3);
            this->pnlTarjetaPasajeros->Name = L"pnlTarjetaPasajeros";
            this->pnlTarjetaPasajeros->Size = System::Drawing::Size(192, 89);
            this->pnlTarjetaPasajeros->TabIndex = 2;
            // 
            // lblTitPasajeros
            // 
            this->lblTitPasajeros->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11, System::Drawing::FontStyle::Bold));
            this->lblTitPasajeros->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(31)));
            this->lblTitPasajeros->Location = System::Drawing::Point(9, 5);
            this->lblTitPasajeros->Name = L"lblTitPasajeros";
            this->lblTitPasajeros->Size = System::Drawing::Size(180, 26);
            this->lblTitPasajeros->TabIndex = 0;
            this->lblTitPasajeros->Text = L"Pasajeros";
            this->lblTitPasajeros->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lblNumPasajeros
            // 
            this->lblNumPasajeros->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 26, System::Drawing::FontStyle::Bold));
            this->lblNumPasajeros->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
                static_cast<System::Int32>(static_cast<System::Byte>(109)));
            this->lblNumPasajeros->Location = System::Drawing::Point(9, 33);
            this->lblNumPasajeros->Name = L"lblNumPasajeros";
            this->lblNumPasajeros->Size = System::Drawing::Size(180, 44);
            this->lblNumPasajeros->TabIndex = 1;
            this->lblNumPasajeros->Text = L"0";
            this->lblNumPasajeros->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel1->ColumnCount = 2;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                883)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel1->Controls->Add(this->pnlPasswords, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->pnlEstadisticas, 1, 0);
            this->tableLayoutPanel1->Location = System::Drawing::Point(0, 682);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 1;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(1480, 238);
            this->tableLayoutPanel1->TabIndex = 10;
            // 
            // tableLayoutPanel2
            // 
            this->tableLayoutPanel2->ColumnCount = 3;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                33.33333F)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                33.33333F)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                33.33333F)));
            this->tableLayoutPanel2->Controls->Add(this->pnlTarjetaViajes, 2, 0);
            this->tableLayoutPanel2->Controls->Add(this->pnlTarjetaConductores, 1, 0);
            this->tableLayoutPanel2->Controls->Add(this->pnlTarjetaPasajeros, 0, 0);
            this->tableLayoutPanel2->Location = System::Drawing::Point(0, 207);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 1;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel2->Size = System::Drawing::Size(596, 95);
            this->tableLayoutPanel2->TabIndex = 22;
            // 
            // lblInvisible4
            // 
            this->lblInvisible4->BackColor = System::Drawing::Color::Red;
            this->lblInvisible4->Location = System::Drawing::Point(0, 193);
            this->lblInvisible4->Name = L"lblInvisible4";
            this->lblInvisible4->Size = System::Drawing::Size(1480, 14);
            this->lblInvisible4->TabIndex = 23;
            this->lblInvisible4->Visible = false;
            // 
            // lblInvisible3
            // 
            this->lblInvisible3->BackColor = System::Drawing::Color::Red;
            this->lblInvisible3->Location = System::Drawing::Point(0, 302);
            this->lblInvisible3->Name = L"lblInvisible3";
            this->lblInvisible3->Size = System::Drawing::Size(596, 16);
            this->lblInvisible3->TabIndex = 24;
            this->lblInvisible3->Visible = false;
            // 
            // lblInvisible6
            // 
            this->lblInvisible6->BackColor = System::Drawing::Color::Red;
            this->lblInvisible6->Location = System::Drawing::Point(0, 665);
            this->lblInvisible6->Name = L"lblInvisible6";
            this->lblInvisible6->Size = System::Drawing::Size(1480, 16);
            this->lblInvisible6->TabIndex = 25;
            this->lblInvisible6->Visible = false;
            // 
            // lblInvisible5
            // 
            this->lblInvisible5->BackColor = System::Drawing::Color::Red;
            this->lblInvisible5->Location = System::Drawing::Point(593, 206);
            this->lblInvisible5->Name = L"lblInvisible5";
            this->lblInvisible5->Size = System::Drawing::Size(15, 714);
            this->lblInvisible5->TabIndex = 26;
            this->lblInvisible5->Visible = false;
            // 
            // AdminMenuForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
                static_cast<System::Int32>(static_cast<System::Byte>(245)));
            this->ClientSize = System::Drawing::Size(1480, 920);
            this->Controls->Add(this->lblInvisible5);
            this->Controls->Add(this->lblInvisible6);
            this->Controls->Add(this->lblInvisible3);
            this->Controls->Add(this->lblInvisible4);
            this->Controls->Add(this->tableLayoutPanel2);
            this->Controls->Add(this->lblInvisible1);
            this->Controls->Add(this->topPanel);
            this->Controls->Add(this->tableLayoutPanel1);
            this->Controls->Add(this->pnlTopBar);
            this->Controls->Add(this->pnlListados);
            this->Controls->Add(this->pnlBusqueda);
            this->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"AdminMenuForm";
            this->Text = L"LYNX | Panel Administrativo";
            this->Activated += gcnew System::EventHandler(this, &AdminMenuForm::AdminMenuForm_Activated);
            this->Load += gcnew System::EventHandler(this, &AdminMenuForm::AdminMenuForm_Load);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AdminMenuForm::AdminMenuForm_KeyDown);
            this->pnlTarjetaViajes->ResumeLayout(false);
            this->pnlBusqueda->ResumeLayout(false);
            this->pnlBusqueda->PerformLayout();
            this->pnlResultado->ResumeLayout(false);
            this->pnlResultado->PerformLayout();
            this->pnlListados->ResumeLayout(false);
            this->pnlListados->PerformLayout();
            this->pnlTopBar->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
            this->topPanel->ResumeLayout(false);
            this->pnlPasswords->ResumeLayout(false);
            this->pnlPasswords->PerformLayout();
            this->pnlEstadisticas->ResumeLayout(false);
            this->pnlEstadisticas->PerformLayout();
            this->pnlTarjetaConductores->ResumeLayout(false);
            this->pnlTarjetaPasajeros->ResumeLayout(false);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel2->ResumeLayout(false);
            this->ResumeLayout(false);

        }


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


		    System::Void previewButton_Click(System::Object^ sender, System::EventArgs^ e)
		    {
			    System::Windows::Forms::MessageBox::Show(
				    L"Panel administrativo funcionando correctamente.",
				    L"LYNX"
			    );
		    }

        // 
        //  ESTADO INTERNO
        //
            bool buscandoPasajero = true;   // tab activo en busqueda
            int  listaActiva = 0;      // 0=Pasajeros, 1=Conductores, 2=Viajes

            System::Drawing::Size normalSize;
            System::Drawing::Point normalLocation;
            System::Windows::Forms::FormWindowState normalState;

        // 
        //  LOAD
        // 
            System::Void AdminMenuForm_Load(System::Object^ sender, System::EventArgs^ e)
            {
                normalSize = this->Size;
                normalLocation = this->Location;
                normalState = this->WindowState;

                // Cargar imagen de la barra LYNX
                try {
                    this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
                    this->pictureBoxIcon->Image = System::Drawing::Image::FromFile("resources/LYNX_image.png");
                    this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
                }
                catch (...) {}

                // Cargar datos del CONDUCTOR desde authManager
                //LoadConductorData();

                FormsStatus::SaveWindow(this);
                if (FormsStatus::isFullscreen) FormsStatus::ApplyWindow(this);

                LoadAdminData();
                // btnListPasajeros_Click(nullptr, nullptr);
            }

            
            void LoadAdminData()
            {
                // if no existe
                if (authManager == nullptr || tripManager == nullptr) 
                    return;

                //actualizar table layout panel de contadores
                lblNumPasajeros->Text = System::Convert::ToString(authManager->getTotalUsers());
                lblNumConductores->Text = System::Convert::ToString(authManager->getTotalDrivers());
                int totalViajes =
                    tripManager->getTotalWaiting() +
                    tripManager->getTotalActiveTrips() +
                    tripManager->getTotalHistoryTrips();
                lblNumViajes->Text = System::Convert::ToString(totalViajes);

                // izquierda de estadisticas
                lblEstPasajerosReg->Text =
                    L"Pasajeros registrados: " + System::Convert::ToString(authManager->getTotalUsers());

                lblEstConductoresReg->Text =
                    L"Conductores registrados: " + System::Convert::ToString(authManager->getTotalDrivers());

                lblEstConductoresDisp->Text =
                    L"Conductores disponibles: " + System::Convert::ToString(authManager->contarConductoresDisponibles(0));

                lblEstMontoCola->Text =
                    System::String::Format(L"Monto total en cola: S/ {0:F2}", tripManager->calcTotalEnCola());

                lblEstCola->Text =
                    tripManager->getTotalWaiting() == 0
                    ? L"Cola: sin viajes en espera"
                    : L"Cola: " + System::Convert::ToString(tripManager->getTotalWaiting()) + L" viaje(s) esperando conductor";

                // derecha de estadisticas
                lblEstViajesCompletados->Text =
                    L"Viajes completados: " + System::Convert::ToString(tripManager->contarViajesCompletados());

                lblEstViajesCurso->Text =
                    L"Viajes en curso: " + System::Convert::ToString(tripManager->contarViajesEnCurso());

                lblEstViajesCancelados->Text =
                    L"Viajes cancelados: " + System::Convert::ToString(tripManager->contarViajesCancelados());

                lblEstViajesHistorial->Text =
                    L"Viajes en historial: " + System::Convert::ToString(tripManager->getTotalHistoryTrips());

                lblEstIngresosFact->Text =
                    System::String::Format(L"Ingresos Facturados: S/ {0:F2}", tripManager->getTotalIngresosCompletados());

                lblEstGanancias->Text =
                    System::String::Format(L"Ganancia plataforma: S/ {0:F2}", tripManager->getTotalPlatformEarnings());

            }

        // 
        //  FULLSCREEN: F11, ESC sale si esta en fullscreen
        // 
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
                    this->Icon = gcnew System::Drawing::Icon("./resources/LYNX_image.ico");
                }
            }

        //
        // Click functions
        // 
            // pictureLYNXClick
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
        //  PLACEHOLDER del campo DNI
        //  Enter: borra el texto gris al hacer clic
        //  Leave: lo repone si el campo quedo vacio
        // 
    private:
        System::Void txtDni_Enter(System::Object^ sender, System::EventArgs^ e)
        {
            if (txtDniBuscar->Text == L"Ingresa el DNI del pasajero...") {
                txtDniBuscar->Text = L"";
                txtDniBuscar->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            }
        }

        System::Void txtDni_Leave(System::Object^ sender, System::EventArgs^ e)
        {
            if (txtDniBuscar->Text == L"") {
                txtDniBuscar->Text = L"Ingresa el DNI del pasajero...";
                txtDniBuscar->ForeColor = System::Drawing::Color::Gray;
            }
        }

        System::Void txtIDViajeBuscar_Enter(System::Object^ sender, System::EventArgs^ e) {
            if (txtIDViajeBuscar->Text == L"Ingresa N de ID de viaje...") {
                txtIDViajeBuscar->Text = L"";
                txtIDViajeBuscar->ForeColor = System::Drawing::Color::FromArgb(57, 107, 239);
            }
        }

        System::Void txtIDViajeBuscar_Leave(System::Object^ sender, System::EventArgs^ e) {
            if (txtIDViajeBuscar->Text == L"") {
                txtIDViajeBuscar->Text = L"Ingresa N de ID de viaje...";
                txtIDViajeBuscar->ForeColor = System::Drawing::Color::Gray;
            }
        }

        // 
        //  TABS DE BUSQUEDA
        // 
    private:
        // Tab Pasajero: habilita el campo DNI
        System::Void btnTabPasajero_Click(System::Object^ sender, System::EventArgs^ e)
        {
            buscandoPasajero = true;

            pnlResultado->BackColor = System::Drawing::Color::FromArgb(245, 250, 246);
            lblResultadoTit->ForeColor = System::Drawing::Color::FromArgb(6, 98, 70);
            lblResultadoInfo->BackColor = System::Drawing::Color::FromArgb(245, 250, 246);

            // Activar pasajero (verde)
            btnTabPasajero->BackColor = System::Drawing::Color::FromArgb(33, 181, 109);
            btnTabPasajero->ForeColor = System::Drawing::Color::White;
            btnTabPasajero->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            btnTabPasajero->FlatAppearance->BorderSize = 0;

            // Desactivar conductor
            btnTabConductor->BackColor = System::Drawing::Color::FromArgb(245, 247, 252);
            btnTabConductor->ForeColor = System::Drawing::Color::FromArgb(39, 50, 120);
            btnTabConductor->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            btnTabConductor->FlatAppearance->BorderSize = 1;

            // Habilitar campo DNI y reponer placeholder si estaba vacio
            txtDniBuscar->Enabled = true;
            if (txtDniBuscar->Text == L"" || txtDniBuscar->Text == L"(No aplica para conductores)") {
                txtDniBuscar->Text = L"Ingresa el DNI del pasajero...";
                txtDniBuscar->ForeColor = System::Drawing::Color::Gray;
            }

            // Cambiar color del boton BUSCAR A VERDE
            btnBuscar->BackColor = System::Drawing::Color::FromArgb(33, 181, 109);

            lblResultadoInfo->Text = L"Ingresa un DNI y presiona Buscar.";
        }

        // Tab Conductor: deshabilita DNI y muestra info de rating
        System::Void btnTabConductor_Click(System::Object^ sender, System::EventArgs^ e)
        {
            buscandoPasajero = false;

            pnlResultado->BackColor = System::Drawing::Color::FromArgb(217, 228, 255);
            lblResultadoTit->ForeColor = System::Drawing::Color::FromArgb(18, 92, 255);
            lblResultadoInfo->BackColor = System::Drawing::Color::FromArgb(217, 228, 255);

            // Activar conductor (azul oscuro)
            btnTabConductor->BackColor = System::Drawing::Color::FromArgb(39, 50, 120);
            btnTabConductor->ForeColor = System::Drawing::Color::White;
            btnTabConductor->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            btnTabConductor->FlatAppearance->BorderSize = 0;

            // Desactivar pasajero
            btnTabPasajero->BackColor = System::Drawing::Color::FromArgb(235, 248, 238);
            btnTabPasajero->ForeColor = System::Drawing::Color::FromArgb(33, 181, 109);
            btnTabPasajero->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            btnTabPasajero->FlatAppearance->BorderSize = 1;

            // Deshabilitar campo DNI
            txtDniBuscar->Enabled = false;
            txtDniBuscar->Text = L"(No aplica para conductores)";
            txtDniBuscar->ForeColor = System::Drawing::Color::Gray;

            // Cambiar color del boton BUSCAR A AZUL
            btnBuscar->BackColor = System::Drawing::Color::FromArgb(39, 50, 120);

            lblResultadoInfo->Text = L"Presiona 'Buscar' para ver conductores con rating >= 4.0";
        }

        // Ejecuta busqueda segun el tab activo
        System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e)
        {

            if (buscandoPasajero) {
                String^ dniText = txtDniBuscar->Text->Trim();

                if (dniText->Length == 0 || dniText == L"Ingresa el DNI del pasajero...") {
                    lblResultadoInfo->Text = L"Ingresa un DNI valido.";
                    pnlResultado->BackColor = System::Drawing::Color::FromArgb(250, 224, 220);
                    lblResultadoTit->ForeColor = System::Drawing::Color::FromArgb(255, 61, 26);
                    lblResultadoInfo->BackColor = System::Drawing::Color::FromArgb(250, 224, 220);
                    return;
                }

                if (dniText->Length != 8)
                {
                    lblResultadoInfo->Text = L"El DNI no contiene 8 digitos";
                    pnlResultado->BackColor = System::Drawing::Color::FromArgb(250, 224, 220);
                    lblResultadoTit->ForeColor = System::Drawing::Color::FromArgb(255, 61, 26);
                    lblResultadoInfo->BackColor = System::Drawing::Color::FromArgb(250, 224, 220);
                    return;
                }

                Passenger p = authManager->getUserByDni(FormsStatus::ToNormalString(dniText));
                
                if (p.getDni() == "") {
                    lblResultadoTit->Text = L"Sin resultado";
                    lblResultadoInfo->Text = L"No se encontro pasajero con DNI: " + dniText;
                    pnlResultado->BackColor = System::Drawing::Color::FromArgb(250, 224, 220);
                    lblResultadoTit->ForeColor = System::Drawing::Color::FromArgb(255, 61, 26);
                    lblResultadoInfo->BackColor = System::Drawing::Color::FromArgb(250, 224, 220);
                    return;
                }

                Trip ultimo = tripManager->getLastTripByPassenger(FormsStatus::ToNormalString(dniText));

                pnlResultado->BackColor = System::Drawing::Color::FromArgb(245, 250, 246);
                lblResultadoTit->ForeColor = System::Drawing::Color::FromArgb(6, 98, 70);
                lblResultadoInfo->BackColor = System::Drawing::Color::FromArgb(245, 250, 246);

                String^ texto = 
                    L"ID: " + FormsStatus::ToManaged(p.getPassengerId()) + L"\n" +
                    L"Nombre: " + FormsStatus::ToManaged(p.getName()) + L"\n" +
                    L"DNI: " + FormsStatus::ToManaged(p.getDni()) + L"\n" +
                    L"Rating: "+ FormsStatus::ToManaged(p.getRating(),1) + L"\n" +
                    L"Viajes: " + FormsStatus::ToManaged(p.getTotalTrips()) + L"\n" +
                    System::String::Format(L"Gasto total: S/ {0:F2}", p.getTotalSpent());

               if (ultimo.getTripId() != "") {
                    texto += L"\nUltimo viaje: " + FormsStatus::ToManaged(ultimo.toString());
                }
                else {
                    texto += L"\nSin viajes registrados.";
                }

                lblResultadoTit->Text = L"Pasajero encontrado";
                lblResultadoInfo->Text = texto;
                
            }
            else {

                String^ texto = "";
                int contador = 1;

                pnlResultado->BackColor = System::Drawing::Color::FromArgb(217, 228, 255);
                lblResultadoTit->ForeColor = System::Drawing::Color::FromArgb(18, 92, 255);
                lblResultadoInfo->BackColor = System::Drawing::Color::FromArgb(217, 228, 255);

                auto copia = authManager->copyDriverList();

                AuthManager::sortDriversByRating(copia);

                for (int i = 0; i < copia->getSize(); i++)
                {
                    Driver d = copia->get(i);

                    if (d.getRating() >= 4.0f)
                    {
                        texto += L"[" + contador.ToString() + L"] " +
                            FormsStatus::ToManaged(d.getDriverId()) + L" | " +
                            FormsStatus::ToManaged(d.getName()) + L" | DNI: " +
                            FormsStatus::ToManaged(d.getDni()) + L" | Rating: " +
                            FormsStatus::ToManaged(d.getRating(),1) + L"\n";

                        contador++;
                    }
                }

                delete copia; // liberar memoria


                lblResultadoTit->Text = L"Conductores destacados";
                lblResultadoInfo->Text = texto->Length > 0
                    ? texto
                    : L"Ningun conductor con rating >= 4.0";
            }
        }

        // 
        //  BOTONES DE LISTADO
        // 
    private:
        // Lista Pasajeros: ordenar por ID o Gasto
        System::Void btnListPasajeros_Click(System::Object^ sender, System::EventArgs^ e)
        {
            txtIDViajeBuscar->Visible = false;
            btnBuscarDeListado->Visible = false;
            btnMaximo->Visible = false;
            btnMinimo->Visible = false;

            listaActiva = 0;

            // Activar pasajero (verde)
            btnListPasajeros->BackColor = System::Drawing::Color::FromArgb(33, 181, 109);
            btnListPasajeros->ForeColor = System::Drawing::Color::White;
            btnListPasajeros->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            btnListPasajeros->FlatAppearance->BorderSize = 0;

            // Desactivar los otros dos
            btnListConductores->BackColor = System::Drawing::Color::FromArgb(245, 247, 252);
            btnListConductores->ForeColor = System::Drawing::Color::FromArgb(39, 50, 120);
            btnListConductores->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            btnListViajes->BackColor = System::Drawing::Color::FromArgb(241, 245, 255);
            btnListViajes->ForeColor = System::Drawing::Color::FromArgb(57, 107, 239);
            btnListViajes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));

            btnOrden1->Text = L"ID";
            btnOrden2->Text = L"Gasto";
            btnOrden2->Visible = true;

            // Cargar lista
            rtbListado->Text = L"==============LISTA DE PASAJEROS==============.";

            if (authManager == nullptr) return;

            if (authManager->getUserList()->isEmpty()) {
                rtbListado->Text = L"Sin pasajeros registrados.\n";
                return;
            }

            String^ texto = L"";

            for (int i = 0; i < authManager->getPassengerList()->getSize(); i++) {
                Passenger p = authManager->getPassengerList()->get(i);

                texto += L"[" + (i + 1).ToString() + L"] " + FormsStatus::ToManaged(p.getPassengerId()) +
                    L" | " + FormsStatus::ToManaged(p.getName()) + 
                    L" | DNI: " + FormsStatus::ToManaged(p.getDni()) +
                    L" | Rating: " + FormsStatus::ToManaged(p.getRating(),1) + 
                    L" | Viajes: " + FormsStatus::ToManaged(p.getTotalTrips()) +
                    L" | Gasto: S/ " + FormsStatus::ToManaged(p.getTotalSpent(),2) + L"\n";
            }

            rtbListado->Text = texto;

        }

        // Lista Conductores: ordenar por ID o Rating
        System::Void btnListConductores_Click(System::Object^ sender, System::EventArgs^ e)
        {
            txtIDViajeBuscar->Visible = false;
            btnBuscarDeListado->Visible = false;
            btnMaximo->Visible = false;
            btnMinimo->Visible = false;

            listaActiva = 1;

            // Activar conductor (azul oscuro)
            btnListConductores->BackColor = System::Drawing::Color::FromArgb(39, 50, 120);
            btnListConductores->ForeColor = System::Drawing::Color::White;
            btnListConductores->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            btnListConductores->FlatAppearance->BorderSize = 0;

            // Desactivar los otros dos
            btnListPasajeros->BackColor = System::Drawing::Color::FromArgb(235, 248, 238);
            btnListPasajeros->ForeColor = System::Drawing::Color::FromArgb(33, 181, 109);
            btnListPasajeros->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            btnListViajes->BackColor = System::Drawing::Color::FromArgb(241, 245, 255);
            btnListViajes->ForeColor = System::Drawing::Color::FromArgb(57, 107, 239);
            btnListViajes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));

            btnOrden1->Text = L"ID";
            btnOrden2->Text = L"Rating";
            btnOrden2->Visible = true;

            // Cargar lista
            rtbListado->Text = L"==============LISTA DE CONDUCTORES==============";

            if (authManager == nullptr) return;

            if (authManager->getDriverList()->isEmpty()) {
                rtbListado->Text = L"Sin conductores registrados.\n";
                return;
            }

            String^ texto = L"";

            for (int i = 0; i < authManager->getDriverList()->getSize(); i++) {
                Driver d = authManager->getDriverList()->get(i);

                texto += L"["+ (i + 1).ToString() + "]" + FormsStatus::ToManaged(d.getDriverId()) +
                    L"| " + FormsStatus::ToManaged(d.getName()) +
                    L" | DNI: " + FormsStatus::ToManaged(d.getDni()) +
                    L" |Rating: " + FormsStatus::ToManaged(d.getRating(), 1) +
                    L"| Disponible: " + FormsStatus::ToManaged(d.getIsAvailable() ? "Si" : "No") +
                    L" |Viajes: " + FormsStatus::ToManaged(d.getTotalTrips()) +
                    L"| Ganancias: S/" + FormsStatus::ToManaged(d.getTotalEarnings(), 2) + L"\n";
            }

            rtbListado->Text = texto;
        }

        // Lista Viajes: ordenar por Precio
        System::Void btnListViajes_Click(System::Object^ sender, System::EventArgs^ e)
        {
            txtIDViajeBuscar->Visible = true;
            btnBuscarDeListado->Visible = true;
            btnMaximo->Visible = false;
            btnMinimo->Visible = false;

            listaActiva = 2;

            // Activar viajes (azul admin)
            btnListViajes->BackColor = System::Drawing::Color::FromArgb(57, 107, 239);
            btnListViajes->ForeColor = System::Drawing::Color::White;
            btnListViajes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            btnListViajes->FlatAppearance->BorderSize = 0;

            // Desactivar los otros dos
            btnListPasajeros->BackColor = System::Drawing::Color::FromArgb(235, 248, 238);
            btnListPasajeros->ForeColor = System::Drawing::Color::FromArgb(33, 181, 109);
            btnListPasajeros->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            btnListConductores->BackColor = System::Drawing::Color::FromArgb(245, 247, 252);
            btnListConductores->ForeColor = System::Drawing::Color::FromArgb(39, 50, 120);
            btnListConductores->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));

            btnOrden1->Text = L"Precio";
            btnOrden2->Visible = false;   // INVISIBLEE viajes solo tiene un criterio
            
            if (txtIDViajeBuscar->Text == L"") {
                txtIDViajeBuscar->Text = L"Ingresa N de ID de viaje...";
                txtIDViajeBuscar->ForeColor = System::Drawing::Color::Gray;
            }

            
            //1
            string codigo = FormsStatus::ToNormalString(txtIDViajeBuscar->Text);

            // ... tu lógica de búsqueda ...

            // 2. LIMPIAR EL CAMPO después de buscar
            txtIDViajeBuscar->Text = L"";
            // 3. Forzar el evento Leave para que vuelva a aparecer el placeholder
            txtIDViajeBuscar_Leave(sender, e);
            

            vector<Trip> viajes = tripManager->exportAllTrips();

            if (viajes.size() == 0) {
                rtbListado->Text = L"Sin viajes registrados.";
                return;
            }

            String^ texto = L"============== LISTA DE VIAJES ==============\n\n";

            for (int i = 0; i < (int)viajes.size(); i++) {
                Trip t = viajes[i];

                texto +=
                    L"" + FormsStatus::ToManaged(t.getTripId()) +
                    L"|" + FormsStatus::ToManaged(t.getOrigin()) +
                    L"->" + FormsStatus::ToManaged(t.getDestination()) +
                    L"|Precio: S/" + FormsStatus::ToManaged(t.getPrice(), 2) +
                    L"|Pasajero DNI:" + FormsStatus::ToManaged(t.getPassengerDni()) +
                    L"|Conductor DNI:" + FormsStatus::ToManaged(t.getDriverDni()) +
                    L"\n";
            }

            rtbListado->Text = texto;

        }

        // Ordenar por criterio 1
        System::Void btnOrden1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            txtIDViajeBuscar->Visible = false;
            btnBuscarDeListado->Visible = false;
            btnMaximo->Visible = false;
            btnMinimo->Visible = false;

            // listaActiva==0 ------> por ID pasajero
            // listaActiva==1 ------> por ID conductor
            // listaActiva==2 ------> por precio de viaje
             
            if (listaActiva == 0)// FALTA
            {
                authManager->sortUsersBySpent();
                btnListPasajeros_Click(sender, e);

                btnMaximo->BackColor = System::Drawing::Color::FromArgb(36, 181, 109);
                btnMinimo->BackColor = System::Drawing::Color::FromArgb(36, 181, 109);

                btnMaximo->Visible = false;
                btnMinimo->Visible = false;
            }
            else if (listaActiva == 1) // FALTA
            {
                authManager->sortDriversByRatingHeapSort();
                btnListConductores_Click(sender, e);

                btnMaximo->BackColor = System::Drawing::Color::FromArgb(18, 92, 255);
                btnMinimo->BackColor = System::Drawing::Color::FromArgb(18, 92, 255);

                btnMaximo->Visible = false;
                btnMinimo->Visible = false;
            }
            else if (listaActiva == 2) {
                txtIDViajeBuscar->Visible = true;
                btnBuscarDeListado->Visible = true;

                vector<Trip> viajes = tripManager->getAllTripsSortedByPrice();

                // para mostrar
                // ------
                if (viajes.size() == 0) {
                    rtbListado->Text = L"Sin viajes registrados.";
                    return;
                }

                String^ texto = L"============== LISTA DE VIAJES ==============\n\n";

                for (int i = 0; i < (int)viajes.size(); i++) {
                    Trip t = viajes[i];

                    texto +=
                        L"" + FormsStatus::ToManaged(t.getTripId()) +
                        L"|" + FormsStatus::ToManaged(t.getOrigin()) +
                        L"->" + FormsStatus::ToManaged(t.getDestination()) +
                        L"|Precio: S/" + FormsStatus::ToManaged(t.getPrice(), 2)+
                        L"|Pasajero DNI:" + FormsStatus::ToManaged(t.getPassengerDni()) +
                        L"|Conductor DNI:" + FormsStatus::ToManaged(t.getDriverDni()) +
                        L"\n";
                }

                rtbListado->Text = texto;
                // ------
            }
        }

        // Buscar para ID de viaje
        System::Void btnBuscarDeListado_Click(System::Object^ sender, System::EventArgs^ e) {
            if (tripManager == nullptr) 
                return;

            String^ codigoText = txtIDViajeBuscar->Text->Trim();

            if (codigoText->Length == 0 || codigoText == L"Ingresa N de ID de viaje...") {
                rtbListado->Text = L"Ingresa un ID de viaje valido. Ejemplo: TRP-10001";
                return;
            }

            string codigo = FormsStatus::ToNormalString(codigoText);

            Trip t = tripManager->searchTripByIdBinary(codigo);

            if (t.getTripId() == "") {
                rtbListado->Text = L"No se encontro viaje con ID: " + codigoText;
                return;
            }

            rtbListado->Text =
                L"VIAJE ENCONTRADO\n\n" +
                FormsStatus::ToManaged(t.getTripId()) +
                L" | " + FormsStatus::ToManaged(t.getOrigin()) +
                L" -> " + FormsStatus::ToManaged(t.getDestination()) +
                L"\nPrecio: S/ " + FormsStatus::ToManaged(t.getPrice(), 2) +
                L"\nEstado: " + FormsStatus::ToManaged(t.getStatus()) +
                L"\nConductor: " + FormsStatus::ToManaged(t.getDriverName()) +
                L"\nDNI conductor: " + FormsStatus::ToManaged(t.getDriverDni()) +
                L"\nDNI pasajero: " + FormsStatus::ToManaged(t.getPassengerDni()) +
                L"\nFecha: " + FormsStatus::ToManaged(t.getDate());
        }

        // Ordenar por criterio 2
        System::Void btnOrden2_Click(System::Object^ sender, System::EventArgs^ e)
        {
            txtIDViajeBuscar->Visible = false;
            btnBuscarDeListado->Visible = false;

            if (authManager == nullptr) return;

            if (listaActiva == 0)
            {
                authManager->sortUsersBySpent();
                btnListPasajeros_Click(sender, e);

                btnMaximo->BackColor = System::Drawing::Color::FromArgb(36, 181, 109);
                btnMinimo->BackColor = System::Drawing::Color::FromArgb(36, 181, 109);

                btnMaximo->Visible = true;
                btnMinimo->Visible = true;
            }
            else if (listaActiva == 1)
            {
                authManager->sortDriversByRatingHeapSort();
                btnListConductores_Click(sender, e);

                btnMaximo->BackColor = System::Drawing::Color::FromArgb(18, 92, 255);
                btnMinimo->BackColor = System::Drawing::Color::FromArgb(18, 92, 255);

                btnMaximo->Visible = true;
                btnMinimo->Visible = true;
            }
        }

        // Maximo click
        System::Void btnMaximo_Click(System::Object^ sender, System::EventArgs^ e) {
            if (authManager == nullptr) return;

            if (listaActiva == 0)
            {
                Passenger p = authManager->getPassengerMaxTotalSpentHeap();

                rtbListado->Text =
                    L"\t\tPASAJERO CON MAYOR RATING\n\n" +
                    FormsStatus::ToManaged(p.getPassengerId()) + 
                    L" | " + FormsStatus::ToManaged(p.getName()) + 
                    L" | DNI: " + FormsStatus::ToManaged(p.getDni()) +
                    L" | Rating: " + FormsStatus::ToManaged(p.getRating(), 1) +
                    L" | Viajes: " + FormsStatus::ToManaged(p.getTotalTrips()) +
                    L" | Gasto: S/ " + FormsStatus::ToManaged(p.getTotalSpent(), 2) + L"\n";
            }

            if (listaActiva == 1)
            {
                Driver d = authManager->getDriverMaxRatingHeap();

                rtbListado->Text =
                    L"\t\tCONDUCTOR CON MAYOR RATING\n\n" +
                    FormsStatus::ToManaged(d.getDriverId()) + L" | " +
                    FormsStatus::ToManaged(d.getName()) + L" | DNI: " +
                    FormsStatus::ToManaged(d.getDni()) + L" | Rating: " +
                    FormsStatus::ToManaged(d.getRating(), 1);
            }
        }

        // Minimo click
        System::Void btnMinimo_Click(System::Object^ sender, System::EventArgs^ e) {
            if (authManager == nullptr) return;

            if (listaActiva == 0)
            {
                Passenger p = authManager->getPassengerMinTotalSpentHeap();

                rtbListado->Text =
                    L"\t\tPASAJERO CON MENOR RATING\n\n" +
                    FormsStatus::ToManaged(p.getPassengerId()) +
                    L" | " + FormsStatus::ToManaged(p.getName()) +
                    L" | DNI: " + FormsStatus::ToManaged(p.getDni()) +
                    L" | Rating: " + FormsStatus::ToManaged(p.getRating(), 1) +
                    L" | Viajes: " + FormsStatus::ToManaged(p.getTotalTrips()) +
                    L" | Gasto: S/ " + FormsStatus::ToManaged(p.getTotalSpent(), 2) + L"\n";
            }

            if (listaActiva == 1)
            {
                Driver d = authManager->getDriverMinRatingHeap();

                rtbListado->Text =
                    L"\t\tCONDUCTOR CON MENOR RATING\n\n" +
                    FormsStatus::ToManaged(d.getDriverId()) + L" | " +
                    FormsStatus::ToManaged(d.getName()) + L" | DNI: " +
                    FormsStatus::ToManaged(d.getDni()) + L" | Rating: " +
                    FormsStatus::ToManaged(d.getRating(), 1);
            }
        }

        // 
        //  CARGAR PASSWORDS DESDE ARCHIVO BINARIO (( YA ESTA ; cambiar formato nomas ))
        // 
        System::Void btnCargarPasswords_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (authManager == nullptr) 
                return;

            // Generar el binario con los datos actuales
            authManager->savePasswordsBinary();

            // Leer el binario y construir el texto a mostrar
            auto previews = authManager->readPasswordsBinary();

            rtbPasswords->Clear();

            for (int i = 0; i < (int)previews.size(); i++) {
                if (previews[i].tipo == "Passenger")
                {
                    rtbPasswords->SelectionColor = System::Drawing::Color::FromArgb(36, 181, 109);
                    previews[i].tipo = "Pasajero";
                }
                else if (previews[i].tipo == "Driver")
                {
                    rtbPasswords->SelectionColor = System::Drawing::Color::FromArgb(18, 92, 255);
                    previews[i].tipo = "Conductor";
                }

                // SOLO el tipo para que se pinte con el color elegido
                rtbPasswords->AppendText(gcnew String(previews[i].tipo.c_str()));

                rtbPasswords->SelectionColor = System::Drawing::Color::Black;

                std::string linea = " | "
                    + previews[i].id + " | "
                    + previews[i].dni + " | "
                    + previews[i].password + "\n";

                rtbPasswords->AppendText(gcnew String(linea.c_str()));
            }

            if (previews.size() == 0) {
                rtbPasswords->Text = L"No hay passwords registrados.";
            }
        }

        //
        // Actived Component: es un evento de Windows Forms que se dispara cada vez que el form se convierte en la ventana activa
        //
        System::Void AdminMenuForm_Activated(System::Object^ sender, System::EventArgs^ e) {

            LoadAdminData();
        }








        




};
}
