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

//1. 사용자에게 몇 명의 학생을 입력할 것인지 묻기
//2. 학생 수 만큼 이름 나이 생일" 순서로 한번에 입력 받기
//3. 1) 학생 정보 출력, 2) 평균 나이, 3) 가장 빠른 생일, 4) 프로그램 종료, 네 가지 기능올 모두 구현
//4. 지금까지 배운 자료구조(배열, 벡터, 리스트), 문자열(스트링) 등 자유롭게 활용 하여 작성 ~작성 전에 어떤 기능을 어떻게 구현할지 먼저 정하고 작성 시작하기~
//5. * 시간이 남으면 * 예외 처리, 주석, 코드 정리 등을 실시하여 완성도를 높이기

// <추가 과제>
// save_st_info() 부분에서 사용자 입력이 올바른지 체크하는 기능을 넣어주세요!
// 이름, 나이, 생년월일에 대한 가이드라인에 맞게 데이터가 들어왔는지 체크를 해주시면 됩니다!
// 문자인지 숫자인지
// 길이는 일치하는지 등
// 
// 학생정보 검색 및 수정 기능을 추가해주세요!
// 학생정보 검색 : 1) 이름, 2)나이, 3)생년월일 중 택1 하여 같은 값을 가진 학생 정보 모두 출력!
// 학생정보 수정 : 학생 이름을 입력하면 학생 정보를 출력하고 혹시 같은 이름의 학생이 있다면 1명만 선택하도록 한 뒤, 나이, 생년월일을 입력받아 학생정도 업데이트!


int main() {
	int stnum;
	string early_birth;

	cout << "입력할 학생의 수 : ";
	cin >> stnum;
	cout << endl;
	cin.ignore();

	// 동적 배열 선언
	string** st_matrix = new string * [stnum + 1];

	for (int i = 0; i < stnum + 1; i++) {

		st_matrix[i] = new string[INFO_COLUMN];

	}

	// 배열 상단에 정보의 종류 할당
	st_matrix[0][NAME_IDX] = "이름";
	st_matrix[0][AGE_IDX] = "나이";
	st_matrix[0][BIRTH_IDX] = "생년월일";

	// 2) 학생 정보 입력받은 뒤 배열에 저장하는 함수 호출
	cout << stnum << " 명의 학생의 이름, 나이, 생년월일을 순서대로 입력하시오. (ex: 리더님 20 050101)" << endl << endl;

	for (int i = 1; i < stnum + 1; i++) {
		InputInfo(st_matrix, i);
	}

	// 3 - 1) 학생 정보 출력
	for (int i = 0; i < stnum + 1; i++) {

		cout << endl;

		for (int j = 0; j < INFO_COLUMN; j++) {

			cout << st_matrix[i][j] << "\t";

		}
	}
	cout << endl << endl;

	// 3 - 2) 평균 나이 출력
	cout << "학생의 평균 나이는 : " << get_avg(st_matrix, stnum) << endl << endl;

	// 3 - 3) 가장 빠른 생일 출력
	early_birth = to_string(get_early_birth(st_matrix, stnum));
	cout << "가장 빠른 생일은 : " << early_birth.substr(0, 2) << " / " << early_birth.substr(2, 2) << endl << endl;

	// 3 - 4) 배열 해제 후 프로그램 종료
	for (int i = 0; i < stnum + 1; i++) {
		delete[] st_matrix[i];
	}
	delete[] st_matrix;

	return 0;
}
