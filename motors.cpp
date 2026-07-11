#include <Arduino.h>
#include "config.h"
#include "motors.h"

void motorsBegin()
{
    pinMode(MOTOR_L_IN1, OUTPUT);
    pinMode(MOTOR_L_IN2, OUTPUT);

    pinMode(MOTOR_R_IN1, OUTPUT);
    pinMode(MOTOR_R_IN2, OUTPUT);

    pinMode(DRV_SLEEP, OUTPUT);

    digitalWrite(DRV_SLEEP, HIGH);

    stopMotors();
}

void stopMotors()
{
    digitalWrite(MOTOR_L_IN1, LOW);
    digitalWrite(MOTOR_L_IN2, LOW);

    digitalWrite(MOTOR_R_IN1, LOW);
    digitalWrite(MOTOR_R_IN2, LOW);
}

void setMotor(int left, int right)
{
    // LEFT MOTOR

    if(left > 0)
    {
        digitalWrite(MOTOR_L_IN1, HIGH);
        digitalWrite(MOTOR_L_IN2, LOW);
    }
    else if(left < 0)
    {
        digitalWrite(MOTOR_L_IN1, LOW);
        digitalWrite(MOTOR_L_IN2, HIGH);
    }
    else
    {
        digitalWrite(MOTOR_L_IN1, LOW);
        digitalWrite(MOTOR_L_IN2, LOW);
    }

    // RIGHT MOTOR

    if(right > 0)
    {
        digitalWrite(MOTOR_R_IN1, HIGH);
        digitalWrite(MOTOR_R_IN2, LOW);
    }
    else if(right < 0)
    {
        digitalWrite(MOTOR_R_IN1, LOW);
        digitalWrite(MOTOR_R_IN2, HIGH);
    }
    else
    {
        digitalWrite(MOTOR_R_IN1, LOW);
        digitalWrite(MOTOR_R_IN2, LOW);
    }
}