/* 
 * File:   Bricks.cpp
 * Author: dragomir
 * 
 * Created on 19 July 2015, 12:51
 */

#include "BricksBoard.h"
#include "Brick.h"

arkanoid::BricksBoard::BricksBoard() {
//  auto material = cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f);
//  
//  for (int i = 0 ; i < BRICK_TYPES_COUNT ; i++) {
//    this->baseBrickSprites[i] = cocos2d::Sprite::create(this->brickPaths[i]);
//    this->baseBrickBodies[i] = cocos2d::PhysicsBody::create(this->baseBrickSprites->getContentSize(), material);
//  }
}

void arkanoid::BricksBoard::createBoard(int width, int height) {
  float offsetX, offsetY;
  
  this->boardWidth = width;
  this->boardHeight = height;
  
  for (int x = 0 ; x < this->boardWidth ; x++) {
    
    offsetY = 0.0;
    
    for (int y = 0 ; y < this->boardHeight ; y++) {
      
      this->bricks.push_back(std::unique_ptr<arkanoid::Brick>(new Brick(offsetX, offsetY)));
      
      offsetY += this->bricks.back()->getSprite()->getContentSize().height;
    }
    
    offsetX += this->bricks.back()->getSprite()->getContentSize().width;
  }
}

std::vector< std::shared_ptr<arkanoid::Brick> > * arkanoid::BricksBoard::getBricks() {
  return &this->bricks;
}

arkanoid::BricksBoard::~BricksBoard() {
  
}

