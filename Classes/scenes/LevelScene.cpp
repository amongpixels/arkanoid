#include "LevelScene.h"

USING_NS_CC;

Scene* LevelScene::createScene() {
  auto scene = Scene::createWithPhysics();
  scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);

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
  float padding = 20.0f;
  
  this->scoreLabel = Label::createWithTTF("Score:", "fonts/Marker Felt.ttf", 24);
  this->scoreLabel->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
  this->scoreLabel->setPosition(
    origin.x + padding, 
    origin.y + visibleSize.height - this->scoreLabel->getContentSize().height - padding
  );
  
  this->livesLabel = Label::createWithTTF("Lives:", "fonts/Marker Felt.ttf", 24);
  this->livesLabel->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
  this->livesLabel->setPosition(
    origin.x + padding,
    origin.y + visibleSize.height - this->scoreLabel->getContentSize().height - this->scoreLabel->getContentSize().height * 1.5f - padding
  );
  
  this->addChild(this->scoreLabel);
  this->addChild(this->livesLabel);
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
}

void LevelScene::loseLife() {
  this->lives -= 1;
  
  if (this->lives == 0) {
    this->gameOver();
  }
  
  this->updateLivesUI();
}

void LevelScene::gameOver() {
  
}

void LevelScene::setupCollisionEvents() {
  auto contactListener = cocos2d::EventListenerPhysicsContact::create();
  contactListener->onContactBegin = CC_CALLBACK_1(LevelScene::onContactBegin, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void LevelScene::setupMouseEvents() {
  this->mouseEventListener = EventListenerMouse::create();
  this->mouseEventListener->onMouseMove = CC_CALLBACK_1(LevelScene::onMouseMove, this);
  this->mouseEventListener->onMouseDown = CC_CALLBACK_1(LevelScene::onMouseClick, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->mouseEventListener, this);
}

// CALLBACKS start here

void LevelScene::onMouseMove (Event* event) {
  EventMouse* e = (EventMouse*) event;
  std::string str = "MousePosition X:";
  str = str + std::to_string(e->getCursorX()) + " Y:" + std::to_string(e->getCursorY());

  this->paddle->setPosition(e->getCursorX());
  
  if (gameState == GAME_STATE_INITIAL) {
    this->ball->alignWithPaddle(this->paddle);
  }

  //cocos2d::log(str.c_str());
}

void LevelScene::onMouseClick(Event* event) {
  if (gameState == GAME_STATE_INITIAL) {
    gameState = GAME_STATE_PLAYING;
    
    this->ball->applyVelocity();
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
      cocos2d::log("collision bottom");
    }
    
    
    if (brick) {
      brick->destroy();
      this->gainScore(1);
    }
  }
  
  

  //bodies can collide
  return true;
}

void LevelScene::restartGame() {
  this->lives = 3;
  this->score = 0;
  this->gameState = GAME_STATE_INITIAL;
  
  this->updateLivesUI();
  this->updateScoreUI();
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
  
  this->restartGame();
  
  // Display initial values

  /*
  /////////////////////////////
  // 2. add a menu item with "X" image, which is clicked to quit the program
  //    you may modify it.

  // add a "close" icon to exit the progress. it's an autorelease object
  auto closeItem = MenuItemImage::create(
                                         "CloseNormal.png",
                                         "CloseSelected.png",
                                         CC_CALLBACK_1(LevelScene::menuCloseCallback, this));
    
      closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                              origin.y + closeItem->getContentSize().height/2));

  // create menu, it's an autorelease object
  auto menu = Menu::create(closeItem, NULL);
  menu->setPosition(Vec2::ZERO);
  this->addChild(menu, 1);

  /////////////////////////////
  // 3. add your codes below...

  // add a label shows "Hello World"
  // create and initialize a label
    
  auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
  // position the label on the center of the screen
  label->setPosition(Vec2(origin.x + visibleSize.width/2,
                          origin.y + visibleSize.height - label->getContentSize().height));

  // add the label as a child to this layer
  this->addChild(label, 1);

  // add "HelloWorld" splash screen"
  auto sprite = Sprite::create("HelloWorld.png");

  // position the sprite on the center of the screen
  sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

  // add the sprite as a child to this layer
  this->addChild(sprite, 0);
    
   */
  return true;
}


