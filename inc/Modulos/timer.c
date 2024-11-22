#include "timer.h"

/**
 * @brief Configura el temporizador para generar interrupciones periódicas.
 *
 * Configura el temporizador para generar una interrupción cada 20 ms
 * utilizando el valor de la constante `RETARDO_MS`.
 */
void configurarTemporizador() {
    TIM_TIMERCFG_Type TimerConfig;
    TimerConfig.PrescaleOption = TIM_PRESCALE_USVAL;
    TimerConfig.PrescaleValue = 1000; // 1 ms por tick

    TIM_MATCHCFG_Type MatchConfig;
    MatchConfig.MatchChannel = 0;
    MatchConfig.IntOnMatch = ENABLE;
    MatchConfig.ResetOnMatch = ENABLE;
    MatchConfig.StopOnMatch = DISABLE;
    MatchConfig.MatchValue = RETARDO_MS; // Generar una interrupción cada 20 ms

    TIM_Init(LPC_TIM0, TIM_TIMER_MODE, &TimerConfig);
    TIM_ConfigMatch(LPC_TIM0, &MatchConfig);

    NVIC_EnableIRQ(TIMER0_IRQn);
    TIM_Cmd(LPC_TIM0, ENABLE);
}
