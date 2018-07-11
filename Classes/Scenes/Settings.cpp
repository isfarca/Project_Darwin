#include "Settings.h"

// Create the settings scene.
Scene* Settings::createScene()
{
	return Settings::create();
}

// Initializing.
bool Settings::init()
{
	if (!Scene::init())
		return false;

	/////ADDED
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	string mainMenuButtonPng = "Icons/home.png";
	string mainMenuButtonPngSelected = "MainMenuSelected.png";

	string goToHelpButtonPng = "Menu/help.png";
	string goToHelpButtonPngSelected = "exitSelected.png" ;

	mainMenuButton = MenuItemImage::create(mainMenuButtonPng, mainMenuButtonPngSelected, CC_CALLBACK_1(Settings::returnToMainMenu, this));
	goToHelpButton = MenuItemImage::create(goToHelpButtonPng, goToHelpButtonPngSelected, CC_CALLBACK_1(Settings::goToHelp, this));


	goToHelpButton->setScale(0.15f, 0.15f);
	mainMenuButton->setScale(0.15f, 0.15f);
	// auto menu = Settings::create(returnToMainMenuButton, nullptr);
	//menu->setPosition(Point::ZERO);

	auto menu = Menu::create(mainMenuButton, goToHelpButton, nullptr);
	menu->setPosition(Point::ZERO);

	mainMenuButton->setPosition(Vec2(visibleSize.width / 2 + 800, 1200));
	goToHelpButton->setPosition(Vec2(visibleSize.width / 2, 300));
	this->addChild(menu);

	/////ADDED END

	// When the scene doesn't init, then stop the init process.

	return true;
}

// Scene handlings.
void Settings::GoToHelpScene(float delta)
{
	// Declare variables.
	Scene* scene = Help::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void Settings::GoToPrologScene(float delta)
{
	// Declare variables.
	Scene* scene = Prolog::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void Settings::returnToMainMenuScene(Ref* pSender)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


///// ADDED
void Settings::returnToMainMenu(Ref* pSender)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void Settings::goToHelp(Ref* pSender)
{
	Scene* scene = Help::create();

	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

///// ADDED END