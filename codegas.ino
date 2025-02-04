//Alarm Kebakaran MQ-2
#include <LiquidCrystal.h>                   //memanggil library LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);       //mendeklarasikan pin arduino yang terhubung ke lcd

const int pinAsap = A0;                      //inisialisasi pin sensor
const int pinSpeker = 8;                     //inisialisasi pin speker
const int ledRed = 13;                       //inisialisasi pin LED

void setup() {
lcd.begin(16, 2);                            //Program menyalakan LCD 16x2
pinMode (ledRed, OUTPUT);                    //menetapkan pin 13 sebagai output
}

void loop() {
//Membaca data dari pin yang dihubungkan ke sensor
int dataAnalog = digitalRead (pinAsap);

//program untuk mengirimkan informasi aman ke LCD
if (dataAnalog == 1) {
  lcd.setCursor (0,0);
  lcd.print ("Sensor Kebakaran");
  lcd.setCursor (0,1);
  lcd.print ("     AMAN...    ");
  noTone(pinSpeker);
  digitalWrite (ledRed, LOW);
}

//program untuk mengirimkan informasi bahaya ke LCD
else if (dataAnalog == 0){
lcd.setCursor (0,0);
lcd.print (" Mendeteksi Ada ");
lcd.setCursor (0,1);
lcd.print ("BAHAYA KEBAKARAN");

//program untuk menyalakan sirine
  // matikan LED
  digitalWrite( ledRed, LOW );
  // mainkan nada di pin#8 dg. frekuensi 261Hz selama 500 ms
  tone( pinSpeker, 261 );
  delay( 500 );
  // nyalakan LED
  digitalWrite( ledRed, HIGH );
  // mainkan nada di pin#8 dg. frekuensi 392Hz selama 500 ms
  tone( pinSpeker, 392 );
  delay( 500 );
}

}
