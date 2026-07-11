# Companion Robot 🤖

An ESP32-C3 powered desktop companion robot with expressive OLED animations, autonomous roaming, touch interaction, and planned voice AI integration using Xiaozhi.

> This project started from the TechTalkies "Chatbot on Wheels" project but has been redesigned into a modular, extensible architecture for future development.

---

# Features

## Current Features

- ✅ ESP32-C3 based firmware
- ✅ 1.3" SH1106 OLED display
- ✅ Smooth eye movement animations
- ✅ Multiple facial expressions
    - Neutral
    - Happy
    - Sleepy
- ✅ Random blinking
- ✅ Autonomous roaming
- ✅ Touch sensor interaction
- ✅ Robot state machine
- ✅ Modular codebase

---

# Planned Features

- 🔲 Smooth expression transitions
- 🔲 Curious eye movement
- 🔲 Idle animations
- 🔲 Better roaming behaviour
- 🔲 Voice interaction (Xiaozhi)
- 🔲 Microphone support (INMP441)
- 🔲 Speaker output (MAX98357A)
- 🔲 OTA firmware updates
- 🔲 Battery monitoring
- 🔲 WiFi provisioning
- 🔲 Charging animation
- 🔲 Sleep mode
- 🔲 Personality engine

---

# Hardware

## Controller

- ESP32-C3 SuperMini

## Display

- 1.3" SH1106 OLED
- I2C
- 128×64

## Motor Driver

- DRV8833

## Motors

- 2 × N20 Gear Motors

## Touch

- TTP223 Capacitive Touch Sensor

## Audio (Upcoming)

- INMP441 I2S Microphone
- MAX98357A I2S Audio Amplifier
- 8Ω Speaker

## Power

- 803040 LiPo Battery
- TP4056 Charging Module

---

# Software Architecture

```
CompanionRobot
│
├── CompanionRobot.ino
│
├── config.h
│
├── display.cpp
├── display.h
│
├── motors.cpp
├── motors.h
│
├── robot.cpp
├── robot.h
│
├── touch.cpp
└── touch.h
```

---

# Robot States

```
          ATTENTION
               │
               ▼
             ROAM
               ▲
               │
             PET
               │
               ▼
            (Future)
             SLEEP
               │
               ▼
            TALKING
```

---

# Current Behaviour

## Attention

- Robot looks forward
- Neutral face
- Waits for interaction

## Roam

- Random movement
- Random eye movement
- Random blinking

## Pet

- Triggered by touch sensor
- Happy face
- Motors stop
- Returns to roaming after release

---

# Display Engine

Supports

- Smooth eye movement
- Facial expressions
- Blink animation
- Eye positioning

Future improvements

- Talking animation
- Eyebrows
- Mouth animation
- Expression interpolation

---

# Motor System

Current

- Forward
- Left
- Right
- Stop

Future

- PWM speed control
- Smooth acceleration
- Obstacle avoidance

---

# Touch System

Current

- Touch detection
- Pet mode

Future

- Tap
- Double tap
- Long press
- Gesture detection

---

# Future AI Integration

The robot is designed to integrate with Xiaozhi AI.

Planned pipeline

```
INMP441
     │
     ▼
 ESP32-C3
     │
     ▼
 Xiaozhi AI
     │
     ▼
 MAX98357A
     │
     ▼
 Speaker
```

During conversations the robot will

- Blink
- Animate eyes
- Move mouth
- React emotionally
- Turn towards the speaker
- Express listening and thinking states

---

# Development Philosophy

The project is being developed incrementally.

Each milestone leaves the robot in a fully working state before introducing new functionality.

Current milestones

- ✅ Display
- ✅ Motors
- ✅ Touch
- ✅ State Machine
- ✅ Autonomous Roaming

Upcoming milestones

- ⏳ Better personality engine
- ⏳ Voice integration
- ⏳ OTA updates
- ⏳ Battery management
- ⏳ AI interaction

---

# Credits

Original inspiration:

TechTalkies – Chatbot on Wheels

https://github.com/TechTalkies/YouTube/tree/main/95_Chatbot_on_wheels

This project significantly restructures the original implementation into a modular architecture with improved maintainability and extensibility.

---

# License

This project is intended for learning and personal use.

Please respect the licenses of all third-party libraries and the original project that inspired this work.
