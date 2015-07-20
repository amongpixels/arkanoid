#include "LevelScene.h"

USING_NS_CC;

Scene* LevelScene::createScene() {
  auto scene = Scene::createWithPhysics();
  //scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);

  auto layer = LevelScene::create();
  
  scene->addChild(layer);
  
  return scene;
}

void LevelScene::createWorldBounds(float worldWidth, float worldHeight) {
  cocos2d::Vec2 positions [] = {
    Vec2(worldWidth * 0.5f, worldHeight), // top bound
    Vec2(worldWidth, worldHeight * 0.5f), // right bound
    Vec2(worldWidth * 0.5f, 0.0f), // bottom bound
    Vec2(0.0f, worldHeight * 0.5f) // left bound
  };
  
  auto material = cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f);

  for (int i = 0; i < 4; i++) {
    this->worldBoundBodies[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(i % 2 == 0 ? worldWidth : 1.0f, i % 2 == 0 ? 1.0f : worldHeight), material);
    this->worldBoundBodies[i]->setDynamic(false);
    this->worldBoundBodies[i]->setCategoryBitmask(COLLISION_GROUP_WORLD_BOUND);
    this->worldBoundBodies[i]->setCollisionBitmask(COLLIDE_WITH_ALL);
    this->worldBoundBodies[i]->setContactTestBitmask(COLLIDE_WITH_ALL);
    
    this->worldBoundNodes[i] = cocos2d::Node::create();
    this->worldBoundNodes[i]->setPosition(positions[i]);
    this->worldBoundNodes[i]->setPhysicsBody(this->worldBoundBodies[i]);
    this->worldBoundNodes[i]->setTag(i);

    this->addChild(this->worldBoundNodes[i]);
  }
}

void LevelScene::createBricks(const cocos2d::Size& visibleSize) {
  this->bricksBoard = std::unique_ptr<arkanoid::BricksBoard> (new arkanoid::BricksBoard());
  this->bricksBoard->createBoard(10, 7, visibleSize.width, visibleSize.height);
  
  for (auto brick : * this->bricksBoard->getBricks()) {
    this->addChild(brick);
  }
}

void LevelScene::createPaddle() {
  this->paddle = std::unique_ptr<arkanoid::Paddle> (new arkanoid::Paddle());
  this->addChild(this->paddle->getSprite());
  
  // Set the paddle in the middle of the screen
  this->paddle->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width * 0.5f);
}

void LevelScene::createBall() {
  this->ball = std::unique_ptr<arkanoid::Ball> (new arkanoid::Ball());
  this->addChild(this->ball->getSprite());
  
  this->ball->alignWithPaddle(this->paddle);
}

void LevelScene::createUI(const cocos2d::Vec2& origin, const cocos2d::Size& visibleSize) {
  float padding = 20.0f; // how much padding of the edges of the screen UI labels have
  
  // Score label
  this->scoreLabel = Label::createWithTTF("Score:", "fonts/Marker Felt.ttf", 24);
  this->scoreLabel->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
  this->scoreLabel->setPosition(
    origin.x + padding, 
    origin.y + visibleSize.height - this->scoreLabel->getContentSize().height - padding
  );
  
  // Lives label
  this->livesLabel = Label::createWithTTF("Lives:", "fonts/Marker Felt.ttf", 24);
  this->livesLabel->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
  this->livesLabel->setPosition(
    origin.x + padding,
    origin.y + visibleSize.height - this->scoreLabel->getContentSize().height - this->scoreLabel->getContentSize().height * 1.5f - padding
  );
  
  // TODO: rewrite below, organise in some sort of layers/screens for each situation
  
  // Game over label
  this->gameOverLabel = Label::createWithTTF("GAME OVER", "fonts/Marker Felt.ttf", 42);
  this->gameOverLabel->setPosition(
    origin.x + visibleSize.width * 0.5f,
    origin.y + visibleSize.height * 0.5f
  );
  this->gameOverLabel->setVisible(false);
  
  // Hint after game is over or won
  this->continueHint = Label::createWithTTF("Press mouse button to start over, ESC to go back to the menu", "fonts/Marker Felt.ttf", 24);
  this->continueHint->setPosition(
    origin.x + visibleSize.width * 0.5f,
    origin.y + visibleSize.height * 0.5f - this->gameOverLabel->getContentSize().height * 1.5f
  );
  this->continueHint->setVisible(false);
  
  // Game won label
  this->winLabel = Label::createWithTTF("STAGE CLEARED", "fonts/Marker Felt.ttf", 42);
  this->winLabel->setPosition(
    origin.x + visibleSize.width * 0.5f,
    origin.y + visibleSize.height * 0.5f
  );
  this->winLabel->setVisible(false);
  
  
  this->addChild(this->scoreLabel);
  this->addChild(this->livesLabel);
  this->addChild(this->gameOverLabel);
  this->addChild(this->continueHint);
  this->addChild(this->winLabel);
}

void LevelScene::updateScoreUI() {
  this->scoreLabel->setString(std::string("Score: ") + std::to_string(this->score));
}

void LevelScene::updateLivesUI() {
  this->livesLabel->setString(std::string("Lives: ") + std::to_string(this->lives));
}

void LevelScene::gainScore(int increase) {
  this->score += increase;
  this->updateScoreUI();
  
  if (this->score == this->bricksBoard->getBricksCount()) {
    this->gameWon();
  }
}

void LevelScene::loseLife() {
  this->lives -= 1;
  
  if (this->lives == 0) {
    this->gameOver();
  }
  else {
    this->ball->killVelocity();
    this->gameState = GAME_STATE_INITIAL;
    this->ball->alignWithPaddle(this->paddle);
    
    /*
     * Because ball position depends on physcis we need to schedule a separate 
     * event to make sure the ball position is set correctly to in front of 
     * the paddle
     */
    this->scheduleOnce(CC_SCHEDULE_SELECTOR(LevelScene::resetBallPosition), 0.1f);
  }
  
  this->updateLivesUI();
}

void LevelScene::gameWon() {
  this->gameState = GAME_STATE_WON;
  
  this->ball->killVelocity();
  this->winLabel->setVisible(true);
  this->continueHint->setVisible(true);
}

void LevelScene::gameOver() {
  this->gameState = GAME_STATE_OVER;
  
  this->gameOverLabel->setVisible(true);
  this->continueHint->setVisible(true);
}

void LevelScene::resetGame() {
  this->resetGameVariables();
  this->bricksBoard->resetBoard();
  this->ball->alignWithPaddle(this->paddle);
  this->gameState = GAME_STATE_INITIAL;
  
  this->continueHint->setVisible(false);
  this->gameOverLabel->setVisible(false);
  this->winLabel->setVisible(false);
}

void LevelScene::setupCollisionEvents() {
  auto contactListener = cocos2d::EventListenerPhysicsContact::create();
  contactListener->onContactBegin = CC_CALLBACK_1(LevelScene::onContactBegin, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void LevelScene::setupMouseEvents() {
  auto mouseEventListener = EventListenerMouse::create();
  mouseEventListener->onMouseMove = CC_CALLBACK_1(LevelScene::onMouseMove, this);
  mouseEventListener->onMouseDown = CC_CALLBACK_1(LevelScene::onMouseClick, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseEventListener, this);
}

void LevelScene::setupKeyboardEvents() {
  auto keyboardListener = cocos2d::EventListenerKeyboard::create();
  keyboardListener->onKeyPressed = CC_CALLBACK_2(LevelScene::onKeyPressed, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

// CALLBACKS start here

void LevelScene::onMouseMove (Event* event) {
  EventMouse* e = (EventMouse*) event;
  
  this->paddle->setPosition(e->getCursorX());
  
  if (gameState == GAME_STATE_INITIAL) {
    this->ball->alignWithPaddle(this->paddle);
  }
}

void LevelScene::onMouseClick(Event* event) {
  if (this->gameState == GAME_STATE_INITIAL) {
    this->gameState = GAME_STATE_PLAYING;
    
    this->ball->applyVelocity();
  }
  else if (this->gameState == GAME_STATE_OVER || this->gameState == GAME_STATE_WON) {
    this->resetGame();
  }
}

bool LevelScene::onContactBegin (cocos2d::PhysicsContact& contact) {
  auto nodeA = contact.getShapeA()->getBody()->getNode();
  auto nodeB = contact.getShapeB()->getBody()->getNode();
  
  arkanoid::Brick * brick = NULL;

  if (nodeA && nodeB) {
    // Check if we are dealing with ball-brick collision
    if (nodeA->getTag() == BRICK_TAG && nodeB->getTag() == BALL_TAG) {
      brick = (arkanoid::Brick *)(nodeA);
    } else if (nodeA->getTag() == BALL_TAG && nodeB->getTag() == BRICK_TAG) {
      brick = (arkanoid::Brick *)(nodeB);
    }
    // Check if we are dealing with ball vs bottom-world-bound collision
    else if 
      ((nodeA->getTag() == BALL_TAG && nodeB->getTag() == WORLD_BOUND_BOTTOM) ||
       (nodeA->getTag() == WORLD_BOUND_BOTTOM && nodeB->getTag() == BALL_TAG)) {
      // Ball hit the bottom of the screen!
      this->loseLife();
      return false; // Ignore normal collision processing
    }
    
    if (brick) {
      brick->destroy();
      this->gainScore(1);
    }
  }
  
  // Bodies can collide
  return true;
}

void LevelScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
  // On escape go back to menu
  if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE) {
    auto menu = MenuScene::createScene();
    cocos2d::Director::getInstance()->replaceScene(menu);
  }
}

void LevelScene::resetGameVariables() {
  this->lives = 3;
  this->score = 0;
  this->gameState = GAME_STATE_INITIAL;
  
  this->updateLivesUI();
  this->updateScoreUI();
}

void LevelScene::resetBallPosition(float dt) {
  this->ball->alignWithPaddle(this->paddle);
}

bool LevelScene::init() {
  if (!Layer::init()) {
    return false;
  }
  
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();
  
  this->createBricks(visibleSize);
  this->createPaddle();
  this->createBall();
  this->createWorldBounds(visibleSize.width, visibleSize.height);
  this->createUI(origin, visibleSize);
  
  this->setupCollisionEvents();
  this->setupMouseEvents();
  this->setupKeyboardEvents();
  
  this->resetGameVariables();
  
  return true;
}


