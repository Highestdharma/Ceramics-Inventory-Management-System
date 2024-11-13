#include "Inventory.h"
#include <iostream>
#include <fstream>
using namespace std;

// Adds a ceramic piece to the inventory by pushing it into the pieces vector
void Inventory::addPiece(const CeramicPiece& piece) {
    pieces.push_back(piece);
}

// Displays all pieces in the inventory
void Inventory::displayAll() const {
    if (pieces.empty()) { // Check if inventory is empty
        cout << "Inventory is empty." << endl;
        return;
    }
    // Loop through each piece in the inventory and display it
    for (const auto& piece : pieces) {
        piece.display();
        cout << "--------------------------" << endl; // Divider between pieces
    }
}

// Filters and displays pieces based on their stage (e.g., Bisqued, Glazed)
void Inventory::filterByStage(CeramicPiece::Stage stage) const {
    bool found = false; // Tracks if any piece matches the filter
    for (const auto& piece : pieces) {
        if (piece.getStage() == stage) { // Check if piece matches the stage
            piece.display();
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) { // No pieces found in the given stage
        cout << "No pieces found in stage '" << CeramicPiece::getStageName(stage) << "'." << endl;
    }
}

// Filters and displays pieces based on their category (e.g., Functional, Sculptural)
void Inventory::filterByCategory(const string& category) const {
    bool found = false;
    for (const auto& piece : pieces) {
        if (piece.getCategory() == category) { // Check if piece matches the category
            piece.display();
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) { // No pieces found in the given category
        cout << "No pieces found in category '" << category << "'." << endl;
    }
}

// Filters and displays pieces based on their texture (e.g., Smooth, Matte)
void Inventory::filterByTexture(const string& texture) const {
    bool found = false;
    for (const auto& piece : pieces) {
        if (piece.getTexture() == texture) { // Check if piece matches the texture
            piece.display();
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) { // No pieces found with the given texture
        cout << "No pieces found with texture '" << texture << "'." << endl;
    }
}

// Filters and displays pieces based on their clay type (e.g., Porcelain, Stoneware)
void Inventory::filterByClayType(const string& clayType) const {
    bool found = false;
    for (const auto& piece : pieces) {
        if (piece.getClayType() == clayType) { // Check if piece matches the clay type
            piece.display();
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) { // No pieces found with the given clay type
        cout << "No pieces found with clay type '" << clayType << "'." << endl;
    }
}

// Saves the current inventory to a file in CSV format
void Inventory::saveToFile(const string& filename) const {
    ofstream outFile(filename); // Open the file for writing
    if (!outFile) { // Check if file opened successfully
        cerr << "Error opening file for writing." << endl;
        return;
    }

    // Write each piece in the inventory to the file as a CSV line
    for (const auto& piece : pieces) {
        outFile << piece.toCSV() << endl;
    }
    outFile.close();
    cout << "Inventory saved to " << filename << endl;
}

// Loads inventory data from a CSV file
void Inventory::loadFromFile(const string& filename) {
    ifstream inFile(filename); // Open the file for reading
    if (!inFile) { // Check if file opened successfully
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) { // Read each line from the file
        CeramicPiece piece = CeramicPiece::fromCSV(line); // Convert line to CeramicPiece
        addPiece(piece); // Add piece to inventory
    }
    inFile.close();
    cout << "Inventory loaded from " << filename << endl;
}