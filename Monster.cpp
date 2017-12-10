//�h���S���N�G�X�gXX��^�J�����I
//�쐬��:16CU0117_���z
//�쐬��:2017_06_28
//�����X�^�[�N���X���\�b�h��`

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
		cout << "��";
	for (size_t i = 0; i < ((hpMAX - hp_) / 5 + (((hpMAX - hp_) % 5 == 0) ? 0 : 1)); i++)
		cout << "��";
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