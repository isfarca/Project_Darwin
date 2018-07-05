#pragma once

#ifndef SpecialAbilities_h
#define SpecialAbilities_h

#include "cocos2d.h"
#include "../Levels/LevelOne.h"
#include "SpecialAbilities.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d;

class SpecialAbilities
{
public:
	static void Initiation();
	static void TimingHandler();
	static void Water(bool isInWater);

	static void RhinoAbility();
	static void TurtleAbility();
	static void HawkAbility();
	static void ElephantAbility();
	static void FishAbility();
};

#endif