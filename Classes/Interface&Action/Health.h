#pragma once
#ifndef Health_h
#define Health_h
#include "cocos2d.h"
#include <string>;
using namespace cocos2d;
using namespace std;

class Health 
{
public:


	static void InitialHealth(Scene* scene);
	static void TakeDamage();
	static void GameOver();
	static void InvulnerableStart();
	static void InvulnerableEnd();

};

#endif