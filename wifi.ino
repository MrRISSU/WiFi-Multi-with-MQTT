/************************INCLUDE************************/
#include "WiFi.h"
/************************MACROS************************/
#define DEFAULT_SSID "TECHNET"
#define DEFAULT_PASSWORD "Technet@23"

/************************STATIC OBJECTS************************/


/************************STATIC VARIABLES************************/
static uint32_t number_of_networks_found = 0;

/************************STATIC FUNCTIONS************************/
static bool Delete_scanned_networks()
{
    Serial.printf("Deleting scanned networks: ");
    WiFi.scanDelete();
    Serial.printf("DELETED\n\r");
    return true;
}

/************************FUNCTIONS************************/
bool Wifi_init()
{
    // Set WiFi to station mode and disconnect from an AP if it was previously connected.
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    return true;
}

bool Scan_WiFi_networks()
{
    Serial.print("Scanning Networks: ");
    // WiFi.scanNetworks will return the number of networks found.
    number_of_networks_found = WiFi.scanNetworks();
    Serial.println("DONE");
    return true;
}

bool Print_scanned_networks()
{
    if (number_of_networks_found == 0)
    {
       Serial.println("no networks found");
       return false;
    }
    else
    {
        Serial.print(number_of_networks_found);
        Serial.println(" networks found");
        Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
        for (int i = 0; i < number_of_networks_found; ++i) 
        {
            //Serial.printf("-%s-", WiFi.SSID(i).c_str());
            // Print SSID and RSSI for each network found
            Serial.printf("%2d | %-32.32s | %4ld | %2ld | ", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i), WiFi.channel(i));
            switch (WiFi.encryptionType(i)) {
              case WIFI_AUTH_OPEN:            Serial.print("open"); break;
              case WIFI_AUTH_WEP:             Serial.print("WEP"); break;
              case WIFI_AUTH_WPA_PSK:         Serial.print("WPA"); break;
              case WIFI_AUTH_WPA2_PSK:        Serial.print("WPA2"); break;
              case WIFI_AUTH_WPA_WPA2_PSK:    Serial.print("WPA+WPA2"); break;
              case WIFI_AUTH_WPA2_ENTERPRISE: Serial.print("WPA2-EAP"); break;
              case WIFI_AUTH_WPA3_PSK:        Serial.print("WPA3"); break;
              case WIFI_AUTH_WPA2_WPA3_PSK:   Serial.print("WPA2+WPA3"); break;
              case WIFI_AUTH_WAPI_PSK:        Serial.print("WAPI"); break;
              default:                        Serial.print("unknown");
        }
        Serial.println();
        delay(10);
      }
    }
    Serial.println("");
    
    // Delete the scan result to free memory for code below.
    //Delete_scanned_networks();
    return true;
}

bool WiFi_connect()
{
    if(WiFi.begin("BSNL", "diamond4259") == WL_CONNECTED)
    {
        Serial.printf("CONNECTED\r\n");
        Serial.printf("SSID :%s\r\n", WiFi.SSID().c_str());
        Serial.printf("RSSI :%d\r\n", WiFi.RSSI());
        return true;
    }
    delay(200);
    Serial.printf("FAILED\r\n");
    return false;

}