#pragma once
#include <iostream>
#include <string>
using namespace std;
double* getInput(int& index, int& size);
bool isNumber(char c);
bool isLegal(double* num);
void updateArrays(double* arr, int size, double* insertArr, double* selectArr, double* fifth);
int suffixLength(string str);
string trimStr(string str);
void isValidStr(string str);