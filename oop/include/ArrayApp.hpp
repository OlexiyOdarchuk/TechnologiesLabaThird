#pragma once
#include "ArrayOperations.hpp"

class ArrayApp {
private:
    ArrayOperations arrayOps;
    void printMenu() const;

public:
    void run();
};
