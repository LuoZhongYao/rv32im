CC := riscv64-linux-gnu-gcc
OBJDUMP := riscv64-linux-gnu-objdump
OBJCOPY := riscv64-linux-gnu-objcopy
CFLAGS += -march=rv32im -mabi=ilp32

rom.bin: rom.elf
	$(OBJCOPY) -Obinary $^ $@

rom.elf: startup.S riscv.c hostapi.c
	$(CC) $^ -o $@ $(CFLAGS) -nostdlib -Ttext=0 -Wl,--build-id=none -g

clean:
	-rm rom.bin rom.elf
