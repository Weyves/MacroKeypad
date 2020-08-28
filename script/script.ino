// Version 0.3

#include <Adafruit_NeoPixel.h>
#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 2;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
};

//char profiles[10] = {'0','1','2','3','4','5','6','7','8','9'};
int selectedProfile;

byte rowPins[ROWS] = {16,10};
byte colPins[COLS] = {9,8,7,6};

const byte  PIXEL_PIN = 2;
const byte PIXEL_COUNT = 16;

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
    Serial.println("Key pressed: ");
    Serial.println(key);
    Serial.println("Current profile: ");
    Serial.println(selectedProfile);
    if(key == '8'){
      Serial.println("Changing profile...");
      if (selectedProfile == 9){
        selectedProfile = 0;
      } else {
        selectedProfile = selectedProfile + 1;
      }
      changeProfile();
    }
    switch(selectedProfile){
      case 0:
        profile0(key);
        break;
      case 1:
        profile1(key);
        break;
      case 2:
        profile2(key);
        break;
      case 3:
        profile3(key);
        break;
      case 4:
        profile4(key);
        break;
      case 5:
        profile5(key);
        break;
      case 6:
        profile6(key);
        break;
      case 7:
        profile7(key);
        break;
      case 8:
        profile8(key);
        break;
      case 9:
        profile9(key);
        break;
      default:
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

//Visual Studio
void profile0(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}

//Eclipse
void profile1(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}

//Visual Studio Code
void profile2(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}

//Spotify
void profile3(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}

//Logic Pro X / GarageBand
void profile4(char key){
  switch(key){
    case '1':
      //Play/Pause
      Keyboard.write((char) 32);
      break;
    case '2':
      //Loop
      break;
    case '3':
      //Stop
      break;
    case '4':
      //Record
      Keyboard.press('r');
      break;
    case '5':
      //Quantize
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('q');
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}

//Program
void profile5(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}

//Program
void profile6(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}

//Program
void profile7(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}

//Program
void profile8(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}

//Program
void profile9(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    default:
      break;
  }
}
