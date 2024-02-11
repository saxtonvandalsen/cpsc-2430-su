// Saxton Van Dalsen
// lab2.cpp
// 1/14/2024

// Purpose: This program utilizes both iterative and recursive approaches to solving 
// Pascal's Triangle. Providing a user interface that asks the user for a desired
// degree and index using dynamic memory allocation to calculate Pascal's Triangle. 
// Functional decomposition is implemented to mitigate memory leaks.

#include <iostream>

using namespace std;

// Function prototypes
int** iterativePascal(int degree);
int recursiveBico(int degree, int index);
int** recursivePascal(int degree, int index);

int main () {

int degree;
int index;
int coefficient;

cout << "Please input the degree of the binomial: ";
cin >> degree;
cout << "Please input the index of the coefficient: ";
cin >> index;


cout << "Lab 1, iterative pascal triangle: " << endl;

// Declaring a pointer to a 2D array to store Lab1 Pascal's Triangle values 
int** iterativeTri = iterativePascal(degree);

// Printing out Lab1 Pascal's Triangle values
for (int row = 0; row < degree + 1; row++) {
  for (int col = 0; col <= row; col++) {
    cout << iterativeTri[row][col] << " ";
  }
  cout << endl;
}

cout << "Lab 2, recursive pascal triangle: " << endl;

// Declared a pointer to a 2D array to store Lab2 Pascal Triangle values
int** recursiveTri = recursivePascal(degree, index);

// Printing out Lab2 Pascal Triangle values
for (int row = 0; row < degree + 1; row++) {
  for (int col = 0; col <= row; col++) {
    cout << recursiveTri[row][col] << " ";
  }
  cout << endl;
}

// To find the value of the coefficient from the user provided index
for (int row = 0; row < degree + 1; row++) {
  for (int col = 0; col <= row; col++) {
    if (recursiveTri[row][index]) {
      coefficient = recursiveTri[row][index];
      break;
    }
  }
}

cout << "The result is: " << coefficient << endl;

// Deallocating memory of iterative & recursive triangle 2D arrays
for (int row = 0; row <= degree; row++) {
  delete [] iterativeTri[row];
  delete [] recursiveTri[row];
}
delete [] iterativeTri;
delete [] recursiveTri;

return 0;
}

// Function to calculate Pascal's Triangle through iteration
int** iterativePascal(int degree) {

  // Allocate memory for Pascal's Triangle with dynamic 2D array
  int ** pascalTri = new int*[degree + 1];
 
  // Calculate values for each row and column for Pascal's Triangle
  for (int row = 0; row < degree + 1; row++) {
    // Setting the size of each row
    pascalTri[row] = new int[row + 1];

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
  
  return pascalTri;
}

// Function to recursively calculate values for Pascal's Triangle
int recursiveBico(int degree, int index) {

  // Base case
  if (index == degree || index == 0) {
      return 1;
  } 
  // General case: Calculating binomial coefficents using a recursive formula
  else {
    return recursiveBico(degree - 1, index) + recursiveBico(degree - 1, index - 1);
  }
}

// Function to calculate Pascal Triangle values by recursiveBico function
int** recursivePascal(int degree, int index) {

    // Allocate memory for Pascal's Triangle with dynamic 2D array
    int** pascalTri = new int*[degree + 1];

    for (int row = 0; row < degree + 1; row++) {
        // Setting the size of each row
        pascalTri[row] = new int[row + 1];

        for (int col = 0; col <= row; col++) {
            // Add Pascal Triangle values for each row calculated by recursiveBico
            pascalTri[row][col] = recursiveBico(row, col);
        }
    }
    return pascalTri; 
}