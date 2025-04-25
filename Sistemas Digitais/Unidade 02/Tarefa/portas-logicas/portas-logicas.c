#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "hardware/clocks.h"
#include "ssd1306.h"

#define BTN_A 5
#define BTN_B 6
#define LED_G 11
#define LED_R 13
#define ADC_CHANNEL_Y 0
#define VRY 27
// DISPLAY
#define I2C_PORT i2c1
#define PINO_SCL 14
#define PINO_SDA 15

ssd1306_t display;

void setup() {
    stdio_init_all();
    // DISPLAY
    i2c_init(I2C_PORT, 400*1000);
    gpio_set_function(PINO_SCL, GPIO_FUNC_I2C);
    gpio_set_function(PINO_SDA, GPIO_FUNC_I2C);
    gpio_pull_up(PINO_SCL);
    gpio_pull_up(PINO_SDA);
    display.external_vcc=false;
    ssd1306_init(&display, 128, 64, 0x3C, I2C_PORT);
    // LEDs
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_put(LED_G, 0);
    gpio_put(LED_R, 0);
    // BUTTONs
    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A); // sem pressionar é 1
    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B); // sem pressionar é 1
    // JOYSTICK
    adc_init();
    adc_gpio_init(VRY);
    adc_select_input(ADC_CHANNEL_Y);
}

void draw(char *text) {
    ssd1306_clear(&display);
    ssd1306_draw_string(&display, 35, 25, 3, text);
    ssd1306_show(&display);
}

void pull(bool state) {
    if (state) {
        gpio_put(LED_R, 0);
        gpio_put(LED_G, 1);
    } else {
        gpio_put(LED_G, 0);
        gpio_put(LED_R, 1);
    }
}

void porta(int selected) {
    switch (selected) {
        case 1:
            if (gpio_get(BTN_A) == 0 || gpio_get(BTN_B) == 0) { pull(false); } 
            else { pull(true); }
            break;
        case 2:
            if (gpio_get(BTN_A) == 0 && gpio_get(BTN_B) == 0) { pull(false); }
            else { pull(true); }
            break;
        case 3:
            if (gpio_get(BTN_A) == 0) { pull(true); }
            else { pull(false); }
            break;
        case 4:
            if (gpio_get(BTN_A) == 1 && gpio_get(BTN_B) == 1) { pull(false); }
            else { pull(true); }
            break;
        case 5:
            if (gpio_get(BTN_A) == 0 && gpio_get(BTN_B) == 0) { pull(true); }
            else { pull(false); }
            break;
        case 6:
            if (gpio_get(BTN_A) == gpio_get(BTN_B)) { pull(false); }
            else { pull(true); }
            break;
        case 7:
            if (gpio_get(BTN_A) == gpio_get(BTN_B)) { pull(true); }
            else { pull(false); }
            break;
    }
}

void menu(int selected) {
    switch (selected) {
        case 1: 
            draw("AND");
            porta(selected);
            break;
        case 2: 
            draw("OR");
            porta(selected);
            break;
        case 3: 
            draw("NOT");
            porta(selected);
            break;
        case 4: 
            draw ("NAND");
            porta(selected);
            break;
        case 5: 
            draw("NOR");
            porta(selected);
            break;
        case 6: 
            draw("XOR");
            porta(selected);
            break;
        case 7: 
            draw("XNOR");
            porta(selected);
            break;
    }
}


int main() {
    setup();
    int selected = 1;
    while (true) {
        int adc_raw_y = adc_read();
        if (adc_raw_y < 500) {
            sleep_ms(200);
            if (selected == 7) {
                selected = 1;
            } else {
                selected++;
            }
        } 
        menu(selected);
    }
}