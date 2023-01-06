
#include "Arduino.h" //Libreria para Touch

int threshold = 26000;   // ESP32S2 
bool touch4detected = false;
bool touch5detected = false;
bool touch6detected = false;
bool touch8detected = false;
const int ledPIN = 35;

void gotTouch4() {
  touch4detected = true;
}
void gotTouch5() {
  touch5detected = true;
}
void gotTouch6() {
  touch6detected = true;
}
void gotTouch8() {
  touch8detected = true;
}

void setup() {
  pinMode(ledPIN , OUTPUT);
  Serial.begin(115200);
  delay(1000); 

  Serial.println("\n ESP32 Touch Interrupt Test\n");
  touchAttachInterrupt(T4, gotTouch4, threshold); 
  touchAttachInterrupt(T5, gotTouch5, threshold);
  touchAttachInterrupt(T6, gotTouch6, threshold);
  touchAttachInterrupt(T8, gotTouch8, threshold);
}

void loop() {
  if (touch4detected) {
    touch4detected = false;
    if (touchInterruptGetLastStatus(T4)) {
        Serial.println(" --- T4 Toque");        
        Serial.println(touchRead(T4));  // get value using T0
        digitalWrite(ledPIN, !digitalRead(ledPIN)); 

    } else {
    }
  }
  if (touch5detected) {
    touch5detected = false;
    if (touchInterruptGetLastStatus(T5)) {
        Serial.println(" --- T5 Tocado");
        Serial.println(touchRead(T5));  // get value using T0
        digitalWrite(ledPIN, !digitalRead(ledPIN)); 
    } else {
    }
  }
    if (touch6detected) {
    touch6detected = false;
    if (touchInterruptGetLastStatus(T6)) {
        Serial.println(" --- T6 Tocado");
        Serial.println(touchRead(T6));  // get value using T0
        digitalWrite(ledPIN, !digitalRead(ledPIN)); 
    } else {
    }
  }
    if (touch8detected) {
    touch8detected = false;
    if (touchInterruptGetLastStatus(T8)) {
        Serial.println(" --- T8 Tocado");
        Serial.println(touchRead(T8));  // get value using T0
        digitalWrite(ledPIN, !digitalRead(ledPIN)); 
    } else {
    }
  }

  delay(80);
}
