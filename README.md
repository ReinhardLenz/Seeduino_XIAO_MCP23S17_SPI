# MCP23S17 LED Control with Seeeduino XIAO

## Overview

This project demonstrates how to control external LEDs using an **MCP23S17 16-bit I/O expander** connected to a **Seeeduino XIAO (SAMD21)** microcontroller via **SPI**. The Seeeduino XIAO provides power and SPI control signals, while the MCP23S17 drives two green LEDs through current-limiting resistors.

This setup is useful when additional GPIOs are required beyond those available on the microcontroller.

---


## Circuit diagram

<img width="919" height="1760" alt="circuit_image1" src="https://github.com/user-attachments/assets/84dc66ac-5d35-45b1-930b-f57fbc6825d7" />


## Circuit photo with SAEAE 24MHz8CH Analyzer

![mcp23s17](https://github.com/user-attachments/assets/85eace06-94ac-44be-b27a-e6361845a788)


## Circuit Summary

* **Microcontroller:** Seeeduino XIAO (SAMD21)
* **I/O Expander:** MCP23S17 (SPI interface)
* **Outputs:** Two green LEDs
* **Current Limiting:** Two 220 Ω resistors
* **Supply Voltage:** 3.3 V (from Seeeduino XIAO)

The LEDs are powered from 3.3 V and switched on/off by the MCP23S17 GPIO pins (GPA0 and GPA1), sinking current through the resistors.

---

## Components

### 1. Seeeduino XIAO

**Description:** Compact microcontroller board based on the SAMD21.

**Relevant Pins:**

* `3V3` – Power supply
* `GND` – Ground
* `A10 / D10 / MOSI` – SPI MOSI
* `A9 / D9 / MISO` – SPI MISO
* `A8 / D8 / SCK` – SPI Clock
* `A0 / D0 / DAC` – Chip Select (CS)

---

### 2. MCP23S17 – 16-bit I/O Expander

**Description:** SPI-based GPIO expander providing 16 programmable I/O pins.

**Relevant Pins:**

* `VDD` – 3.3 V supply
* `VSS` – Ground
* `RESET` – Reset (tied to 3.3 V)
* `SI` – SPI MOSI
* `SO` – SPI MISO
* `SCK` – SPI Clock
* `CS` – Chip Select
* `GPA0`, `GPA1` – GPIO outputs driving LEDs

---

### 3. Resistors (2 × 220 Ω)

**Description:** Current-limiting resistors for the LEDs.

**Properties:**

* Resistance: 220 Ω

---

### 4. Green LEDs (2x)

**Description:** Standard green LEDs used as visual indicators.

**Pins:**

* Anode (+)
* Cathode (−)

---

## Wiring Details

### Seeeduino XIAO ↔ MCP23S17

| Seeeduino XIAO Pin | MCP23S17 Pin | Description     |
| ------------------ | ------------ | --------------- |
| GND                | VSS          | Ground          |
| 3V3                | VDD          | Power supply    |
| 3V3                | RESET        | Reset tied high |
| A10 / D10 (MOSI)   | SI           | SPI MOSI        |
| A9 / D9 (MISO)     | SO           | SPI MISO        |
| A8 / D8 (SCK)      | SCK          | SPI Clock       |
| A0 / D0 (DAC)      | CS           | Chip Select     |

---

### LED Connections

#### LED 1 (via GPA0)

* **Anode:** Connected to 3V3 (Seeeduino XIAO)
* **Cathode:** Connected to resistor (220 Ω)
* **Resistor other end:** Connected to `GPA0` (MCP23S17)

#### LED 2 (via GPA1)

* **Anode:** Connected to 3V3 (Seeeduino XIAO)
* **Cathode:** Connected to resistor (220 Ω)
* **Resistor other end:** Connected to `GPA1` (MCP23S17)

This configuration means the MCP23S17 GPIO pins **sink current** to turn the LEDs on.

---

## Power Notes

* The entire circuit operates at **3.3 V**.
* Ensure that the MCP23S17 is configured for 3.3 V operation.
* No level shifting is required when using the Seeeduino XIAO.
* It is important, that A0, A1, A2 of MCP23S17 are connected to GND. If RESET floats → the chip will randomly reset
* Likewise, the Reset of MCP23S17 must be connected to 3.3V. If they float Device address randomly changes

---
## Pulseview 

<img width="1757" height="829" alt="pulseview" src="https://github.com/user-attachments/assets/047cb788-47ae-4466-95f6-c958844fb973" />

*  CS =Chip Select, CLK = Clock, MOSI =Master Out, Slave In
* SALEAE Connect to device  -> fxlawfw (generic driver for FX2 based LAs) (fx2lafw)
* 16 , 24, 48 MHz sample frequency (with 16 Mhz you can sample very long time, but 24 is more accurate)
* Samples 5G (when chose too much, the Chromebook, where Pulseview operates, get overloaded and stuck
* Add protocol decoder- SPI
---
## Code Notes

No firmware is provided in this repository.

Typical firmware responsibilities include:

* Initializing the SPI bus
* Configuring the MCP23S17 registers
* Setting GPA0 and GPA1 as outputs
* Driving the pins LOW/HIGH to control the LEDs

The MCP23S17 datasheet should be consulted for register configuration details.

---

## Possible Extensions

* Add more LEDs using remaining GPIO pins
* Use interrupts (`INTA`, `INTB`) for input monitoring
* Expand the design with multiple MCP23S17 devices using address pins (`A0–A2`)

---

## License

This project is provided as-is for educational and experimental use.



![Visitor Count](https://komarev.com/ghpvc/?username=ReinhardLenz&repo=GyroVisor&color=green)
