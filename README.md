# 🔥 Heater Control System

A basic embedded system that uses a DHT22 temperature sensor to monitor room temperature and control a simulated heater, LED, and buzzer based on preset thresholds.


**Features**
🌡️ Real-time Temperature Monitoring with DHT22 sensor

🔥 Heater Control based on target temperature

🚨 Overheat Protection using buzzer alert

💡 LED Indicator for heating status

📟 Serial Logging of temperature and system state


**System Requirements**
1. Arduino Uno / Wokwi Simulation
2. DHT22 Temperature Sensor
3. LED, Buzzer, Heater (simulated via output pins)
4. 10kΩ pull-up resistor for the DHT22 data line



**How to Use**
Clone or download the repository
Open the .ino file in the Arduino IDE
Wire the circuit as per the pin configuration
Upload to your board or run in Wokwi
Monitor output via Serial Monitor (9600 baud)


**Pin Configuration**
Component	  Arduino Pin
DHT22 Data	  D2
Heater (LED) 	D3
Status LED  	D4
Buzzer	      D5


 **Simulation**
Try the project directly on Wokwi:


**Future Enhancements**
1. BLE Advertising for current status
2. FreeRTOS-based task handling
3. Configurable temperature profiles
4. LCD/OLED display integration


Link: https://wokwi.com/projects/437162633222426625     


**Keep Learning**
