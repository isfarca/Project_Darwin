#include "LevelThree.h"

// Create the level three scene.
Scene* LevelThree::createScene()
{
	return LevelTwo::create();
}

// Initializing.
bool LevelThree::init()
{
	// When the scene doesn't init, then stop the init process.
	if (!Scene::init())
		return false;

	return true;
}

// Scene handlings
void LevelThree::GoToLoseLoadScene(float delta)
{
	// Declare variables.
	Scene* scene = LoseLoad::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelThree::GoToLevelSelectionScene(float delta)
{
	// Declare variables.
	Scene* scene = LevelSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}