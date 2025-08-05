#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Function defined in this file
int multiply(int a, int b) {
    // Check for integer overflow
    if (a != 0 && b != 0) {
        if (a > 0 && b > 0 && a > numeric_limits<int>::max() / b) {
            cout << "Warning: Integer overflow detected in multiplication" << endl;
            return 0;
        }
        if (a < 0 && b < 0 && a < numeric_limits<int>::max() / b) {
            cout << "Warning: Integer overflow detected in multiplication" << endl;
            return 0;
        }
    }
    return a * b;
}

string getMessage() {
    return "Hello from File B!";
}

int power(int base, int exponent) {
    if (exponent < 0) {
        cout << "Error: Negative exponent not supported" << endl;
        return 0;
    }
    
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        if (result > numeric_limits<int>::max() / base) {
            cout << "Warning: Integer overflow detected in power calculation" << endl;
            return 0;
        }
        result *= base;
    }
    return result;
}

void printTable(int n) {
    if (n < 0) {
        cout << "Error: Cannot print table for negative number" << endl;
        return;
    }
    
    cout << "Multiplication table for " << n << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << multiply(n, i) << endl;
    }
}

// Additional utility functions
int add(int a, int b) {
    // Check for integer overflow
    if ((b > 0 && a > numeric_limits<int>::max() - b) ||
        (b < 0 && a < numeric_limits<int>::min() - b)) {
        cout << "Warning: Integer overflow detected in addition" << endl;
        return 0;
    }
    return a + b;
}

double calculateAverage(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Error: Cannot calculate average of empty array" << endl;
        return 0.0;
    }
    
    long long sum = 0; // Use long long to prevent overflow
    for (int value : arr) {
        sum += value;
    }
    return static_cast<double>(sum) / arr.size();
}

void displayArray(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is empty" << endl;
        return;
    }
    
    cout << "Array elements: ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << endl;
}

// Advanced functions
int findMax(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Error: Cannot find maximum of empty array" << endl;
        return 0;
    }
    return *max_element(arr.begin(), arr.end());
}

int findMin(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Error: Cannot find minimum of empty array" << endl;
        return 0;
    }
    return *min_element(arr.begin(), arr.end());
}

void sortArray(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is already empty" << endl;
        return;
    }
    sort(arr.begin(), arr.end());
    cout << "Array sorted successfully" << endl;
}

int main() {
    cout << "=== File B Main Function ===" << endl;
    
    // Using functions from this file
    int result1 = multiply(8, 9);
    cout << "Multiplication result: " << result1 << endl;
    
    int powerResult = power(2, 5);
    cout << "2^5 = " << powerResult << endl;
    
    printTable(7);
    
    // Using additional functions
    int result2 = add(15, 25);
    cout << "Addition result: " << result2 << endl;
    
    vector<int> data = {2, 4, 6, 8, 10, 12};
    displayArray(data);
    
    double avg = calculateAverage(data);
    cout << "Average of data: " << avg << endl;
    
    // Using advanced functions
    int maxVal = findMax(data);
    cout << "Maximum value: " << maxVal << endl;
    
    int minVal = findMin(data);
    cout << "Minimum value: " << minVal << endl;
    
    vector<int> unsortedData = {12, 4, 8, 2, 10, 6};
    cout << "Before sorting: ";
    displayArray(unsortedData);
    sortArray(unsortedData);
    cout << "After sorting: ";
    displayArray(unsortedData);
    
    // Test error cases
    cout << "\n--- Testing Error Cases ---" << endl;
    multiply(numeric_limits<int>::max(), 2); // Overflow test
    power(2, 31); // Large power test
    add(numeric_limits<int>::max(), 1); // Overflow test
    calculateAverage({}); // Empty array test
    displayArray({}); // Empty array test
    findMax({}); // Empty array test
    findMin({}); // Empty array test
    sortArray({}); // Empty array test
    printTable(-5); // Negative number test
    power(2, -3); // Negative exponent test
    
    return 0;
} 