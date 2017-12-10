//ドラゴンクエストXX絶賛開発中！
//作成者:16CU0117_張越
//作成日:2017_06_28
//モンスタークラスメソッド定義

#include "Monster.h"


CMonster::CMonster(string name, int hp) : name_(name), hp_(hp), hpMAX(hp)
{
};
CMonster::~CMonster()
{
};

string CMonster::getName()
{
	return name_;
}

void CMonster::setName(string n)
{
	name_ = n;
}

int CMonster::getHP()
{
	return hp_;
}

int CMonster::getHpMAX()
{
	return hpMAX;
}

void CMonster::setHP(int h)
{
	hpMAX = h;
	hp_ = h;
}

//
void CMonster::showState()
{
	cout << name_;
	for (size_t i = 0; i < (hp_ / 5); i++)
		cout << "■";
	for (size_t i = 0; i < ((hpMAX - hp_) / 5 + (((hpMAX - hp_) % 5 == 0) ? 0 : 1)); i++)
		cout << "□";
	cout << "(" << hp_ << ")" << endl;
}

void CMonster::demage(int pow)
{
	hp_ -= pow;
}

string CMonster::action()
{
	return act_;
}