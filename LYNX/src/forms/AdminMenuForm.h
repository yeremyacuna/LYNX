#pragma once
#include "../library/FormsStatus.h"
#include <windows.h>

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
            if (components) delete components;
        }

        //  DECLARACION DE CONTROLES

        // Barra LYNX
    private: System::Windows::Forms::Panel^ pnlTopBar;
    private: System::Windows::Forms::PictureBox^ pictureBoxIcon;
    private: System::Windows::Forms::Label^ lblLYNX;

           // Titulo Panel Administrador
    private: System::Windows::Forms::Panel^ pnlTitulo;
    private: System::Windows::Forms::Label^ lblTituloPrincipal;
	private:
		AuthManager* authManager = nullptr;
		TripManager* tripManager = nullptr;
		

           // Cuadros de conteo
    private: System::Windows::Forms::Panel^ pnlTarjetaPasajeros;
    private: System::Windows::Forms::Label^ lblTitPasajeros;
    private: System::Windows::Forms::Label^ lblNumPasajeros;

    private: System::Windows::Forms::Panel^ pnlTarjetaConductores;
    private: System::Windows::Forms::Label^ lblTitConductores;
    private: System::Windows::Forms::Label^ lblNumConductores;

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
    private: System::Windows::Forms::Label^ lblResultadoInfo;

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
    private: System::Windows::Forms::Panel^ pnlPasswords;
    private: System::Windows::Forms::Label^ lblTitPasswords;
    private: System::Windows::Forms::Button^ btnCargarPasswords;
    private: System::Windows::Forms::RichTextBox^ rtbPasswords;

           // Panel estadisticas generales
    private: System::Windows::Forms::Panel^ pnlEstadisticas;
    private: System::Windows::Forms::Label^ lblTitEstadisticas;
    private: System::Windows::Forms::Label^ lblEstPasajerosReg;
    private: System::Windows::Forms::Label^ lblEstConductoresReg;
    private: System::Windows::Forms::Label^ lblEstConductoresDisp;
    private: System::Windows::Forms::Label^ lblEstViajesEspera;
    private: System::Windows::Forms::Label^ lblEstViajesActivos;
    private: System::Windows::Forms::Label^ lblEstViajesHistorial;
    private: System::Windows::Forms::Label^ lblEstGanancias;
    private: System::Windows::Forms::Label^ lblEstMontoCola;
    private: System::Windows::Forms::Label^ lblEstViajesCurso;
    private: System::Windows::Forms::Label^ lblEstCola;

    private: System::ComponentModel::Container^ components;

           //  INICIALIZACION DE COMPONENTES
    private:
#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());

            // COMPONENTES
            this->pnlTopBar = (gcnew System::Windows::Forms::Panel());
            this->pictureBoxIcon = (gcnew System::Windows::Forms::PictureBox());
            this->lblLYNX = (gcnew System::Windows::Forms::Label());
            this->pnlTitulo = (gcnew System::Windows::Forms::Panel());
            this->lblTituloPrincipal = (gcnew System::Windows::Forms::Label());
            this->pnlTarjetaPasajeros = (gcnew System::Windows::Forms::Panel());
            this->lblTitPasajeros = (gcnew System::Windows::Forms::Label());
            this->lblNumPasajeros = (gcnew System::Windows::Forms::Label());
            this->pnlTarjetaConductores = (gcnew System::Windows::Forms::Panel());
            this->lblTitConductores = (gcnew System::Windows::Forms::Label());
            this->lblNumConductores = (gcnew System::Windows::Forms::Label());
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
            this->lblResultadoTit = (gcnew System::Windows::Forms::Label());
            this->lblResultadoInfo = (gcnew System::Windows::Forms::Label());
            this->pnlListados = (gcnew System::Windows::Forms::Panel());
            this->lblTitListados = (gcnew System::Windows::Forms::Label());
            this->btnListPasajeros = (gcnew System::Windows::Forms::Button());
            this->btnListConductores = (gcnew System::Windows::Forms::Button());
            this->btnListViajes = (gcnew System::Windows::Forms::Button());
            this->lblOrdenarPor = (gcnew System::Windows::Forms::Label());
            this->btnOrden1 = (gcnew System::Windows::Forms::Button());
            this->btnOrden2 = (gcnew System::Windows::Forms::Button());
            this->rtbListado = (gcnew System::Windows::Forms::RichTextBox());
            this->pnlPasswords = (gcnew System::Windows::Forms::Panel());
            this->lblTitPasswords = (gcnew System::Windows::Forms::Label());
            this->btnCargarPasswords = (gcnew System::Windows::Forms::Button());
            this->rtbPasswords = (gcnew System::Windows::Forms::RichTextBox());
            this->pnlEstadisticas = (gcnew System::Windows::Forms::Panel());
            this->lblTitEstadisticas = (gcnew System::Windows::Forms::Label());
            this->lblEstPasajerosReg = (gcnew System::Windows::Forms::Label());
            this->lblEstConductoresReg = (gcnew System::Windows::Forms::Label());
            this->lblEstConductoresDisp = (gcnew System::Windows::Forms::Label());
            this->lblEstViajesEspera = (gcnew System::Windows::Forms::Label());
            this->lblEstViajesActivos = (gcnew System::Windows::Forms::Label());
            this->lblEstViajesHistorial = (gcnew System::Windows::Forms::Label());
            this->lblEstGanancias = (gcnew System::Windows::Forms::Label());
            this->lblEstMontoCola = (gcnew System::Windows::Forms::Label());
            this->lblEstViajesCurso = (gcnew System::Windows::Forms::Label());
            this->lblEstCola = (gcnew System::Windows::Forms::Label());

            // SuspendLayout para todos los panels
            this->pnlTopBar->SuspendLayout();
            this->pnlTitulo->SuspendLayout();
            this->pnlTarjetaPasajeros->SuspendLayout();
            this->pnlTarjetaConductores->SuspendLayout();
            this->pnlTarjetaViajes->SuspendLayout();
            this->pnlBusqueda->SuspendLayout();
            this->pnlResultado->SuspendLayout();
            this->pnlListados->SuspendLayout();
            this->pnlPasswords->SuspendLayout();
            this->pnlEstadisticas->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->BeginInit();
            this->SuspendLayout();

            // 
            // pnlTopBar: barra superior LYNX
            // Dock Top para expansion con F11
            // 
            this->pnlTopBar->Dock = System::Windows::Forms::DockStyle::Top;
            this->pnlTopBar->BackColor = System::Drawing::Color::FromArgb(6, 98, 70);
            this->pnlTopBar->Controls->Add(this->pictureBoxIcon);
            this->pnlTopBar->Controls->Add(this->lblLYNX);
            this->pnlTopBar->Location = System::Drawing::Point(0, 0);
            this->pnlTopBar->Name = L"pnlTopBar";
            this->pnlTopBar->Size = System::Drawing::Size(1480, 78);
            this->pnlTopBar->TabIndex = 0;

            // pictureBoxIcon: logo LYNX en la barra
            this->pictureBoxIcon->BackColor = System::Drawing::Color::Transparent;
            this->pictureBoxIcon->Location = System::Drawing::Point(22, -27);
            this->pictureBoxIcon->Name = L"pictureBoxIcon";
            this->pictureBoxIcon->Size = System::Drawing::Size(75, 129);
            this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBoxIcon->TabIndex = 1;
            this->pictureBoxIcon->TabStop = false;

            // lblLYNX: nombre de la app en la barra
            this->lblLYNX->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 22, System::Drawing::FontStyle::Bold));
            this->lblLYNX->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->lblLYNX->Location = System::Drawing::Point(91, 18);
            this->lblLYNX->Name = L"lblLYNX";
            this->lblLYNX->Size = System::Drawing::Size(150, 40);
            this->lblLYNX->TabIndex = 0;
            this->lblLYNX->Text = L"LYNX";

            // 
            // pnlTitulo: "Panel Administrativo"
            // 
            this->pnlTitulo->Dock = System::Windows::Forms::DockStyle::Top;
            this->pnlTitulo->BackColor = System::Drawing::Color::FromArgb(24, 28, 34);
            this->pnlTitulo->Controls->Add(this->lblTituloPrincipal);
            this->pnlTitulo->Location = System::Drawing::Point(0, 78);
            this->pnlTitulo->Name = L"pnlTitulo";
            this->pnlTitulo->Size = System::Drawing::Size(1480, 72);
            this->pnlTitulo->TabIndex = 1;

            // lblTituloPrincipal
            this->lblTituloPrincipal->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 24, System::Drawing::FontStyle::Bold));
            this->lblTituloPrincipal->ForeColor = System::Drawing::Color::White;
            this->lblTituloPrincipal->Location = System::Drawing::Point(30, 14);
            this->lblTituloPrincipal->Name = L"lblTituloPrincipal";
            this->lblTituloPrincipal->Size = System::Drawing::Size(600, 44);
            this->lblTituloPrincipal->TabIndex = 0;
            this->lblTituloPrincipal->Text = L"Panel Administrativo";

            // 
            // TARJETA: Pasajeros
            // 
            this->pnlTarjetaPasajeros->BackColor = System::Drawing::Color::White;
            this->pnlTarjetaPasajeros->Controls->Add(this->lblTitPasajeros);
            this->pnlTarjetaPasajeros->Controls->Add(this->lblNumPasajeros);
            this->pnlTarjetaPasajeros->Location = System::Drawing::Point(30, 168);
            this->pnlTarjetaPasajeros->Name = L"pnlTarjetaPasajeros";
            this->pnlTarjetaPasajeros->Size = System::Drawing::Size(180, 100);
            this->pnlTarjetaPasajeros->TabIndex = 2;

            this->lblTitPasajeros->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11, System::Drawing::FontStyle::Bold));
            this->lblTitPasajeros->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->lblTitPasajeros->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblTitPasajeros->Location = System::Drawing::Point(0, 14);
            this->lblTitPasajeros->Name = L"lblTitPasajeros";
            this->lblTitPasajeros->Size = System::Drawing::Size(180, 26);
            this->lblTitPasajeros->TabIndex = 0;
            this->lblTitPasajeros->Text = L"Pasajeros";

            this->lblNumPasajeros->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 26, System::Drawing::FontStyle::Bold));
            this->lblNumPasajeros->ForeColor = System::Drawing::Color::FromArgb(33, 181, 109);
            this->lblNumPasajeros->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblNumPasajeros->Location = System::Drawing::Point(0, 46);
            this->lblNumPasajeros->Name = L"lblNumPasajeros";
            this->lblNumPasajeros->Size = System::Drawing::Size(180, 44);
            this->lblNumPasajeros->TabIndex = 1;
            this->lblNumPasajeros->Text = L"0";

            // 
            // TARJETA: Conductores
            // 
            this->pnlTarjetaConductores->BackColor = System::Drawing::Color::White;
            this->pnlTarjetaConductores->Controls->Add(this->lblTitConductores);
            this->pnlTarjetaConductores->Controls->Add(this->lblNumConductores);
            this->pnlTarjetaConductores->Location = System::Drawing::Point(225, 168);
            this->pnlTarjetaConductores->Name = L"pnlTarjetaConductores";
            this->pnlTarjetaConductores->Size = System::Drawing::Size(180, 100);
            this->pnlTarjetaConductores->TabIndex = 3;

            this->lblTitConductores->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11, System::Drawing::FontStyle::Bold));
            this->lblTitConductores->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->lblTitConductores->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblTitConductores->Location = System::Drawing::Point(0, 14);
            this->lblTitConductores->Name = L"lblTitConductores";
            this->lblTitConductores->Size = System::Drawing::Size(180, 26);
            this->lblTitConductores->TabIndex = 0;
            this->lblTitConductores->Text = L"Conductores";

            this->lblNumConductores->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 26, System::Drawing::FontStyle::Bold));
            this->lblNumConductores->ForeColor = System::Drawing::Color::FromArgb(39, 50, 120);
            this->lblNumConductores->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblNumConductores->Location = System::Drawing::Point(0, 46);
            this->lblNumConductores->Name = L"lblNumConductores";
            this->lblNumConductores->Size = System::Drawing::Size(180, 44);
            this->lblNumConductores->TabIndex = 1;
            this->lblNumConductores->Text = L"0";

            // 
            // TARJETA: Viajes
            // 
            this->pnlTarjetaViajes->BackColor = System::Drawing::Color::White;
            this->pnlTarjetaViajes->Controls->Add(this->lblTitViajes);
            this->pnlTarjetaViajes->Controls->Add(this->lblNumViajes);
            this->pnlTarjetaViajes->Location = System::Drawing::Point(420, 168);
            this->pnlTarjetaViajes->Name = L"pnlTarjetaViajes";
            this->pnlTarjetaViajes->Size = System::Drawing::Size(180, 100);
            this->pnlTarjetaViajes->TabIndex = 4;

            this->lblTitViajes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11, System::Drawing::FontStyle::Bold));
            this->lblTitViajes->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->lblTitViajes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblTitViajes->Location = System::Drawing::Point(0, 14);
            this->lblTitViajes->Name = L"lblTitViajes";
            this->lblTitViajes->Size = System::Drawing::Size(180, 26);
            this->lblTitViajes->TabIndex = 0;
            this->lblTitViajes->Text = L"Viajes";

            this->lblNumViajes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 26, System::Drawing::FontStyle::Bold));
            this->lblNumViajes->ForeColor = System::Drawing::Color::FromArgb(57, 107, 239);
            this->lblNumViajes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblNumViajes->Location = System::Drawing::Point(0, 46);
            this->lblNumViajes->Name = L"lblNumViajes";
            this->lblNumViajes->Size = System::Drawing::Size(180, 44);
            this->lblNumViajes->TabIndex = 1;
            this->lblNumViajes->Text = L"0";

            // 
            // pnlBusqueda
            // Tab Pasajero busca por DNI, tab Conductor muestra rating >= 4.0
            // 
            this->pnlBusqueda->BackColor = System::Drawing::Color::White;
            this->pnlBusqueda->Controls->Add(this->lblTitBusqueda);
            this->pnlBusqueda->Controls->Add(this->btnTabPasajero);
            this->pnlBusqueda->Controls->Add(this->btnTabConductor);
            this->pnlBusqueda->Controls->Add(this->txtDniBuscar);
            this->pnlBusqueda->Controls->Add(this->btnBuscar);
            this->pnlBusqueda->Controls->Add(this->pnlResultado);
            this->pnlBusqueda->Location = System::Drawing::Point(30, 288);
            this->pnlBusqueda->Name = L"pnlBusqueda";
            this->pnlBusqueda->Size = System::Drawing::Size(580, 330);
            this->pnlBusqueda->TabIndex = 5;

            // Titulo del panel busqueda
            this->lblTitBusqueda->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13, System::Drawing::FontStyle::Bold));
            this->lblTitBusqueda->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->lblTitBusqueda->Location = System::Drawing::Point(15, 14);
            this->lblTitBusqueda->Name = L"lblTitBusqueda";
            this->lblTitBusqueda->AutoSize = true;
            this->lblTitBusqueda->TabIndex = 0;
            this->lblTitBusqueda->Text = L"Buscar usuario";

            // btnTabPasajero: activo por defecto
            this->btnTabPasajero->BackColor = System::Drawing::Color::FromArgb(33, 181, 109);
            this->btnTabPasajero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnTabPasajero->FlatAppearance->BorderSize = 0;
            this->btnTabPasajero->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            this->btnTabPasajero->ForeColor = System::Drawing::Color::White;
            this->btnTabPasajero->Location = System::Drawing::Point(15, 50);
            this->btnTabPasajero->Name = L"btnTabPasajero";
            this->btnTabPasajero->Size = System::Drawing::Size(160, 32);
            this->btnTabPasajero->TabIndex = 1;
            this->btnTabPasajero->Text = L"Pasajero  (DNI)";
            this->btnTabPasajero->UseVisualStyleBackColor = false;
            this->btnTabPasajero->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnTabPasajero->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnTabPasajero_Click);

            // btnTabConductor: inactivo por defecto
            this->btnTabConductor->BackColor = System::Drawing::Color::FromArgb(245, 247, 252);
            this->btnTabConductor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnTabConductor->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(39, 50, 120);
            this->btnTabConductor->FlatAppearance->BorderSize = 1;
            this->btnTabConductor->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->btnTabConductor->ForeColor = System::Drawing::Color::FromArgb(39, 50, 120);
            this->btnTabConductor->Location = System::Drawing::Point(185, 50);
            this->btnTabConductor->Name = L"btnTabConductor";
            this->btnTabConductor->Size = System::Drawing::Size(175, 32);
            this->btnTabConductor->TabIndex = 2;
            this->btnTabConductor->Text = L"Conductor  (Rating)";
            this->btnTabConductor->UseVisualStyleBackColor = false;
            this->btnTabConductor->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnTabConductor->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnTabConductor_Click);

            // txtDniBuscar: campo DNI con un texto gris que desaparece al hacer click, esta simulado con los eventos Enter/Leave
            this->txtDniBuscar->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10));
            this->txtDniBuscar->ForeColor = System::Drawing::Color::Gray;
            this->txtDniBuscar->Location = System::Drawing::Point(15, 98);
            this->txtDniBuscar->Name = L"txtDniBuscar";
            this->txtDniBuscar->Size = System::Drawing::Size(400, 28);
            this->txtDniBuscar->TabIndex = 3;
            this->txtDniBuscar->Text = L"Ingresa el DNI del pasajero...";
            this->txtDniBuscar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txtDniBuscar->Enter += gcnew System::EventHandler(this, &AdminMenuForm::txtDni_Enter);
            this->txtDniBuscar->Leave += gcnew System::EventHandler(this, &AdminMenuForm::txtDni_Leave);

            // btnBuscar: mismo color que el tab activo (pasajero verde por defecto)
            this->btnBuscar->BackColor = System::Drawing::Color::FromArgb(33, 181, 109);
            this->btnBuscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnBuscar->FlatAppearance->BorderSize = 0;
            this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            this->btnBuscar->ForeColor = System::Drawing::Color::White;
            this->btnBuscar->Location = System::Drawing::Point(425, 98);
            this->btnBuscar->Name = L"btnBuscar";
            this->btnBuscar->Size = System::Drawing::Size(130, 28);
            this->btnBuscar->TabIndex = 4;
            this->btnBuscar->Text = L"Buscar";
            this->btnBuscar->UseVisualStyleBackColor = false;
            this->btnBuscar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnBuscar->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnBuscar_Click);

            // pnlResultado: cuadro donde aparece el resultado de la busqueda
            this->pnlResultado->BackColor = System::Drawing::Color::FromArgb(245, 250, 246);
            this->pnlResultado->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->pnlResultado->Controls->Add(this->lblResultadoTit);
            this->pnlResultado->Controls->Add(this->lblResultadoInfo);
            this->pnlResultado->Location = System::Drawing::Point(15, 140);
            this->pnlResultado->Name = L"pnlResultado";
            this->pnlResultado->Size = System::Drawing::Size(550, 175);
            this->pnlResultado->TabIndex = 5;

            this->lblResultadoTit->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
            this->lblResultadoTit->ForeColor = System::Drawing::Color::FromArgb(6, 98, 70);
            this->lblResultadoTit->Location = System::Drawing::Point(8, 8);
            this->lblResultadoTit->Name = L"lblResultadoTit";
            this->lblResultadoTit->AutoSize = true;
            this->lblResultadoTit->TabIndex = 0;
            this->lblResultadoTit->Text = L"Resultado:";

            this->lblResultadoInfo->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblResultadoInfo->ForeColor = System::Drawing::Color::FromArgb(50, 60, 55);
            this->lblResultadoInfo->Location = System::Drawing::Point(8, 28);
            this->lblResultadoInfo->Name = L"lblResultadoInfo";
            this->lblResultadoInfo->Size = System::Drawing::Size(535, 140);
            this->lblResultadoInfo->TabIndex = 1;
            this->lblResultadoInfo->Text = L"Ingresa un DNI y presiona Buscar.";

            // 
            // pnlListados: panel con Pasajeros/Conductores/Viajes
            // "Ordenar por" cambia segun la lista activa
            // RichTextBox con scroll vertical para los datos
            // 
            this->pnlListados->BackColor = System::Drawing::Color::White;
            this->pnlListados->Controls->Add(this->lblTitListados);
            this->pnlListados->Controls->Add(this->btnListPasajeros);
            this->pnlListados->Controls->Add(this->btnListConductores);
            this->pnlListados->Controls->Add(this->btnListViajes);
            this->pnlListados->Controls->Add(this->lblOrdenarPor);
            this->pnlListados->Controls->Add(this->btnOrden1);
            this->pnlListados->Controls->Add(this->btnOrden2);
            this->pnlListados->Controls->Add(this->rtbListado);
            this->pnlListados->Location = System::Drawing::Point(630, 168);
            this->pnlListados->Name = L"pnlListados";
            this->pnlListados->Size = System::Drawing::Size(832, 450);
            this->pnlListados->TabIndex = 6;

            // Titulo del panel listados
            this->lblTitListados->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13, System::Drawing::FontStyle::Bold));
            this->lblTitListados->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->lblTitListados->Location = System::Drawing::Point(15, 12);
            this->lblTitListados->Name = L"lblTitListados";
            this->lblTitListados->AutoSize = true;
            this->lblTitListados->TabIndex = 0;
            this->lblTitListados->Text = L"Listado de usuarios y viajes";

            // btnListPasajeros: color pasajero activo por defecto
            this->btnListPasajeros->BackColor = System::Drawing::Color::FromArgb(33, 181, 109);
            this->btnListPasajeros->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnListPasajeros->FlatAppearance->BorderSize = 0;
            this->btnListPasajeros->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            this->btnListPasajeros->ForeColor = System::Drawing::Color::White;
            this->btnListPasajeros->Location = System::Drawing::Point(15, 50);
            this->btnListPasajeros->Name = L"btnListPasajeros";
            this->btnListPasajeros->Size = System::Drawing::Size(115, 32);
            this->btnListPasajeros->TabIndex = 1;
            this->btnListPasajeros->Text = L"Pasajeros";
            this->btnListPasajeros->UseVisualStyleBackColor = false;
            this->btnListPasajeros->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnListPasajeros->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnListPasajeros_Click);

            // btnListConductores: color conductor inactivo
            this->btnListConductores->BackColor = System::Drawing::Color::FromArgb(245, 247, 252);
            this->btnListConductores->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnListConductores->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(39, 50, 120);
            this->btnListConductores->FlatAppearance->BorderSize = 1;
            this->btnListConductores->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->btnListConductores->ForeColor = System::Drawing::Color::FromArgb(39, 50, 120);
            this->btnListConductores->Location = System::Drawing::Point(140, 50);
            this->btnListConductores->Name = L"btnListConductores";
            this->btnListConductores->Size = System::Drawing::Size(115, 32);
            this->btnListConductores->TabIndex = 2;
            this->btnListConductores->Text = L"Conductores";
            this->btnListConductores->UseVisualStyleBackColor = false;
            this->btnListConductores->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnListConductores->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnListConductores_Click);

            // btnListViajes: color admin inactivo
            this->btnListViajes->BackColor = System::Drawing::Color::FromArgb(241, 245, 255);
            this->btnListViajes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnListViajes->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(57, 107, 239);
            this->btnListViajes->FlatAppearance->BorderSize = 1;
            this->btnListViajes->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->btnListViajes->ForeColor = System::Drawing::Color::FromArgb(57, 107, 239);
            this->btnListViajes->Location = System::Drawing::Point(265, 50);
            this->btnListViajes->Name = L"btnListViajes";
            this->btnListViajes->Size = System::Drawing::Size(95, 32);
            this->btnListViajes->TabIndex = 3;
            this->btnListViajes->Text = L"Viajes";
            this->btnListViajes->UseVisualStyleBackColor = false;
            this->btnListViajes->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnListViajes->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnListViajes_Click);

            // lblOrdenarPor
            this->lblOrdenarPor->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblOrdenarPor->ForeColor = System::Drawing::Color::FromArgb(80, 80, 80);
            this->lblOrdenarPor->Location = System::Drawing::Point(15, 96);
            this->lblOrdenarPor->Name = L"lblOrdenarPor";
            this->lblOrdenarPor->AutoSize = true;
            this->lblOrdenarPor->TabIndex = 4;
            this->lblOrdenarPor->Text = L"Ordenar por:";

            // btnOrden1
            this->btnOrden1->BackColor = System::Drawing::Color::FromArgb(24, 28, 34);
            this->btnOrden1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnOrden1->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnOrden1->FlatAppearance->BorderSize = 1;
            this->btnOrden1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
            this->btnOrden1->ForeColor = System::Drawing::Color::White;
            this->btnOrden1->Location = System::Drawing::Point(120, 92);
            this->btnOrden1->Name = L"btnOrden1";
            this->btnOrden1->Size = System::Drawing::Size(75, 26);
            this->btnOrden1->TabIndex = 5;
            this->btnOrden1->Text = L"ID";
            this->btnOrden1->UseVisualStyleBackColor = false;
            this->btnOrden1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnOrden1->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnOrden1_Click);

            // btnOrden2
            this->btnOrden2->BackColor = System::Drawing::Color::FromArgb(24, 28, 34);
            this->btnOrden2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnOrden2->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnOrden2->FlatAppearance->BorderSize = 1;
            this->btnOrden2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 8, System::Drawing::FontStyle::Bold));
            this->btnOrden2->ForeColor = System::Drawing::Color::White;
            this->btnOrden2->Location = System::Drawing::Point(205, 92);
            this->btnOrden2->Name = L"btnOrden2";
            this->btnOrden2->Size = System::Drawing::Size(75, 26);
            this->btnOrden2->TabIndex = 6;
            this->btnOrden2->Text = L"Gasto";
            this->btnOrden2->UseVisualStyleBackColor = false;
            this->btnOrden2->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnOrden2->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnOrden2_Click);

            // rtbListado: area scrolleable con los datos listados
            this->rtbListado->BackColor = System::Drawing::Color::FromArgb(248, 250, 249);
            this->rtbListado->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtbListado->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
            this->rtbListado->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->rtbListado->Location = System::Drawing::Point(15, 130);
            this->rtbListado->Name = L"rtbListado";
            this->rtbListado->ReadOnly = true;
            this->rtbListado->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
            this->rtbListado->Size = System::Drawing::Size(800, 305);
            this->rtbListado->TabIndex = 7;
            this->rtbListado->Text = L"";

            // 
            // pnlPasswords
            // 
            this->pnlPasswords->BackColor = System::Drawing::Color::White;
            this->pnlPasswords->Controls->Add(this->lblTitPasswords);
            this->pnlPasswords->Controls->Add(this->btnCargarPasswords);
            this->pnlPasswords->Controls->Add(this->rtbPasswords);
            this->pnlPasswords->Location = System::Drawing::Point(30, 638);
            this->pnlPasswords->Name = L"pnlPasswords";
            this->pnlPasswords->Size = System::Drawing::Size(580, 210);
            this->pnlPasswords->TabIndex = 7;

            this->lblTitPasswords->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13, System::Drawing::FontStyle::Bold));
            this->lblTitPasswords->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->lblTitPasswords->Location = System::Drawing::Point(15, 14);
            this->lblTitPasswords->Name = L"lblTitPasswords";
            this->lblTitPasswords->AutoSize = true;
            this->lblTitPasswords->TabIndex = 0;
            this->lblTitPasswords->Text = L"Passwords en binario";

            // btnCargarPasswords
            this->btnCargarPasswords->BackColor = System::Drawing::Color::FromArgb(24, 28, 34);
            this->btnCargarPasswords->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCargarPasswords->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnCargarPasswords->FlatAppearance->BorderSize = 1;
            this->btnCargarPasswords->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Bold));
            this->btnCargarPasswords->ForeColor = System::Drawing::Color::White;
            this->btnCargarPasswords->Location = System::Drawing::Point(500, 10);
            this->btnCargarPasswords->Name = L"btnCargarPasswords";
            this->btnCargarPasswords->Size = System::Drawing::Size(68, 28);
            this->btnCargarPasswords->TabIndex = 1;
            this->btnCargarPasswords->Text = L"Cargar";
            this->btnCargarPasswords->UseVisualStyleBackColor = false;
            this->btnCargarPasswords->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnCargarPasswords->Click += gcnew System::EventHandler(this, &AdminMenuForm::btnCargarPasswords_Click);

            this->rtbPasswords->BackColor = System::Drawing::Color::FromArgb(248, 250, 249);
            this->rtbPasswords->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtbPasswords->Font = (gcnew System::Drawing::Font(L"Consolas", 8));
            this->rtbPasswords->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->rtbPasswords->Location = System::Drawing::Point(15, 52);
            this->rtbPasswords->Name = L"rtbPasswords";
            this->rtbPasswords->ReadOnly = true;
            this->rtbPasswords->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
            this->rtbPasswords->Size = System::Drawing::Size(550, 148);
            this->rtbPasswords->TabIndex = 2;
            this->rtbPasswords->Text = L"Presiona 'Cargar' para leer el archivo binario de passwords.";

            // 
            // pnlEstadisticas
            // 
            this->pnlEstadisticas->BackColor = System::Drawing::Color::White;
            this->pnlEstadisticas->Controls->Add(this->lblTitEstadisticas);
            this->pnlEstadisticas->Controls->Add(this->lblEstPasajerosReg);
            this->pnlEstadisticas->Controls->Add(this->lblEstConductoresReg);
            this->pnlEstadisticas->Controls->Add(this->lblEstConductoresDisp);
            this->pnlEstadisticas->Controls->Add(this->lblEstViajesEspera);
            this->pnlEstadisticas->Controls->Add(this->lblEstViajesActivos);
            this->pnlEstadisticas->Controls->Add(this->lblEstViajesHistorial);
            this->pnlEstadisticas->Controls->Add(this->lblEstGanancias);
            this->pnlEstadisticas->Controls->Add(this->lblEstMontoCola);
            this->pnlEstadisticas->Controls->Add(this->lblEstViajesCurso);
            this->pnlEstadisticas->Controls->Add(this->lblEstCola);
            this->pnlEstadisticas->Location = System::Drawing::Point(630, 638);
            this->pnlEstadisticas->Name = L"pnlEstadisticas";
            this->pnlEstadisticas->Size = System::Drawing::Size(832, 210);
            this->pnlEstadisticas->TabIndex = 8;

            this->lblTitEstadisticas->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13, System::Drawing::FontStyle::Bold));
            this->lblTitEstadisticas->ForeColor = System::Drawing::Color::FromArgb(24, 27, 31);
            this->lblTitEstadisticas->Location = System::Drawing::Point(15, 14);
            this->lblTitEstadisticas->Name = L"lblTitEstadisticas";
            this->lblTitEstadisticas->AutoSize = true;
            this->lblTitEstadisticas->TabIndex = 0;
            this->lblTitEstadisticas->Text = L"Estadisticas generales";

            // Columna izquierda de estadisticas
            this->lblEstPasajerosReg->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblEstPasajerosReg->ForeColor = System::Drawing::Color::FromArgb(40, 55, 48);
            this->lblEstPasajerosReg->Location = System::Drawing::Point(15, 50);
            this->lblEstPasajerosReg->Name = L"lblEstPasajerosReg";
            this->lblEstPasajerosReg->AutoSize = true;
            this->lblEstPasajerosReg->TabIndex = 1;
            this->lblEstPasajerosReg->Text = L"Usuarios registrados:       0";

            this->lblEstConductoresReg->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblEstConductoresReg->ForeColor = System::Drawing::Color::FromArgb(40, 55, 48);
            this->lblEstConductoresReg->Location = System::Drawing::Point(15, 74);
            this->lblEstConductoresReg->Name = L"lblEstConductoresReg";
            this->lblEstConductoresReg->AutoSize = true;
            this->lblEstConductoresReg->TabIndex = 2;
            this->lblEstConductoresReg->Text = L"Conductores registrados:    0";

            this->lblEstConductoresDisp->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblEstConductoresDisp->ForeColor = System::Drawing::Color::FromArgb(40, 55, 48);
            this->lblEstConductoresDisp->Location = System::Drawing::Point(15, 98);
            this->lblEstConductoresDisp->Name = L"lblEstConductoresDisp";
            this->lblEstConductoresDisp->AutoSize = true;
            this->lblEstConductoresDisp->TabIndex = 3;
            this->lblEstConductoresDisp->Text = L"Conductores disponibles:    0";

            this->lblEstViajesEspera->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblEstViajesEspera->ForeColor = System::Drawing::Color::FromArgb(40, 55, 48);
            this->lblEstViajesEspera->Location = System::Drawing::Point(15, 122);
            this->lblEstViajesEspera->Name = L"lblEstViajesEspera";
            this->lblEstViajesEspera->AutoSize = true;
            this->lblEstViajesEspera->TabIndex = 4;
            this->lblEstViajesEspera->Text = L"Viajes en espera:           0";

            this->lblEstMontoCola->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblEstMontoCola->ForeColor = System::Drawing::Color::FromArgb(40, 55, 48);
            this->lblEstMontoCola->Location = System::Drawing::Point(15, 146);
            this->lblEstMontoCola->Name = L"lblEstMontoCola";
            this->lblEstMontoCola->AutoSize = true;
            this->lblEstMontoCola->TabIndex = 5;
            this->lblEstMontoCola->Text = L"Monto total en cola:  S/ 0.00";

            this->lblEstCola->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblEstCola->ForeColor = System::Drawing::Color::FromArgb(40, 55, 48);
            this->lblEstCola->Location = System::Drawing::Point(15, 170);
            this->lblEstCola->Name = L"lblEstCola";
            this->lblEstCola->AutoSize = true;
            this->lblEstCola->TabIndex = 6;
            this->lblEstCola->Text = L"Cola: [--] Sin viajes en espera";

            // Columna derecha de estadisticas
            this->lblEstViajesActivos->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblEstViajesActivos->ForeColor = System::Drawing::Color::FromArgb(40, 55, 48);
            this->lblEstViajesActivos->Location = System::Drawing::Point(430, 50);
            this->lblEstViajesActivos->Name = L"lblEstViajesActivos";
            this->lblEstViajesActivos->AutoSize = true;
            this->lblEstViajesActivos->TabIndex = 7;
            this->lblEstViajesActivos->Text = L"Viajes activos:     0";

            this->lblEstViajesHistorial->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblEstViajesHistorial->ForeColor = System::Drawing::Color::FromArgb(40, 55, 48);
            this->lblEstViajesHistorial->Location = System::Drawing::Point(430, 74);
            this->lblEstViajesHistorial->Name = L"lblEstViajesHistorial";
            this->lblEstViajesHistorial->AutoSize = true;
            this->lblEstViajesHistorial->TabIndex = 8;
            this->lblEstViajesHistorial->Text = L"Viajes en historial: 0";

            this->lblEstViajesCurso->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->lblEstViajesCurso->ForeColor = System::Drawing::Color::FromArgb(40, 55, 48);
            this->lblEstViajesCurso->Location = System::Drawing::Point(430, 98);
            this->lblEstViajesCurso->Name = L"lblEstViajesCurso";
            this->lblEstViajesCurso->AutoSize = true;
            this->lblEstViajesCurso->TabIndex = 9;
            this->lblEstViajesCurso->Text = L"Viajes en curso:     0";

            // Ganancias en verde
            this->lblEstGanancias->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 10, System::Drawing::FontStyle::Bold));
            this->lblEstGanancias->ForeColor = System::Drawing::Color::FromArgb(6, 98, 70);
            this->lblEstGanancias->Location = System::Drawing::Point(430, 122);
            this->lblEstGanancias->Name = L"lblEstGanancias";
            this->lblEstGanancias->AutoSize = true;
            this->lblEstGanancias->TabIndex = 10;
            this->lblEstGanancias->Text = L"Ganancia plataforma:  S/ 0.00";

            // 
            // FORMULARIO
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(245, 247, 245);
            this->ClientSize = System::Drawing::Size(1480, 868);
            this->Controls->Add(this->pnlEstadisticas);
            this->Controls->Add(this->pnlPasswords);
            this->Controls->Add(this->pnlListados);
            this->Controls->Add(this->pnlBusqueda);
            this->Controls->Add(this->pnlTarjetaViajes);
            this->Controls->Add(this->pnlTarjetaConductores);
            this->Controls->Add(this->pnlTarjetaPasajeros);
            this->Controls->Add(this->pnlTitulo);
            this->Controls->Add(this->pnlTopBar);
            this->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"AdminMenuForm";
            this->Text = L"LYNX | Panel Administrativo";
            this->Load += gcnew System::EventHandler(this, &AdminMenuForm::AdminMenuForm_Load);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AdminMenuForm::AdminMenuForm_KeyDown);

            // ResumeLayout para todos los panels
            this->pnlTopBar->ResumeLayout(false);
            this->pnlTitulo->ResumeLayout(false);
            this->pnlTarjetaPasajeros->ResumeLayout(false);
            this->pnlTarjetaConductores->ResumeLayout(false);
            this->pnlTarjetaViajes->ResumeLayout(false);
            this->pnlBusqueda->ResumeLayout(false);
            this->pnlResultado->ResumeLayout(false);
            this->pnlListados->ResumeLayout(false);
            this->pnlPasswords->ResumeLayout(false);
            this->pnlEstadisticas->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIcon))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
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
        //  ESTADO INTERNO
        // 
    private:
        bool buscandoPasajero = true;   // tab activo en busqueda
        int  listaActiva = 0;      // 0=Pasajeros, 1=Conductores, 2=Viajes

        System::Drawing::Size              normalSize;
        System::Drawing::Point             normalLocation;
        System::Windows::Forms::FormWindowState normalState;

        // 
        //  LOAD
        // 
    private:
        System::Void AdminMenuForm_Load(System::Object^ sender, System::EventArgs^ e)
        {
            // Cargar imagen del logo en la barra
            try {
                this->pictureBoxIcon->Image = System::Drawing::Image::FromFile("resources/LYNX_image.png");
                this->pictureBoxIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            }
            catch (...) {}

            // Para Pantalla Completa
            normalSize = this->Size;
            normalLocation = this->Location;
            normalState = this->WindowState;
            FormsStatus::SaveWindow(this);

            if (FormsStatus::isFullscreen) {
                FormsStatus::ApplyWindow(this);
            }
        }

        // 
        //  FULLSCREEN: F11, ESC sale si esta en fullscreen
        // 
    private:
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

        // 
        //  TABS DE BUSQUEDA
        // 
    private:
        // Tab Pasajero: habilita el campo DNI
        System::Void btnTabPasajero_Click(System::Object^ sender, System::EventArgs^ e)
        {
            buscandoPasajero = true;

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
                // Buscar pasajero por DNI usando AuthManager
                lblResultadoInfo->Text = L"Aqui aparecera el resultado del pasajero buscado por DNI.";
            }
            else {
                // Listar conductores con rating >= 4.0
                lblResultadoInfo->Text = L"Aqui apareceran los conductores con rating >= 4.0";
            }
        }

        // 
        //  BOTONES DE LISTADO
        // 
    private:
        // Lista Pasajeros: ordenar por ID o Gasto
        System::Void btnListPasajeros_Click(System::Object^ sender, System::EventArgs^ e)
        {
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
            rtbListado->Text = L"Aqui se listaran todos los pasajeros registrados.";
        }

        // Lista Conductores: ordenar por ID o Rating
        System::Void btnListConductores_Click(System::Object^ sender, System::EventArgs^ e)
        {
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

            rtbListado->Text = L"Aqui se listaran todos los conductores registrados.";
        }

        // Lista Viajes: ordenar por Precio
        System::Void btnListViajes_Click(System::Object^ sender, System::EventArgs^ e)
        {
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

            rtbListado->Text = L"Aqui se listaran todos los viajes del historial y activos.";
        }

        // Ordenar por criterio 1
        System::Void btnOrden1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // listaActiva==0 ------> por ID pasajero
            // listaActiva==1 ------> por ID conductor
            // listaActiva==2 ------> por precio de viaje
            rtbListado->Text = L"Ordenamiento por " + btnOrden1->Text + L" aplicado.";
        }

        // Ordenar por criterio 2
        System::Void btnOrden2_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // listaActiva==0 -----> por gasto total pasajero
            // listaActiva==1 -----> por rating conductor
            rtbListado->Text = L"Ordenamiento por " + btnOrden2->Text + L" aplicado.";
        }

        // 
        //  CARGAR PASSWORDS DESDE ARCHIVO BINARIO
        // 
    private:
        System::Void btnCargarPasswords_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Leer archivo binario de passwords y mostrar cada entrada
            rtbPasswords->Text = L"Aqui se mostraran los passwords leidos del archivo binario.";
        }

    };
}