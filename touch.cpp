#include <Arduino.h>

#include "config.h"
#include "touch.h"

bool currentTouch = false;
bool previousTouch = false;

void touchBegin()
{
    pinMode(TOUCH_PIN, INPUT);
}

void touchUpdate()
{
    previousTouch = currentTouch;
    currentTouch = digitalRead(TOUCH_PIN);
}

bool isTouching()
{
    return currentTouch;
}

bool touchStarted()
{
    return currentTouch && !previousTouch;
}

bool touchEnded()
{
    return !currentTouch && previousTouch;
}