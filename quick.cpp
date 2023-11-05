#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int deterministicPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int randomizedPartition(int arr[], int low, int high) {
    srand(time(nullptr));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);

    return deterministicPartition(arr, low, high);
}

void deterministicQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = deterministicPartition(arr, low, high);

        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);

        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    int deterministicArr[n];
    int randomizedArr[n];

    
        // cout << "Enter " << n << " integers: ";
        // for (int i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }
    
    for (int i = 0; i < n; i++) {
        deterministicArr[i] = arr[i];
        randomizedArr[i] = arr[i];
    }

    clock_t deterministicStart = clock();
    deterministicQuickSort(deterministicArr, 0, n - 1);
    clock_t deterministicEnd = clock();

    clock_t randomizedStart = clock();
    randomizedQuickSort(randomizedArr, 0, n - 1);
    clock_t randomizedEnd = clock();

    cout << "Original Array: ";
    printArray(arr, n);

    cout << "Deterministic Quick Sort: ";
    printArray(deterministicArr, n);
    cout << "Time taken by Deterministic Quick Sort: " << (double)(deterministicEnd - deterministicStart) / CLOCKS_PER_SEC << " seconds" << endl;

    cout << "Randomized Quick Sort: ";
    printArray(randomizedArr, n);
    cout << "Time taken by Randomized Quick Sort: " << (double)(randomizedEnd - randomizedStart) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
