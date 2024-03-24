#include <iostream>

void HaniMove(int num, char from, char by, char to)
{
	if (num == 1) {
		// 옮길 개수가 1개면 그냥 옮기고 끝낸다.
		printf("원반1을 %c에서 %c로 이동\n", from, to);
	}
	else {
		// 아니면 Move
		HaniMove(num - 1, from, to, by);	// 작은 원반들 옮기기 
		printf("원반%d를 %c에서 %c로 이동\n", num, from, to);	// 가장 큰 원반 옮김
		HaniMove(num - 1, by, from, to);	// 작은 원반들 큰 원반 위로 옮기기
	}
}

int main()
{
	HaniMove(10, 'A', 'B', 'C');
}