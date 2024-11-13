#ifndef CERAMICPIECE_H
#define CERAMICPIECE_H

#include <string>
using namespace std;

class CeramicPiece {
public:
    enum Stage { PRE_BISQUED, BISQUED, GLAZED, FIRED };

private:
    string name;
    double width;
    double height;
    double weight;
    Stage stage;
    string category;
    string uniqueMarkings;
    string texture;
    string clayType;
    int quantity;

public:
    // Constructor
    CeramicPiece(string name, double width, double height, double weight, Stage stage,
        string category, string uniqueMarkings, string texture, string clayType, int quantity);

    // Display method
    void display() const;

    // Accessors
    string getClayType() const;
    Stage getStage() const;
    string getCategory() const;   // New getter
    string getTexture() const;    // New getter

    // CSV methods
    string toCSV() const;
    static CeramicPiece fromCSV(const string& csvLine);

    // Static methods for stage
    static string getStageName(Stage stage);
    static Stage parseStage(const string& stageName);
};

#endif