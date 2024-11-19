/************************INCLUDE************************/


/************************MACROS************************/
#define    NO_ELE(a)    sizeof(a)/sizeof(a[0])

/************************STRUCTURES************************/
typedef struct WiFi_credentials
{
    // A common Wi-Fi Name/ Password would include 8 to 63 printable ASCII characters
    char SSID[63];
    char Password[63];
}WiFi_credentials;

/************************GLOBAL************************/


/************************HOOkS************************/
WiFi_credentials WiFi_credentials_hook[] = 
{
/*    SSID             Password     */
    {"BSNL",          "diamond4259"  },
    {"TECHNET",       "Technet@23"   },
    {"MrRISSU",       "123456789"    }
};

/************************FUNC DECL************************/
extern bool Wifi_init();
extern bool Scan_WiFi_networks();
extern bool Print_scanned_networks();
extern bool Connect_to_default_AP();
