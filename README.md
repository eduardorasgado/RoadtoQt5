# RoadtoQt5
Modern C++ desktop GUI development labs using famous Qt5 framework and QtCreator.

## Annotations

Some packages work by other non qt libs integration. So I use conan package manager
as an easy way to integrate building method.

### CONAN PACKAGES AND QT(QtCreator) INTEGRATION

To build a qt and conan libraries projects:

#### In a terminal:

- Create your desire conanfile.txt custom libs file in same folder main.cpp is

- Create a conan build directory inside the solution, not the debug folder.

- Enter the folder created and run:
```console
	conan install .. -g qmake
```
This command will generate a conanbuildinfo.pri in the actual build folder.

#### In QtCreator:

- In .pro file in qt creator add:
```console
CONFIG += conan_basic_setup
include(conan_build_folder/conanbuildinfo.pri)
```
- Then just include your headers in your files and enjoy.
