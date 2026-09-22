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
