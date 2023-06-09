#include "Header.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()


/*
Name : Ohad Ripshtos
Id : 323012039
I did the assignment on my own with the approval of Proffesor Yossi
*/


const int NUM_ARRAYS = 500;
const int ARRAY_SIZE = 1000;

int lastN = 0;

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create 500 arrays using pointers
    int** arrays = (int ** ) calloc(NUM_ARRAYS,sizeof(int *));

    if (arrays == NULL) 
    { 
        cout << "allocation error";
        return 0;
    }


    for (int i = 0; i < NUM_ARRAYS; i++)
    {
        arrays[i] = (int*)calloc(ARRAY_SIZE, sizeof(int*));
    }


    int sum = 0;

    // Fill each array with 1 to n, and then with 1's
    for (int i = 0; i < NUM_ARRAYS; i++)
    {
        // Generate a random natural integer between 1 and ARRAY_SIZE
        int n = rand() % ARRAY_SIZE + 1;

        // Fill the first n cells of the array with random numbers
        for (int* ptr = arrays[i]; ptr < arrays[i] + n; ptr++)
        {
            *ptr = rand() % ARRAY_SIZE + 1;
        }

        // Fill the rest of the cells with 0's using pointers
        for (int* ptr = arrays[i] + n; ptr < arrays[i] + ARRAY_SIZE; ptr++)
        {
            *ptr = 0;
        }
        
        bubbleSort(arrays[i],n);// Sorts the array using bubble sort !
        
        int x = rand() % ARRAY_SIZE + 1;

        
        sum += Search1(arrays[i], 1000, x);
        sum += Search1(arrays[i], 1000, x);
        sum += Search1(arrays[i], 1000, x);
    }

    sum = sum / 500;

    cout << "in average, the algorithm found the cell index to be : " << sum << endl;

    // prints the full last array
    for (int i = 0; i < 1000; i++)
    {
            cout << arrays[499][i] << " ";
    }
   

    cout << endl;

    // Deallocate the memory used by the arrays
    for (int i = 0; i < NUM_ARRAYS; i++)
    {
       free (arrays[i]);
    }
    
    free(arrays); 

    return 0;
}