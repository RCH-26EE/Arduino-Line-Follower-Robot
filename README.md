
# 🤖 Arduino Line-Follower Robot

An autonomous **line-following robot** built using an **Arduino Uno, L298N motor driver, 8-channel IR sensor array, and two DC geared motors**.

The robot detects a contrasting line on the ground using the IR sensor array and adjusts the speed/direction of the two motors to follow the path.

## 📌 Project Status

**Current status:** 🟡 Under development

* ✅ Arduino Uno setup completed
* ✅ Motor driver connected
* ✅ Two DC geared motors installed
* ✅ Motors tested successfully
* ✅ 8-channel IR sensor array connected
* 🔄 IR sensor testing and calibration
* ⏳ Line-following algorithm
* ⏳ Final autonomous testing

---

## 🛠️ Components

| Component                 | Quantity |
| ------------------------- | -------: |
| Arduino Uno               |        1 |
| L298N Motor Driver        |        1 |
| 8-channel IR Sensor Array |        1 |
| DC Geared Motors          |        2 |
| Robot Wheels              |        2 |
| Robot Chassis             |        1 |
| Breadboard                |        1 |
| Jumper Wires              |  Several |
| Battery Pack              |        1 |

---

## ⚙️ Hardware Architecture

```text
                ┌──────────────────┐
                │   IR SENSOR ARRAY│
                │    D1 ───── D8   │
                └────────┬─────────┘
                         │
                         ▼
                ┌──────────────────┐
                │    ARDUINO UNO   │
                │                  │
                │ Sensor Processing│
                │ Motor Control    │
                └────────┬─────────┘
                         │
                         ▼
                ┌──────────────────┐
                │      L298N       │
                │  Motor Driver    │
                └───────┬───┬──────┘
                        │   │
                       ▼     ▼
                    LEFT   RIGHT
                    MOTOR  MOTOR
```

---

## 🔌 IR Sensor Connections

The project uses an **8-channel IR sensor array**.

| IR Sensor | Arduino Uno |
| --------- | ----------- |
| VCC       | 5V          |
| GND       | GND         |
| D1        | D2          |
| D2        | D3          |
| D3        | D4          |
| D4        | D5          |
| D5        | D6          |
| D6        | D7          |
| D7        | D8          |
| D8        | D9          |
| IR        | 5V          |

The eight sensor outputs are read by Arduino digital pins **D2–D9**.

> **Note:** The original wiring reference used an Arduino Nano. The project was later moved to an Arduino Uno, while retaining the same digital pin numbers.

---

## 🔌 L298N Connections

| L298N Pin | Arduino Uno |
| --------- | ----------- |
| ENA       | D10         |
| IN1       | D12         |
| IN2       | D13         |
| IN3       | A0          |
| IN4       | A1          |
| ENB       | D11         |
| GND       | GND         |

### Motors

```text
L298N OUT1 ── Left Motor wire 1
L298N OUT2 ── Left Motor wire 2

L298N OUT3 ── Right Motor wire 1
L298N OUT4 ── Right Motor wire 2
```

If one motor rotates in the opposite direction, its two motor wires can be swapped.

---

## 🔋 Power Connections

The motor battery is connected directly to the L298N motor power input.

```text
Battery (+) ───── L298N +12V / Vs

Battery (-) ───── L298N GND
                         │
                         └──── Arduino GND
```

### ⚠️ Important

The motor battery should **not** be connected directly to the Arduino 5V pin.

A **common ground** between the Arduino and L298N is required for reliable control.

---

## 💻 Software

The project is programmed using the **Arduino IDE**.

### Development stages

1. Arduino Uno setup
2. Motor driver testing
3. Individual motor testing
4. IR sensor testing
5. Sensor calibration
6. Line-following algorithm
7. Motor speed tuning
8. Full-track testing

---

## 🧪 Sensor Testing

Before implementing the complete line-following algorithm, the eight IR sensors are tested individually.

The sensor test reads:

```text
D1 → Arduino D2
D2 → Arduino D3
D3 → Arduino D4
D4 → Arduino D5
D5 → Arduino D6
D6 → Arduino D7
D7 → Arduino D8
D8 → Arduino D9
```

Example Serial Monitor output:

```text
1 1 1 1 0 0 1 1
```

The output depends on the sensor module's logic and whether the sensors are positioned over the line or the background.

---

## 🧠 Line-Following Principle

The eight IR sensors continuously detect the position of the line.

The Arduino interprets the sensor pattern and determines whether the robot should:

* Move forward
* Turn slightly left
* Turn slightly right
* Make a sharper correction
* Stop when the line is lost

The motor driver then converts these control signals into movement of the left and right motors.

---

## 🔧 Troubleshooting During Development

### Problem 1 — Arduino upload errors

The project initially encountered serial-port/upload issues while setting up the Arduino.

**Solution:** The Arduino connection and serial communication were checked before continuing with motor control.

### Problem 2 — Motor movement

The motor driver and motors were tested independently before implementing the line-following algorithm.

**Result:** Motors were successfully made to operate.

### Problem 3 — IR sensor readings

The sensor array did not initially provide reliable readings.

**Current investigation:**

* Checking sensor wiring
* Testing individual sensor outputs
* Checking VCC/GND connections
* Testing black vs. white surfaces
* Adjusting sensor sensitivity
* Verifying Arduino input pins

---

## 📷 Project Documentation

Photos and videos of the robot, wiring, sensor testing, and final demonstration will be added to the `images/` and `docs/` folders as development continues.

---

## 🚀 Future Improvements

* Implement an 8-sensor line-following algorithm
* Add PWM-based motor speed control
* Calibrate sensor thresholds
* Implement proportional/PID control
* Improve turning accuracy
* Optimize robot speed
* Add obstacle detection
* Create a cleaner permanent circuit instead of the breadboard prototype

---

## 👩‍💻 Project Development

This project was developed as a hands-on embedded systems and robotics project to understand:

* Arduino programming
* Digital sensors
* Motor drivers
* PWM motor control
* Embedded debugging
* Autonomous navigation
* Basic robotics control systems

---

## 📜 License

This project is intended for educational and experimental purposes.
