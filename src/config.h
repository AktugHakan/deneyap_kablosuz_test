#include <Arduino.h>
#include <pins_arduino.h>

// ---AYARLAR---
const unsigned long SERIAL_BAUD = 115200;

const char WAIT_UNTIL_SLEEP_SECONDS = 10; // Idle modunda uykuya geçmeden önce kaç saniye bekleyeceği

const char *WELCOME_MESSAGE =
    "╔══════════════════════════════════════════════╗\n"
    "║ DeneYap Mini kablosuz özellik testi programı ║\n"
    "╚══════════════════════════════════════════════╝\n";

const char *MENU = "Mod seçin:\n1 - WiFi\n2 - Bluetooth";

const char *INVALID_INPUT = "Yaptığınız seçim geçerli değil!";

// Hangi pin ile uyandırılacağı
const gpio_num_t WAKE_UP_PIN = GPIO_NUM_0;

// Pin HIGH olunca mı yoksa LOW olunca mı cihazın uyandırılacağı
const bool WAKE_IF_HIGH = false;
