/*1 SORTED ARRAY FIND ELEMENT*/
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int key, int size){          ----------------- 📘 Learning -----------------
    int low = 0;                                         | 🔎 Problem: Sorted array me ek element    |
    int high = size - 1;                                 |     search karna hai efficiently.        |
                                                          |                                          |
    while(low <= high)                                   | 💡 Binary Search Concept:                 |
    {                                                    | 1. Array sorted hona chahiye.            |
        int mid = (low + (high - low) / 2);              | 2. Har step me mid nikalo.               |
        // int mid = (low + high) / 2;                   | 3. Agar key == arr[mid] → 🎯 found.      |
        // can cause overflow if low+high is large       | 4. Agar key > arr[mid] → 🔼 right search. |
                                                          | 5. Agar key < arr[mid] → 🔽 left search.  |
        if(arr[mid] == key)                              |                                          |
        {                                                | ⚡ Efficiency: O(log n) time complexity.  |
            return mid; // ✅ element found               |    (Linear search se bahut fast).        |
        }                                                |                                          |
        else if (arr[mid] < key)                         | 🛑 Edge Cases:                            |
        {                                                | - Agar array empty ho toh -1 return.     |
            low = mid + 1; // 🔼 search right half        | - Agar key present nahi hai toh -1.      |
        }                                                |                                          |
        else                                             | ✅ Learning: Overflow avoid karne ke liye |
        {                                                |    mid = low + (high-low)/2 use karna.   |
            high = mid - 1; // 🔽 search left half        ----------------------------------------------
        }
    }
    return -1; // ❌ element not found
}

int main (){
    int arr[] = {1,3,5,7,9}; // sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int result = binarySearch(arr, key, size);

    if(result == -1) 
    {
        printf("The targeted key %d is not found in the array", key);
    }
    else 
    {
        printf("The targeted key %d is found at index %d", key, result);
    }
    return 0;
}                                                  ----------------- 📊 Dry Run (key = 7) -----------------
                                                    | Step | low | high | mid | arr[mid] | Comparison | Action  |
                                                    |------|-----|------|-----|----------|------------|---------|
                                                    |  1️⃣  |  0  |  4   |  2  |    5     | 5 < 7      | low=3   |
                                                    |  2️⃣  |  3  |  4   |  3  |    7     | 7 == 7 ✅  | Found@3 |
                                                    ------------------------------------------------------------
