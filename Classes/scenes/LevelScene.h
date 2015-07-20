#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#define WORLD_BOUND_TOP 0
#define WORLD_BOUND_RIGHT 1
#define WORLD_BOUND_BOTTOM 2
#define WORLD_BOUND_LEFT 3

#define GAME_STATE_INITIAL 1
#define GAME_STATE_PLAYING 2
#define GAME_STATE_OVER 3
#define GAME_STATE_WON 4

#include <cstring>
#include <memory>

#include "cocos2d.h"
#include "MenuScene.h"
#include "game/Paddle.h"
#include "game/Ball.h"
#include "game/BricksBoard.h"

using namespace cocos2d;

class LevelScene : public Layer
{
private:
  
  int score, lives, gameState;
  
  // These are used to limit bounds around the level so the ball doesn't fly off
  cocos2d::PhysicsBody* worldBoundBodies [4];
  cocos2d::Node* worldBoundNodes [4];
  
  std::unique_ptr<arkanoid::Ball> ball;
  std::unique_ptr<arkanoid::BricksBoard> bricksBoard;
  std::unique_ptr<arkanoid::Paddle> paddle;
  
  cocos2d::Label *scoreLabel, *livesLabel, *gameOverLabel, *continueHint, *winLabel;
  
  void createWorldBounds(float worldWidth, float worldHeight);
  void createPaddle();
  void createBall();
  void createBricks(const cocos2d::Size& visibleSize);
  void createUI(const cocos2d::Vec2& origin, const cocos2d::Size& visibleSize);
  
  void updateScoreUI();
  void updateLivesUI();
  
  void resetGameVariables();
  void resetBallPosition(float dt);
  void resetGame();
  void loseLife();
  void gainScore(int increase);
  void gameWon();
  void gameOver();
  
  void setupMouseEvents();
  void setupCollisionEvents();
  void setupKeyboardEvents();
  
  void onMouseMove(Event* event);
  void onMouseClick(Event* event);
  void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
  bool onContactBegin(cocos2d::PhysicsContact& contact);
  
public:
    static Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(LevelScene);
};

#endif // __HELLOWORLD_SCENE_H__
