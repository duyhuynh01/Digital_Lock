  #ifndef KEYPAD_HPP
  #define KEYPAD_HPP

  #include <Arduino.h>
  #include <TFT_eSPI.h> // Include TFT_eSPI library

  // Keypad start position, key sizes and spacing
  #define KEY_X 40 // Centre of key
  #define KEY_Y 96
  #define KEY_W 62 // Width and height
  #define KEY_H 30
  #define KEY_SPACING_X 18 // X and Y gap
  #define KEY_SPACING_Y 20
  #define KEY_TEXTSIZE 1 // Font size multiplier

  // Using two fonts since numbers are nice when bold
  #define LABEL1_FONT &FreeSansOblique12pt7b // Key label font 1
  #define LABEL2_FONT &FreeSansBold12pt7b    // Key label font 2

  // Numeric display box size and location
  #define DISP_X 1
  #define DISP_Y 10
  #define DISP_W 238
  #define DISP_H 50
  #define DISP_TSIZE 3
  #define DISP_TCOLOR TFT_CYAN

  // Number length, buffer for storing it and character index
  #define NUM_LEN 12

    // We have a status line for messages
  #define STATUS_X 120 // Centred on this
  #define STATUS_Y 65

//   TFT_eSPI_Button key[15];

// uint16_t keyColor[15] = {TFT_RED, TFT_DARKGREY, TFT_DARKGREEN,
//                          TFT_BLUE, TFT_BLUE, TFT_BLUE,
//                          TFT_BLUE, TFT_BLUE, TFT_BLUE,
//                          TFT_BLUE, TFT_BLUE, TFT_BLUE,
//                          TFT_BLUE, TFT_BLUE, TFT_BLUE};

// char keyLabel[15][5] = {"New", "Del", "Send", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", "0", "#"};

// uint8_t numberIndex = 0;

// char numberBuffer[NUM_LEN + 1] = "";


extern char keyLabel[15][5];
extern uint16_t keyColor[15];
extern uint8_t numberIndex;
extern char numberBuffer[NUM_LEN + 1];

  //------------------------------------------------------------------------------------------
  class Keypadprint
{
public:
  Keypadprint();
  void initKeypad();
  void drawKeypad();
  bool getKeypad();
  void status(const char *msg);
  void calibration();
  TFT_eSPI tft = TFT_eSPI();
  };

  #endif
