#include <iostream>
#include <string>
#include "CeramicPiece.h"
#include "Inventory.h"
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\nCeramics Inventory Management System" << endl;
    cout << "1. Add new ceramic piece" << endl;
    cout << "2. View all pieces" << endl;
    cout << "3. Filter by stage" << endl;
    cout << "4. Filter by category" << endl;
    cout << "5. Filter by texture" << endl;
    cout << "6. Filter by clay type" << endl;
    cout << "7. Save inventory to file" << endl;
    cout << "8. Load inventory from file" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to handle adding a new ceramic piece
void addCeramicPiece(Inventory& inventory) {
    string name, category, uniqueMarkings, texture, clayType;
    double width, height, weight;
    int quantity, stageChoice;
    CeramicPiece::Stage stage;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter width (cm): ";
    cin >> width;
    cout << "Enter height (cm): ";
    cin >> height;
    cout << "Enter weight (grams): ";
    cin >> weight;

    cout << "Select stage (0: Pre-Bisqued, 1: Bisqued, 2: Glazed, 3: Fired): ";
    cin >> stageChoice;
    if (stageChoice < 0 || stageChoice > 3) {
        cout << "Invalid stage choice. Setting to Pre-Bisqued." << endl;
        stage = CeramicPiece::PRE_BISQUED;
    }
    else {
        stage = static_cast<CeramicPiece::Stage>(stageChoice);
    }

    cout << "Enter category (Functional/Sculptural): ";
    cin.ignore();
    getline(cin, category);
    cout << "Enter unique markings: ";
    getline(cin, uniqueMarkings);
    cout << "Enter texture: ";
    getline(cin, texture);
    cout << "Enter clay type: ";
    getline(cin, clayType);
    cout << "Enter quantity: ";
    cin >> quantity;

    // Add piece to inventory
    CeramicPiece newPiece(name, width, height, weight, stage, category, uniqueMarkings, texture, clayType, quantity);
    inventory.addPiece(newPiece);
    cout << "Ceramic piece added successfully!" << endl;
}

// Function to filter and display pieces by stage
void filterByStage(const Inventory& inventory) {
    int stageChoice;
    cout << "Select stage to filter (0: Pre-Bisqued, 1: Bisqued, 2: Glazed, 3: Fired): ";
    cin >> stageChoice;
    if (stageChoice < 0 || stageChoice > 3) {
        cout << "Invalid choice." << endl;
        return;
    }
    inventory.filterByStage(static_cast<CeramicPiece::Stage>(stageChoice));
}

int main() {
    Inventory inventory;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addCeramicPiece(inventory);
            break;
        case 2:
            inventory.displayAll();
            break;
        case 3:
            filterByStage(inventory);
            break;
        case 4: {
            string category;
            cout << "Enter category to filter (Functional/Sculptural): ";
            cin.ignore();
            getline(cin, category);
            inventory.filterByCategory(category);
            break;
        }
        case 5: {
            string texture;
            cout << "Enter texture to filter: ";
            cin.ignore();
            getline(cin, texture);
            inventory.filterByTexture(texture);
            break;
        }
        case 6: {
            string clayType;
            cout << "Enter clay type to filter: ";
            cin.ignore();
            getline(cin, clayType);
            inventory.filterByClayType(clayType);
            break;
        }
        case 7: {
            string filename;
            cout << "Enter filename to save inventory: ";
            cin >> filename;
            inventory.saveToFile(filename);
            break;
        }
        case 8: {
            string filename;
            cout << "Enter filename to load inventory: ";
            cin >> filename;
            inventory.loadFromFile(filename);
            break;
        }
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}