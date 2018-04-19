// This program demonstrates performance variations of quicksort and shellsort
// sorting algorithm implementations.

#include <iostream>
using namespace std;

// part - 1 - quicksort

template<class T>
void quicksort(T data[], int first, int last)
{
    int lower = first + 1,
        upper = last;
    swap( data[first], data[ (first + last) / 2 ] );
    T bound = data[first];
    while (lower <= upper)
    {
        while (bound > data[lower])
        {
            lower++;
        }
        while (bound < data[upper])
        {
            upper--;
        }
        if (lower < upper)
        {
            swap(data[lower++], data[upper--]);
        }
        else
        {
            lower++;
        }
    }
}

template<class T>
void quicksort(T data[], int n)
{
    int i, max;
    if (n < 2)
    {
        return;
    }
    // find largest el and put it at the end of data[]
    for (i = 1, max = 0; i < n; i++)
    {
        if (data[max] < data[i])
        {
            max = i;
        }
    }
    swap(data[n - 1], data[max]); // now largest el is in its final position
    quicksort(data, 0, n - 2);
}

// implement each of 2 techniques for choosing quicksort bound:

    // 1 - using a randomly chosen element from within the portion of
    // the array being sorted

        // generate array of ~20 random ints
        // provide test code of array

    // 2 - using a median element of the first, middle, and last el's of the
    // portion of the array currently being sorted.

        // generate another array of ~20 random ints
        // provide test code of array

// implement the quicksort demo'd on page 514 figure 9.11

    // generate array of ~20 random ints
    // provide test code of array

// run each of the 3 above algos on randomly generated data of these 6 sizes:








    // algo 1
        // 5000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 10000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 50000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 100000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 150000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 200000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time

    // algo 2
        // 5000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 10000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 50000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 100000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 150000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 200000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time

    // algo 3
        // 5000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 10000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 50000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 100000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 150000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time
        // 200000
            // run 1, report MEDIAN execution time
            // run 2, report MEDIAN execution time
            // run 3, report MEDIAN execution time
            // run 4, report MEDIAN execution time
            // run 5, report MEDIAN execution time

// Plot all this data on an Excel spreadsheet
    // x-axis is data size
    // y-axis is the median execution time
    // draw plot lines - each one on the same figure - include a legend
    // you may include more data sizes, if you so choose
    // export the plot chart to a word document and discuss the relative
    // runtime performance of each of the three variants. Which is your fav?

// part - 2 - shellsort


template<class T>
void Shellsort(T data[], int n)
{
    int i, j, hCnt, h;
    int increments[20], k;
    // create an appropriate number of increments h
    for (h = 1, i = 0; h < n; i++)
    {
        increments[i] = h;
        h = 3 * h + 1;
    }
    // loop on the number of different increments h
    for (i--; i >= 0; i--)
    {
        h = increments[i];
        // loop on the number of subarrays h-sorted in the ith pass
        for (hCnt = h; hCnt < 2 * h; hCnt++)
        {
            // insertion sort for subarray containing every hth el of arr data
            for (j = hCnt; j < n; )
            {
                T tmp = data[j];
                k = j;
                while (k - h >= 0 && tmp < data[k - h])
                {
                    data[k] = data[k - h];
                    k -= h;
                }
                data[k] = tmp;
                j += h;
            }
        }
    }
}

int main()
{
    cout << "It's alive\n";

    return 0;
}
