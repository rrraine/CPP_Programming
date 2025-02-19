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

    cout << "\n=== Linear Probing Hash Table ===" << endl;
    LinearProbing<int, string> lp;
    lp.add(1, "Apple");
    lp.add(2, "Banana");
    lp.add(102, "Cherry"); // Will be placed in next available slot
    lp.print();
    cout << "Search 2: " << (lp.search(2) ? "Found" : "Not Found") << endl;
    lp.remove(2);
    lp.print();

    cout << "\n=== Linear Probing Hash Table<str, int> ===" << endl;
    LinearProbing<string, int> lp2;
    lp2.add("Apple", 1);
    lp2.add("Banana", 2);
    lp2.add("Cherry", 102); // Will be placed in next available slot
    lp2.print();
    cout << "Search Banana: " << (lp2.search("Banana") ? "Found" : "Not Found") << endl;
    lp2.remove("Banana");
    lp2.print();

    return 0;
}
