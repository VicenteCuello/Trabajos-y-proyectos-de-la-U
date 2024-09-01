#include "QuadTree.h"
#include <iostream>
using namespace std;

int main(){
    Point topLeft(-200.0, -200.0);
    Point bottomRight(200.0, 200.0);
    QuadTree* quadTree = new QuadTree(topLeft, bottomRight);

    City city1;
    city1.country = "Chile";
    city1.name = "Rancagua";
    city1.accentCity = "Cachapoal";
    city1.region = "Libertador Bernardo Ohiggins";
    city1.population = 5;
    city1.latitude = 40;
    city1.longitude = 40;
    Point point1(city1.longitude, city1.latitude);
    quadTree->insert(point1, city1);
 
    City city2;
    city2.country = "United Kingdom";
    city2.name = "London";
    city2.accentCity = "alfa romeo";
    city2.region = "England";
    city2.population = 5;
    city2.latitude = 51;
    city2.longitude = 49;
    Point point2(city2.longitude, city2.latitude);
    quadTree->insert(point2, city2);

    City city3;
    city3.country = "Belgica";
    city3.name = "Francorchamps";
    city3.accentCity = "mclaren";
    city3.region = "Stavelot";
    city3.population = 5;
    city3.latitude = 31;
    city3.longitude = 121;
    Point point3(city3.longitude, city3.latitude);
    quadTree->insert(point3, city3);

    City city4;
    city4.country = "Paises Bajos";
    city4.name = "Zandvoort";
    city4.accentCity = "mercedes";
    city4.region = "Septenrional";
    city4.population = 5;
    city4.latitude = 11;
    city4.longitude = 90;
    Point point4(city4.longitude, city4.latitude);
    quadTree->insert(point4, city4);

    City city5;
    city5.country = "Belgica";
    city5.name = "Francorchamps";
    city5.accentCity = "williams";
    city5.region = "Stavelot";
    city5.population = 5;
    city5.latitude = -40;
    city5.longitude = -170;
    Point point5(city5.longitude, city5.latitude);
    quadTree->insert(point5, city5);
    
    cout << "Total de puntos: " << quadTree->totalPoints() << endl;
    cout << "Total de nodos: " << quadTree->totalNodes() << endl;
    vector<City>* list = quadTree->list();
    

    Point testPoint(0, 0);
    double distance = 100;
    
    int count = quadTree->countRegion(testPoint, distance);
    cout << "Número de nodos en la región: " << count << endl;
    int count2 = quadTree->aggregateRegion(testPoint, distance);
    cout << "Número de population en la región: " << count2 << endl;

    return 0;    
}