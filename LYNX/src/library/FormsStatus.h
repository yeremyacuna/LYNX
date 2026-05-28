#pragma once

namespace LYNX {
    public ref class FormsStatus {

    public:
        static bool isFullscreen = false; // booleano de verificacion de fullscreen
        static System::Windows::Forms::Form^ mainMenu = nullptr; // variable de tipo Form

        static System::Drawing::Size normalSize = System::Drawing::Size(1496, 959); // guardar size
        static System::Drawing::Point normalLocation = System::Drawing::Point(0, 0);    // guardar locacion 
       
        // guardar la ventana actual
        static void SaveWindow(System::Windows::Forms::Form^ form)
        {
            if (form != nullptr && !form->IsDisposed && form->WindowState == System::Windows::Forms::FormWindowState::Normal)
            {
                normalSize = form->Size;
                normalLocation = form->Location;
            }
        }

        // aplicar la ventana actual
        static void ApplyWindow(System::Windows::Forms::Form^ form)
        {
            if (form == nullptr || form->IsDisposed)
            {
                return;
            }

            form->WindowState = System::Windows::Forms::FormWindowState::Normal;

            if (isFullscreen)
            {
                form->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                form->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            }
            else
            {
                form->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
                form->Size = normalSize;
                form->Location = normalLocation;
            }
        }
    };
}
