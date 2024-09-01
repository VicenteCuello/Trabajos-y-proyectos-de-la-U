#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

int main() {
    vector<int> ns = {10000, 100000, 1000000, 10000000};
    

    for (int n : ns) {
 
            auto start = high_resolution_clock::now();

            LinkedList lista;

            for(int i = 0; i<10000001; i++){
                lista.insert_left(i);

            }


            for (int i = 0; i < n; i++) {
                LinkedList lista;
                lista.find(i);
            }

            

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);

           
            cout << "n=" << n << " Tiempo: " << duration.count() << " ms" << endl;
        
        
        
        }
    

    return 0;
}