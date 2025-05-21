#ifndef INPLACE_MERGESORT_H
#define INPLACE_MERGESORT_H

#include<vector>

struct InPlace_MergeSort{
    static void merge(std::vector<int> &arr, int left, int mid, int right) {
        int start1 = left, start2 = mid + 1;
        while(start1 <= mid && start2 <= right) {
            if(arr[start1] <= arr[start2]) ++start1;
            else {
                int val = arr[start2], idx = start2;
                while(idx > start1) arr[idx] = arr[idx - 1], --idx;
                arr[idx] = val;
                ++start1; ++mid; ++start2;
            }
        }
    }

    static void sort(std::vector<int> &arr, int left, int right) {
        if(left < right) {
            int mid = (left + right) >> 1;
            sort(arr, left, mid);
            sort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    static void sort(std::vector<int> &arr, int n) {
        sort(arr, 0, n - 1);
    }
};

#endif