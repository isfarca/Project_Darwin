#pragma once
#ifndef SpecialAbilities_h
#define SpecialAbilities_h

#include "cocos2d.h"
#include "IngameButtons.h"
using namespace cocos2d;

class SpecialAbilities
{
public:

	static void Initiation();
	static void TimingHandler();

	static void RhinoAbility();
	static void TurtleAbility();
	static void HawkAbility();
	static void ElephantAbility();
	static void FishAbility();

};

#endif
