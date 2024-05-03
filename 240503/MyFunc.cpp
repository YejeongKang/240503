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
		// ������   2 5   0 0 1 1  3  0
		bool error;
		int ok = 0;
		int name_split_point;
		int age_split_point;
		string input;
		string name;
		string age;
		string birth;

		while (ok == 0) {

			bool error = false; // �߰��� �ѹ� ���� �޼��� ��� �������� ok �ް� ���� �� �ֵ��� error ���� �ʱ�ȭ

			getline(cin, input);

			// �̸� ����
			name_split_point = input.find(" ");

			name = input.substr(0, name_split_point);

			// �̸��� ���ڰ� �ִ��� Ȯ��(���ڸ� 0, �׷��� Ư�����ڵ� 0�� �Ǵ°� ��� �ذ��մϱ� ???)
			// �̸��� ���̴� �������.
			for (char c : name) {

				if (isdigit(c) != 0) {
					cout << "***�Է� ����: �̸��� ���ڷθ� �Է��Ͻÿ�.***" << endl;
					error = true;
					break;
				}
			}

			// ���� ����
			age_split_point = input.find(" ", name_split_point + 1);

			age = input.substr((name_split_point + 1), (age_split_point - name_split_point - 1));

			// ���̰� ���ڷ� �̷�����ִ��� Ȯ��
			// ������ ���̴� �������.
			for (char c : age) {

				if (isdigit(c) == 0) {
					cout << "***�Է� ����: ���̴� ���ڷθ� �Է��Ͻÿ�.***" << endl;
					error = true;
					break;
				}
			}

			// ���� ����
			birth = input.substr(age_split_point + 1);

			// ������ ���̰� �����ڸ����� Ȯ��
			if (birth.length() != 6) {
				cout << "***�Է� ����: ������ ���� �ڸ��� �Է��Ͻÿ�.***" << endl;
				error = true;
			}

			// ���̰� ���ڷ� �̷�����ִ��� Ȯ��
			for (char c : birth) {

				if (isdigit(c) == 0) {
					cout << "***�Է� ����: ������ ���ڷθ� �Է��Ͻÿ�.***" << endl;
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
