#include <iostream>
#include <time.h>
#include <windows.h>

// 곱셈 가로열 * 세로행

struct ARR{
	int arr[4][4];
};

struct ARR33 {
	int arr[3][3];
};

struct ARR35 {
	int arr[3][5];
};

ARR Multiply(ARR A, ARR B) {

	ARR R;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			R.arr[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				R.arr[i][j] += A.arr[i][k] * B.arr[k][j]; // 열*행 4번 
			}
		}
	}

	return R;
}

ARR Plus(ARR A, ARR B) {

	ARR R;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			R.arr[i][j] = A.arr[i][j] + B.arr[i][j];
		}
	}

	return R;
}

ARR Minus(ARR A, ARR B) {

	ARR R;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			R.arr[i][j] = A.arr[i][j] - B.arr[i][j];
		}
	}

	return R;
}

int MatrixValue33(ARR33 A) {

	ARR35 T;
	for (int i = 0; i < 3; i++) {
		for (int j = 0;j < 5;j++) {
			T.arr[i][j] = A.arr[i][j % 3];
		}
	}

	int Result = 0;
	for (int i = 0; i < 3; i++) {
		Result += T.arr[0][0 + i] * T.arr[1][1 + i] * T.arr[2][2 + i];
	}
	for (int i = 0; i < 3; i++) {
		Result -= T.arr[2][0 + i] * T.arr[1][1 + i] * T.arr[0][2 + i];
	}

	return Result;
}

int MatrixValue44(ARR A) {

	int Result = 0;

	ARR33 T;
	for (int i = 0; i < 3;i++) {
		for (int j = 0; j < 3; j++) {
			T.arr[i][j] = A.arr[1 + i][1 + j];
		}
	}
	Result += A.arr[0][0] * MatrixValue33(T);

	for (int j = 0; j < 3; j++) {
		T.arr[j][0] = A.arr[j+1][0];
	}
	Result -= A.arr[0][1] * MatrixValue33(T);

	for (int j = 0; j < 3; j++) {
		T.arr[j][1] = A.arr[j+1][1];
	}
	Result += A.arr[0][2] * MatrixValue33(T);

	for (int j = 0; j < 3; j++) {
		T.arr[j][2] = A.arr[j+1][2];
	}
	Result -= A.arr[0][3] * MatrixValue33(T);

	return Result;
}

ARR MatrixTrans(ARR A) {

	ARR T;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4;j++) {
			T.arr[i][j] = A.arr[j][i];
		}
	}

	return T;
}

void PrintARR(ARR A) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << A.arr[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "-------------------------\n";
}

void RandomARR(ARR& A, ARR& B) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			A.arr[i][j] = (rand() % 9) + 1;
			B.arr[i][j] = (rand() % 9) + 1;
		}
	}
}

ARR FindMaxMin(ARR A, bool flag) {

	ARR T;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			T.arr[i][j] = A.arr[i][j];
		}
	}
	
	int n;
	if (flag) {
		n = 0;
	}
	else {
		n = 9;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (flag) {
				if (A.arr[i][j] > n) {
					n = A.arr[i][j];
				}
			}
			else {
				if (A.arr[i][j] < n) {
					n = A.arr[i][j];
				}
			}
		}
	}

	if (flag) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				T.arr[i][j] += n;
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				T.arr[i][j] -= n;
			}
		}
	}

	return T;
}

void NumPrintARR(ARR A, char* ch) {

	int n;

	n = atoi(ch);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (A.arr[i][j] % n == 0) {
				std::cout << A.arr[i][j] << ' ';
			}
			else {
				std::cout << ' ' << ' ';
			}
		}
		std::cout << '\n';
	}
	std::cout << "-------------------------\n";
}

int main() 
{
	srand(time(NULL));
	ARR arr[3];

	RandomARR(arr[0], arr[1]);
	PrintARR(arr[0]);
	PrintARR(arr[1]);

	char toggle = NULL;
	char temp = NULL;
	
	while (1) {
		
		std::cout << "명령어를 입력하세요. : ";
		char command;
		std::cin >> command;

		if (command == 'm') { //
			arr[2] = Multiply(arr[0], arr[1]);
			PrintARR(arr[2]);
		}
		else if (command == 'a') { //
			arr[2] = Plus(arr[0], arr[1]);
			PrintARR(arr[2]);
		}
		else if (command == 'd') { //
			arr[2] = Minus(arr[0], arr[1]);
			PrintARR(arr[2]);
		}
		else if (command == 'r') { //
			std::cout << MatrixValue44(arr[0]) << ' ' << MatrixValue44(arr[1]) << '\n';
		}
		else if (command == 't') { //
			arr[0] = MatrixTrans(arr[0]);
			arr[1] = MatrixTrans(arr[1]);
			PrintARR(arr[0]);
			PrintARR(arr[1]);
		}
		else if (command == 'e') { //
			if (toggle != command) {
				arr[2] = FindMaxMin(arr[0], false);
				PrintARR(arr[2]);
				arr[2] = FindMaxMin(arr[1], false);
				PrintARR(arr[2]);
			}
			else {
				PrintARR(arr[0]);
				PrintARR(arr[1]);
			}
			toggle = command;
		}
		else if (command == 'f') { //
			if (toggle != command) {
				arr[2] = FindMaxMin(arr[0], true);
				PrintARR(arr[2]);
				arr[2] = FindMaxMin(arr[1], true);
				PrintARR(arr[2]);
			}
			else {
				PrintARR(arr[0]);
				PrintARR(arr[1]);
			}
			toggle = command;
		}
		else if (command >= '1' && command <= '9') {
			if (temp != command) {
				NumPrintARR(arr[0], &command);
				NumPrintARR(arr[1], &command);
			}
			else {
				PrintARR(arr[0]);
				PrintARR(arr[1]);
			}
			temp = command;
		}

		else if (command == 's') { //
			RandomARR(arr[0], arr[1]);
			PrintARR(arr[0]);
			PrintARR(arr[1]);
		}
		else if (command == 'q') { //
			return 0;
		}
	}
}

