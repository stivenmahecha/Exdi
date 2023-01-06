#include "ESPmDNS.h"
#include <WiFi.h>
    
const char* ssid = "HOUSE MP";
const char* password =  "1035232570L";

#define MDNS_DEVICE_NAME "EXDI_0001"
#define SERVICE_NAME "EXDI"
#define SERVICE_PROTOCOL "udp"
#define SERVICE_PORT 5600
       
void setup(){
  Serial.begin(115200);
    
  WiFi.begin(ssid, password);
    
  // Comienza el envio de Broadcast mDNS  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(".");
  }
   
  if(!MDNS.begin(MDNS_DEVICE_NAME)) {
     Serial.println("Error encountered while starting mDNS");
     return;
  }
  
  MDNS.addService(SERVICE_NAME, SERVICE_PROTOCOL, SERVICE_PORT);
 
  Serial.println(WiFi.localIP());
    
}
    
void loop(){}