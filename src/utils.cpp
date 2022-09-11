#include <utils.h>

void set_led(led_state_enum state)
{
    switch (state)
    {
    case busy: // Sarı
        digitalWrite(LEDR, HIGH);
        digitalWrite(LEDG, HIGH);
        digitalWrite(LEDB, LOW);
        break;

    case idle: // Yeşil
        digitalWrite(LEDG, HIGH);
        digitalWrite(LEDR, LOW);
        digitalWrite(LEDB, LOW);
        break;

    case fail: // Kırmızı yanıp sönme
        digitalWrite(LEDG, LOW);
        digitalWrite(LEDR, LOW);
        digitalWrite(LEDB, LOW);
        while (true)
        {
            digitalWrite(LEDR, HIGH);
            delay(200);
            digitalWrite(LEDR, LOW);
        }
        break;

    case debug:
        digitalWrite(LEDG, LOW);
        digitalWrite(LEDR, LOW);
        digitalWrite(LEDB, HIGH);
        break;

    default:
        Serial.println("HATA! Bilinmeyen led durumu");
        set_led(fail);
    }
}

// Serial'den bir girdi alana kadar bekler, timeout true ise WAIT_UNTIL_SLEEP_SECONDS kadar bekler ve uyur.
char *serial_input(bool timeout)
{
    while (Serial.available())
    {
        Serial.read();
    }
    set_led(idle);
    char wait_time = 0;
    while (!Serial.available())
    {
        wait_time++;
        delay(100);
        if (timeout && wait_time > WAIT_UNTIL_SLEEP_SECONDS * 10)
        {
            Serial.println("Uzun süre işlem yapılmadı. Uyutuluyor.");
            esp_sleep_enable_ext0_wakeup(WAKE_UP_PIN, WAKE_IF_HIGH ? HIGH : LOW);
            esp_deep_sleep_start();
        }
    }
    set_led(busy);
    int char_count = Serial.available();
    char *msg = new char[char_count];
    Serial.readBytes(msg, char_count - 1);
    Serial.println(msg);
    return msg;
}