# 🚰 Arduino Automatic Water Dispenser (Submersible Pump Version)
An **automatic water dispenser** built using an **Arduino Uno**, **ultrasonic sensor**, and a **submersible pump motor**. The system automatically dispenses water when a glass or hand is placed under the outlet and stops when it is removed — ensuring hygiene and water conservation.
## 🧠 Project Overview
This project replaces the traditional manual tap or button-based water dispenser with an **automatic, touchless system**. When the **ultrasonic sensor** detects an object (like a glass) within a set distance, the Arduino activates a **submersible pump** to start dispensing water. Once the object is removed, the pump turns off automatically.  
This project was developed by **Ciril C Reji** as a DIY automation experiment using basic electronic components and Arduino.
## ⚙️ Components Used
| Component | Description |
|------------|-------------|
| **Arduino Uno** | Main microcontroller controlling the system |
| **HC-SR04 Ultrasonic Sensor** | Detects presence of object (glass/hand) |
| **Submersible Pump Motor (5V/12V)** | Pumps water from the container |
| **NPN Transistor / MOSFET (e.g. IRF540 / TIP120)** | Switch to drive motor from Arduino |
| **Resistors (1 kΩ, 10 kΩ)** | For gate/base control and pull-down |
| **Diode (1N4007)** | Flyback protection for motor |
| **Power Supply (5V or 12V DC)** | To power the pump and Arduino |
| **Breadboard / Jumper Wires** | For circuit connections |
| **Tubing / Water Container** | For water storage and flow |
## 🔌 Circuit Diagram

![image](https://github.com/ciril7/Arduino-Automatic-Water-Dispenser/blob/main/circuit.png)


**Working principle:**
1. The ultrasonic sensor continuously measures the distance to detect a glass.  
2. If an object is detected within a threshold (e.g., <10 cm), Arduino outputs a HIGH signal.  
3. The transistor or MOSFET switches ON the pump.  
4. When the object moves away, the signal goes LOW and pump stops.  

## 💻 Arduino Code
```cpp
#define TRIG 9
#define ECHO 8
#define PUMP 12
#define LED 13
long duration;
int distance;
int threshold = 10; // Distance in cm
void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(PUMP, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < threshold) {
    digitalWrite(PUMP, HIGH);
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(PUMP, LOW);
    digitalWrite(LED, LOW);
  }
  delay(200);
}


🧩 Working Demo

Power the Arduino with 5V/12V adapter (depending on pump voltage).

Place a glass near the sensor (<10 cm).

Pump turns ON → water flows.

Remove the glass → pump turns OFF.



Troubleshooting

| Problem              | Cause                                      | Solution                               |
| -------------------- | ------------------------------------------ | -------------------------------------- |
| Pump not working     | Power supply too weak                      | Use adapter with higher current (≥1 A) |
| Sensor not detecting | Incorrect wiring                           | Check TRIG/ECHO pins and connections   |
| Pump always ON       | Wrong transistor orientation / code error  | Verify wiring and digital logic        |
| No serial output     | Serial monitor not open or wrong baud rate | Set baud to 9600                       |



🚀 Possible Improvements

Add timer cut-off to prevent overflow.

Include LCD display for status messages.

Integrate water level sensor in the container.

Use IR proximity sensor for faster detection.

Make it IoT-enabled with ESP8266 or ESP32.


images
[image](https://github.com/ciril7/Arduino-Automatic-Water-Dispenser/blob/main/IMG_8737.jpeg)



📄 License

This project is open-source under the MIT License
. Feel free to modify and improve it for personal or educational use.

👨‍💻 Author

Ciril C Reji
📧 cirilcreji@gmail.com

🔗 https://github.com/ciril7
