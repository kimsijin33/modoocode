#include <iostream>

//https://modoocode.com/269
//pibonacci
int main() {
	int bef = 1, cur = 1;

	for (int i = 0; i < 98; i++) {
		int temp = cur;
		cur = cur + bef;
		bef = temp;

		std::cout << i << " : " << cur << std::endl;
	}
	std::cout << "F100 : " << cur << std::endl;

	return 0;
}
