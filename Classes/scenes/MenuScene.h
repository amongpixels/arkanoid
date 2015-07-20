/* 
 * File:   MenuScene.h
 * Author: dragomir
 *
 * Created on 19 July 2015, 23:17
 */

#ifndef MENUSCENE_H
#define	MENUSCENE_H

#include "cocos2d.h"
#include "LevelScene.h"
#include "game/HighScore.h"

class MenuScene : public cocos2d::Layer {
private:
  arkanoid::HighScore highScore;
  
  void createLogo(const cocos2d::Size& visibleSize);
  void createMenu(const cocos2d::Size& visibleSize);
  void createHighScore(const cocos2d::Size& visibleSize);
  
  void newGameButtonCallback (Ref* pSender);
  void exitButtonCallback (Ref* pSender);
public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  
  CREATE_FUNC(MenuScene);
};

#endif	/* MENUSCENE_H */

