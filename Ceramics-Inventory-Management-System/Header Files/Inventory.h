#ifndef INVENTORY_H
#define INVENTORY_H

#include "CeramicPiece.h"
#include <vector>
#include <string>
using namespace std;

class Inventory {
private:
    vector<CeramicPiece> pieces;

public:
    void addPiece(const CeramicPiece& piece);
    void displayAll() const;
    void filterByStage(CeramicPiece::Stage stage) const;
    void filterByCategory(const string& category) const;
    void filterByTexture(const string& texture) const;
    void filterByClayType(const string& clayType) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
