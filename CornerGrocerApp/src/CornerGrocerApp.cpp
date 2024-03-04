// CornerGrocerApp.cpp

#include "CornerGrocerApp.h"

void CornerGrocerApp::run() {
    // Processing the input file and create a backup file at the beginning of the program
    processInputFile("../CS210_Project_Three_Input_File.txt");
    saveDataToFile("../frequency.dat");

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice (1-4): ";

        // Validating user input for the menu choice
        while (!(std::cin >> choice) || choice < 1 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
        }

        // Executing the chosen option
        switch (choice) {
            case 1:
                optionOne();
                break;
            case 2:
                optionTwo();
                break;
            case 3:
                optionThree();
                break;
            case 4:
                optionFour();
                break;
        }
    } while (choice != 4);  // Continues until the user chooses to exit
}

void CornerGrocerApp::processInputFile(const std::string& filename) {
    // Opening the input file and read item frequencies
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        exit(1);
    }

    std::string item;
    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

void CornerGrocerApp::displayMenu() {
    // Displaying the menu options
    std::cout << "\nMenu:\n";
    std::cout << "1. Search for item and display frequency\n";
    std::cout << "2. Display frequency of all items\n";
    std::cout << "3. Display histogram of item frequencies\n";
    std::cout << "4. Exit\n";
}

void CornerGrocerApp::optionOne() {
    // Searching for and display the frequency of a specific item
    std::string searchItem;
    std::cout << "Enter the item to search for: ";
    std::cin >> searchItem;

    // Converting the search item to lowercase for case-insensitive comparison
    std::transform(searchItem.begin(), searchItem.end(), searchItem.begin(), ::tolower);

    // Checking to see if the item is found in the records
    bool found = false;
    for (const auto& pair : itemFrequency) {
        std::string lowercaseItem = pair.first;
        std::transform(lowercaseItem.begin(), lowercaseItem.end(), lowercaseItem.begin(), ::tolower);

        if (lowercaseItem == searchItem) {
            std::cout << "Frequency of " << pair.first << ": " << pair.second << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Item not found in the records.\n";
    }
}

void CornerGrocerApp::optionTwo() {
    // Displaying the frequency of all items
    std::cout << "\nFrequency of all items:\n";
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void CornerGrocerApp::optionThree() {
    // Displaying a histogram of item frequencies
    std::cout << "\nHistogram of item frequencies:\n";
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

void CornerGrocerApp::optionFour() {
    // Saving data to the backup file and exit the program
    saveDataToFile("../frequency.dat");
    std::cout << "Data saved to frequency.dat. Exiting program.\n";
    exit(0);
}

void CornerGrocerApp::saveDataToFile(const std::string& filename) {
    // Opening the output file in append mode for backup
    std::ofstream outputFile(filename, std::ios::app);
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        exit(1);
    }

    // Getting the current date and time for identification
    time_t currentTime = std::time(0);
    tm* localTime = std::localtime(&currentTime);
    std::string timestamp = std::to_string(localTime->tm_year + 1900) + "-"
                           + std::to_string(localTime->tm_mon + 1) + "-"
                           + std::to_string(localTime->tm_mday) + " "
                           + std::to_string(localTime->tm_hour) + ":"
                           + std::to_string(localTime->tm_min) + ":"
                           + std::to_string(localTime->tm_sec);

    // Writing identification details and item frequencies to the file
    outputFile << "Output date and time: " << timestamp << "\n";
    outputFile << "Output by: CornerGrocerApp\n";
    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }

    std::cout << "Data appended to " << filename << " for backup.\n";
}
