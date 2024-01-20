#include <iostream>

void calculateSumAndAverage(int* array, int size, int* sum, double* average) {
    *sum = 0;
    for (int i = 0; i < size; i++) {
        *sum += array[i];
    }
    *average = static_cast<double>(*sum) / size;
}

int main() {
    setlocale(LC_ALL, "ru");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* array = new int[size];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    int sum;
    double average;
    calculateSumAndAverage(array, size, &sum, &average);

    std::cout << "Сумма элементов массива: " << sum << std::endl;
    std::cout << "Среднее значение элементов массива: " << average << std::endl;

    delete[] array;

    return 0;
}