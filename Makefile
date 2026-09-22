.PHONY: all clean run

all:
	$(MAKE) -C src all

run:
	$(MAKE) -C src run

clean:
	$(MAKE) -C src clean

