// Version 0.4

#include <Adafruit_NeoPixel.h>
#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 2;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
};

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
        
    if(key == '8'){
      Serial.println("Changing profile...");
      if (selectedProfile == 9){
        selectedProfile = 0;
      } else {
        selectedProfile = selectedProfile + 1;
      }
      changeProfile();
    }
    
    if(key == '4'){
      Serial.println("Changing profile...");
      if (selectedProfile == 0){
        selectedProfile = 9;
      } else {
        selectedProfile = selectedProfile - 1;
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
  Serial.println("Current profile: ");
  Serial.println(selectedProfile);
  switch(selectedProfile){
    case 0:
      //Purple
      colorWipe(strip.Color(153, 51, 255), 50);
      break;
    case 1:
      //Orange
      colorWipe(strip.Color(255, 128, 0), 50);
      break;
    case 2:
      //Blue
      colorWipe(strip.Color(0, 0, 255), 50);
      break;
    case 3:
      //Green
      colorWipe(strip.Color(0, 255, 0), 50);
      break;
    case 4:
      //White
      colorWipe(strip.Color(127, 127, 127), 50);
      break;
    case 5:
      //Cyan
      colorWipe(strip.Color(102, 255, 255), 50);
      break;
    case 6:
      //Red
      colorWipe(strip.Color(255, 0, 0), 50);
      break;
    case 7:
      //Pistachio
      colorWipe(strip.Color(102, 255, 178), 50);
      break;
    case 8:
      //Light pink
      colorWipe(strip.Color(255, 153, 255), 50);
      break;
    case 9:
      //Windows
      colorWipe(strip.Color(0, 128, 255), 50);
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
      //Play-Pause
      Keyboard.write((char) 32);
      break;
    case '2':
      //Prev song
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ARROW);
      break;
    case '3':
      //Next song
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_RIGHT_ARROW);
      break;
    case '5':
      //Volume Down
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_DOWN_ARROW);
      break;
    case '6':
      //Volume Up
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_UP_ARROW);
      break;
    case '7':
      //Mute-Unmute
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_DOWN_ARROW);
      break;
    default:
      break;
  }
}

//Logic Pro X / GarageBand
void profile4(char key){
  switch(key){
    case '1':
      //Play-Pause
      Keyboard.write((char) 32);
      break;
    case '2':
      //Loop
      break;
    case '3':
      //Stop
      break;
    case '5':
      //Record
      Keyboard.press('r');
      break;
    case '6':
      //Quantize
      Keyboard.press('q');
      break;
    case '7':
      //Save
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('s');
      break;
    default:
      break;
  }
}

//OBS
void profile5(char key){
  switch(key){
    case '1':
      break;
    case '2':
      break;
    case '3':
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

//Windows
void profile9(char key){
  switch(key){
    case '1':
      //Cmd
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      delay(100);
      Keyboard.write("cmd");
      Keyboard.press(KEY_RETURN);
      break;
    case '2':
      //Services
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      delay(100);
      Keyboard.write("services.msc");
      Keyboard.press(KEY_RETURN);
      break;
    case '3':
      //File manager
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('e');
      break;
    case '5':
      //Lock
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('l');
      break;
    case '6':
      //Unlock work pc
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_DELETE);
      break;
    case '7':
      //Crop screenshot
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('r');
      break;
    default:
      break;
  }
}
