#ifndef PrintCombination_H
#define PrintCombination_H
#include <iostream>

void PrintCombination(int* arr, const int& n, const int& r);
void combinationUtil(int arr[], int n, int r, int index, int data[], int i);
#endif