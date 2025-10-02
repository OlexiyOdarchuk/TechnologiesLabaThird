#include <iostream>
#include <string>

constexpr int ARR_LENGTH = 5;

void chooseOperation(const char chose, bool &isCreate, int arr[ARR_LENGTH]);

int main() {

  bool isCreate{false};
  int arr[ARR_LENGTH];
  char choose;
  std::cout << "ОПЕРАЦІЇ З МАСИВАМИ: " << std::endl
            << std::endl
            << "1) Ввести значення елементів масиву" << std::endl
            << "2) Вивести значення елементів масиву" << std::endl
            << "3) Обчислення мінімального елементу" << std::endl
            << "4) Обчислення максимального елементу" << std::endl
            << "5) Обчислення середнього арифметичного" << std::endl
            << "6) Відсортувати масив за зростанням" << std::endl
            << "7) Відсортувати масив за спаданням" << std::endl
            << "8) Вийти" << std::endl;
  while (true) {
    std::cout << std::endl << "Оберіть операцію (1-8): ";
    std::cin >> choose;
    if (choose != '8') {
      chooseOperation(choose, isCreate, arr);
    } else {
      std::cout << "Вихід..." << std::endl;
      break;
    }
  }
}

void createArr(int arr[ARR_LENGTH]) {
  std::cout << "Введіть значення елементів масиву:" << std::endl;
  for (int i = 0; i < ARR_LENGTH; i++) {
    while (true) {
      std::cout << "Елемент " << i << ": ";
      if (std::cin >> arr[i]) {
        break;
      } else {
        std::cout << "Помилка: введіть ціле число!" << std::endl;
        std::cin.clear();
        std::string trash;
        std::getline(std::cin, trash);
      }
    }
  }
  std::cout << "Масив на " << ARR_LENGTH << " елементів (0-" << ARR_LENGTH - 1
            << ") створено!" << std::endl;
}

void writeElements(const int arr[ARR_LENGTH]) {
  for (int i = 0; i < ARR_LENGTH; i++) {
    std::cout << "Елемент " << i << ": " << arr[i] << std::endl;
  }
}

int minElemArr(const int arr[ARR_LENGTH]) {
  int min{arr[0]};
  for (int i = 1; i < ARR_LENGTH; i++) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return min;
}

int maxElemArr(const int arr[ARR_LENGTH]) {
  int max{arr[0]};
  for (int i = 1; i < ARR_LENGTH; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

double calculateAverage(const int arr[ARR_LENGTH]) {
  double sum{0};
  for (int i = 0; i < ARR_LENGTH; i++) {
    sum += arr[i];
  }
  return sum / ARR_LENGTH;
}

void swap(int &elem1, int &elem2) {
  int temp = elem1;
  elem1 = elem2;
  elem2 = temp;
}

void sortArrMin(int arr[ARR_LENGTH]) {
  for (int i = 0; i < ARR_LENGTH - 1; i++) {
    for (int j = 0; j < ARR_LENGTH - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void sortArrMax(int arr[ARR_LENGTH]) {
  for (int i = 0; i < ARR_LENGTH - 1; i++) {
    for (int j = 0; j < ARR_LENGTH - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
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

void chooseOperation(const char choose, bool &isCreate, int arr[ARR_LENGTH]) {
  switch (choose) {
  case '1':
    if (!isCreate) {
      createArr(arr);
      isCreate = true;
      break;
    } else {
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
      std::cout << "Найбільший елемент масиву: " << maxElemArr(arr)
                << std::endl;
    break;
  case '5':
    if (requireCreated(isCreate))
      std::cout << "Середнє арифметичне по елементах масиву: "
                << calculateAverage(arr) << std::endl;
    break;
  case '6':
    if (requireCreated(isCreate)) {
      sortArrMin(arr);
      std::cout << "Масив відсортований успішно!" << std::endl;
    }
    break;
  case '7':
    if (requireCreated(isCreate)) {
      sortArrMax(arr);
      std::cout << "Масив відсортований успішно!" << std::endl;
    }
    break;
  default:
    std::cout << "Помилка: Невідома операція" << std::endl;
    break;
  }
}
