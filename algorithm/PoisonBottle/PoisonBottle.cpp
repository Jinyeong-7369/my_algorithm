#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(void)
{
	int bottle;
	cout << "��ü ������ ������ �Է��� �ּ���";
	cin >> bottle;
	cout << "��ü ������ ������ " << bottle << "�̰� ���� �� ������ �� �� �ϳ��Դϴ�." << endl;
	bool* isPoison = new bool[bottle] {0};
	srand((unsigned int)time(NULL));
	int poison = (rand() % bottle);
	isPoison[poison] = 1;

	int man;
	cout << "���� ���� ����� ���� �����ּ���" << endl;
	cin >> man;
	bool* isDead = new bool[man] {0};
	for (int i = 0; i < bottle; i++)
	{
		cout << i + 1<< "�� ���� ���� ����� �����ּ���" << endl;
		for (int j = 0; j < man; j++)
		{
			bool sel;
			cout << j + 1 << "�� ����� �� ���� ���Ǳ��?(0 : No, 1 : Yes)" << endl;
			cin >> sel;
			if(sel) isDead[j] =isDead[j] || isPoison[i];
		}
	}

	cout << "�������� ������ ";
	for (int i = 0; i < man; i++)
	{
		if (isDead[i]) cout << i + 1 << ' ';
	}
	cout << "�� �׾����ϴ�." << endl;

	cout << "���� �� ������ �����ϱ��?" << endl;
	int result;
	cin >> result;
	if (result-1 == poison) cout << "�����Դϴ�." << endl;
	else cout << "�����Դϴ�." "������ " << poison + 1 << "�Դϴ�" << endl;

	delete[] isPoison;

}