#include <Arduino.h>

#include "display.h"
#include "robot.h"
#include "touch.h"
#include "motors.h"

RobotState currentState = ATTENTION;

enum MoveState
{
    MOVE_STOP,
    MOVE_FORWARD,
    MOVE_LEFT,
    MOVE_RIGHT
};

MoveState moveState = MOVE_STOP;

unsigned long moveStartTime = 0;
unsigned long moveDuration = 0;

unsigned long stateStartTime = 0;
unsigned long petReleaseTime = 0;

unsigned long lastLook = 0;
unsigned long lastExpression = 0;

int currentExpression = 0;

void enterAttention()
{
    currentState = ATTENTION;

    stateStartTime = millis();

    lookCenter();

    setExpressionNeutral();

    stopMotors();

    Serial.println("STATE -> ATTENTION");
}

void robotBegin()
{
    touchBegin();

    enterAttention();
}

void enterRoam()
{
    currentState = ROAM;

    stateStartTime = millis();

    moveStartTime = 0;      // Force a new roaming decision immediately
    moveDuration = 0;

    setExpressionNeutral();

    Serial.println("STATE -> ROAM");
}

void enterPet()
{
    currentState = PET;

    stateStartTime = millis();

    lookCenter();

    setExpressionHappy();

    stopMotors();

    Serial.println("STATE -> PET");
}

void updateRoaming()
{
    if (millis() - moveStartTime < moveDuration)
        return;

    moveStartTime = millis();

    moveState = (MoveState)random(4);

    switch (moveState)
    {
        case MOVE_STOP:
            stopMotors();
            moveDuration = random(800, 1800);
            Serial.println("ROAM -> STOP");
            break;

        case MOVE_FORWARD:
            setMotor(1, 1);
            moveDuration = random(1500, 3000);
            Serial.println("ROAM -> FORWARD");
            break;

        case MOVE_LEFT:
            setMotor(-1, 1);
            moveDuration = random(500, 1200);
            Serial.println("ROAM -> LEFT");
            break;

        case MOVE_RIGHT:
            setMotor(1, -1);
            moveDuration = random(500, 1200);
            Serial.println("ROAM -> RIGHT");
            break;
    }
}

void robotUpdate()
{
    unsigned long now = millis();

    // ---------- Look around ----------

    if(now - lastLook > 3000)
    {
        lastLook = now;

        switch(random(5))
        {
            case 0: lookCenter(); break;
            case 1: lookLeft(); break;
            case 2: lookRight(); break;
            case 3: lookUp(); break;
            case 4: lookDown(); break;
        }
    }

    // ---------- Change expression ----------

    if(now - lastExpression > 6000)
    {
        lastExpression = now;

        currentExpression++;

        if(currentExpression > 2)
            currentExpression = 0;

        switch(currentExpression)
        {
            case 0:
                setExpressionNeutral();
                break;

            case 1:
                setExpressionHappy();
                break;

            case 2:
                setExpressionSleep();
                break;
        }
    }

    switch(currentState)
  {
    case ATTENTION:

        if(millis() - stateStartTime > 10000)
        {
            enterRoam();
        }

        break;

    case ROAM:

        updateRoaming();

        break;

    case PET:

        if(isTouching())
        {
            setExpressionHappy();
        }

        if(!isTouching())
        {
            if(millis() - petReleaseTime > 2000)
            {
                enterRoam();
            }
        }

        break;

    case SLEEP:

        break;
  }

    displayUpdate();
    touchUpdate();

    if (touchStarted())
  {
    enterPet();
  }

    if (touchEnded())
  {
    petReleaseTime = millis();
  }
}