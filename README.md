# 🚗 Hand Motion Controlled Car

> A gesture-controlled car system built on two ATmega32 microcontrollers, communicating wirelessly over Bluetooth — where a simple tilt of your hand becomes real, physical motion.

---

## 📖 Overview

**Hand Motion Controlled Car** is a graduation project that replaces traditional joystick/button controls with natural hand gestures. An accelerometer worn on the hand detects orientation and motion, and that data is transmitted wirelessly to a car equipped with its own microcontroller — translating human movement into driving commands in real time.

The system is composed of two independent, communicating embedded modules:

| Module | Role |
|---|---|
| 🖐️ **Hand Module** | Reads hand motion via an MPU6050 accelerometer and transmits control commands |
| 🚙 **Car Module** | Receives commands and drives the DC motors accordingly |

---

## 🏗️ System Architecture

The entire codebase follows a **strict layered embedded architecture**, separating concerns cleanly across three layers:

```
┌─────────────────────────────┐
│         APP Layer            │  ← Application logic & control flow
├─────────────────────────────┤
│         HAL Layer            │  ← Hardware Abstraction (Motor, MPU6050, Bluetooth)
├─────────────────────────────┤
│         MCAL Layer           │  ← Microcontroller Abstraction (TWI/I2C, Timers, GPIO, UART)
└─────────────────────────────┘
```

This structure keeps hardware-specific code isolated from application logic, making the system easier to debug, extend, and port.

---

## 🔧 Hardware Components

| Component | Purpose |
|---|---|
| **ATmega32** (×2) | Core microcontroller for each module |
| **MPU6050** | 6-axis accelerometer/gyroscope for hand motion sensing |
| **HC-05** | Bluetooth module for wireless UART communication between modules |
| **L293D** | Motor driver IC for DC motor control |
| **DC Motors** | Physical car movement |

---

## 🔌 How It Works

1. The **Hand Module** continuously reads orientation data from the MPU6050 over **I2C/TWI**.
2. Motion data is processed and converted into directional commands (forward, backward, left, right, stop).
3. Commands are transmitted over **UART via HC-05 Bluetooth** to the Car Module.
4. The **Car Module** receives the commands and drives the DC motors using **PWM-controlled Timer signals** through the L293D driver.
5. The car responds in real time to the tilt and movement of your hand.

---

## ⚙️ Key Engineering Highlights

- ✅ Full **MCAL → HAL → APP** layered driver stack, built from scratch
- ✅ Custom **I2C/TWI driver** for reliable MPU6050 communication
- ✅ **PWM-based motor speed control** via Timer peripherals
- ✅ Wireless **UART/Bluetooth** communication protocol between two independent MCUs
- ✅ Architectural decision to replace flex sensors with an **MPU6050 accelerometer**, reducing cost while improving motion accuracy
- ✅ Simulated and validated in **Proteus** prior to hardware deployment

---

## 🛠️ Tools & Environment

- **IDE:** Atmel Studio
- **Simulation:** Proteus / SimulIDE
- **Language:** Embedded C
- **Communication Protocols:** I2C (TWI), UART, Bluetooth (HC-05)

---

## 📂 Project Structure

```
hand-motion-controlled-car/
├── Car_Module/
│   ├── APP/
│   ├── HAL/
│   └── MCAL/
├── Hand_Module/
│   ├── APP/
│   ├── HAL/
│   └── MCAL/
└── README.md
```

---

## 🚀 Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/Zyad5976/hand-motion-controlled-car.git
   ```
2. Open each module (`Car_Module` / `Hand_Module`) in **Atmel Studio**.
3. Build and flash each project to its respective ATmega32.
4. Pair the two HC-05 Bluetooth modules.
5. Power up both modules and start controlling the car with hand motion.

---

## 👤 Author

**Zyad Hussein (Eltawel)**
Mechatronics Engineer | Embedded Systems Developer

- GitHub: [@Zyad5976](https://github.com/Zyad5976)
- LinkedIn: [zyad-hussien-35a790199](https://www.linkedin.com/in/zyad-hussien-35a790199)

---

## 📜 License

This project is open for educational and personal use. Feel free to fork, learn from it, and build upon it.
