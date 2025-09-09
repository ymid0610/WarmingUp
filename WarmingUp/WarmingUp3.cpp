#include <iostream>
#include <sstream>
#include <string>

struct LIST{
	int x, y, z;
	bool flag = false;
};

void swap(LIST& a, LIST& b) {
	LIST temp;
	
	temp = a;
	a = b;
	b = temp;
}

void SwapByDistance(LIST& a, LIST& b) {
	int r1 = a.x * a.x + a.y * a.y + a.z * a.z;
	int r2 = b.x * b.x + b.y * b.y + b.z * b.z;

	if (r1 > r2) {
		swap(a, b);
	}
}

int main() {
	LIST list[10];
	
	char toggle = NULL;
	LIST temp[10];

	while (1) {
		for (int i = 9; i >= 0; i--) {
			std::cout << i << "번 리스트 : ";
			if (list[i].flag) {
				std::cout << list[i].x << ", " << list[i].y << ", " << list[i].z;
			}
			std::cout << std::endl;
		}
		
		char command;
		int x, y, z;
		std::cin >> command;

		if (command == '+') { //
			std::cin >> x >> y >> z;
			int i;
			for (i = 0; i < 10; i++) {
				if (!list[i].flag) {
					list[i].x = x, list[i].y = y, list[i].z = z;
					list[i].flag = true;
					break;
				}
			}
			if (i == 10) {
				std::cout << "꽉참" << std::endl;
			}
		}
		else if (command == '-') { //
			for (int i = 9; i >= 0; i--) {
				if (list[i].flag) {
					list[i].x = NULL, list[i].y = NULL, list[i].z = NULL;
					list[i].flag = false;
					break;
				}
			}
		}
		else if (command == 'e') {
			std::cin >> x >> y >> z;

			if (!list[9].flag) {
				for (int i = 9; i > 0; i--) {
					swap(list[i - 1], list[i]);
				}
				list[0].x = x, list[0].y = y, list[0].z = z;
				list[0].flag = true;
			}
			else { // 공백 안밀기
				int n;
				for (n = 9; n > 0; n--) {
					if (!list[n].flag) {
						break;
					}
				}
				if (n == 0) {
					list[0].x = x, list[0].y = y, list[0].z = z;
					list[0].flag = true;
				}
				else {
					for (int i = n; i > 0; i--) {
						swap(list[i - 1], list[i]);
					}
					list[0].x = x, list[0].y = y, list[0].z = z;
					list[0].flag = true;
				}
			}
		}
		else if (command == 'd') {
			for (int i = 0; i < 10; i++) {
				if (list[i].flag) {
					list[i].x = NULL, list[i].y = NULL, list[i].z = NULL;
					list[i].flag = false;
					break;
				}
			}
		}
		else if (command == 'a') {
			int n = 0;
			for (int i = 0; i < 10; i++) {
				if (list[i].flag) {
					n++;
				}
			}
			std::cout << n << "개" << std::endl;
		}
		else if (command == 'b') { //
			for (int i = 0; i < 9; i++) {
				swap(list[i], list[i + 1]);
			}
		}
		else if (command == 'c') {
			for (int i = 0; i < 10; i++) {
				list[i].x = NULL, list[i].y = NULL, list[i].z = NULL;
				list[i].flag = false;
			}
		}
		else if (command == 'f') {

			if (toggle != command) {

				for (int i = 0; i < 10; i++) {
					temp[i] = list[i];
				}

				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						SwapByDistance(list[j], list[j + 1]);
					}
				}

				toggle = command;
			}
			else {
				for (int i = 0; i < 10; i++) {
					list[i] = temp[i];
				}
				toggle = NULL;
			}
		}
		else if (command == 'q') {
			return 0;
		}
	}
}
