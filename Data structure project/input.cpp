#include "input.h"

double* getInput(int& index, int& size) {
	int i = 0;
	size = 0, index = 0;
	double currNum = 0, *arr;
	while (size <= 0) {
		cin >> size;
		if (size <= 0) {
			cout << "wrong input";
			exit(1);
		}
	}
	arr = new double[size];
	while (index<1 || index>size) {
		cin >> index;
		if (index<1 || index>size) {
			cout << "wrong input";
			exit(1);
		}
	}
	while (i < size) {
		if (isLegal(&currNum)) {
			arr[i++] = currNum;
			cin.clear();
		}
		else {
			cout << "wrong input" << endl;
			exit(1);
		}
	}

	return arr;
}

bool isNumber(char c) {
	return c >= '0' && c <= '9';
}

bool isLegal(double* num) {
	string str;
	cin >> str;
	isValidStr(str);
	str = trimStr(str);
	int suffix = suffixLength(str);
	if (suffix > 5 || suffix == 0)
		return false;
	int size = str.length() + 1;
	char*convertChar = new char[size];
	for (int v = 0; v < size - 1; v++) {
		convertChar[v] = str[v];
	}
	convertChar[size - 1] = '\0';
	*num = atof(convertChar);
	delete[]convertChar;
	return true;
}
void updateArrays(double* arr, int size, double* insertArr, double* selectArr, double* fifth) {
	for (int i = 0; i < size; i++) {
		insertArr[i] = arr[i];
		selectArr[i] = arr[i];
		fifth[i] = arr[i];
	}
}


int suffixLength(string str) {
	int i = 0, size = str.length(), counter = 0;
	while (str[i] != '.'&&i < size) {
		i++;
	}
	if (str[i] == '.') {
		counter++;
		i++;
	}
	while (i < size) {
		counter++;
		i++;
	}
	return counter;
}

string trimStr(string str) {
	int size = str.length(), i = 0;
	int counter = 0;
	while (str[i] != '.'&&i < size) {
		i++;
	}
	i++;
	while (i < size) {
		if (str[i] == '0')
			counter++;
		else
			counter = 0;
		i++;
	}
	if (counter == 0)
		return str;

	str.erase(size - counter, counter);

	return str;
}
void isValidStr(string str)
{
	int i = 0;
	bool isNum;
	while (i < str.length())
	{
		if (str[i] == '.' || str[i] == '-')
			i++;

		isNum = isNumber(str[i]);
		if (!isNum) {
			cout << "wrong input";
			exit(1);
		}
		i++;

	}
}
