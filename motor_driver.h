#ifndef __MOTOR_DRIVER__
#define __MOTOR_DRIVER__

#include <stdint.h>
#include <stdbool.h>

#include "motor_driver_config.h"

#ifndef MOTOR_DRIVER_PWM_TYPE
#error "Need define MOTOR_DRIVER_PWM_TYPE"
#else
typedef MOTOR_DRIVER_PWM_TYPE motor_pwm_t;
#endif // MOTOR_DRIVER_PWM_TYPE

#ifndef MOTOR_DRIVER_GPIO_TYPE
#error "Need define MOTOR_DRIVER_GPIO_TYPE"
#else
typedef MOTOR_DRIVER_GPIO_TYPE motor_gpio_t;
#endif // MOTOR_DRIVER_GPIO_TYPE

struct SMotor
{
    motor_pwm_t pwm;
    motor_gpio_t forward;
    motor_gpio_t backward;
};

typedef struct SMotor motor_t;

struct SMotorDriver
{
    motor_t left;
    motor_t right;
    motor_gpio_t stby;
};

typedef struct SMotorDriver motor_driver_t;

#ifndef MOTOR_DRIVER_SET_PWM_POWER
void MotorDriverSetPWMPower(motor_pwm_t* pwmHandler, uint8_t percent);
#define MOTOR_DRIVER_SET_PWM_POWER(pPWM, percent) MotorDriverSetPWMPower((pPWM), (percent))
#endif // MOTOR_DRIVER_SET_PWM_POWER

#ifndef MOTOR_DRIVER_SET_GPIO_STATE
void MotorDriverSetGPIOState(motor_gpio_t* gpio, bool state);
#define MOTOR_DRIVER_SET_GPIO_STATE(pGPIO, state) MotorDriverSetGPIOState((pGPIO), (state))
#endif // MOTOR_DRIVER_SET_GPIO_STATE

void MotorStop(motor_t* pMotor);
void MotorRunForward(motor_t* pMotor, uint8_t percent);
void MotorRunBackward(motor_t* pMotor, uint8_t percent);

void MotorDriverRunForward(motor_driver_t* pMotorDriver, uint8_t percent);
void MotorDriverRunBackward(motor_driver_t* pMotorDriver, uint8_t percent);
void MotorDriverRunLeft(motor_driver_t* pMotorDriver, uint8_t percent);
void MotorDriverRunRight(motor_driver_t* pMotorDriver, uint8_t percent);
void MotorDriverStop(motor_driver_t* pMotorDriver);

#endif // __MOTOR_DRIVER__
