/*  Access Control ver. 1
 *  Functions:
 *  1. Read iButton and display ID, CRC and FAMILY code on 16x2 LCD Display
 *  2. Check for CRC error and display message if CRC not valid
 *  3. Check family of iButton and display message if not DS1990 (ROM 64bit)
 *  4. Set LED to indicate that an iButton was read successfully
*/

#include <LiquidCrystal.h>
#include <OneWire.h>

OneWire  ds(12);
LiquidCrystal lcd(7,6,5,4,3,2);
byte addr[8];  // variable to hold the 64 bit Address of iButton

void setup() {
  lcd.begin(16,2);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  lcd.clear();
  lcd.print("  1st EPAL of");
  lcd.setCursor(0,1);
  lcd.print(" Ag. Dimitrios");
  delay(4000);
}

void loop() {
  lcd.clear();
  delay(5);
  lcd.print(" Insert iButton");
  while (!ds.reset()){delay(800);} // send pulse and wait for answer from iButton
  
  if (ds.search(addr)){   // iButton found, 64 bits (8 bytes) saved to <addr> array !!
    
     if ( OneWire::crc8( addr, 7) != addr[7]) {  // check CRC error
        lcd.clear();
        delay(5);
        lcd.print("Remove Key and");
        lcd.setCursor(3,1);
        lcd.print("try again");
     }
     else if ( addr[0] != 0x01) {   //check if family DS1990
        lcd.clear();
        delay(5);
        lcd.print("  Not a valid");
        lcd.setCursor(5,1);
        lcd.print("iButton");
     }
     else {  // if everything OK print CRC, family, 40bit address and set LED
        digitalWrite(13, HIGH);  //Set LED   
        lcd.clear();
        delay(5);
        byte i;
        for( i = 8; i > 0; i--) {
           if (i==8){lcd.print("CRC:");}
           if (i==7){continue;}
           if (i==6){lcd.setCursor(0,1);lcd.print(" ID: ");}
           if (i==1){lcd.setCursor(9,0); lcd.print("fam: ");}
           lcd.print(addr[i-1], HEX);
     //      if (i < 7 && i > 1){lcd.print(":");}
        }
     }
     delay(4000);   // wait for 4 sec to read message on LCD
  }
  digitalWrite(13, LOW);  //Turn off LED
  ds.reset_search(); // clear <addr> array
}
