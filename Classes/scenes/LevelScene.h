#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#define WORLD_BOUND_TOP 0
#define WORLD_BOUND_RIGHT 1
#define WORLD_BOUND_BOTTOM 2
#define WORLD_BOUND_LEFT 3

#define GAME_STATE_INITIAL 1
#define GAME_STATE_PLAYING 2
#define GAME_STATE_OVER 3

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
  
  int score;
  int gameState;
  
  // These are used to limit bounds around the level so the ball doesn't fly off
  cocos2d::PhysicsBody * worldBoundBodies [4];
  cocos2d::Node * worldBoundNodes [4];
  
  std::unique_ptr <arkanoid::Ball> ball;
  std::unique_ptr <arkanoid::BricksBoard> bricksBoard;
  std::unique_ptr <arkanoid::Paddle> paddle;
  
  EventListenerMouse * mouseEventListener;
  
  void createWorldBounds (float worldWidth, float worldHeight);
  void createPaddle ();
  void createBall ();
  void createBricks ();
  
  void setupMouseEvents ();
  void setupCollisionEvents ();
  
  void onMouseMove (Event * );
  void onMouseClick (Event * );
  bool onContactBegin (cocos2d::PhysicsContact &);
  
public:
    static Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(LevelScene);
};

#endif // __HELLOWORLD_SCENE_H__
