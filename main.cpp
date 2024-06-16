#include <iostream>
#include <fstream>

#include "utils.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "data_generator.h"

using namespace std;

/**
 * argc: arguments count
 * argv: arguments values 
 */
int main(int argc, char **argv) {
    // Vi du chay utils.h#benchmark
    ofstream out("output.txt");

    int *a = new int[500000];
    GenerateReverseData(a, 10000);
    int ns[] = {100, 1000, 5000, 10000, 50000, 500000};
    for (int i = 0; i < 6; ++i) {
        int n = ns[i];
        int *b = new int[n];
        for (int j = 0; j < n; ++j) {
            b[j] = a[j];
        }

        RunInfo run = benchmark(b, n, countingSort);
        out << run.elapsed_time << "\n";
        delete[] b;
    }

    delete[] a;
    out.close();
    return 0;
}