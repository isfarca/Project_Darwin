#include "GeneSelection.h"

// Create the prolog scene.
Scene* GeneSelection::createScene()
{
	return GeneSelection::create();
}

// Initializing.
bool GeneSelection::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	mutationOnePng = "Png/Mutation/mutation1.png";
	mutationOnePngSelected = "Png/Mutation/mutation1Selected.png";

	mutationTwoPng = "Png/Mutation/mutation2.png";
	mutationTwoPngSelected = "Png/Mutation/mutation2Selected.png";

	mutationThreePng = "Png/Mutation/mutation3.png";
	mutationThreePngSelected = "Png/Mutation/mutation3Selected.png";

	mutationFourPng = "Png/Mutation/mutation4.png";
	mutationFourPngSelected = "Png/Mutation/mutation4Selected.png";

	mutationFivePng = "Png/Mutation/mutation5.png";
	mutationFivePngSelected = "Png/Mutation/mutation5Selected.png";

	reset = "Png/Mutation/reset.png";
	resetSelected = "Png/Mutation/resetSelected";

	chosenMutationPngFirst = "Png/nothingSelected.png";
	chosenMutationPngSecond = "Png/nothingSelected.png";
	chosenMutationPngThird = "Png/nothingSelected.png";

	firstGeneSprite = Sprite::create(chosenMutationPngFirst);
	secondGeneSprite = Sprite::create(chosenMutationPngSecond);
	thirdGeneSprite = Sprite::create(chosenMutationPngThird);

	mutationOneBtn = MenuItemImage::create(mutationOnePng, mutationOnePngSelected, CC_CALLBACK_1(GeneSelection::mutationOne, this));
	mutationTwoBtn = MenuItemImage::create(mutationTwoPng, mutationTwoPngSelected, CC_CALLBACK_1(GeneSelection::mutationTwo, this));
	mutationThreeBtn = MenuItemImage::create(mutationThreePng, mutationThreePngSelected, CC_CALLBACK_1(GeneSelection::mutationThree, this));
	mutationFourBtn = MenuItemImage::create(mutationFourPng, mutationFourPngSelected, CC_CALLBACK_1(GeneSelection::mutationFour, this));
	mutationFiveBtn = MenuItemImage::create(mutationFivePng, mutationFivePngSelected, CC_CALLBACK_1(GeneSelection::mutationFive, this));

	resetSelectedMutationBtn = MenuItemImage::create(reset, resetSelected, CC_CALLBACK_1(GeneSelection::ResetSelectedMutation, this));

	auto menu = Menu::create(mutationOneBtn, mutationTwoBtn, mutationThreeBtn, mutationFourBtn, mutationFiveBtn, resetSelectedMutationBtn, nullptr);
	menu->setPosition(Point::ZERO);

	mutationOneBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	mutationTwoBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 50);
	mutationThreeBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 100);
	mutationFourBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 150);
	mutationFiveBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 200);

	firstGeneSprite->setPosition(visibleSize.width / 2 + 200, visibleSize.height / 2 + 50);
	secondGeneSprite->setPosition(visibleSize.width / 2 + 200, visibleSize.height / 2 + 150);
	thirdGeneSprite->setPosition(visibleSize.width / 2 + 200, visibleSize.height / 2 + 200);

	this->addChild(firstGeneSprite);
	this->addChild(secondGeneSprite);
	this->addChild(thirdGeneSprite);

	resetSelectedMutationBtn->setPosition(visibleSize.width / 2 + 250, visibleSize.height / 2 - 200);
	this->addChild(menu);

	this->scheduleUpdate();

	return true;
}

void GeneSelection::update(float delta)
{
	firstGeneSprite = Sprite::create(chosenMutationPngFirst);
	secondGeneSprite = Sprite::create(chosenMutationPngSecond);
	thirdGeneSprite = Sprite::create(chosenMutationPngThird);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	firstGeneSprite->setPosition(visibleSize.width / 2 + 200, visibleSize.height / 2 + 50);
	secondGeneSprite->setPosition(visibleSize.width / 2 + 200, visibleSize.height / 2 + 150);
	thirdGeneSprite->setPosition(visibleSize.width / 2 + 200, visibleSize.height / 2 + 200);

	this->addChild(firstGeneSprite);
	this->addChild(secondGeneSprite);
	this->addChild(thirdGeneSprite);

}

// Scene handlings
void GeneSelection::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void GeneSelection::GoToLoadScene(float delta)
{
	// Declare variables.
	Scene* scene = Load::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

// Mutation handlings.
void GeneSelection::mutationOne(Ref* pSender) 
{
	GeneSelection::mutationOneInt = 1;
	ChosenMutation(1, mutationOnePng, mutationOnePng);
	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
}

void GeneSelection::mutationTwo(Ref* pSender) 
{
	GeneSelection::mutationTwoInt = 2;
	ChosenMutation(2, mutationTwoPng, mutationTwoPng);
	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
}

void GeneSelection::mutationThree(Ref* pSender) 
{
	GeneSelection::mutationThreeInt = 3;
	ChosenMutation(3, mutationThreePng, mutationThreePng);
	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
}

void GeneSelection::mutationFour(Ref* pSender) 
{
	GeneSelection::mutationFourInt = 4;
	ChosenMutation(4, mutationFourPng, mutationFourPng);
	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
}

void GeneSelection::mutationFive(Ref* pSender) 
{
	GeneSelection::mutationFiveInt = 5;

	ChosenMutation(5, mutationFivePng, mutationFivePng);

	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
}

void GeneSelection::ResetSelectedMutation(Ref* pSender)
{
	specialOne = 0;
	specialTwo = 0;
	specialThree = 0;
	chosenMutationPngFirst = "Png/nothingSelected.png";
	chosenMutationPngSecond = "Png/nothingSelected.png";
	chosenMutationPngThird = "Png/nothingSelected.png";

	specialOnePng = "Png/nothingSelected.png";
	specialTwoPng = "Png/nothingSelected.png";
	specialThreePng = "Png/nothingSelected.png";
}

void GeneSelection::ChosenMutation(int mutationKind, string mutationPng, string specialPngSelected) 
{
	if (specialOne == 0)
	{
		// erster mutations slot
		specialOne = mutationKind;
		chosenMutationPngFirst = mutationPng;
		specialOnePng = specialPngSelected;
	}
	else if (specialTwo == 0)
	{
		// zweiter mutationsslot
		specialTwo = mutationKind;
		chosenMutationPngSecond = mutationPng;
		specialTwoPng = specialPngSelected;
	}
	else if (specialThree == 0)
	{
		// dritter mutationsslot
		specialThree = mutationKind;
		chosenMutationPngThird = mutationPng;
		specialThreePng = specialPngSelected;
	}
	else 
	{
		return;
	}
}