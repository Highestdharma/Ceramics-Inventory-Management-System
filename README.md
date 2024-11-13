# Ceramics-Inventory-Management-System
Description

The Ceramics Inventory Management System is a C++ application designed to help artists and ceramic enthusiasts manage their ceramic pieces. It allows users to track details of each piece through various stages (Pre-Bisqued, Bisqued, Glazed, Fired), including attributes like dimensions, weight, clay type, texture, and category (Functional or Sculptural). The project demonstrates core programming concepts such as classes, file handling with streams, modular design, and data storage.
Features

    Add New Pieces: Input ceramic piece details, including name, dimensions, weight, stage, clay type, and quantity.
    Filter Inventory: Filter pieces based on stage, category, texture, or clay type for quick lookup.
    Save and Load Inventory: Save inventory data to a CSV file and load it back for future use.
    Object-Oriented Design: Structured using C++ classes and modular files.

Getting Started
Prerequisites

To run this project, you'll need:

    C++ Compiler (e.g., g++ for Linux/macOS, MinGW for Windows)
    Git (optional, for cloning from GitHub)

Installation

    Clone the repository:

git clone https://github.com/yourusername/CeramicsInventorySystem.git

Navigate into the project directory:

cd CeramicsInventorySystem

Compile the project:

g++ main.cpp CeramicPiece.cpp Inventory.cpp -o ceramics_inventory

Run the program:

    ./ceramics_inventory

Usage

    Add Ceramic Pieces: Follow prompts to input details like name, dimensions, stage, and quantity.
    View All Pieces: Lists all pieces currently stored in the inventory.
    Filter Pieces: Filter based on criteria like stage or clay type to narrow down results.
    Save and Load Inventory: Save your current inventory to a CSV file for future use, or load an existing inventory file.

Sample Commands

After launching the program, you can interact with the system using the menu options.

1. Add new ceramic piece
2. View all pieces
3. Filter by stage
4. Filter by category
5. Filter by texture
6. Filter by clay type
7. Save inventory to file
8. Load inventory from file
9. Exit

Example Usage

To add a new piece:

    Choose option 1 from the menu and follow the prompts for each attribute.

To save your current inventory:

    Choose option 7, then specify a filename to save the data (e.g., inventory.csv).

Future Work

Planned future enhancements include:

    Sorting Functionality: Add sorting options for easier organization (e.g., by weight or stage).
    Graphical Interface: Build a GUI to make the application more user-friendly.
    Additional Data Fields: Include fields like date created or estimated firing temperature.

Contributing

Feel free to fork this repository and submit pull requests for any improvements or bug fixes.
License

This project is open-source and available under the MIT License. See the LICENSE file for more details.
Acknowledgments

    Special thanks to [Your Instructor/Professor] for guidance and support in this project.
    C++ Documentation: cplusplus.com


