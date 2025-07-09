#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// ================== SEARCH ALGORITHMS AND ANALYSIS ==================

void analyzeBinarySearch(int size, int result, int target, const vector<int>& arr, long duration) {
    cout << "\nBinary Search Complexity Analysis:\n";
    cout << "Array size: " << size << "\n";
    cout << "Best case: O(1) - element found at first comparison (middle)\n";
    cout << "Average case: O(log n) - ~" << log2(size) << " comparisons\n";
    cout << "Worst case: O(log n) - up to " << ceil(log2(size)) << " comparisons\n";
    cout << "Actual time taken: " << duration << " microseconds\n";

    if (result != -1) {
        if (arr[size / 2] == target) {
            cout << "Actual case: Best case (found at middle)\n";
        } else {
            cout << "Actual case: Average case (found after " << ceil(log2(size)) << " comparisons)\n";
        }
    } else {
        cout << "Actual case: Worst case (element not found)\n";
    }
}

void analyzeExponentialSearch(int size, int result, int target, const vector<int>& arr, long duration) {
    cout << "\nExponential Search Complexity Analysis:\n";
    cout << "Array size: " << size << "\n";
    cout << "Best case: O(1) - element found at first position\n";
    cout << "Average case: O(log i) - where i is target position\n";
    cout << "Worst case: O(log n) - ~" << 2 * ceil(log2(size)) << " operations\n";
    cout << "Actual time taken: " << duration << " microseconds\n";

    if (result != -1) {
        if (arr[0] == target) {
            cout << "Actual case: Best case (found at first position)\n";
        } else {
            cout << "Actual case: Average case (found after range finding and binary search)\n";
        }
    } else {
        cout << "Actual case: Worst case (element not found)\n";
    }
}

int binarySearch(const vector<int>& arr, int target, long& duration) {
    auto start = steady_clock::now();
    
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            duration = duration_cast<microseconds>(steady_clock::now() - start).count();
            return mid;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    duration = duration_cast<microseconds>(steady_clock::now() - start).count();
    return -1;
}

int exponentialSearch(const vector<int>& arr, int target, long& duration) {
    auto start = steady_clock::now();
    
    if (arr.empty()) {
        duration = duration_cast<microseconds>(steady_clock::now() - start).count();
        return -1;
    }
    if (arr[0] == target) {
        duration = duration_cast<microseconds>(steady_clock::now() - start).count();
        return 0;
    }

    int i = 1;
    while (i < arr.size() && arr[i] <= target) i *= 2;

    int left = i / 2;
    int right = min(i, (int)arr.size() - 1);
    long binarySearchTime = 0;
    int result = binarySearch(vector<int>(arr.begin() + left, arr.begin() + right + 1), target, binarySearchTime);
    
    duration = duration_cast<microseconds>(steady_clock::now() - start).count();
    return (result != -1) ? left + result : -1;
}

// ================== SORT ALGORITHMS ==================

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1); //Temporary Array
    int i = left, j = mid + 1, k = 0;// Indices for left, right and temp arrays
    // Merge while both halves have elements
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++]; //Take from left
        else temp[k++] = arr[j++]; //Take from right
    }
    // Copy remaining elements from left and right halves
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    // Copy back to original array
    for (int idx = 0; idx < k; idx++) arr[left + idx] = temp[idx];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find middle point
        mergeSort(arr, left, mid); // Sort first half
        mergeSort(arr, mid + 1, right); // Sort second half
        merge(arr, left, mid, right); // Merge the sorted halves`
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; //Choose last element as pivot
    int i = low - 1; // Tracks the rightmost element < pivot 
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); //Move smaller elemets left
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); //Partition Index
        quickSort(arr, low, pi - 1); // sort left of pivot
        quickSort(arr, pi + 1, high); // sort right of pivot
    }
}

// ================== UTILITY FUNCTIONS ==================

vector<int> generateRandomArray(int n) {
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, n);
    for (int& num : arr) num = distrib(gen);
    return arr;
}

void printAlgorithmAnalysis(const string& name, const string& best, 
                            const string& avg, const string& worst) {
    cout << "\nAlgorithm: " << name << "\n";
    cout << "Best Case: " << best << "\n";
    cout << "Average Case: " << avg << "\n";
    cout << "Worst Case: " << worst << "\n";
}

// ================== MAIN FUNCTION ==================

int main() {
    int N;
    cout << "Enter number of elements (N): ";
    cin >> N;

    vector<int> numbers(N);
    cout << "Random numbers generated: ";
    for (int i = 0; i < N; ++i) {
        numbers[i] = rand() % N;
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Sort the numbers for search algorithms
    cout << "Sorted numbers: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    int target;
    cout << "Enter number to search: ";
    cin >> target;

    // Binary Search with timing
    long binDuration = 0;
    int binResult = binarySearch(numbers, target, binDuration);
    if (binResult != -1) cout << "\nBinary Search: Element found at index " << binResult << endl;
    else cout << "\nBinary Search: Element not found." << endl;
    analyzeBinarySearch(numbers.size(), binResult, target, numbers, binDuration);

    // Exponential Search with timing
    long expDuration = 0;
    int expResult = exponentialSearch(numbers, target, expDuration);
    if (expResult != -1) cout << "\nExponential Search: Element found at index " << expResult << endl;
    else cout << "\nExponential Search: Element not found." << endl;
    analyzeExponentialSearch(numbers.size(), expResult, target, numbers, expDuration);

    // Sorting time analysis
    vector<int> arr = generateRandomArray(N);

    cout << "\n=== SORT OPERATIONS ===\n";

    vector<int> mergeArr = arr;
    auto start = steady_clock::now();
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    auto stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nMerge Sort:\n";
    cout << "Time taken: " << duration.count() << " microseconds\n";
    cout << "Sorted correctly: " << (is_sorted(mergeArr.begin(), mergeArr.end()) ? "Yes" : "No") << "\n";
    printAlgorithmAnalysis("Merge Sort", "O(n log n)", "O(n log n)", "O(n log n)");

    vector<int> quickArr = arr;
    start = steady_clock::now();
    quickSort(quickArr, 0, quickArr.size() - 1);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nQuick Sort:\n";
    cout << "Time taken: " << duration.count() << " microseconds\n";
    cout << "Sorted correctly: " << (is_sorted(quickArr.begin(), quickArr.end()) ? "Yes" : "No") << "\n";
    printAlgorithmAnalysis("Quick Sort", "O(n log n)", "O(n log n)", "O(n^2)");

    // Runtime with varying input sizes
    cout << "\n=== RUNTIME ANALYSIS WITH VARYING INPUT SIZES ===\n";
    vector<int> sizes = {100, 1000, 10000, 50000};
    cout << "Size\tMerge(µs)\tQuick(µs)\tBinary(µs)\tExponential(µs)\n";
    for (int size : sizes) {
        vector<int> testArr = generateRandomArray(size);
        sort(testArr.begin(), testArr.end());
        int testTarget = rand() % (size * 2);  // May or may not be in array

        // Merge Sort
        vector<int> mergeTest = testArr;
        start = steady_clock::now();
        mergeSort(mergeTest, 0, mergeTest.size() - 1);
        auto mergeTime = duration_cast<microseconds>(steady_clock::now() - start).count();

        // Quick Sort
        vector<int> quickTest = testArr;
        start = steady_clock::now();
        quickSort(quickTest, 0, quickTest.size() - 1);
        auto quickTime = duration_cast<microseconds>(steady_clock::now() - start).count();

        // Binary Search
        long binTime = 0;
        binarySearch(testArr, testTarget, binTime);

        // Exponential Search
        long expTime = 0;
        exponentialSearch(testArr, testTarget, expTime);

        cout << size << "\t" << mergeTime << "\t\t" << quickTime << "\t\t" 
             << binTime << "\t\t" << expTime << "\n";
    }
    
    int wait;
    cin>>wait;
    return 0;
}