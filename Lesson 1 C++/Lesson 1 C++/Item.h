#pragma once
#include <iostream>
class Item
{

	private:
		std::string mName;
		std::string mDescription;
		int mPrice;
		float mWeight;
		bool mStackable;
		bool mSellable;

	public:
		Item();
		Item(std::string name, std::string desc, int price = 0, float weight = 0, bool stack = true, bool sell = true);
		~Item();
		std::string GetName()const;
		std::string GetDescription();
		int GetPrice()const;
		float GetWeight();
		void DisplayItem();
		bool operator==(Item a);
		bool operator<(Item a)const;

};

