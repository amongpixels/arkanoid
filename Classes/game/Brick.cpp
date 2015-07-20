/* 
 * File:   Brick.cpp
 * Author: dragomir
 * 
 * Created on 19 July 2015, 17:34
 */

#include "Brick.h"

char * arkanoid::Brick::spritePaths [BRICK_TYPES_COUNT] = {
  "bricks/purple.png",
  "bricks/red.png",
  "bricks/yellow.png"
};

cocos2d::PhysicsMaterial arkanoid::Brick::material = cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f);

arkanoid::Brick::Brick(int type) {
  // Because we are creating our own sprite type remember to add it to cocos2d memory management release pool
  if (this->initWithFile(arkanoid::Brick::spritePaths[type])) {
    this->autorelease();
  }
  else {
    auto sprite = this; // haha what
    CC_SAFE_DELETE(sprite);
    return;
  }
  
  this->type = type;
  
  this->initPhysicsBody();
  this->setTag(BRICK_TAG); // Tags are used in contact callbacks so we know it's a brick!
  
}

void arkanoid::Brick::initPhysicsBody() {
  auto physicsBody = cocos2d::PhysicsBody::createBox(this->getContentSize(), arkanoid::Brick::material);
  physicsBody->setCategoryBitmask(COLLISION_GROUP_BRICK);
  physicsBody->setCollisionBitmask(COLLIDE_WITH_ALL);
  physicsBody->setContactTestBitmask(COLLIDE_WITH_ALL);
  physicsBody->setDynamic(false);
  
  this->setPhysicsBody(physicsBody);
}


void arkanoid::Brick::destroy() {
  this->destroyed = true;
  this->getPhysicsBody()->setEnable(false);
  this->setVisible(false);
}

void arkanoid::Brick::recreate() {
  this->destroyed = false;
  this->getPhysicsBody()->setEnable(true);
  this->setVisible(true);
}

