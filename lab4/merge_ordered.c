int *merge_ordered(int *arry1, int *arry2, int size1, int size2)
{
	int *p1 = arry1;
	int *p2 = arry2;
	int *merged = (int *)malloc(sizeof(int) * (size1+size2));
	int i = 0,j = 0, m = 0;
	for (; i < size1 && j < size2;++m)
	{
		if(p1[i] < p2[j])
		{	
			merged[m] = p1[i];
			++i;
		}
		else
		{
			merged[m] = p2[j];
			++j;
		}
	}
	if (size1 - i == 0)
		for (; j < size2; ++j, ++m)
			merged[m] = p2[j];
	else
		for(; i < size1; ++i, ++m)
			merged[m] = p1[i];
	return merged;
}
