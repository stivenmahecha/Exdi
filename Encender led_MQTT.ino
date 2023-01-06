#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient pruebaMQTT;
PubSubClient mqttClient(pruebaMQTT);

const char* ssid     = "HOUSE MP";
const char* password = "1035232570L";

char *server = "broker.emqx.io";
int port = 1883;

int ledpin= 18;
int fotopin=35;

int var = 0;
int ledval = 0;
int fotoval = 0;
char datos[40];
String resultS = "";

void wifiInit() {
    Serial.print("Conectándose a ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
        delay(500);  
    }
    Serial.println("");
    Serial.println("Conectado a WiFi");
    Serial.println("Dirección IP: ");
    Serial.println(WiFi.localIP());
  }

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("] ");

  char payload_string[length + 1];
  
  int resultI;

  memcpy(payload_string, payload, length);
  payload_string[length] = '\0';
  resultI = atoi(payload_string);
  
  var = resultI;

  resultS = "";
  
  for (int i=0;i<length;i++) {
    resultS= resultS + (char)payload[i];
  }
  Serial.println();
}



void reconnect() {
  while (!mqttClient.connected()) {
    Serial.print("Intentando conectarse MQTT...");

    if (mqttClient.connect("pruebaMQTT")) {
      Serial.println("Conectado");

      mqttClient.subscribe("Entrada/01");
      
    } else {
      Serial.print("Fallo, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" intentar de nuevo en 5 segundos");
     // Espere 5 segundos antes de volver a intentar
      delay(5000);
    }
  }
}

void setup()
{
  pinMode(ledpin,OUTPUT);
  Serial.begin(115200);
  delay(10);
  wifiInit();
  mqttClient.setServer(server, port);
  mqttClient.setCallback(callback);
}

void loop()
{
   if (!mqttClient.connected()) {
    reconnect();
  }
  mqttClient.loop();

  Serial.print("String: ");
  Serial.println(resultS);

  if(var == 0)
  {
  digitalWrite(ledpin,LOW);
  }
  else if (var == 1)
  {
  digitalWrite(ledpin,HIGH);
  }

  fotoval = analogRead(fotopin);
  Serial.print("Foto: ");
  Serial.println(fotoval);

  sprintf(datos, "Valor fotoresistencia: %d ", fotoval);
  mqttClient.publish("EXDI/SALIDA",datos);
  delay(5000);
  
  
}
