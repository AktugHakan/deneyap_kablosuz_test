#include <Arduino.h>
#include <pins_arduino.h>

// ---AYARLAR---
const unsigned long SERIAL_BAUD = 115200;

const char WAIT_UNTIL_SLEEP_SECONDS = 10; // Idle modunda uykuya geçmeden önce kaç saniye bekleyeceği

const char *WELCOME_MESSAGE =
    "╔══════════════════════════════════════════════╗\n"
    "║ DeneYap Mini kablosuz özellik testi programı ║\n"
    "╚══════════════════════════════════════════════╝\n";

const char *MENU_MAIN = "Mod seçin:\n1 - WiFi\n2 - Bluetooth";

const char *MSG_SCANNING_WIFI_AP = "WiFi ağları aranıyor...";

const char *MENU_WIFI_NOT_FOUND = "Ağ bulunamadı.\n1 - Yeniden ara\n2 - Ana menü";

const char *MENU_WIFI_AP_LIST = "Bağlanmak için bir ağ seçin:";

const char *MSG_INVALID_INPUT = "Yaptığınız seçim geçerli değil!";

// Hangi pin ile uyandırılacağı
const gpio_num_t WAKE_UP_PIN = GPIO_NUM_0;

// Pin HIGH olunca mı yoksa LOW olunca mı cihazın uyandırılacağı
const bool WAKE_IF_HIGH = false;
