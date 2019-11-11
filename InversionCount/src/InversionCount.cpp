/* Maylee Gagnon
 * CS 2223 HW3P2
 * 11.10.19
 */

#include <iostream>
#include <array>
using namespace std;

/* Prints the given array
 * @param arr The array to be printed
 * @param n The number of elements in the array
 */
void printArr(int arr[], int n){
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/* O(n^2)
 * @param arr The array of numbers to be checked
 * @param n The number of elements in array
 * @return The number of inversions found
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

/* Feathers the two sorted arrays into one
 * Counts the inversions
 * @param arr The actual array being sorted
 * @param temp Place holder array
 * @param l The position of the left array
 * @param m The divide between the two arrays
 * @param r The very end of the array
 * @return the number of inversions
 */
int merge(int arr[], int temp[], int l, int m, int r){
	int i = l; //left array pos
	int j = m; //right array pos
	int k = l; //actual array pos
	int ct = 0 ;

	//compare the values in both arrays, update array/ct as appropriate
	while ((i <= m-1) && (j <= r)){
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			ct += m-i; // update inversion count
		}
	}

	//adds the left over elements to array
	while (i <= m-1){
		temp[k++] = arr[i++];
	}
	while (j <= r){
		temp[k++] = arr[j++];
	}

	//copies new array into the actual array
	for (i = l; i <= r; i++){
		arr[i] = temp[i];
	}
	return ct;
}


/* Actually does the work to sort the arrays. Using merge sort
 * @param arr Array to be sorted
 * @param temp Place holder array
 * @param l The start of the array (changes as the array is split in recursive calls)
 * @parm r The end of the array  (^)
 * @return The number of inversions found in array
 */
int mergeSort(int arr[], int temp[], int l, int r){
	int m;
	int ct  = 0;
	if (r > l) { // array needs to be split
		m = (r+l)/2; //  finding the middle

		ct += mergeSort(arr, temp, l, m); // recursive calls for each of the larger array
		ct += mergeSort(arr, temp, m+1, r);

		ct += merge(arr, temp, l, m+1, r); // call to feather the two arrays together
	}
	return ct;
}

/*  O(nLog(n))
 * Merge sort & count, prints sorted array
 * @param arr The array of numbers to be checked
 * @param n The number of elements in array
 * @return The number of inversions found
 */
int fastInversionCount(int arr[], int size){
	int temp[size];
	int i = mergeSort(arr, temp, 0, size-1);
	cout << "arr: ";
	printArr(temp, size);
	return i;
}

/* Function used to test fastInversionCount. Prints original, prints easy count, prints sorted, prints fast count
 * @param testArr Array to be tested
 * @param n Number of elements in array
 */
void test(int testArr[], int n){
	cout << "orginal:";
	printArr(testArr,n);
	cout << "easy count:" << easyInversionCount(testArr, n) << endl;
	cout << "sorted arr:";
	int i = fastInversionCount(testArr, n);
	cout << "fast count: " << i << endl;
	cout << endl;
}
int main() {
	int arr[3] = {3,2,1};
	int n = 3;
	cout << "easy count:" << easyInversionCount(arr, n) << endl;
	cout << endl;

	//Testing fastInversionCount
	int a1[2] = {4,2};
	test(a1, 2);

	int a2[4] = {4,2,3,1};
	test(a2, 4);

	int a3[8] = {19,8,90,7,6,1,3,11};
	test(a3, 8);

	int a4[4] = {1,2,3,4};
	test(a4, 4);

	return 0;
}
