#include <stdio.h>
#include <iostream>

using namespace std;
/* This function is same in both iterative and recursive*/

/* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
static void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;

    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
       cout<<"TOP :"<<top<<endl;
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];

        // Set pivot element at its correct position in sorted array
        //int p = partition( arr, l, h );
        int x = arr[h];
        int p = (l - 1);

   for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            p++;
           // System.out.println("Zam "+tab[p]+" z "+tab[j]);
            cout<<"Zam "<<arr[p]<<" z "<<arr[j]<<endl;
            swap (arr[p], arr[j]);

        }
    }
    cout<<"W.Zam "<<arr[p+1]<<" z "<<arr[h]<<endl;
    swap (arr[p + 1], arr[h]);


        p++;
        // If there are elements on left side of pivot, then push left
        // side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot, then push right
        // side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}

// A utility function to print contents of arr
void printArr( int arr[], int n )
{
    int i;
    for ( i = 0; i < n; ++i )
         printf( "%d ", arr[i] );
}

// Driver program to test above functions
int main()
{
    int arr[] = {6, 5, 1, 2, 3, 4, 7, 8, 9, 11, 1, 2, 3, 4, 9};
    int n = sizeof( arr ) / sizeof( *arr ); // zajebisty trick ^^
    quickSortIterative( arr, 0, n-1 );
    printArr( arr, n );
    return 0;
}
