#include <iostream>
#include <string>
#include <vector>

#include "MyFunc.h"

using namespace std;

#define INFO_COLUMN 3
#define NAME_IDX 0
#define AGE_IDX 1
#define BIRTH_IDX 2

namespace inputData
{
	void InputInfo(string** arr, int i) {
		// 0 1 2 3 4 5 6 7 8 9 10 11 12
		// 강예정   2 5   0 0 1 1  3  0
		bool error;
		int ok = 0;
		int name_split_point;
		int age_split_point;
		string input;
		string name;
		string age;
		string birth;

		while (ok == 0) {

			bool error = false; // 중간에 한번 에러 메세지 떴어도 마지막에 ok 받고 나갈 수 있도록 error 변수 초기화

			getline(cin, input);

			// 이름 추출
			name_split_point = input.find(" ");

			name = input.substr(0, name_split_point);

			// 이름에 숫자가 있는지 확인(문자면 0, 그런데 특수문자도 0이 되는건 어떻게 해결합니까 ???)
			// 이름의 길이는 상관없음.
			for (char c : name) {

				if (isdigit(c) != 0) {
					cout << "***입력 오류: 이름은 문자로만 입력하시오.***" << endl;
					error = true;
					break;
				}
			}

			// 나이 추출
			age_split_point = input.find(" ", name_split_point + 1);

			age = input.substr((name_split_point + 1), (age_split_point - name_split_point - 1));

			// 나이가 숫자로 이루어져있는지 확인
			// 나이의 길이는 상관없음.
			for (char c : age) {

				if (isdigit(c) == 0) {
					cout << "***입력 오류: 나이는 숫자로만 입력하시오.***" << endl;
					error = true;
					break;
				}
			}

			// 생일 추출
			birth = input.substr(age_split_point + 1);

			// 나이의 길이가 여섯자리인지 확인
			if (birth.length() != 6) {
				cout << "***입력 오류: 생일은 여섯 자리만 입력하시오.***" << endl;
				error = true;
			}

			// 나이가 숫자로 이루어져있는지 확인
			for (char c : birth) {

				if (isdigit(c) == 0) {
					cout << "***입력 오류: 생일은 숫자로만 입력하시오.***" << endl;
					error = true;
					break;
				}
			}

			if (error == false) {
				arr[i][NAME_IDX] = name;
				arr[i][AGE_IDX] = age;
				arr[i][BIRTH_IDX] = birth;
				ok++;
			}
		}

	}
}

namespace calculatingData {

	float get_avg(string** arr, int num) {

		float sum = 0;

		for (int i = 1; i < num + 1; i++) {

			sum += stof(arr[i][AGE_IDX]);

		} return (sum / num);
	}

	int get_early_birth(string** arr, int num) {

		int min = 10000;

		for (int i = 1; i < num + 1; i++) {
			int birth_md = stoi(arr[i][BIRTH_IDX].substr(2, 5));
			if (birth_md <= min) {

				min = birth_md;

			}
		}
		return min;
	}
}
