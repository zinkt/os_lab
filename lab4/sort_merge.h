
int comp(int a, int b);


int *merge(int *ary1, int *ary2, int size1, int size2)
{
	int *p1 = ary1;
	int *p2 = ary2;
	int merged_ary[size1+size2];
	int *p3 = merged_ary;
	while(size1>0 && size2>0)
	{
		if(*p1<*p2)
		{
			*p3 = *p1;
			p1++;
			--size1;
		}
		else
		{
			*p3 = *p2;
			p2++;
			--size2;
		}
		p3++;
	}
	if(size1)
		for (int i = 0; i < count; ++i)
		{
			/* code */
		}

}
