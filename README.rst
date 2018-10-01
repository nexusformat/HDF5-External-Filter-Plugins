================================
Welcome to HDF5 external filters
================================

The external filter mechanism introduced with HDF5 1.8.12 allows applications
to utilize custom filters not shipped by the HDF5 core library without
recompiling your application. This repository provides external filters
for HDF5 for

* the LZ4 compression algorithm
* BZip2 compression
* and the BLOSC library.

Installation
============

Currently the plugins must be built directly from the sources using `cmake`
version 3 or higher.  To build, use commands like these::

    mkdir build
    cd build
    cmake .. -DENABLE_BITSHUFFLE_PLUGIN=yes -DENABLE_LZ4_PLUGIN=yes -DENABLE_BZIP2_PLUGIN=yes -DCMAKE_INSTALL_PREFIX=/usr/local
    make install

For detailed information about the installation procedures for each module,
consult the ``Readme`` files in the plugin subdirectories.


If you have a running WiX distribution installed on your Windows system MSI
packages can be built. Currently the installation requires some manual
intervention once the code is built (or even after an eventual MSI package
has been installed).
