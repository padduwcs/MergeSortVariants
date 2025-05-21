#ifndef OUTOFPLACE_MERGESORT_H
#define OUTOFPLACE_MERGESORT_H

#include<vector>

struct OutOfPlace_MergeSort{
    static void merge(std::vector<int> &arr, int left, int mid, int right) {
        std::vector<int> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while(i <= mid && j <= right) 
            tmp[k++] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
        while(i <= mid) tmp[k++] = arr[i++];
        while(j <= right) tmp[k++] = arr[j++];
        
        for(int p = 0; p < (int)tmp.size(); ++p) arr[left + p] = tmp[p];
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