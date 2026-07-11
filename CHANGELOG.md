# Changelog

All notable changes to this project will be documented in this file.

This project follows an incremental development process where every milestone results in a fully working robot before adding new functionality.

---

## [0.8.0] - Autonomous Roaming

### Added
- Robot movement state machine
- Random roaming behaviour
- Random forward movement
- Random left turns
- Random right turns
- Random idle stops
- Movement timer system
- Motor control integrated into robot state machine

### Improved
- Clean separation between robot state and movement logic
- Pet mode immediately interrupts roaming
- Modular movement architecture for future expansion

---

## [0.7.0] - Robot State Machine

### Added
- Robot state machine
- ATTENTION state
- ROAM state
- PET state
- State transition timers
- State helper functions
- Serial debugging for state changes

### Improved
- Centralized robot behaviour
- Easier future expansion for Sleep and Talking states

---

## [0.6.0] - Touch Interaction

### Added
- Dedicated touch module
- Touch event detection
- Touch start detection
- Touch release detection
- Pet mode activation
- Happy face on touch

### Improved
- Modular touch handling
- Removed touch logic from display code

---

## [0.5.0] - Face Animation Engine

### Added
- Smooth eye movement
- Target eye positions
- Eye interpolation
- Random eye movement
- Multiple facial expressions
- Neutral expression
- Happy expression
- Sleepy expression

### Improved
- Removed blocking delays
- Modular display engine

---

## [0.4.0] - OLED Display

### Added
- SH1106 display support
- Face rendering engine
- Eye drawing
- Mouth drawing
- Display module

### Fixed
- OLED initialization
- I2C configuration for ESP32-C3
- SH1106 compatibility

---

## [0.3.0] - Motor Driver

### Added
- DRV8833 driver support
- Motor initialization
- Forward movement
- Left turn
- Right turn
- Stop function
- Motor abstraction layer

### Fixed
- DRV8833 SLEEP pin handling
- ESP32-C3 GPIO mapping

---

## [0.2.0] - Hardware Bring-up

### Added
- ESP32-C3 SuperMini support
- Project structure
- Configuration header
- Modular source layout

### Fixed
- Board configuration
- Upload issues
- Serial communication
- Boot configuration

---

## [0.1.0] - Initial Project

### Added
- Initial project setup
- Arduino IDE configuration
- Basic project compilation
- Hardware verification

---

# Upcoming

## [0.9.0] - Personality Engine

### Planned
- Better idle behaviour
- Curious expressions
- Expression transitions
- Natural eye movement
- Improved blinking
- Better roaming decisions

---

## [1.0.0] - Interactive Companion

### Planned
- Voice interaction
- Xiaozhi AI integration
- INMP441 microphone
- MAX98357A speaker
- Talking animations
- Listening animations
- Emotional reactions

---

## Future Roadmap

### Hardware
- Battery monitoring
- OTA updates
- Charging animation
- Sleep mode
- Power management

### Behaviour
- Curious mode
- Idle mode
- Sleep mode
- Wake animation
- Emotional engine

### AI
- Voice conversation
- Context memory
- Sound localization
- Personality profiles