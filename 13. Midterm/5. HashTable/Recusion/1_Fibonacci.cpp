#include <iostream>
#include <cmath>

using namespace std;

long fibo(int n){ // standard 

    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibo(n-1) + fibo(n-2);
}

// in main fibonacci(0, 1, 2, n)
long long fibonacci(long f1, long f2, int i, int n){

    
    if (n == 0) return 0; // base 1
    if (n == 1) return 1; // base 2
    if (i == n) return f2; // stop condition

    return fibonacci(f2, f1 + f2, i + 1, n);
}

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long ans = fibonacci(0, 1, 2, n);
    cout << "Fibonacci of " << n << " is " << ans << endl;

    return 0;
}