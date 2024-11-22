/**
 * @file adc.c
 * @brief Funciones para la configuración y manejo del ADC.
 *
 * Este archivo contiene las funciones necesarias para configurar y utilizar el ADC
 * para leer los valores de la batería y la temperatura.
 */
#include "adc.h"
#include "lpc17xx_pinsel.h"

extern uint16_t dmaBuffer[2]; // Definido en main.c

/**
 * @brief Configura el ADC para leer los canales de la batería y la temperatura.
 *
 * Esta función configura los pines y el ADC para que pueda leer los valores
 * de los sensores de la batería y la temperatura.
 */
void configurarADC() {
    PINSEL_CFG_Type pinConfig;

    pinConfig.Portnum = PINSEL_PORT_0;
    pinConfig.Pinnum = PINSEL_PIN_23; // Canal batería
    pinConfig.Funcnum = PINSEL_FUNC_1;
    PINSEL_ConfigPin(&pinConfig);

    pinConfig.Pinnum = PINSEL_PIN_24; // Canal temperatura
    PINSEL_ConfigPin(&pinConfig);

    ADC_Init(LPC_ADC, 200000);

    ADC_ChannelCmd(LPC_ADC, 0, ENABLE);
    ADC_ChannelCmd(LPC_ADC, 1, ENABLE);

    ADC_IntConfig(LPC_ADC, ADC_ADINTEN0, ENABLE);
    ADC_IntConfig(LPC_ADC, ADC_ADINTEN1, ENABLE);

    NVIC_EnableIRQ(ADC_IRQn);
}

/**
 * @brief Manejo de interrupciones generadas por ADC
 *
 * Esta funcion ejecuta una rutina luego de generarse una interrupcion de ADC
 */
void ADC_IRQHandler(void) {
    if (ADC_ChannelGetStatus(LPC_ADC, 0, ADC_DATA_DONE)) {
        dmaBuffer[0] = ADC_ChannelGetData(LPC_ADC, 0);
    }
    if (ADC_ChannelGetStatus(LPC_ADC, 1, ADC_DATA_DONE)) {
        dmaBuffer[1] = ADC_ChannelGetData(LPC_ADC, 1);
    }
}
