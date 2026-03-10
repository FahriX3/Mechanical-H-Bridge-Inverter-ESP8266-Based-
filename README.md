# Mechanical-H-Bridge-Inverter-ESP8266-Based-
# ⚡ Mechanical H-Bridge Inverter: A "Gabut" Research
> **Turning "What If?" into a High-Voltage Reality.**

![Status](https://img.shields.io/badge/Status-Legacy_Project-yellow)
![Platform](https://img.shields.io/badge/Platform-ESP8266-blue?logo=espressif)
![Category](https://img.shields.io/badge/Category-Power_Electronics-orange)

An experimental project exploring the boundaries of mechanical switching in power electronics. This project converts **12V DC to 520V AC** using a custom-coded H-Bridge made of mechanical relays, controlled by an ESP8266.

---

## 📖 Project Overview
Normally, inverters use MOSFETs or IGBTs for high-speed switching. In this "kegabutan" (leisure) experiment, I challenged that norm by using **4-Channel Mechanical Relays** to handle the H-Bridge logic. 

The goal was to reach a standard 50Hz frequency using an old UPS Iron-Core Transformer.

## 🛠️ Technical Specifications

| Component | Detail |
| :--- | :--- |
| **Logic Controller** | ESP8266 (Isolated Power via USB) |
| **Switching Element** | 4-Channel Relay Module (Active Low) |
| **Input Source** | 12V DC (1A Transformer + Bridge Rectifier) |
| **Smoothing** | 2x 4700uF 35V Electrolytic Capacitors (Series Configuration) |
| **Output Transformer** | Iron-Core Transformer 650VA (Ex-UPS) |
| **Tested Load** | Consumer-grade LED Bulb |

---

## 📐 Mathematical Analysis
Based on the code implementation, the switching frequency was calculated as follows:

- **Phase A+D (ON):** $10 \text{ ms}$
- **Phase B+C (ON):** $10 \text{ ms}$
- **Dead-Time (Safety):** $2 \text{ ms} \times 2$
- **Total Period ($T$):** $10+2+10+2 = 24 \text{ ms}$

$$f = \frac{1000 \text{ ms}}{24 \text{ ms}} \approx 41.67 \text{ Hz}$$

> **Conclusion:** The system operates at **41.67 Hz**, limited by the mechanical travel time of the relay armatures.

---

## 💻 The Logic (ESP8266 Code)
The code utilizes a **Dead-Time Protection** strategy to ensure the mechanical relay contacts fully detach before the opposite phase activates, preventing catastrophic short circuits.

```cpp
void loop() {
  // Phase 1: Forward Polarity
  digitalWrite(relayA, LOW);
  digitalWrite(relayD, LOW);
  digitalWrite(relayB, HIGH);
  digitalWrite(relayC, HIGH);
  delay(10); 

  // Dead-Time Protection (2ms)
  digitalWrite(relayA, HIGH);
  digitalWrite(relayD, HIGH);
  delay(2); 

  // Phase 2: Reverse Polarity
  digitalWrite(relayB, LOW);
  digitalWrite(relayC, LOW);
  delay(10); 

  // Dead-Time Protection
  digitalWrite(relayB, HIGH);
  digitalWrite(relayC, HIGH);
  delay(2);
}
