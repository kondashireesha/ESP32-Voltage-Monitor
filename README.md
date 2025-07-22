# ESP32 Voltage Monitoring System

This project demonstrates how to monitor analog voltage using the ESP32's built-in ADC and display real-time voltage data through serial logs. An LED indicator is used to show low or high voltage levels.

##Hardware Components Used

- ESP32 Dev Board
- 1x LED (for status indication)
- Resistor (220Ω for LED)
- Analog Voltage Source (e.g., Potentiometer or Sensor)
- Jumper wires and breadboard

##Features

- Reads analog voltage from GPIO34 (ADC1_CHANNEL_6)
- Converts raw ADC data to real voltage (0–3.3V)
- Displays voltage value via serial monitor
- LED indicates:
  - **Low Voltage** (< 3.3V): LED ON
  - **Normal Voltage** (= 3.3V): LED OFF
  - **High Voltage** (> 3.3V): LED ON

## 🛠Software Tools

- [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- VS Code with ESP-IDF Extension
- Git for version control
- Wokwi (optional, for simulation)

 How It Works:
- Configures GPIO34 as analog input using `ADC1_CHANNEL_6`
- Sets GPIO2 as digital output to drive the LED
- Reads analog value from the 12-bit ADC (range: 0 to 4095)
- Converts the ADC raw value into voltage using the following formula:
**ADC Voltage Conversion Formula**
  
voltage = (adc_raw / 4095.0) * reference_voltage;
Voltage per step = reference_voltage / 4095
                 = 3.3V / 4095 ≈ 0.00080586 V
                 ≈ 0.806 mV
If adc_raw = 2048, then:
voltage = (2048 / 4095.0) * 3.3 ≈ 1.65V 
the above readme if is good 

