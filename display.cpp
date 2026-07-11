#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#include "config.h"
#include "display.h"

Adafruit_SH1106G oled(128,64,&Wire,-1);

float eyeX = 0;
float eyeY = 0;

float targetEyeX = 0;
float targetEyeY = 0;

bool blinkActive = false;

unsigned long blinkStart = 0;
unsigned long nextBlink = 0;

int normalEyeHeight = 28;

int eyeWidth = 28;
int eyeHeight = 28;

int mouthWidth = 24;
int mouthHeight = 5;

void displayBegin()
{
    Wire.begin(OLED_SDA, OLED_SCL);

    if(!oled.begin(0x3C,true))
    {
        while(true);
    }

    oled.clearDisplay();
    oled.display();
    randomSeed(micros());

    nextBlink = millis() + random(3000,7000);
}

void updateEyes()
{
    eyeX += (targetEyeX - eyeX) * 0.15;
    eyeY += (targetEyeY - eyeY) * 0.15;
}

void drawFace()
{
    oled.clearDisplay();

    int leftX = 22 + eyeX;
    int rightX = 78 + eyeX;

    int drawEyeY = 16 + eyeY;

    oled.fillRoundRect(leftX,
                       eyeY,
                       eyeWidth,
                       eyeHeight,
                       8,
                       SH110X_WHITE);

    oled.fillRoundRect(rightX,
                       eyeY,
                       eyeWidth,
                       eyeHeight,
                       8,
                       SH110X_WHITE);

    oled.fillRoundRect(
        52,
        54,
        mouthWidth,
        mouthHeight,
        3,
        SH110X_WHITE);

    oled.display();
}

void updateBlink()
{
    unsigned long now = millis();

    if (!blinkActive && now > nextBlink)
    {
        blinkActive = true;
        blinkStart = now;

        nextBlink = now + random(3000,7000);
    }

    if(blinkActive)
    {
        unsigned long t = now - blinkStart;

        if(t < 60)
        {
            eyeHeight = map(t,0,60,normalEyeHeight,2);
        }
        else if(t < 120)
        {
            eyeHeight = map(t,60,120,2,normalEyeHeight);
        }
        else
        {
            blinkActive = false;
            eyeHeight = normalEyeHeight;
        }
    }
}

void displayUpdate()
{
  updateEyes();
  updateBlink();
  drawFace();
}

void lookCenter()
{
    targetEyeX = 0;
    targetEyeY = 0;
}

void lookLeft()
{
    targetEyeX = -6;
}

void lookRight()
{
    targetEyeX = 6;
}

void lookUp()
{
    targetEyeY = -4;
}

void lookDown()
{
    targetEyeY = 4;
}

void setExpressionNeutral()
{
    eyeWidth = 28;
    normalEyeHeight = 28;
    eyeHeight = normalEyeHeight;

    mouthWidth = 24;
    mouthHeight = 5;
}

void setExpressionHappy()
{
    eyeWidth = 34;
    normalEyeHeight = 20;
    eyeHeight = normalEyeHeight;

    mouthWidth = 30;
    mouthHeight = 8;
}

void setExpressionSleep()
{
    eyeWidth = 34;
    normalEyeHeight = 4;
    eyeHeight = normalEyeHeight;
    mouthWidth = 20;
    mouthHeight = 2;
}