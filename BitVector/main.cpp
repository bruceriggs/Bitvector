#include <iostream>
#include "BitVector.h"

using std::cout;

int main(int argc, char** argv) {

    // I want 20 bools
    BitVector myList(20);

    // By default, all 20 are false.

    // Set some random ones to true
    myList.set(3, true);
    myList.set(8, true);
    myList.set(2, true);

    // Use the accessor and size()
    for (int ii = 0; ii < myList.size(); ++ii) {
        cout << ii << ": " << myList[ii] << '\n';
    }
    cout << "---------------------------------\n";

    // There's also the uglier getter
    cout << "0 Again: " << myList.get(0) << '\n';
    cout << "---------------------------------\n";

    // Set them all to true
    myList.setAll(true);
    for (int ii = 0; ii < myList.size(); ++ii) {
        cout << ii << ": " << myList[ii] << '\n';
    }
    cout << "---------------------------------\n";

    // Resize the list
    myList.resize(41);

    // Resizing keeps old data, if possible
    for (int ii = 0; ii < myList.size(); ++ii) {
        cout << ii << ": " << myList[ii] << '\n';
    }
    cout << "---------------------------------\n";

    return 0;
}