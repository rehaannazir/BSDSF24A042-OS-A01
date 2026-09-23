# BSDSF24A042-OS-A01
Operating Systems Programming Assignment 01

## Part 2: Multi-file Build

On the `multifile-build` branch, build and run the direct multi-file version
on Linux:

```bash
make
./bin/client
```

Remove generated object files and the executable with `make clean`.

## Part 3: Static Library Build

On the `static-build` branch, `make` creates `lib/libmyutils.a` from the
string and file modules, then links `bin/client_static` against it. Run the
program with `./bin/client_static`. Use `make clean` to remove this branch's
generated files.

## Part 4: Dynamic Library Build

On the `dynamic-build` branch, `make` builds both the static version and
`lib/libmyutils.so` with `-fPIC`, then links `bin/client_dynamic` to the shared
library. To let the Linux loader find the library in this project, run:

```bash
make
export LD_LIBRARY_PATH="$PWD/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
./bin/client_dynamic
ldd bin/client_dynamic
```

`make run-dynamic` performs the library-path setup for one run.

## Part 5: Manual Pages and Installation

On the `man-pages` branch, the application has a section 1 manual page at
`man/man1/client.1`. Each of the six library functions has a section 3 page
under `man/man3/`. Preview a page before installation with, for example,
`man -l man/man3/mygrep.3`.

Install the dynamic client, shared library, and manual pages on Linux with:

```bash
make
sudo make install
client
man client
man mygrep
```

The install target uses `/usr/local` by default and refreshes the dynamic
loader cache. It also accepts `PREFIX` and `DESTDIR` for alternate or staged
installation paths.
