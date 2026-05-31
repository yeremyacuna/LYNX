<div align="center">

<img src="LYNX/resources/LYNX_image.png" alt="LYNX" width="150" height="200" />

# LYNX

### Sistema de Gestión de Viajes y Pasajeros

[![C++](https://img.shields.io/badge/C++-00599C?logo=cplusplus&logoColor=white)](https://github.com/yeremyacuna/LYNX)
[![Data Structures](https://img.shields.io/badge/Data_Structures-Algorithm-orange)](https://github.com/yeremyacuna/LYNX)

**Estructuras de Datos**

</div>

---

## Descripción

**LYNX** es un sistema de gestión de viajes que implementa estructuras de datos fundamentales desde cero para administrar pasajeros, vehículos y rutas de manera eficiente, sin utilizar la Standard Template Library (STL).

### Características principales

- Sistema de autenticación con roles (Administrador/Usuario)
- Gestión completa de pasajeros y usuarios
- Administración de vehículos y asignación de rutas
- Gestión de viajes con cola de espera
- Persistencia de datos mediante archivos
- Implementación nativa: LinkedList, Queue, Stack, DoublyLinkedList

---

###### Authors
### Yeremy [@yeremyacuna](https://github.com/yeremyacuna)
### Melissa [@Melsy23](https://github.com/Melsy23)
### Salvador [@Salvarcc](https://github.com/Salvarcc)

---

###### Files

**Estructuras de Datos (include/)**
- [Node.h](LYNX/include/Node.h)
- [LinkedList.h](LYNX/include/LinkedList.h)
- [DoublyLinkedList.h](LYNX/include/DoublyLinkedList.h)
- [Queue.h](LYNX/include/Queue.h)
- [Stack.h](LYNX/include/Stack.h)
- [FileManager.h](LYNX/include/FileManager.h)

**Lógica del Sistema (src/)**
- [main.cpp](LYNX/src/main.cpp)
- [MainMenu.h](LYNX/src/MainMenu.h)
- [AdministratorMenu.h](LYNX/src/AdministratorMenu.h)
- [AuthManager.h](LYNX/src/AuthManager.h)
- [TripManager.h](LYNX/src/TripManager.h)

**Modelos (src/)**
- [Passenger.h](LYNX/src/Passenger.h)
- [Trip.h](LYNX/src/Trip.h)
- [User.h](LYNX/src/User.h)
- [Vehicle.h](LYNX/src/Vehicle.h)

**Formularios Designer (src/forms/)**
- [AdminMenuForm.h](LYNX/src/forms/AdminMenuForm.h)
- [DriverMenuForm.h](LYNX/src/forms/DriverMenuForm.h)
- [PassengerMenuForm.h](LYNX/src/forms/PassengerMenuForm.h)
- [LoginForm.h](LYNX/src/forms/LoginForm.h)
- [RegisterForm.h](LYNX/src/forms/RegisterForm.h)


---

###### Icon
<div align="center">
<img src="LYNX/resources/LYNX_image.png" alt="LYNX" width="500" height="500" />
</div>

---

###### Structure

**Detalles:**
- **src**: Código fuente y lógica del programa
- **forms**: Estructura lógica y visual del programa en Windows Forms
- **include**: Headers de estructuras de datos
- **assets**: Archivos predeterminados de la aplicación
- **data**: Archivos generados/usados por el usuario
- **resources**: Iconos, UI, imágenes
- **docs**: Documentación, diagramas
- **tests**: Pruebas, etc.

---

## Tecnologías

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual_Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white)

</div>

---

## Estructuras de Datos Implementadas

| Estructura | Archivo | Descripción |
|:-----------|:--------|:------------|
| **Nodo** | `Node.h` | Estructura base para todas las listas |
| **Lista Enlazada** | `LinkedList.h` | Lista enlazada simple |
| **Lista Doble** | `DoublyLinkedList.h` | Lista doblemente enlazada |
| **Cola** | `Queue.h` | Cola FIFO para gestión de turnos |
| **Pila** | `Stack.h` | Pila LIFO para operaciones |

---

## Arquitectura del Sistema

### Componentes Principales

**Gestión de Datos**
- `FileManager.h`: Persistencia de datos .txt . bin
- `Node.h`: Estructura base

**Autenticación y Usuarios**
- `AuthManager.h`: Sistema de autenticación
- `User.h`: Modelo de usuario

**Gestión de Viajes**
- `TripManager.h`: Administración de viajes
- `Trip.h`: Modelo de viaje
- `Passenger.h`: Modelo de pasajero
- `Vehicle.h`: Modelo de vehículo

**Interfaces**
- `MainMenu.h`: Menú principal
- `AdministratorMenu.h`: Panel de administración
- `MainMenuForm.h`: Menú principal de Windows Form

---

## Características Técnicas

### Sin uso de STL
Todas las estructuras de datos están implementadas desde cero, sin utilizar la Standard Template Library, con fines educativos.

### Gestión de Memoria
- Asignación dinámica manual
- Destructores para evitar memory leaks
- Manejo directo de punteros

### Persistencia
- Sistema de archivos para guardar datos
- Carga automática al iniciar
- Guardado automático al cerrar

---

## Contribuciones

1. Fork el repositorio
2. Crea una rama: `git checkout -b feature/nueva-funcionalidad`
3. Commit: `git commit -m 'Agregar funcionalidad'`
4. Push: `git push origin feature/nueva-funcionalidad`
5. Abre un Pull Request

---

<div align="center">

**Developed by LYNX Team**

</div>
