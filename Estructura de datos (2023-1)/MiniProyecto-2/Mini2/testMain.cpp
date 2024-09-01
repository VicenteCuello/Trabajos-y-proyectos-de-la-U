#include "QuadTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#define ARCHIVE "worldcitiespop_fixed.csv"
using namespace std;

vector<City> readFile(const string& filename, int limite) {
    vector<City> cities;
    ifstream file(filename);
    if (!file) {
        cerr << "No se pudo abrir el archivillo :)" << filename << endl;
        return cities;
    }

    ifstream archivo(ARCHIVE);
    string line;
    char limit = ';';
    getline(archivo, line);
    int count = 0;

    while(getline(archivo, line) && count < limite){

        stringstream stream(line);
        City auxCity;
        string aux;
        getline(stream, aux, limit);
        auxCity.country = aux;

        getline(stream, aux, limit);
        auxCity.name = aux;

        getline(stream, aux, limit);
        auxCity.accentCity = aux;

        getline(stream, aux, limit);
        auxCity.region = aux;

        getline(stream, aux, limit);
        auxCity.population = stoi(aux);

        getline(stream, aux, limit);
        auxCity.latitude = stod(aux);

        getline(stream, aux, limit);
        auxCity.longitude = stod(aux);
        auxCity.geopoints = Point(auxCity.latitude, auxCity.longitude);
        getline(stream, aux, limit);

        cities.push_back(auxCity);
        count++;
    }

    archivo.close();
    return cities;
}


int main(){
    int limite = 20;
    vector<City> constantinopla =   readFile(ARCHIVE, limite);

    /*
    for (const auto& city : constantinopla) {
        cout << "Pais: " << city.country << endl;
        cout << "Nombre de la ciudad: " << city.name << endl;
        cout << "Acento: " << city.accentCity << endl;
        cout << "Población: " << city.population << endl;
        cout << "Region: " << city.region << endl;
        cout << "Latitud: " <<  city.latitude << endl;
        cout << "Longitud: " << city.longitude << endl;
        cout << "Geopoint: " << city.geopoints.x << ", " << city.geopoints.y << endl;
        cout << "------------------------------------------------" << endl;
    }
    */
    return 0;
}