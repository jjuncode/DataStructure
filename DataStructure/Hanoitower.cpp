#include <iostream>

void HaniMove(int num, char from, char by, char to)
{
	if (num == 1) {
		// �ű� ������ 1���� �׳� �ű�� ������.
		printf("����1�� %c���� %c�� �̵�\n", from, to);
	}
	else {
		// �ƴϸ� Move
		HaniMove(num - 1, from, to, by);	// ���� ���ݵ� �ű�� 
		printf("����%d�� %c���� %c�� �̵�\n", num, from, to);	// ���� ū ���� �ű�
		HaniMove(num - 1, by, from, to);	// ���� ���ݵ� ū ���� ���� �ű��
	}
}

int main()
{
	HaniMove(10, 'A', 'B', 'C');
}