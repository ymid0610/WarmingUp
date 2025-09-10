#include <iostream>
#include <string>
#include <Windows.h>

void Board_Draw(char Board[][5], int point, int count) {
	std::cout << "점수 : " << point << " 남은 횟수 : " << count << std::endl;
	std::cout << "  a b c d e" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << i+1 << ' ';
		for (int j = 0; j < 5; j++) {
			if (isupper(Board[i][j]) || Board[i][j] == '@') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			}
			std::cout << Board[i][j] << ' ';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void Board_Input_Draw(char Board[][5], int point, int count, int x1, int y1, int x2, int y2) {
	std::cout << "점수 : " << point << " 남은 횟수 : " << count << std::endl;
	std::cout << "  a b c d e" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << ' ';
		for (int j = 0; j < 5; j++) {
			if ((x1 == j && y1 == i) || (x2 ==j && y2 ==i)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			}
			std::cout << Board[i][j] << ' ';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Board_Hint_Draw(char Board[][5], int point, int count) {
	std::cout << "점수 : " << point << " 남은 횟수 : " << count << std::endl;
	std::cout << "  a b c d e" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << ' ';
		for (int j = 0; j < 5; j++) {
			std::cout << Board[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Board_swap(char* ch1, char* ch2) {
	char temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
}

void Board_shuffle(char Board[][5]) {
	srand(time(NULL));
	for (int i = 0; i < 25; i++) {
		int r1 = rand() % 5; int r2 = rand() % 5;
		int r3 = rand() % 5; int r4 = rand() % 5;
		Board_swap(&Board[r1][r2], &Board[r3][r4]);
	}
}

int main() {
	std::string InitialStr = "aabbccddeeffgghhiijjkkll@";

	char Board[5][5];
	char ShowBoard[5][5];

	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			Board[i][j] = InitialStr[k++];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ShowBoard[i][j] = '*';
		}
	}

	Board_shuffle(Board);

	int point = 0, count = 10;

	while (count > 0) {
		system("cls");
		Board_Draw(ShowBoard, point, count);

		std::cout << "입력: ";

		std::string Input1, Input2;
		std::cin >> Input1;

		int x1, y1, x2, y2;

		if ('a' <= Input1[0] && Input1[0] <= 'e') {
			x1 = Input1[0] - 'a';
			y1 = atoi(&Input1[1]) - 1;

			std::cin >> Input2;

			if ('a' <= Input2[0] && Input2[0] <= 'e') {
				x2 = Input2[0] - 'a';
				y2 = atoi(&Input2[1]) - 1;

				if (isupper(ShowBoard[y1][x1]) != 0) {
					ShowBoard[y2][x2] = Board[y2][x2];
				}
				else if (isupper(ShowBoard[y2][x2]) != 0) {
					ShowBoard[y1][x1] = Board[y1][x1];
				}
				else {
					ShowBoard[y1][x1] = Board[y1][x1]; //@
					ShowBoard[y2][x2] = Board[y2][x2]; //a
				}

				system("cls");
				Board_Input_Draw(ShowBoard, point, count, x1, y1, x2, y2);
				Sleep(1000);

				count--;
				point++;

				if (ShowBoard[y1][x1] == ShowBoard[y2][x2]) {
					ShowBoard[y1][x1] = toupper(ShowBoard[y1][x1]); //A
					ShowBoard[y2][x2] = toupper(ShowBoard[y2][x2]); //c
				}
				else if (ShowBoard[y1][x1] == '@') {

					for (int i = 0;i < 5; i++) {
						for (int j = 0; j < 5; j++) {
							if (Board[i][j] == tolower(ShowBoard[y2][x2])) { //a == A
								ShowBoard[i][j] = toupper(Board[i][j]);
							}
						}

					}
					ShowBoard[y2][x2] = toupper(ShowBoard[y2][x2]);

				}
				else if (ShowBoard[y2][x2] == '@') {

					for (int i = 0;i < 5; i++) {
						for (int j = 0; j < 5; j++) {
							if (Board[i][j] == tolower(ShowBoard[y1][x1])) { //a == A
								ShowBoard[i][j] = toupper(Board[i][j]);
							}
						}

					}
					ShowBoard[y1][x1] = toupper(ShowBoard[y1][x1]);

				}
				else {
					point--;
					if (isupper(ShowBoard[y1][x1]) != 0) {
						ShowBoard[y2][x2] = '*';
					}
					else if(isupper(ShowBoard[y2][x2]) != 0) {
						ShowBoard[y1][x1] = '*';
					}
					else {
						ShowBoard[y1][x1] = '*';
						ShowBoard[y2][x2] = '*';
					}
				}

			}
		}
		else if (Input1[0] == 'r') {
			Board_shuffle(Board);
			point = 0, count = 10;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					ShowBoard[i][j] = '*';
				}
			}
		}
		else if (Input1[0] == 'h') {
			system("cls");
			Board_Hint_Draw(Board, point, count);
			Sleep(2000);
		}
	}
	std::cout << "게임이 종료되었습니다. 점수 : " << point;
	return 0;
}