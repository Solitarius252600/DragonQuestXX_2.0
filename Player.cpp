//�h���S���N�G�X�gXX��^�J�����I
//�쐬��:16CU0117_���z
//�쐬��:2017_06_28
//�v���C���[�N���X���\�b�h��`

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
		cout << "����������\n�@�U�L\n�@�ɂ���" << endl;
		break;
	case Death:
		cout << "�@��������\n���U�L\n�@�ɂ���" << endl;
		break;
	case Escape0:
		cout << "�@��������\n�@�U�L\n���ɂ���" << endl;
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