#include <iostream>
#include "unorderedSet.h"

using namespace std;

int main() {
    // Test integer set
    unorderedSet<int> intSet;
    int intArray[] = { 1, 2, 3, 4, 5, 3 }; // Including a duplicate for testing

    cout << "Integer Set Test:" << endl;
    for (int i = 0; i < 6; ++i) {
        intSet.insertEnd(intArray[i]);
    }

    cout << "Set after inserting elements using insertEnd:" << endl;
    intSet.print(); // Print the set

    // Verify insertAt doesn't allow duplicates
    intSet.insertAt(3, 6); // Inserting a unique item
    intSet.insertAt(4, 3); // Inserting a duplicate item
    cout << "Set after inserting elements using insertAt:" << endl;
    intSet.print();

    // Verify replaceAt doesn't allow duplicates
    intSet.replaceAt(5, 7); // Replacing with a unique item
    intSet.replaceAt(2, 6); // Replacing with a duplicate item
    cout << "Set after replacing elements using replaceAt:" << endl;
    intSet.print();

    // Test string set
    unorderedSet<string> stringSet;
    string stringArray[] = { "apple", "banana", "orange", "banana" }; // Including a duplicate for testing

    cout << "\nString Set Test:" << endl;
    for (int i = 0; i < 4; ++i) {
        stringSet.insertEnd(stringArray[i]);
    }

    cout << "Set after inserting elements using insertEnd:" << endl;
    stringSet.print(); // Print the set

    // Verify insertAt doesn't allow duplicates
    stringSet.insertAt(3, "grape"); // Inserting a unique item
    stringSet.insertAt(4, "orange"); // Inserting a duplicate item
    cout << "Set after inserting elements using insertAt:" << endl;
    stringSet.print();

    // Verify replaceAt doesn't allow duplicates
    stringSet.replaceAt(1, "kiwi"); // Replacing with a unique item
    stringSet.replaceAt(2, "banana"); // Replacing with a duplicate item
    cout << "Set after replacing elements using replaceAt:" << endl;
    stringSet.print();

    // Test union and intersection operations
    unorderedSet<int> intSet1, intSet2, intUnion, intIntersection;
    int intArray1[] = { 1, 2, 3, 4 };
    int intArray2[] = { 3, 4, 5, 6 };

    for (int i = 0; i < 4; ++i) {
        intSet1.insertEnd(intArray1[i]);
        intSet2.insertEnd(intArray2[i]);
    }

    intUnion = intSet1 + intSet2;
    cout << "\nUnion of integer sets:" << endl;
    intUnion.print();

    intIntersection = intSet1 - intSet2;
    cout << "\nIntersection of integer sets:" << endl;
    intIntersection.print();

    return 0;
}
