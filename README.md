This is a small C++ `Hello World` program testing a project build using [conan.io](https://www.conan.io/) as package manager, [CMake](https://en.wikipedia.org/wiki/CMake) as build generator and linking with [SQLite3](https://sqlite.org/) library.

## Requirements

* [CMake](https://cmake.org/), see [how to install](https://cmake.org/install/).
* [conan.io](https://www.conan.io/) package manager, see [how to install](http://docs.conan.io/en/latest/installation.html).
* A C++ compiler

## How to build - on Mac OS X and [*nix](https://en.wikipedia.org/wiki/Unix-like):

First establish out-of-source `build/` folder, so that source folder is not polluted:

  ~~~
  $ mkdir build
  $ cd build
  ~~~

Initialize your project with *conan* - this is using the `conanfile.txt` specifying that SQLite (v3.15.2) is an dependency and that conan should integrate with *CMake*:

  ~~~
  $ conan install ..
  ~~~

If you see error *Try to build from source with --build* then do the following to build the actual SQLite library from its source:

  ~~~
  $ conan install --build SQLite3
  ~~~

Generate the build files using *CMake*:

  ~~~
  $ cmake ..
  ~~~

Build the project:

  ~~~
  $ make
  ~~~

If everything went successfully, you can run the built executable:

  ~~~
  $ bin/mytest
  ~~~

Expected output:

  ~~~
  Hello World!
  SQLite version 3.15.2
  ~~~


