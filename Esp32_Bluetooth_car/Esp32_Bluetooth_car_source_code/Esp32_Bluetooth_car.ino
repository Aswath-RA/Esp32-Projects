

//********************************************************************************
// Hai Welcome To Esp32 Bluetooth Based RC Car Project :-)                
// In this Project ,I used Esp32,Motor Driver(L298N),5v Dc motor *2 and 5v PowerBank 

// To Control the Car here i used a Bluetooth app available in playstore (Arduino Car)
// Link for the app : https://play.google.com/store/apps/details?id=com.electro_tex.bluetoothcar&hl=en_IN&gl=US 
// Fine tune the app settings if need for car control.

// I Hope You like the project for any doubt contact : aswath.raviji@gmail.com

//$$$$$ Let Your Code Conquer The World $$$$$
//************************************************************************

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

char receivedChar;// received value will be stored as CHAR in this variable

const int MR1 = 12; //ESP32 pins (MR=Right Motor) (ML=Left Motor) (1=Forward) (2=Backward)
const int MR2 = 14; 
const int ML1 = 27;
const int ML2 = 26;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Drift car"); //You can change your Bluetooth device name
  pinMode(MR1, OUTPUT); 
  pinMode(MR2, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
}

void Forward(){
        //RIGHT MOTOR
      digitalWrite(MR1,HIGH);//MOVE FRONT
      digitalWrite(MR2,LOW); //MOVE BACK
      //LEFT MOTOR
      digitalWrite(ML1,LOW);//MOVE BACK
      digitalWrite(ML2,HIGH);//MOVE FRONT
}
void Backward(){
      digitalWrite(MR1,LOW);
      digitalWrite(MR2,HIGH);
      digitalWrite(ML1,HIGH);
      digitalWrite(ML2,LOW);
}
void Left(){
      digitalWrite(MR1,HIGH);
      digitalWrite(MR2,LOW);
      digitalWrite(ML1,HIGH);
      digitalWrite(ML2,LOW);
}
void Right(){
      digitalWrite(MR1,LOW);
      digitalWrite(MR2,HIGH);
      digitalWrite(ML1,LOW);
      digitalWrite(ML2,HIGH);
}
void Stop(){
      digitalWrite(MR1,LOW); 
      digitalWrite(MR2,LOW);
      digitalWrite(ML1,LOW); 
      digitalWrite(ML2,LOW); 
}
void loop() {
    receivedChar =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
     
    Serial.print ("Received:");//print on serial monitor
    Serial.println(receivedChar);//print on serial monitor    
    
    if(receivedChar == 'F')
    {
      Forward();
       
    }
    if(receivedChar == 'B')
    {
 
      Backward(); 
    }         
     if(receivedChar == 'L')
    {

      Left();
    }        
    if(receivedChar == 'R')
    {

      Right(); 
    }
    if(receivedChar == 'S')
    {
      Stop();
    }
    
  }
  delay(20);
}
 
