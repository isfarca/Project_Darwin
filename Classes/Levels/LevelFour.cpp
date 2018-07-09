#include "LevelFour.h"

// Create the level four scene.
Scene* LevelFour::createScene()
{
	return LevelTwo::create();
}

// Initializing.
bool LevelFour::init()
{
	// When the scene doesn't init, then stop the init process.
	if (!Scene::init())
		return false;

	return true;
}

// Scene handlings
void LevelFour::GoToLoseLoadScene(float delta)
{
	// Declare variables.
	Scene* scene = LoseLoad::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelFour::GoToLevelSelectionScene(float delta)
{
	// Declare variables.
	Scene* scene = LevelSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}