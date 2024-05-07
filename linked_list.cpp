#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    string productId;
    string productName;
    string productPrice;
    Node* next;

    Node(string id, string name, string price) 
	{
        productId = id;
        productName = name;
        productPrice = price;
        next = NULL; 
    }
};

class ProductList {
private:
    Node* head;

public:
    ProductList() 
	{
        head = NULL; 
    }

    ~ProductList() 
	{
        Node* ptr = head;
        while (ptr != NULL) 
		{
            Node* next = ptr->next;
            delete ptr;
            ptr = next;
        }
        head = NULL;
    }
    void displayProducts() 
	
	{
        cout << "\nProduct List\n";
        cout << "ID\tName\tPrice\n";
        Node* ptr = head;
        while (ptr != NULL) 
		{
            cout << ptr->productId << "\t" << ptr->productName << "\t" << ptr->productPrice << endl;
             ptr = ptr->next;
        }
        cout << endl;
    }
    void insertProduct(int pos, Node* newProduct) 
	{
        if (pos == 0) 
		{
            newProduct->next = head;
            head = newProduct;
        }
		 else 
		{
            Node* temp = head;
            for (int i = 0; i < pos - 1 && temp != NULL; ++i) 
			{
                temp = temp->next;
            }
            if (temp != NULL) 
			{
                newProduct->next = temp->next;
                temp->next = newProduct;
            } else 
			{
                cout << "Invalid position\n";
            }
        }
        cout << "Product inserted at position " << pos << "\n";
    }

    void deleteProduct(int pos) 
	{
        if (head == NULL) 
		{
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        if (pos == 0) 
		{
            head = head->next;
            delete temp;
        } else 
		{
            for (int i = 0; temp != NULL && i < pos - 1; ++i) 
			{
                temp = temp->next;
            }
            if (temp != NULL && temp->next != NULL) 
			{
                Node* nextNode = temp->next->next;
                delete temp->next;
                temp->next = nextNode;
            } else 
			{
                cout << "Invalid position\n";
            }
        }
        cout << "Product deleted from position " << pos << "\n";
    }
};

int main() {
    ProductList productList;

    int choice, pos;
    string id, name, price;

    while (true) {
        cout << "\nProduct Management System\n";
        cout << "1. Display Products\n";
        cout << "2. Insert Product\n";
        cout << "3. Delete Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice ";
        cin >> choice;

        switch (choice) {
            case 1:
                productList.displayProducts();
                break;
            case 2:
                cout << "Enter the position to insert ";
                cin >> pos;
                cout << "Enter Product ID ";
                cin >> id;
                cout << "Enter Product Name ";
                cin >> name;
                cout << "Enter Product Price ";
                cin >> price;
                productList.insertProduct(pos, new Node(id, name, price));
                break;
            case 3:
                cout << "Enter the position to delete ";
                cin >> pos;
                productList.deleteProduct(pos);
                break;
            case 4:
                cout << "Exit\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}

