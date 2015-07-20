/* 
 * File:   Brick.h
 * Author: dragomir
 *
 * Created on 19 July 2015, 17:34
 */

#ifndef BRICK_H
#define	BRICK_H

#include "cocos2d.h"
#include "CollisionMasks.h"

#define BRICK_TYPES_COUNT 3
#define BRICK_PURPLE 0
#define BRICK_RED 1
#define BRICK_YELLOW 2

#define BRICK_TAG 10

namespace arkanoid {
  class Brick : public cocos2d::Sprite {
  private:
    bool destroyed;
    int type;
    
    void initPhysicsBody();
    
  public:
    static char* spritePaths [BRICK_TYPES_COUNT];
    static cocos2d::PhysicsMaterial material;
    
    /**
     * "destroy" this brick when ball collides with it. Doesn't really destroy
     * the object, just removes it from physics simulation
     */
    void destroy();
    
    /**
     * After brick is destroyed it can be brought back to life with recreate()
     */
    void recreate();
    
    Brick(int);

  };
}

#endif	/* BRICK_H */

