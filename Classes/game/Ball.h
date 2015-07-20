/* 
 * File:   Ball.h
 * Author: dragomir
 *
 * Created on 19 July 2015, 01:42
 */

#ifndef BALL_H
#define	BALL_H

#define BALL_TAG 11

#include <memory>

#include "cocos2d.h"
#include "CollisionMasks.h"
#include "Paddle.h"

namespace arkanoid {
  
  class Ball {
  private:
    cocos2d::Sprite* sprite;
    cocos2d::PhysicsBody* physicsBody;
  public:
    Ball();
    cocos2d::Sprite* getSprite ();
    
    /**
     * Given the paddle it places the ball on it
     * @param paddle
     */
    void alignWithPaddle(const std::unique_ptr<arkanoid::Paddle>& paddle);
    
    /**
     * Kickstarts the ball to move
     */
    void applyVelocity();
    
    /**
     * Reduces all ball velocity to zero
     */
    void killVelocity();
    
    virtual ~Ball();
  

  };
}

#endif	/* BALL_H */

