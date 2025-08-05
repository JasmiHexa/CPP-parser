#include <iostream>
#include <cmath>

using namespace std;

// Function to demonstrate calculator functions
void demonstrate_calculator_functions() {
    cout << "\n=== Calculator Functions Demonstration ===" << endl;
    
    // Calculate circle area
    double radius = 3.0;
    double pi = 3.14159;
    double area = pi * pow(radius, 2);
    cout << "Circle area with radius " << radius << ": " << area << endl;
    
    // Calculate hypotenuse
    double a = 5.0, b = 12.0;
    double hypotenuse = sqrt(pow(a, 2) + pow(b, 2));
    cout << "Hypotenuse for sides " << a << " and " << b << ": " << hypotenuse << endl;
    
    // Calculate combinations
    int n = 6, r = 3;
    int numerator = 1, denominator = 1;
    for (int i = 2; i <= n; i++) numerator *= i;
    for (int i = 2; i <= r; i++) denominator *= i;
    for (int i = 2; i <= (n-r); i++) denominator *= i;
    int combinations = numerator / denominator;
    cout << "Combinations C(" << n << ", " << r << "): " << combinations << endl;
    
    // Calculate compound interest
    double principal = 500.0, rate = 0.08;
    int time = 2;
    double amount = principal * pow(1 + rate, time);
    double interest = amount - principal;
    cout << "Compound interest for $" << principal << " at " << (rate*100) << "% for " << time << " years: $" << interest << endl;
}

// Function to perform complex calculation
double complex_calculation(double x, double y) {
    cout << "Performing complex calculation with x=" << x << " and y=" << y << endl;
    
    // Calculate absolute values
    double abs_x = abs(x);
    double abs_y = abs(y);
    
    // Calculate squares
    double power_x = pow(abs_x, 2);
    double power_y = pow(abs_y, 2);
    
    // Calculate sum and square root
    double sum = power_x + power_y;
    double result = sqrt(sum);
    
    // Calculate associated circle area
    double pi = 3.14159;
    double circle_area = pi * pow(result, 2);
    
    cout << "Complex calculation result: " << result << endl;
    cout << "Associated circle area: " << circle_area << endl;
    
    return result;
}

int main() {
    cout << "=== Cross-File Function Call Demonstration ===" << endl;
    
    // Test the complex calculation function
    cout << "\nTesting complex calculation:" << endl;
    double result1 = complex_calculation(3.0, 4.0);
    
    // Test the calculator functions demonstration
    demonstrate_calculator_functions();
    
    // Test another complex calculation
    cout << "\nTesting another complex calculation:" << endl;
    double result2 = complex_calculation(-5.0, 12.0);
    
    cout << "\n=== Final Results ===" << endl;
    cout << "Complex calculation 1 result: " << result1 << endl;
    cout << "Complex calculation 2 result: " << result2 << endl;
    
    return 0;
} 