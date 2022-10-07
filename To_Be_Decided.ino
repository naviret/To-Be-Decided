

//#include <iostream>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <time.h>       /* time */
#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>

#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>


#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#include <avr/pgmspace.h>


const char button_1_q1[] PROGMEM = "Closest color to Butler Library";
const char button_2_q1[] PROGMEM = "Mix all the colors";
const char button_3_q1[] PROGMEM = "What Kermit the Frog and granny smith apples have in common";
const char button_4_q1[] PROGMEM = "Columbia engineerings color";
const char button_5_q1[] PROGMEM = "Shape in Brazils flag";
const char button_6_q1[] PROGMEM = "Shape of your buttons";
const char button_7_q1[] PROGMEM = "Pointy spike";
const char button_8_q1[] PROGMEM = "Regularly shaped swimming pool";
const char button_9_q1[] PROGMEM = "Syrup";
const char button_10_q1[] PROGMEM = "Non-emulsified mayo is ____________";
const char button_11_q1[] PROGMEM = "Soggy toast";
const char button_12_q1[] PROGMEM = "If you slapped someone with this, it probably would hurt";
const char button_13_q1[] PROGMEM = "Do this to ruin your friends homework";
const char button_14_q1[] PROGMEM = "A lady-like insect";
const char button_15_q1[] PROGMEM = "Often associated with snail shells";
const char button_16_q1[] PROGMEM = "Bottom half of the US flag";

const char button_1_q2[] PROGMEM = "Snow is _____";
const char button_2_q2[] PROGMEM = "Color without the letter e starting with b";
const char button_3_q2[] PROGMEM = "Color that represents peace";
const char button_4_q2[] PROGMEM = "Synonym for feeling down";
const char button_5_q2[] PROGMEM = "P=4w";
const char button_6_q2[] PROGMEM = "Shape of uneaten pizza";
const char button_7_q2[] PROGMEM = "Cross section of a pyramid";
const char button_8_q2[] PROGMEM = "Shape of chocolate bar";
const char button_9_q2[] PROGMEM = "Glassforming liquid";
const char button_10_q2[] PROGMEM = "Tears are ___";
const char button_11_q2[] PROGMEM = "Overripe fruit";
const char button_12_q2[] PROGMEM = "Oobleck";
const char button_13_q2[] PROGMEM = "Child drawing";
const char button_14_q2[] PROGMEM = "Pattern commonly found in Central European folk art";
const char button_15_q2[] PROGMEM = "Hypnosis";
const char button_16_q2[] PROGMEM = "Zebra";

const char button_1_q3[] PROGMEM = "Cotton is _____";
const char button_2_q3[] PROGMEM = "Absence of color";
const char button_3_q3[] PROGMEM = "What Kermit the Frog and granny smith apples have in common";
const char button_4_q3[] PROGMEM = "George Washingtons favorite color";
const char button_5_q3[] PROGMEM = "Shine bright like a Diamond";
const char button_6_q3[] PROGMEM = "Endless curve";
const char button_7_q3[] PROGMEM = "Shape of top of Columbia and NY Presbyterian hospital";
const char button_8_q3[] PROGMEM = "A=lw";
const char button_9_q3[] PROGMEM = "High value of eta";
const char button_10_q3[] PROGMEM = "Dihydrogen monoxide";
const char button_11_q3[] PROGMEM = "Mashed potatoes";
const char button_12_q3[] PROGMEM = "Ketchup";
const char button_13_q3[] PROGMEM = "Noodles";
const char button_14_q3[] PROGMEM = "Named after a type of dance";
const char button_15_q3[] PROGMEM = "Fibonacci sequence";
const char button_16_q3[] PROGMEM = "Pattern of bee";


const char *const QUESTIONS[16][3] PROGMEM = {{button_1_q1, button_1_q2, button_1_q3},
                                              {button_2_q1, button_2_q2, button_2_q3}, 
                                              {button_3_q1, button_3_q2, button_3_q3}, 
                                              {button_4_q1, button_4_q2, button_4_q3}, 
                                              {button_5_q1, button_5_q2, button_5_q3},
                                              {button_6_q1, button_6_q2, button_6_q3}, 
                                              {button_7_q1, button_7_q2, button_7_q3},
                                              {button_8_q1, button_8_q2, button_8_q3}, 
                                              {button_9_q1, button_9_q2, button_9_q3}, 
                                              {button_10_q1, button_10_q2, button_10_q3}, 
                                              {button_11_q1, button_11_q2, button_11_q3}, 
                                              {button_12_q1, button_12_q2, button_12_q3}, 
                                              {button_13_q1, button_13_q2, button_13_q3},
                                              {button_14_q1, button_14_q2, button_14_q3}, 
                                              {button_15_q1, button_15_q2, button_15_q3}, 
                                              {button_16_q1, button_16_q2, button_16_q3}};


char buffer[60]; 



class Button {
    private:
        bool _state;
        uint8_t _pin;

    public:
        Button(uint8_t pin) : _pin(pin) {}

        void begin() {
            pinMode(_pin, INPUT_PULLUP);
            _state = digitalRead(_pin);
        }

        bool isReleased() {
            bool v = digitalRead(_pin);
            if (v != _state) {
                _state = v;
                if (_state) {
                    return true;
                }
            }
            return false;
        }
};

hd44780_I2Cexp screen1(0x27, 20, 4); //Arduino screens.  
hd44780_I2Cexp screen2(0x26, 20, 4);
hd44780_I2Cexp screen3(0x25, 20, 4);
hd44780_I2Cexp screen4(0x24, 20, 4);



Button b1(1);
Button b2(2);
Button b3(3);
Button b4(4);
Button b5(5);
Button b6(6);
Button b7(7);
Button b8(8);
Button b9(9);
Button b10(10);
Button b11(11);
Button b12(12);
Button b13(13);
Button b14(A0);
Button b15(A1);
Button b16(A2);


#define PIXEL_PIN A3
#define PIXEL_COUNT 24
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

//use for color in colorWipe function
int red;
int green;
int blue;


void setup() {
  
  //have to initialize buttons too
  b1.begin();
  b2.begin();
  b3.begin();
  b4.begin();
  b5.begin();
  b6.begin();
  b7.begin();
  b8.begin();
  b9.begin();
  b10.begin();
  b11.begin();
  b12.begin();
  b13.begin();
  b14.begin();
  b15.begin();
  b16.begin();
  
  screen1.init(); 
  screen2.init();
  screen3.init();
  screen4.init();

  screen1.backlight();
  screen2.backlight();
  screen3.backlight();
  screen4.backlight();


     

  strip.begin();
  
  randomSeed(analogRead(0));

  screen1.lineWrap();
  screen2.lineWrap();
  screen3.lineWrap();
  screen4.lineWrap();
  
}

void countdownGame(){
  screen1.setCursor(0,0);
  screen2.setCursor(0,0);
  screen3.setCursor(0,0);
  screen4.setCursor(0,0);
  
  screen1.clear();
  screen2.clear();
  screen3.clear();
  screen4.clear();

  screen1.print("3");
  screen2.print("3");
  screen3.print("3");
  screen4.print("3");

  theaterChaseRainbow(25);

  screen1.clear();
  screen2.clear();
  screen3.clear();
  screen4.clear();

  screen1.print("2");
  screen2.print("2");
  screen3.print("2");
  screen4.print("2");

  theaterChaseRainbow(25);

  screen1.clear();
  screen2.clear();
  screen3.clear();
  screen4.clear();

  screen1.print("1");
  screen2.print("1");
  screen3.print("1");
  screen4.print("1");
  
  theaterChaseRainbow(25);

  screen1.clear();
  screen2.clear();
  screen3.clear();
  screen4.clear();
  
  screen1.print("Starting......");
  screen2.print("Starting......");
  screen3.print("Starting......");
  screen4.print("Starting......");

  screen1.clear();
  screen2.clear();
  screen3.clear();
  screen4.clear();

  strip.clear();

  
}

void displayWon(hd44780_I2Cexp scn) {
  scn.clear();
  scn.setCursor(0, 1);
  scn.print("Game Over");
  scn.setCursor(0, 2);
  scn.print("You Won");
  
}

void displayLost(hd44780_I2Cexp scn) {
  scn.clear();
  scn.setCursor(0, 1);
  scn.print("Game Over");
  scn.setCursor(0, 2);
  scn.print("You Lost");
  
}




void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}

void colorWipe(uint32_t color, int wait) {
  
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}




void loop(){

  //make the timer screen do something

  screen1.setCursor(0,1);
  screen1.print("To_Be_Decided");
  screen1.setCursor(0,2);
  screen1.print("Player One");

  screen2.setCursor(0,1);
  screen2.print("To_Be_Decided");
  screen2.setCursor(0,2);
  screen2.print("Player Two");

  screen3.setCursor(0,1);
  screen3.print("To_Be_Decided");
  screen3.setCursor(0,2);
  screen3.print("Player Three");

  screen4.setCursor(0,1);
  screen4.print("To_Be_Decided");
  screen4.setCursor(0,2);
  screen4.print("Player Four");

  red = random(0,256);
  green = random(0,256);
  blue = random(0,256);
  colorWipe(strip.Color(red,green,blue), 100);
  
  bool startGame = false;
  
  if (b1.isReleased()) { //this correctly starts the game but the screens don't show the questions so the time runs out and the screens print game over
    startGame = true;
  }

  if (startGame == true) {
    
    countdownGame();
    
  
    //String buttons[] = {"b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "b9", "b10", "b11", "b12", "b13", "b14", "b15", "b16"};
    int buttons[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int gameButtons[4] = {}; 
    
    //repeats through each screen once
    
    int b = random(0,16);
    int q = random(0,3);
    gameButtons[0] = (b+1);
    screen1.setCursor(0,0);
    //screen1.print(QUESTIONS[b][0]);
    screen1.print(strcpy_P(buffer, (char*)pgm_read_word(&(QUESTIONS[b][q]))));
   
    b = random(0,16);
    q = random(0,3);
    gameButtons[1] = (b+1);
    screen2.setCursor(0,0);
    //screen2.print(QUESTIONS[b][0]);
    screen2.print(strcpy_P(buffer, (char*)pgm_read_word(&(QUESTIONS[b][q]))));
 
    b = random(0,16);
    q = random(0,3);
    gameButtons[2] = (b+1);
    screen3.setCursor(0,0);
    //screen3.print(QUESTIONS[b][0]);
    screen3.print(strcpy_P(buffer, (char*)pgm_read_word(&(QUESTIONS[b][q]))));
   
    b = random(0,16);
    q = random(0,3);
    gameButtons[3] = (b+1);
    screen4.setCursor(0,0);
    //screen4.print(QUESTIONS[b][0]);
    screen4.print(strcpy_P(buffer, (char*)pgm_read_word(&(QUESTIONS[b][q]))));
    
    int timer = 0;
    int buttonsMissing = 4;
    int wrongButton = 4;
    bool weWon = false;
    int colorTime = 40;
    int switcher = 1;
    int b1missing = 1;
    int b2missing = 1;
    int b3missing = 1;
    int b4missing = 1;
    int b5missing = 1;
    int b6missing = 1;
    int b7missing = 1;
    int b8missing = 1;
    int b9missing = 1;
    int b10missing = 1;
    int b11missing = 1;
    int b12missing = 1;
    int b13missing = 1;
    int b14missing = 1;
    int b15missing = 1;
    int b16missing = 1;
    
    
    while (timer <= 15000) {
      if (timer < 10000) {
        red = random(0,256);
        green = random(0,256);
        blue = random(0,256);
      }
      else if (timer >= 10000) {
        
        red = 255;
        green = 0;  
        blue = 0;
        
        if (switcher == -1) {
          red = 255;
          green = 10;  
          blue = 10;
        }
        colorTime = 20;
        
        switcher = switcher*-1;
      }
      
       
     
      colorWipe(strip.Color(red,green,blue), colorTime); 

      int b1missing = 1;
      if (b1.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 1/*"b1"*/){
            buttonsMissing - b1missing;
            b1missing = 0;
            //screen1.print("\\b1/right//");

          }
          else{
            wrongButton--;
            //screen1.print("\\b1/wrong//");
          }
        } 
      }

      
      if (b2.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 2/*"b2"*/){
            buttonsMissing = buttonsMissing - b2missing;
            b2missing = 0;
            //screen1.print("\\b2/right//");
          }
          else{
            wrongButton--;
            //screen1.print("\\b2/wrong//");
          }
        } 
      }
      
    
      if (b3.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 3/*"b3"*/){
            buttonsMissing = buttonsMissing - b3missing;
            b3missing = 0;
            //screen1.print("\\b3/right//");
          }
          else{
            wrongButton--;
            //screen1.print("\\b3/wrong//");
          }
        } 
      }
      
      
      if (b4.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 4/*"b4"*/){
            buttonsMissing = buttonsMissing - b4missing;
            b4missing = 0;
            //screen1.print("\\b4/right//");
          }
          else{
            wrongButton--;
            //screen1.print("\\b4/wrong//");
          }
        } 
      }

      
      if (b5.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 5/*"b5"*/){
            buttonsMissing = buttonsMissing - b5missing;
            b5missing = 0;
            //screen2.print("\\b5/right//");
          }
          else{
            wrongButton--;
            //screen2.print("\\b5/wrong//");
          }
        } 
      }

      
      if (b6.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 6/*"b6"*/){ 
            buttonsMissing = buttonsMissing - b6missing;
            b6missing = 0;
            //screen2.print("\\b6/right//");
          }
          else{
            wrongButton--;
            //screen2.print("\\b6/wrong//");
          }
        } 
      }
      
    
      if (b7.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 7/*"b7"*/){
            buttonsMissing = buttonsMissing - b7missing;
            b7missing = 0;
            //screen2.print("\\b7/right//");
          }
          else{
            wrongButton--;
            //screen2.print("\\b7/wrong//");
          }
        } 
      }

      
      if (b8.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 8/*"b8"*/){
            buttonsMissing = buttonsMissing - b8missing;
            b8missing = 0;
            //screen2.print("\\b8/right//");
          }
          else{
            wrongButton--;
            //screen2.print("\\b8/wrong//");
          }
        } 
      }
  
      if (b9.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 9/*"b9"*/){
            buttonsMissing = buttonsMissing - b9missing;
            b9missing = 0;
            //screen3.print("\\b9/right//");
          }
          else{
            wrongButton--;
            //screen3.print("\\b9/wrong//");
          }
        } 
      }
  
      if (b10.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 10/*"b10"*/){
            buttonsMissing = buttonsMissing - b10missing;
            b10missing = 0;
            //screen3.print("\\b10/right//");
          }
          else{
            wrongButton--;
            //screen3.print("\\b10/wrong//");
          }
        } 
      }
  
      if (b11.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 11/*"b11"*/){
            buttonsMissing = buttonsMissing - b11missing;
            b11missing = 0;
            //screen3.print("\\b11/right//");
          }
          else{
            wrongButton--;
            //screen3.print("\\b11/wrong//");
          }
        } 
      }
  
      if (b12.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 12/*"b12"*/){
            buttonsMissing = buttonsMissing - b12missing;
            b12missing = 0;
            //screen3.print("\\b12/right//");
          }
          else{
            wrongButton--;
            //screen3.print("\\b12/wrong//");
          }
        } 
      }
  
      if (b13.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 13/*"b13"*/){
            buttonsMissing = buttonsMissing - b13missing;
            b13missing = 0;
            //screen4.print("\\b13/right//");
          }
          else{
            wrongButton--;
            //screen4.print("\\b13/wrong//");
          }
        } 
      }
  
      if (b14.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 14/*"b14"*/){
            buttonsMissing = buttonsMissing - b14missing;
            b14missing = 0;
            //screen4.print("\\b14/right//");
          }
          else{
            wrongButton--;
            //screen4.print("\\b14/wrong//");
          }
        } 
      }
  
      if (b15.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 15/*"b15"*/){
            buttonsMissing = buttonsMissing - b15missing;
            b15missing = 0;
            //screen4.print("\\b15/right//");
          }
          else{
            wrongButton--;
            //screen4.print("\\b15/wrong//");
          }
        } 
      }
  
      if (b16.isReleased()) {
        for (int i = 0; i < 4; i++) {
          if (gameButtons[i] == 16/*"b16"*/){
            buttonsMissing = buttonsMissing - b16missing;
            b16missing = 0;
            //screen4.print("\\b16/right//");
          }
          else{
            wrongButton--;
            //screen4.print("\\b16/wrong//");
          }
        } 
      }
  
  
      if (buttonsMissing == 0) {
        weWon = true;
        timer = 20000; 
        
      }
  
      if (wrongButton == 0) {
        weWon = false;
        timer = 20000;
      }
  
      
      timer = timer + (colorTime * PIXEL_COUNT);
      
  
    }
  
    if (weWon == true) {
      delay(10000);
      displayWon(screen1);
      displayWon(screen2);   
      displayWon(screen3);
      displayWon(screen4);
      theaterChaseRainbow(300);
      
    }
    else if (weWon == false) { 
      delay(10000);
      displayLost(screen1);
      displayLost(screen2);   
      displayLost(screen3);
      displayLost(screen4); 
      colorWipe(strip.Color(0,191,255), 300);
    }

  }

}

/*
do
  {
    randNumber = random(1,6); // generate random number between 1 & 5 (minimum is inclusive, maximum is exclusive)
  } while (randNumber != prevRand);
*/
