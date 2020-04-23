/**
 * 4. Make a program that will determine if the entered 
 * string is a palindrome or not using the recursion. 
 * Make sure it accepts space and uppercase letter.
 * 
 * Created 2020-04-23 14:59:42
 */

#include<iostream>
#include<string>
using namespace std;

bool palindromeChecker(string word, int startPos, int endPos);

int main() {

    string word;

    cout << "Enter a string: ";
    getline(cin, word);

    // By default, this is set to true. If the user enters nothing,
    // it is automatically a palindrome.
    bool isPalindrome = true;

    if(!word.empty()) {
        isPalindrome = palindromeChecker(word, 0, word.length() - 1);
    }
    
    cout << "Its" << (isPalindrome ? " " : " not ") << "a palindrome" << endl;
    return 0;
}

/**
 * Algorithm:
 * 
 * If the string is made of no letters or just one letter, then it is a palindrome.
 * Otherwise, compare the first and last letters of the string.
 * If the first and last letters differ, then the string is not a palindrome.
 * Otherwise, the first and last letters are the same. Strip them from the string,
 *  and determine whether the string that remains is a palindrome.
 *  Take the answer for this smaller string and use it as the answer for the original string.
 * 
 * Source: https://www.khanacademy.org/computing/computer-science/algorithms/recursive-algorithms/a/using-recursion-to-determine-whether-a-word-is-a-palindrome
 */
bool palindromeChecker(string word, int startPos, int endPos) {
    if(startPos == endPos) return true;
    if(startPos < endPos) { // a little modification to stop comparing when it is overshooting itself
        if(word[startPos] == word[endPos]) {
            return palindromeChecker(word, startPos + 1, endPos - 1);
        } else return false;
    }
    return true;
}