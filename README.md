This is a small C++ `Hello World` program testing building with [conan.io](https://www.conan.io/) package manager and linking/using SQLite3 library.

## Requirements

* CMake
* [conan.io](https://www.conan.io/) package manager, see [how to install](http://docs.conan.io/en/latest/installation.html).
* A C++ compiler

## How to build - on Mac OS X, [*nix](https://en.wikipedia.org/wiki/Unix-like):

First establish out-of-source `build/` folder, so that source folder is not polluted:

  ~~~
  $ mkdir build
  $ cd build
  ~~~

Initialize conan (this is using the `conanfile.txt` specifying that SQLite (v3.15.2) is an dependency):

  ~~~
  $ conan install ..
  ~~~

If you see error *Try to build from source with --build* then do the following to build the actual SQLite library from its source:

  ~~~
  $ conan install --build SQLite3
  ~~~

Generate the build files using CMake:

  ~~~
  $ cmake ..
  ~~~

Build the project:

  ~~~
  $ make
  ~~~

Run the built executable:

  ~~~
  $ bin/mytest
  ~~~

Expected output:

  ~~~
  Hello World!
  SQLite version 3.15.2
  ~~~


