#include "CeramicPiece.h"
#include <iostream>
#include <sstream>
using namespace std;

// Initializes all attributes of a ceramic piece with the given values
CeramicPiece::CeramicPiece(string name, double width, double height, double weight, Stage stage,
    string category, string uniqueMarkings, string texture, string clayType, int quantity)
    : name(name), width(width), height(height), weight(weight), stage(stage),
    category(category), uniqueMarkings(uniqueMarkings), texture(texture), clayType(clayType), quantity(quantity) {}

// Prints all details of the ceramic piece to the console
void CeramicPiece::display() const {
    cout << "Name: " << name << endl;
    cout << "Dimensions: " << width << " cm x " << height << " cm" << endl;
    cout << "Weight: " << weight << " grams" << endl;
    cout << "Stage: " << getStageName(stage) << endl;
    cout << "Category: " << category << endl;
    cout << "Unique Markings: " << uniqueMarkings << endl;
    cout << "Texture: " << texture << endl;
    cout << "Clay Type: " << clayType << endl;
    cout << "Quantity: " << quantity << endl;
}

// Returns the clay type of the piece
string CeramicPiece::getClayType() const { return clayType; }

// Returns the stage of the piece as an enum value
CeramicPiece::Stage CeramicPiece::getStage() const { return stage; }

// Returns the category of the piece (e.g., Functional, Sculptural)
string CeramicPiece::getCategory() const { return category; }

// Returns the texture of the piece (e.g., Smooth, Matte)
string CeramicPiece::getTexture() const { return texture; }

// Takes a Stage enum value and returns its corresponding string representation
string CeramicPiece::getStageName(Stage stage) {
    switch (stage) {
    case PRE_BISQUED: return "Pre-Bisqued";
    case BISQUED: return "Bisqued";
    case GLAZED: return "Glazed";
    case FIRED: return "Fired";
    default: return "Unknown";
    }
}

// Converts a string representation of a stage to its corresponding enum value
CeramicPiece::Stage CeramicPiece::parseStage(const string& stageName) {
    if (stageName == "Pre-Bisqued") return PRE_BISQUED;
    else if (stageName == "Bisqued") return BISQUED;
    else if (stageName == "Glazed") return GLAZED;
    else if (stageName == "Fired") return FIRED;
    throw invalid_argument("Invalid stage name");
}

// Converts the ceramic piece's attributes into a CSV-formatted string
// Saving the piece's data to a file
string CeramicPiece::toCSV() const {
    return name + "," + to_string(width) + "," + to_string(height) + "," + to_string(weight) + "," +
        getStageName(stage) + "," + category + "," + uniqueMarkings + "," + texture + "," + clayType + "," +
        to_string(quantity);
}

// Static method to create a CeramicPiece object from a CSV-formatted string
// Loading a piece from a file
CeramicPiece CeramicPiece::fromCSV(const string& csvLine) {
    stringstream ss(csvLine); // Create a stringstream from the CSV line
    string name, widthStr, heightStr, weightStr, stageStr, category, uniqueMarkings, texture, clayType, quantityStr;

    // Parse each field separated by commas
    getline(ss, name, ',');
    getline(ss, widthStr, ',');
    getline(ss, heightStr, ',');
    getline(ss, weightStr, ',');
    getline(ss, stageStr, ',');
    getline(ss, category, ',');
    getline(ss, uniqueMarkings, ',');
    getline(ss, texture, ',');
    getline(ss, clayType, ',');
    getline(ss, quantityStr, ',');

    // Convert string values to appropriate data types
    double width = stod(widthStr);
    double height = stod(heightStr);
    double weight = stod(weightStr);
    Stage stage = parseStage(stageStr); // Parse the stage string to an enum value
    int quantity = stoi(quantityStr);

    // Return a new CeramicPiece object with parsed values
    return CeramicPiece(name, width, height, weight, stage, category, uniqueMarkings, texture, clayType, quantity);
}
