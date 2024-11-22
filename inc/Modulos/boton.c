#include "boton.h"

/**
 * @brief Configura el botón para generar una interrupción por flanco de bajada.
 *
 * Esta función configura un pin GPIO como entrada con resistencia pull-up
 * y genera una interrupción cuando se detecta un flanco de bajada en el pin
 * correspondiente al botón.
 */
void configurarBoton() {
    PINSEL_CFG_Type PinConfig;
    PinConfig.Portnum = PUERTO_BOTON;
    PinConfig.Pinnum = PIN_BOTON;
    PinConfig.Funcnum = 0; // Configurar como GPIO
    PinConfig.Pinmode = PINSEL_PINMODE_PULLUP;
    PinConfig.OpenDrain = PINSEL_PINMODE_NORMAL;
    PINSEL_ConfigPin(&PinConfig);

    GPIO_SetDir(PUERTO_BOTON, (1 << PIN_BOTON), 0); // Configurar como entrada

    GPIO_IntCmd(PUERTO_BOTON, (1 << PIN_BOTON), 1); // Interrupción por flanco de bajada
    NVIC_EnableIRQ(EINT3_IRQn);
}
