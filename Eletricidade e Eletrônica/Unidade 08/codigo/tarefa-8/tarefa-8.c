#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"


#define BTN_B 6
#define LED_R 13
#define BUZZER_PIN 21

void setup() {
    stdio_init_all();
    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_put(LED_R, 0);
}

// inicialização do PWM no pino do buzzer
void setup_buzzer() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f); // ajusta o divisor de clock
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(BUZZER_PIN, 0); // desliga o PWM inicialmente
}

// notas musicais para o alerta sonoro
uint alert_notes[] = {
    600, 300, 600, 300, 600, 300, 600, 300,  
    600, 300
};

// duração das notas em milissegundos
uint note_duration[] = {
    500, 500, 500, 500, 500, 500, 500, 500,  
    500, 500
};

// toca uma nota com a frequência e duração especificadas
void play_tone(uint frequency, uint duration_ms) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    uint32_t clock_freq = clock_get_hz(clk_sys);
    uint32_t top = clock_freq / frequency - 1;
    pwm_set_wrap(slice_num, top);
    pwm_set_gpio_level(BUZZER_PIN, top / 2); // 50% de duty cycle (volume médio)
    sleep_ms(duration_ms);
    pwm_set_gpio_level(BUZZER_PIN, 0); // desliga o som após a duração
}

// Função principal para tocar a música
void alert_sound() {
    for (int i = 0; i < sizeof(alert_notes) / sizeof(alert_notes[0]); i++) {
        play_tone(alert_notes[i], note_duration[i]);
    }
}

void alert() {
    gpio_put(LED_R, 1);
    alert_sound();
}

int main() {
    setup();
    setup_buzzer();

    while(true) {
        if (gpio_get(BTN_B) == 0) {
            while (gpio_get(BTN_B) == 0) {
                sleep_ms(200);
                alert();
            }
            gpio_put(LED_R, 0);
        }
        sleep_ms(20);
    }

    return 0;
}


