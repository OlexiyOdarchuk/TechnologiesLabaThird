#include "ArrayOperations.hpp"

bool ArrayOperations::checkCreated() const {
    if (!isCreated) {
        std::cout << "Помилка: Масив ще не створено" << std::endl;
        return false;
    }
    return true;
}

void ArrayOperations::create() {
    if (isCreated) {
        std::cout << "Помилка: Масив вже створено" << std::endl;
        return;
    }
    std::cout << "Введіть значення елементів масиву:" << std::endl;
    for (int i = 0; i < ARR_LENGTH; i++) {
        std::cout << "Елемент " << i << ": ";
        std::cin >> arr[i];
    }
    isCreated = true;
    std::cout << "Масив на " << ARR_LENGTH << " елементів створено!" << std::endl;
}

void ArrayOperations::print() const {
    if (!checkCreated()) return;
    for (int i = 0; i < ARR_LENGTH; i++)
        std::cout << "Елемент " << i << ": " << arr[i] << std::endl;
}

void ArrayOperations::minElement() const {
    if (!checkCreated()) return;
    int min = arr[0];
    for (int i = 1; i < ARR_LENGTH; i++)
        if (arr[i] < min) min = arr[i];
    std::cout << "Найменший елемент: " << min << std::endl;
}

void ArrayOperations::maxElement() const {
    if (!checkCreated()) return;
    int max = arr[0];
    for (int i = 1; i < ARR_LENGTH; i++)
        if (arr[i] > max) max = arr[i];
    std::cout << "Найбільший елемент: " << max << std::endl;
}

void ArrayOperations::average() const {
    if (!checkCreated()) return;
    double sum = 0;
    for (int i = 0; i < ARR_LENGTH; i++) sum += arr[i];
    std::cout << "Середнє арифметичне: " << sum / ARR_LENGTH << std::endl;
}

void ArrayOperations::sortMin() {
    if (!checkCreated()) return;
    for (int i = 0; i < ARR_LENGTH - 1; i++)
        for (int j = 0; j < ARR_LENGTH - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
    std::cout << "Масив відсортовано за зростанням!" << std::endl;
}

void ArrayOperations::sortMax() {
    if (!checkCreated()) return;
    for (int i = 0; i < ARR_LENGTH - 1; i++)
        for (int j = 0; j < ARR_LENGTH - i - 1; j++)
            if (arr[j] < arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
    std::cout << "Масив відсортовано за спаданням!" << std::endl;
}
