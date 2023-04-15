#include "Header.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

 
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

    // Fill each array with 1 to n, and then with 1's
    for (int i = 0; i < NUM_ARRAYS; i++)
    {
        // Generate a random natural integer between 1 and ARRAY_SIZE
        int n = rand() % ARRAY_SIZE + 1;

        // Fill the first n cells of the array with 1 to n using pointers
        for (int* ptr = arrays[i]; ptr < arrays[i] + n; ptr++)
        {
            *ptr = ptr - arrays[i] + 1;
        }

        // Fill the rest of the cells with 0's using pointers
        for (int* ptr = arrays[i] + n; ptr < arrays[i] + ARRAY_SIZE; ptr++)
        {
            *ptr = 0;
        }

        lastN = n;
        cout << "First n value for array " << i << " is " << lastN << endl;
    }

    // Print the first 10 cells of the first 10 arrays as a check
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arrays[i][j] << " ";
        }
        cout << endl;
    }

    // prints the full last array
    for (int i = 0; i < 1000; i++)
    {
            cout << arrays[499][i] << " ";
    }
    
    //checks search 1
    int* lastArr = arrays[499];
    int index = Search1(lastArr, 1000, 999);
    cout << index << endl;

    //checks search 2
    index = Search2(lastArr, 1000, 999);
    cout << index << endl;


    // Deallocate the memory used by the arrays
    for (int i = 0; i < NUM_ARRAYS; i++)
    {
       free (arrays[i]);
    }

    free(arrays); 

    return 0;
}