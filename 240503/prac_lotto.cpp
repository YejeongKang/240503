#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int randNum;
	int pickNum;
	int lottoNumArray[6];
	bool pickOK;
	int ball = 0;

	while (ball < 6) {

		// 1 ~ 45 사이의 난수 생성
		srand(time(NULL));

		randNum = rand();

		pickNum = randNum % 45 + 1;

		for (int ltnum : lottoNumArray) {

			if (pickNum == ltnum) {
				pickOK = false;
				break;
			}
			else {
				pickOK = true;
			}
		}

		if (pickOK == true) {

			lottoNumArray[ball] = pickNum;
			ball++;

		}
	}
	cout << "[이번 회차 로또 당첨 번호]" << endl;

	for (int ltnum : lottoNumArray) {
		cout << ltnum << " ";
	}
	
}