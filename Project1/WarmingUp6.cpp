#include <iostream>
#include <Windows.h>
#include <string>

struct PLAYER {
	int x, y;

	void move_up() {
		y--;
	}
	void move_down() {
		y++;
	}
	void move_left() {
		x--;
	}
	void move_right() {
		x++;
	}
};

int main() {
	int Board[30][30];

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			Board[i][j] = 0;
		}
	}

	srand(time(NULL));
	Board[rand() % 30][rand() % 30] = -1;
	Board[rand() % 30][rand() % 30] = -1;
	Board[rand() % 30][rand() % 30] = -1;
	Board[rand() % 30][rand() % 30] = -1;
	Board[rand() % 30][rand() % 30] = -1;

	PLAYER player = { 0,0 };

	while (1) {
		system("cls");
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				if (player.x == j && player.y == i) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					std::cout << '*';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					if (Board[i][j] != 0) {
						if (Board[i][j] == -1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
							std::cout << 'X';
						}
						else {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Board[i][j]);
							std::cout << Board[i][j];
						}
					}
					else {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						std::cout << Board[i][j];
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				std::cout << ' ';
			}
			std::cout << std::endl;
		}
		
		std::string command;

		getline(std::cin, command);

		if (command[0] == 'w') {
			if (player.y != 0 && Board[player.y-1][player.x] != -1) {
				player.move_up();
				Board[player.y][player.x]++;
			}
		}
		else if (command[0] == 's') {
			if (player.y != 29 && Board[player.y+1][player.x] != -1) {
				player.move_down();
				Board[player.y][player.x]++;
			}
		}
		else if (command[0] == 'a') {
			if (player.x != 0 && Board[player.y][player.x-1] != -1) {
				player.move_left();
				Board[player.y][player.x]++;
			}
		}
		else if (command[0] == 'd') {
			if (player.x != 29 && Board[player.y][player.x+1] != -1) {
				player.move_right();
				Board[player.y][player.x]++;
			}
		}
		else if (command[0] == NULL) {

			player.x = 0; player.y = 0;
			for (int i = 0; i < 30; i++) {
				for (int j = 0; j < 30; j++) {
					Board[i][j] = 0;
				}
			}
			Board[rand() % 30][rand() % 30] = -1;
			Board[rand() % 30][rand() % 30] = -1;
			Board[rand() % 30][rand() % 30] = -1;
			Board[rand() % 30][rand() % 30] = -1;
			Board[rand() % 30][rand() % 30] = -1;

		}

	}
}