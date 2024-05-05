
#include <iostream>
#include "inv.h"
#include <string>

using namespace std;

Inventory::Inventory() : head(NULL) {}

Inventory::~Inventory() {
    Product* current = head;
    while (current) {
        Product* next = current->next;
        delete current;
        current = next;
    }
}

void Inventory::SortInsert(Product* newProduct) { // Check if newProduct is valid
    if (!newProduct) {
        cout << "Invalid product.\n";
    }

    if (isFound(newProduct->id)) {  // Check if a product with the same ID already exists
        cout << "Product with ID " << newProduct->id << " already exists. Cannot add duplicate product.\n";
        delete newProduct;
    }

    Product* current;     // If the list is empty or newProduct has the smallest ID, insert at the beginning

    if (!head || head->id >= newProduct->id) {
        newProduct->next = head;
        head = newProduct;
    } else {  // Find the correct position to insert newProduct
        current = head;
        while (current->next != NULL && current->next->id < newProduct->id) {
            current = current->next;
        }
        newProduct->next = current->next;
        current->next = newProduct;
    }
}
void Inventory::addProduct() {
    Product* newProduct = new Product;
    cout << "Enter product ID: ";
    cin >> newProduct->id;
    if (isFound(newProduct->id)) {
        cout << "Product with ID " << newProduct->id << " already exists. Cannot add duplicate product.\n";
        delete newProduct;

    }

    cout << "Enter product name: ";
    cin.ignore(); // Ignore any remaining newline characters
    getline(cin, newProduct->name);

    int quantity;
    do {
        cout << "Enter quantity (0 or more): ";
        cin >> quantity;
        if (quantity < 0) {
            cout << "Quantity cannot be negative. Please enter a valid quantity.\n";
        }
    } while (quantity < 0);
    newProduct->quantity = quantity;

    SortInsert(newProduct);
    cout << "Product added with ID " << newProduct->id << ", Name " << newProduct->name << ", Quantity " << newProduct->quantity << ".\n";
}
void Inventory::displayProducts() {
    Product* current = head;
    if (!current) {
        cout << "Inventory is empty.\n";

    }
    while (current) {
        cout << "ID: " << current->id << " Name: " << current->name << " Quantity: " << current->quantity << "\n";
        current = current->next;
    }
}

void Inventory::RetrieveData(int id) {
    Product* current = head;
    while (current) {
        if (current->id == id) {
            cout << "ID: " << current->id << " Name: " << current->name << " Quantity: " << current->quantity << "\n";
            return;
        }
        current = current->next;
    }
    cout << "Product not found.\n";
}

bool Inventory::isFound(int id) {
    Product* current = head;
    while (current) {
        if (current->id == id) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void Inventory::updateProduct(int id) {
    Product* current = head;
    while (current) {
        if (current->id == id) {
            cout << "Note: Current quantity is: " << current->quantity << "\n";
            int newQuantity;
            do {
                cout << "Enter new quantity (0 or more): ";
                cin >> newQuantity;
                if (newQuantity < 0) {
                    cout << "Quantity cannot be negative. Please enter a valid quantity.\n";
                }
            } while (newQuantity < 0);
            current->quantity = newQuantity;
            cout << "Product updated. Quantity changed from " << current->quantity << " to " << newQuantity << ".\n";
            return;
        }
        current = current->next;
    }
    cout << "Product not found.\n";
}

void Inventory::deleteProduct(int id) {
    Product* current = head;
    Product* prev = NULL;
    while (current) {
        if (current->id == id) {
            int deletedId = current->id;
            string deletedName = current->name;
            int deletedQuantity = current->quantity;

            if (!prev) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Product deleted with ID " << deletedId << ", Name " << deletedName << ", Quantity " << deletedQuantity << ".\n";
        }
        prev = current;
        current = current->next;
    }
    cout << "Product not found.\n";
}

int Inventory::countProducts() {
    int counter = 0;
    Product* current = head;
    while (current) {
        counter++;
        current = current->next;
    }
    return counter;
}
