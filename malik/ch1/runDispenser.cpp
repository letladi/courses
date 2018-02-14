#include "cashRegister.h"
#include "dispenserType.h"
#include <iostream>

using namespace std;

void showSelection();
void sellProduct(dispenserType& product, cashRegister& pCounter);

int main() {
    cashRegister counter;
    dispenserType appleJuice(100, 50);
    dispenserType orangeJuice(100, 65);
    dispenserType mangoLassi(75, 45);
    dispenserType fruitPunch(100, 85);

    int choice;

    showSelection();
    cin >> choice;

    while (choice != 9) {
        switch(choice) {
        case 1:
            sellProduct(appleJuice, counter);
            break;
        case 2:
            sellProduct(orangeJuice, counter);
            break;
        case 3:
            sellProduct(mangoLassi, counter);
        case 4:
            sellProduct(fruitPunch, counter);
            break;

        default:
            cout << "Invalid selection." << endl;
        }
        showSelection();
        cin >> choice;
    }
    
    return 0;
}

void showSelection() {
    cout << "*** Welcome to Shelly's Fruit Juice Shop ***" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for apple juice" << endl;
    cout << "2 for orange juice" << endl;
    cout << "3 for mango lassi" << endl;
    cout << "4 for fruit punch" << endl;
    cout << "9 for exit" << endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter) {
    int amount = 0;
    int deposit = 0;

    if (product.getNoOfItems() > 0) {

        int depositCount = 0;
        while (amount < product.getCost()) {
             cout << "Please deposit "  << (depositCount++ ? "another " : "") << product.getCost() - amount << " cents" << endl;
            cin >> deposit;
            amount += deposit;

        }

        pCounter.acceptAmount(amount);
        product.makeSale();
        cout << "Collect your item at the bottom and enjoy." << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    } else {
        cout << "Sorry, this item is sold out." << endl;
    }
}