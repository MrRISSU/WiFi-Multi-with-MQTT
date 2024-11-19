#include "main_h.h"

void setup()
{
    Serial.begin(115200);
    Wifi_init();
    Scan_WiFi_networks();
    Print_scanned_networks();
    //WiFi_connect();
    WiFiMulti_add_APs();
    WiFiMulti_connect();

    Init_NTP_Time();
    Serial.println("BOOTING COMPLETED");
}

void loop()
{
    Print_NTP_Time();
}
