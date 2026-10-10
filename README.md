# Clasificador interactivo con neurona sigmoide

Clasificador interactivo de una neurona sigmoide, implementado en C++ con MFC.

## Tipo y requisitos

Es un proyecto de aplicación de escritorio para Windows con interfaz MFC; el repositorio contiene el código fuente, no un ejecutable listo para abrir. Requiere Visual Studio 2022 con la carga de trabajo de desarrollo de escritorio con C++, el componente MFC para MSVC v143 y Windows SDK 10.0. La aplicación usa MFC dinámico; en una computadora sin Visual Studio puede ser necesario instalar el Microsoft Visual C++ Redistributable correspondiente.

## Abrir, compilar y ejecutar

1. Desde la raíz del repositorio, abra `Neurona1.sln` en Visual Studio.
2. Seleccione `x64` y `Debug` (o `Release`), confirme que `Neurona1` sea el proyecto de inicio y compile.
3. Ejecute con `F5` o `Ctrl+F5`.
4. En el área de dibujo, haga clic izquierdo para agregar un ejemplo de la clase 1 y clic derecho para agregar uno de la clase 0. Pulse **Entrenar** para ajustar la neurona y **Evaluar** para detener el entrenamiento y mostrar el resultado.

## Archivos del proyecto

- `Neurona1/Neurona.cpp` y `Neurona1/Neurona.h`: modelo de la neurona.
- `Neurona1/Neurona1Dlg.cpp`: diálogo principal e interacción.

## Por dónde empezar a leer

1. `Neurona1/Neurona1.cpp`: inicio de la aplicación MFC y creación del diálogo principal.
2. `Neurona1/Neurona1Dlg.cpp` y `Neurona1/Neurona1Dlg.h`: controles, eventos del mouse y ciclo de entrenamiento.
3. `Neurona1/Neurona.cpp` y `Neurona1/Neurona.h`: evaluación sigmoide, actualización de pesos y dibujo de la neurona.

## Archivos no incluidos

- `Neurona1/Neurona1.vcxproj.user`: configuración local de inicio y depuración de Visual Studio, vinculada a una computadora.
- `Neurona1/Neurona1.aps`: caché del editor de recursos de Visual Studio; el IDE la vuelve a generar.
- `.vs/` y los directorios `x64/`: cachés del IDE y resultados compilados, no archivos fuente.