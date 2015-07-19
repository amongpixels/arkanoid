#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#define WORLD_BOUND_TOP 0
#define WORLD_BOUND_RIGHT 1
#define WORLD_BOUND_BOTTOM 2
#define WORLD_BOUND_LEFT 3

#include <cstring>
#include <memory>

#include "cocos2d.h"
#include "game/Paddle.h"
#include "game/Ball.h"
#include "game/BricksBoard.h"

using namespace cocos2d;

class LevelScene : public Layer
{
private:
  EventListenerMouse * mouseEventListener;
  
  cocos2d::PhysicsBody * worldBoundBodies [4];
  cocos2d::Node * worldBoundNodes [4];
  
  std::unique_ptr <arkanoid::Ball> ball;
  std::unique_ptr <arkanoid::BricksBoard> bricksBoard;
  std::unique_ptr <arkanoid::Paddle> paddle;
  
  void onMouseMove (Event * );
  void createWorldBounds (float worldWidth, float worldHeight);
  void createBricks ();
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    //virtual ~LevelScene();
    
    // implement the "static create()" method manually
    CREATE_FUNC(LevelScene);
};

#endif // __HELLOWORLD_SCENE_H__
