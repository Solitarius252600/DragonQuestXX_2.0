//�h���S���N�G�X�gXX��^�J�����I
//�쐬��:16CU0117_���z
//�쐬��:2017_06_28
//�����X�^�[�N���X�w�b�_�[�t�@�C��
#pragma once
#include <stdio.h>
#include<string>
#include<iostream>
using namespace std;

class CMonster
{
	string name_ = "";
	int hpMAX = 0;
	int hp_ = 0;
	string act_ = "�l�q�����Ă��遥";

public:
	CMonster(string name = "�f�t�H���g�����X�^�[", int hp = 9999);
	~CMonster();

	string getName();
	void setName(string n);
	int getHpMAX();
	int getHP();
	void setHP(int h);
	void showState();
	void demage(int pow);
	string action();

};

