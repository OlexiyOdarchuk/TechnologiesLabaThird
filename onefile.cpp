#include <iostream>
#define ARR_LENGHT 5

void createArr(int* arr);
void writeElements(int* arr);
int minElemArr(int* arr);
int maxElemArr(int* arr);
int midlOfEelems(int* arr);
void sortArrMin(int* arr);
void sortArrMax(int* arr);
void choseOperation(char chose, bool &isCreate, int* arr);

int main(){
    bool isCreate{false};
    int* arr{new int[ARR_LENGHT]};
    char chose;
    std::cout << "ОПЕРАЦІЇ З МАСИВАМИ: " << std::endl << std::endl;
    std::cout << "1) Ввести значення елементів масиву" << std::endl;
    std::cout << "2) Вивести значення елементів масиву" << std::endl;
    std::cout << "3) Обчислення мінімального елементу" << std::endl;
    std::cout << "4) Обчислення максимального елементу" << std::endl;
    std::cout << "5) Обчислення середнього арифметичного" << std::endl;
    std::cout << "6) Відсортувати масив за зростанням" << std::endl;
    std::cout << "7) Відсортувати масив за спаданням" << std::endl;
    std::cout << "8) Вийти" << std::endl;
    while(true){
        std::cout << std::endl <<"Оберіть операцію (1-8): ";
        std::cin >> chose;
        if (chose != '8'){
            choseOperation(chose, isCreate, arr);
        } else {
            std::cout << "Вихід..." << std::endl;
            break;
        }
    }
    delete [] arr;
}

void createArr(int* arr){
    std::cout << "Введіть значення елементів масиву:" << std::endl;
    for (int i = 0; i < ARR_LENGHT; i++){
        std::cout << "Елемент " << i << ": ";
        std::cin >> arr[i];
    }
    std::cout << "Масив на " << ARR_LENGHT << " елементів (0-" << ARR_LENGHT-1 << ") створено!" << std::endl;
}

void writeElements(int* arr){
    for (int i = 0; i < ARR_LENGHT; i++){
        std::cout << "Елемент " << i << ": " << arr[i] << std::endl;
    }
}

int minElemArr(int* arr){
    int min{arr[0]};
    for(int i = 0; i < ARR_LENGHT; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int maxElemArr(int* arr){
    int max{arr[0]};
    for(int i = 0; i < ARR_LENGHT; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int midlOfEelems(int* arr){
    int sum{arr[0]};
    for (int i = 0; i < ARR_LENGHT; i++){
        sum += arr[i];
    }
    return sum / ARR_LENGHT;
}

void sortArrMin(int* arr){
    for (int i = 0; i < ARR_LENGHT - 1; i++){
        for (int j = 0; j < ARR_LENGHT - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void sortArrMax(int* arr){
    for (int i = 0; i < ARR_LENGHT - 1; i++){
        for (int j = 0; j < ARR_LENGHT - i - 1; j++){
            if (arr[j] < arr[j + 1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void choseOperation(char chose, bool &isCreate, int* arr){
    switch(chose){
        case '1':
        if (!isCreate){
            createArr(arr);
            isCreate = true;
            break;
        }
        else{
            std::cout << "Масив вже створено" << std::endl;
            break;
        }
    case '2':
        if (isCreate){
            writeElements(arr);
            break;
        }
        else{
            std::cout << "Масив не створено" << std::endl;
            break;
        }
    case '3':
        if (isCreate){
            std::cout << "Найменший елемент масиву: " << minElemArr(arr) << std::endl;
            break;
        }
        else{
            std::cout << "Масив не створено" << std::endl;
            break;
        }
    case '4':
        if (isCreate){
            std::cout << "Найбільший елемент масиву: " << maxElemArr(arr) << std::endl;
            break;
        }
        else{
            std::cout << "Масив не створено" << std::endl;
            break;
        }
    case '5':
        if (isCreate){
            std::cout << "Середнє арифметичне по елементах масиву: " << midlOfEelems(arr) << std::endl;
            break;
        }
        else{
            std::cout  << "Масив не створено" << std::endl;
            break;
        }
    case '6':
        if (isCreate){
            sortArrMin(arr);
            std::cout << "Масив відсортований успішно!" << std::endl;
            break;
        }
        else{
            std::cout << "Масив не створено" << std::endl;
            break;
        }
    case '7':
        if (isCreate){
            sortArrMax(arr);
            std::cout << "Масив відсортований успішно!" << std::endl;
            break;
        }
        else{
            std::cout << "Масив не створено" << std::endl;
            break;
        }
    default:
        std::cout << "Помилка: Невідома операція" << std::endl;
        break;
    }
}
