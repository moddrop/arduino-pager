
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buzzerPin = 8; 
const int buttonPin = 2;

int buttonState = 0; 

void setup() {

	lcd.begin();
  lcd.backlight();

  lcd.setCursor(3, 0);
	lcd.print("WELCOME TO");

  lcd.setCursor(0, 1);
  lcd.print("TEMPLE OS MOBILE");

  pinMode(buzzerPin, OUTPUT); 

  playTune();

  startup(); 
}

void loop() {
  
}

void playTune() {

  int notes[] = {293, 329, 349, 349, 329, 329, 349, 293, 261, 293, 293, 329, 261, 392, 349, 293, 329, 349, 349, 329, 329, 349, 293, 261, 293, 293, 329, 261, 392, 349 };
  int durations[] = {167, 167, 167, 164, 164, 167, 167, 167, 167, 167, 167, 167, 164, 167, 167, 167, 167, 167, 164, 164, 167, 167, 167, 167, 167, 167, 167, 164, 167, 167};

  for (int i = 0; i < 30; i++) {
    tone(buzzerPin, notes[i], durations[i]);

    delay(durations[i]);

    noTone(buzzerPin);
    
    delay(50); 
  }
}

void startup() {
  lcd.begin();
	lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Public Domain OS");

  lcd.setCursor(5, 1);
	lcd.print("Menu");
}
