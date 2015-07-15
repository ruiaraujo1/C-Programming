int standart_search(int elem, int *vec, int size) {
	int i = 0;
	
	while ((i < size) && (elem != vec[i]))
		i++;
	
	
	if(i == size)
		return -1; //elem does not exist
	else
		return i;
}


//Array is sorted in ascending order
int sequencial_search_as(int elem, int *vec, int size) {
	int i = 0;
	
	while ((i < size) && (vec[i] < elem)) 
		i++;

	
	if ((i < size) && (elem == vec[i])) 
		return i;
	else 
		return -1; //elem does not exist

}


//Array is sorted in decreasing order
int sequencial_search_de(int elem, int *vec, int size) {
	int i = 0;
	
	while ((i < size) && (vec[i] > elem))
		i++;
	
	if ((i < size) && (elem == vec[i]))
		return i;
	else 
		return -1; //elem does not exist
}


int binary_search(int elem, int *vec, int size) {
	int begin = 0, end = size - 1, middle, k = -1;
	
	while ((begin <= end) && (k == -1)) {
		middle = (begin + end) / 2;
		
		if(elem == vec[middle]) {
			k = middle;
		}
		else {
			if(elem > vec[middle]) {
				begin = middle + 1;
			}
			else {
				end = middle - 1;
			}
		}
	}
	
	return k;
	
}


int binary_search_recursive(int elem, int *vec, int begin, int end) {
	int middle;
	
	if (begin > end) {
		return -1; //elem does not exist
	}
	
	middle = (begin + end) / 2;
	
	if (elem == vec[middle]) {
		return middle;
	}
	
	if (elem > vec[middle]) {
		return binary_search_recursive(elem, vec, middle + 1, end);
	}
	else {
		return binary_search_recursive(elem, vec, begin, middle - 1);		
	}
}