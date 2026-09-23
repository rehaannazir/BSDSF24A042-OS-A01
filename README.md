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
