#include"Graphics.h"
#include"Paddle.h"
#include"Ball.h"

Graphics g = Graphics(12, 11, 13);
//HumanPaddle humanPaddle = HumanPaddle(1);
Ball ball = Ball();
AIPaddle aiPaddle1=AIPaddle(1,ball);
AIPaddle aiPaddle2=AIPaddle(2,ball);

void setup() {
  Serial.begin(9600);

}

void paint() {
  //humanPaddle.draw(g);
  aiPaddle1.draw(g);
  aiPaddle2.draw(g);
  ball.draw(g);
  g.paint();
}

void repaint() {
  g.clearBuffer();
  paint();
}

void loop() {
  //humanPaddle.move();
  aiPaddle1.move();
  aiPaddle2.move();
  ball.move();
  ball.checkPaddleCollision(aiPaddle1, aiPaddle2);
  repaint();
  //delay(5);
}
