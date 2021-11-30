#include "Shop.h"
#include <map>
#include <string>
#include "Weapon.h"
#include "Character.h"
using namespace std;

Shop::Shop()
{
}

Shop::Shop(Character& player)
{
	mplayer = player;
	mInShop = true;
	
}

Shop::~Shop()
{
}

void Shop::Display()
{
	cout << "Here's my shop" << endl;
	string objectname;
	int price;
	int it = 0;
	for (it_inventory i = mInventory.begin(); i != mInventory.end(); i++)
	{
		cout << "Item Number : " << it << endl;
		cout << "\tName : " << i->first.GetName() << endl;
		cout << "\tQuantity : " << i->second << endl;
		cout << "\tPrice : " << i->first.GetPrice() << endl;
		cout << "============================================" << endl;
		it += 1;
	}
	cout << "Your Money : " << mplayer.GetMoney() << endl;
}

void Shop::AddItem(Item item, int quantity)
{
	if (mInventory.find(item) == mInventory.end()) {
		//Pas trouvé
		mInventory[item] = quantity;
	}
	else {
		//Augmenter l'item 
		mInventory[item] += quantity;
	}
}
void Shop::RemoveItem(Item item, int quantity)
{
	if (mInventory.find(item) == mInventory.end()) {

		cout << "Nothing like this here" << endl;
	}
	else {
		mInventory[item] -= quantity;
		if (quantity <= 0)
		{
			mInventory.erase(item);
		}
	}
}

std::map<Item, int> Shop::GetInventory()
{
	return mInventory;
}

void Shop::ShopLoop()
{
	cout << "Do you want to see what i'm selling ? yes or no" << endl;
	string Yesno;
	cin >> Yesno;
	if (Yesno == "no")
	{
		cout << "Okay I should not help you next time" << endl;
	}
	else
	{
		while (mInShop)
		{
			SelectItem();
		}
	}	
}

void Shop::SelectItem()
{
	Display();
	bool isChoosing = true;
	int it = 0;
	cout << "What will you take ? write the number of the item" << endl;
	while (isChoosing)
	{
		int selectedItem;
		cin >> selectedItem;
		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a number" << endl;
			continue;
		}
		else if (selectedItem >= mInventory.size())
		{
			cout << "Please enter a proper number" << endl;
		}
		else 
		{
			for (it_inventory i = mInventory.begin(); i != mInventory.end(); i++)
			{
				if (it == selectedItem) 
				{
					cout << " Name : " << i->first.GetName() << endl;
					HowMuch(i->first);
				}
				it += 1;
			}
			isChoosing = false;
			mInShop = false;
		}
	}
}

void Shop::HowMuch(Item item)
{
	cout << "How much do you want ?" << endl;
	while (true)
	{
		int howMuch;
		cin >> howMuch;
		if (cin.fail() == 1)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a number" << endl;
			continue;
		}
		else if (howMuch > mInventory[item])
		{
			cout << "I can't sell that much i don't have that many" << endl;
		}
		else
		{
			cout << "It'll cost you : " << item.GetPrice()*howMuch << endl;
			cout << "Are you okay with that ? yes or no" << endl;
			string Yesno;
			cin >> Yesno;
			if (Yesno == "yes")
			{
				RemoveItem(item, howMuch);
				break;
			}
			else
			{
				cout << "Okay, you can buy another thing if you want" << endl;
				SelectItem();
			}
		}
	}
}
