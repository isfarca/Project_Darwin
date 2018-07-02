#include "MenuTest.h"
#include "HelloWorldScene.h"
#include "TouchScene.h"
#include <string>

USING_NS_CC;
using namespace std;


Scene* MenuTest::createScene() {

	
	return MenuTest::create();
};


bool MenuTest::init() {
	if (!Scene::init()) {
		return false;
	}
	
	string startGame = "menu/start-game.png";

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	startMenu = MenuItemImage::create(startGame, "menu/start-game-selected.png", CC_CALLBACK_1(MenuTest::changeScene, this)); 
	exitMenu = MenuItemImage::create("menu/exit-game.png", "menu/exit-game-selected.png", CC_CALLBACK_1(MenuTest::exitGame, this));
	
	auto menu = Menu::create(startMenu, nullptr);
	menu->setPosition(Point::ZERO);
	startMenu->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
	exitMenu->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 - exitMenu->getContentSize().height - 20);
	this->addChild(menu);
	return true;
}

void MenuTest::changeScene(Ref *pSender) {
	auto scene = TouchScene::createScene();
	Director::getInstance()->pushScene(TransitionFade::create(1.0f, scene));
	


}

void MenuTest::exitGame(Ref *pSender) {
	Director::getInstance()->end();
}