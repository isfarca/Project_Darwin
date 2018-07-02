#pragma once
#ifndef MenuTest_h
#define MenuTest_h

#include "cocos2d.h"


class MenuTest : cocos2d::Scene {
public:
	static cocos2d::Scene* createScene();
	cocos2d::Label* menuLabel;
	virtual bool init();
	cocos2d::MenuItemImage *startMenu;
	cocos2d::MenuItemImage *exitMenu;
	void changeScene(Ref *pSender);
	void exitGame(Ref *pSender);



	CREATE_FUNC(MenuTest);
};
#endif // !MenuTest_h
