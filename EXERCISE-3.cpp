/**
 * Make a program that will determine the fibonacci
 * at the desired position number using recursion.
 * 
 * Created 2020-04-23 12:44:35
 */

#include<iostream>
#include<vector>
using namespace std;

int fiboCustom(int pos, int one, int two);

int main() {

    int first, second, pos;

    cout << "Enter the first Fibonacci number: ";
    cin >> first;
    cout << "Enter the second Fibonacci number: ";
    cin >> second;
    cout << "Enter the position of the desired Fibonacci number: ";
    cin >> pos;


    cout << "The Fibonacci number at position " << pos << " is: " << fiboCustom(pos, first, second) << endl;

    cout << endl;

    return 0;
}

/* 
   FIBONACCI: A sequence in which the numbers are made by adding 
   the first two numbers in a list.

   0, 1, 1, 2, 3, 5, 8, 13, 21,...

   0 + 1 is 1,
   1 + 1 is 2,
   1 + 2 is 3,
   2 + 3 is 5,
   so on and so forth.

   Recursion fibonacci
   This was my template to build upon - It relies on
   the num to generate a fibo sequence.
   If the user inputs 5 as num, the following will happen:

                         -----fib(5)-----
                        /                \
                 -fib(4)-                -fib(3)-   
                /        \              /        \ 
            fib(3)      fib(2)          fib(2)   fib(1)
            /    \      /    \         /      \
      fib(2)   fib(1)  fib(1) fib(0)  fib(1) fib(0)
     /     \
   fib(1) fib(0)

   source: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

   // Template:
   int fib(int num) {

       if(num <= 1)
           return num;

       return fib(num - 1) + fib (num - 2);
   }
*/

// With the fibonacci format in mind, instead of returning the number,
// we will use that as the position instead.
int fiboCustom(int pos, int one, int two) {
    switch(pos) {
        // Since the first two values are already given,
        // we might as well make them return a constant
        // number (so that the recursion stops).
        case 1:
            return one;
        case 2:
            return two;

        // This does the recursion of our custom fibonacci.
        // Note that we need to keep the values one and two the same over the
        // duration of this method so we can determine the set from the two 
        // given numbers.
        default:
            return fiboCustom(pos-1, one, two) + fiboCustom(pos-2, one, two);
    }
}