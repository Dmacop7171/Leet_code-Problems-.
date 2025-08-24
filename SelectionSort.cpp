// 🔹 Selection Sort Algorithm

// Selection Sort works by repeatedly selecting the smallest (or largest) element from the unsorted portion and putting it in its correct position.

// ⚡ Steps:

// Start from index i = 0.

// Find the minimum element from the unsorted part i … n-1.

// Swap it with the element at index i.

// Increment i and repeat until the array is sorted.

// 📊 Example

// Array: [29, 10, 14, 37, 14]

// Pass 1: Minimum from [29,10,14,37,14] → 10 → swap with 29 → [10,29,14,37,14]

// Pass 2: Minimum from [29,14,37,14] → 14 → swap with 29 → [10,14,29,37,14]

// Pass 3: Minimum from [29,37,14] → 14 → swap with 29 → [10,14,14,37,29]

// Pass 4: Minimum from [37,29] → 29 → swap with 37 → [10,14,14,29,37]
// ✅ Sorted!

// 🖥️ C++ Implementation
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {29, 10, 14, 37, 14};
    selectionSort(arr);
    for(int x : arr) cout << x << " ";
    return 0;
}
