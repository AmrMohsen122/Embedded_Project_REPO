void reverseArray(char *arr, char *reversed) {
    int i;
    int j = (sizeof(arr) / sizeof(char)-1);
    
    
    for (i = 0; i < j; i++) {

        reversed[i] = arr[j - (i + 1)];



    }
   
}

char *int_to_char(int x){
	int i;
	char arr[5];
	static char reversed[5];
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
	reverseArray(arr,reversed);
	return reversed;	
}