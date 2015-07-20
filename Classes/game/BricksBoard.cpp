/* 
 * File:   Bricks.cpp
 * Author: dragomir
 * 
 * Created on 19 July 2015, 12:51
 */

#include "BricksBoard.h"
#include "Brick.h"

arkanoid::BricksBoard::BricksBoard() {

}

void arkanoid::BricksBoard::createBoard(int width, int height, float screenWidth, float screenHeight) {
  float offsetX, offsetY; // these are used to place one brick after another in rows and columns
  float centerOffsetX, centerOffsetY; // these are used to center the whole board in the middle and off the top of the screen
  
  this->boardWidth = width;
  this->boardHeight = height;
  
  for (int x = 0 ; x < this->boardWidth ; x++) {
    
    offsetY = 0.0;
    
    for (int y = 0 ; y < this->boardHeight ; y++) {
      this->bricks.push_back(new Brick(cocos2d::random<int>(0, BRICK_TYPES_COUNT-1)));
      
      /*
       * Because we don't know the size of the brick till we load the first file
       * (we assume all bricks have the same size) calculate centering offsets 
       * after the first brick loads
       */
      if (x == 0 && y == 0) {
        auto size = this->bricks.back()->getContentSize();
        centerOffsetX = (screenWidth - (width - 1) * size.width) * 0.5f; // that width - 1 is because anchor points are in the middle so we offset "back" by 0.5 of brick's width
        centerOffsetY = (screenHeight - (height + 2) * size.height) + size.height * 0.5f; // let's say that bricks always star at a distance of 2 * brick height off the top of the screen
      }
      
      this->bricks.back()->setPosition(offsetX + centerOffsetX, offsetY + centerOffsetY);
      
      offsetY += this->bricks.back()->getContentSize().height;
    }
    
    offsetX += this->bricks.back()->getContentSize().width;
  }
}

int arkanoid::BricksBoard::getBricksCount() {
  return this->bricks.size();
}

void arkanoid::BricksBoard::resetBoard() {
  for (auto brick : this->bricks) {
    brick->recreate();
  }
}

std::vector<arkanoid::Brick*>* arkanoid::BricksBoard::getBricks() {
  return &this->bricks;
}

arkanoid::BricksBoard::~BricksBoard() {
  
}

