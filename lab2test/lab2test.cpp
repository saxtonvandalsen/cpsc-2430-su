
#include <iostream>
#include <chrono>
using namespace std::chrono;

using namespace std;

// Function prototypes
int** iterativePascal(int degree);
int recursiveBico(int degree, int index);
int** recursivePascal(int degree, int index);

int main () {

int degree = 24;
int index = 7;

auto start = high_resolution_clock::now();

//iterativePascal(degree);
//recursivePascal(degree, index);
recursiveBico(degree, index);

auto stop = high_resolution_clock::now();

auto duration = stop - start;
auto duration_ns = duration_cast<nanoseconds>(duration);

cout << duration_ns.count() << endl;



return 0;
}

// Function to calculate Pascal's Triangle through iteration
int** iterativePascal(int degree) {

  // Allocate memory for Pascal's Triangle with dynamic 2D array
  int ** pascalTri = new int*[degree + 1];

  // Calculate values for each row and column for Pascal's Triangle
  for (int row = 0; row < degree + 1; row++) {
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