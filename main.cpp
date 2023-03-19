/*
 * By Abdelrahman Taymour --- 20210200
 * Mohamed Sherif --- 20210342
 * Mohamed Alaa Eddin Mostafa --- 20211083
 */
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

template<typename T>
// selection sort
void selectionSort(T array[], int n){
    //index to the current unordered minimum value
    int minimum;
    for (int i = 0; i < n-1; i++) {
        minimum=i;
        /*
         *selects the minimum array item and puts it in place with the sorted array part
         */
        for (int j = i+1; j < n; ++j) {
            if (array[j]<array[minimum]){
                minimum=j;
            }
            if(minimum != i){
                swap(array[minimum],array[i]);
            }

        }
    }
}
template<typename T>
void insertionSort(T array[], int n){
    T current;
    int j;
    //for loops starts from 1 not 0 since we let the first element is the sorted one
    for (int i = 1; i < n; ++i) {
        current=array[i];
        j=i-1;
        /*
         * Loops on every pair of the array then swaps if one is not in his place
         * The loop goes n-1,n-2,n-3 ......3,2,1 loops as the right side of the array gets sorted automatically.
         */
        while (j>=0 && array[j]>current){
            swap(array[j+1],array[j]);
            j=j-1;
        }
        array[j+1]=current;
    }
}
template<typename T>
void BubbleSort(T array[],int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
}

// Merge Sort algorithm

template <typename T>
void merge(T arr[], int Lindex, int middle, int Rindex) {
    int leftSize = middle - Lindex + 1;  // left array size
    int rightSize = Rindex - middle; // Right array size
    //Create the Two sub-arrays
    T leftArr[leftSize];
    T rightArr[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[Lindex + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int leftIndexArr = 0;
    int rightIndexArr = 0;
    int mergedIndex = Lindex;
    //compare the two arrays untill one ends 
    while (leftIndexArr < leftSize && rightIndexArr < rightSize) {
        if (leftArr[leftIndexArr] <= rightArr[rightIndexArr]) {     // if the left item is lower 
                                                                    // improt it to the big array
            arr[mergedIndex++] = leftArr[leftIndexArr++];
        } else {                                                    // if the right item is lower 
                                                                    // improt it to the big array
            arr[mergedIndex++] = rightArr[rightIndexArr++];
        }
    }

    while (leftIndexArr < leftSize) {       // unless it's the end of the first array ipmort the
                                            //items into the bigger array
        arr[mergedIndex++] = leftArr[leftIndexArr++];
    }

    while (rightIndexArr < rightSize) {     // unless it's the end of the second array ipmort the
                                            //items into the bigger array
        arr[mergedIndex++] = rightArr[rightIndexArr++];
    }
}

template <typename T>
void mergeSort(T arr[], int Lindex, int Rindex) {
    //test base case if size of array =1 
    if (Lindex >= Rindex) {
        return;
    }

    int middle = (Lindex + Rindex) / 2; // calculate the mid index

    mergeSort(arr, Lindex, middle); // split the first half and sort
    mergeSort(arr, middle + 1, Rindex); // split the second half and sort

    merge(arr, Lindex, middle, Rindex); // merge the final array sorted
}

template<class T>
void countSort(vector<T> &a) {
    vector<T> v;
    map<T, int> mp;
    for (auto &i: a)
        mp[i]++;
    for (auto &i: mp) {
        for (int j = 0; j < i.second; j++) {
            v.push_back(i.first);
        }
    }
    a = v;
}

template<class T>
int partition(vector<T> &a, int l, int r) {
    int pivot = a[r];
    int pivotIndex = r;
    int j = l;
    int i = l - 1;
    while (i <= r and j <= r) {
        if (a[j] <= pivot) {
            i++;
            swap(a[j], a[i]);
            j++;
        } else {
            j++;
        }
    }
    return i;
}

template<class T>
void quickSort(vector<T> &a, int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

template<class T>
void shellSort(vector<T> &a) {
    int gap = a.size() / 2;
    while (gap) {
        for (int j = gap; j < a.size(); j++) {
            for (int k = j - gap; k >= 0; k -= gap) {
                if (a[k + gap] <= a[k])swap(a[k + gap], a[k]);
                else break;
            }
        }
        gap /= 2;
    }
}


//Main function 
int main() {

    srand(time(nullptr)); // Initialize random seed with current time
    const int N = 10; // Change N to the desired array size

    int arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000; // Generates a random integer between 0 and 999
    }
    cout<<"unsorted: ";
    for (int i = 0; i < N; i++) {
        cout<<arr[i]<<" "; // Generates a random integer between 0 and 999
    }
    int arrSize = N;

    mergeSort(arr, 0,arrSize - 1);
    cout<<endl<<"sorted: ";
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
    }

