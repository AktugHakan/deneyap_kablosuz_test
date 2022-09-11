#include <Arduino.h>
#include <pins_arduino.h>
#include <WiFi.h>
#include <config.h>
#include <wifi_routine.h>

// ---PROTOTIPLER---
void set_led(led_state_enum state);
char *serial_input(bool timeout);

// ---PROGRAM---
void setup()
{
    Serial.begin(SERIAL_BAUD);
    pinMode(LEDR, OUTPUT);
    pinMode(LEDB, OUTPUT);
    pinMode(LEDG, OUTPUT);
    set_led(busy);

    WiFi.mode(WIFI_STA);

    if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_UNDEFINED)
    {
        // Serial bağlantı üzerinden tepki gelmezse uyku moduna geç
        serial_input(true);
        Serial.println(WELCOME_MESSAGE);
    }
}

void loop()
{
    Serial.println(MENU_MAIN);
    char *msg = serial_input(true);

    switch (msg[0])
    {
    case '1':
        // WiFi
        Serial.println("Wifi Selected");
        break;
    case '2':
        // Bluetooth
        Serial.println("BT Selected");
        break;

    default:
        Serial.println(MSG_INVALID_INPUT);
    }
}
