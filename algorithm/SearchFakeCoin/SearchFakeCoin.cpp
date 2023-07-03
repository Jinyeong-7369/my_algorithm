#include<iostream>
using namespace std;

int sum(int a[], int first, int last)
{
	int ret = 0;
	for (int i = first; i <= last; i++)
	{
		ret += a[i];
	}
	return ret;
}
int main(void)
{
	int fake_coin;
	int n;
	cout << "��ü ������ ������ �����ּ���";
	cin >> n;
	int* isFake = new int[n] {0};
	cout << "��¥ ������ ��ȣ�� �Է��ϼ���(0~" << n - 1 << ")";
	cin >> fake_coin;
	isFake[fake_coin] = 1;

	int low = 0;
	int high = n - 1;
	
	int O = 0;
	int search = 0;
	int middle = (low + high) / 2;
	while (low < high)
	{
		O++;
		middle = (low + high) / 2;
		if (sum(isFake, low, middle) < sum(isFake, middle + 1, high))
		{
			low = middle + 1;
		}
		else
		{
			high = middle;
		}
	}
	cout <<"��¥ ������" << low << "�Դϴ�(�ҿ� �ð� : " << O << ")" <<endl;
	delete []isFake;
}