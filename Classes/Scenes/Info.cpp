#include "Info.h"

// Create the info scene.
Scene* Info::createScene()
{
	return Info::create();
}

// Initializing.
bool Info::init()
{
	// When the scene doesn't init, then stop the init process.
	if (!Scene::init())
		return false;

	/////ADDED
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	string mainMenuButtonPng = "MainMenu.png";
	string mainMenuButtonPngSelected = "MainMenuSelected.png";

	string goToCreditsPng = "exit.png";
	string goToCreditsPngSelected = "exitSelected.png";

	mainMenuButton = MenuItemImage::create(mainMenuButtonPng, mainMenuButtonPngSelected, CC_CALLBACK_1(Info::returnToMainMenu, this));
	creditsButton = MenuItemImage::create(goToCreditsPng, goToCreditsPngSelected, CC_CALLBACK_1(Info::goToCredits, this));

	// auto menu = Settings::create(returnToMainMenuButton, nullptr);
	//menu->setPosition(Point::ZERO);

	auto menu = Menu::create(mainMenuButton, creditsButton, nullptr);
	menu->setPosition(Point::ZERO);

	mainMenuButton->setPosition(Vec2(visibleSize.width / 2 + 800, 1200));
	creditsButton->setPosition(Vec2(visibleSize.width / 2, 300));
	this->addChild(menu);

	/////ADDED END


	return true;
}

// Scene handlings
void Info::GoToCreditsScene(float delta)
{
	// Declare variables.
	Scene* scene = Credits::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void Info::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

///// ADDED
void Info::returnToMainMenu(Ref* pSender)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void Info::goToCredits(Ref* pSender)
{
	// Declare variables.
	Scene* scene = Credits::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
///// ADDED END