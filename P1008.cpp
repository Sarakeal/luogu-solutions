#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int arr[10];

int main()
{
	for (int num = 123; num < 333; num++)
	{
		int count = 0;
		memset(arr, 0, sizeof(arr));
		arr[num % 10] = arr[num / 10 % 10] = arr[num / 100] = arr[2 * num % 10] = arr[2 * num / 10 % 10] = arr[2 * num / 100] = arr[3 * num % 10] = arr[3 * num / 10 % 10] = arr[3 * num / 100] = 1;
		for (int i = 1; i <= 9; i++) {
			if (arr[i] == 1) {
				count++;
			}
		}
		if (count == 9) {
			cout << num << " " << 2 * num << " " << 3 * num << endl;
		}
	}
	return 0;
}