
#include "WiFiMulti.h"

static WiFiMulti WiFiMulti;

void WiFiMulti_add_APs()
{
    WiFi.mode(WIFI_STA);
    for(int i = 0; i < NO_ELE(WiFi_credentials_hook);i++)
    {
        WiFiMulti.addAP(WiFi_credentials_hook[i].SSID, WiFi_credentials_hook[i].Password);
    }
}

bool WiFiMulti_connect()
{
    if(WiFiMulti.run() != WL_CONNECTED)
    {
        Serial.println("WiFi not connected!");
        delay(1000);
        return false;
    }
    else if(WiFi.status() == WL_CONNECTED)
    {
        Serial.printf("WIFI Connected\r\nSSID : %s\r\nSTRENGTH : %d\r\n", WiFi.SSID().c_str(), WiFi.RSSI());
        return true;
    }
}