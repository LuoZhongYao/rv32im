project(ribp-hello-world)
cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_COMPILER riscv64-linux-gnu-gcc)
set(CMAKE_OBJCOPY riscv64-linux-gnu-objcopy)
set(CMAKE_C_FLAGS "-march=rv32im -mabi=ilp32")

add_executable(rom.elf startup.S riscv.c hostapi.c)
set_property(SOURCE startup.S PROPERTY LANGUAGE C)
add_custom_command(TARGET rom.elf
	POST_BUILD
	COMMAND ${CMAKE_OBJCOPY} ARGS -Obinary rom.elf rom.bin)
target_link_options(rom.elf PRIVATE -nostdlib -Ttext=0 -Wl,--build-id=none)
