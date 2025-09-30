#include <iostream>
#include "array_operations.hpp"

int main(){
    bool isCreate{false};
    int arr[ARR_LENGTH];
    char choose;

    std::cout << "ОПЕРАЦІЇ З МАСИВАМИ: " << std::endl << std::endl
              << "1) Ввести значення елементів масиву" << std::endl
              << "2) Вивести значення елементів масиву" << std::endl
              << "3) Обчислення мінімального елементу" << std::endl
              << "4) Обчислення максимального елементу" << std::endl
              << "5) Обчислення середнього арифметичного" << std::endl
              << "6) Відсортувати масив за зростанням" << std::endl
              << "7) Відсортувати масив за спаданням" << std::endl
              << "8) Вийти" << std::endl;

    while(true){
        std::cout << std::endl <<"Оберіть операцію (1-8): ";
        std::cin >> choose;
        if (choose != '8'){
            chooseOperation(choose, isCreate, arr);
        } else {
            std::cout << "Вихід..." << std::endl;
            break;
        }
    }
}
