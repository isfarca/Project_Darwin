#include "SpecialAbilities.h"

#define FLY_SFX "Bruellen.wav"
#define CHARGE_SFX "Bruellen.wav"
#define TRAMPLE_SFX "Bruellen.wav"
#define SWIM_SFX "Bruellen.wav"
#define HOLE_UP_SFX "Bruellen.wav"

// Declare variables.
int turtleCooldown, turtleDuration, hawkCooldown, hawkDuration, rhinoCooldown, rhinoDuration, elephantCooldown, elephantDuration;

bool turtleActive, hawkActive, fishActive, rhinoActive, elephantActive;
bool playerIsInWater;

void SpecialAbilities::Initiation()
{
	//various
	playerIsInWater = false;

	//turtle
	turtleCooldown = 0;
	turtleDuration = 0;
	turtleActive = false;

	//hawk
	hawkCooldown = 0;
	hawkDuration = 0;
	hawkActive = 0;

	//Fish
	fishActive = 0;
}

//ability 1
void SpecialAbilities::HawkAbility()
{
	if (hawkCooldown <= 0)
	{
		//equals 5 seconds
		hawkDuration = 300;
		//equals 15 seconds
		hawkCooldown = 900;
		hawkActive = true;
		//call function to set new values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY) 
		LevelOne::JumpValues(true, 1.5, 200, 0, 2.0, -200, 0);
		//play sound and debug
		SimpleAudioEngine::getInstance()->playEffect(FLY_SFX);
		log("fly");
	}
}

//ability 2
void SpecialAbilities::RhinoAbility()
{
	if (rhinoCooldown <= 0)
	{
		//equals 3 seconds
		rhinoDuration = 180;
		//equals 9 seconds
		rhinoCooldown = 540;
		rhinoActive = true;
		//call other script to start charging
		LevelOne::ChargeMode(true, 1.4f);
		//play sound and debug
		SimpleAudioEngine::getInstance()->playEffect(CHARGE_SFX);
		log("charge");
	}
}

//ability 3
void SpecialAbilities::ElephantAbility()
{
	if (elephantCooldown <= 0)
	{
		//equals 3 seconds
		elephantDuration = 180;
		//equals 9 seconds
		elephantCooldown = 540;
		elephantActive = true;
		//call other script to start charging
		LevelOne::TrampleMode(true, 1.2f);
		//play sound and debug
		SimpleAudioEngine::getInstance()->playEffect(CHARGE_SFX);
		log("charge");
	}
	//play sound and debug
	SimpleAudioEngine::getInstance()->playEffect(TRAMPLE_SFX);
	log("stomp");
}

//ability 4
void SpecialAbilities::FishAbility()
{
	//check global bool and if ability is inactive
	if (playerIsInWater && fishActive == false)
	{
		fishActive = true;
		//call function to set new values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY) 
		LevelOne::JumpValues(true, 1.5f, 200, 0, 2.0, -200, 0);
	}
	//deactivate if already active
	else if (playerIsInWater && fishActive == true)
	{
		fishActive = false;
		//call function to restore default values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY
		LevelOne::JumpValues(false, 1.0f, 0, 300, 1.0, -200, 0);
	}
	//play sound and debug
	SimpleAudioEngine::getInstance()->playEffect(SWIM_SFX);
	log("swim");
}

//ability 5
void SpecialAbilities::TurtleAbility()
{
	if (turtleCooldown <= 0)
	{
		//equals 4 seconds
		turtleDuration = 240;
		//equels 12 seconds
		turtleCooldown = 720;
		turtleActive = true;
		Health::InvulnerableStart();
		//play sound and debug
		SimpleAudioEngine::getInstance()->playEffect(HOLE_UP_SFX);
		log("hole up");
	}
}

//to manage cooldowns and durations
void SpecialAbilities::TimingHandler()
{
	//cooldowns
	if (turtleCooldown > 0)
	{
		turtleCooldown--;
	}
	if (hawkCooldown > 0)
	{
		hawkCooldown--;
	}
	if (rhinoCooldown > 0)
	{
		rhinoCooldown--;
	}
	if (elephantCooldown > 0)
	{
		elephantCooldown--;
	}

	//durations
	//turtle
	if (turtleDuration > 0)
	{
		turtleDuration--;
	}
	else if (turtleActive == true)
	{
		turtleActive = false;
		Health::InvulnerableEnd();
		log("return to normal health");
	}
	//hawk
	if (hawkDuration > 0)
	{
		hawkDuration--;
	}
	else if (hawkActive == true)
	{
		hawkActive = false;
		//call function to restore default values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY)  
		//extrema: Größe des Bogens
		//offset: Höhenunterschied am Ende 
		LevelOne::JumpValues(false, 1.0f, 0, 300, 1.0, -200, 0);
	}

	//rhino
	if (rhinoDuration > 0)
	{
		rhinoDuration--;
	}
	else if (rhinoActive == true)
	{
		rhinoActive = false;
		LevelOne::ChargeMode(false, 1.0f);
	}

	//elephant
	if (elephantDuration > 0)
	{
		elephantDuration--;
	}
	else if (elephantActive == true)
	{
		elephantActive = false;
		LevelOne::TrampleMode(false, 1.0f);
	}

	//fish
	if (!playerIsInWater && fishActive == true)
	{
		fishActive = false;
		//call function to restore default values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY
		LevelOne::JumpValues(false, 1.0f, 0, 300, 1.0, -200, 0);
	}
}

void SpecialAbilities::Water(bool isInWater)
{
	playerIsInWater = isInWater;
}