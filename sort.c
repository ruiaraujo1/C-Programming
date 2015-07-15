void SelectionSort(int *vec, int size) {
	int i, j, lower_pos, temp;
	
	for (i = 0; i < size-1; i++) {
		
		lower_pos = i;
		
		for(j = i + 1; j < size; j++) {
		
			//'finds' the position of the lowest value of the array
			if(vec[j] < vec[lower_pos])
				lower_pos = j;
		}
		
		if(lower_pos != i) {
			temp = vec[lower_pos];
			vec[lower_pos] = vec[i];
			vec[i] = temp;
		}
	}
}

void BubbleSort(int *vec, int size) {
	int i, Nswitch, temp;
	
	do {
		Nswitch = 0;
		
		for(i = 0; i < size-1; i++) {
			if(vec[i] > vec[i+1]) {
				temp = vec[i];
				vec[i] = vec[i+1];
				vec[i+1] = temp;
				Nswitch++;				
			}
		}
	} while(Nswitch != 0);	
}

void InsertionSort(int vec[], int size) {
	int i, j, temp;
	
	for (i = 1; i < size; i++) {
		
		//stores in a temporary variable the element to insert, so you can move the other elements of the array
		temp = vec[i];
		
		//moves the elements bigger than 'temp' one position to the right
		for (j = i; j > 0 && vec[j-1] > temp; j--) {
			vec[j] = vec[j-1];
		}
		
		//if the element on 'temp' is not in the right position it's inserted on the right position
		if (j != i) {
			vec[j] = temp;
		}
	}
}