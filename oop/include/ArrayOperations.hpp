#pragma once
#include <iostream>

constexpr int ARR_LENGTH = 5;

class ArrayOperations {
private:
    int arr[ARR_LENGTH];
    bool isCreated{false};

    bool checkCreated() const;

public:
    void create();
    void print() const;
    void minElement() const;
    void maxElement() const;
    void average() const;
    void sortMin();
    void sortMax();
};
