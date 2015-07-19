/* 
 * File:   Bricks.h
 * Author: dragomir
 *
 * Created on 19 July 2015, 12:51
 */

#ifndef BRICKS_H
#define	BRICKS_H

#define BRICK_TYPES_COUNT 3
#define BRICK_PURPLE 0
#define BRICK_RED 1
#define BRICK_YELLOW 2

#include <vector>
#include "cocos2d.h"

namespace arkanoid {
  class Bricks {
  private:
    
    const char * spritePaths [BRICK_TYPES_COUNT] = { "bricks/purple.png", "bricks/red.png", "bricks/yellow.png" };
    
    //cocos2d::Sprite * baseBrickSprites [BRICK_TYPES_COUNT];
    //cocos2d::PhysicsBody * baseBrickBodies [BRICK_TYPES_COUNT];
    
    int boardWidth;
    int boardHeight;
    
    std::vector <cocos2d::Sprite *> sprites;
    
    //cocos2d::Sprite * brickSprites;
    //cocos2d::PhysicsBody * brickBodies;
  public:
    Bricks();
    void createBoard (int, int);
    
    std::vector <cocos2d::Sprite *> * getSprites ();
    
    virtual ~Bricks();
  

  };
}

#endif	/* BRICKS_H */

