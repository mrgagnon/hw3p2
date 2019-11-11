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

/*
/* Merges two sorted array back into A
 *
 *
int merge(int B[], int C[], int A[], int Bp, int Cq){
	cout << "merge" << endl;
	cout << "Bp: " << Bp << endl;

	int i = 0;
	int j = 0;
	int k = 0;
	int ct = 0;

	while ((i <= Bp) && (j <= Cq)){
		if (B[i] <= C[j]){
			A[k] = B[i];
			i++;
		}
		else {
			A[k] = C[j];
			j++;

			ct++;  //TODO
		}
		k++;
	}

	if (i == Bp) {
		for (int x = j; x <= Cq -1; x++){ // copy C[j..q-1] to A[k..p+q-1]
			A[k] = C[x];
			k++;
		}
	}
	else {
		for (int x = i; x < Bp; x++){ // copy B[i ..p-1] to A[k..p+q-1]
			A[k] = B[x];
			k++;
		}
	}
	return ct;
}

/*Recursive merge sort
 * @param A Array to be sorted
 * @param n Number of elements in array
 * @return Number of inversions
 *
int mergeSort(int A[], int n){
	cout << "mergeSort" << endl;
	int mid = (n/2)-1;
	int B[mid];
	int C[mid];
	int ct = 0;

	if (n>1){
		cout << "mergeSort n>1" << endl;
		for (int i = 0; i <= mid; i++){
			B[i] = A[i];
		}
		int posC = 0;
		for (int i = (mid+1); i <= n-1; i++){
			C[posC] = A[i];
			posC++;
		}

		ct += mergeSort(B, mid);
		ct += mergeSort(C, mid);

		int Bp = *(&B +1)-B;
		int Cq = *(&C +1)-C;
		ct += merge(B,C,A,Bp,Cq);
		cout << "after merge call" << endl;
	}
	return ct;
}
*/

/* Suppose to be done in O(nLog(n))
 * Merge sort & count, prints sorted array
 * @param arr The array of numbers to be checked
 * @param n The number of elements in array
 * @return The number of inversions found
 *
 */
int fastInversionCount(int arr[], int size){
	cout << "in fastInversionCount" << endl;

	int i = mergeSort(arr,size);
	cout << "arr: " << endl;
	printArr(arr, size);

	return i;
}

int main() {
	int arr[3] = {3,2,1};
	int n = 3;
	cout << "easy count:" << easyInversionCount(arr, n) << endl;


	// call to fastInversionCount();
	int testArr[2] = {4,2};
	int n1 = 2; // TODO calculate size
	//int testArr[4] = {4,2,3,1};
	//int n1 = 4; // TODO calculate size
	//int testArr[8] = {19,8,90,7,6,1,3,11};
	//int n1 = 8;
	//int testArr[4] = {1,2,3,4};
	//int n1 = 4;
	cout << "orginal:" << endl;
		printArr(testArr,n1);

	cout << "easy count:" << easyInversionCount(testArr, n1) << endl;

	cout << "sorted:" << endl;
	int i = fastInversionCount(testArr, n1);
	cout << "count: " << i << endl;

	return 0;
}
