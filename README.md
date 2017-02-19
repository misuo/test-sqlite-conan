This is a small build and package manager test. It test building a simple `Hello World` C++ program using/linked with SQLite3 library.

## Requirements

* CMake
* Conan.io package manager
* A C++ compiler

## How to build

On Mac/*nix:

    $ mkdir build
    $ cd build
    $ conan install ..

If you see error "Try to build from source with --build" then do

    $ conan install --build SQLite3


    $ cmake ..
    $ make
    $ bin/mytest

Expected output:

    Hello World!
    3.15.2


