#include "ArrayApp.hpp"

void ArrayApp::printMenu() const {
    std::cout << "ОПЕРАЦІЇ З МАСИВАМИ: " << std::endl << std::endl
              << "1) Ввести значення елементів масиву" << std::endl
              << "2) Вивести значення елементів масиву" << std::endl
              << "3) Обчислення мінімального елементу" << std::endl
              << "4) Обчислення максимального елементу" << std::endl
              << "5) Обчислення середнього арифметичного" << std::endl
              << "6) Відсортувати масив за зростанням" << std::endl
              << "7) Відсортувати масив за спаданням" << std::endl
              << "8) Вийти" << std::endl;
}

void ArrayApp::run() {
    char choose;
    printMenu();

    while (true) {
        std::cout << std::endl << "Оберіть операцію (1-8): ";
        std::cin >> choose;
        if (choose == '8') {
            std::cout << "Вихід..." << std::endl;
            return;
        }

        switch (choose) {
            case '1': arrayOps.create(); break;
            case '2': arrayOps.print(); break;
            case '3': arrayOps.minElement(); break;
            case '4': arrayOps.maxElement(); break;
            case '5': arrayOps.average(); break;
            case '6': arrayOps.sortMin(); break;
            case '7': arrayOps.sortMax(); break;
            default:
                std::cout << "Помилка: невідома операція" << std::endl;
                break;
        }
    }
}
