#include <chrono>
#include <iostream>
#include "utils.h"


using namespace std;

void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

int partition(int a[], int l, int r, int &comparisions) {
    int pivot = a[(l+r)/2];
    int i = l, j = r;
    while (++comparisions && i < j) {
        while (++comparisions && a[i] < pivot) ++i;
        while (++comparisions && a[j] > pivot) --j;

        if (++comparisions && i < j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    return j;
}

int quickSort(int a[], int l, int r) {
    int comparisions = 0; 
    
    if (++comparisions && l >= r) 
        return comparisions;

    int p = partition(a, l, r, comparisions);
    comparisions += quickSort(a, l, p);
    comparisions += quickSort(a, p+1, r);
    return comparisions;
}

int quickSort(int a[], int n) {
    return quickSort(a, 0, n - 1);
}

RunInfo benchmark(int a[], int n, int (*sort)(int a[], int n)) {
    auto start = chrono::steady_clock::now();
    int comparisions = sort(a, n);
    auto end = chrono::steady_clock::now();
    long long elapsed_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    return RunInfo {elapsed_time, comparisions};
}