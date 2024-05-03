#include <iostream>
#include <string>

#include "MyFunc.h"

using namespace std;
using namespace calculatingData;
using namespace inputData;

#define INFO_COLUMN 3
#define NAME_IDX 0
#define AGE_IDX 1
#define BIRTH_IDX 2

//1. ����ڿ��� �� ���� �л��� �Է��� ������ ����
//2. �л� �� ��ŭ �̸� ���� ����" ������ �ѹ��� �Է� �ޱ�
//3. 1) �л� ���� ���, 2) ��� ����, 3) ���� ���� ����, 4) ���α׷� ����, �� ���� ��ɿ� ��� ����
//4. ���ݱ��� ��� �ڷᱸ��(�迭, ����, ����Ʈ), ���ڿ�(��Ʈ��) �� �����Ӱ� Ȱ�� �Ͽ� �ۼ� ~�ۼ� ���� � ����� ��� �������� ���� ���ϰ� �ۼ� �����ϱ�~
//5. * �ð��� ������ * ���� ó��, �ּ�, �ڵ� ���� ���� �ǽ��Ͽ� �ϼ����� ���̱�

// <�߰� ����>
// save_st_info() �κп��� ����� �Է��� �ùٸ��� üũ�ϴ� ����� �־��ּ���!
// �̸�, ����, ������Ͽ� ���� ���̵���ο� �°� �����Ͱ� ���Դ��� üũ�� ���ֽø� �˴ϴ�!
// �������� ��������
// ���̴� ��ġ�ϴ��� ��
// 
// �л����� �˻� �� ���� ����� �߰����ּ���!
// �л����� �˻� : 1) �̸�, 2)����, 3)������� �� ��1 �Ͽ� ���� ���� ���� �л� ���� ��� ���!
// �л����� ���� : �л� �̸��� �Է��ϸ� �л� ������ ����ϰ� Ȥ�� ���� �̸��� �л��� �ִٸ� 1�� �����ϵ��� �� ��, ����, ��������� �Է¹޾� �л����� ������Ʈ!


int main() {
	int stnum;
	string early_birth;

	cout << "�Է��� �л��� �� : ";
	cin >> stnum;
	cout << endl;
	cin.ignore();

	// ���� �迭 ����
	string** st_matrix = new string * [stnum + 1];

	for (int i = 0; i < stnum + 1; i++) {

		st_matrix[i] = new string[INFO_COLUMN];

	}

	// �迭 ��ܿ� ������ ���� �Ҵ�
	st_matrix[0][NAME_IDX] = "�̸�";
	st_matrix[0][AGE_IDX] = "����";
	st_matrix[0][BIRTH_IDX] = "�������";

	// 2) �л� ���� �Է¹��� �� �迭�� �����ϴ� �Լ� ȣ��
	cout << stnum << " ���� �л��� �̸�, ����, ��������� ������� �Է��Ͻÿ�. (ex: ������ 20 050101)" << endl << endl;

	for (int i = 1; i < stnum + 1; i++) {
		InputInfo(st_matrix, i);
	}

	// 3 - 1) �л� ���� ���
	for (int i = 0; i < stnum + 1; i++) {

		cout << endl;

		for (int j = 0; j < INFO_COLUMN; j++) {

			cout << st_matrix[i][j] << "\t";

		}
	}
	cout << endl << endl;

	// 3 - 2) ��� ���� ���
	cout << "�л��� ��� ���̴� : " << get_avg(st_matrix, stnum) << endl << endl;

	// 3 - 3) ���� ���� ���� ���
	early_birth = to_string(get_early_birth(st_matrix, stnum));
	cout << "���� ���� ������ : " << early_birth.substr(0, 2) << " / " << early_birth.substr(2, 2) << endl << endl;

	// 3 - 4) �迭 ���� �� ���α׷� ����
	for (int i = 0; i < stnum + 1; i++) {
		delete[] st_matrix[i];
	}
	delete[] st_matrix;

	return 0;
}
