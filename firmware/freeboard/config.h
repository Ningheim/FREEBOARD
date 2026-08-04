#pragma once

#define MCP23017_I2C_ADDRESS (0x20 << 1)

// All 91 LEDs are powered from USB VBUS. Keep the global brightness limited
// so a full-white effect cannot demand several amps from the USB connection.
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 32
#define RGB_MATRIX_DEFAULT_VAL 24
#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_KEYPRESSES

#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_TIMEOUT 60000
