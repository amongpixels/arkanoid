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

arkanoid::Brick::Brick(float offsetX, float offsetY) {
  this->sprite = cocos2d::Sprite::create(arkanoid::Brick::spritePaths[BRICK_RED]);
  this->sprite->setTag(BRICK_TAG);
  
  this->physicsBody = cocos2d::PhysicsBody::createBox(this->sprite->getContentSize(), arkanoid::Brick::material);
  this->physicsBody->setCategoryBitmask(COLLISION_GROUP_BRICK);
  this->physicsBody->setCollisionBitmask(COLLIDE_WITH_ALL);
  this->physicsBody->setContactTestBitmask(COLLIDE_WITH_ALL);
  
  this->sprite->setPosition(offsetX, offsetY);
  this->sprite->setPhysicsBody(physicsBody);
      
  this->physicsBody->setDynamic(false);
  
  auto contactListener = cocos2d::EventListenerPhysicsContact::create();
  contactListener->onContactBegin = CC_CALLBACK_1(arkanoid::Brick::onContactBegin, this);
  this->getSprite()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this->sprite);

  //cocos2d::schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);
}

bool arkanoid::Brick::onContactBegin(cocos2d::PhysicsContact& contact) {
  auto nodeA = contact.getShapeA()->getBody()->getNode();
  auto nodeB = contact.getShapeB()->getBody()->getNode();

  if (nodeA && nodeB) {
    if (nodeA->getTag() == BRICK_TAG) {
      nodeA->removeFromParentAndCleanup(true);
    } else if (nodeB->getTag() == BRICK_TAG) {
      nodeB->removeFromParentAndCleanup(true);
    }
  }

  //bodies can collide
  return true;
}

cocos2d::Sprite * arkanoid::Brick::getSprite() {
  return this->sprite;
}

arkanoid::Brick::~Brick() {
}

