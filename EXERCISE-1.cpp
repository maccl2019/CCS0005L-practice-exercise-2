/**
 * 1. Make a program that has four user-defined 
 * functions consisting the arraysubscript()
 * arrayname(),subscriptnotation() and
 * offsetnotation() that will output each elements
 * in different methods. Main function
 * must only contain all the functions being 
 * called and nothing else more.
 * 
 * Created 2020-04-23 08:24:55
 * 
 */

#include<iostream>
using namespace std;

int a[4] = {8, 3, 6, 2};

void arraySubscript();
void arrayName();
void subscriptNotation(int *cPtr);
void offsetNotation(int *cPtr);

int main() {

    cout << "Array subscript notation" << endl;
    arraySubscript();
    cout << endl;

    cout << "Pointer/offset notation where" << endl;
    cout << "the pointer is the array name" << endl;
    arrayName();
    cout << endl;

    cout << "Pointer subscript notation" << endl;
    subscriptNotation(a);
    cout << endl;

    cout << "Pointer/offset notation" << endl;
    offsetNotation(a);
    cout << endl;

    return 0;
}

void arraySubscript() {
    cout << "a[0] = " << a[0] << endl;
    cout << "a[1] = " << a[1] << endl;
    cout << "a[2] = " << a[2] << endl;
    cout << "a[3] = " << a[3] << endl;
};

void arrayName() {
    cout << "*(a + 0) = " << *(a+0) << endl;
    cout << "*(a + 1) = " << *(a+1) << endl;
    cout << "*(a + 2) = " << *(a+2) << endl;
    cout << "*(a + 3) = " << *(a+3) << endl;
};

void subscriptNotation(int *cPtr) {
    cout << "cPtr[0] = " << cPtr[0] << endl;
    cout << "cPtr[1] = " << cPtr[1] << endl;
    cout << "cPtr[2] = " << cPtr[2] << endl;
    cout << "cPtr[3] = " << cPtr[3] << endl;
};

void offsetNotation(int *cPtr) {
    cout << "*(cPtr + 0) = " << *(cPtr+0) << endl;
    cout << "*(cPtr + 1) = " << *(cPtr+1) << endl;
    cout << "*(cPtr + 2) = " << *(cPtr+2) << endl;
    cout << "*(cPtr + 3) = " << *(cPtr+3) << endl;
};
