// Lesson 1 C++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Weapon.h"
#include "Character.h"
#include "Shop.h"
using namespace std;

int main()
{
    int force = 0, dexterity = 0, constitution = 0, intelligence = 0, wisdom = 0, charisma = 0;

    cout << "What's your name traveller ?" << endl;
    string playerName;
    // store the user input in the variable playerName
    cin >> playerName;

    cout << playerName << " , I didn't want to talk to you but it's an obligation since i'm a predifined sentence, so Welcome in our world.... Arf i hate my job " << endl;
    cout << "I still don't care but what's your age ?" << endl;
    int age;
    cin >> age;
    int totalpoint = 20;
    int points;
    int response = 0;
    string Yesno;
    string weapontype;
    int Shopmerch;
    int howmuch;
    Character player(playerName, 20, 5, 5, 5, 5, 5, 5, 100);
    Shop merchant(player);

    typedef std::map<Item, int>::iterator it_inventory;

    if (age < 18)
    {
        cout << playerName << ", Aren't you a little young for the game ? after all who am i to ask you that i'm not your father" << endl;
    }

    else
    {
        cout << "Ok, " << playerName << " you chose to buy this game so i'll let you start your adventure, i think you made an error but do what you want" << endl;
    }
    cout << playerName << "You'll put a certain number of point in 6 category, you have 20 points to put in the 6 category" << endl;
    do
    {
        if (totalpoint > 0)
        {
            cout << "How much do you put in strenght ?" << endl;
            cin >> points;
            force += points;
            totalpoint -= points;
        }
        if (totalpoint > 0)
        {
            cout << "How much do you put in dexterity ?" << endl;
            cin >> points;
            dexterity += points;
            totalpoint -= points;
        }
        if (totalpoint > 0)
        {
            cout << "How much do you put in constitution" << endl;
            cin >> points;
            constitution += points;
            totalpoint -= points;
        }
        if (totalpoint > 0)
        {
            cout << "How much do you put in intelligence" << endl;
            cin >> points;
            intelligence += points;
            totalpoint -= points;
        }
        if (totalpoint > 0)
        {
            cout << "How much do you put in wisdom" << endl;
            cin >> points;
            wisdom += points;
            totalpoint -= points;
        }
        if (totalpoint > 0)
        {
            cout << "How much do you put in charisma" << endl;
            cin >> points;
            charisma += points;
            totalpoint -= points;
        }

        cout << "That's your statistics, Strenght: " << force << " Dexterity: " << dexterity << " intelligence: " << intelligence << " constitution: " << constitution << " wisdom: " << wisdom << " charisma: " << charisma << endl;

        cout << "Do you want to keep these statistics ? 1 for yes or 2 for No" << endl;
        cin >> response;
        if (response == 1)
        {
            cout << "Ok here's your class:" << endl;
        }
        if (response == 2)
        {
            cout << "You should've chose better don't make me lose my time" << endl;
            force = 0;
            dexterity = 0;
            intelligence = 0;
            constitution = 0;
            wisdom = 0;
            charisma = 0;
            totalpoint = 20;
        }
    } while (response != 1);

    if (force + dexterity > 11)
    {
        cout << "You are a warrior" << endl;
        Weapon GreatSword = Weapon("Great Sword", "Basically a Great Sword", WeaponType::Sword, 4, 8);
        Weapon GreatAxe = Weapon("Great Axe", "Basically a Great Axe", WeaponType::Axe, 3.5, 9);
        cout << "You can choose your weapon" << endl;
        cout << "Do you want the axe or the sword ?" << endl;
        cin >> weapontype;
        if (weapontype == "axe") {
            cout << "Take your axe..., You got a Great Axe" << endl;
            player.AddItem(GreatAxe, 1);
        }
        else if (weapontype == "sword") {
            cout << "Take your sword, You got a Great Sword" << endl;
            player.AddItem(GreatSword, 1);
        }
        else {
            cout << "Make That again and i throw you in the world without any weapon" << endl;
        }

    }
    else if (intelligence + wisdom > 14)
    {
        cout << "You are a mage" << endl;
        Weapon magicstaff = Weapon("Magic Staff", "It's like a boomrang but if you throw it it wont comeback",WeaponType::Staff, 12, 6);
        cout << "You'll take this staff don't cry for better there's nothing better" << endl;
        player.AddItem(magicstaff, 1);
        

    }
    else if (wisdom + charisma + intelligence == 20)
    {
        cout << "You'll be a merchant" << endl;
        cout << "You'll get 500 gold coins and a pass of trader that allows you and you're group to pass throught the town without paying anything. " << endl;
    }
    else
    {
        cout << "You're a type of person that prefer to be good in all kind of stuff, The kind of person that i don't like, Good Luck... You have no class" << endl;
        cout << "I've got pity for you, don't say to anyone that i did what i'm going to do, " << endl;
        Weapon littleSword = Weapon("Little Sword", "A little Sword for a person with no future", WeaponType::Sword, 2, 4);
        cout << "Take this weapon and good luck, You Get a littleSword" << endl;
        player.AddItem(littleSword, 1);
    }
    
    cout << "You're gonna start your journey in this new world, as a start you'll have to talk to the shop owner and then kill a chicken to get food." << endl;
    cout << "Don't comeback too early, i want some time for me, i want to watch some anime" << endl;
    cout << "==========================================================================" << endl;
    cout << "You're starting to wake up in front of a big city..." << endl;
    cout << "You hear a voice next to you : Are you Okay ?" << endl;
    cout << "yes or no ?" << endl;
    cin >> Yesno;
    if (Yesno == "yes")
    {
        cout << "Get up if you're okay !" << endl;
    }
    else {
        cout << "You don't seem to be that fine" << endl;
        Weapon potion = Weapon("Potion", "A potion that can regen your life", WeaponType::Potion, 1, 1);
        player.AddItem(potion, 1);
    }
    cout << "I'm a merchant, if you need something just call me i'll help you" << endl;
    Weapon potion = Weapon("Potion", "A potion that can regen your life", WeaponType::Potion, 1, 1, 10, 2);
    merchant.AddItem(potion, 5);
    Weapon bottes = Weapon("Boots", "It's better to wear Boots instead of walking with naked feet", WeaponType::Object, 1, 1, 25, 5);
    merchant.AddItem(bottes, 1);
    Weapon caillou = Weapon("Little Stone", "A little magical stone...In reality that's just a stone", WeaponType::Object, 1, 2, 5, 2);
    merchant.AddItem(caillou, 10);
    merchant.ShopLoop();
    /*cout << "Do you want to see what i'm selling ?" << endl; 
    cin >> Yesno;
    if (Yesno == "yes")
    {
        merchant.Display();
        cout << "put the number of the item that you want below" << endl;
        cin >> Shopmerch;
        map<Item, int> temp = merchant.GetInventory();
        if (Shopmerch == 1)
        {
            cout << "You want to buy a "<< temp.begin()->first.GetName() <<"how many do you want ? " << endl;
            cin >> howmuch;
            if (howmuch <=  )
        }

    }
    else {
        cout << "Okay i Understand don't hesitate to come to my shop" << endl;

    }*/

}

