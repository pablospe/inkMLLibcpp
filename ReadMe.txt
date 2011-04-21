Version - 0.5.0
InkML Processor library - C++ implementation.
It provides a very minimal implementation of the InkML draft specification. 
It parses only the InkML:trace, InkML:traceGroup elements. 
InkML draft specification is available at, http://www.w3.org/TR/InkML/.

Instructions to build the source code:
=====================================
* Download inkMLLibcpp-0.5.0.src.zip from http://sourceforge.net/projects/inkmltk
* Extract the inkMLLibcpp-0.5.0.src.zip file, it creates a directory with name 'inkMLLibcpp-src'.

Prerequisites:
=============
1. Download the TinyXml (http://sourceforge.net/projects/tinyxml) from sourceforge.net. 
   We advice you to read and understand their licensing terms.
2. Unzip the TinyXml package file. 
   In Linux system, the archive file can be extracted using the 'unzip' command.

TinyXml header file:
-------------------
1. Create a directory with name 'tinyxml' in inkMLLibcpp-src\include folder
2. Copy the tinystr.h, tinyxml.h to inkMLLibcpp-src\include\tinyxml

TinyXml library file:
---------------------
1. Build TinyXml. 
    Linux: Use a C++ compiler (g++ or gcc) to compile the source code as shown below,
	   g++ -c tinyxml.cpp tinystr.cpp tinyxmlparser.cpp tinyxmlerror.cpp
    Windows: Use the given Visual Studio project with the following change to the project settings,
             a.	open project settings
	     b.	Goto C/C++ tab
	     c. Select "Code Generation" from 'Category' setting.
	     d.	Select "Multithreaded DLL" from 'Use run-time library' setting.
	     e.	Press OK.

2. Create a directory with name 'lib' in the inkMLLibcpp-src folder.
3. Copy the TinyXml library file.
	Windows: copy tinyxml.lib to  <plugin install path>\lib folder.
	Linux: copy the tinyxml.o, tinystr.o, tinyxmlparser.o and tinyxmlerror.o files to inkMLLibcpp-src\lib folder.

Windows: To Build InkML Library from Visual Studio:
---------------------------------------------------
1. Open the ".\src\InkMLLib.sln" file using Visual Studio 2005. 
2. Ensure that the following library References have been added to inkMLLibcpp project:
   	a. tinyxml.lib 
3. To add the above library file
        a. Go to Project->Properties.
	b. Expand configuration properties -> Librarian ->Command Line.
        c. add the above library in to 'additional options'.
        d. Click 'OK'.
4. Add include path 
        a. Go to Project->Properties.
	b. Expand configuration properties -> C/C++->General.
        c. Include .\include\tinyxml in 'Additional Include Directories'.
        d. Click 'OK'.
5. Add header files :
	a. Right click on project solution.
        b. Goto Add -> Existing Item.
        c. Add third party header file tinystr.h, tinyxml.h
6. Build the project.

Linux: To Build InkML Library
-----------------------------
1. Change present working directory to the inkMLLibcpp-src/src folder.
2. Run the build.sh file. Ensure that you have given execute permission to the script file. 
   You may use the "chmod +x build.sh" command to add execute permission to build.sh.
   	./build.sh
3. On successful compilation, the InkML processor library (libinkmllibcpp.a) is created and saved to inkMLLibcpp-src/bin directory.

For more details and information, please see the project web site, http://inkmltk.sourceforge.net