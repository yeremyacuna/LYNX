================================================================================
            INFORME DETALLADO DE DESARROLLO TÉCNICO - PROYECTO LYNX
================================================================================

Este documento certifica y detalla la participación individual de los desarrolladores
en el ciclo de vida del software LYNX, especificando sus contribuciones críticas,
lógica implementada y la autovaloración correspondiente al desempeño técnico y
colaborativo.

--------------------------------------------------------------------------------
1. INTEGRANTE: YEREMY
--------------------------------------------------------------------------------
ROL: Arquitecto de Interfaz de Usuario (UX/UI) y Lógica de Navegación

CONTRIBUCIONES TÉCNICAS:
*   Diseño y Arquitectura del Sistema de Menús: Lideró la implementación del 
    componente 'MainMenu.h', estableciendo un sistema de navegación jerárquico 
    robusto que garantiza un flujo de usuario intuitivo y eficiente.
*   Estética y Experiencia de Usuario (UX): Desarrolló la identidad visual del 
    software en entorno de consola, implementando técnicas de formateo avanzado 
    y diseño de layouts para mejorar la legibilidad y la interacción.
*   Control de Flujo y Validación: Implementó algoritmos de control de errores 
    en la captura de entradas, asegurando la integridad de los datos desde el 
    primer contacto con el usuario y previniendo desbordamientos o estados 
    inválidos en la navegación.
*   Integración Visual de Módulos: Actuó como nexo integrador, asegurando que 
    las funcionalidades de back-end se presentaran de manera cohesiva y amigable
    en las capas de presentación.

AUTOVALORACIÓN: 20/20
Justificación: Compromiso total con la usabilidad del sistema y liderazgo en el
frente estético, logrando un producto final profesional y funcional.

--------------------------------------------------------------------------------
2. INTEGRANTE: MELISSA
--------------------------------------------------------------------------------
ROL: Desarrolladora de Lógica de Negocio y Modelado de Entidades

CONTRIBUCIONES TÉCNICAS:
*   Modelado de Entidades del Dominio: Diseñó y codificó las clases fundamentales
    (User, Driver, Passenger, Admin), aplicando principios de Programación 
    Orientada a Objetos (POO) como herencia y encapsulamiento para representar 
    los diferentes roles del ecosistema LYNX.
*   Gestión de Lógica Transaccional: Implementó la lógica interna para la 
    creación y gestión de viajes (Trip.h) y vehículos (Vehicle.h), vinculando 
    las entidades de manera coherente para reflejar la realidad del negocio.
*   Sistema de Seguridad y Permisos: Desarrolló el 'AuthManager.h', encargándose
    de la validación de credenciales y la segregación de funciones según el rol
    del usuario, garantizando que el acceso a datos sensibles esté restringido.
*   Optimización de Procesos de Negocio: Refinó los métodos de asignación y 
    actualización de estados en tiempo real para las entidades de transporte.

AUTOVALORACIÓN: 20/20
Justificación: Ejecución impecable de la arquitectura de clases y la lógica 
operativa, permitiendo que el sistema sea escalable y semánticamente correcto.

--------------------------------------------------------------------------------
3. INTEGRANTE: SALVADOR
--------------------------------------------------------------------------------
ROL: Ingeniero de Estructuras de Datos y Persistencia de Sistemas

CONTRIBUCIONES TÉCNICAS:
*   Desarrollo de Low-Level Data Structures: Implementó desde cero las librerías 
    de estructuras dinámicas (LinkedList, LinkedDoubleList, Queue, Stack, Node),
    optimizando la gestión de memoria manual y garantizando la eficiencia en el 
    acceso y manipulación de elementos.
*   Arquitectura de Persistencia: Diseñó el 'FileManager.h', estableciendo un 
    sistema de serialización y deserialización de datos para archivos planos (.txt),
    lo que permite la persistencia del estado del sistema entre sesiones.
*   Gestión de I/O y Base de Datos plana: Desarrolló los mecanismos de lectura 
    y escritura de buffers de texto, asegurando que la información de usuarios, 
    viajes y vehículos se guarde de forma estructurada y segura en el disco.
*   Optimización de Algoritmos de Búsqueda: Implementó algoritmos eficientes 
    dentro de las listas para la recuperación rápida de registros específicos 
    basados en criterios de búsqueda personalizados.

AUTOVALORACIÓN: 20/20
Justificación: Garantizó la base sólida y estructural del proyecto, manejando con
maestría la manipulación de punteros y la seguridad en el almacenamiento de datos.

================================================================================
                                FIN DEL DOCUMENTO
================================================================================
