#include <stdio.h>
#include <time.h>
#include "session5_sort.h"

int main()
{
    double time_spent = 0.0;
    int numRecords;
    long int comparisons;
    clock_t begin, end;

    scanf("%d", &numRecords);

    Record arr[numRecords], arrcopy[numRecords];

    for (int i = 0; i < numRecords; i++)
    {
        scanf("%ld %d", &arr[i].serialnumber, &arr[i].score);
    }

    for (int i = 0; i < numRecords; i++)
    {
        arrcopy[i] = arr[i];
    }

    begin = clock();

    comparisons = InsertionSort(arrcopy, numRecords);

    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Insertion sort: %ld %lf\n", comparisons, time_spent);

    for (int i = 0; i < numRecords; i++)
    {
        arrcopy[i] = arr[i];
    }

    begin = clock();

    comparisons = BubbleSort(arrcopy, numRecords);

    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Bubble sort: %ld %lf\n", comparisons, time_spent);

    for (int i = 0; i < numRecords; i++)
    {
        arrcopy[i] = arr[i];
    }

    begin = clock();

    comparisons = SelectionSort(arrcopy, numRecords);

    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Selection sort: %ld %lf\n", comparisons, time_spent);

    return 0;
}

long int InsertionSort(Record *A, int n)
{
    long int counter = 0;

    for (int i = 1; i < n; ++i)
    {
        Record temp = A[i];
        int j = i - 1;
        while (j >= 0 && A[j].serialnumber > temp.serialnumber)
        {
            A[j + 1] = A[j];
            j = j - 1;
            counter++;
        }

        A[j + 1] = temp;
        if (j != -1)
            counter++;
    }
    return counter;
}

int isSorted(Record *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i].serialnumber > a[i + 1].serialnumber)
            return 0;
    }
    return 1;
}

long int BubbleSort(Record *a, int n)
{
    if (isSorted(a, n))
        return 0;
    else
    {
        long int ctr = 0;
        int j;
        for (int i = 0; i < n - 1; i++)
        {
            int noswaps = 1;
            for (j = 0; j < n - i - 1; j++)
            {
                ctr++;
                if (a[j].serialnumber > a[j + 1].serialnumber)
                {
                    Record temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    noswaps = 0;
                }
            }

            if (noswaps == 1)
                return ctr;
        }
        return ctr;
    }
}

long int SelectionSort(Record *a, int n)
{
    long int ctr = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        int j;
        for (j = i + 1; j < n; ++j)
        {
            if (a[j].serialnumber < a[min].serialnumber)
                min = j;
            ctr++;
        }
        Record temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
    }
    return ctr;
}