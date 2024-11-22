#include "uart.h"
#include "lpc17xx_pinsel.h"

/**
 * @brief Configura la UART para la comunicación serial.
 *
 * Esta función configura la UART3 en el LPC1769 con una tasa de baudios de 9600,
 * sin paridad, 8 bits de datos y 1 bit de parada. El pin P0.0 se configura para
 * la función UART3 TX.
 */
void configurarUART() {
    PINSEL_CFG_Type pinConfig;
    pinConfig.Portnum = PINSEL_PORT_0;
    pinConfig.Pinnum = PINSEL_PIN_0;
    pinConfig.Funcnum = PINSEL_FUNC_2;
    PINSEL_ConfigPin(&pinConfig);

    UART_CFG_Type UARTConfig;
    UARTConfig.Baud_rate = 9600;
    UARTConfig.Parity = UART_PARITY_NONE;
    UARTConfig.Databits = UART_DATABIT_8;
    UARTConfig.Stopbits = UART_STOPBIT_1;

    UART_Init(LPC_UART3, &UARTConfig);
    UART_TxCmd(LPC_UART3, ENABLE);
}
