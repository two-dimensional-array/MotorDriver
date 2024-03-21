#include "motor_driver.h"

void MotorStop(motor_t* pMotor)
{
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotor->forward, false);
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotor->backward, false);
}

void MotorRunForward(motor_t* pMotor, uint8_t percent)
{
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotor->forward, true);
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotor->backward, false);
    MOTOR_DRIVER_SET_PWM_POWER(&pMotor->pwm, percent);
}

void MotorRunBackward(motor_t* pMotor, uint8_t percent)
{
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotor->forward, false);
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotor->backward, true);
    MOTOR_DRIVER_SET_PWM_POWER(&pMotor->pwm, percent);
}

void MotorDriverRunForward(motor_driver_t* pMotorDriver, uint8_t percent)
{
    MotorRunForward(&pMotorDriver->left, percent);
    MotorRunForward(&pMotorDriver->right, percent);
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotorDriver->stby, true);
}

void MotorDriverRunBackward(motor_driver_t* pMotorDriver, uint8_t percent)
{
    MotorRunBackward(&pMotorDriver->left, percent);
    MotorRunBackward(&pMotorDriver->right, percent);
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotorDriver->stby, true);
}

void MotorDriverRunLeft(motor_driver_t* pMotorDriver, uint8_t percent)
{
    MotorRunForward(&pMotorDriver->left, percent);
    MotorRunBackward(&pMotorDriver->right, percent);
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotorDriver->stby, true);
}

void MotorDriverRunRight(motor_driver_t* pMotorDriver, uint8_t percent)
{
    MotorRunBackward(&pMotorDriver->left, percent);
    MotorRunForward(&pMotorDriver->right, percent);
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotorDriver->stby, true);
}

void MotorDriverStop(motor_driver_t* pMotorDriver)
{
    MotorStop(&pMotorDriver->left);
    MotorStop(&pMotorDriver->right);
    MOTOR_DRIVER_SET_GPIO_STATE(&pMotorDriver->stby, false);
}
