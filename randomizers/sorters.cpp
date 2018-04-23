// This program demonstrates performance variations of quicksort and shellsort
// sorting algorithm implementations.

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>

using namespace std;

// This random number generating function is very similar to one found online:
// http://www.cplusplus.com/forum/beginner/183358/
int randInt(int bottom, int plusUp)
{
    // random int in range [bottom, (bottom + plusUp - 1)]
    return rand() % plusUp + bottom;
}

// part - 1 - quicksort

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

// implement the quicksort demo'd on page 514 figure 9.11
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

void drozdekQuickSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    drozdekQuickSort(nums, dataSetSize);
}


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

void randomPivotQuickSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    randomPivotQuickSort(nums, 0, dataSetSize - 1);
}

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

void medianQuickSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    medianQuickSort(nums, 0, dataSetSize - 1);
}

// not DRY, must iterate over container of functions?
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
// Plot all this data on an Excel spreadsheet
    // x-axis is data size
    // y-axis is the median execution time
    // draw plot lines - each one on the same figure - include a legend
    // you may include more data sizes, if you so choose
    // export the plot chart to a word document and discuss the relative
    // runtime performance of each of the three variants. Which is your fav?

// part - 2 - shellsort

template<class T>
void shellSortInsertionSort(T data[], int n)
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

void shellSortInsertionSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    shellSortInsertionSort(nums, dataSetSize);
}

template<class T>
void shellSortSelectionSort(T data[], int n)
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

void shellSortSelectionSort(int dataSetSize)
{
    int nums[dataSetSize];
    for (int i = 0; i < dataSetSize; i++)
        nums[i] = randInt(0, 500001);
    shellSortSelectionSort(nums, dataSetSize);
}

/*
Be	careful;	some	of	these	algorithms	count	up	from	1,	some	generate	numbers	in	a
descending	sequence.		Either	way,	once	you	have	generated	the	increments,	you	will
use	them	in	a	descending	sequence.		In	all	cases,	the	final	iteration	increment	will	be
1.
*/

// variant 1:
    // increment scheme: h_1 = 1, h_i+1 = 3h_i +1
    // stop with h_t for which h_t+2 >= n
    // (default version w/ diff. stopping condition)

        // using internal insertion sort on ~30 elements

        // using internal selection sort on ~30 elements

// variant 2:
    // increment scheme: h = 2^k - 1 for k = 1 up
    // to largest k for which (2^k - 1) < n

    // using internal insertion sort on ~30 elements

    // using internal selection sort on ~30 elements

// variant 3:
    // increment scheme: h = 2^k + 1 for k = 1 up
    // to largest k for which (2^k + 1) < n

    // using internal insertion sort on ~30 elements

    // using internal selection sort on ~30 elements

// variant 4:
    // Fibonacci numbers staring with F(2) = 1 up to largest F(k) < n

    // using internal insertion sort on ~30 elements

    // using internal selection sort on ~30 elements

// variant 5:
    // n/2 is hte increment for the 1st iteration, then
    // h_i = floor(0.75h_i+1) until you reah 1

    // using internal insertion sort on ~30 elements

    // using internal selection sort on ~30 elements

// run each of the 10 above algos on randomly generated data of these 6 sizes:

// not DRY, must iterate over container of functions?
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
}
// Plot all this data on an Excel spreadsheet
    // x-axis is data size
    // y-axis is the median execution time
    // draw plot lines - each one on the same figure - include a legend
    // you may include more data sizes, if you so choose
    // export the plot chart to a word document and discuss the relative
    // runtime performance of each of the three variants. Which is your fav?


int main()
{
    srand(time(0)); // seed the pseudo random number generator

    // randomPivotQuickSortTester(20);
    // medianQuickSortTester(20);
    // drozdekQuickSortTester(20);
    // shellSortInsertionSortTester(20);
    // cout << "This one is broken:\n";
    // shellSortSelectionSortTester(20);
    shellSortSelectionSortTester(20);
    // quicksortExecutionTimes();
    // shellsortExecutionTimes();
    return 0;
}
