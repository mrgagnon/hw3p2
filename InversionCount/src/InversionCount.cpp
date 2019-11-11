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

/* Merges the two arrays that are previously sorted
 * @param arr The two sorted arrays to be merged
 * @param temp The resulting&merged, array with elements from the two given
 * @param lN the start of the array
 * @param mN middle position or where the first array stops
 * @param rN the end of the array
 * @return The number of inversions in the array
 */
int merge(int arr[], int arrResult[], int lN, int mN, int rN){
	cout << "inmerge" << endl;
	int posLeft = lN;
	int posRight = mN;
	int posResult = lN;
	int ct = 0;

	while ((posLeft < mN) && (posRight <= rN)) {
		if (arr[posLeft] <=  arr[posRight]) {
			arrResult[posResult] = arr[posLeft];
			posResult++;
			posLeft++;
		}
		else {
			arrResult[posResult] = arr[posRight];
			posResult++;
			posRight++;

			ct = ct+ (mN-1);
		}
	}

	while (posLeft < mN){
		arrResult[posResult] = arr[posLeft];
		posResult++;
		posLeft++;
	}
	while (posRight <= rN) {
		arrResult[posResult] = arr[posRight];
		posResult++;
		posRight++;
	}

/*
	for (int i = lN; i <rN; i++){
		arr[i] = arrResult[i];
	}*/

	return ct;
}

/* Uses mergeSort to sort the array
 * Divide the array, recursive call for both sides, call ot merge
 * @param arr The array to sorted and checked
 * @param arrTemp A temporary array to use during sorting
 * @param lN Starting position on the left side
 * @param rN Starting position on the right side
 * @return The number of inversions in the array
 */
int mergeSort(int arr[], int arrTemp[], int lN, int rN){
	int ct = 0;
	if (rN > lN){
		cout << "inmergeSort" << endl;
		int mN = (rN+lN)/2;
		cout << "m: " << mN << endl;

		ct+= mergeSort(arr, arrTemp, lN, mN);
		ct+= mergeSort(arr, arrTemp, mN+1, rN);

		ct+= merge(arr, arrTemp, lN, mN+1, rN);
	}
	return ct;
}

/* Suppose to be done in O(nLog(n))
 * Merge sort & count, prints sorted array
 * @param arr The array of numbers to be checked
 * @param n The number of elements in array
 * @return The number of inversions found
 *
 */
int fastInversionCount(int arr[], int size){
	cout << "in fastInversionCount" << endl;
	int tempArr[size];
	int i = mergeSort(arr, tempArr, 0, size-1);
	cout << "tempArr: " << endl;
	printArr(tempArr, size);

	return i;
}

int main() {
	int arr[3] = {3,2,1};
	int n = 3;
	cout << "easy count:" << easyInversionCount(arr, n) << endl;


	// call to fastInversionCount();
	int testArr[4] = {4,2,3,1};
	int n1 = 4; // TODO calculate size
	//int testArr[8] = {19,8,90,7,6,1,3,11};
	//int n1 = 8;
	cout << "orginal:" << endl;
		printArr(testArr,n1);

	cout << "easy count:" << easyInversionCount(testArr, n1) << endl;

	cout << "sorted:" << endl;
	int i = fastInversionCount(testArr, n1);
	cout << "count: " << i << endl;

	return 0;
}
