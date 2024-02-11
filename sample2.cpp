#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void generate_output(const string& filename) {
    ifstream inputFile(filename.c_str());

    // Check if the input file is opened successfully
    if (!inputFile) {
        cout << "Failed to open the input file." << endl;
        return;
    }

    // Extracting the number of rows, columns, and k from the first line
    int rows, cols, k;
    inputFile >> rows >> cols >> k;

    // Initializing boolean vectors to store rows and columns; all elements are false at first
    vector<bool> row(rows, false), col(cols, false);

    // Initializing a vector of strings that will store the input lines
    vector<string> line(rows);

    // Iterating through each line of the input file
    for (int i = 0; i < rows; i++) {
        inputFile >> line[i];
        // Iterating through every character of line[i], if a character signifies a bomb,
        // mark the respective bool row and column as true
        for (int j = 0; j < cols; j++) {
            if (line[i][j] == 'B') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // Closes input file
    inputFile.close();

	vector<int> nonSafe;
	for (int i = 0; i < rows; i++) {
	    for (int j = 0; j < cols; j++) {
	        if (line[i][j] == 'B') {
	            // If a bomb is found, mark the entire row with asterisks
	            for (int k = 0; k < cols; k++) {
	                if (line[i][k] != 'B' && line[i][k] != '*') {
	                    nonSafe.push_back(line[i][k] - '0');
	                    line[i][k] = '*';
	                }
	            }
	            // Mark also the entire column with asterisks
	            for (int k = 0; k < rows; k++) {
	                if (line[k][j] != 'B' && line[k][j] != '*') {
	                    nonSafe.push_back(line[k][j] - '0');
	                    line[k][j] = '*';
	                }
	            }        
            // Mark the bomb position with an asterisk
            line[i][j] = '*';
       		}
    	}
	}
	
	//Sort the nonsafe vectors in descending order (so the max value will be in front)
    sort(nonSafe.begin(), nonSafe.end(), greater<int>());

	while (k > 0) {
	    int temp;
		// Find the smallest value in the grid (ignoring asterisks)
		int minVal = -1;  // Initialize with a value that is guaranteed to be smaller than any valid element
		//iterate through the grid (lines vector)
		for (int i = 0; i < rows; i++) {
    		for (int j = 0; j < cols; j++) {
        		if (line[i][j] != '*' && (minVal == -1 || line[i][j] - '0' < minVal)) {
            	minVal = line[i][j] - '0';
        		}
    		}
		}

    	// Update the corresponding positions in the line vector
    	for (int i = 0; i < rows; i++) {
    	    for (int j = 0; j < cols; j++) {
    	        if (line[i][j] -'0' == minVal && line[i][j] != '*') {
    	            int value = line[i][j] - '0';
    	            if (value < nonSafe.front()) {
    	                temp = line[i][j];
    	                line[i][j] = nonSafe.front() + '0';
    	                nonSafe[0] = temp - '0';
    	            }
    	        }
    	    }
    	}
    	
    	// Re-sort the safe and non-safe vectors after swapping
    	sort(nonSafe.begin(), nonSafe.end(), greater<int>());
    	
    	k--;

	}

    // Print the safe positions
    cout << "Safe Positions:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << line[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Sum the remaining numbers in the grid (line vector)
    int remainingSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (line[i][j] != '*') {
                remainingSum += line[i][j] - '0';
            }
        }
    }
    
    //display the sum of the remaining numbers in the grid (line vector)
    cout << "Sum of remaining numbers: " << remainingSum << endl;
}

int main(int argc, char const *argv[]) {
    // Error checking if the input file name is provided
    if (argc < 2) {
        cout << "ERROR: Please provide the input filename as an argument." << endl;
        return 1;
    }
	
    string filename = argv[1];
    //call the generate_output function
    generate_output(filename);

    return 0;
}

