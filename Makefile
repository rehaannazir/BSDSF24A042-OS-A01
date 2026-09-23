.PHONY: all clean run run-dynamic

all:
	$(MAKE) -C src all

run:
	$(MAKE) -C src run

run-dynamic:
	$(MAKE) -C src run-dynamic

clean:
	$(MAKE) -C src clean
