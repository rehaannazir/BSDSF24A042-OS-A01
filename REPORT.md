# Operating Systems Programming Assignment 01 Report

Roll Number: BSDSF24A042

## Part 1: Project Scaffolding and Version Control

The project repository and required directory structure were created according to the assignment specification.

## Part 2: Multi-file Project Using Make

### Linking rule: `$(TARGET): $(OBJECTS)`

This rule states that the executable depends on all object files. If an object file is newer than the executable, `make` runs the linking command again. In this direct multi-file build, the linker receives every object file explicitly. A rule that links against a library instead supplies the library search path and library name, normally with options such as `-Llib` and `-lmyutils`; the linker then obtains the required functions from that library.

### Git tags

A Git tag is a permanent name attached to a particular commit, normally used to identify a released version. It makes an important project state easy to find and reproduce. A lightweight tag is only a name pointing to a commit. An annotated tag is a complete Git object containing the tagger, date, message, and optional signature, so it is more suitable for official releases.

### GitHub Releases and binary assets

A GitHub Release presents a tagged version as a downloadable, documented software release. Its title and notes explain what the version contains. Attaching the compiled `client` binary allows a Linux user to run that build without compiling the C source code first. The tag identifies the exact source version from which the binary was built.

## Part 3: Static Library

### How the Makefile changed

In Part 2, the executable depended on all three object files and linked them directly. In Part 3, `LIB_OBJECTS` contains only the string and file modules. The `$(LIBRARY)` rule archives those two objects as `lib/libmyutils.a`; the client rule depends on that archive and `main.o`. Its link command uses `-L../lib` to choose the library directory and `-lmyutils` to select `libmyutils.a`. Changing either utility source rebuilds the archive and then relinks the client.

### `ar` and `ranlib`

`ar` stores multiple object files in one static library archive. `ranlib` creates or refreshes the archive's symbol index, which helps the linker find definitions inside it. On GNU systems, `ar rcs` already writes that index; this Makefile also calls `ranlib` explicitly to make the step visible.

### Symbols in `client_static`

`nm bin/client_static` shows definitions such as `mystrlen`, `mygrep`, and `wordCount` in the final executable. The linker copied the required object code from `libmyutils.a` into the executable at build time. Consequently, the program does not need the `.a` file at runtime.

## Part 4: Dynamic Library

### Position-independent code (`-fPIC`)

The shared library's object files are compiled with `-fPIC`, so their machine code can run regardless of where the dynamic loader maps `libmyutils.so` in a process. This lets the same shared object be loaded at different addresses without rewriting its code pages. The Makefile keeps separate `.pic.o` objects for the shared library and ordinary `.o` objects for the static archive.

### Static and dynamic client sizes

On this Linux build, `bin/client_static` is 16,968 bytes and `bin/client_dynamic` is 16,624 bytes: the dynamic client is 344 bytes smaller (about 2%). The static client contains the selected utility object code from `libmyutils.a`; the dynamic client mainly records a dependency on `libmyutils.so` and resolves those functions when it runs. The difference is modest here because this utility library is small, and executable metadata and C runtime dependencies account for much of both files. A larger library or different compiler settings could produce a larger gap.

### `LD_LIBRARY_PATH` and the dynamic loader

`LD_LIBRARY_PATH` is a list of directories the Linux dynamic loader searches for shared libraries. Without the project `lib/` directory in that path, `./bin/client_dynamic` fails because `libmyutils.so` cannot be found. After setting `LD_LIBRARY_PATH` to include the project's `lib/`, all six client tests pass. `ldd bin/client_dynamic` then shows `libmyutils.so` resolving to this repository's `lib/libmyutils.so`. This demonstrates that the executable identifies its needed shared library, while the loader must locate and load the actual file at runtime.
