# Searching and Sorting Algorithms Analysis

## Overview

This project implements and analyzes four fundamental searching and sorting algorithms using **C++**:

- Binary Search
- Exponential Search
- Merge Sort
- Quick Sort

The primary objective is to understand how these algorithms work, evaluate their time and space complexities, and compare their practical performance through execution-time benchmarks.

## Objectives

- Implement searching and sorting algorithms in C++.
- Understand best-case, average-case, and worst-case time complexities.
- Compare the performance of different algorithms.
- Measure execution time for different input sizes.
- Analyze algorithm efficiency using theoretical and experimental results.

## Algorithms Implemented

| Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Binary Search | O(1) | O(log n) | O(log n) |
| Exponential Search | O(1) | O(log n) | O(log n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |

## Project Structure

```text
Searching-Sorting-Analysis/
│
├── src/
│   └── main.cpp
│
├── docs/
│   └── complexity-analysis.md
│
├── README.md
├── CMakeLists.txt
├── .gitignore
└── LICENSE
```

## Technologies Used

- **Programming Language:** C++
- **Standard:** C++17
- **Compiler:** GCC, Clang, or MSVC
- **Build System:** CMake

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/karyadahal/Group-Assignment_G10.git
```

### 2. Navigate to the project directory

```bash
cd Group-Assignment_G10/Searching-Sorting-Analysis
```

### 3. Compile the program

Using g++:

```bash
g++ -std=c++17 -O2 src/main.cpp -o algorithms
```

### 4. Run the program

On Windows:

```bash
algorithms.exe
```

On Linux/macOS:

```bash
./algorithms
```

## Performance Analysis

The program evaluates algorithm performance using different input sizes:

- 100 elements
- 1,000 elements
- 10,000 elements
- 50,000 elements

Execution time is measured using the C++ `steady_clock` timer. The program also tracks comparisons and checks whether sorting produces the expected result.

## Complexity Analysis

A detailed explanation of the algorithms, including their time and space complexities, is available in:

`docs/complexity-analysis.md`

## Expected Learning Outcomes

After completing this project, users should be able to:

- Explain how searching and sorting algorithms operate.
- Differentiate between logarithmic, linearithmic, and quadratic complexity.
- Understand the practical performance differences between algorithms.
- Interpret benchmarking results.
- Identify suitable algorithms for different problem sizes.

