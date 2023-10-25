//Programmer Hutson Horton
//Date 10/25/23
//Resources: Class, ChatGPT to translate, Coding with John Videos


#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(int array1[], int length1)
{
    for (int i = 1; i < length1; i++)
    {
        int key = array1[i];
        int j = i - 1;
        // while loop to stop running when we reach the beginning of the array, if bigger than key, key is smallest or equal to key (?)
        while (j >= 0 && array1[j] > key)
        {
            // j + 1 = index position one to the right
            array1[j + 1] = array1[j];
            j = j - 1;
        }
        array1[j + 1] = key;
    }
}
//===========================================================
//                      End of Insertion Sort
//                      Start of MergeSort
//===========================================================
void mergeSort(int array1[], int length1) {
    if (length1 <= 1)
        return;  // Base case: An array with 0 or 1 elements is already sorted.

    int middle = length1 / 2;

    // Recursively sort the left subarray
    int left[middle];
    for (int i = 0; i < middle; i++) {
        left[i] = array1[i];
    }
    mergeSort(left, middle);

    // Recursively sort the right subarray
    int right[length1 - middle];
    for (int i = middle; i < length1; i++) {
        right[i - middle] = array1[i];
    }
    //I wrote the Java code and used ChatGPT to translate it, I later added the comments to ensure I would be able to understand it now and later.


    mergeSort(right, length1 - middle);

    // Merge the sorted subarrays
    //i = Left Half, j = Right Half, k = Merged Array
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < middle && j < length1 - middle) {
        //Compare i'th element of Left Half, and j'th element of Right Half, find smallest number, add to k, our merged array
        //Increment Array w/ lowest number to have another number to compare with
        if (left[i] <= right[j]) {
            array1[k] = left[i];
            i++;
        } else {
            array1[k] = right[j];
            j++;
        }
        //Increment k for a new spot to add sorted integers
        k++;
    }
//Catchall for if there are more elements in one array then there is in another, it will stick it onto the end of the merged array
    while (i < middle) {
        array1[k] = left[i];
        i++;
        k++;
    }
    while (j < length1 - middle) {
        array1[k] = right[j];
        j++;
        k++;
    }
}
//===========================================================
//                      End of Merge Sort
//                      Start of QuickSort
//===========================================================
void quickSort(int array1[], int length1);
void quickSort_recursion(int array1[], int low, int high);
int partition(int array1[], int low, int high);

//int pivot=array1[high];
//Video was cut short to discuss final







int main()
{
    int array1[] = {8, 2, 7, 4, 5, 1, 9, 3, 11, 44, 22, 76, 99, 6};
    int length1 = 14;
//Before Calling Function, Output Unsorted Array to Ensure Sorting is Happening
    cout << "Unsorted array: ";
    for (int i = 0; i < length1; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
//Call Function (Comment Out Functions, use as needed)
insertionSort(array1, length1);
//mergeSort(array1, length1);
//quickSort(array1, length1);
    cout << "Sorted array: ";
    for (int i = 0; i < length1; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    return 0;
}

