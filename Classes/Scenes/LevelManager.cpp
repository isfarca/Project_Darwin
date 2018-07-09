#include "LevelManager.h"

// Declare variables.
int levelId;

// Create the level manager scene.
Scene* LevelManager::createScene()
{
	return LevelManager::create();
}

// Initializing.
bool LevelManager::init()
{
	// When the scene doesn't init, then stop the init process.
	if (!Scene::init())
		return false;

	// Default value.
	LevelManager::SetLevelId(1);

	// Call the current level from id.
	switch (LevelManager::GetLevelId())
	{
	case 1:
		// Go to next scene and disable the loading progress.
		this->scheduleOnce(schedule_selector(LevelManager::GoToLevelOne), DISPLAY_TIME_NEXT_SCENE);
		break;
	case 2:
		// Go to next scene and disable the loading progress.
		this->scheduleOnce(schedule_selector(LevelManager::GoToLevelTwo), DISPLAY_TIME_NEXT_SCENE);
		break;
	case 3:
		// Go to next scene and disable the loading progress.
		this->scheduleOnce(schedule_selector(LevelManager::GoToLevelThree), DISPLAY_TIME_NEXT_SCENE);
		break;
	case 4:
		// Go to next scene and disable the loading progress.
		this->scheduleOnce(schedule_selector(LevelManager::GoToLevelFour), DISPLAY_TIME_NEXT_SCENE);
		break;
	}

	return true;
}

// Property for loading the current level.
int LevelManager::GetLevelId()
{
	return levelId;
}
void LevelManager::SetLevelId(int value)
{
	levelId = value;
}

// Scene handlings
void LevelManager::GoToLevelOne(float delta)
{
	// Declare variables.
	Scene* scene = LevelOne::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelManager::GoToLevelTwo(float delta)
{
	// Declare variables.
	Scene* scene = LevelTwo::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelManager::GoToLevelThree(float delta)
{
	// Declare variables.
	Scene* scene = LevelThree::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelManager::GoToLevelFour(float delta)
{
	// Declare variables.
	Scene* scene = LevelFour::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}