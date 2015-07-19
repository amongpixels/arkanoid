#include "LevelScene.h"

USING_NS_CC;

Scene* LevelScene::createScene() {
  // 'scene' is an autorelease object
  auto scene = Scene::createWithPhysics();
  scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);

  // 'layer' is an autorelease object
  auto layer = LevelScene::create();

  // add layer as a child to scene
  scene->addChild(layer);


  // return the scene
  return scene;
}

void LevelScene::onMouseMove(Event* event) {
  EventMouse* e = (EventMouse*) event;
  std::string str = "MousePosition X:";
  str = str + std::to_string(e->getCursorX()) + " Y:" + std::to_string(e->getCursorY());

  this->paddle->setPosition(e->getCursorX());

  cocos2d::log(str.c_str());
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
    
    this->worldBoundNodes[i] = cocos2d::Node::create();
    this->worldBoundNodes[i]->setPosition(positions[i]);
    this->worldBoundNodes[i]->setPhysicsBody(this->worldBoundBodies[i]);

    this->addChild(this->worldBoundNodes[i]);
  }
}

void LevelScene::createBricks() {
  
  this->bricksBoard = std::unique_ptr<arkanoid::BricksBoard> (new arkanoid::BricksBoard());
  this->bricksBoard->createBoard(4, 4);
  
  for (auto brick : * this->bricksBoard->getBricks()) {
    this->addChild(brick->getSprite());
  }
  
}

// on "init" you need to initialize your instance

bool LevelScene::init() {

  //////////////////////////////
  // 1. super init first
  if (!Layer::init()) {
    return false;
  }

  this->paddle = std::unique_ptr<arkanoid::Paddle> (new arkanoid::Paddle());
  this->addChild(this->paddle->getSprite());

  this->ball = std::unique_ptr<arkanoid::Ball> (new arkanoid::Ball());
  
  this->createBricks();

  Size visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  this->createWorldBounds(visibleSize.width, visibleSize.height);

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

  this->addChild(this->ball->getSprite());

  this->mouseEventListener = EventListenerMouse::create();
  this->mouseEventListener->onMouseMove = CC_CALLBACK_1(LevelScene::onMouseMove, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->mouseEventListener, this);

  return true;
}

void LevelScene::menuCloseCallback(Ref* pSender) {
  Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
}
