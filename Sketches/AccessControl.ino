/*  Access Control ver. 2
 *  Functions:
 *  1. Read iButton ID (40 bit)
 *  2. Check for CRC error and display message if CRC not valid
 *  3. Check family of iButton and display message if not DS1990 (ROM 64bit)
 *  4. Set LED and display message if access approved
 *  5. Don't set led and display message if access denied.
 *  6. Use string variable to hold valid ID (iButton that has access)
 *  7. Use Relay to open door
*/

#include <LiquidCrystal.h>
#include <OneWire.h>
 

OneWire  ds(12);
LiquidCrystal lcd(7,6,5,4,3,2);
byte addr[8];  // variable to hold the 64 bit Address of iButton
String customID = "";
String validID[2] = {"1b113bba" , "   BACAS JOHN"};
String name0=" Project Team:  ";
String name1="   Aggelos G    ";
String name2="   Giorgos K    ";
String name3="   Nikolas A    ";
String name4="   Bacas John   ";
unsigned long previousMillis = 0;

void setup() {
//  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(13, OUTPUT);   // builtIn LED indicator pin
  digitalWrite(13, LOW);
  pinMode(9, OUTPUT);    // Relay Control pin
  digitalWrite(9, HIGH);
  lcd.print("  1st EPAL of");
  lcd.setCursor(0,1);
  lcd.print(" Ag. Dimitrios");
  delay(4000);
}

void loop() {
   lcd.clear();
   delay(3);
   lcd.print(" Insert iButton");
   byte nameMes = 0;
   while (!ds.reset()){                // send pulse and wait for answer from iButton
      delay(500);
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= 3000){
        previousMillis = currentMillis;
        printName(nameMes);
        nameMes +=1;
        if (nameMes == 5) {nameMes = 0;}
      }
   }
   if (ds.search(addr)){   // iButton found, 64 bits (8 bytes) saved to <addr> array !!
    
      if ( OneWire::crc8( addr, 7) != addr[7]) {  // check CRC error
         lcd.clear();
         delay(3);
         lcd.print("Remove Key and");
         lcd.setCursor(3,1);
         lcd.print("try again");
      }
      else if ( addr[0] != 0x01) {   //check if family DS1990
         lcd.clear();
         delay(3);
         lcd.print("  Not a valid");
         lcd.setCursor(5,1);
         lcd.print("iButton");
      }
      else {  // if everything OK check if valid iButton
         customID = "";
         byte i;
         for( i = 5; i > 1; i--) {
            customID += String(addr[i-1], HEX);
         }
         checkID(customID);
      }
      delay(1200);   // wait for 1.2 sec and deactivate relay
   }
   digitalWrite(9, HIGH);     // Unset Relay, door cannot open
   delay(2000);
   digitalWrite(13, LOW);     //Turn off LED
   ds.reset_search(); // clear <addr> array
}

void checkID(String s){
   lcd.clear();
   delay(3);
//   Serial.println(s);
//   Serial.println(validID[0]);
   if (s.equals(validID[0])){    // if iButton is valid
      digitalWrite(13, HIGH);    // Turn LED On
      digitalWrite(9, LOW);      // Set Relay, door can open
      lcd.print(validID[1]);
      lcd.setCursor(1,1);
      lcd.print("Access Granted");
   }
   else{                         // if iButton is not valid
      lcd.print(" Access Denied");
   }
   return;
}

void printName(byte num){
   lcd.setCursor(0,1);
   if (num ==0) { lcd.print(name0);}
   if (num ==1) { lcd.print(name1);}
   if (num ==2) { lcd.print(name2);}
   if (num ==3) { lcd.print(name3);}
   if (num ==4) { lcd.print(name4);}
   return;
}
