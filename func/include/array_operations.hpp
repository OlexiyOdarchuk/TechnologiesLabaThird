#pragma once
#include <iostream>

constexpr int ARR_LENGTH = 5;

void createArr(int arr[ARR_LENGTH]);
void writeElements(const int arr[ARR_LENGTH]);
int minElemArr(const int arr[ARR_LENGTH]);
int maxElemArr(const int arr[ARR_LENGTH]);
double calculateAverage(const int arr[ARR_LENGTH]);
void swap(int& elem1, int& elem2);
void sortArrMin(int arr[ARR_LENGTH]);
void sortArrMax(int arr[ARR_LENGTH]);
bool requireCreated(bool isCreate);
void chooseOperation(const char choose, bool &isCreate, int arr[ARR_LENGTH]);
