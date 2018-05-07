// This program demonstrates performance variations of quicksort and shellsort
// sorting algorithm implementations.

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <cmath>

using namespace std;

// Pseudo Random Number Generator
int randInt(int bottom, int plusUp)
{
    // random int in range [bottom, (bottom + plusUp - 1)]
    return rand() % plusUp + bottom;
}

// part - 1 - quicksort

// This function implements the quicksort sorting algorithm from the book.
// input: an array to be sorted,
//        an int, first, the index of the beginning of the segment to be sorted
//        an int, last, the index of the end       of the segment to be sorted
template<class T>
void drozdekQuickSort(T data[], int first, int last)
{
    int lower = first + 1,
        upper = last;
    swap( data[first], data[ (first + last) / 2 ] );
    T bound = data[first];
    while (lower <= upper)
    {
        while (bound > data[lower])
            lower++;
        while (bound < data[upper])
            upper--;
        if (lower < upper)
            swap(data[lower++], data[upper--]);
        else
            lower++;
    }
    swap(data[upper], data[first]);
    if (first < upper - 1)
        drozdekQuickSort(data, first, upper - 1);
    if (upper + 1 < last)
        drozdekQuickSort(data, upper + 1, last);
}

// This is a helper for the above. It has a different signature.
// This function prepares the array for the above function.
template<class T>
void drozdekQuickSort(T data[], int n)
{
    int i, max;
    if (n < 2)
        return;
    // find largest el and put it at the end of data[]
    for (i = 1, max = 0; i < n; i++)
        if (data[max] < data[i])
            max = i;
    swap(data[n - 1], data[max]); // now largest el is in its final position
    drozdekQuickSort(data, 0, n - 2);
}

// This function tests the quick sort algorithm from the book.
void drozdekQuickSortTester(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    cout << "Unsorted array before Drozdek's quicksort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;

    drozdekQuickSort(nums, dataSetSize);

    cout << "\nSorted array after Drozdek's quicksort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;
    cout << endl;
}

// This function creates and array, to be quicksorted, of random ints 0- 500,000
void drozdekQuickSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    drozdekQuickSort(nums, dataSetSize);
}

// This function implements a quicksort sorting algorithm with a random
// pivot point.
// input: an array to be sorted,
//        an int, first, the index of the beginning of the segment to be sorted
//        an int, last, the index of the end       of the segment to be sorted
template<class T>
void randomPivotQuickSort(T data[], int first, int last)
{
    int pivotIndex = randInt(first, last - first + 1),
        marker = first;
    T pivot = data[pivotIndex];
    swap(data[last], data[pivotIndex]);
    for (int i = first; i <= last - 1; i++)
        if (data[i] < pivot)
        {
            swap(data[marker], data[i]);
            marker++;
        }
    swap(data[marker], data[last]);
    if (first < marker - 1)
        randomPivotQuickSort(data, first, marker - 1);
    if (marker + 1 < last)
        randomPivotQuickSort(data, marker + 1, last);
}

// This function tests the randomPivotQuickSort function.
void randomPivotQuickSortTester(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    cout << "Unsorted array before randomly chosen pivot style quicksort:\n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;

    randomPivotQuickSort(nums, 0, dataSetSize - 1);

    cout << "\nSorted array after randomly chosen pivot style quicksort:\n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;
    cout << endl;
}

// This function creates an array, to be sorted with the random pivot
// quicksort, of random ints, 0 - 500,000
void randomPivotQuickSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    randomPivotQuickSort(nums, 0, dataSetSize - 1);
}

// This function implements a quicksort sorting algorithm using the median
// element as a pivot.
// input: an array to be sorted,
//        an int, first, the index of the beginning of the segment to be sorted
//        an int, last, the index of the end       of the segment to be sorted
template<class T>
void medianQuickSort(T data[], int first, int last)
{
    int lower = first + 1,
        upper = last,
        marker = first,
        medianIndex = (first + last) / 2;
    T median = data[medianIndex];
    swap( data[last], data[medianIndex] );

    for (int i = first; i <= last - 1; i++)
        if (data[i] < median)
        {
            swap(data[marker], data[i]);
            marker++;
        }
    swap(data[marker], data[last]);
    if (first < marker - 1)
        medianQuickSort(data, first, marker - 1);
    if (marker + 1 < last)
        medianQuickSort(data, marker + 1, last);
}

// This function tests the medianQuickSort function.
void medianQuickSortTester(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    cout << "Unsorted array before median element as pivot style quicksort:\n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;

    medianQuickSort(nums, 0, dataSetSize - 1);

    cout << "\nSorted array after median element as pivot style quicksort:\n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;
    cout << endl;
}

// This function creates an array, to be quicksorted with the median pivot
// element quicksort function, of random ints, 0 - 500,000
void medianQuickSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    medianQuickSort(nums, 0, dataSetSize - 1);
}

// This function tests the execution times of the quicksort functions.
void quicksortExecutionTimes()
{
    int sizes[6] = { 5000, 10000, 50000, 100000, 150000, 200000 };
    cout << "Median execution time of random pivot element quicksort with \n";
    for (int i = 0; i < 6; i++)
    {
        using namespace std::chrono;
        int times[5];
        for (int j = 0; j < 5; j++)
        {
            auto begin = high_resolution_clock::now();
            randomPivotQuickSort(sizes[i]);
            auto end = high_resolution_clock::now();
            auto length = duration_cast<microseconds>(end - begin);
            times[j] = length.count();
        }
        sort(times, times + (5 / times[0]));
        cout << "\t" << sizes[i]
             << " elements was " << times[3] << " microseconds.\n";
    }

    cout << "Median execution time of median element pivot quicksort with \n";
    for (int i = 0; i < 6; i++)
    {
        using namespace std::chrono;
        int times[5];
        for (int j = 0; j < 5; j++)
        {
            auto begin = high_resolution_clock::now();
            medianQuickSort(sizes[i]);
            auto end = high_resolution_clock::now();
            auto length = duration_cast<microseconds>(end - begin);
            times[j] = length.count();
        }
        sort(times, times + (5 / times[0]));
        cout << "\t" << sizes[i]
             << " elements was " << times[3] << " microseconds.\n";
    }

    cout << "Median execution time of Drozdek's quicksort with \n";
    for (int i = 0; i < 6; i++)
    {
        using namespace std::chrono;
        int times[5];
        for (int j = 0; j < 5; j++)
        {
            auto begin = high_resolution_clock::now();
            drozdekQuickSort(sizes[i]);
            auto end = high_resolution_clock::now();
            auto length = duration_cast<microseconds>(end - begin);
            times[j] = length.count();
        }
        sort(times, times + (5 / times[0]));
        cout << "\t" << sizes[i]
             << " elements was " << times[3] << " microseconds.\n";
    }
}

// part - 2 - shellsort

// This function implements a shellsort sorting algorithm using
// an internal insertion sort.
// variant 1:
    // increment scheme: h_1 = 1, h_i+1 = 3h_i +1
    // stop with h_t for which h_t+2 >= n
    // (default version w/ different stopping condition)
// input: an array to be sorted,
//        an int, the size of the array to be sorted
// output: nothing
template<class T>
void shellSortInsertionSort(T data[], int n)
{
    int i, j, hCnt, h;
    int increments[20], k;

    // variant 1:
        // increment scheme: h_1 = 1, h_i+1 = 3h_i +1
        // stop with h_t for which h_t+2 >= n
        // (default version w/ diff. stopping condition)
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

// This function tests the shellsort with internal insertion sort
void shellSortInsertionSortTester(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    cout << "Unsorted array before shellsort with internal insertion sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;

    shellSortInsertionSort(nums, dataSetSize);

    cout << "\nSorted array after shellsort with internal insertion sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;
    cout << endl;
}

// This function creates an array, to be sorted with the shellsort with interal
// insertion sort, of random ints, 0 - 500,000
void shellSortInsertionSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    shellSortInsertionSort(nums, dataSetSize);
}

// This function implements a shellsort sorting algorithm using
// an internal insertion sort.
// variant 2:
    // increment scheme: h = 2^k - 1 for k = 1 up
    // to largest k for which (2^k - 1) < n
// input: an array to be sorted,
//        an int, the size of the array to be sorted
template<class T>
void shellSortInsertionSort2KMinus(T data[], int n)
{
    int i, j, hCnt, h;
    int increments[20], k;
    // variant 2:
        // increment scheme: h = 2^k - 1 for k = 1 up
        // to largest k for which (2^k - 1) < n
    for (h = 1, i = 0; h < n; i++)
    {
        increments[i] = h;
        h = pow(2, i + 2) - 1;
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

// This function tests the shellSortInsertionSort2KMinus function.
void shellSortInsertionSort2KMinusTester(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    cout << "Unsorted array before 1st alt. shellsort, insertion sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;

    shellSortInsertionSort2KMinus(nums, dataSetSize);

    cout << "\nSorted array after 1st alt. shellsort, insertion sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;
    cout << endl;
}

// This function creates an array, to be sorted with
// the shellSortInsertionSort2KMinus function, of random ints, 0 - 500,000
void shellSortInsertionSort2KMinus(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    shellSortInsertionSort2KMinus(nums, dataSetSize);
}

// This function implements a shellsort sorting algorithm using
// an internal insertion sort.
// variant 3:
    // increment scheme: h = 2^k + 1 for k = 1 up
    // to largest k for which (2^k + 1) < n
// input: an array to be sorted,
//        an int, the size of the array to be sorted
template<class T>
void shellSortInsertionSort2KPlus(T data[], int n)
{
    int i, j, hCnt, h;
    int increments[20], k;
    // variant 3:
        // increment scheme: h = 2^k + 1 for k = 1 up
        // to largest k for which (2^k + 1) < n
    for (h = 3, i = 0; h < n; i++)
    {
        increments[i] = h;
        h = pow(2, i + 2) + 1;
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

// This function tests the shellSortInsertionSort2KPlus function.
void shellSortInsertionSort2KPlusTester(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    cout << "Unsorted array before 2nd alt. shellsort, insertion sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;

    shellSortInsertionSort2KPlus(nums, dataSetSize);

    cout << "\nSorted array after 2nd alt. shellsort, insertion sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;
    cout << endl;
}

// This function creates an array, to be sorted with the
// shellSortInsertionSort2KPlus function, of random ints, 0 - 500,000
void shellSortInsertionSort2KPlus(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    shellSortInsertionSort2KPlus(nums, dataSetSize);
}

// This function implements a shellsort sorting algorithm using
// an internal selection sort.
// variant 1:
    // increment scheme: h_1 = 1, h_i+1 = 3h_i +1
    // stop with h_t for which h_t+2 >= n
// input: an array to be sorted,
//        an int, the size of the array to be sorted
template<class T>
void shellSortSelectionSort(T data[], int n)
{
    int i, j, hCnt, h;
    int increments[20], k;

    // variant 1:
        // increment scheme: h_1 = 1, h_i+1 = 3h_i +1
        // stop with h_t for which h_t+2 >= n
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
            // selection sort
            for (j = hCnt; j <= n; j += h)
            {
                int smallestIndex = j - h;
                k = j;
                while (k <= n - 1)
                {
                    if (data[k] < data[smallestIndex])
                    {
                        smallestIndex = k;
                    }
                    k += h;
                }
                swap(data[j - h], data[smallestIndex]);
            }

        }
    }
}

// This function tests the shellSortSelectionSort function.
void shellSortSelectionSortTester(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    cout << "Unsorted array before shellsort with internal selection sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;

    shellSortSelectionSort(nums, dataSetSize);

    cout << "\nSorted array after shellsort with internal selection sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;
    cout << endl;
}

// This function creates an array, to be sorted with the
// shellSortSelectionSort function, of random ints, 0 - 500,000
void shellSortSelectionSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    shellSortSelectionSort(nums, dataSetSize);
}

// This function implements a shellsort sorting algorithm using
// an internal selection sort.
// variant 2:
    // increment scheme: h = 2^k - 1 for k = 1 up
    // to largest k for which (2^k - 1) < n
// input: an array to be sorted,
//        an int, the size of the array to be sorted
template<class T>
void shellSortSelectionSort2KMinus(T data[], int n)
{
    int i, j, hCnt, h;
    int increments[20], k;
    // variant 2:
        // increment scheme: h = 2^k - 1 for k = 1 up
        // to largest k for which (2^k - 1) < n
    // create an appropriate number of increments h
    for (h = 1, i = 0; h < n; i++)
    {
        increments[i] = h;
        h = pow(2, i + 2) - 1;
    }

    // loop on the number of different increments h
    for (i--; i >= 0; i--)
    {
        h = increments[i];
        // loop on the number of subarrays h-sorted in the ith pass
        for (hCnt = h; hCnt < 2 * h; hCnt++)
        {
            // using internal selection sort
            for (j = hCnt; j <= n; j += h)
            {
                int smallestIndex = j - h;
                k = j;
                while (k <= n - 1)
                {
                    if (data[k] < data[smallestIndex])
                    {
                        smallestIndex = k;
                    }
                    k += h;
                }
                swap(data[j - h], data[smallestIndex]);
            }

        }
    }
}

// This function tests the shellSortSelectionSort2KMinus function.
void shellSortSelectionSort2KMinusTester(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    cout << "Unsorted array before 1st alt. shellsort, selection sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;

    shellSortSelectionSort2KMinus(nums, dataSetSize);

    cout << "\nSorted array after 1st alt. shellsort, selection sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;
    cout << endl;
}

// This function creates an array, to be sorted with the
// shellSortSelectionSort2KMinus function, of random ints, 0 - 500,000
void shellSortSelectionSort2KMinus(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    shellSortSelectionSort2KMinus(nums, dataSetSize);
}

// This function implements a shellsort sorting algorithm using
// an internal selection sort.
// variant 3:
    // increment scheme: h = 2^k + 1 for k = 1 up
    // to largest k for which (2^k + 1) < n
// input: an array to be sorted,
//        an int, the size of the array to be sorted
template<class T>
void shellSortSelectionSort2KPlus(T data[], int n)
{
    int i, j, hCnt, h;
    int increments[20], k;
    // variant 3:
        // increment scheme: h = 2^k + 1 for k = 1 up
        // to largest k for which (2^k + 1) < n
    // create an appropriate number of increments h
    for (h = 3, i = 0; h < n; i++)
    {
        increments[i] = h;
        h = pow(2, i + 2) + 1;
    }

    // loop on the number of different increments h
    for (i--; i >= 0; i--)
    {
        h = increments[i];
        // loop on the number of subarrays h-sorted in the ith pass
        for (hCnt = h; hCnt < 2 * h; hCnt++)
        {
            // using internal selection sort
            for (j = hCnt; j <= n; j += h)
            {
                int smallestIndex = j - h;
                k = j;
                while (k <= n - 1)
                {
                    if (data[k] < data[smallestIndex])
                    {
                        smallestIndex = k;
                    }
                    k += h;
                }
                swap(data[j - h], data[smallestIndex]);
            }

        }
    }
}

// This function tests the shellSortSelectionSort2KPlus function.
void shellSortSelectionSort2KPlusTester(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    cout << "Unsorted array before 2nd alt. shellsort, selection sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;

    shellSortSelectionSort2KPlus(nums, dataSetSize);

    cout << "\nSorted array after 2nd alt. shellsort, selection sort: \n";
    for (int i = 0; i < dataSetSize; i++)
        cout << nums[i] << endl;
    cout << endl;
}

// This function creates an array, to be sorted with the
// shellSortSelectionSort2KPlus function, of random ints, 0 - 500,000
void shellSortSelectionSort2KPlus(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    shellSortSelectionSort2KPlus(nums, dataSetSize);
}

// This function outputs the median execution times of these 6 functions:
// shellSortInsertionSort,
// shellSortSelectionSort,
// shellSortInsertionSort2KMinus,
// shellSortSelectionSort2KMinus,
// shellSortInsertionSort2KPlus, and
// shellSortSelectionSort2KPlus
// in microseconds.
void shellsortExecutionTimes()
{
    int sizes[6] = { 5000, 10000, 50000, 100000, 150000, 200000 };
    cout << "Median execution time of shellsort with insertion sort:\n";
    for (int i = 0; i < 6; i++)
    {
        using namespace std::chrono;
        int times[5];
        for (int j = 0; j < 5; j++)
        {
            auto begin = high_resolution_clock::now();
            shellSortInsertionSort(sizes[i]);
            auto end = high_resolution_clock::now();
            auto length = duration_cast<microseconds>(end - begin);
            times[j] = length.count();
        }
        sort(times, times + (5 / times[0]));
        cout << "\t" << sizes[i]
             << " elements was " << times[3] << " microseconds.\n";
    }

    cout << "Median execution time of shellsort with selection sort \n";
    for (int i = 0; i < 6; i++)
    {
        using namespace std::chrono;
        int times[5];
        for (int j = 0; j < 5; j++)
        {
            auto begin = high_resolution_clock::now();
            shellSortSelectionSort(sizes[i]);
            auto end = high_resolution_clock::now();
            auto length = duration_cast<microseconds>(end - begin);
            times[j] = length.count();
        }
        sort(times, times + (5 / times[0]));
        cout << "\t" << sizes[i]
             << " elements was " << times[3] << " microseconds.\n";
    }

    cout << "Median execution time of 1st alt. shellsort, insertion sort:\n";
    for (int i = 0; i < 6; i++)
    {
        using namespace std::chrono;
        int times[5];
        for (int j = 0; j < 5; j++)
        {
            auto begin = high_resolution_clock::now();
            shellSortInsertionSort2KMinus(sizes[i]);
            auto end = high_resolution_clock::now();
            auto length = duration_cast<microseconds>(end - begin);
            times[j] = length.count();
        }
        sort(times, times + (5 / times[0]));
        cout << "\t" << sizes[i]
             << " elements was " << times[3] << " microseconds.\n";
    }

    cout << "Median execution time of 1st alt. shellsort, selection sort \n";
    for (int i = 0; i < 6; i++)
    {
        using namespace std::chrono;
        int times[5];
        for (int j = 0; j < 5; j++)
        {
            auto begin = high_resolution_clock::now();
            shellSortSelectionSort2KMinus(sizes[i]);
            auto end = high_resolution_clock::now();
            auto length = duration_cast<microseconds>(end - begin);
            times[j] = length.count();
        }
        sort(times, times + (5 / times[0]));
        cout << "\t" << sizes[i]
             << " elements was " << times[3] << " microseconds.\n";
    }

    cout << "Median execution time of 2nd alt. shellsort, insertion sort:\n";
    for (int i = 0; i < 6; i++)
    {
        using namespace std::chrono;
        int times[5];
        for (int j = 0; j < 5; j++)
        {
            auto begin = high_resolution_clock::now();
            shellSortInsertionSort2KPlus(sizes[i]);
            auto end = high_resolution_clock::now();
            auto length = duration_cast<microseconds>(end - begin);
            times[j] = length.count();
        }
        sort(times, times + (5 / times[0]));
        cout << "\t" << sizes[i]
             << " elements was " << times[3] << " microseconds.\n";
    }

    cout << "Median execution time of 2nd alt. shellsort, selection sort \n";
    for (int i = 0; i < 6; i++)
    {
        using namespace std::chrono;
        int times[5];
        for (int j = 0; j < 5; j++)
        {
            auto begin = high_resolution_clock::now();
            shellSortSelectionSort2KPlus(sizes[i]);
            auto end = high_resolution_clock::now();
            auto length = duration_cast<microseconds>(end - begin);
            times[j] = length.count();
        }
        sort(times, times + (5 / times[0]));
        cout << "\t" << sizes[i]
             << " elements was " << times[3] << " microseconds.\n";
    }
}

int main()
{
    srand(time(0)); // seed the pseudo random number generator
    randomPivotQuickSortTester(20);
    medianQuickSortTester(20);
    drozdekQuickSortTester(20);
    shellSortInsertionSortTester(30);
    shellSortSelectionSortTester(30);
    shellSortInsertionSort2KMinusTester(30);
    shellSortSelectionSort2KMinusTester(30);
    shellSortInsertionSort2KPlusTester(30);
    shellSortSelectionSort2KPlusTester(30);
    quicksortExecutionTimes();
    shellsortExecutionTimes();
    return 0;
}
