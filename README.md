# Ceramics-Inventory-Management-System
The Ceramics Inventory Management System is a C++ application designed to help artists and ceramic enthusiasts manage their ceramic pieces. It allows users to track details of each piece through various stages (Pre-Bisqued, Bisqued, Glazed, Fired), including attributes like dimensions, weight, clay type, texture, and category (Functional or Sculptural). The project demonstrates core programming concepts such as classes, file handling with streams, modular design, and data storage.
Features

    Add New Pieces: Input ceramic piece details, including name, dimensions, weight, stage, clay type, and quantity.
    Filter Inventory: Filter pieces based on stage, category, texture, or clay type for quick lookup.
    Save and Load Inventory: Save inventory data to a CSV file and load it back for future use.
    Object-Oriented Design: Structured using C++ classes and modular files.

# Installation

    Clone the repository:

git clone https://github.com/Highestdharma/Ceramics-Inventory-Management-System.git

Navigate into the project directory:

cd Ceramics-Inventory-Management-System

Compile the project:

g++ main.cpp CeramicPiece.cpp Inventory.cpp -o ceramics_inventory

Run the program:

    ./ceramics_inventory

# Usage

Upon running the program, you’ll be prompted with a menu of options:

    Add New Ceramic Piece: Enter details for a new piece, like name, dimensions, weight, texture, and stage.
    View All Pieces: View all pieces currently in the inventory.
    Filter by Attributes: Filter pieces by stage, category, texture, or clay type.
    Save Inventory to File: Save your inventory data to a CSV file for future access.
    Load Inventory from File: Load an inventory from a CSV file.

Sample Commands

After launching the program, choose options from the menu by entering the corresponding number:

1. Add new ceramic piece
2. View all pieces
3. Filter by stage
4. Filter by category
5. Filter by texture
6. Filter by clay type
7. Save inventory to file
8. Load inventory from file
9. Exit

Example Walkthrough

To add a new piece:

    Select option 1 and input the required details as prompted.

To save your current inventory:

    Select option 7, and specify a filename (e.g., inventory.csv).

Future Enhancements

Potential future improvements include:

    Sorting Functionality: Allow sorting by weight, stage, or other attributes.
    Graphical Interface: Create a GUI for more accessible interaction.
    Additional Attributes: Track other data, such as creation date or firing temperature.

# Contributing

Contributions are welcome! Feel free to fork this repository, make improvements, and submit pull requests.
License

This project is open-source under the MIT License. See the LICENSE file for more information.
Acknowledgments

    Thanks to Professor Onwuka for their guidance.
    C++ Documentation: cplusplus.com
