/* Maylee Gagnon
 * CS 2223 HW3P2
 * 11.10.19
 *
 */

#include <iostream>
#include <array>
using namespace std;

void printArr(int arr[], int n){
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/* Supose to be done in O(n^2)
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

/* Merges two sorted arrays into one sorted array
 * @param arr1 One of the array to be merged, previously sorted
 * @param arr2 The other array to be merged, previously sorted
 * @return int arr[] One sorted array with the elements from arr1 and arr2
 */
int* merge(int B[], int C[]){
	int p, q;
	int A[p + q -1];
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < p && j < q) {
		if (B[i] <= C[j]) {
			A[k] = B[i];
			i++;
		}
		else {
			A[k] = C[j];
			j++;
		}
		k++;
	}

	if (i == p){
		for (int x = j; x < q; x++){ //C[j..j-1] to A[k..p+q-1]
			A[k] = C[x];
			k++;
		}
	}
	else {
		for (int x = i; x < p; x++){ //B[i..p-1] to A[k..p+q-1]
			A[k] = B[x];
			k++;
		}
	}
	return A;
}

/* Sorts the given array
 * Using recursive merge sort
 * O(nLog(n)(
 * @param arr[] Array to be sorted
 * @param n Number of elements in array
 * @return arr[] Array of sorted items non-decreasing
 */
int* mergeSort(int A[], int n){
	int nHalf = n/2;
	int B[nHalf];
	int C[nHalf];

	if(n>1){
		for (int i = 0; i < nHalf; i++){ // A[0,n/2-1] to B[0,n/2-1]
			B[i] = A[i];
		}
		int pos = 0;
		for (int i = nHalf; i < n; i++){ // A[n/2-1, n-1] to C[0..n/2-1]
			C[pos] = A[i];
		}

		mergeSort(B, nHalf);
		mergeSort(C, nHalf);

		merge(B,C);
	}
	return A;
}


/* Suppose to be done in O(nLog(n))
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
	cout << easyInversionCount(arr, n) << endl;

	// call to fastInversionCount();
	int arr1[5] = {2,4,1,5,6};
	int n1 = 5;
	cout << "orginal" << endl;
	printArr(arr1,n1);
	cout << "sorted" << endl;

	int A[5];
	printArr(mergeSort(arr1,n1),n1);


	return 0;
}
