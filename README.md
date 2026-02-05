# C PIC Compiler - Compilador C/ASM para Microcontroladores PIC en Android

![License](https://img.shields.io/badge/license-GPL--3.0-blue.svg)
![Platform](https://img.shields.io/badge/platform-Android-green.svg)
![API Level](https://img.shields.io/badge/API-23%20to%2036-brightgreen.svg)
![Architecture](https://img.shields.io/badge/arch-ARM64-orange.svg)

## Descripción

**C PIC Compiler** es una aplicación Android nativa que permite compilar código ensamblador (ASM) y código en lenguaje C para microcontroladores PIC directamente desde tu dispositivo móvil. Esta herramienta está diseñada para desarrolladores de sistemas embebidos que desean programar microcontroladores PIC sin necesidad de una PC.

## Características

- ✅ Compilación de código C y ensamblador para microcontroladores PIC
- ✅ Basado en las herramientas oficiales SDCC y GPUTILS
- ✅ Soporte para múltiples familias de microcontroladores PIC
- ✅ Interfaz Android nativa optimizada
- ✅ Sin necesidad de conexión a internet para compilar
- ✅ Compilador completo integrado en la aplicación

## Requisitos del Sistema

### Hardware
- Dispositivo Android con arquitectura **ARM64 (arm64-v8a)**
- Sistema operativo Android de **64 bits**
- Mínimo 100 MB de espacio libre

### Software
- Android **API Level 23** (Android 6.0 Marshmallow) o superior
- Soportado hasta **API Level 36** (Android 16)

> ⚠️ **Nota importante**: Esta aplicación **solo** es compatible con dispositivos Android ARM64 de 64 bits. No funciona en dispositivos de 32 bits ni en otras arquitecturas.

## Tecnologías Utilizadas

Esta aplicación integra los siguientes compiladores y herramientas:

### SDCC (Small Device C Compiler)
- **Fuente**: [SDCC en SourceForge](https://sourceforge.net/projects/sdcc/)
- **Descripción**: Compilador C de código abierto optimizado para microcontroladores de 8 bits
- **Licencia**: GPL

### GPUTILS (GNU PIC Utilities)
- **Fuente**: [GPUTILS en SourceForge](https://sourceforge.net/projects/gputils/)
- **Descripción**: Suite de herramientas para ensamblar y enlazar código para microcontroladores PIC
- **Licencia**: GPL

## Instalación

### Desde el Código Fuente

1. Clona este repositorio:
```bash
git clone https://github.com/Danielk10/C-PIC.git
cd C-PIC
```

2. Abre el proyecto en Android Studio

3. Asegúrate de tener instalado:
   - Android SDK API 36
   - CMake 3.22.1 o superior
   - NDK (Android Native Development Kit)

4. Compila el proyecto:
```bash
./gradlew assembleRelease
```

5. El APK se generará en: `app/build/outputs/apk/release/`

## Uso

1. **Abre la aplicación** en tu dispositivo Android
2. **Crea o importa** tu código fuente C o ASM
3. **Configura** el microcontrolador PIC objetivo
4. **Compila** tu proyecto
5. **Exporta** el archivo HEX generado para programarlo en tu microcontrolador

## Estructura del Proyecto

```
C-PIC/
├── app/
│   ├── src/
│   │   ├── main/
│   │   │   ├── cpp/          # Código nativo C/C++ (NDK)
│   │   │   ├── java/         # Código Java de la aplicación
│   │   │   └── res/          # Recursos de la interfaz
│   │   └── ...
│   └── build.gradle          # Configuración de compilación
├── gradle/
├── LICENSE                   # Licencia GPL-3.0
└── README.md                # Este archivo
```

## Compilación Nativa

Esta aplicación utiliza **Android NDK** y **CMake** para compilar componentes nativos optimizados para ARM64. Los binarios de SDCC y GPUTILS están integrados como bibliotecas nativas (.so).

### Configuración NDK
- **ABI soportado**: `arm64-v8a`
- **CMake versión**: 3.22.1
- **Compatibilidad Java**: Java 11

## Contribuciones

Las contribuciones son bienvenidas. Si deseas colaborar:

1. Haz un fork del proyecto
2. Crea una rama para tu característica (`git checkout -b feature/nueva-caracteristica`)
3. Realiza tus cambios y haz commit (`git commit -am 'Agregar nueva característica'`)
4. Sube tus cambios (`git push origin feature/nueva-caracteristica`)
5. Abre un Pull Request

## Licencia

Este proyecto está licenciado bajo la **GNU General Public License v3.0** (GPL-3.0).

Ver el archivo [LICENSE](LICENSE) para más detalles.

### Licencias de Componentes

- **SDCC**: GPL License - [SDCC License](https://sourceforge.net/projects/sdcc/)
- **GPUTILS**: GPL License - [GPUTILS License](https://sourceforge.net/projects/gputils/)
- **C-PIC**: GPL-3.0 License

## Créditos

- **Desarrollador**: Daniel Diamon (Danielk10)
- **Basado en**: SDCC y GPUTILS
- **Inspiración**: Llevar el desarrollo de microcontroladores PIC a dispositivos móviles siguiendo los pasos de Termux del cuál hice usó para este proyecto


## Soporte

Si encuentras algún problema o tienes sugerencias:

- Abre un [Issue en GitHub](https://github.com/Danielk10/C-PIC/issues)
- Contacta al desarrollador a través de GitHub

## Limitaciones Conocidas

- Solo compatible con dispositivos ARM64 de 64 bits
- No soporta depuración en tiempo real del microcontrolador
- Requiere permisos de almacenamiento para leer/escribir archivos de proyecto

## Roadmap

- [ ] Soporte para más familias de microcontroladores
- [ ] Editor de código con resaltado de sintaxis mejorado
- [ ] Plantillas de proyectos predefinidas
- [ ] Integración con herramientas de programación PIC
- [ ] Documentación de referencia de la API de PIC

## Agradecimientos

Gracias a los equipos de desarrollo de SDCC, GPUTILS y Termux versión Google Play por proporcionar estas excelentes herramientas de código abierto que hacen posible este proyecto.

---

**Nota**: Esta aplicación es una herramienta de desarrollo y requiere conocimientos de programación de microcontroladores PIC y lenguaje C/ensamblador.
