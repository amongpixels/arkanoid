/* 
 * File:   Bricks.h
 * Author: dragomir
 *
 * Created on 19 July 2015, 12:51
 */

#ifndef BRICKS_H
#define	BRICKS_H

#include <vector>
#include <memory>

#include "cocos2d.h"
#include "Brick.h"

namespace arkanoid {
  class BricksBoard {
  private:
    
    int boardWidth;
    int boardHeight;
    
    std::vector <std::shared_ptr<arkanoid::Brick>> bricks;
    
  public:
    
    BricksBoard();
    /**
     * Creates a brick board of width x height bricks, centers in the screen of 
     * given dimensions
     * @param width
     * @param height
     * @param screenWidth
     * @param screenHeight
     */
    void createBoard (int width, int height, float screenWidth, float screenHeight);
    
    std::vector <std::shared_ptr<arkanoid::Brick>> * getBricks ();
    
    virtual ~BricksBoard();

  };
}

#endif	/* BRICKS_H */

