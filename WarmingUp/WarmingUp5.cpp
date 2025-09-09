#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

struct SQUARE {
	int x1, y1;
	int x2, y2;

	void Draw(char Board[][40], int max, char ch) {

		for (int i = y1; i <= y2; i++) {
			for (int j = x1; j <= x2; j++) {
				int Y = ((i % max) + max) % max; 
				int X = ((j % max) + max) % max; 
				if (Board[Y][X] == 'O') {
					Board[Y][X] = '#';
				}
				else {
					Board[Y][X] = ch;
				}

			}
		}
	}
};

int main() {
	char Board[40][40];

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			Board[i][j] = '.';
		}
	}

	int max = 30;

	SQUARE s1, s2;

	int xCount = 0;

	bool flag = true;
	bool re = false;

	while (1) {
		system("cls");
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				std::cout << Board[i][j] << ' ';
			}
			std::cout << std::endl;
		}

		std::string command;
		getline(std::cin, command);

		if (command[0] == 'x') {
			if (flag) {
				s1.x1++; s1.x2++;
			}
			else {
				s2.x1++; s2.x2++;
			}
		}
		else if (command[0] == 'X') {
			if (flag) {
				s1.x1--; s1.x2--;
			}
			else {
				s2.x1--; s2.x2--;
			}
		}
		else if (command[0] == 'y') {
			if (flag) {
				s1.y1++; s1.y2++;
			}
			else {
				s2.y1++; s2.y2++;
			}
		}
		else if (command[0] == 'Y') {
			if (flag) {
				s1.y1--; s1.y2--;
			}
			else {
				s2.y1--; s2.y2--;
			}
		}
		else if (command[0] == 's') {
			if (flag) {
				s1.x2++; s1.y2++;
			}
			else {
				s2.x2++; s2.y2++;
			}
		}
		else if (command[0] == 'S') {
			if (flag) {
				s1.x2--; s1.y2--;
			}
			else {
				s2.x2--; s2.y2--;
			}
		}
		else if (command[0] == 'i') {
			if (flag) {
				s1.x2++;
			}
			else {
				s2.x2++;
			}
		}
		else if (command[0] == 'I') {
			if (flag) {
				s1.x2--;
			}
			else {
				s2.x2--;
			}
		}
		else if (command[0] == 'j') {
			if (flag) {
				s1.y2++;
			}
			else {
				s2.y2++;
			}
		}
		else if (command[0] == 'j') {
			if (flag) {
				s1.y2--;
			}
			else {
				s2.y2--;
			}
		}
		else if (command[0] == 'a') {
			if (flag) {
				s1.x2++; s1.y2--;
			}
			else {
				s2.x2++; s2.y2--;
			}
		}
		else if (command[0] == 'A') {
			if (flag) {
				s1.x2--; s1.y2++;
			}
			else {
				s2.x2--; s2.y2++;
			}
		}
		else if (command[0] == 'b') {
			int n1 = (s1.x2 - s1.x1 + 1);
			int n2 = (s1.y2 - s1.y1 + 1);
			std::cout <<  n1 * n2  << " | " << (s2.x2 - s2.x1 + 1) * (s2.y2 - s2.y1 + 1) << std::endl;
			Sleep(1000);
		}

		else if (command[0] == 'c') {
			if (max < 40) {
				max++;
			}
		}
		else if (command[0] == 'd') {
			if (max > 10) {
				max--;
			}
		}
		else if (isdigit(command[0])){
			std::istringstream iss1(command);
			iss1 >> s1.x1 >> s1.y1 >> s1.x2 >> s1.y2;
			getline(std::cin, command);
			std::istringstream iss2(command);
			iss2 >> s2.x1 >> s2.y1 >> s2.x2 >> s2.y2;
		}
		else if (command[0] == 'r') {
			for (int i = 0; i < 40; i++) {
				for (int j = 0; j < 40; j++) {
					Board[i][j] = '.';
				}
			}
			s1 = { NULL ,NULL, NULL, NULL }, s2 = { NULL ,NULL, NULL, NULL };
			re = true;
		}
		else if (command[0] == 'q') {
			return 0;
		}
		else if (command[0] == 't') {
			flag = !flag;
		}
		
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 40; j++) {
				Board[i][j] = '.';
			}
		}

		if (!re) {
			s1.Draw(Board, max, 'O');
			s2.Draw(Board, max, 'X');
		}
		else {
			re = !re;
		}

	}

}