#pragma once
#include <iostream>
#include "Character.h"
class Shop
{
private:

	std::vector<Item> mItems;
	std::map<Item, int>	mInventory;
	typedef std::map<Item, int>::iterator it_inventory;
	Character mplayer;
	bool mInShop;

public:
	Shop();
	Shop(Character& player);
	~Shop();
	void Display();
	void AddItem(Item item, int quantity);
	void RemoveItem(Item item, int quantity);
	std::map<Item, int> GetInventory();
	void ShopLoop();
	void SelectItem();
	void HowMuch(Item item);


};
