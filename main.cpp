#include <iostream>

using std::cout;
using std::endl;

// Вариант 1: передаем массив как указатель на начало массива
void flipArrA (int *arr, size_t size) {
    for (size_t i{}; i < (size / 2); ++i) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = temp;
    }
}

// Вариант 2: передаем массив как ссылку
template<size_t T>
void flipArrB (int (&arr)[T]) {
    for (size_t i{}; i < T / 2; ++i) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + T - i - 1);
        *(arr + T - i - 1) = temp;
    }
}

template<size_t T>
void printArr (const int (&arr)[T]) {
    for (int i = 0; i < T; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << "Begin:\n";
    printArr(arr);
    flipArrA(arr, sizeof(arr) / sizeof(*arr));
    cout << "Flip as pointer:\n";
    printArr(arr);
    cout << "Flip as reference:\n";
    flipArrB(arr);
    printArr(arr);
}
