/* 
 * File:   Paddle.h
 * Author: dragomir
 *
 * Created on 18 July 2015, 22:56
 */

#ifndef PADDLE_H
#define	PADDLE_H

#include "cocos2d.h"

namespace arkanoid {

  class Paddle {
  private:
    const float offsetY = 100.0f;
    
    cocos2d::Sprite * sprite;
    cocos2d::PhysicsBody * physicsBody;
  public:
    Paddle();
    
    cocos2d::Sprite * getSprite ();
    void setPosition (float);
    
    virtual ~Paddle();
  private:

  };
}


#endif	/* PADDLE_H */

