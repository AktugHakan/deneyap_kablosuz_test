#pragma once

#include <Arduino.h>
#include <pins_arduino.h>
#include "config.h"

enum led_state_enum
{
    busy, // Kırmızı
    idle, // Yeşil
    fail, // 
    debug
};

void set_led(led_state_enum state);
char *serial_input(bool timeout);