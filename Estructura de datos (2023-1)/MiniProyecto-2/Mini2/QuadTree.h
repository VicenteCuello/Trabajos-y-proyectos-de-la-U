#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
using namespace std;

class QuadTree{
    private:
        Point leftU, rightL;
        City ciudad;
        vector<City>* notInserted;
        QuadTree* Quad1;
        QuadTree* Quad2;
        QuadTree* Quad3;
        QuadTree* Quad4;
        bool type;
    public:
        QuadTree(Point, Point);
        ~QuadTree();
        int totalPoints();
        int totalNodes();
        void insert(Point, City);
        vector<City>* search(QuadTree*, vector<City>*);
        vector<City>* list();
        int countRegion(Point, int);
        int aggregateRegion(Point, int);
};