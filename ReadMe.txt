Version - 0.5.0
InkML Processor library - C++ implementation.
It provides a very minimal implementation of the InkML draft specification. 
It parses only the InkML:trace, InkML:traceGroup elements. 
InkML draft specification is available at, http://www.w3.org/TR/InkML/.

Prerequisites:
=============
* TinyXml (http://sourceforge.net/projects/tinyxml)
 
How to compile?
===============

    * Using cmake:
        _ mkdir build_release
        _ cd build_release
        _ cmake ..
        _ make

	(for debug)
        _ mkdir build_debug
        _ cd build_debug
        _ cmake -DCMAKE_BUILD_TYPE=Debug ..
        _ make

Instalation
===========

  * make install
  * (optional) make install DESTDIR="/some/absolute/path"
