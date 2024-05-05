#include <iostream>
#include "inv.h"
using namespace std;
int main() {
    Inventory inventory;
    int choice;

    do {
         cout << "1. Add Product\n";
         cout << "2. Display All Products\n";
         cout << "3. Display Specific Product\n";
         cout << "4. Update Product\n";
         cout << "5. Delete Product\n";
         cout << "6. Count Products\n";
         cout << "7. Exit\n";
         cout << "Enter your choice: ";
         cin >> choice;

        switch (choice) {
            case 1:
                inventory.addProduct();
                break;
            case 2:
                inventory.displayProducts();
                break;
            case 3: {
                int id;
                 cout << "Enter product ID: ";
                 cin >> id;
                if (inventory.isFound(id)) {
                    inventory.RetrieveData(id);
                } else {
                     cout << "Product not found.\n";
                }
                break;
            }
            case 4: {
                int id;
                 cout << "Enter product ID to update: ";
                 cin >> id;
                if (inventory.isFound(id)) {
                    inventory.updateProduct(id);
                } else {
                     cout << "Product not found.\n";
                }
                break;
            }
            case 5: {
                int id;
                 cout << "Enter product ID to delete: ";
                 cin >> id;
                if (inventory.isFound(id)) {
                    inventory.deleteProduct(id);
                     cout << "Product deleted.\n";
                } else {
                     cout << "Product not found.\n";
                }
                break;
            }
            case 6: {
				int numProducts = inventory.countProducts();
    			 cout << "Number of products: " << numProducts <<  endl;
                break;
            }
            case 7:
                 cout << "Exiting...\n";
                break;
            default:
                 cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}


