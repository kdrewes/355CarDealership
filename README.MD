#Authors#
<br><br>
Jordan Nakamoto,<br>
Richard Yocke,<br>
Anthony Tara,<br>
Kyle Drewes<br>

#Project Description#
<br><br>
An app to manage the inventory of a car dealership. Local MYSQL database connected to CPP program.

#Installation Instructions#<br>
1. Setup Oracle mysqlcppconnector
https://github.com/mysql/mysql-connector-cpp
<br><br>
2. Connect the CPP linker to the library locations in the makefile. Current setup is for M1 Macbook Air filesystem
<br><br>
3. Download http://wxwidgets.org, the GUI library.
  - on MacOSX this is most easily done through Homebrew Package Manager
  - once again, this library has been linked in the Makefile for building on M1 Mac filesystem
<br><br>
4. Open main.cpp and on line 79, provide the login credentials used for your local MYSQL credentials
<br><br>
Build the app with "make"
Run the executable with "./app"


