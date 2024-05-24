#include <RF24.h>
#include <SPI.h>
#include <Servo.h>
#include <nRF24L01.h>

RF24 radio(9,10); //CE, CSN

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

const byte direccion[6] = "00001";

int enviar[5];

void setup() {
  servo1.attach(6);
  servo2.attach(5);
  servo3.attach(4);
  servo4.attach(3);
  servo5.attach(2);

  radio.begin();

  radio.openReadingPipe(0, direccion);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();

}

void loop() {
  if(radio.available()){
   
    radio.read(&enviar, sizeof(enviar));

      servo1.write(enviar[0]); //Pulgar
      servo2.write(enviar[0]); //Indice
      servo3.write(enviar[2]); //Medio
      servo4.write(enviar[2]); //Anular
      servo5.write(enviar[2]); //Meñique
    }

}
