#include "quantum.h"
#include "i2c_master.h"

#define MCP23017_IODIRA 0x00
#define MCP23017_GPPUA  0x0C
#define MCP23017_GPIOA  0x12

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        {      0, NO_LED,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12,     13 },
        {     14,     15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28 },
        {     29,     30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43 },
        {     44,     45,     46, NO_LED,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57 },
        {     58,     59,     60, NO_LED,     61,     62,     63,     64,     65,     66,     67,     68,     69,     70,     71 },
        {     72,     73,     74,     75, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,     76,     77,     78,     79,     80 },
    },
    {
        {   4, 14 }, {  26, 14 }, {  40, 14 }, {  55, 14 }, {  70, 14 }, {  92, 14 }, { 106, 14 }, { 121, 14 },
        { 136, 14 }, { 158, 14 }, { 173, 14 }, { 187, 14 }, { 202, 14 }, { 224, 14 }, {   4, 26 }, {  18, 26 },
        {  33, 26 }, {  48, 26 }, {  62, 26 }, {  77, 26 }, {  92, 26 }, { 106, 26 }, { 121, 26 }, { 136, 26 },
        { 151, 26 }, { 165, 26 }, { 180, 26 }, { 202, 26 }, { 224, 26 }, {   7, 36 }, {  26, 36 }, {  40, 36 },
        {  55, 36 }, {  70, 36 }, {  84, 36 }, {  99, 36 }, { 114, 36 }, { 128, 36 }, { 143, 36 }, { 158, 36 },
        { 173, 36 }, { 187, 36 }, { 206, 36 }, { 224, 36 }, {   9, 45 }, {  29, 45 }, {  44, 45 }, {  59, 45 },
        {  73, 45 }, {  88, 45 }, { 103, 45 }, { 118, 45 }, { 132, 45 }, { 147, 45 }, { 162, 45 }, { 176, 45 },
        { 200, 45 }, { 224, 45 }, {  13, 55 }, {  37, 55 }, {  51, 55 }, {  66, 55 }, {  81, 55 }, {  95, 55 },
        { 110, 55 }, { 125, 55 }, { 140, 55 }, { 154, 55 }, { 169, 55 }, { 189, 55 }, { 209, 55 }, { 224, 55 },
        {   6, 64 }, {  24, 64 }, {  42, 64 }, {  97, 64 }, { 152, 64 }, { 171, 64 }, { 195, 64 }, { 209, 64 },
        { 224, 64 }, {   0,  0 }, {   9,  0 }, {  18,  0 }, {  28,  0 }, {  37,  0 }, {  46,  0 }, {  55,  0 },
        {  64,  0 }, {  73,  0 }, { 176,  0 },
    },
    {
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
    }
};
#endif



static uint8_t encoder_state;
static int8_t  encoder_delta;
static bool    encoder_button;
static uint16_t encoder_button_timer;

void keyboard_post_init_kb(void) {
    i2c_init();

    // Keep every unused expander pin as an input. GPA0--GPA2 carry the
    // encoder and its switch, and use the MCP23017's internal pull-ups.
    uint8_t iodira = 0xFF;
    uint8_t gppua = 0x07;
    i2c_write_register(MCP23017_I2C_ADDRESS, MCP23017_IODIRA, &iodira, 1, 100);
    i2c_write_register(MCP23017_I2C_ADDRESS, MCP23017_GPPUA, &gppua, 1, 100);

    uint8_t data;
    if (i2c_read_register(MCP23017_I2C_ADDRESS, MCP23017_GPIOA, &data, 1, 100) == I2C_STATUS_SUCCESS) {
        encoder_state  = (~data) & 0x03;
        encoder_button = !(data & (1 << 2));
    }

    keyboard_post_init_user();
}

void matrix_scan_kb(void) {
    static const int8_t encoder_table[16] = {
         0, -1,  1,  0,
         1,  0,  0, -1,
        -1,  0,  0,  1,
         0,  1, -1,  0,
    };

    uint8_t data;
    if (i2c_read_register(MCP23017_I2C_ADDRESS, MCP23017_GPIOA, &data, 1, 100) == I2C_STATUS_SUCCESS) {
        uint8_t new_state = (~data) & 0x03;
        encoder_delta += encoder_table[(encoder_state << 2) | new_state];
        encoder_state = new_state;

        if (encoder_delta >= 4) {
            tap_code(KC_VOLU);
            encoder_delta = 0;
        } else if (encoder_delta <= -4) {
            tap_code(KC_VOLD);
            encoder_delta = 0;
        }

        bool new_button = !(data & (1 << 2));
        if (new_button != encoder_button && timer_elapsed(encoder_button_timer) >= 20) {
            encoder_button = new_button;
            encoder_button_timer = timer_read();
            if (encoder_button) {
                tap_code(KC_MUTE);
            }
        }
    }

    matrix_scan_user();
}
