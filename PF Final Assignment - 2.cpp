#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Item {
    string name;
    double price;
};

vector<Item> fruits = { {"Apple", 0.5}, {"Banana", 0.3}, {"Orange", 0.7} };
vector<Item> dairy = { {"Milk", 2.0}, {"Cheese", 3.5}, {"Yogurt", 1.8} };
vector<Item> bakery = { {"Bread", 1.2}, {"Croissant", 2.5}, {"Cake", 5.0} };
vector<Item> grains = { {"Rice", 1.8}, {"Pasta", 2.2}, {"Oats", 3.0} };

vector<Item> cart;

template<typename T>
void printLine(T text, char fill = '-') {
    cout << setfill(fill) << setw(40) << text << endl;
}

void showStore() {
    int choice;
    while (true) {
        cout << "\nSelect a Category:\n";
        cout << "1. Fruits\n2. Dairy\n3. Bakery\n4. Grains\n5. Go Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        vector<Item>* selectedCategory = nullptr;

        if (choice == 1) selectedCategory = &fruits;
        else if (choice == 2) selectedCategory = &dairy;
        else if (choice == 3) selectedCategory = &bakery;
        else if (choice == 4) selectedCategory = &grains;
        else if (choice == 5) return;
        else {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        printLine("Available Items");
        for (size_t i = 0; i < selectedCategory->size(); ++i) {
            cout << i + 1 << ". " << (*selectedCategory)[i].name << " - $" << (*selectedCategory)[i].price << endl;
        }
        printLine("", '=');
    }
}

void addToCart() {
    while (true) {
        int categoryChoice, itemChoice;

        cout << "\nSelect a Category to Add Items From:\n";
        cout << "1. Fruits\n2. Dairy\n3. Bakery\n4. Grains\n5. Go Back\n";
        cout << "Enter choice: ";
        cin >> categoryChoice;

        vector<Item>* selectedCategory = nullptr;

        if (categoryChoice == 1) selectedCategory = &fruits;
        else if (categoryChoice == 2) selectedCategory = &dairy;
        else if (categoryChoice == 3) selectedCategory = &bakery;
        else if (categoryChoice == 4) selectedCategory = &grains;
        else return; // Go back

        while (true) {
            printLine("Select Item to Add");
            for (size_t i = 0; i < selectedCategory->size(); ++i) {
                cout << i + 1 << ". " << (*selectedCategory)[i].name << " - $" << (*selectedCategory)[i].price << endl;
            }
            printLine("", '=');

            cout << "Enter item number to add to cart (0 to go back): ";
            cin >> itemChoice;

            if (itemChoice > 0 && itemChoice <= selectedCategory->size()) {
                cart.push_back((*selectedCategory)[itemChoice - 1]);
                cout << (*selectedCategory)[itemChoice - 1].name << " added to cart!\n";
            } else if (itemChoice == 0) {
                break;
            } else {
                cout << "Invalid choice! Try again.\n";
            }
        }
    }
}

void viewCart() {
    if (cart.empty()) {
        cout << "Your cart is empty!\n";
        return;
    }
    printLine("Your Cart");
    double total = 0;
    for (const auto &item : cart) {
        cout << item.name << " - $" << item.price << endl;
        total += item.price;
    }
    printLine("", '=');
    cout << "Total: $" << total << endl;
}

void checkout() {
    viewCart();
    if (!cart.empty()) {
        cout << "Proceeding to checkout... Thank you for shopping!\n";
        cart.clear();
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. View Store\n2. Add to Cart\n3. View Cart\n4. Checkout\n5. Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
            case 1: showStore(); break;
            case 2: addToCart(); break;
            case 3: viewCart(); break;
            case 4: checkout(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option! Try again.\n";
        }
    } while (choice != 5);
    return 0;
}

