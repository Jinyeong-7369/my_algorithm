#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(void)
{
	int bottle;
	cout << "전체 술병의 개수를 입력해 주세요";
	cin >> bottle;
	cout << "전체 술병의 개수는 " << bottle << "이고 독이 든 술병은 그 중 하나입니다." << endl;
	bool* isPoison = new bool[bottle] {0};
	srand((unsigned int)time(NULL));
	int poison = (rand() % bottle);
	isPoison[poison] = 1;

	int man;
	cout << "술을 맛볼 사람의 수를 정해주세요" << endl;
	cin >> man;
	bool* isDead = new bool[man] {0};
	for (int i = 0; i < bottle; i++)
	{
		cout << i + 1<< "번 술을 맛볼 사람을 정해주세요" << endl;
		for (int j = 0; j < man; j++)
		{
			bool sel;
			cout << j + 1 << "번 사람은 이 술을 마실까요?(0 : No, 1 : Yes)" << endl;
			cin >> sel;
			if(sel) isDead[j] =isDead[j] || isPoison[i];
		}
	}

	cout << "일주일이 지나고 ";
	for (int i = 0; i < man; i++)
	{
		if (isDead[i]) cout << i + 1 << ' ';
	}
	cout << "이 죽었습니다." << endl;

	cout << "독이 든 술병은 무엇일까요?" << endl;
	int result;
	cin >> result;
	if (result-1 == poison) cout << "정답입니다." << endl;
	else cout << "오답입니다." "정답은 " << poison + 1 << "입니다" << endl;

	delete[] isPoison;

}