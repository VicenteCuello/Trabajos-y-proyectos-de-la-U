#include "Array.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

int main() {
    vector<int> ns = {10000, 100000, 1000000, 10000000};
    vector<int> bs = {10000001};

    for (int n : ns) {
        for (int b : bs) {
            auto start = high_resolution_clock::now();

            Array lista(b);


            for (int i = 0; i < n; i++) {
                Array lista(b);
                lista.insert_left(i);
            }

            

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);

           
            cout << "n=" << n << " b=" << b << " Tiempo: " << duration.count() << " ms" << endl;
        }
    }

    return 0;
}

