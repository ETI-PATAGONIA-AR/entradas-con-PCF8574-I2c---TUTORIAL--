//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//Ejemplo: Expansor de entradas I2c con PCF8574 - prof.martintorres@educ.ar - ETI Patagonia
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

#include "Arduino.h"
#include "PCF8574.h"

#define ARDUINO_UNO_INTERRUPTED_PIN 2 // En el arduino solo el pin 1 y 2 son para interrupcion

void keyPressedOnPCF8574(); // Funcion interrupcion
 
// Set direccion i2c
PCF8574 pcf8574(0x20, ARDUINO_UNO_INTERRUPTED_PIN, keyPressedOnPCF8574);
unsigned long timeElapsed;

//variables pulsador 1
        uint8_t val0=0;
        int val_0_viejo=0; //button old
        int val_0; //buton new
        int S1_estado=0; //led estado
//variables pulsador 2
        uint8_t val1=0;
        int val_1_viejo=0; //button old
        int val_1; //buton new
        int S2_estado=0; //led estado
//variables pulsador 3
        uint8_t val2=0;
        int val_2_viejo=0; //button old
        int val_2; //buton new
        int S3_estado=0; //led estado
//variables pulsador 4
        uint8_t val3=0;
        int val_3_viejo=0; //button old
        int val_3; //buton new
        int S4_estado=0; //led estado
//variables pulsador 5
        uint8_t val4=0;
        int val_4_viejo=0; //button old
        int val_4; //buton new
        int S5_estado=0; //led estado
//variables pulsador 6
        uint8_t val5=0;
        int val_5_viejo=0; //button old
        int val_5; //buton new
        int S6_estado=0; //led estado
//variables pulsador 7
        uint8_t val6=0;
        int val_6_viejo=0; //button old
        int val_6; //buton new
        int S7_estado=0; //led estado
//variables pulsador 8
        uint8_t val7=0;
        int val_7_viejo=0; //button old
        int val_7; //buton new
        int S8_estado=0; //led estado       

int led=13;
int S8=12;
int S7=11;
int S6=10;
int S5=9;
int S4=8;
int S3=7;
int S2=6;
int S1=5;
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void setup() 
  {
  // Declaramos como salida los puertos fisicos del ARDUINO
  // y los ponemos en estado bajo 
  pinMode(led,OUTPUT);         ////se declará el pin 13 como SALIDA
digitalWrite(led, LOW); 
  pinMode(S8,OUTPUT);         ////se declará el pin 12 como SALIDA
digitalWrite(S8, LOW);
  pinMode(S7,OUTPUT);         ////se declará el pin 11 como SALIDA
 digitalWrite(S7, LOW);
  pinMode(S6,OUTPUT);         ////se declará el pin 10 como SALIDA
digitalWrite(S6, LOW);
  pinMode(S5,OUTPUT);         ////se declará el pin 9 como SALIDA
digitalWrite(S5, LOW);
  pinMode(S4,OUTPUT);         ////se declará el pin 8 como SALIDA
digitalWrite(S4, LOW);
  pinMode(S3,OUTPUT);         ////se declará el pin 7 como SALIDA
digitalWrite(S3, LOW);
  pinMode(S2,OUTPUT);         ////se declará el pin 6 como SALIDA
digitalWrite(S2, LOW);   
  pinMode(S1,OUTPUT);         ////se declará el pin 5 como SALIDA
digitalWrite(S1, LOW);   
 
  //Serial.begin(115200); // inicializamos la comunicación RS232
  Serial.begin(57600); // inicializamos la comunicación RS232
 
  pcf8574.pinMode(P0, INPUT); //se declará el pin PO del CI PCF8574 como entrada
  pcf8574.pinMode(P1, INPUT); //se declará el pin P1 del CI PCF8574 como entrada
  pcf8574.pinMode(P2, INPUT); //se declará el pin P2 del CI PCF8574 como entrada
  pcf8574.pinMode(P3, INPUT); //se declará el pin P3 del CI PCF8574 como entrada
  pcf8574.pinMode(P4, INPUT); //se declará el pin P4 del CI PCF8574 como entrada
  pcf8574.pinMode(P5, INPUT); //se declará el pin P5 del CI PCF8574 como entrada
  pcf8574.pinMode(P6, INPUT); //se declará el pin P6 del CI PCF8574 como entrada
  pcf8574.pinMode(P7, INPUT); //se declará el pin P7 del CI PCF8574 como entrada
  //Como ejemplo a futuro, otras configuraciones de los puertos del PCF8574
  //pcf8574.pinMode(P0, INPUT_PULLUP);
  //pcf8574.pinMode(P1, INPUT);
  //pcf8574.pinMode(P7, OUTPUT);
  //pcf8574.pinMode(P6, OUTPUT, HIGH);
  //pcf8574.pinMode(P4, OUTPUT, LOW);
    
  pcf8574.begin();// inicializamos la comunicación entre el uc y el CI PCF8574
  Serial.println("iniciando ejemplo.....");
 timeElapsed = millis();
  }
unsigned long lastSendTime = 0;        // last send time
unsigned long interval = 4000;          // interval between sends
 
bool startVal = HIGH;
bool keyPressed = false;

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void loop()
{
 
    if (keyPressed)
       {
        /*
        uint8_t val0 = pcf8574.digitalRead(P0);
        uint8_t val1 = pcf8574.digitalRead(P1);
        uint8_t val2 = pcf8574.digitalRead(P2);
        uint8_t val3 = pcf8574.digitalRead(P3);
        uint8_t val4 = pcf8574.digitalRead(P4);
        uint8_t val5 = pcf8574.digitalRead(P5);
        uint8_t val6 = pcf8574.digitalRead(P6);
        uint8_t val7 = pcf8574.digitalRead(P7);
        */
        val0 = pcf8574.digitalRead(P0);
        val_0 = val0;
        val1 = pcf8574.digitalRead(P1);
         val_1 = val1;
        val2 = pcf8574.digitalRead(P2);
         val_2 = val2;
        val3 = pcf8574.digitalRead(P3);
         val_3 = val3;
        val4 = pcf8574.digitalRead(P4);
         val_4 = val4;
        val5 = pcf8574.digitalRead(P5);
         val_5 = val5;
        val6 = pcf8574.digitalRead(P6);
         val_6 = val6;
        val7 = pcf8574.digitalRead(P7);
         val_7 = val7;
        
        accion();
        debug_1();
       keyPressed= false;
     }

   if (millis() - lastSendTime > interval)
          {           
            digitalWrite(led, startVal);
            if (startVal==HIGH)
                {
                startVal = LOW;
                }
               else
                {
                startVal = HIGH;
                }
            debug_2();   
            lastSendTime = millis();
           }
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void accion()
{

if (val_0 == HIGH && val_0_viejo== LOW)
   {
    if (S1_estado==0)
       {
        digitalWrite(S1, HIGH);
        S1_estado=1;
       }
    else
       {
       digitalWrite(S1, LOW);
       S1_estado=0;   
       }
   }
   val_0_viejo = val_0;
/////////////////////////////////////////////
if (val_1 == HIGH && val_1_viejo== LOW)
   {
    if (S2_estado==0)
       {
        digitalWrite(S2, HIGH);
        S2_estado=1;
       }
    else
       {
       digitalWrite(S2, LOW);
       S2_estado=0;   
       }
   }
   val_1_viejo = val_1;   
/////////////////////////////////////////////
if (val_2 == HIGH && val_2_viejo== LOW)
   {
    if (S3_estado==0)
       {
        digitalWrite(S3, HIGH);
        S3_estado=1;
       }
    else
       {
       digitalWrite(S3, LOW);
       S3_estado=0;   
       }
   }
   val_2_viejo = val_2;
/////////////////////////////////////////////
if (val_3 == HIGH && val_3_viejo== LOW)
   {
    if (S4_estado==0)
       {
        digitalWrite(S4, HIGH);
        S4_estado=1;
       }
    else
       {
       digitalWrite(S4, LOW);
       S4_estado=0;   
       }
   }
   val_3_viejo = val_3;
/////////////////////////////////////////////
if (val_4 == HIGH && val_4_viejo== LOW)
   {
    if (S5_estado==0)
       {
        digitalWrite(S5, HIGH);
        S5_estado=1;
       }
    else
       {
       digitalWrite(S5, LOW);
       S5_estado=0;   
       }
   }
   val_4_viejo = val_4; 
/////////////////////////////////////////////
if (val_5 == HIGH && val_5_viejo== LOW)
   {
    if (S6_estado==0)
       {
        digitalWrite(S6, HIGH);
        S6_estado=1;
       }
    else
       {
       digitalWrite(S6, LOW);
       S6_estado=0;   
       }
   }
   val_5_viejo = val_5;
/////////////////////////////////////////////
if (val_6 == HIGH && val_6_viejo== LOW)
   {
    if (S7_estado==0)
       {
        digitalWrite(S7, HIGH);
        S7_estado=1;
       }
    else
       {
       digitalWrite(S7, LOW);
       S7_estado=0;   
       }
   }
   val_6_viejo = val_6;
/////////////////////////////////////////////
if (val_7 == HIGH && val_7_viejo== LOW)
   {
    if (S8_estado==0)
       {
        digitalWrite(S8, HIGH);
        S8_estado=1;
       }
    else
       {
       digitalWrite(S8, LOW);
       S8_estado=0;   
       }
   }
   val_7_viejo = val_7;           
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void debug_1()
{
        Serial.println("---");
        Serial.print(" P0 ");Serial.print (val0);
        Serial.println("   ");
        Serial.print(" P1 ");Serial.print(val1);
        Serial.println("   ");
        Serial.print(" P2 "); Serial.print(val2);
        Serial.println("   ");
        Serial.print(" P3 ");Serial.print(val3);
        Serial.println("   ");
        Serial.print(" P4 ");Serial.print(val4);
        Serial.println("   ");
        Serial.print(" P5 "); Serial.print(val5);
        Serial.println("   ");
        Serial.print(" P6 ");Serial.print(val6);
        Serial.println("   ");
        Serial.print(" P7 ");Serial.print(val7);
        
}

void debug_2()
{
        Serial.println("---");
        //Serial.println("   ");
        Serial.print("LED: ");Serial.print(startVal); 
}
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////// 
void keyPressedOnPCF8574()
     {
    
    // Interrupt called (No Serial no read no wire in this function, and DEBUG disabled on PCF library)
     keyPressed = true;
     } 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////