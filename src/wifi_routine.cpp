#include <wifi_routine.h>

void wifi_routine_begin()
{
    WiFi.disconnect();

    bool loop = true;
    do
    {
        loop = wifi_loop();
    } while (loop);
}

bool wifi_loop()
{
    if (connected)
    {
    }
    else
    {
        Serial.println(MSG_SCANNING_WIFI_AP);
        const int ap_count = WiFi.scanNetworks();
        if (WiFi.status() == WL_SCAN_COMPLETED)
        {
            Serial.println(MENU_WIFI_AP_LIST);
            for (int i = 1; i <= ap_count; i++)
            {
                Serial.print(i);
                Serial.print(" - ");
                Serial.print("Sinyal:");
                Serial.print(WiFi.RSSI(i));
                Serial.println(WiFi.SSID(i));
            }
        }
        else
        {
            while (true)
            {
                Serial.println(MENU_WIFI_NOT_FOUND);
                char *msg = serial_input(true);
                switch (msg[0])
                {
                case '1':
                    return true;
                    break;
                case '2':
                    return false;
                    break;
                default:
                    Serial.println(MSG_INVALID_INPUT);
                }
                delete[] msg;
            }
        }
    }
}