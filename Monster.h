//ドラゴンクエストXX絶賛開発中！
//作成者:16CU0117_張越
//作成日:2017_06_28
//モンスタークラスヘッダーファイル
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
	string act_ = "様子を見ている▼";

public:
	CMonster(string name = "デフォルトモンスター", int hp = 9999);
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

