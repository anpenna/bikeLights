// This is just the code for doing different light patterns.
// There is no code for switching patterns, changes must be
// hard-coded.

#include <SPI.h> // Not actualy used but needed to compile
#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 150
#define DATA_PIN 8

// used to make basic mood lamp colour fading feature
int fade_h;
int fade_direction = 1;

// For updown color changing
int hue = 0;
int hueOffset = 30;
int changeCount = 0;

// power settings
float percentOn = .5;

int numberOfPatterns = 16;
int delayTime = 75;

// Define the array of leds
CRGB leds[NUM_LEDS];

//For color flipping
bool toggle = true;
int numOfToggles = 10;

// Variables will change:
int buttonPushCounter = -1;   // counter for the number of button presses

//Code for keypad
char lastKeyState = 'Z';     // previous state of the key
char keyState = 'A'; //current state of the key
char key = 'A';

void setup()
{
  Serial.begin(9600); // Debugging only
  // this line sets the LED strip type - refer fastLED documeantion for more details https://github.com/FastLED/FastLED
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop()
{
  key = 'A';
  if (key == 'A') {
    Serial.println("Received an A!");
    skittles();
  } else if (key == 'B') {
    //Serial.println("Received an B!");
    rainbow_chunk();
  } else if (key == 'C') {
    //Serial.println("Received an C!");
    single_colour(0);
  } else if (key == 'D') {
    Serial.println("Received an D!");
    single_colour(25);
  } else if (key == 'E') {
    //Serial.println("Received an E!");
    single_colour(42);
  } else if (key == 'F') {
    //Serial.println("Received an F!");
    single_colour(96);
  } else if (key == 'G') {
    //Serial.println("Received an G!");
    single_colour(128);
  } else if (key == 'H') {
    //Serial.println("Received an H!");
    single_colour(160);
  } else if (key == 'I') {
    //Serial.println("Received an I!");
    single_colour(213);
  } else if (key == 'J') {
    //Serial.println("Received an J!");
    acid_cloud();
  } else if (key == 'K') {
    //Serial.println("Received an K!");
    colour_fade();
  } else if (key == 'L') {
    //Serial.println("Received an L!");
    dropdot();
  } else if (key == 'M') {
    //Serial.println("Received an M!");
    updown();
  } else if (key == 'N') {
    //Serial.println("Received an N!");
    wave();
  } else if (key == 'O') {
    //Serial.println("Received an O!");
    constant_lightning_fast();
  } else if (key == 'P') {
    //Serial.println("Received an P!");
    flipflop();
  } else {
    //Serial.println("Key was none of the above");
  }
  lastKeyState = key;
  delay(150);

  //  if (buttonPushCounter == 0)
  //    skittles();
  //  else if (buttonPushCounter == 1)
  //    rainbow_chunk();
  //  else if (buttonPushCounter == 2)
  //    single_colour(0);
  //  else if (buttonPushCounter == 3)
  //    single_colour(25);
  //  else if (buttonPushCounter == 4)
  //    single_colour(42);
  //  else if (buttonPushCounter == 5)
  //    single_colour(96);
  //  else if (buttonPushCounter == 6)
  //    single_colour(128);
  //  else if (buttonPushCounter == 7)
  //    single_colour(160);
  //  else if (buttonPushCounter == 8)
  //    single_colour(213);
  //  else if (buttonPushCounter == 9)
  //    acid_cloud();
  //  else if (buttonPushCounter == 10)
  //    colour_fade();
  //  else if (buttonPushCounter == 11)
  //    dropdot();
  //  else if (buttonPushCounter == 12)
  //    updown();
  //  else if (buttonPushCounter == 13)
  //    wave();
  //  else if (buttonPushCounter == 14)
  //    constant_lightning_fast();
  //  else if (buttonPushCounter == 15)
  //    flipflop();
  //  else
  //    acid_cloud();
  //  // Delay a little bit to avoid bouncing
  //  delay(delayTime);
}

// utility function to turn all the lights off.
void reset() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( 0, 0, 0);
  }
  FastLED.show();

}

// Makes all the LEDs a single colour, see https://raw.githubusercontent.com/FastLED/FastLED/gh-pages/images/HSV-rainbow-with-desc.jpg for H values
void single_colour(int H) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( H, 255, round(255 * percentOn));
  }
  FastLED.show();
  delay(0);
}

void wave() {
  int test = 0;
  int changed = 0;
  for (int j = 0; j < NUM_LEDS; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      int val;
      int hue;
      int sat;
      if (i == j) {
        val = 255;
        sat = 0;
        hue = 0;
      }
      else if (i == j - 1) {
        val = 225;
        sat = 0;
        hue = 0;
      }
      else if (i == j - 2) {
        val = 200;
        sat = 0;
        hue = 0;
      }
      else if (i == j - 3) {
        val = 150;
        sat = 128;
        hue = 128;
      }
      else if (i == j - 4) {
        val = 150;
        sat = 128;
        hue = 128;
      }
      else if (i == j - 5) {
        val = 100;
        sat = 128;
        hue = 164;
      }
      else if (i == j - 6) {
        val = 100;
        sat = 128;
        hue = 164;
      }
      else if (i == j - 7) {
        val = 100;
        sat = 128;
        hue = 164;
      }
      else if (i == j - 8) {
        val = 100;
        sat = 128;
        hue = 164;
      }
      else {
        val = 50;
        sat = 128;
        hue = 175;
      }
      leds[i] = CHSV( hue, sat, val);
    }
    FastLED.show();
    delay(delayTime);
  }
}

void colour_fade() {
  int test = 0;
  int changed = 0;

  //mood lamp that cycles through colours
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( fade_h, 255, round(255 * percentOn));
  }
  if (fade_h > 254) {
    fade_direction = -1; //reverse once we get to 254
  }
  else if (fade_h < 0) {
    fade_direction = 1;
  }

  fade_h += fade_direction;
  FastLED.show();
  delay(delayTime);
}

void rainbow_chunk() {
  double sizeChunk = NUM_LEDS / 7;
  for (int i = 0; i < round(sizeChunk); i++) {
    leds[i] = CHSV( 0, 255, round(255 * percentOn));
  }
  for (int i = round(sizeChunk); i < round(sizeChunk * 2); i++) {
    leds[i] = CHSV( 25, 255, round(255 * percentOn));
  }
  for (int i = round(sizeChunk * 2); i < round(sizeChunk * 3); i++) {
    leds[i] = CHSV( 42, 255, round(255 * percentOn));
  }
  for (int i = round(sizeChunk * 3); i < round(sizeChunk * 4); i++) {
    leds[i] = CHSV( 96, 255, round(255 * percentOn));
  }
  for (int i = round(sizeChunk * 3); i < round(sizeChunk * 5); i++) {
    leds[i] = CHSV( 128, 255, round(255 * percentOn));
  }
  for (int i = round(sizeChunk * 5); i < round(sizeChunk * 6); i++) {
    leds[i] = CHSV( 160, 255, round(255 * percentOn));
  }
  for (int i = round(sizeChunk * 6); i < round(sizeChunk * 7); i++) {
    leds[i] = CHSV( 213, 255, round(255 * percentOn));
  }
  FastLED.show();
  //avoid flickr which occurs when FastLED.show() is called - only call if the colour changes
  /*if(lastMode != mode){
    FastLED.show();
    lastMode = mode;
    }*/
  delay(0);
}

void skittles() {
  int test = 0;
  int changed = 0;
  for (int j = 0; j < NUM_LEDS; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV( round((1.0 * (i - j) / NUM_LEDS) * 255), 255, round(255 * percentOn));
    }
    FastLED.show();
    delay(delayTime);
  }
  delay(delayTime);
}

void acid_cloud() {
  int test = 0;
  int changed = 0;
  // a modification of the rolling lightning which adds random colour. trippy.
  //iterate through every LED
  for (int i = 0; i < NUM_LEDS; i++) {
    if (random(0, 100) > 90) {
      leds[i] = CHSV( random(0, 255), 255, round(255 * percentOn));

    }
    else {
      leds[i] = CHSV(0, 0, 0);
    }
  }
  FastLED.show();
  delay(random(5, 100));
}

void dropdot() {
  int test = 0;
  int changed = 0;
  int minv = 0;
  int maxv = NUM_LEDS - 1;

  for (int k = 0; k < NUM_LEDS; k++) {
    for (int j = minv; j < maxv; j++) {
      for (int i = 0; i < NUM_LEDS; i++) {
        int val;
        if (i == j)
          val = 255;
        else if (i < minv)
          val = 255;
        else if (i > maxv)
          val = 255;
        else if (i == j - 1)
          val = 200;
        else if (i == j - 2)
          val = 150;
        else if (i == j - 3)
          val = 100;
        else if (i == j - 4)
          val = 50;
        else
          val = 0;
        leds[i] = CHSV( 0, 0, val);
      }
      FastLED.show();
      delay(k);
    }
    maxv--;
    for (int j = maxv; j >= minv; j--) {
      for (int i = 0; i < NUM_LEDS; i++) {
        int val;
        if (i == j)
          val = 255;
        else if (i < minv)
          val = 255;
        else if (i > maxv)
          val = 255;
        else if (i == j + 1)
          val = 200;
        else if (i == j + 2)
          val = 150;
        else if (i == j + 3)
          val = 100;
        else if (i == j + 4)
          val = 50;
        else
          val = 0;
        leds[i] = CHSV( 0, 0, val);
      }
      FastLED.show();
      delay(k);
    }
    minv++;
  }
}

void updown() {
  int test = 0;
  int changed = 0;
  for (int j = 0; j < NUM_LEDS; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      int val;
      if (i == j)
        val = 255;
      else if (i == j - 1)
        val = 200;
      else if (i == j - 2)
        val = 150;
      else if (i == j - 3)
        val = 100;
      else if (i == j - 4)
        val = 50;
      else
        val = 0;
      leds[i] = CHSV( hue, 255, val);
    }
    FastLED.show();
    delay(100);
  }
  hue = (hue + hueOffset) % 255;
  for (int j = NUM_LEDS - 1; j >= 0; j--) {
    for (int i = 0; i < NUM_LEDS; i++) {
      int val;
      if (i == j)
        val = 255;
      else if (i == j + 1)
        val = 200;
      else if (i == j + 2)
        val = 150;
      else if (i == j + 3)
        val = 100;
      else if (i == j + 4)
        val = 50;
      else
        val = 0;
      leds[i] = CHSV( hue, 255, val);
    }
    FastLED.show();
    delay(100);
  }
  hue = (hue + hueOffset) % 255;
}

void constant_lightning_fast() {
  switch (random(1, 3)) {
    case 1:
      thunderburst();
      delay(1);
      Serial.println("Thunderburst");
      break;

    case 2:
      rolling();
      delay(1);
      Serial.println("Rolling");
      break;

    case 3:
      crack();
      delay(1);
      Serial.println("Crack");
      break;


  }
}

void thunderburst() {

  int test = 0;
  int changed = 0;

  // this thunder works by lighting two random lengths
  // of the strand from 10-20 pixels.
  int rs1 = random(0, NUM_LEDS / 2);
  int rl1 = random(10, 20);
  int rs2 = random(rs1 + rl1, NUM_LEDS);
  int rl2 = random(10, 20);

  //repeat this chosen strands a few times, adds a bit of realism
  for (int r = 0; r < random(3, 6); r++) {

    for (int i = 0; i < rl1; i++) {
      leds[i + rs1] = CHSV( 0, 0, round(255 * percentOn));
    }

    if (rs2 + rl2 < NUM_LEDS) {
      for (int i = 0; i < rl2; i++) {
        leds[i + rs2] = CHSV( 0, 0, round(255 * percentOn));
      }
    }

    FastLED.show();
    //stay illuminated for a set time
    delay(random(10, 50));

    reset();
    delay(random(10, 50));
  }
}

void rolling() {
  int test = 0;
  int changed = 0;
  // a simple method where we go through every LED with 1/10 chance
  // of being turned on, up to 10 times, with a random delay between each time
  for (int r = 0; r < random(2, 10); r++) {
    //iterate through every LED
    for (int i = 0; i < NUM_LEDS; i++) {
      if (random(0, 100) > 90) {
        leds[i] = CHSV( 0, 0, round(255 * percentOn));

      }
      else {
        //dont need reset as we're blacking out other LEDs her
        leds[i] = CHSV(0, 0, 0);
      }
    }
    FastLED.show();
    delay(random(5, 100));
    reset();
  }
}

void crack() {

  int test = 0;
  int changed = 0;

  //turn everything white briefly
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( 0, 0, round(255 * percentOn));
  }
  FastLED.show();
  delay(random(10, 100));
  reset();
}

void flipflop() {
  if (toggle) {
    for (int i = 0; i < NUM_LEDS; i = i + 2) {
      leds[i] = CHSV( hue, 255, round(255 * percentOn));
    }
    for (int i = 1; i < NUM_LEDS; i = i + 2) {
      leds[i] = CHSV( (hue + hueOffset) % 255, 255, round(255 * percentOn));
    }
  }
  else {
    for (int i = 1; i < NUM_LEDS; i = i + 2) {
      leds[i] = CHSV( hue, 255, round(255 * percentOn));
    }
    for (int i = 0; i < NUM_LEDS; i = i + 2) {
      leds[i] = CHSV( (hue + hueOffset) % 255, 255, round(255 * percentOn));
    }
  }
  FastLED.show();
  delay(100);

  toggle = !toggle;
  changeCount = changeCount + 1;
  //Serial.println(changeCount);

  if (changeCount % 10 == 1) {
    hue = (hue + hueOffset) % 255;
  }
}

