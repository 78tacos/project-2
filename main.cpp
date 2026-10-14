#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include "splittimer.h"
using namespace std;
using namespace std::chrono;

vector<int> arr100k(100000);
vector<int> arr200k(200000);
vector<int> arr300k(300000);
vector<int> arr400k(400000);
vector<int> arr500k(500000);
vector<int> sortedArr100k(100000);
vector<int> sortedArr200k(200000);
vector<int> sortedArr300k(300000);
vector<int> sortedArr400k(400000);
vector<int> sortedArr500k(500000);
vector<vector<int>> sortedArrays;
vector<vector<int>> unsortedArrays;


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
  
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortMod(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        int mid = low + (high - low) / 2;
        // partition() always pivots on the last element.
        swap(arr[mid], arr[high]);
        int pi = partition(arr, low, high);

        quickSortMod(arr, low, pi - 1);
        quickSortMod(arr, pi + 1, high);
    }
}

void quickSortRand(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        int randomIndex = low + rand() % (high - low + 1);

        // partition() always pivots on the last element.
        swap(arr[randomIndex], arr[high]);
        int pi = partition(arr, low, high);

        quickSortRand(arr, low, pi - 1);
        quickSortRand(arr, pi + 1, high);
    }
}

void fillArrayRand(vector<int>& arr) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, arr.size() - 1);
    for (auto& i : arr) {
        i = dis(gen);
    }
}

void fillArray(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = i + 1;
    }
}

int main() {

    double timerAvg = 0, totalTime = 0;
    unsortedArrays = {arr100k, arr200k, arr300k, arr400k, arr500k};
    sortedArrays = {sortedArr100k, sortedArr200k, sortedArr300k, sortedArr400k, sortedArr500k};
    
    SplitTimer timer;

    
    cout << "Quicksort on sorted array 100k-500k: " << endl;
    for (size_t j = 0; j < sortedArrays.size(); ++j) {
        cout << "Array #" << j + 1 << ": " << endl;
        for (int i = 0; i < 10; ++i) {
            fillArray(sortedArrays[j]);
            timer.start();
            quickSort(sortedArrays[j], 0, sortedArrays[j].size() - 1);
            totalTime += timer.stop();
        }
        timerAvg = totalTime / 10;
        cout << "Average time of sorted array: " << sortedArrays[j].size() << " using quicksort: " << timerAvg << " ms" << endl;
        totalTime = 0;
    }
    timerAvg = 0;
    

    cout << "\nQuicksort on unsorted arrays 100k-500k: " << endl;
    for (size_t j = 0; j < unsortedArrays.size(); ++j) {
        cout << "Array #" << j + 1 << ": " << endl;
        for (int i = 0; i < 10; ++i) {
            fillArrayRand(unsortedArrays[j]);
            timer.start();
            quickSort(unsortedArrays[j], 0, unsortedArrays[j].size() - 1);
            totalTime += timer.stop();
        }
        timerAvg = totalTime / 10;
        cout << "Average time of unsorted array: " << unsortedArrays[j].size() << " using quicksort: " << timerAvg << " ms" << endl;
        totalTime = 0;
    }
    timerAvg = 0;

    cout << "\nModified quicksort on sorted array 100k-500k: " << endl;
    for (size_t j = 0; j < sortedArrays.size(); ++j) {
        cout << "Array #" << j + 1 << ": " << endl;
        for (int i = 0; i < 10; ++i) {
            fillArray(sortedArrays[j]);
            timer.start();
            quickSortMod(sortedArrays[j], 0, sortedArrays[j].size() - 1);
            totalTime += timer.stop();
        }
        timerAvg = totalTime / 10;
        cout << "Average time of sorted array: " << sortedArrays[j].size() << " using modified quicksort: " << timerAvg << " ms" << endl;
        totalTime = 0;
    }
    timerAvg = 0;

    cout << "\nModified quicksort on unsorted arrays 100k-500k: " << endl;
    for (size_t j = 0; j < unsortedArrays.size(); ++j) {
        cout << "Array #" << j + 1 << ": " << endl;
        for (int i = 0; i < 10; ++i) {
            fillArrayRand(unsortedArrays[j]);
            timer.start();
            quickSortMod(unsortedArrays[j], 0, unsortedArrays[j].size() - 1);
            totalTime += timer.stop();
        }
        timerAvg = totalTime / 10;
        cout << "Average time of unsorted array: " << unsortedArrays[j].size() << " using modified quicksort: " << timerAvg << " ms" << endl;
        totalTime = 0;
    }
    timerAvg = 0;


    cout << "\nRandom quicksort on sorted array 100k-500k: " << endl;
    for (size_t j = 0; j < sortedArrays.size(); ++j) {
        cout << "Array #" << j + 1 << ": " << endl;
        for (int i = 0; i < 10; ++i) {
            fillArray(sortedArrays[j]);
            timer.start();
            quickSortRand(sortedArrays[j], 0, sortedArrays[j].size() - 1);
            totalTime += timer.stop();
        }
        timerAvg = totalTime / 10;
        cout << "Average time of sorted array: " << sortedArrays[j].size() << " using random quicksort: " << timerAvg << " ms" << endl;
        totalTime = 0;
    }
    timerAvg = 0;

    cout << "\nRandom quicksort on unsorted arrays 100k-500k: " << endl;
    for (size_t j = 0; j < unsortedArrays.size(); ++j) {
        cout << "Array #" << j + 1 << ": " << endl;
        for (int i = 0; i < 10; ++i) {
            fillArrayRand(unsortedArrays[j]);
            timer.start();
            quickSortRand(unsortedArrays[j], 0, unsortedArrays[j].size() - 1);
            totalTime += timer.stop();
        }
        timerAvg = totalTime / 10;
        cout << "Average time of unsorted array: " << unsortedArrays[j].size() << " using random quicksort: " << timerAvg << " ms" << endl;
        totalTime = 0;
    }
    timerAvg = 0;

    return 0;
}