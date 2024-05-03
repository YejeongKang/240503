#pragma once

#include <string>

using namespace std;

namespace inputData{
	void InputInfo(string** arr, int i);
}

namespace calculatingData {
	float get_avg(string** arr, int num);
	int get_early_birth(string** arr, int num);

}

