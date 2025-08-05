#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the area of a circle
double calculate_circle_area(double radius) {
    cout << "Calculating circle area with radius: " << radius << endl;
    double pi = 3.14159;
    double area = pi * pow(radius, 2);
    cout << "Circle area: " << area << endl;
    return area;
}

// Function to calculate the hypotenuse of a right triangle
double calculate_hypotenuse(double a, double b) {
    cout << "Calculating hypotenuse for sides: " << a << " and " << b << endl;
    double sum_squares = pow(a, 2) + pow(b, 2);
    double hypotenuse = sqrt(sum_squares);
    cout << "Hypotenuse: " << hypotenuse << endl;
    return hypotenuse;
}

// Function to calculate combinations (nCr)
int calculate_combinations(int n, int r) {
    cout << "Calculating combinations C(" << n << ", " << r << ")" << endl;
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    // Calculate factorial for n, r, and (n-r)
    int n_fact = 1, r_fact = 1, nr_fact = 1;
    
    for (int i = 2; i <= n; i++) n_fact *= i;
    for (int i = 2; i <= r; i++) r_fact *= i;
    for (int i = 2; i <= (n-r); i++) nr_fact *= i;
    
    int result = n_fact / (r_fact * nr_fact);
    cout << "Combinations result: " << result << endl;
    return result;
}

// Function to calculate compound interest
double calculate_compound_interest(double principal, double rate, int time) {
    cout << "Calculating compound interest for principal: " << principal 
         << ", rate: " << rate << ", time: " << time << endl;
    double amount = principal * pow(1 + rate, time);
    double interest = amount - principal;
    cout << "Compound interest: " << interest << endl;
    return interest;
}

// Main function to demonstrate calculator functions
int main() {
    cout << "=== Calculator Functions Demo ===" << endl;
    
    // Test circle area calculation
    double circle_area = calculate_circle_area(5.0);
    
    // Test hypotenuse calculation
    double hyp = calculate_hypotenuse(3.0, 4.0);
    
    // Test combinations calculation
    int comb = calculate_combinations(5, 2);
    
    // Test compound interest calculation
    double interest = calculate_compound_interest(1000.0, 0.05, 3);
    
    cout << "\n=== Summary ===" << endl;
    cout << "Circle area: " << circle_area << endl;
    cout << "Hypotenuse: " << hyp << endl;
    cout << "Combinations: " << comb << endl;
    cout << "Compound interest: " << interest << endl;
    
    return 0;
} 