#include <iostream> 
#include "separateChaining.cpp"
#include "linearProbing.cpp"
using namespace std;


// Main function for testing
int main() {
    cout << "=== Separate Chaining Hash Table ===" << endl;
    SeparateChaining<int, string> sc;
    sc.add(1, "Apple");
    sc.add(2, "Banana");
    sc.add(102, "Cherry"); // Collision with index 2
    sc.print();
    cout << "Search 2: " << (sc.search(2) ? "Found" : "Not Found") << endl;
    sc.remove(2);
    sc.print();

    // cout << "\n=== Linear Probing Hash Table ===" << endl;
    // LinearProbing<int, string> lp;
    // lp.add(1, "Apple");
    // lp.add(2, "Banana");
    // lp.add(102, "Cherry"); // Will be placed in next available slot
    // lp.print();
    // cout << "Search 2: " << (lp.search(2) ? "Found" : "Not Found") << endl;
    // lp.remove(2);
    // lp.print();

    return 0;
}
