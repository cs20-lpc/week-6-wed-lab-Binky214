#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned);
unsigned fib(unsigned);
unsigned mult(unsigned, unsigned);
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

// TR means tail-recursive function specifically

// AI recommended that I use two functions for accumulation
unsigned fact_tr(unsigned n, unsigned x) {
    if (n <= 1) {
        return x;
    }
    return fact_tr(n - 1, x * n);
}

unsigned fact(unsigned n) {
    return fact_tr(n, 1);
}

unsigned fib_tr(unsigned n, unsigned a, unsigned b) {
    if (n == 0) {
        return a;
    }
    return fib_tr(n - 1, b, a + b);
}

unsigned fib(unsigned n) {
    return fib_tr(n, 0, 1);
}

unsigned mult_tr(unsigned x, unsigned y, unsigned z) {
    if (y == 0) {
        return z;
    }
    return mult_tr(x, y - 1, z + x);
}

unsigned mult(unsigned x, unsigned y) {
    return mult_tr(x, y, 0);
}

unsigned power_tr(unsigned x, unsigned y, unsigned z) {
    if (y == 0) {
        return z;
    }
    return power_tr(x, y - 1, z * x);
}

unsigned power(unsigned x, unsigned y) {
    return power_tr(x, y, 1);
}

unsigned product_tr(unsigned x, unsigned y, unsigned z) {
    if (x > y) {
        return z;
    }
    return product_tr(x + 1, y, z * x);
}

unsigned product(unsigned x, unsigned y) {
    return product_tr(x, y, 1);
}