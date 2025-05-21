#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;

#include "OutOfPlace_MergeSort.h"
#include "InPlace_MergeSort.h"
#include "Natural_MergeSort.h"


int main() {

    int n;
    std::cout <<  "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements:\n";
    for(int &x : arr) std::cin >> x;

    std::vector<int> outofplace_arr = arr;
    std::vector<int> inplace_arr = arr;
    std::vector<int> natural_arr = arr;

    auto time0 = high_resolution_clock::now();
    OutOfPlace_MergeSort::sort(outofplace_arr, n);
    auto time1 = high_resolution_clock::now();
    InPlace_MergeSort::sort(inplace_arr, n);
    auto time2 = high_resolution_clock::now();
    Natural_MergeSort::sort(natural_arr, n);
    auto time3 = high_resolution_clock::now();

    double OutofplaceMergeSortTime  = duration_cast<microseconds>(time1 - time0).count();
    double InplaceMergeSortTime     = duration_cast<microseconds>(time2 - time1).count();
    double NaturalMergeSortTime     = duration_cast<microseconds>(time3 - time2).count();

    std::cout << "\nOut-of-place Merge Sort:" << '\n';
    std::cout << "Result: ";
    for(int x : outofplace_arr) std:: cout << x << ' ';
    std::cout << '\n' << "Out-of-place Merge Sort Time: " << OutofplaceMergeSortTime << " microseconds\n";

    std::cout << "\nIn-place Merge Sort:" << '\n';
    std::cout << "Result: ";
    for(int x : inplace_arr) std:: cout << x << ' ';
    std::cout << '\n' << "In-place Merge Sort Time: " << InplaceMergeSortTime << " microseconds\n";

    std::cout << "\nNatural Merge Sort:" << '\n';
    std::cout << "Result: ";
    for(int x : natural_arr) std:: cout << x << ' ';
    std::cout << '\n' << "Natural Merge Sort Time: " << NaturalMergeSortTime << " microseconds\n";

    return 0;
}