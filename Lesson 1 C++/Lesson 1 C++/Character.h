#pragma once
#include <string>
#include <vector>
#include <map>
#include "Item.h"
#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character

{
private :
	string mName;
	int mMaxLife;
	int mStrenght;
	int mDex;
	int mConstitution;
	int mIntelligence;
	int mWisdom;
	int mCharisma;
	int mLifePoints;
	int mMoney;

	std::vector<Item> mItems;
	std::map<Item, int>	mInventory;
	typedef std::map<Item, int>::iterator it_inventory;

public:
	Character();
	Character(string name,int maxlife, int f, int d, int c, int i, int w, int ch, int money);
	~Character();
	string GetName();
	int GetStrenght();
	int GetDex();
	int GetConstitution();
	int GetIntelligence();
	int GetWisdom();
	int GetCharisma();
	int GetLifePoints();
	int GetMoney();

	void SetForce(int value);
	void SetDex(int value);
	void SetConstitution(int value);
	void SetIntelligence(int value);
	void SetWisdom(int value);
	void SetCharisma(int value);
	void SetMoney(int value);
	void Heal(int points);
	void Hurt(int points);
	void AddItem(Item item, int quantity);
	void BuyItem(Item item, int quantity, int price);


	void DisplaySumUp();
	void DisplayLife();

};
#endif
