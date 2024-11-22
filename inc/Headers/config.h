/**
 * @file config.h
 * @brief Definiciones generales del proyecto.
 *
 * Este archivo contiene las constantes y configuraciones generales utilizadas en todo el proyecto.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "lpc17xx_pinsel.h"
#include "lpc17xx_pwm.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_adc.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_gpdma.h"
#include "lpc17xx_uart.h"

#define PUERTO_BOTON 2
#define PIN_BOTON 10
#define ANGULO_MAXIMO 180
#define PASO_ANGULO 1 // Grados a aumentar o disminuir por iteración
#define RETARDO_MS 20 // Retardo entre cambios de ángulo
#define BUFFER_SIZE 2 // 2 valores del ADC
#define CANAL_ADC_BATERIA 0 // Canal ADC para el nivel de batería
#define CANAL_ADC_TEMPERATURA 1 // Canal ADC para el LM35
#define UART_BAUD_RATE 9600 // Tasa de baud para comunicación UART

extern uint16_t dmaBuffer[BUFFER_SIZE];

#endif // CONFIG_H
