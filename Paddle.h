#include "Ball.h"
#ifndef Paddle_h
#define Paddle_h

class Paddle {
  public:
    virtual void move() = 0;
    virtual uint8_t getY() = 0;
    virtual void draw(Graphics&) = 0;
};

class HumanPaddle: public Paddle {
  private:
    uint8_t player, x;
    float y, yVel;
    boolean upAccel, downAccel;
    const double GRAVITY = 0.94;
  public:
    HumanPaddle(int player) {
      upAccel = false; downAccel = false;
      y = 6; yVel = 0;
      if (player == 1) {
        x = 0;
      } else {
        x = 23;
      }

    }
    void draw(Graphics& g) {
      g.drawLine(x, (uint8_t)y, x, y + 3);
    }

    void move() {
      if (upAccel) {
        yVel -= 2;
      } else if (downAccel) {
        yVel += 2;
      } else if (!upAccel && !downAccel) {
        yVel *= GRAVITY;
      }
      if (yVel >= 5)
        yVel = 5;
      else if (yVel <= -5)
        yVel = -5;

      y += yVel;

      if (y < 0)
        y = 0;
      if (y > 12)
        y = 12;
    }

    void setUpAccel(boolean input) {
      upAccel = input;
    }

    void setDownAccel(boolean input) {
      downAccel = input;
    }

    uint8_t getY() {
      return (uint8_t)y;
    }
};

class AIPaddle: public Paddle {
  private:
    uint8_t player, x;
    float y, yVel;
    const double GRAVITY = 0.94;
    Ball& ball;
  public:
    AIPaddle(int player, Ball& b1):ball(b1) {
      y = 6; yVel = 0;
      if (player == 1) {
        x = 0;
      } else {
        x = 23;
      }

    }
    void draw(Graphics& g) {
      g.drawLine(x, (uint8_t)y, x, y + 3);
    }

    void move() {
      y = ball.getY() - 2;
      if (y < 0)
        y = 0;
      if (y > 12)
        y = 12;
    }

    uint8_t getY() {
      return (uint8_t)y;
    }
};
#endif
