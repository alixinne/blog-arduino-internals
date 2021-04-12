ENVS=arduino avr template
S_FILES=$(patsubst %,build/%.s,$(ENVS))
SIZE_FILES=$(patsubst %,build/%-size.txt,$(ENVS))
PROG_FILES=$(S_FILES) $(SIZE_FILES)

PUBLIC=public
OUT_PAGE=$(PUBLIC)/index.html
OUT_FILES=$(OUT_PAGE) $(PROG_FILES)

BASE=$(HOME)/.platformio/packages/toolchain-atmelavr/bin/avr-
OBJDUMP=$(BASE)objdump
SIZE=$(BASE)size --mcu=atmega328p -C

all: $(OUT_PAGE)

$(PUBLIC):
	mkdir -p $@

$(OUT_PAGE): page.py page.html.j2 $(PUBLIC) $(PROG_FILES)
	python $< $(ENVS) > $@

$(S_FILES): build/%.s:build/%/firmware.elf
	$(OBJDUMP) -drwCS $^ > $@

$(SIZE_FILES): build/%-size.txt:build/%/firmware.elf
	$(SIZE) $^ > $@

build/%/firmware.elf: src/%/main.cpp
	pio run -e $(patsubst src/%/main.cpp,%,$^)

clean:
	rm -f $(OUT_FILES)

.PHONY: all clean
