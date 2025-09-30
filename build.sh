#!/bin/bash

if [ ! -d "build" ]; then
    mkdir -p build
fi

cd build
cmake ..
cmake --build .
cd ../bin

echo
echo "Збірка завершена успішно"
echo

echo "Файли в директорії bin:"
ls
