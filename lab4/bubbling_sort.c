void bubbling_sort(int *ary, int start, int end)
{
	int temp;
	for (int i = 0; i < end-start; ++i){
		for (int j = 0; j < end-start-i; ++j){
			if(ary[j]>ary[j+1]){
				temp = ary[j];
				ary[j] = ary[j+1];
				ary[j+1] = temp;
			}
		}
	}
}