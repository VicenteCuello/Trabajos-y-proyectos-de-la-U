#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class DynamicArray {
private:
    int k;

    int calculateK(int n) {
        return ceil(log2(n + 1));
    }

    void resizeArraysIfNeeded() {
        int currentTotalSize = 0;
        for (const auto& array : arrays) {
            currentTotalSize += array.size();
        }
        k = calculateK(currentTotalSize);
        arrays.resize(k);
    }

public:
    vector<vector<double>> arrays;

    DynamicArray(int n) {
        k = calculateK(n);
        arrays.resize(k);
    }

    void insert(double value) {
        vector<double> newArray = {value};

        for (int i = 0; i < k; ++i) {
            if (arrays[i].empty()) {
                arrays[i] = newArray;
                sort(arrays[i].begin(), arrays[i].end());
                return;
            } else {
                newArray.insert(newArray.end(), arrays[i].begin(), arrays[i].end());
                arrays[i].clear();
                sort(newArray.begin(), newArray.end());
                
            }
        }

        
        arrays.push_back(newArray);
        resizeArraysIfNeeded();
    }

    bool search(double value) {
        for (int i = 0; i < k; i++) {
            if (!arrays[i].empty()) {
                int bot = 0;
                int top = arrays[i].size() - 1;

                while (bot <= top) {
                    int mid = bot + (top - bot) / 2;

                    if (arrays[i][mid] == value) {
                        return true;
                    }

                    if (arrays[i][mid] < value) {
                        bot = mid + 1;
                    } else {
                        top = mid - 1;
                    }
                }
            }
        }
        return false;
    }

    void print() {
        for (int i = 0; i < k; i++) {
            std::cout << "A" << i << ": ";
            for (double val : arrays[i]) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int n = 5000;
    DynamicArray da(n);

    
    // Generar promedios aleatorios entre 1.0 y 7.0
    std::srand(std::time(0));
    for (int i = 0; i < n; ++i) {
        double promedio = 1.0 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (7.0 - 1.0)));
        promedio = std::round(promedio * 100.0) / 100.0; // Redondear a dos decimales
        da.insert(promedio);
    }

    da.print();
    
    //Buscar algunos valores y medir tiempos
    std::vector<double> searchValues = {2.50, 4.50, 6.50};
    for (double value : searchValues) {
        if (da.search(value)) {
            std::cout << "Found value: " << value << std::endl;
        } else {
            std::cout << "Value not found: " << value << std::endl;
        }
    }
    for (int i = 0; i < da.arrays.size(); ++i)
    {

        std::cout << "Arreglo" << i+1 << ": " << da.arrays[i].size() << std::endl;
    }

    return 0;
}