#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // GPIO 22 para o servomotor

int main() {
    stdio_init_all();

    // Configura a GPIO 22 como saída de PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    // Configuração do PWM
    pwm_set_clkdiv(slice_num, 125); //125 de prescaler para o determinado wrap, para que seja possível obter o 50Hz
    pwm_set_wrap(slice_num, 19999);  // Ajusta o wrap para 19999 para que tenhamos 20000 ciclos
    pwm_set_enabled(slice_num, true);      // Inicializa o PWM com as configurações definidas

    pwm_set_gpio_level(SERVO_PIN, 2400);
    sleep_ms(5000);  // Aguarda 5 segundos

    pwm_set_gpio_level(SERVO_PIN, 1470);
    sleep_ms(5000);  // Aguarda 5 segundos

    pwm_set_gpio_level(SERVO_PIN, 500);
    sleep_ms(5000);  // Aguarda 5 segundos

    while (true) {
        // Movimenta suavemente de 0° para 180° com incrementos de 5 µs
        for (int duty = 500; duty <= 2400; duty += 5) {
            pwm_set_gpio_level(SERVO_PIN, duty);
            sleep_ms(10);  // Aguarda 10 ms para suavizar o movimento
        }

        // Movimenta suavemente de 180° para 0° com decrementos de 5 µs
        for (int duty = 2400; duty >= 500; duty -= 5) {
            pwm_set_gpio_level(SERVO_PIN, duty);
            sleep_ms(10);  // Aguarda 10 ms para suavizar o movimento
        }
    }

    return 0;
}
