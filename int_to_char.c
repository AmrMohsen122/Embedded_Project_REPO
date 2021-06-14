
void reverseArray(char *arr, char *reversed) {
    int i;
    int j = (sizeof(arr) / sizeof(char)-1);
    for (i = 0; i < j; i++) {
        reversed[i] = arr[j - (i + 1)];
    }
<<<<<<< HEAD
=======
   
>>>>>>> d10dc64c60bcea787c2ea0222af414e49a180f3e
}

char *int_to_char(int x){
	int i;
	static char arr[5];
	
	if(x == 0){
		arr[0] = '0';
		arr[1] = '\0';
	}
	for(i = 0 ; x != 0; i++){
		arr[i] = (int) (x % 10) + 48;
		x /= 10;
		if(x == 0){
			arr[i+1] = '\0';
		}
	
	}
	
	return arr;	
}
