// // put your setup code here, to run once:
//const int led_1 = 1;
//  // this LED represents low power level. It is green. 
//const int led_2 = 2;
//  // this LED represents medium power level. Also green. 
//const int led_3 = 3;
//  // this LED represents HIGH power level. It is red. 
//const int pot_1 = 0;



// Contributors:

// Hugh Ritchie
// Rohit Sattu
// Do Park

void setup() {
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  float pot_reading = (analogRead(A0));
  // this is the raw reading from the potentiometer, it's value is
  // unusable because it goes beyond what a LED can use. (0-254)
  
  int pot_reading_mapped = map(pot_reading, 0, 1024, 0, 300);
   //  this is the processed reading using the map() function. 
   // it outputs a variable between 0 and 254.

   Serial.println(pot_reading_mapped);

   if (pot_reading_mapped > 0 && pot_reading_mapped < 100)
   {
    digitalWrite(A2,LOW);
    digitalWrite(A3,LOW);
    digitalWrite(A1,HIGH);
   }
   
   else if (pot_reading_mapped >= 100 && pot_reading_mapped < 200)
   {
        digitalWrite(A1,LOW);
    digitalWrite(A3,LOW);
    digitalWrite(A2,HIGH);
   }
   
   else if (pot_reading_mapped >= 200 && pot_reading_mapped < 300)
   {
        digitalWrite(A2,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A3,HIGH);
   }

  

}
