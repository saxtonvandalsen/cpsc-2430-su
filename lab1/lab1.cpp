// Saxton Van Dalsen
// lab1.cpp
// 01/07/2024

// Purpose: This program utilizes user input to compute and present
// Pascal's Triangle based on a specific binomial degree. Additionally
// it returns the corresponding value of a specific binomial coefficient.

#include <iostream>

using namespace std;

int bico(int n, int i);

int main() {

  int binomial;
  int coefficient;

  cout << "Please input the degree of the binomial: ";
  cin >> binomial;
  cout << "Please input the index of the coefficient: ";
  cin >> coefficient;

  bico(binomial, coefficient);

  return 0;
}

// Function to calculate and display Pascal's Triangle based on
// a given binomial value and returns target coefficient value
int bico(int n, int i) {

  int size = n + 1; // Increase size by 1 for array memory

  int coefficient; // Hold coefficient value

  // Allocate memory for Pascal's Triangle with dynamic 2D array
  int ** pascalTri = new int*[size];
  for (int row = 0; row < size; row++) {
    pascalTri[row] = new int[row + 1];
  }

  // Calculate values for each row and column for Pascal's Triangle
  for (int row = 0; row < size; row++) {
    for (int col = 0; col <= row; col++) {

      if (col == 0) {
        pascalTri[row][col] = 1;
      } else if (col == row) {
        pascalTri[row][col] = 1;
      } else {
        // Calculating current element using sum of previous Pascal Triangle values
        pascalTri[row][col] = pascalTri[row - 1][col] + pascalTri[row - 1][col - 1];
      }
    }
  }

  // Printing out Pascal's Triangle
  for (int row = 0; row < size; row++) {
    for (int col = 0; col <= row; col++) {
      cout << pascalTri[row][col] << " ";
    }
    cout << endl;
  }

  // Loop to find the value of the given coefficient
  for (int row = 0; row < size; row++) {
    for (int col = 0; col <= row; col++) {
      if (pascalTri[row][i]) {
        coefficient = pascalTri[row][i];
        break;
      }
    }
  }
  
  cout << "The result is: " << coefficient << endl;

  // Deallocating memory
  for (int row = 0; row < size; row++) {
    delete [] pascalTri[row];
  }
  delete [] pascalTri;

  return coefficient;
}