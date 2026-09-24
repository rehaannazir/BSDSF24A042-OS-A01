PREFIX ?= /usr/local
DESTDIR ?=
INSTALL ?= install

.PHONY: all clean run run-dynamic install

all:
	$(MAKE) -C src all

run:
	$(MAKE) -C src run

run-dynamic:
	$(MAKE) -C src run-dynamic

install: all
	$(INSTALL) -d "$(DESTDIR)$(PREFIX)/bin" "$(DESTDIR)$(PREFIX)/lib" \
		"$(DESTDIR)$(PREFIX)/share/man/man1" "$(DESTDIR)$(PREFIX)/share/man/man3"
	$(INSTALL) -m 755 bin/client_dynamic "$(DESTDIR)$(PREFIX)/bin/client"
	$(INSTALL) -m 755 lib/libmyutils.so "$(DESTDIR)$(PREFIX)/lib/libmyutils.so"
	$(INSTALL) -m 644 man/man1/client.1 "$(DESTDIR)$(PREFIX)/share/man/man1/client.1"
	$(INSTALL) -m 644 man/man3/*.3 "$(DESTDIR)$(PREFIX)/share/man/man3/"
	@if [ -z "$(DESTDIR)" ]; then ldconfig; fi

clean:
	$(MAKE) -C src clean
