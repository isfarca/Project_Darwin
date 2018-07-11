#include "LevelSelection.h"
#define BUTTON_SFX "sounds/Button_Sound.wav"

// Create the prolog scene.
Scene* LevelSelection::createScene()
{
	return LevelSelection::create();
}

// Initializing.
bool LevelSelection::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// LEVEL PNG PATH
	string levelOnePng = "Menu/Level/levl1.png";
	string levelOnePngSelected = "Menu/Level/levl1pressed.png";
	string levelOnePngBlocked = "";

	string levelTwoPng = "Png/Level_2.png";
	string levelTwoPngSelected = "Png/Level_2Selected.png";
	string levelTwoPngBlocked = "Menu/Level/levl2.png";

	string levelThreePng = "Png/Level_3.png";
	string levelThreePngSelected = "Png/Level_3Selected.png";
	string levelThreePngBlocked = "Menu/Level/levl4.png";

	string levelFourPng = "Png/Level_4.png";
	string levelFourPngSelected = "Png/Level_4Selected.png";
	string levelFourPngBlocked = "Menu/Level/levl4.png";

	// MENU PNG PATH
	string goToMainMenuPng = "Icons/home.png";
	string goToMainMenuPngSelected = "Icons/home.png";

	// Level Sprite Png Reference
	/*
	string levelOneSpritePng = "";
	string levelTwoSpritePng = "";
	string levelThreeSpritePng = "";
	string levelFourSpritePng = "";




	LevelOneSprite = Sprite::create(levelOneSpritePng);
	LevelTwoSprite = Sprite::create(levelTwoSpritePng);
	LevelThreeSprite = Sprite::create(levelThreeSpritePng);
	LevelFourSprite = Sprite::create(levelFourSpritePng);
	
	LevelOneSprite->setScale(0.15f, 0.15f);
	LevelTwoSprite->setScale(0.15f, 0.15f);
	LevelThreeSprite->setScale(0.15f, 0.15f);
	LevelFourSprite->setScale(0.15f, 0.15f);

	LevelOneSprite->setPosition(Vec2(visibleSize.width / 2, 1200));
	LevelTwoSprite->setPosition(Vec2(visibleSize.width / 2, 1200));
	LevelThreeSprite->setPosition(Vec2(visibleSize.width / 2, 1200));
	LevelFourSprite->setPosition(Vec2(visibleSize.width / 2, 1200));

	*/

	//string goToGeneSelectionPng = "Png/continue.png"; **********DELETED
	//string goToGeneSelectionPngSelected = "Png/continue.png"; **********DELETED

	// Buttons
	levelOneButton = MenuItemImage::create(levelOnePng, levelOnePngSelected, levelOnePngBlocked, CC_CALLBACK_1(LevelSelection::StartLevelOne, this));
	levelTwoButton = MenuItemImage::create(levelTwoPng, levelTwoPngSelected, levelTwoPngBlocked, CC_CALLBACK_1(LevelSelection::StartLevelTwo, this));
	levelThreeButton = MenuItemImage::create(levelThreePng, levelThreePngSelected, levelThreePngBlocked, CC_CALLBACK_1(LevelSelection::StartLevelThree, this));
	levelFourButton = MenuItemImage::create(levelFourPng, levelFourPngSelected, levelFourPngBlocked, CC_CALLBACK_1(LevelSelection::StartLevelFour, this));

	goToMainMenuButton = MenuItemImage::create(goToMainMenuPng, goToMainMenuPngSelected, CC_CALLBACK_1(LevelSelection::GoToMainMenuScene, this));
	
	//goToGeneSelectionButton = MenuItemImage::create(goToGeneSelectionPng, goToGeneSelectionPngSelected, CC_CALLBACK_1(LevelSelection::GoToGeneSelectionScene, this)); **********DELETED
	
	
	levelOneButton->setScale(0.77f, 0.77f);
	levelTwoButton->setScale(0.77f, 0.77f);
	levelThreeButton->setScale(0.77f, 0.77f);
	levelFourButton->setScale(0.77f, 0.77f);
	
	goToMainMenuButton->setScale(0.15f, 0.15f);

	auto menu = Menu::create(levelOneButton, levelTwoButton, levelThreeButton, levelFourButton, goToMainMenuButton,/* goToGeneSelectionButton**********DELETED,*/ nullptr);

	menu->setPosition(Point::ZERO);


	// level selection scale button


	//Level Selection Position
	levelOneButton->setPosition(Vec2(visibleSize.width / 2 + 123, 1070));
	levelTwoButton->setPosition(Vec2(visibleSize.width / 2, 800));
	levelThreeButton->setPosition(Vec2(visibleSize.width / 2, 600));
	levelFourButton->setPosition(Vec2(visibleSize.width / 2, 400));

	goToMainMenuButton->setPosition(Vec2(visibleSize.width / 2 + 800, 1200));
	//goToGeneSelectionButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 450); **********DELETED

	levelTwoButton->setEnabled(false);
	levelThreeButton->setEnabled(false);
	levelFourButton->setEnabled(false);

	this->addChild(menu);

	return true;
}

// Scene handlings
void LevelSelection::GoToMainMenuScene(Ref* pSender)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


void LevelSelection::GoToGeneSelectionScene(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);

	// Declare variables.
	Scene* scene = GeneSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

// Set level id.
void LevelSelection::StartLevelOne(Ref* pSender)
{
	Scene* scene = GeneSelection::createScene();
	LevelManager::SetLevelId(1);
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelSelection::StartLevelTwo(Ref* pSender)
{
	Scene* scene = GeneSelection::createScene();
	LevelManager::SetLevelId(2);
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}
void LevelSelection::StartLevelThree(Ref* pSender)
{
	Scene* scene = GeneSelection::createScene();
	LevelManager::SetLevelId(3);
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelSelection::StartLevelFour(Ref* pSender)
{
	Scene* scene = GeneSelection::createScene();
	LevelManager::SetLevelId(4);
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}