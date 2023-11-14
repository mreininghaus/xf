# xf - swap two files

This little tool provides a convenient method to swap two files. If you have files `file_a` and `file_b`
and want to rename `file_a` to `file_b` and vice versa, just call `xf file_a file_b`.

## Runtime requirements
xf currently runs only on Linux with a kernel version >= 3.15 and glibc >= 2.28.

## Build
xf is built using CMake, which you may need to install first via your preferred method.
There are no special dependencies beyond the above-mentioned glibc and a C compiler.
To build and install xf, run
```
$ cmake -DCMAKE_BUILD_TYPE=Release -S <path-to-xf> -B xf-build
$ cd xf-build
$ make
$ sudo make install
```
This will install xf into `/usr/local/bin/xf`.
