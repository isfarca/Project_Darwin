#include "ChangeForm.h"

#define HAWK_MUTATION_SFX "sounds/forms/hawk.wav"
#define RHINO_MUTATION_SFX "sounds/forms/rhino.wav"	//change sound
#define ELEPHANT_MUTATION_SFX "sounds/forms/elephant.wav"
#define FISH_MUTATION_SFX "sounds/forms/fish.wav"
#define TURTLE_MUTATION_SFX "sounds/forms/turtle.wav"	//change sound

//variables
int smokeDuration;

//mutation 1
void ChangeForm::mutationHawk(Sprite* smoke)
{
	//smoke-sprite
	auto emitter = ParticleSmoke::create();

	smoke->addChild(emitter, 1);
	emitter->setPosition(70, 100);
	emitter->setScale(10);
	smokeDuration = 30;

	ChangeForm::SmokeTimer(smoke);

	//hawk-sound
	SimpleAudioEngine::getInstance()->playEffect(HAWK_MUTATION_SFX);
	//deactivate all other effects
	SpecialAbilities::ResetAllEffects();
	log("Hawk");
}

//mutation 2
void ChangeForm::mutationRhino(Sprite* smoke)
{
	//smoke-sprite
	auto emitter = ParticleSmoke::create();

	smoke->addChild(emitter, 1);
	emitter->setPosition(70, 100);
	emitter->setScale(10);
	smokeDuration = 30;


	//rhino-sound
	SimpleAudioEngine::getInstance()->playEffect(RHINO_MUTATION_SFX);
	//deactivate all other effects
	SpecialAbilities::ResetAllEffects();
	log("Rhino");
}

//mutation 3
void ChangeForm::mutationElephant(Sprite* smoke)
{
	//smoke-sprite
	auto emitter = ParticleSmoke::create();

	smoke->addChild(emitter, 1);
	emitter->setPosition(70, 100);
	emitter->setScale(10);
	smokeDuration = 30;


	//elephant-sound
	SimpleAudioEngine::getInstance()->playEffect(ELEPHANT_MUTATION_SFX);
	//deactivate all other effects
	SpecialAbilities::ResetAllEffects();
	log("Elephant");
}

//mutation 4
void ChangeForm::mutationFish(Sprite* smoke)
{
	//smoke-sprite
	auto emitter = ParticleSmoke::create();

	smoke->addChild(emitter, 1);
	emitter->setPosition(70, 100);
	emitter->setScale(10);
	smokeDuration = 30;


	//fish-sound
	SimpleAudioEngine::getInstance()->playEffect(FISH_MUTATION_SFX);
	//deactivate all other effects
	SpecialAbilities::ResetAllEffects();
	log("Fish");
}

//mutation 5
void ChangeForm::mutationTurtle(Sprite* smoke)
{
	//smoke-sprite
	auto emitter = ParticleSmoke::create();

	smoke->addChild(emitter, 1);
	emitter->setPosition(70, 100);
	emitter->setScale(10);
	smokeDuration = 30;


	//turtle-sound
	SimpleAudioEngine::getInstance()->playEffect(TURTLE_MUTATION_SFX);
	//deactivate all other effects
	SpecialAbilities::ResetAllEffects();
	log("Turtle");
}

void ChangeForm::SmokeTimer(Sprite* smoke)
{
	if (smokeDuration > 0)
		smokeDuration--;
	else
		smoke->removeAllChildren();
}