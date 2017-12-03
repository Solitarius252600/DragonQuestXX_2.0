//ドラゴンクエストXX絶賛開発中！
//作成者:16CU0117_張越
//作成日:2017_06_28
//プレイヤークラスメソッド定義

#include "Player.h"

CPlayer::CPlayer(string name) : name_(name)
{
	pow_ = rand() % 5 + 5;
};
CPlayer::~CPlayer()
{
};

string CPlayer::getName()
{
	return name_;
}

int CPlayer::getCounter()
{
	return attackCounter_;
}

void CPlayer::addCounter()
{
	attackCounter_++;
}

void CPlayer::resetCounter()
{
	attackCounter_ = 0;
}

Command CPlayer::getCommand()
{
	return command_;
}

void CPlayer::setCommand(int input)
{
	switch (input)
	{
	case 1:
		break;
	case 2:
		switch (command_)
		{
		case Attack:
			command_ = Death;
			break;
		case Death:
			command_ = Escape0;
			break;
		case Escape0:
			command_ = Attack;
			break;
		default:
			break;
		}
		break;
	case 8:
		switch (command_)
		{
		case Attack:
			command_ = Escape0;
			break;
		case Death:
			command_ = Attack;
			break;
		case Escape0:
			command_ = Death;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void CPlayer::showCommand()
{
	switch (command_)
	{
	case Attack:
		cout << "＞たたかう\n　ザキ\n　にげる" << endl;
		break;
	case Death:
		cout << "　たたかう\n＞ザキ\n　にげる" << endl;
		break;
	case Escape0:
		cout << "　たたかう\n　ザキ\n＞にげる" << endl;
		break;
	default:
		break;
	}
}

void CPlayer::randPow()
{
	pow_ = rand() % 6 + 5;
}

int CPlayer::getPow()
{
	return pow_;
}

int CPlayer::getPosX()
{
	return position[0];
}

int CPlayer::getPosY()
{
	return position[1];
}

void CPlayer::setPos(int x, int y)
{
	position[0] = x;
	position[1] = y;
}

void CPlayer::getKey()
{
	keyflag = true;
}

bool CPlayer::getKeyflag()
{
	return keyflag;
}

void CPlayer::gameClear()
{
	gameClearflag = true;
}

bool CPlayer::getClearflag()
{
	return gameClearflag;
}