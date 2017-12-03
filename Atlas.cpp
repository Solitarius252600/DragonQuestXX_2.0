//ドラゴンクエストXX絶賛開発中！
//作成者:16CU0117_張越
//作成日:2017_06_28
//マップクラスメソッド定義
#include "Atlas.h"


CAtlas::CAtlas()
{
}


CAtlas::~CAtlas()
{
}

void CAtlas::render()
{
	system("cls");

	for (size_t i = 0; i < mapHigh; i++)
	{
		for (size_t j = 0; j < mapWidth; j++)
		{
			switch (mapData[i][j])
			{
			case 0:
				cout << "　";
				break;
			case 1:
				cout << "海";
				break;
			case 2:
				cout << "木";
				break;
			case 3:
				cout << "■";
				break;
			case 4:
				cout << "勇";
				break;
			case 5:
				cout << "ス";
				break;
			case 6:
				cout << "鍵";
				break;
			case 7:
				cout << "宝";
				break;
			case 8:
				cout << "扉";
				break;
			default:
				cout << "パソコンは三秒後爆発！" << endl;
				break;
			}
		}
		cout << "\n";
	}
	cout << "\n\n";

	cout << "+----------------------------------------+" << endl;
	cout << "2：↓,8：↑,4：←,6：→," << endl;
	cout << "+----------------------------------------+" << endl;

}

int CAtlas::getMapData(int x, int y)
{
	return mapData[x][y];
}

void CAtlas::setMapData(int x, int y, int data)
{
	mapData[x][y] = data;
}
