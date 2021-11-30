#include "Item.h"
#include<iostream>
using namespace std;

Item::Item() {

}
Item::Item(string name, string desc, int price, float weight, bool stack, bool sell) {
	mName = name;
	mDescription = desc;
	mPrice = price;
	mWeight = weight;
	mStackable = stack;
	mSellable = sell;
}
Item::~Item() {}
string Item::GetName() const{
	return mName;
}
string Item::GetDescription() {
	return mDescription;
}
int Item::GetPrice()const {
	return mPrice;
}
float Item::GetWeight() {
	return mWeight;
}
void Item::DisplayItem() {
	cout << "Item : " << mName << " is " << mDescription << ". It costs " << mWeight << " and weights" << mWeight << '\n';
}

bool Item::operator==(Item a)
{
	return a.GetName() == mName;
}
bool Item::operator<(Item a)const
{
	return a.GetName() < mName;
}
