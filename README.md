# Custom Embedded Firmware Building with Makefile

This repo is educational-purpose. I'm showing that how to build a embedded 
firmware written for STM32F446RE microcontroller without any IDEs or external
dependencies (except Makefile). 

The firmware was written with CMSIS and STM32 HAL libraries so that you have
to get it:

```bash
$ git clone --recurse-submodules https://github.com/STMicroelectronics/STM32CubeF4.git
```

Also to compile the firmware, you need the corresponding ARM toolchain:

```bash
$ sudo apt install gcc-arm-none-eabi	/* NEVER use host's toolchain */
```

After got the required libraries, put these under `./drivers` directory. Also
make sure that the linker script (in case, STM32F446RETX_FLASH.ld) should be in
there. Mostly, it comes with CMSIS, but move it as how I did.

To build the firmware, just run the Makefile:

```bash
$ make lib		# build the static library for just one time
$ make bin		# build the firmware code for every change
```

This will create the both `firmware.elf` and `firmware.bin`. According to your
situation, use one of them to flash the firmware. I generally work with `.elf`
executables. Because it has debugging symbols beside the program machine code.

Suppose that you have ST-LINK connection. You can flash the `firmware.elf` with
`openocd` like this:

```bash
$ $ openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program firmware.elf verify reset exit"
```

Of course, make sure that you have the `openocd` tool as well. You can install:

```bash
$ sudo apt install openocd
```
