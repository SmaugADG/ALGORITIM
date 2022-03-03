#include"function.h"

//3.1 ¡¾PATB1001¡¿
int callatz(void) {
	int n,count=0;
	scanf("%d",&n);
	while (n>1) {
		if (n%2==0) {
			n /= 2;
		}
		else {
			n = (n * 3 + 1)/2;
		}
		count++;
	}
	return count;
}

// ¡¾PATB1032¡¿
void digger(void) {

	int i,j, score,num;
	int max = 0;
	int arr[100000] = { 0 };
	scanf("%d",&num);
	for (i = 0; i < num;i++) {
		scanf("%d %d",&j,&score);
		arr[j - 1] += score;
	}
	for (i = 0; i < num;i++) {
		if (max<arr[i]) {
			max = arr[i];
			j = i+1;
		}
	}

	printf("%d %d",j,max);
	return;
}

//3.2¡¾codeup1934¡¿
void search_memb() {
	int n,i,val;
	int arr[10] = { 0 };
	scanf("%d",&n);
	for (i = 0; i < n;i++) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&val);
	int k=-1;
	for (i = 0; i < n;i++) {
		if (arr[i]==val) {
			k = i;
			break;
		}
	}
	printf("%d",k);
}

//3.3¡¾PATB1036¡¿
void print_square(void) {
	int i,j, row, col;
	char ch;
	scanf("%d %c",&col,&ch);
	if (col%2==0) {
		row = col / 2;
	}
	else {
		row = col / 2 + 1;
	}
	for (i = 0; i < row;i++) {
		printf("%c", ch);
		for (j = 1; j < col-1;j++) {
			if (i==0||i==row-1) {
				printf("%c",ch);
			}
			else {
				printf(" ");
			}
		}
		printf("%c\n", ch);
	}
	return;
}

//3.4 ¡¾codeup1928¡¿
static int is_leap(int year) {
	return (year %4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
void date_sub(void) {
	int date[13][2] = { {0,0},{31,31},{28,29}, {31,31},{30,30},
		{31,31},{30,30}, {31,31}, {31,31},{30,30}, {31,31},
		{30,30}, {31,31} };
	int date1, y1,m1,d1;
	int date2, y2,m2,d2;
	scanf("%d %d",&date1,&date2);
	if (date1>date2) {
		int tmp;
		tmp = date1;
		date1 = date2;
		date2 = tmp;
	}
	y1 = date1 / 10000; m1 = (date1 % 10000) / 100; d1 = date1 % 100;
	y2 = date2 / 10000; m2 = (date2 % 10000) / 100; d2 = date2 % 100;
	int count=1;
	while (y1<y2||m1<m2||d1<d2) {
		d1++;
		if (d1== date[m1][is_leap(y1)]+1) {
			m1++;
			d1 = 1;
		}
		if (m1==13) {
			y1++;
			m1 = 1;
		}
		count++;
	}
	printf("%d",count);
	return;
}
//3.5¡¾PATB1022¡¿
void base_conv(void) {
	int arr[31];
	int a, b,sum,base;
	scanf("%d %d %d",&a,&b,&base);
	sum = a + b;
	int i = 0;
	do {
		arr[i] = sum % base;
		sum /= base;
		i++;
	} while (sum>0);
	for (int j = i - 1; j >= 0; j--) {
		printf("%x",arr[j]);
	}
	return;
}
//3.6 ¡¾codeup5901¡¿
void is_palstring(void) {
	char arr[32];
	scanf("%s",arr);
	for (int i = 0, j = strlen(arr) - 1; i < j;i++,j--) {
		if (arr[i]!=arr[j]) {
			printf("Not Palindrome String\n");
			return;
		}
	}
	printf("Is Palindrome String");
}
// ¡¾PATB1009¡¿
void str_rev(void) {
	char str[90];
	char ans[90][90] = {0};
	fgets(str, 90, stdin);
	int row = 0, col = 0;
	for (int i = 0; i < strlen(str)-1;i++) {
		if (str[i]!=' ') {
			ans[row][col] = str[i];
			col++;
		}
		else {
			ans[row][col] = '\0';
			row++;
			col = 0;
		}
	}
	for (int j = row; j >=0;j--) {
		printf("%s",ans[j]);
		if (j>0) {
			printf(" ");
		}
	}
	return;
}