void swap(int *x,int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}
void quick_sort_rec(int *nums,int start,int end)
{
	if (start >= end)
		return;
	int mid = nums[end];
	int left = start, right = end - 1;
	while(left<right)
	{
		while(nums[left]<mid && left<right)
			left++;
		while(nums[right]>=mid && left<right)
			right--;
		swap(nums+left,nums+right);
	}
	if (nums[left] >= nums[end])
		swap(nums+left,nums+end);
	else
		left++;
	if (left)
		quick_sort_rec(nums,start,left-1);
	quick_sort_rec(nums,left+1,end);
}