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
    //this->autorelease();
  }
  else {
    //auto sprite = this; // haha what
    //CC_SAFE_DELETE(sprite);
    return;
  }
  
  this->type = type;
  
  auto physicsBody = cocos2d::PhysicsBody::createBox(this->getContentSize(), arkanoid::Brick::material);
  physicsBody->setCategoryBitmask(COLLISION_GROUP_BRICK);
  physicsBody->setCollisionBitmask(COLLIDE_WITH_ALL);
  physicsBody->setContactTestBitmask(COLLIDE_WITH_ALL);
  physicsBody->setDynamic(false);
  
  this->setTag(BRICK_TAG); // Tags are used in contact callbacks so we know it's a brick!
  //this->setPosition(offsetX, offsetY);
  this->setPhysicsBody(physicsBody);
  
  // Let brick handle its own collision
  //auto contactListener = cocos2d::EventListenerPhysicsContact::create();
  //contactListener->onContactBegin = CC_CALLBACK_1(arkanoid::Brick::onContactBegin, this);
  //this->getSprite()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this->sprite);

  //cocos2d::schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);
}

void arkanoid::Brick::destroy() {
  this->removeFromParentAndCleanup(true);
}

//bool arkanoid::Brick::onContactBegin(cocos2d::PhysicsContact& contact) {
//  auto nodeA = contact.getShapeA()->getBody()->getNode();
//  auto nodeB = contact.getShapeB()->getBody()->getNode();
//
//  if (nodeA && nodeB) {
//    if (nodeA->getTag() == BRICK_TAG) {
//      nodeA->removeFromParentAndCleanup(true);
//    } else if (nodeB->getTag() == BRICK_TAG) {
//      nodeB->removeFromParentAndCleanup(true);
//    }
//  }
//
//  //bodies can collide
//  return true;
//}

//cocos2d::Sprite * arkanoid::Brick::getSprite() {
//  return this->sprite;
//}

//arkanoid::Brick::~Brick() {
//}

