#include <iostream>
#include "io.h"

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
