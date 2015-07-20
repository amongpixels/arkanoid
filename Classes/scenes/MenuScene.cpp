/* 
 * File:   MenuScene.cpp
 * Author: dragomir
 * 
 * Created on 19 July 2015, 23:17
 */

#include "MenuScene.h"

cocos2d::Scene* MenuScene::createScene() {
  auto scene = cocos2d::Scene::create();
  auto layer = MenuScene::create();

  // add layer as a child to scene
  scene->addChild(layer);

  return scene;
}

void MenuScene::createLogo(const cocos2d::Size& visibleSize) {
  auto logo = cocos2d::Sprite::create("menu/logo.png");
  logo->setPosition(visibleSize.width * 0.5f, visibleSize.height - logo->getContentSize().height * 0.5 - 50.0f);
  this->addChild(logo);
}

void MenuScene::createMenu(const cocos2d::Size& visibleSize) {
  float offsetTop = 100.0f; // by how much offset the menu from the center top
  
  // New game button
  auto newGameButton = cocos2d::MenuItemImage::create(
    "menu/new_game_button_normal.png",
    "menu/new_game_button_selected.png",
    CC_CALLBACK_1(MenuScene::newGameButtonCallback, this)
  );
  newGameButton->setPosition(visibleSize.width * 0.5f, visibleSize.height * 0.5f - offsetTop);

  // Exit button
  auto exitButton = cocos2d::MenuItemImage::create(
    "menu/exit_button_normal.png",
    "menu/exit_button_selected.png",
    CC_CALLBACK_1(MenuScene::exitButtonCallback, this)
  );
  exitButton->setPosition(
    visibleSize.width * 0.5f, 
    visibleSize.height * 0.5f - newGameButton->getContentSize().height - 20.0f - offsetTop
  );

  auto menu = cocos2d::Menu::create(newGameButton, exitButton, NULL);
  menu->setPosition(cocos2d::Vec2::ZERO);
  this->addChild(menu, 1);
}

void MenuScene::createHighScore(const cocos2d::Size& visibleSize) {
  auto highScoreLabel = cocos2d::Label::createWithTTF(
    std::string("Current high score: ") + std::to_string(this->highScore.getHighScore()),
    "fonts/Marker Felt.ttf", 
    24
  );
  highScoreLabel->setPosition(visibleSize.width * 0.5f, visibleSize.height * 0.5f);
  
  this->addChild(highScoreLabel);
}

bool MenuScene::init() {
  if (!cocos2d::Layer::init()) {
    return false;
  }

  cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
  cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

  // Create and place logo in the middle
  this->createLogo(visibleSize);
  this->createMenu(visibleSize);
  this->createHighScore(visibleSize);

  return true;
}

void MenuScene::newGameButtonCallback(Ref* pSender) {
  auto scene = LevelScene::createScene();
  cocos2d::Director::getInstance()->replaceScene(scene);
}

void MenuScene::exitButtonCallback(Ref* pSender) {
  cocos2d::Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
}
