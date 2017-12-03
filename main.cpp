//�h���S���N�G�X�gXX��^�J�����I
//�쐬��:16CU0117_���z
//�쐬��:2017_06_28
//���C���֐�CPP
#include <Windows.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<time.h>
#include"Monster.h"
#include"Player.h"
#include"Atlas.h"

using namespace std;


//�֐��v���g�^�C�v
bool Battle(CMonster*, CPlayer*);
void Move(CAtlas*,CPlayer*,CMonster*);
void setColor(int);

int main()
{
	srand((unsigned)time(NULL));

	CMonster* monsterP(new CMonster("�X���C��", 50));
	CPlayer* playerP(new CPlayer("�E�҃��V�q�R"));
	CAtlas* atlasP(new CAtlas);

	while (!playerP->getClearflag())
	{
		Move(atlasP, playerP,monsterP);
	}

	system("cls");
	setColor(0x0C);
	cout << "�@�@�@�@�@�@�@�N���A���܂����I���߂łƂ��������܂��I\n\n\n\n\n\n";
	setColor(0000);
	system("pause");

	delete monsterP;
	delete playerP;
	delete atlasP;
	return 0;
}

//�키�֐�
//true�[�[�[�[�G��|����
//false�[�[�[�����؂���
bool Battle(CMonster* monsterP, CPlayer* playerP)
{
	int input = 0;

	while (monsterP->getHP() >0)
	{
		system("cls");
		monsterP->showState();
		cout << "+----------------------------------------+" << endl;
		playerP->showCommand();
		cout << "+----------------------------------------+" << endl;
		cout << "2�F��,8�F��,�P�F����" << endl;

		cin >> input;
		playerP->setCommand(input);
		if (input == 1)
		{
			switch (playerP->getCommand())
			{
			case Attack:
				if (rand() % 100 < 5)
				{
					cout << "�~�X��" << endl;
					system("pause");
					break;
				}
				playerP->randPow();
				monsterP->demage(playerP->getPow());
				playerP->addCounter();
				cout << monsterP->getName() << "��" << playerP->getPow() << "�̃_���[�W��" << endl;
				cout << monsterP->getName() << "��" << monsterP->action() << endl;
				system("pause");
				break;
			case Death:
				if (playerP->getCounter() >= 5)
				{
					cout << playerP->getName() << "��" << "�U�L" << "��������" << endl;
					cout << monsterP->getName() << "��" << "���̍�" << "��" << "�~�߂�" << endl;
					system("pause");
					goto KILL;
				}
				else
				{
					cout << "MP������Ȃ��I" << endl;
					system("pause");
				}
				break;
			case Escape0:
				if (rand() % 2)
				{
					cout << playerP->getName() << "��" << "�����o����" << endl;
					system("pause");
					system("cls");
					cout << "���܂��@�����؂ꂽ" << endl;
					playerP->resetCounter();
					system("pause");
					return false;
				}
				else
				{
					cout << playerP->getName() << "��" << "�����o����" << endl;
					cout << "�������@�܂�肱�܂�Ă��܂���" << endl;
					cout << monsterP->getName() << "��" << monsterP->action() << endl;
					system("pause");
				}
				break;
			default:
				break;
			}
		}
	}

KILL:
	system("cls");
	cout << monsterP->getName() << "��" << "�|����" << endl;
	playerP->resetCounter();
	system("pause");
	return true;

}

//�ړ��֐�
void Move(CAtlas* atlasP,CPlayer* playerP,CMonster* monsterP)
{
	int input = 0;

	atlasP->render();

	cin >> input;

	switch (input)
	{
	case 2:
		switch (atlasP->getMapData(playerP->getPosX() + 1, playerP->getPosY()))
		{
		case 0:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX() + 1, playerP->getPosY(), 4);
			playerP->setPos(playerP->getPosX() + 1, playerP->getPosY());
			break;
		case 5:
			if (Battle(monsterP, playerP))
			{
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
				atlasP->setMapData(playerP->getPosX() + 1, playerP->getPosY(), 4);
				playerP->setPos(playerP->getPosX() + 1, playerP->getPosY());
				monsterP->setHP(monsterP->getHpMAX() + 10);
			}
			else
			{
				monsterP->setHP(monsterP->getHP());
			}
			break;
		case 6:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX() + 1, playerP->getPosY(), 4);
			playerP->setPos(playerP->getPosX() + 1, playerP->getPosY());
			playerP->getKey();
			cout << "\n�Â��L�[����ɓ��ꂽ�I�I\n\n";
			system("pause");
			break;
		case 7:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX() + 1, playerP->getPosY(), 4);
			playerP->setPos(playerP->getPosX() + 1, playerP->getPosY());
			playerP->gameClear();
		case 8:
			if (playerP->getKeyflag())
			{
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
				atlasP->setMapData(playerP->getPosX() + 1, playerP->getPosY(), 4);
				playerP->setPos(playerP->getPosX() + 1, playerP->getPosY());
				cout << "\n���������[�[\n\n";
				system("pause");
			}
			else
			{
				cout << "\n�����ɂ͔�������I�I\n\n";
				system("pause");
			}
			break;
		default:
			break;
		}
		break;
	case 8:
		switch (atlasP->getMapData(playerP->getPosX() - 1, playerP->getPosY()))
		{
		case 0:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX() - 1, playerP->getPosY(), 4);
			playerP->setPos(playerP->getPosX() - 1, playerP->getPosY());
			break;
		case 5:
			if (Battle(monsterP, playerP))
			{
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
				atlasP->setMapData(playerP->getPosX() - 1, playerP->getPosY(), 4);
				playerP->setPos(playerP->getPosX() - 1, playerP->getPosY());
				monsterP->setHP(monsterP->getHpMAX() + 10);
			}
			else
			{
				monsterP->setHP(monsterP->getHP());
			}
			break;
		case 6:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX() - 1, playerP->getPosY(), 4);
			playerP->setPos(playerP->getPosX() - 1, playerP->getPosY());
			playerP->getKey();
			cout << "\n�Â��L�[����ɓ��ꂽ�I�I\n\n";
			system("pause");
			break;
		case 7:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX() - 1, playerP->getPosY(), 4);
			playerP->setPos(playerP->getPosX() - 1, playerP->getPosY());
			playerP->gameClear();
		case 8:
			if (playerP->getKeyflag())
			{
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
				atlasP->setMapData(playerP->getPosX() - 1, playerP->getPosY(), 4);
				playerP->setPos(playerP->getPosX() - 1, playerP->getPosY());				
				cout << "\n���������[�[\n\n";
				system("pause");
			}
			else
			{
				cout << "\n�����ɂ͔�������I�I\n\n";
				system("pause");
			}
			break;
		default:
			break;
		}
		break;
	case 4:
		switch (atlasP->getMapData(playerP->getPosX(), playerP->getPosY() - 1))
		{
		case 0:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY() - 1, 4);
			playerP->setPos(playerP->getPosX(), playerP->getPosY() - 1);
			break;
		case 5:
			if (Battle(monsterP, playerP))
			{
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY() - 1, 4);
				playerP->setPos(playerP->getPosX(), playerP->getPosY() - 1);
				monsterP->setHP(monsterP->getHpMAX() + 10);
			}
			else
			{
				monsterP->setHP(monsterP->getHP());
			}
			break;
		case 6:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY() - 1, 4);
			playerP->setPos(playerP->getPosX(), playerP->getPosY() - 1);
			playerP->getKey();
			cout << "\n�Â��L�[����ɓ��ꂽ�I�I\n\n";
			system("pause");
			break;
		case 7:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY() - 1, 4);
			playerP->setPos(playerP->getPosX(), playerP->getPosY() - 1);
			playerP->gameClear();
		case 8:
			if (playerP->getKeyflag())
			{
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY() - 1, 4);
				playerP->setPos(playerP->getPosX(), playerP->getPosY() - 1);
				cout << "\n���������[�[\n\n";
				system("pause");
			}
			else
			{
				cout << "\n�����ɂ͔�������I�I\n\n";
				system("pause");
			}
			break;
		default:
			break;
		}
		break;
	case 6:
		switch (atlasP->getMapData(playerP->getPosX(), playerP->getPosY() + 1))
		{
		case 0:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY() + 1, 4);
			playerP->setPos(playerP->getPosX(), playerP->getPosY() + 1);
			break;
		case 5:
			if (Battle(monsterP, playerP))
			{
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY() + 1, 4);
				playerP->setPos(playerP->getPosX(), playerP->getPosY() + 1);
				monsterP->setHP(monsterP->getHpMAX() + 10);
			}
			else
			{
				monsterP->setHP(monsterP->getHP());
			}
			break;
		case 6:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY() + 1, 4);
			playerP->setPos(playerP->getPosX(), playerP->getPosY() + 1);
			playerP->getKey();
			cout << "\n�Â��L�[����ɓ��ꂽ�I�I\n\n";
			system("pause");
			break;
		case 7:
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
			atlasP->setMapData(playerP->getPosX(), playerP->getPosY() + 1, 4);
			playerP->setPos(playerP->getPosX(), playerP->getPosY() + 1);
			playerP->gameClear();
		case 8:
			if (playerP->getKeyflag())
			{
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY(), 0);
				atlasP->setMapData(playerP->getPosX(), playerP->getPosY() + 1, 4);
				playerP->setPos(playerP->getPosX(), playerP->getPosY() + 1);
				cout << "\n���������[�[\n\n";
				system("pause");
			}
			else
			{
				cout << "\n�����ɂ͔�������I�I\n\n";
				system("pause");
			}
		default:
			break;
		}
		break;
	default:
		break;
	}

}

void setColor(int color)
{
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO csbi;//�\����*


	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//hStdout�̃R���\�[���X�N���[���o�b�t�@����csbi�Ɏ擾
	GetConsoleScreenBufferInfo(hStdout, &csbi);

	//�v�����v�g�̕����̐F��ύX
	SetConsoleTextAttribute(hStdout, color);

	return;
}