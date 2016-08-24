#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <Keypad.h>


RH_ASK driver;

//Keypad setup
const byte ROWS = 4; // define row 4
const byte COLS = 4; // define column 4
char lastKeyState = 'A';     // previous state of the key
char keyState = 'A'; //current state of the key
char key = 'A';
char keys[ROWS][COLS] = {
{'M','I','E','A'},
{'N','J','F','B'},
{'O','K','G','C'},
{'P','L','H','D'}
};
// connect row ports of the button to corresponding IO ports on the board
byte rowPins[ROWS] = {2,3,4,5};
// connect column ports of the button to corresponding IO ports on the board
byte colPins[COLS] = {6,7,8,9};
// call class library performance function of Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS,  COLS );

char *msg = "Z";

//Wait time 
int delayTime = 200;

void setup()
{
    Serial.begin(9600);   // Debugging only
    Serial.println("begin");
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  char key = keypad.getKey();
  
  if (key == 'A') {
    Serial.println(key);
    const char *msg = "A";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'B') {
    Serial.println(key);
    const char *msg = "B";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}    
  else if (key == 'C') {
    Serial.println(key);
    const char *msg = "C";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime); 
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'D') {
    Serial.println(key);
    const char *msg = "D";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);    }
  else if (key == 'E') {
    const char *msg = "E";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'F') {
    const char *msg = "F";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime); 
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'G') {
    const char *msg = "G";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}    
  else if (key == 'H') {
    const char *msg = "H";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'I') {
    const char *msg = "I";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime); 
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'J') {
    const char *msg = "J";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}    
  else if (key == 'K') {
    const char *msg = "K";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'L') {
    const char *msg = "L";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime); 
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'M') {
    const char *msg = "M";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}    
  else if (key == 'N') {
    const char *msg = "N";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'O') {
    const char *msg = "O";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime); 
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);}
  else if (key == 'P') {
    const char *msg = "P";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(delayTime);
  }    
    /*const char *msg = "Hello World!";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);*/
}
