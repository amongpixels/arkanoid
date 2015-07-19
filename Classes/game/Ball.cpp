/* 
 * File:   Ball.cpp
 * Author: dragomir
 * 
 * Created on 19 July 2015, 01:42
 */

#include "Ball.h"

static const int DRAG_BODYS_TAG = 0x79;

arkanoid::Ball::Ball() {
  this->sprite = cocos2d::Sprite::create("ball/ballGrey.png");
  this->physicsBody = cocos2d::PhysicsBody::createCircle(10.0f, cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f));
  this->physicsBody->setCategoryBitmask(COLLISION_GROUP_BALL);
  this->physicsBody->setCollisionBitmask(COLLIDE_WITH_ALL);
  this->physicsBody->setContactTestBitmask(COLLIDE_WITH_ALL);
  
  this->sprite->setPosition(cocos2d::Vec2(400, 400));
  this->sprite->setPhysicsBody(this->physicsBody);

  this->physicsBody->setGravityEnable(false);

  this->physicsBody->setVelocity(cocos2d::Vec2(cocos2d::random(-500, 500), cocos2d::random(-500, 500)));
  this->physicsBody->setTag(DRAG_BODYS_TAG);
}

cocos2d::Sprite * arkanoid::Ball::getSprite() {
  return this->sprite;
}

arkanoid::Ball::~Ball() {
}

