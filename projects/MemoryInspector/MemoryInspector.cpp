// Memory Inspector - Chapter 7 pointer concepts
// Manages a list of five student quiz scores.

#include <iostream>
#include <iomanip>
using namespace std;

const size_t SIZE = 5; // number of quiz scores

// Task 2: computes the average score using only pointer arithmetic.
double average(const int *scores, size_t size);

// Task 3: swaps two scores using pass-by-reference.
void swapScores(int &a, int &b);

// Task 4: bubble sort, array passed as a pointer; pointer arithmetic only.
void bubbleSort(int *scores, size_t size);

// Task 5:
// The const qualifier tells the compiler (and anyone reading the code) that
// this function only needs to LOOK at the scores, never change them. If any
// statement inside the function tried to modify a score through the pointer
// (for example *(scores + i) = 0;), the compiler would refuse to compile it.
// This protects the caller's data from accidental modification and documents
// the function's intent right in its signature (principle of least privilege).
void printScores(const int *scores, size_t size);

int main() {
    int quizScores[SIZE] = {88, 72, 95, 64, 79};
    int *scoresPtr = quizScores; // pointer to the first element

    // ---- Task 1: pointer definitions and operators ----
    cout << "Task 1: Scores and their memory addresses\n";
    for (size_t i = 0; i < SIZE; ++i) {
        cout << "Score " << *(scoresPtr + i)
             << " is stored at address " << (scoresPtr + i) << '\n';
    }

    cout << "\nTotal size of the array: " << sizeof(quizScores) << " bytes\n";
    cout << "Size of one element:     " << sizeof(*scoresPtr) << " bytes\n";
    cout << "Number of elements:      "
         << sizeof(quizScores) / sizeof(*scoresPtr) << '\n';

    // ---- Task 2: pointer arithmetic and the array relationship ----
    cout << fixed << setprecision(2);
    cout << "\nTask 2: Average score: " << average(scoresPtr, SIZE) << '\n';

    cout << "Address of the third element via array indexing:    "
         << &quizScores[2] << '\n';
    cout << "Address of the third element via pointer arithmetic: "
         << (scoresPtr + 2) << '\n';

    // ---- Task 3: swap the highest and lowest scores ----
    int *highPtr = scoresPtr; // points to the largest score seen so far
    int *lowPtr = scoresPtr;  // points to the smallest score seen so far
    for (size_t i = 1; i < SIZE; ++i) {
        if (*(scoresPtr + i) > *highPtr)
            highPtr = scoresPtr + i;
        if (*(scoresPtr + i) < *lowPtr)
            lowPtr = scoresPtr + i;
    }

    cout << "\nTask 3: Swapping highest (" << *highPtr
         << ") and lowest (" << *lowPtr << ")\n";
    swapScores(*highPtr, *lowPtr);
    cout << "Scores after the swap: ";
    printScores(scoresPtr, SIZE);

    // ---- Task 4: bubble sort ----
    cout << "\nTask 4: Scores before sorting: ";
    printScores(scoresPtr, SIZE);
    bubbleSort(scoresPtr, SIZE);
    cout << "Scores after sorting:  ";
    printScores(scoresPtr, SIZE);

    // ---- Task 5: const-qualified pointer parameter ----
    cout << "\nTask 5: Final scores (printed via const pointer): ";
    printScores(scoresPtr, SIZE);

    return 0;
}

// Returns the average of the scores; receives a pointer and a count,
// and walks the array with pointer arithmetic only.
double average(const int *scores, size_t size) {
    int total = 0;
    for (size_t i = 0; i < size; ++i)
        total += *(scores + i);
    return static_cast<double>(total) / size;
}

// Swaps the two scores referred to by a and b.
void swapScores(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Sorts the scores into ascending order with bubble sort; adjacent
// elements are compared and swapped through pointer arithmetic.
void bubbleSort(int *scores, size_t size) {
    for (size_t pass = 1; pass < size; ++pass) {
        for (size_t i = 0; i < size - pass; ++i) {
            if (*(scores + i) > *(scores + i + 1))
                swapScores(*(scores + i), *(scores + i + 1));
        }
    }
}

// See the comment above the prototype for why the parameter is const:
// this function only reads the scores, and const makes the compiler
// enforce that promise.
void printScores(const int *scores, size_t size) {
    for (size_t i = 0; i < size; ++i)
        cout << *(scores + i) << ' ';
    cout << '\n';
}
