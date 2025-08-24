// 🔹 Bubble Sort

// A comparison-based sorting algorithm where the largest (or smallest) element "bubbles up" to the end in each pass.

// Working Principle

// Compare adjacent elements.

// If they are in the wrong order → swap them.

// Repeat this process until no swaps are needed.

// With each pass, the largest element moves to its correct position at the end.

// Example

// Array = [5, 3, 8, 4, 2]

// Pass 1: [3, 5, 4, 2, 8] → (8 bubbled to end)

// Pass 2: [3, 4, 2, 5, 8]

// Pass 3: [3, 2, 4, 5, 8]

// Pass 4: [2, 3, 4, 5, 8] → Sorted ✅

// Code (C++ Example)
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization: stop if already sorted
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    bubbleSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}

// Time & Space Complexity

// Best Case (Already Sorted): O(n) (with optimization)

// Average Case: O(n²)

// Worst Case: O(n²)

// Space: O(1) (In-place)

// ✅ Good for teaching purposes, but inefficient in practice → rarely used in real-world systems.
