#include <iostream>

constexpr int ARR_LENGTH = 5;

class ArrayOperations {
    private:
        int arr[ARR_LENGTH];
        bool isCreated{false};

        bool checkCreated() const {
            if (!isCreated) {
                std::cout << "Помилка: Масив ще не створено" << std::endl;
                return false;
            }
            return true;
        }

    public:
        void create() {
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

        void print() const {
            if (!checkCreated()) return;
            for (int i = 0; i < ARR_LENGTH; i++) {
                std::cout << "Елемент " << i << ": " << arr[i] << std::endl;
            }
        }

        void minElement() const {
            if (!checkCreated()) return;
            int min = arr[0];
            for (int i = 1; i < ARR_LENGTH; i++)
                if (arr[i] < min)
                    min = arr[i];
            std::cout << "Найменший елемент: " << min << std::endl;
        }

        void maxElement() const {
            if (!checkCreated()) return;
            int max = arr[0];
            for (int i = 1; i < ARR_LENGTH; i++)
                if (arr[i] > max) max = arr[i];
            std::cout << "Найбільший елемент: " << max << std::endl;
        }

        void average() const {
            if (!checkCreated()) return;
            double sum = 0;
            for (int i = 0; i < ARR_LENGTH; i++) sum += arr[i];
            std::cout << "Середнє арифметичне: " << sum / ARR_LENGTH << std::endl;
        }

        void sortMin() {
            if (!checkCreated()) return;
            for (int i = 0; i < ARR_LENGTH - 1; i++)
                for (int j = 0; j < ARR_LENGTH - i - 1; j++)
                    if (arr[j] > arr[j + 1])
                        std::swap(arr[j], arr[j + 1]);
            std::cout << "Масив відсортовано за зростанням!" << std::endl;
        }

        void sortMax() {
            if (!checkCreated()) return;
            for (int i = 0; i < ARR_LENGTH - 1; i++)
                for (int j = 0; j < ARR_LENGTH - i - 1; j++)
                    if (arr[j] < arr[j + 1])
                        std::swap(arr[j], arr[j + 1]);
            std::cout << "Масив відсортовано за спаданням!" << std::endl;
        }
};

class ArrayApp {
    private:
        ArrayOperations arrayOprs;

        void printMenu() const {
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

    public:
        void run() {
            char choose;
            printMenu();

            while (true) {
                std::cout << std::endl << "Оберіть операцію (1-8): ";
                std::cin >> choose;
                if (choose == '8') {
                    std::cout << "Вихід..." << std::endl;
                    break;
                }
                switch (choose) {
                    case '1': arrayOprs.create(); break;
                    case '2': arrayOprs.print(); break;
                    case '3': arrayOprs.minElement(); break;
                    case '4': arrayOprs.maxElement(); break;
                    case '5': arrayOprs.average(); break;
                    case '6': arrayOprs.sortMin(); break;
                    case '7': arrayOprs.sortMax(); break;
                    default:
                        std::cout << "Помилка: невідома операція" << std::endl;
                        break;
                }
            }
        }
};

int main() {
    ArrayApp app;
    app.run();
}
