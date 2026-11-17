#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

// Product structure
struct Product {
    int id;
    string name;
    float price;
    int quantity;
    Product* next;
};

// Hash Node structure
struct HashNode {
    int id;
    Product* product;
    HashNode* next;
};

// Global variables
Product* head = NULL;
HashNode* hashTable[SIZE] = {NULL};

// Hash function
int hashFunction(int id) {
    return id % SIZE;
}

// Search product using Hash Table
Product* search(int id) {
    int index = hashFunction(id);

    HashNode* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->id == id) {
            return temp->product;
        }
        temp = temp->next;
    }

    return NULL;
}

// Add Product
void addProduct() {
    int id;

    cout << "\nEnter Product ID: ";
    cin >> id;

    if (search(id) != NULL) {
        cout << "Product ID already exists!\n";
        return;
    }

    Product* newProduct = new Product;

    newProduct->id = id;

    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, newProduct->name);

    cout << "Enter Product Price: ";
    cin >> newProduct->price;

    cout << "Enter Product Quantity: ";
    cin >> newProduct->quantity;

    // Insert into Linked List
    newProduct->next = head;
    head = newProduct;

    // Insert into Hash Table using Chaining
    int index = hashFunction(id);

    HashNode* newNode = new HashNode;

    newNode->id = id;
    newNode->product = newProduct;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;

    cout << "\nProduct added successfully!\n";
}

// Display Products
void displayProducts() {
    Product* temp = head;

    if (temp == NULL) {
        cout << "\nNo products available!\n";
        return;
    }

    cout << "\n========== PRODUCT LIST ==========\n";

    while (temp != NULL) {
        cout << "\nProduct ID: " << temp->id;
        cout << "\nProduct Name: " << temp->name;
        cout << "\nPrice: " << temp->price;
        cout << "\nQuantity: " << temp->quantity;
        cout << "\n----------------------------------\n";

        temp = temp->next;
    }
}

// Update Product
void updateProduct() {
    int id;

    cout << "\nEnter Product ID to update: ";
    cin >> id;

    Product* temp = search(id);

    if (temp == NULL) {
        cout << "Product not found!\n";
        return;
    }

    cout << "Enter New Price: ";
    cin >> temp->price;

    cout << "Enter New Quantity: ";
    cin >> temp->quantity;

    cout << "\nProduct updated successfully!\n";
}

// Remove Product
void removeProduct() {
    int id;

    cout << "\nEnter Product ID to remove: ";
    cin >> id;

    Product* temp = head;
    Product* prev = NULL;

    // Find product in Linked List
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Product not found!\n";
        return;
    }

    // Delete from Linked List
    if (prev == NULL) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    // Delete from Hash Table
    int index = hashFunction(id);

    HashNode* h = hashTable[index];
    HashNode* p = NULL;

    while (h != NULL && h->id != id) {
        p = h;
        h = h->next;
    }

    if (h != NULL) {
        if (p == NULL) {
            hashTable[index] = h->next;
        }
        else {
            p->next = h->next;
        }

        delete h;
    }

    delete temp;

    cout << "\nProduct removed successfully!\n";
}

// Search Product
void searchProduct() {
    int id;

    cout << "\nEnter Product ID to search: ";
    cin >> id;

    Product* temp = search(id);

    if (temp == NULL) {
        cout << "\nProduct not found!\n";
    }
    else {
        cout << "\nProduct Found!\n";
        cout << "Product ID: " << temp->id << endl;
        cout << "Product Name: " << temp->name << endl;
        cout << "Price: " << temp->price << endl;
        cout << "Quantity: " << temp->quantity << endl;
    }
}

// Free allocated memory
void cleanup() {
    while (head != NULL) {
        Product* temp = head;
        head = head->next;
        delete temp;
    }

    for (int i = 0; i < SIZE; i++) {
        while (hashTable[i] != NULL) {
            HashNode* temp = hashTable[i];
            hashTable[i] = hashTable[i]->next;
            delete temp;
        }
    }
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "     E-COMMERCE PRODUCT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Remove Product\n";
        cout << "4. Display Products\n";
        cout << "5. Search Product\n";
        cout << "6. Exit\n";

        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addProduct();
                break;

            case 2:
                updateProduct();
                break;

            case 3:
                removeProduct();
                break;

            case 4:
                displayProducts();
                break;

            case 5:
                searchProduct();
                break;

            case 6:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    cleanup();

    return 0;
}
