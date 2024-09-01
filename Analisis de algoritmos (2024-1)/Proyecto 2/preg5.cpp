#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;


struct Box {
    array<int, 3> dimensions;
    int weight;
    Box(int x, int y, int z, int w) : dimensions({x, y, z}), weight(w) {
        sort(dimensions.rbegin(), dimensions.rend()); 
    }
};


bool compareBoxes(const Box &a, const Box &b) {
    if (a.weight != b.weight)
        return a.weight < b.weight;
    return a.dimensions > b.dimensions; 
}


bool canNest(const Box &caja1, const Box &caja2) {
    return caja1.weight <= caja2.weight &&
           caja1.dimensions[0] <= caja2.dimensions[0] &&
           caja1.dimensions[1] <= caja2.dimensions[1] &&
           caja1.dimensions[2] <= caja2.dimensions[2];
}


int maxNestingBoxes(vector<Box> &boxes) {
    sort(boxes.begin(), boxes.end(), compareBoxes);
    int n = boxes.size();
    vector<int> dp(n, 1);  
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (canNest(boxes[j], boxes[i])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Box> boxes1 = {Box(41, 50, 30, 3), Box(30, 25, 40, 1), Box(40, 49, 30, 2)};
    vector<Box> boxes2 = {Box(40, 50, 30, 2), Box(21, 22, 23, 1), Box(30, 51, 40, 1), Box(41, 49, 30, 3)};
    vector<Box> boxes3 = {Box(10, 10, 10, 1), Box(10, 10, 10, 1), Box(10, 10, 10, 1)};
    cout << "Cantidad de cajas que se pueden anidar en boxes1: " << maxNestingBoxes(boxes1) << endl;  // Salida: 3
    cout << "Cantidad de cajas que se pueden anidar en boxes2: " << maxNestingBoxes(boxes2) << endl;  // Salida: 2
    cout << "Cantidad de cajas que se pueden anidar en boxes3: " << maxNestingBoxes(boxes3) << endl;  // Salida: 2
    return 0;
}
