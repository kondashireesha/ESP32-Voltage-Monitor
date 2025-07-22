#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_log.h"

#define LED_PIN GPIO_NUM_2
#define VOLTAGE_PIN ADC1_CHANNEL_6  // GPIO34 corresponds to ADC1 Channel 6
#define ADC_MAX_VALUE 4095
#define REF_VOLTAGE 3.3  // Assuming a 3.3V reference voltage
static const char *TAG = "VoltageMonitor";

void app_main(void) {
    // Configure LED pin as output
    esp_rom_gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    // Configure ADC
    adc1_config_width(ADC_WIDTH_BIT_12); 
    // 12-bit ADC resolution
    adc1_config_channel_atten(VOLTAGE_PIN, ADC_ATTEN_DB_12); // Allows reading up to ~3.9V
    while (1) {
        // Read ADC value
        int sensor_value = adc1_get_raw(VOLTAGE_PIN);
        // Convert ADC value to voltage
        float voltage = (sensor_value / (float)ADC_MAX_VALUE) * REF_VOLTAGE;
        // Print voltage
        ESP_LOGI(TAG, "Take Power: %.2fV", voltage);
        // Check voltage level and control LED
        if (voltage < 3.3) {
            gpio_set_level(LED_PIN, 1);  // Turn ON LED for low voltage
            ESP_LOGI(TAG, "Low Power");
        } else if (voltage > 3.3) {
            gpio_set_level(LED_PIN, 1);  // Turn ON LED for high voltage
            ESP_LOGI(TAG, "High Power");
        } else {
            gpio_set_level(LED_PIN, 0);  // Turn OFF LED for normal power
            ESP_LOGI(TAG, "Normal Power");
        }
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay 1 second
    }
}