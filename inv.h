#ifndef INVENTORY_H
#define INVENTORY_H
#include<iostream>
#include <string>
using namespace std ;
class Product {

    public:
    int id;
    string name;
    int quantity;
    Product* next;
};

class Inventory {
private:
    Product* head;
public:
    Inventory();
    ~Inventory();
    void SortInsert(Product* newProduct);
    void addProduct();
    void displayProducts();
    void RetrieveData(int id);
    bool isFound(int id);
    void updateProduct(int id);
    void deleteProduct(int id);
    int countProducts();
};

#endif


