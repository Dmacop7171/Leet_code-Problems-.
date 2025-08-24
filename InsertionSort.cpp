// 🔹 Idea

// Insertion sort works the way we sort playing cards in our hand:

// Pick a card (element) one by one.

// Place it in the correct position among already sorted cards (subarray).

// 🔹 Algorithm

// Start from index 1 (since a single element at index 0 is already "sorted").

// Take the current element (key) and compare it with the elements on its left.

// Shift all elements that are greater than key one position to the right.

// Insert key at its correct position.

// Repeat until the array is sorted.

// 🔹 Example

// Array: [5, 3, 4, 1, 2]

// Step 1: [3, 5, 4, 1, 2] (insert 3 before 5)

// Step 2: [3, 4, 5, 1, 2] (insert 4 between 3 and 5)

// Step 3: [1, 3, 4, 5, 2] (insert 1 at front)

// Step 4: [1, 2, 3, 4, 5] (insert 2 at correct place)

// Sorted ✅

// 🔹 Code (C++)
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];   // current element
        int j = i - 1;

        // Shift larger elements to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insert key in its correct position
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {5, 3, 4, 1, 2};
    insertionSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}

// 🔹 Complexity

// Best Case (Already Sorted): O(n)

// Worst Case (Reverse Sorted): O(n²)

// Space Complexity: O(1) (in-place sorting)

// Stability: ✅ Yes (does not swap equal elements)
