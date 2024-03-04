# CornerGrocerApp

## Overview

The CornerGrocerApp is a command-line application designed to manage and analyze item frequencies in a grocery store. It provides users with functionalities to search for specific items, display the frequency of all items, and visualize item frequencies through a histogram. This application is particularly useful for grocery store owners or managers who want to track and analyze the popularity of various items.

## Usage

1. **Build the Application:**

   - Ensure you have CMake installed.
   - Open a terminal and navigate to the project directory.
   - Run the following commands:
     ```bash
     mkdir build
     cd build
     cmake ..
     cmake --build .
     ```

2. **Run the Application:**

   - After building the application, run the executable.
     ```bash
     ./CornerGrocerApp
     ```

3. **Menu Options:**

   - Upon launching the application, you'll be presented with a menu containing the following options:
     1. Search for item and display frequency
     2. Display frequency of all items
     3. Display histogram of item frequencies
     4. Exit

4. **Option One: Search for Item**

   - Enter the item you want to search for when prompted.
   - The application will display the frequency of the specified item.

5. **Option Two: Display Frequency of All Items**

   - This option will show the frequency of all items in the grocery store.

6. **Option Three: Display Histogram**

   - The application will generate and display a histogram of item frequencies.

7. **Option Four: Exit the Application**

   - Selecting this option will save the data to a backup file and exit the program.

8. **Data Backup:**

   - The application automatically saves data to a file named `frequency.dat` for backup.

9. **User Testing (Optional):**

   - The app provides an option to test different functionalities by allowing the user to navigate through the menu and explore various features.

10. **Exit the Application:**
    - To exit the program, follow the on-screen instructions.

## Code Design and Functionality

### CornerGrocerApp.cpp

- **Functionality:**

  - Processes the input file to populate item frequencies.
  - Displays a menu with four options for the user.
  - Implements functions for each menu option.
  - Saves data to a backup file and exits the program.

- **Option One (Search Functionality):**

  - Implements case-insensitive item search.
  - Displays the frequency of the searched item or a message if not found.

- **Option Two (Display Frequency):**

  - Shows the frequency of all items in the grocery store.

- **Option Three (Display Histogram):**

  - Generates and displays a histogram of item frequencies.

- **Option Four (Exit):**
  - Saves data to `frequency.dat` and exits the program.

### CornerGrocerApp.h

- **Class Structure:**
  - Defines the `CornerGrocerApp` class with private member variables and functions.
  - Utilizes a map to store item frequencies.

### CMakeLists.txt

- **Project Configuration:**
  - Sets the C++ standard to 14.
  - Lists source files and includes the `include` directory.

## Troubleshooting

- If you encounter any issues or have questions, please contact the developer for assistance.

## Acknowledgments

This application was developed using C++ and adheres to best practices for code organization and readability. It provides a straightforward and efficient solution for managing and analyzing grocery store item frequencies.
