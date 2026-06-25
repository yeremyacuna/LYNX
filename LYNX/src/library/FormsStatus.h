#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Drawing;       
using namespace System::Windows::Forms; 
using std::string;
using std::fixed;

namespace LYNX {
    public ref class FormsStatus {

    public:
        static bool isFullscreen = false; // booleano de verificacion de fullscreen
        static System::Windows::Forms::Form^ mainMenu = nullptr; // variable de tipo Form

        static System::Drawing::Size normalSize = System::Drawing::Size(1496, 959); // guardar size
        static System::Drawing::Point normalLocation = System::Drawing::Point(0, 0);    // guardar locacion 
       
        static bool isWithoutF11 = false;

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
                isWithoutF11 = true;
            }
        }

        template<typename T>
        inline static System::String^ ToManaged(const T& value)
        {
            std::ostringstream ss;
            ss << value;
            return gcnew System::String(ss.str().c_str());
        }

        template<typename T>
        inline static System::String^ ToManaged(const T& value, int decimals)
        {
            std::ostringstream ss;

            if (decimals >= 0)
            {
                ss << std::fixed << std::setprecision(decimals);
            }

            ss << value;

            return gcnew System::String(ss.str().c_str());
        }

        inline static string ToNormalString(String^ text)
        {
            if (text == nullptr) return "";
            return msclr::interop::marshal_as<std::string>(text);
        }
    };
}
