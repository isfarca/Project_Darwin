#include "LevelTwo.h"

// Create the level two scene.
Scene* LevelTwo::createScene()
{
	return LevelTwo::create();
}

// Initializing.
bool LevelTwo::init()
{
	// When the scene doesn't init, then stop the init process.
	if (!Scene::init())
		return false;

	return true;
}

// Scene handlings
void LevelTwo::GoToLoseLoadScene(float delta)
{
	// Declare variables.
	Scene* scene = LoseLoad::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelTwo::GoToLevelSelectionScene(float delta)
{
	// Declare variables.
	Scene* scene = LevelSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}