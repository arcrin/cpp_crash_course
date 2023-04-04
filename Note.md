# {fmt} build and installation
Download `{fmt}` souorce code from https://fmt.dev/latest/index.html

Get MinGW build from https://github.com/niXman/mingw-builds-binaries/releases

use the following command to build the library. 

`cmake -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM="C:/mingw64/bin/make.exe" -DCMAKE_CXX_COMPILER="C:/mingw64/bin/g++.exe" .. `

Need to use the build tool `make` and compiler `g++` from the same distribution. Mixing MinGW tools with Microsoft 
tools don't seem to work.

Modify the `{fmt} CmakeList.txt` file:

Add `set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")`. 
This will specify compiler path.

Add `set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/bin"
CACHE PATH "Install path prefix, prepended onto install directories.")` to specify the installation path when calling
`make install`.