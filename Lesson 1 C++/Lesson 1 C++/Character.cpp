#include <iostream>
#include "Character.h"
using namespace std;

Character::Character()
{
}

Character::Character(string name, int maxlife, int f, int d, int c, int i, int w, int ch, int money)
{
	mName = name;
	mMaxLife = maxlife;
	mStrenght = f;
	mDex = d;
	mConstitution = c;
	mIntelligence = i;
	mWisdom = w;
	mCharisma = ch;
	mLifePoints = maxlife;
	mMoney = money;
}
Character::~Character() {}

string Character::GetName() {
	return mName;
}
int Character::GetStrenght() {
	return mStrenght;
}
int Character::GetDex() {
	return mDex;
}
int Character::GetConstitution() {
	return mConstitution;
}
int Character::GetIntelligence() {
	return mIntelligence;
}
int Character::GetWisdom() {
	return mWisdom;
}
int Character::GetCharisma() {
	return mCharisma;
}
int Character::GetLifePoints() {
	return mLifePoints;
}

int Character::GetMoney()
{
	return mMoney;
}

void Character::SetForce(int value) { mStrenght = value; }
void Character::SetDex(int value) { mDex = value; }
void Character::SetConstitution(int value) { mConstitution = value; }
void Character::SetIntelligence(int value) { mIntelligence = value; }
void Character::SetWisdom(int value) { mWisdom = value; }
void Character::SetCharisma(int value) { mCharisma = value; }
void Character::SetMoney(int value) { mMoney = value; }
void Character::Heal(int points) {
	mLifePoints = ((mLifePoints + points) >= mMaxLife) ? mMaxLife : (mLifePoints + points);
}
void Character::Hurt(int points) { mLifePoints -= points; }

void Character::AddItem(Item item, int quantity)
{
	if (mInventory.find(item) == mInventory.end()) {
		//Pas trouvé
		mInventory[item] = quantity;
	}
	else {
		//Augmenter l'item 
		mInventory[item] += quantity;
	}

	//for (it_inventory iterator = mInventory.begin(); iterator != mInventory.end(); iterator++) 
	//{
	//	Item i = iterator->first;
	//	cout << i.GetName() << " / " << item.GetName();
	//	//if (i == item)
	//	/*if (i.GetName() == item.GetName())
	//	{
	//		iterator->second += quantity;
	//	}
	//	else
	//	{
	//		mInventory[item] = quantity;
	//	}*/
	//}
	//

}

void Character::BuyItem(Item item, int quantity, int price)
{
	if (mMoney >= price) {

		AddItem(item, quantity);
		mMoney -= price;
	}
}

void Character::DisplaySumUp() 
{
	cout << mName << "has the following characteristics:\n";
	cout << "Force : " << mStrenght << '\n';
	cout << "Dexterity : " << mDex << '\n';
	cout << "Constitution : " << mConstitution << '\n';
	cout << "Int : " << mIntelligence << '\n';
	cout << "Wisdom : " << mWisdom << '\n';
	cout << "Charisma : " << mCharisma << '\n';
}
