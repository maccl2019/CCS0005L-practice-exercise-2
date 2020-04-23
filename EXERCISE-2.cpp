/**
 * 2. Make a program that will ask for the number of rows
 * and column to output a two-dimensional array using pointers.
 * The program must contains two user-defined function called
 * multimdimensional() to enter the elements of rows and columns
 * and result() to output the two-dimensioanal array.
 * 
 * Created 2020-04-23 08:47:21
 */

#include<iostream>
using namespace std;

int** multiMDimensional(const size_t rows, const size_t cols);
void result(int** array, size_t rows, size_t cols);

int main() {

    int **array;

    int row, col;
    cout << "Enter how many rows: ";
    cin >> row;
    cout << "Enter how many columns: ";
    cin >> col;

    array = multiMDimensional(row, col);
    result(array, row, col);

    return 0;
}

/** NOTE
 * UPDATE: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
 * There *is* a way to do it:
 * 
 * @Mehrdad Afshari (https://stackoverflow.com/users/33708/mehrdad-afshari):
 * int** a = new int*[rowCount];
 * for(int i = 0; i < rowCount; ++i)
 *     a[i] = new int[colCount];
 * 
 * Leaving my original answer as a comment.
 * 
 * The thing is, there is no actual way to declare
 * a 2D array dynamically (UPDATE, there is - look at note above)
 * but understanding the way a table works, we can do a workaround:
 * 
 * Think of this as a 3x4 table:
 * +-----+-----+-----+-----+
 * |   1 |   2 |   3 |   4 |
 * +-----+-----+-----+-----+
 * |   5 |   6 |   7 |   8 |
 * +-----+-----+-----+-----+
 * |   9 |  10 |  11 |  12 |
 * +-----+-----+-----+-----+
 * 
 * It has a size of 3x4 cells, or 12 cells in total
 * Since declaring a 2D array would not be possible,
 * we can instead declare it as a normal array like this:
 * int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
 * Since we know that we have four numbers per row,
 * we can denote them in code instead, so that everytime
 * we hit a multiple of 4, we treat it as a new row.
 * int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
 *             ^ Row 1     ^ Row 2     ^ Row 3
 * 
 * Additionally, saving them would be easy - we just add them
 * sequentially. Accessing them is as easy by multiplying
 * the row and column of the data you want to access.
 * Just make sure to account 0 as the first row and column
 * of the data.
 * 
 * int* multiMDimensional(const size_t rows, const size_t cols) {
 * 
 *     // This declares a new array with the specified size,
 *     // instead of declaring an array with a very big size
 *     // that might not be able to be used, wasting memory.
 *     int *arr = new int[rows * cols];
 *     int count = 0;
 * 
 *     cout << "Data entry: " << endl;
 *     for(int rowCount = 0; rowCount < rows; rowCount++) {
 *         for(int colCount = 0; colCount < cols; colCount++) {
 *         
 *             cout << "Enter data for [" << rowCount << "][" << colCount << "]: ";
 *             cin >> arr[count]; 
 *             count++;
 *         }
 *     }
 * 
 *     return arr;
 * }
 */

int** multiMDimensional(const size_t rows, const size_t cols) {

    // This declares a new array with the specified size,
    // instead of declaring an array with a very big size
    // that might not be able to be used, wasting memory.
    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    cout << "Data entry: " << endl;
    for(int rowCount = 0; rowCount < rows; rowCount++) {
        for(int colCount = 0; colCount < cols; colCount++) {
            cout << "Enter data for [" << rowCount << "][" << colCount << "]: ";
            cin >> arr[rowCount][colCount]; 
        }
    }

    return arr;
}

void result(int** array, size_t rows, size_t cols) {

    cout << "Array data with size " << rows << "x" << cols << ":" << endl;

    int count = 0;
    for(int rowCount = 0; rowCount < rows; rowCount++) {
        for(int colCount = 0; colCount < cols; colCount++) {
            cout << array[rowCount][colCount] << '\t';
        }
        cout << endl;
    }
}

