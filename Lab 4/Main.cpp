/*
Rafael Gallegos Cespedes
Computer Science Fall 2024
Due: Sep. 3, 2024
Lab 3 User and File I/O
This lab is a basic demo of the C++ language.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Class to handle temperature bar chart display
class TemperatureChart {
private:
    vector<int> temperatures;  // Stores the list of temperatures
    const int MIN_TEMP = -30;  // Minimum temperature in the range
    const int MAX_TEMP = 120;  // Maximum temperature in the range
    const int STAR_TEMP_RANGE = 3;  // Each star represents a range of 3 degrees

    // Validates if the temperature is within the allowable range
    bool isValidTemperature(int temp) {
        return temp >= MIN_TEMP && temp <= MAX_TEMP;
    }

    // Displays a single bar for the given temperature
    void displayBar(int temp) {
        int starCount = abs(temp)/3;  // Calculate the number of stars
        if (temp >= 0)
        {
            
        cout << setw(4) << temp << setw(12) << "|";  // Print the temperature
       
        for (int i = 0; i < starCount; i++) {
            cout << '*';
        }
        cout << endl;
        }
        if (temp <= -10)
        {
            cout << temp << setw(13 - starCount);
            for (int i = 0; i < starCount; i++) {
                cout << "*";
            }
            cout << "|";  // Print the temperature
            cout << endl;
        }
        if (temp <= -1 && temp >-10)
        {
            cout << temp << setw(14 - starCount);
            for (int i = 0; i < starCount; i++) {
                cout << "*";
            }
            cout << "|";  // Print the temperature
            cout << endl;
        }
    }

public:
    // Reads temperatures from a file
    void readTemperaturesFromFile(const string& filename) {
        ifstream infile("Temperature.dat");
        if (!infile) {
            cerr << "Error: Could not open the file." << endl;
            exit(1);  // Exit if file cannot be opened
        }

        int temp;
        while (infile >> temp) {
            if (isValidTemperature(temp)) {
                temperatures.push_back(temp);  // Only add valid temperatures
            }
            else {
                cerr << "Warning: Invalid temperature " << temp << " ignored." << endl;
            }
        }

        infile.close();
    }

    // Displays the temperature bar chart
    void displayChart() {
        cout << "Temperature Bar Chart (Each '*' represents 3 degrees)" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int temp : temperatures) {
            displayBar(temp);  // Display bar for each temperature
        }
    }
};

// Main function
int main() {
    TemperatureChart chart;
    string filename;

    // Ask user for the filename
  
    
    filename = "Temperature.dat";

    // Read temperatures from the file
    chart.readTemperaturesFromFile(filename);

    // Display the bar chart
    chart.displayChart();

    return 0;
}
