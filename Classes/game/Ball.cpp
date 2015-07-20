/* 
 * File:   Ball.cpp
 * Author: dragomir
 * 
 * Created on 19 July 2015, 01:42
 */

#include "Ball.h"

arkanoid::Ball::Ball () {
  
  this->sprite = cocos2d::Sprite::create("ball/ballGrey.png");
  this->physicsBody = cocos2d::PhysicsBody::createCircle(10.0f, cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.5f));
  this->physicsBody->setCategoryBitmask(COLLISION_GROUP_BALL);
  this->physicsBody->setCollisionBitmask(COLLIDE_WITH_ALL);
  this->physicsBody->setContactTestBitmask(COLLIDE_WITH_ALL);
  
  this->sprite->setPosition(cocos2d::Vec2(400, 400));
  this->sprite->setPhysicsBody(this->physicsBody);
  this->sprite->setTag(BALL_TAG);

  this->physicsBody->setGravityEnable(false);
}

cocos2d::Sprite * arkanoid::Ball::getSprite() {
  
  return this->sprite;
}

void arkanoid::Ball::alignWithPaddle (const std::unique_ptr<arkanoid::Paddle> & paddle) {
  
  this->physicsBody->setVelocity(cocos2d::Vec2::ZERO);
  this->sprite->setPosition(paddle->getSprite()->getPosition().x, paddle->getSprite()->getPosition().y + 30.0f);
}

void arkanoid::Ball::applyVelocity () {
  
  this->physicsBody->setVelocity(cocos2d::Vec2(0.0f, 300.0f));
  this->physicsBody->setAngularVelocity(cocos2d::random(-4.0f, 4.0f)); // angular velocity makes the ball a bit more unpredictable = fun
}

arkanoid::Ball::~Ball() {
  
}

