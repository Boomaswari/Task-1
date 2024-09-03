#include <Keypad.h>
#include <LiquidCrystal.h>

const int rs = 10, e = 11, d4 = 12, d5 = 13, d6 = A0, d7 = A1;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

const byte ROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}, colPins[COLS] = {6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String correctPasscode = "1234", enteredPasscode = "";
int attempts = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey();
  if (attempts >= 3) {
    lcd.setCursor(0, 1);
    lcd.print("Locked Out   ");
    delay(10000);
    attempts = 0;
    lcd.clear();
    lcd.print("Enter Password:");
  } else if (key) {
    if (key == '#') {
      lcd.clear();
      if (enteredPasscode == correctPasscode) {
        lcd.print("Access Granted");
      } else {
        lcd.print("Access Denied");
        attempts++;
      }
      delay(2000);
      enteredPasscode = "";
      lcd.clear();
      lcd.print("Enter Password:");
    } else if (key == '*') {
      enteredPasscode = "";
      lcd.clear();
      lcd.print("Enter Password:");
    } else {
      enteredPasscode += key;
      lcd.setCursor(0, 1);
      lcd.print(enteredPasscode);
    }
  }
}
