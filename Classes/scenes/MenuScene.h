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

class MenuScene : public cocos2d::Layer {
private:
  void newGameButtonCallback (Ref* pSender);
  void exitButtonCallback (Ref* pSender);
public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  
  CREATE_FUNC(MenuScene);
};

#endif	/* MENUSCENE_H */

