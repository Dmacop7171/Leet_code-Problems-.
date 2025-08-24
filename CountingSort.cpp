// 🔹 Idea

// Counting Sort is a non-comparison sorting algorithm that works when the range of input values (0 … k) is not too large compared to the number of elements (n).
// Instead of comparing, it counts how many times each number appears and then uses this to place them in the correct position.

// 🔹 Steps

// Find the maximum value in the array (max).

// Create a frequency array (count[]) of size max+1 and initialize with 0.

// Traverse the array and increment the frequency of each element.

// Modify count[] so that each element at index i stores the sum of counts up to i (prefix sum).

// This gives the final position of each element.

// Build the output array by placing elements at their correct position (while maintaining stability).

// Copy output back to original array.

// 🔹 Code (C++ Example)
#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();
    int maxVal = *max_element(arr.begin(), arr.end());

    // Step 2: Create count array
    vector<int> count(maxVal + 1, 0);

    // Step 3: Count frequency
    for (int num : arr)
        count[num]++;

    // Step 4: Prefix sum to get positions
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // Step 5: Build output array (stable sort)
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy back
    arr = output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}

// 🔹 Example

// Input:
// [4, 2, 2, 8, 3, 3, 1]

// Count array before prefix sum:
// [0,1,2,0,1,0,0,0,1]

// After prefix sum:
// [0,1,3,3,4,4,4,4,5]

// Final sorted output:
// [1,2,2,3,3,4,8]

// 🔹 Complexity

// Time: O(n + k) (where k = max value)

// Space: O(n + k)

// Stable: Yes
// 
// Best Use Case: When input is integers within a small range (e.g., student marks, ages, etc.).
