// CornerGrocerApp.h

#ifndef CORNER_GROCER_APP_H
#define CORNER_GROCER_APP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <limits>
#include <algorithm>
#include <ctime> 

class CornerGrocerApp {
public:
    // Function to start and run the CornerGrocerApp
    void run();

private:
    // Map to store item frequencies
    std::map<std::string, int> itemFrequency;

    // Function to process the input file and populate item frequencies
    void processInputFile(const std::string& filename);

    // Function to display the menu options
    void displayMenu();

    // Functions to handle each menu option
    void optionOne();
    void optionTwo();
    void optionThree();
    void optionFour();

    // Function to save data to a backup file
    void saveDataToFile(const std::string& filename);
};

#endif // CORNER_GROCER_APP_H
