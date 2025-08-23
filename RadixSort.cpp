// 🔹 What is Radix Sort?

// Radix Sort is a non-comparative sorting algorithm that sorts numbers digit by digit (or character by character, for strings).
// It uses a stable sorting algorithm (usually Counting Sort) as a subroutine.

// 🔹 How it Works (Base 10 Example)

// Suppose we want to sort [170, 45, 75, 90, 802, 24, 2, 66].

// Find the max element → 802 → it has 3 digits → we’ll sort digit by digit.

// Sort by least significant digit (LSD → 1’s place)
// Numbers sorted: [170, 90, 802, 2, 24, 45, 75, 66]

// Sort by next digit (10’s place)
// Numbers sorted: [802, 2, 24, 45, 66, 170, 75, 90]

// Sort by most significant digit (100’s place)
// Final sorted: [2, 24, 45, 66, 75, 90, 170, 802]

#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{

    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // using counting sort
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    // count sort for every decimal place
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);
    print(arr, n);
    return 0;
}
