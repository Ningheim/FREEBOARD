# Freeboard

Custom 81-key keyboard using a Raspberry Pi Pico, 91 SK6812MINI-E LEDs,
an I2C OLED, and a rotary encoder connected through an MCP23017 expander.

* Keyboard Maintainer: [Freedom Nyadroh](https://github.com/ningheim)
* Controller: Raspberry Pi Pico (RP2040)
* Matrix: 6 rows by 15 columns, COL2ROW
* RGB: 91 serial LEDs on GP21 (81 key lights and 10 decorative lights)
* I2C: I2C1 on GP22/GP26
* Encoder: MCP23017 address 0x20, GPA0/GPA1/GPA2

Make example for this keyboard (after setting up your build environment):

    make freeboard:default

Flashing example for this keyboard:

    make freeboard:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Installation

Copy this entire `freeboard` directory to:

    ~/qmk_firmware/keyboards/freeboard

For QMK 0.33 and newer, keep the board metadata named `keyboard.json`.
Do not rename it to `info.json`.

If QMK's own Python source was previously edited, restore it first:

    cd ~/qmk_firmware
    git restore lib/python/qmk/keyboard.py

Then verify and compile:

    qmk clean
    qmk list-keyboards | grep freeboard
    qmk compile -kb freeboard -km default

The compiled UF2 should be placed in the root of the QMK firmware directory.

## Default controls

The encoder changes volume and its push switch toggles mute. Hold the key
immediately to the left of the arrow cluster to access the Fn layer. The Fn
layer contains RGB controls; Fn+Esc enters the RP2040 bootloader.

The OLED configuration assumes the common 128x32 SSD1306 display at address
0x3C. For a 128x64 display, add `#define OLED_DISPLAY_128X64` to `config.h`.

## RGB power limit

The PCB powers all 91 LEDs from USB VBUS. Firmware therefore limits the maximum
RGB brightness. Raising this limit can exceed the USB port's current budget,
especially with white or pale effects.

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
