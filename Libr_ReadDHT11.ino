#include "DHT.h"
#define DHTPIN 2    // Digital pin connected to the DHT sensor
bool DHTError = false; // Checksum Error

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

// defines variables
float Val_humi = 0; // Humidity variables
float Val_temp = 0;// Temperature variables

void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  Read_Sen_Dht11_Loop();
  Print_Serial_loop();
}

void Read_Sen_Dht11_Loop() {
  Val_humi = dht.readHumidity();
  Val_temp = dht.readTemperature();// Read temperature as Celsius (the default)
}
void Print_Serial_loop(){
  if (DHTError == false){
    Serial.print(F("Humidity: ")); Serial.print(Val_humi);
    Serial.print(F("%  Temperature: "));Serial.print(Val_temp);Serial.println(F("°C "));
  }else{ 
      Serial.println("Error");
    }
    DelayTimer(500000); //wait 2,5 sec
}
void DelayTimer(long int DelayValue){
  long int DelayTime = micros();
  do {    
  }while (micros()-DelayTime < DelayValue);
}
