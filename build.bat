@echo off

if not exist build (
    mkdir build
)

cd build

cmake ..
cmake --build .

cd ..
cd bin

echo.
echo Збірка завершена успішно
echo.

echo Файли в директорії bin:
dir /b
pause
