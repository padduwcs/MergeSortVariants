#ifndef NATURAL_MERGESORT_H
#define NATURAL_MERGESORT_H

#include<vector>

struct Natural_MergeSort{
    static void merge(std::vector<int> &arr, int left, int mid, int right) {
        std::vector<int> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while(i <= mid && j <= right) 
            tmp[k++] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
        while(i <= mid) tmp[k++] = arr[i++];
        while(j <= right) tmp[k++] = arr[j++];
        
        for(int p = 0; p < (int)tmp.size(); ++p) arr[left + p] = tmp[p];
    }

    static int findRunEnd(std::vector<int>& arr, int start, int n) {
        int end = start;
        while (end < n - 1 && arr[end] <= arr[end + 1]) ++end;
        int i = end + 1, j = end + 1;
        while (j < n - 1 && arr[j] > arr[j + 1]) j++;
        while (i < j) {
            std::swap(arr[i], arr[j]);
            i++; j--;
        }
        return end;
    }

    static void sort(std::vector<int> &arr, int n) {
        if(n <= 1) return;

        while (true) {
            int left = 0;
            int merged_runs = 0;

            while (left < n) {
                int mid = findRunEnd(arr, left, n);
                if (mid == n - 1) break;

                int right = findRunEnd(arr, mid + 1, n);
                merge(arr, left, mid, right);
                ++merged_runs;

                left = right + 1;
            }

            if(merged_runs == 0) break;
        }

    }
};

#endif