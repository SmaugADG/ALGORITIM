#include"function.h"
//交换
static void swap(int* a,int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//遍历输出
static void print_s(int arr[],int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
//4.1 简单选择排序
void simp_sort() {
	int arr[] = { 3,6,9,2,1,5,4,7 };
	int i, j, k;
	for (i = 0; i < 8-1;i++) {
		k = i;
		for (j = i + 1; j < 8;j++) {
			if (arr[k]>arr[j]) {
				k = j;
			}
		}
		swap(&arr[i],&arr[k]);
	}

	print_s(arr,8);
	
}

//4.1.2 插入排序
void insert_sort() {
	int arr[] = { 3,6,9,2,1,5,4,7 };
	int i, j, k, tmp;
	for (i = 1; i <= 7;i++) {
		tmp = arr[i]; 
		for (j = 0; j < i;j++) {
			if (tmp<arr[j]) {
				for (k = i; k > j; k--) {
					arr[k] = arr[k - 1];
				}
				arr[k] = tmp;
				break;
			}
		}
	}
	
	print_s(arr,8);
}