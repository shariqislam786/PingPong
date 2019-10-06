#ifndef Graphics_h
#define Graphics_h

#include "TwoDLEDMatrixCascade.h"

class Graphics {
  private:
    uint8_t buffer[24][2];
    TwoDLEDMatrixCascade ledMatrix;
    void swap(uint8_t *first, uint8_t *second) {
      //swap lower
      *first = *first ^ *second;
      *second = *first ^ *second;
      *first = *first ^ *second;
    }
  public:
    Graphics(uint8_t dataPin, uint8_t clkPin, uint8_t csPin): ledMatrix(dataPin, clkPin, csPin, 2, 3) {
      ledMatrix.shutdown(false);
      /* Set the brightness to a medium values */
      ledMatrix.setIntensity(8);
      /* and clear the display */
      ledMatrix.clearDisplay();
      ledMatrix.setRotation(0, 1);
      ledMatrix.setRotation(1, 1);
      ledMatrix.setRotation(2, 1);
      ledMatrix.setRotation(3, 3);
      ledMatrix.setRotation(4, 3);
      ledMatrix.setRotation(5, 3);
      for (int i = 0; i < 24; i++) {
        buffer[i][0] = 0;
        buffer[i][1] = 0;
      }
    }
    void paint() {
      for (int i = 0; i < 24; i++) {
        ledMatrix.setColumn(i, buffer[i]);
      }
    }

    void clearBuffer() {
      for (int i = 0; i < 24; i++) {
        buffer[i][0] = 0;
        buffer[i][1] = 0;
      }
    }


    void drawPoint(uint8_t x, uint8_t y) {
      buffer[x][y / 8] |= 128 >> y % 8;
    }

    void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
      if (x1 == x2) {
        if (y1 > y2) {
          swap(&y1, &y2);
        }
        for (uint8_t i = y1; i <= y2; i++) {
          buffer[x1][i / 8] |= 128 >> (i % 8);
        }
      }

      if (y1 == y2) {
        if (x1 > x2) {
          swap(&x1, &x2);
        }

        for (uint8_t i = x1; i <= x2; i++) {
          buffer[i][y1 / 8] |= 128 >> (y1 % 8);
        }
      }
    }

};


#endif
