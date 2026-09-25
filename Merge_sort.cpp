#include <bits/stdc++.h>
using namespace std;
 
class Solution {
private:
    // Merges two sorted ranges into the original array.
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> leftPart;
        vector<int> rightPart;
 
        // Copy left range to preserve values during merging.
        for (int index = left; index <= mid; index++) {
            leftPart.push_back(arr[index]);
        }
 
        // Copy right range for safe comparison during merging.
        for (int index = mid + 1; index <= right; index++) {
            rightPart.push_back(arr[index]);
        }
 
        int leftIndex = 0;
        int rightIndex = 0;
        int writeIndex = left;
 
        // Compare both ranges until one becomes empty.
        while (leftIndex < leftPart.size() && rightIndex < rightPart.size()) {
            // Take from left on equality to keep sorting stable.
            if (leftPart[leftIndex] <= rightPart[rightIndex]) {
                arr[writeIndex] = leftPart[leftIndex];
                leftIndex++;
            } else {
                arr[writeIndex] = rightPart[rightIndex];
                rightIndex++;
            }
            writeIndex++;
        }
 
        // Copy remaining left values as they are already sorted.
        while (leftIndex < leftPart.size()) {
            arr[writeIndex] = leftPart[leftIndex];
            leftIndex++;
            writeIndex++;
        }
 
        // Copy remaining right values as they are already sorted.
        while (rightIndex < rightPart.size()) {
            arr[writeIndex] = rightPart[rightIndex];
            rightIndex++;
            writeIndex++;
        }
    }
 
    // Divides the range and merges both sorted halves.
    void mergeSortHelper(vector<int>& arr, int left, int right) {
        // A range of zero or one value is already sorted.
        if (left >= right) {
            return;
        }
 
        int mid = left + (right - left) / 2;
 
        // Sort left half before merging.
        mergeSortHelper(arr, left, mid);
 
        // Sort right half before merging.
        mergeSortHelper(arr, mid + 1, right);
 
        // Merge both sorted halves.
        merge(arr, left, mid, right);
    }
 
public:
    // Sorts the array using merge sort.
    vector<int> mergeSort(vector<int>& arr) {
        int n = arr.size();
 
        // Arrays with fewer than two values are already sorted.
        if (n < 2) {
            return arr;
        }
 
        mergeSortHelper(arr, 0, n - 1);
        return arr;
    }
};
 
