#include <Adafruit_NeoPixel.h>
#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 2;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
};

char profiles[10] = {'0','1','2','3','4','5','6','7','8','9'};
char selectedProfile;

byte rowPins[ROWS] = {16,10};
byte colPins[COLS] = {9,8,7,6};

const byte  PIXEL_PIN = 2;
const byte PIXEL_COUNT = 12;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  strip.begin();
  strip.show();
  selectedProfile = 0;
}

void loop() {
  char key = keypad.getKey();
  if(key){
    Serial.println('Key pressed: ' + key);
    Serial.println('Current profile: ' + selectedProfile);
    switch(key){
      case '1':
        Keyboard.press(KEY_F11);
        break;
      case '2':
        Keyboard.press(KEY_F10);
        break;
      case '3':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_F11);
        break;
      case '4':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_F5);
        break;
      case '5':
        Keyboard.press(KEY_F8);
        break;
      case '6':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_F2);
        break;
      case '7':
        Keyboard.press(KEY_F5);
        break;
      case '8':
        if(selectedProfile = 9){
          selectedProfile = 0;
        } else {
          selectedProfile++;
        }
        changeProfile();
        break;
    }
    delay(100);
    Keyboard.releaseAll();
  }
}

void changeProfile(){
  switch(selectedProfile){
    case 0:
      //Red//
      colorWipe(strip.Color(255, 0, 0), 50);
      break;
    case 1:
      //Green//
      colorWipe(strip.Color(0, 255, 0), 50);
      break;
    case 2:
      //Blue//
      colorWipe(strip.Color(0, 0, 255), 50);
      break;
    case 3:
      //White//
      colorWipe(strip.Color(127, 127, 127), 50);
      break;
    case 4:
      //Cyan//
      colorWipe(strip.Color(102, 255, 255), 50);
      break;
    case 5:
      //Orange//
      colorWipe(strip.Color(255, 128, 0), 50);
      break;
    case 6:
      //Purple//
      colorWipe(strip.Color(153, 51, 255), 50);
      break;
    case 7:
      //Pistachio//
      colorWipe(strip.Color(102, 255, 178), 50);
      break;
    case 8:
      //Light pink//
      colorWipe(strip.Color(255, 153, 255), 50);
      break;
    case 9:
      //Shrek//
      colorWipe(strip.Color(153, 255, 153), 50);
      break;
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
