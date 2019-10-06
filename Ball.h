#ifndef Ball_h
#define Ball_h

class Paddle;

class Ball {
  private:
    float xVel, yVel, x, y;
  public:
    Ball() {
      x = 7;
      y = 12;
      xVel = 2;
      yVel = 1;
    }
    void draw(Graphics& g) {
      Serial.println("Draw");
      Serial.println(y);
      g.drawPoint(x, y);
    }
    void move() {
      x += xVel;
      y += yVel;
      if (y < 0 || y > 15) {
        yVel = -yVel;
        y += yVel;
      }
    }

    void checkPaddleCollision(Paddle&, Paddle&);

    uint8_t getX() {
      return (uint8_t)x;
    }

    uint8_t getY() {
      Serial.println(y);
      return (uint8_t)y;
    }


};

#include "Paddle.h"

inline void Ball::checkPaddleCollision(Paddle& p1, Paddle& p2) {
  if (x <= 0) {
    if (y >= p1.getY() && y <= p1.getY() + 3) {
      xVel = -xVel;
      x += xVel;
    }
  } else if (x >= 23) {
    if (y >= p1.getY() && y <= p1.getY() + 3) {
      xVel = -xVel;
    }
  }
}
#endif
