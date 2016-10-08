//归并排序 merge sort
#include <stdio.h>  
#include<stdlib.h>  
#include<iostream>
using namespace std;
#define N  11  

void disp(void);

int a[N] = { 121,25,49,25,93,62,72,8,37,16,54 };

//将有二个有序数列a[first...mid]和a[mid...last]合并。  
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	//printf("\n%d,%d,%d", i, m, n);   //打印first,mid,last  

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];

	disp();                       //打印每次合并完的数组  
}
/*递归的进行分解，然后合并*/
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序  
		mergesort(a, mid + 1, last, temp); //右边有序  
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
		//cout << a;
	}
}

//归并排序  
bool MergeSort()
{
	int *p;

	p = (int *)malloc(N * sizeof(int));    //为了分配临时数组  
	if (p != NULL)
	{
		mergesort(a, 0, N - 1, p);
		free(p);
	}
	else
		return false;

}

/*输出函数*/
void disp(void)
{
	int i;

	//    printf("\n排序结果: \n");  
	printf("\n\n");
	for (i = 0; i<N; i++)
	{
		printf("%d", a[i]);
		printf("  ");
	}


}

int main(void)
{
	MergeSort();      //归并排序  
					  //disp();  
	system("pause");
	return 0;

}
