#include <RF24.h>
#include <SPI.h>
#include <Servo.h>
#include <nRF24L01.h>

RF24 radio(9,10); //CE, CSN

const byte direccion[6] = "00001";

int pot_pulgar, pot_indice, pot_medio, pot_anular, pot_menique;
int ang_pulgar, ang_indice, ang_medio, ang_anular, ang_menique;
int enviar[5];

void setup() {
  radio.begin();
  
  Serial.begin(9600);
  
  radio.openWritingPipe(direccion);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();

}

void loop() {
  pot_pulgar=analogRead(A0);
  ang_pulgar=map(pot_pulgar, 0, 45, 30, 125);

 
  
 

  

  pot_anular=analogRead(A5);
  ang_anular=map(pot_anular, 85, 220, 30, 110);

  enviar[0]= ang_pulgar;
  enviar[2]= ang_anular;

  Serial.println(pot_anular);

  radio.write(&enviar, sizeof(enviar));
  delay(5);
 
}
