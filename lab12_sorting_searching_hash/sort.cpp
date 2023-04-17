// CSE2017-01 Data Structure
// Lab 12 - Sorting, Searching, Hash
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 June 2
//
// sort.cpp
// :Implementation of a set of sorting routines


template < class DT >
void selectionSort(DT keyList[], int numKeys) {
	// Selection sort routine. Sorts the first numKeys keys in keyList
	// into ascending order.
	int min;
	for (int i = 0; i < numKeys - 1; i++) {
		min = i;
		for (int j = i + 1; j < numKeys; j++) {
			if (keyList[min] > keyList[j])
				min = j;
		}
		DT temp = keyList[i];
		keyList[i] = keyList[min];
		keyList[min] = temp;
	}
}

//--------------------------------------------------------------------

template < class DT >
void quickPartition(DT keyList[], int numKeys, int left, int right);

template < class DT >
void quickSort(DT keyList[], int numKeys) {
	// Quicksort routine. Sorts the first numKeys keys in keyList into
	// ascending order.
	quickPartition(keyList, numKeys, 0, numKeys - 1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void quickPartition(DT keyList[], int numKeys, int left, int right) {// ¼öÁ¤
	// Recursive partner of the quickSort routine. Partitions the array
	// entries between left and right into two subarrays. One subarray
	// contains the keys that are less than or equal to splitValue, and
	// the other contains the keys that are greater than splitValue.
	// Recursively sorts each of these subarrays.
	if (left < right) {
		int pivot = keyList[(left + right) / 2];
		int l = left;
		int r = right;
		while (l <= r) {
			while (keyList[l] < pivot) l++;
			while (keyList[r] > pivot) r--;
			if (l <= r) {
				DT temp = keyList[l];
				keyList[l] = keyList[r];
				keyList[r] = temp;
				l++;
				r--;
			}
		}
		quickPartition(keyList, numKeys, left, r);
		quickPartition(keyList, numKeys, l, right);
	}
}

//--------------------------------------------------------------------

template < class DT >
void bubbleSort(DT keyList[], int numKeys) {
	for (int i = 0; i < numKeys - 1; i++) {
		for (int j = 0; j < numKeys - 1 - i; j++) {
			if (keyList[j] > keyList[j + 1]) {
				DT temp = keyList[j];
				keyList[j] = keyList[j + 1];
				keyList[j + 1] = temp;
			}
		}
	}
}
