//ドラゴンクエストXX絶賛開発中！
//作成者:16CU0117_張越
//作成日:2017_06_28
//メイン関数CPP
#include <Windows.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<time.h>
#include"Monster.h"
#include"Player.h"
#include"Atlas.h"

using namespace std;


//関数プロトタイプ
bool Battle(CMonster*, CPlayer*);
void Move(CAtlas*,CPlayer*,CMonster*);
void setColor(int);

int main()
{
	srand((unsigned)time(NULL));

	CMonster* monsterP(new CMonster("スライム", 50));
	CPlayer* playerP(new CPlayer("勇者ヨシヒコ"));
	CAtlas* atlasP(new CAtlas);

	while (!playerP->getClearflag())
	{
		Move(atlasP, playerP,monsterP);
	}

	system("cls");
	setColor(0x0C);
	cout << "　　　　　　　クリアしました！おめでとうございます！\n\n\n\n\n\n";
	setColor(0000);
	system("pause");

	delete monsterP;
	delete playerP;
	delete atlasP;
	return 0;
}

//戦う関数
//trueーーーー敵を倒した
//falseーーー逃げ切った
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
		cout << "2：↓,8：↑,１：決定" << endl;

		cin >> input;
		playerP->setCommand(input);
		if (input == 1)
		{
			switch (playerP->getCommand())
			{
			case Attack:
				if (rand() % 100 < 5)
				{
					cout << "ミス▼" << endl;
					system("pause");
					break;
				}
				playerP->randPow();
				monsterP->demage(playerP->getPow());
				playerP->addCounter();
				cout << monsterP->getName() << "に" << playerP->getPow() << "のダメージ▼" << endl;
				cout << monsterP->getName() << "は" << monsterP->action() << endl;
				system("pause");
				break;
			case Death:
				if (playerP->getCounter() >= 5)
				{
					cout << playerP->getName() << "は" << "ザキ" << "を唱えた" << endl;
					cout << monsterP->getName() << "の" << "息の根" << "を" << "止めた" << endl;
					system("pause");
					goto KILL;
				}
				else
				{
					cout << "MPが足りない！" << endl;
					system("pause");
				}
				break;
			case Escape0:
				if (rand() % 2)
				{
					cout << playerP->getName() << "は" << "逃げ出した" << endl;
					system("pause");
					system("cls");
					cout << "うまく　逃げ切れた" << endl;
					playerP->resetCounter();
					system("pause");
					return false;
				}
				else
				{
					cout << playerP->getName() << "は" << "逃げ出した" << endl;
					cout << "しかし　まわりこまれてしまった" << endl;
					cout << monsterP->getName() << "は" << monsterP->action() << endl;
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
	cout << monsterP->getName() << "を" << "倒した" << endl;
	playerP->resetCounter();
	system("pause");
	return true;

}

//移動関数
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
			cout << "\n古いキーを手に入れた！！\n\n";
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
				cout << "\nかかかかーー\n\n";
				system("pause");
			}
			else
			{
				cout << "\nそこには扉がある！！\n\n";
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
			cout << "\n古いキーを手に入れた！！\n\n";
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
				cout << "\nかかかかーー\n\n";
				system("pause");
			}
			else
			{
				cout << "\nそこには扉がある！！\n\n";
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
			cout << "\n古いキーを手に入れた！！\n\n";
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
				cout << "\nかかかかーー\n\n";
				system("pause");
			}
			else
			{
				cout << "\nそこには扉がある！！\n\n";
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
			cout << "\n古いキーを手に入れた！！\n\n";
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
				cout << "\nかかかかーー\n\n";
				system("pause");
			}
			else
			{
				cout << "\nそこには扉がある！！\n\n";
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
	CONSOLE_SCREEN_BUFFER_INFO csbi;//構造体*


	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//hStdoutのコンソールスクリーンバッファ情報をcsbiに取得
	GetConsoleScreenBufferInfo(hStdout, &csbi);

	//プロンプトの文字の色を変更
	SetConsoleTextAttribute(hStdout, color);

	return;
}