//�h���S���N�G�X�gXX��^�J�����I
//�쐬��:16CU0117_���z
//�쐬��:2017_06_28
//�}�b�v�N���X���\�b�h��`
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
				cout << "�@";
				break;
			case 1:
				cout << "�C";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "�E";
				break;
			case 5:
				cout << "�X";
				break;
			case 6:
				cout << "��";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			default:
				cout << "�p�\�R���͎O�b�㔚���I" << endl;
				break;
			}
		}
		cout << "\n";
	}
	cout << "\n\n";

	cout << "+----------------------------------------+" << endl;
	cout << "2�F��,8�F��,4�F��,6�F��," << endl;
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
