#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {

        int minIndex = left;
        int maxIndex = right;

        if (arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        for (int i = left + 1; i < right; i++) {

            if (arr[i] < arr[minIndex])
                minIndex = i;

            else if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        swap(arr[left], arr[minIndex]);

        if (maxIndex == left)
            maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}
