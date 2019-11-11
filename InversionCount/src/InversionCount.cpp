/* Maylee Gagnon
 * CS 2223 HW3P2
 * 11.10.19
 *
 */

#include <iostream>
#include <array>
using namespace std;

/* O(n^2)
 * @param arr The array of numbers to be checked
 * @param n The number of elements in array
 * @return The number of inversions found
 *
 */
int easyInversionCount(int arr[], int n){
	int inverCt = 0;
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			if (arr[i] > arr[j]) {
				inverCt++;
			}
		}
	}
	return inverCt;
}

/* O(nLog(n))
 * @param arr The array of numbers to be checked
 * @param n The number of elements in array
 * @return The number of inversions found
 *
 */
int fastInversionCount(){
	return 0;
}
int main() {
	int arr[3] = {3,2,1};
	int n = 3;
	cout << easyInversionCount(arr, n);

	// call to fastInversionCount();

	return 0;
}
