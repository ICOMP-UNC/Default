/**
 * @file main.c
 * @brief Archivo principal para configurar el sistema.
 *
 * Este archivo inicializa todos los módulos necesarios para el correcto funcionamiento del sistema
 * y contiene el bucle principal que espera interrupciones.
 */

#include "config.h"
#include "pwm.h"
#include "adc.h"
#include "uart.h"
#include "timer.h"
#include "dma.h"
#include "boton.h"

/**
 * @brief Función principal que configura todos los módulos y espera interrupciones.
 *
 * La función inicializa los módulos de PWM, ADC, UART, temporizadores, DMA y el botón.
 * Luego entra en un bucle esperando interrupciones.
 *
 * @return int Código de estado (no se utiliza en este caso).
 */
int main(void) {
    configurarPWM();
    configurarBoton();
    configurarADC();
    configurarUART();
    configurarTemporizador();
    configurarDMA();

    while (1) {
        __WFI(); // Esperar interrupción
    }
}
