#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "hardware/adc.h"
#include "hardware/clocks.h"
#include "ssd1306.h"
#include "ws2818b.pio.h"

// MATRIZ DE LED
#define LED_PIN 7
#define LED_COUNT 25
// LED RGB
#define LED_G 11
#define LED_R 13
// JOYSTICK
#define ADC_CHANNEL_Y 0
#define VRY 27
#define JOYSTICK_BTN 22
// DISPLAY
#define I2C_PORT i2c1
#define PINO_SCL 14
#define PINO_SDA 15

ssd1306_t display;

void setup() {
    stdio_init_all();
    // RGB
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_put(LED_G, 0);
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_put(LED_R, 0);
    // JOYSTICK
    adc_init();
    adc_gpio_init(VRY);
    adc_select_input(ADC_CHANNEL_Y);
    gpio_init(JOYSTICK_BTN);
    gpio_set_dir(JOYSTICK_BTN, GPIO_OUT);
    gpio_pull_up(JOYSTICK_BTN);
    // OLED
    i2c_init(I2C_PORT, 400*1000);// I2C Inicialização. Usando 400Khz.
    gpio_set_function(PINO_SCL, GPIO_FUNC_I2C);
    gpio_set_function(PINO_SDA, GPIO_FUNC_I2C);
    gpio_pull_up(PINO_SCL);
    gpio_pull_up(PINO_SDA);
    display.external_vcc=false;
    ssd1306_init(&display, 128, 64, 0x3C, I2C_PORT);
    ssd1306_clear(&display);
}

// Definição de pixel GRB
struct pixel_t {
    uint8_t G, R, B; // Três valores de 8-bits compõem um pixel.
  };
  typedef struct pixel_t pixel_t;
  typedef pixel_t npLED_t; // Mudança de nome de "struct pixel_t" para "npLED_t" por clareza.
  
// Declaração do buffer de pixels que formam a matriz.
npLED_t leds[LED_COUNT];
  
// Variáveis para uso da máquina PIO.
PIO np_pio;
uint sm;
  
int matriz[5][5][3] = {
    {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

// Inicializa a máquina PIO para controle da matriz de LEDs.
void initPio() {
  
    // Cria programa PIO.
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
  
    // Toma posse de uma máquina PIO.
    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0) {
      np_pio = pio1;
      sm = pio_claim_unused_sm(np_pio, true); // Se nenhuma máquina estiver livre, panic!
    }

    // Inicia programa na máquina PIO obtida.
    ws2818b_program_init(np_pio, sm, offset, LED_PIN, 800000.f);

    // Limpa buffer de pixels.
    for (uint i = 0; i < LED_COUNT; ++i) { // POSSIVELMENTE TEM QUE TROCAR O LED_COUNT PRA 4 PRA PEGAR COR SO PARA OS 4 PRIMEIROS DA MATRIZ
    leds[i].R = 0;
    leds[i].G = 0;
    leds[i].B = 0;
  }

}


// RECEBE O ENDEREÇO DO GETINDEX E O VALOR DE R G B PARA AQUELE LED ESPECIFICO
void setLEDPio(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    leds[index].R = r;
    leds[index].G = g;
    leds[index].B = b;
}


// Limpa o buffer de pixels.
void clearPio() {
    for (uint i = 0; i < LED_COUNT; ++i)
      npSetLED(i, 0, 0, 0);
  }
 
// PASSAR A LINHA E A COLUNA COMO PARÂMETROS PARA CALCULAR ENDEREÇO
int getIndex(int x, int y) {
    // Se a linha for par (0, 2, 4), percorremos da esquerda para a direita.
    // Se a linha for ímpar (1, 3), percorremos da direita para a esquerda.
    if (y % 2 == 0) {
        return 24-(y * 5 + x); // Linha par (esquerda para direita).
    } else {
        return 24-(y * 5 + (4 - x)); // Linha ímpar (direita para esquerda).
    }
}

// DESENHAR A MATRIZ APÓS SETAR OS LEDS (ÚLTIMA ETAPA), O INDEX É O MESMO DE GETINDEX
void writePio() {
    // Escreve cada dado de 8-bits dos pixels em sequência no buffer da máquina PIO.
    for (uint i = 0; i < LED_COUNT; ++i) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}

// ITERA POR TODA A MATRIZ E ADICIONA OS VALORES PARA TODOS OS LEDS CONFORME OS VALORES DA MATRIZ MATRIZ
void render() {
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) {
            int index = getIndex(i, j);
            setLEDPio(index, matriz[i][j][0], matriz[i][j][1], matriz[i][j][2]);
        }
    }
}



int main() {
    setup();
    initPio();

  }