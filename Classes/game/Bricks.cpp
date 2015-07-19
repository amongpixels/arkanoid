/* 
 * File:   Bricks.cpp
 * Author: dragomir
 * 
 * Created on 19 July 2015, 12:51
 */

#include "Bricks.h"

arkanoid::Bricks::Bricks() {
//  auto material = cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f);
//  
//  for (int i = 0 ; i < BRICK_TYPES_COUNT ; i++) {
//    this->baseBrickSprites[i] = cocos2d::Sprite::create(this->brickPaths[i]);
//    this->baseBrickBodies[i] = cocos2d::PhysicsBody::create(this->baseBrickSprites->getContentSize(), material);
//  }
}

void arkanoid::Bricks::createBoard(int width, int height) {
  this->boardWidth = width;
  this->boardHeight = height;
  
  cocos2d::Sprite * sprite;
  cocos2d::PhysicsBody * physicsBody;
  
  auto material = cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f);
  
  float offsetX, offsetY;
  
  for (int x = 0 ; x < this->boardWidth ; x++) {
    offsetY = 0.0;
    for (int y = 0 ; y < this->boardHeight ; y++) {
      
      sprite = cocos2d::Sprite::create(this->spritePaths[BRICK_RED]);
      physicsBody = cocos2d::PhysicsBody::createBox(sprite->getContentSize(), material);
      
      sprite->setPosition(offsetX, offsetY);
      sprite->setPhysicsBody(physicsBody);
      
      physicsBody->setDynamic(false);
      
      this->sprites.push_back(sprite);
      
      offsetY += sprite->getContentSize().height;
    }
    
    offsetX += sprite->getContentSize().width;
  }
}

std::vector <cocos2d::Sprite * > * arkanoid::Bricks::getSprites() {
  return &this->sprites;
}

arkanoid::Bricks::~Bricks() {
  
}

