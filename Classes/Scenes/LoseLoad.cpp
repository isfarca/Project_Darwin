#include "LoseLoad.h"

// Create the lose load scene.
Scene* LoseLoad::createScene()
{
	return LoseLoad::create();
}

// Initializing.
bool LoseLoad::init()
{
	// When the scene doesn't init, then stop the init process.
	if (!Scene::init())
		return false;

	// Initialize variables for random darwin info sentence.
	sentence[0] = 'A';
	sentence[1] = 'B';
	sentence[2] = 'C';
	sentence[3] = 'D';

	sentenceLength = sizeof(sentence) / sizeof(sentence[0]);
	randomIndex = RandomHelper::random_int(0, (int)(sentenceLength - 1));

	// Start the loading process.
	this->schedule(schedule_selector(LoseLoad::UpdateProgress), DISPLAY_TIME_NEXT_SCENE);

	return true;
}

// Calling per frame for loading.
void LoseLoad::UpdateProgress(float delta)
{
	// Increment the loading counter.
	counter++;

	// Get size informations.
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	// Clear the window.
	this->removeAllChildren();

	// When the counter under hundred, than the scene is loading, else scene is loaded and wait for a tap.
	if (counter <= 99)
	{
		// Set the label texts.
		labelLoadingProcess = Label::createWithTTF("You lost...", "fonts/Marker Felt.ttf", 60);
		this->addChild(labelLoadingProcess, 0);

		currentSentence = __String::createWithFormat("%c", sentence[randomIndex]);
		darwinInfoLabel = Label::createWithTTF(currentSentence->getCString(), "fonts/Marker Felt.ttf", 60);
		this->addChild(darwinInfoLabel, 0);
	}
	else if (counter >= 100)
	{
		// Set counter of hundred for memory release.
		counter = 100;

		// Set the label texts.
		labelLoadingProcess = Label::createWithTTF("Tap to continue", "fonts/Marker Felt.ttf", 60);
		this->addChild(labelLoadingProcess, 0);

		currentSentence = __String::createWithFormat("%c", sentence[randomIndex]);
		darwinInfoLabel = Label::createWithTTF(currentSentence->getCString(), "fonts/Marker Felt.ttf", 60);
		this->addChild(darwinInfoLabel, 0);

		// Touch event for began.
		eventListenerTouchOneByOne = EventListenerTouchOneByOne::create();
		eventListenerTouchOneByOne->onTouchBegan = CC_CALLBACK_2(LoseLoad::onTouchBegan, this);
		this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListenerTouchOneByOne, this);
	}

	// Set label settings.
	labelLoadingProcess->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - ((visibleSize.height / 2) / 2)));
	labelLoadingProcess->setTextColor(Color4B(255, 255, 255, 255));

	darwinInfoLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.3f));
	darwinInfoLabel->setTextColor(Color4B(255, 255, 255, 255));
}

// Touch event: 'Began'.
bool LoseLoad::onTouchBegan(Touch* touch, Event* event)
{
	// Go to next scene and disable the loading progress.
	this->scheduleOnce(schedule_selector(LoseLoad::GoToLevelManagerScene), DISPLAY_TIME_NEXT_SCENE);
	unschedule(schedule_selector(LoseLoad::UpdateProgress));

	return true;
}

// Scene handlings.
void LoseLoad::GoToLevelManagerScene(float delta)
{
	// Declare variables.
	Scene* scene = LevelManager::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(scene);
}