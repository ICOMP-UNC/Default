/**
 * @file pwm.h
 * @brief Prototipos de funciones para generar PWM.
 *
 * Este archivo contiene las declaraciones de las funciones necesarias para configurar
 * y utilizar PWM en el sistema.
 */
#ifndef PWM_H
#define PWM_H

#include "lpc17xx_pwm.h"

void configurarPWM(void);
void establecerAnguloServo(uint8_t angulo);

#endif // PWM_H
