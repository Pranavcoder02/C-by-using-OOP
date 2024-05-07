#include<iostream>
#include<string>

using namespace std;
class Product {
public:
    string productId;
    string productName;
    string productPrice;
};

class ProductManagementSystem {
private:
    Product productList[100];
    int n;
public:
    ProductManagementSystem() : n(0) {}

    void displayProducts() {
        cout << "\nProduct List\n";
        cout << "ID\tName\tPrice\n";
        for (int i = 0; i < n; ++i) {
            cout << productList[i].productId << "\t" << productList[i].productName << "\t" << productList[i].productPrice << endl;
        }
        cout << endl;
    }

    void insertProduct(int pos,  Product& newProduct) {
        for (int i = n; i > pos; --i) {
            productList[i] = productList[i - 1];
        }
        productList[pos] = newProduct;
        n++;
        cout << "Product inserted at position " << pos << "\n";
    }

    void deleteProduct(int pos) {
        for (int i = pos; i < n - 1; ++i) {
            productList[i] = productList[i + 1];
        }
        n--;
        cout << "Product deleted from position " << pos << "\n";
    }

    void start() {
        int choice, pos;
        Product newProduct;

        while (true) {
            cout << "\nProduct Management System\n";
            cout << "1. Display Products\n";
            cout << "2. Insert Product\n";
            cout << "3. Delete Product\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                displayProducts();
                break;
            case 2:
                cout << "Enter the position to insert: ";
                cin >> pos;
                cout << "Enter Product ID: ";
                cin >> newProduct.productId;
                cout << "Enter Product Name: ";
                cin >> newProduct.productName;
                cout << "Enter Product Price: ";
                cin >> newProduct.productPrice;
                insertProduct(pos, newProduct);
                break;
            case 3:
                cout << "Enter the position to delete: ";
                cin >> pos;
                deleteProduct(pos);
                break;
            case 4:
                cout << "Exiting\n";
                return;
            default:
                cout << "Invalid choice\n";
            }
        }
    }
};

int main() {
    ProductManagementSystem pms;
    pms.start();
    return 0;
}

