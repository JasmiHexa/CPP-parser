#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Function defined in this file
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

// Additional utility functions
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
    return "Hello from File A!";
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

int main() {
    cout << "=== File A Main Function ===" << endl;
    
    // Using functions from this file
    int result1 = add(10, 20);
    cout << "Addition result: " << result1 << endl;
    
    vector<int> numbers = {5, 10, 15, 20, 25};
    displayArray(numbers);
    
    double avg = calculateAverage(numbers);
    cout << "Average: " << avg << endl;
    
    // Using additional functions
    int result2 = multiply(5, 6);
    cout << "Multiplication result: " << result2 << endl;
    
    string message = getMessage();
    cout << "Message: " << message << endl;
    
    int powerResult = power(2, 5);
    cout << "2^5 = " << powerResult << endl;
    
    printTable(7);
    
    // Test error cases
    cout << "\n--- Testing Error Cases ---" << endl;
    add(numeric_limits<int>::max(), 1); // Overflow test
    multiply(numeric_limits<int>::max(), 2); // Overflow test
    power(2, 31); // Large power test
    calculateAverage({}); // Empty array test
    displayArray({}); // Empty array test
    printTable(-5); // Negative number test
    
    return 0;
} 