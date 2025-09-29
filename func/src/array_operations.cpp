#include "array_operations.h"

void createArr(int arr[ARR_LENGTH]){
    std::cout << "Введіть значення елементів масиву:" << std::endl;
    for (int i = 0; i < ARR_LENGTH; i++){
        std::cout << "Елемент " << i << ": ";
        std::cin >> arr[i];
    }
    std::cout << "Масив на " << ARR_LENGTH << " елементів (0-" << ARR_LENGTH-1 << ") створено!" << std::endl;
}

void writeElements(const int arr[ARR_LENGTH]){
    for (int i = 0; i < ARR_LENGTH; i++){
        std::cout << "Елемент " << i << ": " << arr[i] << std::endl;
    }
}

int minElemArr(const int arr[ARR_LENGTH]){
    int min{arr[0]};
    for(int i = 1; i < ARR_LENGTH; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int maxElemArr(const int arr[ARR_LENGTH]){
    int max{arr[0]};
    for(int i = 1; i < ARR_LENGTH; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

double calculateAverage(const int arr[ARR_LENGTH]){
    double sum{0};
    for (int i = 0; i < ARR_LENGTH; i++){
        sum += arr[i];
    }
    return sum / ARR_LENGTH;
}

void sortArrMin(int arr[ARR_LENGTH]){
    for (int i = 0; i < ARR_LENGTH - 1; i++){
        for (int j = 0; j < ARR_LENGTH - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void sortArrMax(int arr[ARR_LENGTH]){
    for (int i = 0; i < ARR_LENGTH - 1; i++){
        for (int j = 0; j < ARR_LENGTH - i - 1; j++){
            if (arr[j] < arr[j + 1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

bool requireCreated(bool isCreate) {
    if (!isCreate) {
        std::cout << "Помилка: Масив не створено" << std::endl;
        return false;
    }
    return true;
}

void chooseOperation(const char choose, bool &isCreate, int arr[ARR_LENGTH]){
    switch(choose){
        case '1':
            if (!isCreate){
                createArr(arr);
                isCreate = true;
                break;
            }
            else{
                std::cout << "Помилка: Масив вже створено" << std::endl;
                break;
            }
        case '2':
            if (requireCreated(isCreate))
                writeElements(arr);
            break;
        case '3':
            if (requireCreated(isCreate))
                std::cout << "Найменший елемент масиву: " << minElemArr(arr) << std::endl;
            break;
        case '4':
            if (requireCreated(isCreate))
                std::cout << "Найбільший елемент масиву: " << maxElemArr(arr) << std::endl;
            break;
        case '5':
            if (requireCreated(isCreate))
                std::cout << "Середнє арифметичне по елементах масиву: " << calculateAverage(arr) << std::endl;
            break;
        case '6':
            if (requireCreated(isCreate)){
                sortArrMin(arr);
                std::cout << "Масив відсортований успішно!" << std::endl;
            }
            break;
        case '7':
            if (requireCreated(isCreate)){
                sortArrMax(arr);
                std::cout << "Масив відсортований успішно!" << std::endl;
            }
            break;
        default:
            std::cout << "Помилка: Невідома операція" << std::endl;
            break;
    }
}
