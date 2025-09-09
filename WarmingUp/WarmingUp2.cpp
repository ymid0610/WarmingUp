#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <stack>
#include <list>

#include <Windows.h>

int CountAlpha(std::string& str) {
    int cnt = 0;
    for (char& ch : str) {
        if (isalpha(ch)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    std::ifstream in("data.txt");
    std::string FileStr;

    if (in.is_open()) {
        in.seekg(0, std::ios::end);
        int size = in.tellg();

        FileStr.resize(size);

        in.seekg(0, std::ios::beg);
        in.read(&FileStr[0], size);
    }
    else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }

    char toggle = NULL;
    std::stack<std::string> stack;
    stack.push(FileStr);

    std::cout << stack.top() << std::endl;

    while (1) {
        std::cout << "명령어를 입력하세요. : ";
        
        char command;
        std::cin >> command;

        if (command == 'a') { //
            if (toggle != command) {
                std::string str = stack.top();
                for (char& ch : str) {
                    if (std::islower(ch)) {
                        ch = std::toupper(ch);
                    }
                }
                toggle = command;
                stack.push(str);
                std::cout << stack.top() << std::endl;
            }
            else {
                toggle = NULL;
                stack.pop();
                std::cout << stack.top() << std::endl;
            }
        }
        else if (command == 'b') { // 단어 배열
            std::list<std::string> lists;
            std::string word;

            for (int i = 0; i < stack.top().size(); i++) {
                if (stack.top()[i] == ' ') {
                    word.push_back('\0');
                    lists.push_back(word);
                    word.clear();
                }
                else if (stack.top()[i] == '\n') {
                    word.push_back('\0');
                    lists.push_back(word);
                    word.clear();

                    lists.push_back("\n");
                }
                else {
                    word.push_back(stack.top()[i]);
                }
            }

            int count = 0;
            for (std::string& list : lists) {
                if (list[0] != '\n') {
                    std::cout << list << ' ';
                    count++;
                }
                else {
                    std::cout << "- 단어의 개수 : " << count << std::endl;
                    count = 0;
                }
            }
            std::cout << std::endl;

        }
        else if (command == 'c') { // 단어 배열
            if (toggle != command) {
                std::list<std::string> lists;
                std::string word;

                for (int i = 0; i < stack.top().size(); i++) {
                    if (stack.top()[i] == ' ') {
                        word.push_back('\0');
                        lists.push_back(word);
                        word.clear();
                    }
                    else if (stack.top()[i] == '\n') {
                        word.push_back('\0');
                        lists.push_back(word);
                        word.clear();

                        lists.push_back("\n");
                    }
                    else {
                        word.push_back(stack.top()[i]);
                    }
                }

                for (std::string& list : lists) {
                    if (std::isupper(list[0])) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        if (list[0] != '\n') {
                            std::cout << list << ' ';
                        }
                        else {
                            std::cout << std::endl;
                        }

                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        if (list[0] != '\n') {
                            std::cout << list << ' ';
                        }
                        else {
                            std::cout << std::endl;
                        }
                    }
                }
                std::cout << std::endl;
                toggle = command;
            }
            else {
                toggle = NULL;
                std::cout << stack.top() << std::endl;
            }
        }
        else if (command == 'd') { // 문장 배열
            if (toggle != command) {
                std::list<std::string> lists;
                std::string word;

                for (int i = 0; i < stack.top().size(); i++) {
                    if (stack.top()[i] == '\n') {
                        word.push_back('\0');
                        lists.push_back(word);
                        word.clear();

                        lists.push_back("\n");
                    }
                    else {
                        word.push_back(stack.top()[i]);
                    }
                }

                for (std::string& list : lists) {
                    if (list[0] != '\n') {
                        std::reverse(list.begin(), list.end());
                        std::cout << list;
                    }
                    else {
                        std::cout << list;
                    }
                }
                std::cout << std::endl;
                toggle = command;

                std::string ReverseStr;
                for (std::string& list : lists) {
                    ReverseStr += list;
                }
                stack.push(ReverseStr);

            }
            else {
                toggle = NULL;
                stack.pop();
                std::cout << stack.top() << std::endl;
            }
        }
        else if (command == 'e') { // 
            std::string str = stack.top();
            if (toggle != command) {
                for (char& ch : str) {
                    if (ch == ' ') {
                        ch = '/';
                    }
                }
                toggle = command;
                stack.push(str);
                std::cout << stack.top() << std::endl;
            }
            else {
                toggle = NULL;
                stack.pop();
                std::cout << stack.top() << std::endl;
            }
        }
        else if (command == 'f') { // 단어 배열

            if (toggle != command) {
                std::list<std::string> lists;
                std::string word;

                for (int i = 0; i < stack.top().size(); i++) {
                    if (stack.top()[i] == ' ' || stack.top()[i] == '/') {
                        word.push_back('\0');
                        lists.push_back(word);
                        word.clear();

                        if (stack.top()[i] == ' ') {
                            lists.push_back(" ");
                        }
                        else {
                            lists.push_back("/");
                        }

                    }
                    else if (stack.top()[i] == '\n') {
                        word.push_back('\0');
                        lists.push_back(word);
                        word.clear();

                        lists.push_back("\n");
                    }
                    else {
                        word.push_back(stack.top()[i]);
                    }
                }
                std::string ReverseStr;
                for (std::string& list : lists) {
                    std::reverse(list.begin(), list.end());
                    ReverseStr += list;
                }
                stack.push(ReverseStr);

                std::cout << stack.top() << std::endl;
                toggle = command;
            }
            else {
                toggle = NULL;
                stack.pop();
                std::cout << stack.top() << std::endl;
            }

        }
        else if (command == 'g') { //
            std::string str = stack.top();
            if (toggle != command) {
                char Original, Replaced;

                std::cout << "바꾸고 싶은 문자 : ";
                std::cin >> Original;

                std::cout << "문자 입력 : ";
                std::cin >> Replaced;

                for (char& ch : str) {
                    if (ch == Original) {
                        ch = Replaced;
                    }
                }
                toggle = command;
                stack.push(str);
                std::cout << stack.top() << std::endl;
            }
            else {
                toggle = NULL;
                stack.pop();
                std::cout << stack.top() << std::endl;
            }
        }
        else if (command == 'h') { // 
            std::string str = stack.top();
            if (toggle != command) {
                for (int i = 0; i < str.size(); i++) {
                    if (isdigit(str[i])) {
                        str.insert(i+1, 1, '\n');
                    }
                }
                toggle = command;
                stack.push(str);
                std::cout << stack.top() << std::endl;
            }
            else {
                toggle = NULL;
                stack.pop();
                std::cout << stack.top() << std::endl;
            }
        }
        else if (command == 'i') { // 문장배열
            if (toggle == '1') {
                std::list<std::string> lists;
                std::string word;

                for (int i = 0; i < stack.top().size(); i++) {
                    if (stack.top()[i] == '\n') {
                        word.push_back('\0');
                        lists.push_back(word);
                        word.clear();
                    }
                    else {
                        word.push_back(stack.top()[i]);
                    }
                }

                int n = 0;

                lists.sort([](std::string& a, std::string& b) {
                    return CountAlpha(a) > CountAlpha(b);
                    });

                std::string str;
                for (std::string& list : lists) {
                    str += list;
                    str += '\n';
                }
                stack.push(str);

                std::cout << stack.top() << std::endl;
                toggle = '2';
            }
            else if (toggle == '2') {
                stack.pop();
                stack.pop();
                toggle = NULL;
                std::cout << stack.top() << std::endl;
            }
            else {
                std::list<std::string> lists;
                std::string word;

                for (int i = 0; i < stack.top().size(); i++) {
                    if (stack.top()[i] == '\n') {
                        word.push_back('\0');
                        lists.push_back(word);
                        word.clear();
                    }
                    else {
                        word.push_back(stack.top()[i]);
                    }
                }

                int n = 0;

                lists.sort([](std::string& a, std::string& b) {
                    return CountAlpha(a) < CountAlpha(b);
                    });

                std::string str;
                for (std::string& list : lists) {
                    str += list;
                    str += '\n';
                }
                stack.push(str);

                std::cout << stack.top() << std::endl;
                toggle = '1';
            }
        }
        else if (command == 'j') { // 단어배열
            std::string input;
            std::cin >> input;

            std::list<std::string> lists;
            std::string word;

            for (int i = 0; i < stack.top().size(); i++) {
                if (stack.top()[i] == ' ') {
                    lists.push_back(word);
                    word.clear();
                }
                else if (stack.top()[i] == '\n') {
                    lists.push_back(word);
                    word.clear();

                    lists.push_back("\n");
                }
                else {
                    word.push_back(stack.top()[i]);
                }
            }

            for (std::string& list : lists) {
                std::string temp = list;

                for (char& ch : temp) {
                    if (std::isupper(ch)) {
                        ch = std::tolower(ch);
                    }
                }
                for (char& ch : input) {
                    if (std::isupper(ch)) {
                        ch = std::tolower(ch);
                    }
                }

                if (temp == input) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    std::cout << list << ' ';
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    if (list[0] != '\n') {
                        std::cout << list << ' ';
                    }
                    else {
                        std::cout << std::endl;
                    }
                }
            }
            std::cout << std::endl;
        }
        else if (command == 'q') {
            return 0;
        }
        else if (command == 'u') {
            stack.pop();
            std::cout << stack.top() << std::endl;
        }
    }
}