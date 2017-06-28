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

Currently the plugins must be built directly from the sources. On Windows
use ``CMake`` and on Linux the ``autotools`` scripts delivered to build the code.
If you have a running WiX distribution installed on your Windows system
MSI packages can be built. Currently the installation requires some
manual intervention once the code is built (or even after an eventual
MSI package has been installed).
For detailed information about the current installation procedures consult
the ``Readme`` files in the plugin subdirectories. 




