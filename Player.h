//�h���S���N�G�X�gXX��^�J�����I
//�쐬��:16CU0117_���z
//�쐬��:2017_06_28
//�v���C���[�N���X�w�b�_�[�t�@�C��
#pragma once
#include <stdio.h>
#include<string>
#include<iostream>
using namespace std;
#pragma once


enum Command
{
	Attack,
	Death,
	Escape0,
};

class CPlayer
{
	string name_ = "";
	int pow_ = 0;
	int mp_ = 0;
	Command command_ = Attack;
	int attackCounter_ = 0;
	int position[2] = {2,2};
	bool keyflag = false;
	bool gameClearflag = false;
	
public:
	CPlayer(string name);
	~CPlayer();

	string getName();
	int getCounter();
	void addCounter();
	void resetCounter();
	Command getCommand();
	void setCommand(int input);
	void showCommand();
	void randPow();
	int getPow();
	int getPosX();
	int getPosY();
	void setPos(int x, int y);
	void getKey();
	bool getKeyflag();
	void gameClear();
	bool getClearflag();
};

