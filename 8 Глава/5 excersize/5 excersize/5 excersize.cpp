#include <iostream>

static const int SIZE_NUMBERS = 5;
template <typename T> T max5(T numbers[SIZE_NUMBERS]);

int main()
{
    double numbers[SIZE_NUMBERS] = { 1, 3, 5, 7, -8 };
    std::cout << max5(numbers) << std::endl;
}

template <typename T> T max5(T numbers[SIZE_NUMBERS]) {
    T max = numbers[0];

    for (int i = 1; i < SIZE_NUMBERS; ++i)
        if (numbers[i] > max) max = numbers[i];

    return max;
}