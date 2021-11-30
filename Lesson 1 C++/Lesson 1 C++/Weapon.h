#pragma once
#include "Item.h"

enum class WeaponType {
    Sword,  //0
    Long_Sword,  //1
    Knife,  //2
    Axe,  //3
    Bow,  //4
    Staff, //5
    Potion, //6
    Object //7
};

class Weapon :
    public Item
{
private:
    WeaponType mType;
    float mAttackRange;
    int mAttackDamage;
public:
    Weapon();
    Weapon(std::string name, std::string desc, WeaponType type, float range, int damage, int price = 0, float weight = 0);
    ~Weapon();
    WeaponType GetWeaponType();
    int GetRange();
    int GetDamage();
};

