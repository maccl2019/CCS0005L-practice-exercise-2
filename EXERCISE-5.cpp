/**
 * Make a program that will convert decimal number
 * to binary using recursion
 * 
 * Created 2020-04-23 15:49:56
 */

#include<iostream>

// this is a huge int type that supports numbers larger than 2 million.
#define ull unsigned long long

using namespace std;

ull binaryRecursion(int decimal);

int main() {
    ull dec = 0;

    cout << "Enter a decimal number: ";
    cin >> dec;

    cout << "Decimal " << dec << " = 0b" << binaryRecursion(dec);
    return 0;
}

/**
 *  This emulates the technique of getting the remainder
 *  of the number when divided by 2 and using the whole
 *  number of the answer over and over until it reaches
 *  zero.
 * 
 *  Example:
 *  
 *  Given number is 250
 * 
 *  2 | 250 r 0
 *  2 | 125 r 1
 *  2 | 62  r 0
 *  2 | 31  r 1
 *  2 | 15  r 1
 *  2 | 7   r 1
 *  2 | 3   r 1
 *  2 | 1   r 1
 *      0
 * 
 * Answer: 1111 1010
 */


ull binaryRecursion(int decimal) {
    if(decimal == 0) return 0;
    return decimal % 2 + 10 * binaryRecursion(decimal/2);
}