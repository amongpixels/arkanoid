/* 
 * File:   HighScore.h
 * Author: dragomir
 *
 * Created on 20 July 2015, 13:38
 */

#ifndef HIGHSCORE_H
#define	HIGHSCORE_H

#include <cstdio>

#include "cocos2d.h"

namespace arkanoid {
  /**
   * A quick and dirty highscore storage
   */
  class HighScore {
  private:
    static char* storagePath;
    int score;
  public:
    HighScore();
    /**
     * This will only save the score as high score if it's higher than current highscore
     * @param score
     */
    void saveHighScore(int score);
    int getHighScore();
    virtual ~HighScore();
  };
}

#endif	/* HIGHSCORE_H */

