/* 
 * File:   Paddle.cpp
 * Author: dragomir
 * 
 * Created on 18 July 2015, 22:56
 */

#include "Paddle.h"

arkanoid::Paddle::Paddle() {
  auto material = cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f);
  
  this->sprite = cocos2d::Sprite::create("paddle/paddleRed.png");
  this->physicsBody = cocos2d::PhysicsBody::createBox(this->sprite->getContentSize(), material);
  this->physicsBody->setDynamic(false);
  this->physicsBody->setCategoryBitmask(COLLISION_GROUP_PADDLE);
  this->physicsBody->setCollisionBitmask(COLLIDE_WITH_ALL);
  
  this->sprite->setPhysicsBody(this->physicsBody);
}

cocos2d::Sprite* arkanoid::Paddle::getSprite() {
  return this->sprite;
}

void arkanoid::Paddle::setPosition(float x) {
  this->sprite->setPosition(x, this->offsetY);
} 

arkanoid::Paddle::~Paddle() {
  
}

