#include <WiFiManager.h> 
#include "ESPmDNS.h"
#include <WiFi.h>


  void setup () {
    // pon tu código de configuración aquí, para ejecutar una vez:
 
    Serial.begin(115200);
    
  
    WiFiManager wm;  //WiFiManager, Inicialización local. Una vez que su negocio está hecho, no hay necesidad de mantenerlo

    
    //wm.resetSettings(); // restablecer la configuración al reiniciar

    // Conéctese automáticamente usando las credenciales guardadas,
    // si la conexión falla, inicia un punto de acceso con el nombre especificado ("AutoConnectAP"),
    // si está vacío, se generará automáticamente el SSID, si la contraseña está en blanco, será un AP anónimo (wm.autoConnect())
    // luego entra en un bucle de bloqueo en espera de configuración y devolverá un resultado de éxito
     //ESP.restart(); Reinicia el ESP32
    bool res;
    // res = wm.autoConnect(); // nombre AP generado automáticamente desde chipid
    // res = wm.autoConnect("AutoConnectAP"); // aplicación anónima
    res = wm.autoConnect("Exdi_0001","12345678"); // Nombre y contraseña generada
    if(!res) {
        Serial.println("No se pudo establecer la conexión");
        
    } 
    else {
        //si llegas aquí te has conectado al WiFi  
        Serial.println("Conexión exitosa :)");

       while (WiFi.status() != WL_CONNECTED) {
        
    delay(1000);
    Serial.println(".");
  }
   
  Serial.println(WiFi.localIP());
 
 }

}

void loop() {
    // pon tu código principal aquí, para ejecutar repetidamente:  
}
