#include "config.h"
#include "motors.h"
#include "display.h"
#include "robot.h"

void setup()
{
    Serial.begin(115200);

    Serial.println();
    Serial.println("Companion Robot V1");

    motorsBegin();
    displayBegin();
    robotBegin();
}

void loop()
{
    robotUpdate();
}