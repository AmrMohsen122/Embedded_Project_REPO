void reverseArray(char *arr, char *reversed) {
    int i;
    int j = (sizeof(arr) / sizeof(char)-1);
    
    
    for (i = 0; i < j; i++) {

        reversed[i] = arr[j - (i + 1)];



    }
   
}