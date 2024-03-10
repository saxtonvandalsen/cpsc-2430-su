// Saxton Van Dalsen
// lab5.cpp
// 03/06/2024

#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;

using namespace std;

// Function prototypes
void measureSort(void (*sortingFunction)(int*, int));
void percolateDown(int* A, int n, int index);
void heapSort(int* A, int n);
void mergeSort(int* A, int n);
void merge(int* A, int p, int q, int r);
void quickSort(int* A, int n);
int partition(int* A, int i, int j);
void printArray(int* A, int n);

int main () {

    // Function pointer
    void (*sortingFunction)(int*, int);

    cout << endl << "Heap Sort" << endl;
    sortingFunction = &heapSort;
    measureSort(sortingFunction);

    cout << endl << "Merge Sort" << endl;
    sortingFunction = &mergeSort;
    measureSort(sortingFunction);

    // To generate randomized numbers for each sort
    srand(time(nullptr));

    cout << endl << "Quick Sort" << endl;
    sortingFunction = &quickSort;
    measureSort(sortingFunction);

    return 0;
}

// Function that creates unsorted random array to test
// out each sorting algorithm and prints the before and
// after of the process while measuring its execution time
void measureSort(void (*sortingFunction)(int*, int)) {

    int size[] = {10, 100, 1000, 10000, 100000};

    for (int i = 0; i < 5; i++) {

        // Allocating memory for the array
        int* array = new int[size[i]];

        // Using random numbers to fill the array
        for (int j = 0; j < size[i]; j++) {
            array[j] = rand() % 100000;
        }

        // Display size 10 random unsorted array
        if (size[i] == 10) {
            cout << "Unsorted random array: " << endl;
            printArray(array, size[i]);
        }

        // Measuring execution time to sort the unsorted array
        auto start = high_resolution_clock::now();
        sortingFunction(array, size[i]);
        auto stop = high_resolution_clock::now();

        // Calculating the execution time in nanoseconds
        auto duration = duration_cast<nanoseconds>(stop - start);

        // Displaying size 10 sorted array
        if (size[i] == 10) {
            cout << "Sorted array: " << endl;
            printArray(array, size[i]);
        }

        // Display the time measurement with units in nanoseconds
        cout << "Array size " << size[i] << " duration: ";
        cout << duration.count() << " ns." << endl;

        // Freeing allocated memory
        delete[] array;
    }
}

// Recursive function to percolate down the given array with the given index 
// and size (minHeap)
void percolateDown(int* A, int n, int index) {

    int left = 2 * index + 1; // Get left child
    int right = 2 * index + 2; // Get right child
    int smallest = index; // For comparison and swapping indexes

    // Comparing the left child with index and assigning it as smallest
    // if it's smaller than the current index
    if (left < n && A[left] > A[smallest]) {
        smallest = left;
    }

    // Comparing the right child with index and assigning it as smallest
    // if it's smaller than current index
    if (right < n && A[right] > A[smallest]) {
        smallest = right;
    }

    // If current index doesn't equal the smallest value then swapping
    // and recursively calling percolateDown
    if (smallest != index) {
        swap(A[index], A[smallest]);
        percolateDown(A, n, smallest);
    }
}

// Function to build the min heap by calling percolateDown on each non-leaf node
void heapSort(int* A, int n) {

    // Heapify the array to create a min heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        percolateDown(A, n, i);
    }

    // Getting elements from the heap and sorting the array
    for (int i = n - 1; i > 0; i--) {

        // Swapping current index with the last then
        // calling percolateDown with index
        swap(A[0], A[i]);
        percolateDown(A, i, 0);
    }
}

// Function to merge two sorted subarrays into one sorted array
void merge(int* A, int p, int q, int r) {
    
    int leftSize = q - p + 1; // Left subarray size
    int rightSize = r - q; // Right subarray size

    // Temporary vectors for both subarrays
    vector<int> leftSubArray(leftSize);
    vector<int> rightSubArray(rightSize);

    // Storing data from original array A
    // to leftSubArray's data
    for (int i = 0; i < leftSize; i++) {
        leftSubArray[i] = A[p + i];
    }

    // Storing data from original array A
    // to rightSubArray's data
    for (int j = 0; j < rightSize; j++) {
        rightSubArray[j] = A[q + 1 + j];
    }

    int i = 0; // Index of first subArray
    int j = 0; // Index of second subArray
    int k = p; // Index of the merged subArray

    // Iterating through both subarrays and comparing
    // elements to merge into the orignal array
    while (i < leftSize && j < rightSize) {

        // Comparing elements from each subarray
        if (leftSubArray[i] <= rightSubArray[j]) {

            // If left subarray element is smaller then copy
            // into merged subarray and advance index
            A[k] = leftSubArray[i];
            i++;
        } else {

            // If right subarray is smaller then copy into merged
            // subarray and advance its index
            A[k] = rightSubArray[j];
            j++;
        }
        // Advancing merged subarray index
        k++;
    }

    // Copying over remaining elements of left subarray
    // if needed. Advancing indexes accordingly
    while (i < leftSize) {
        A[k] = leftSubArray[i];
        i++;
        k++;
    }

    // Copying over remaining elements of right subarray
    // if needed. Advancing indexes accordingly
    while (j < rightSize) {
        A[k] = rightSubArray[j];
        j++;
        k++;
    }
}

// Function that sorts array A of size n by
// dividing into halves, sorting them each then merging
// together to produces sorted array.
void mergeSort(int* A, int n) {
    
    // As long as n > 1
    if (n > 1) {
        
        int mid = n / 2; // Getting the middle index
        
        mergeSort(A, mid); // Recursively sorting left half
        mergeSort(A + mid, n - mid); // Recursively sorting right half
        merge(A, 0, mid - 1, n - 1); // Calling 'merge' to sort the halves
    }
}

// Function to partition A[i to j] by using a
// randomized pivot. It returns final position of the pivot
int partition(int* A, int i, int j) {

    // Creating a random index to use between
    // the range of i and j
    int randomIndex = rand() % (j - i + 1) + i;
    int pivot = A[randomIndex];

    // Have to move pivot to beginning of array
    swap(A[i], A[randomIndex]);
    
    int m = i; // Initially S1 and S2 are empty

    // Iterating through elements to process S1 and S2
    for (int k = i + 1; k <= j; k++) {
        
        // If element is less than pivot, move to S1
        // increment and swap
        if (A[k] < pivot) {
            m++;
            swap(A[k], A[m]);
        }
    }
    
    swap(A[i], A[m]); // Placing the pivot a the right place
    return m; // Returning pivots final position
}

// Function to sort array A of size n by recursively
// partitioning array around a pivot then sorting the subarrays
// accordingly
void quickSort(int* A, int n) {
    
    // Base case, if already sorted
    if (n <= 1) {
        return;
    }

    int p = partition(A, 0, n - 1); // Obtain position of pivot

    quickSort(A, p); // Sorting elements less than pivot
    quickSort(A + p + 1, n - p - 1); // Sorting elements greater than pivot
}

// Function to print the contents of the array
void printArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}