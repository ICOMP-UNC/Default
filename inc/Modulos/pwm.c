#include "pwm.h"
#include "lpc17xx_pinsel.h"

/**
 * @brief Configura el PWM para controlar un servo.
 *
 * Esta función configura el PWM en el pin P2.0 para controlar un servo.
 * Se configura el período del PWM en 20 ms y el ancho de pulso inicial en 1.5 ms.
 */
void configurarPWM() {
    // Configuración del pin P2.0 como PWM1.1
    PINSEL_CFG_Type PinConfig;
    PinConfig.Funcnum = 1;       // Función PWM
    PinConfig.OpenDrain = PINSEL_PINMODE_NORMAL;
    PinConfig.Pinmode = PINSEL_PINMODE_PULLUP;
    PinConfig.Portnum = 2;       // Puerto 2
    PinConfig.Pinnum = 0;        // Pin 0
    PINSEL_ConfigPin(&PinConfig);

    PWM_TIMERCFG_Type PWMConfig;
    PWMConfig.PrescaleOption = PWM_TIMER_PRESCALE_USVAL;
    PWMConfig.PrescaleValue = 1; // 1 µs

    PWM_Init(LPC_PWM1, PWM_MODE_TIMER, &PWMConfig);

    uint32_t periodMatch = 20000; // 20 ms para un servo de 50Hz
    PWM_MatchUpdate(LPC_PWM1, 0, periodMatch, PWM_MATCH_UPDATE_NOW);

    uint32_t pulseMatch = 1500; // Pulso inicial
    PWM_MatchUpdate(LPC_PWM1, 1, pulseMatch, PWM_MATCH_UPDATE_NOW);

    PWM_MATCHCFG_Type MatchConfig;
    MatchConfig.MatchChannel = 0;
    MatchConfig.IntOnMatch = DISABLE;
    MatchConfig.ResetOnMatch = ENABLE;
    MatchConfig.StopOnMatch = DISABLE;

    PWM_ConfigMatch(LPC_PWM1, &MatchConfig);
    MatchConfig.ResetOnMatch = DISABLE;
    PWM_ConfigMatch(LPC_PWM1, &MatchConfig);

    PWM_ChannelCmd(LPC_PWM1, 1, ENABLE);

    PWM_ResetCounter(LPC_PWM1);
    PWM_CounterCmd(LPC_PWM1, ENABLE);
    PWM_Cmd(LPC_PWM1, ENABLE);
}

void establecerAnguloServo(uint8_t angulo) {
    uint32_t anchoPulso = 1000 + (angulo * 1000) / 180;
    PWM_MatchUpdate(LPC_PWM1, 1, anchoPulso, PWM_MATCH_UPDATE_NOW);
}
