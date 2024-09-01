#include"QuadTree.h"
#include <iostream>

QuadTree :: QuadTree(Point a, Point b){
    this->leftU = a;
    this->rightL = b;
    this->notInserted = new vector<City>;
    this->Quad1 = nullptr;
    this->Quad2 = nullptr;
    this->Quad3 = nullptr;
    this->Quad4 = nullptr;
    this->type = false;
}

QuadTree :: ~QuadTree(QuadTree* nodo){
    if (nodo == nullptr)
        return;
    deleteQuadTree(nodo->Quad1);
    deleteQuadTree(nodo->Quad2);
    deleteQuadTree(nodo->Quad3);
    deleteQuadTree(nodo->Quad4);
    delete nodo;
}

int QuadTree :: totalPoints(){
    int count = 0;
    if (Quad1 != nullptr) {
        if (Quad1->type == true) {
            if (abs(Quad1->leftU.x - Quad1->rightL.x) <= 1 && abs(Quad1->leftU.y - Quad1->rightL.y) <= 1) 
            count++;
            else
            count += Quad1->totalPoints(); 
        }
    }
    if (Quad2 != nullptr) {
        if (Quad2->type == true) {
            if (abs(Quad2->leftU.x - Quad2->rightL.x) <= 1 && abs(Quad2->leftU.y - Quad2->rightL.y) <= 1) 
            count++;
            else
            count += Quad2->totalPoints();
        }
    }
    if (Quad3 != nullptr) {
        if (Quad3->type == true) {
            if (abs(Quad3->leftU.x - Quad3->rightL.x) <= 1 && abs(Quad3->leftU.y - Quad3->rightL.y) <= 1) 
            count++;
            else
            count += Quad3->totalPoints();
        }
    }
    if (Quad4 != nullptr) {
        if (Quad4->type == true) {
            if (abs(Quad4->leftU.x - Quad4->rightL.x) <= 1 && abs(Quad4->leftU.y - Quad4->rightL.y) <= 1) 
            count++;
            else
            count += Quad4->totalPoints();
        }
    }
    return count;
}

int QuadTree :: totalNodes(){
    int count = 0;
    if (Quad1 != nullptr) {
        if (Quad1->type == true) {
            count++;
            count += Quad1->totalNodes();
        }
    }
    if (Quad2 != nullptr) {
        if (Quad2->type == true) {
            count++;
            count += Quad2->totalNodes();
        }
    }
    if (Quad3 != nullptr) {
        if (Quad3->type == true) {
            count++;
            count += Quad3->totalNodes();
        }
    }
    if (Quad4 != nullptr) {
        if (Quad4->type == true) {
            count++;
            count += Quad4->totalNodes();
        }
    }
    return count;
}

void QuadTree :: insert(Point geopoint, City Luton){
    //Comprobar si las coordenadas del punto pertenecen a la region
    if (geopoint.x < leftU.x && geopoint.x > rightL.x && geopoint.y < leftU.y && geopoint.y > rightL.y) {
        return;
    }
    //Comprobar si estamos ante un Nodo unitario, e insertar si no esta ocupado
    if (abs(leftU.x - rightL.x) <= 1 && abs(leftU.y - rightL.y) <= 1) {
        if (type == false){
            ciudad = Luton;
            type = true;
            cout<<"Se ha guardado la ciudad en las coordenadas: " <<"latitud: "<<leftU.x<<" - "<<"longitud: "<<leftU.y<<endl;
        }else{
            notInserted->insert(notInserted->begin(),Luton);
        }
        return;
    }
    type = true;
    //Generar QuadTrees hijos hasta llegar a un Nodo unitario
    if (geopoint.x < (leftU.x + rightL.x) / 2) {
        if(geopoint.y < (leftU.y + rightL.y) / 2) {
            if (Quad1 == nullptr) Quad1 = new QuadTree(leftU, Point((leftU.x + rightL.x) / 2, (leftU.y + rightL.y) / 2));
            Quad1->insert(geopoint, Luton);
        }else{
            if (Quad3 == nullptr) Quad3 = new QuadTree(Point(leftU.x, (leftU.y + rightL.y) / 2), Point((leftU.x + rightL.x) / 2, rightL.y));
            Quad3->insert(geopoint, Luton);
        }
    } else {
        if (geopoint.y < (leftU.y + rightL.y) / 2) {
            if (Quad2 == nullptr) Quad2 = new QuadTree(Point((leftU.x + rightL.x) / 2, leftU.y), Point(rightL.x, (leftU.y + rightL.y) / 2));
            Quad2->insert(geopoint, Luton);
        } else {
            if (Quad4 == nullptr) Quad4 = new QuadTree(Point((leftU.x + rightL.x) / 2, (leftU.y + rightL.y) / 2), rightL);
            Quad4->insert(geopoint, Luton);
        }
    }
}

vector<City>* QuadTree :: search(QuadTree* tree, vector<City>* result){
    if(tree != nullptr){
        if (abs(tree->leftU.x - tree->rightL.x) <= 1 && abs(tree->leftU.y - tree->rightL.y) <= 1) {
            result->insert(result->begin(), tree->ciudad);
        }
        search(tree->Quad1, result);
        search(tree->Quad2, result);
        search(tree->Quad3, result);
        search(tree->Quad4, result);
    }
    return result;
}

vector<City>* QuadTree :: list(){
    vector<City>* result = new vector<City>;
    search(this->Quad1, result);
    search(this->Quad2, result);
    search(this->Quad3, result);
    search(this->Quad4, result);
    return result;
}

int QuadTree :: countRegion(Point p, int d){
    int result = 0;
    Point alpha, beta;
    alpha = Point(p.x-d,p.y-d);
    beta = Point(p.x+d,p.y+d);
    if(alpha.x <= leftU.x && alpha.y <= leftU.y && beta.x >= rightL.x && beta.y >= rightL.y){
     if(abs(leftU.x - rightL.x) <= 1 && abs(leftU.y - rightL.y) <= 1){
        result ++;
        }
    }
        if(Quad1 != nullptr)
            result += Quad1->countRegion(p, d);
        if(Quad2 != nullptr)
            result += Quad2->countRegion(p, d);
        if(Quad3 != nullptr)
            result += Quad3->countRegion(p, d);
        if(Quad4 != nullptr)
            result += Quad4->countRegion(p, d);
            
    return result;
}

int QuadTree :: aggregateRegion(Point p, int d){
    int result = 0;
    Point alpha, beta;
    alpha = Point(p.x-d,p.y-d);
    beta = Point(p.x+d,p.y+d);
    if(alpha.x <= leftU.x && alpha.y <= leftU.y && beta.x >= rightL.x && beta.y >= rightL.y){
     if(abs(leftU.x - rightL.x) <= 1 && abs(leftU.y - rightL.y) <= 1){
        result +=ciudad.population;
        }
    }
        if(Quad1 != nullptr)
            result += Quad1->aggregateRegion(p, d);
        if(Quad2 != nullptr)
            result += Quad2->aggregateRegion(p, d);
        if(Quad3 != nullptr)
            result += Quad3->aggregateRegion(p, d);
        if(Quad4 != nullptr)
            result += Quad4->aggregateRegion(p, d);
            
    return result;
}
