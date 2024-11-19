#include "time.h"

#define NTP_SERVER "0.in.pool.ntp.org"
#define GMT_OFFSET_SEC 0
#define DAY_LIGHT_OFFSET_SEC 3600

void Init_NTP_Time()
{
  configTime(GMT_OFFSET_SEC, DAY_LIGHT_OFFSET_SEC, NTP_SERVER);
}

void Print_NTP_Time()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.print(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.print("\r");
  delay(1000);
}

