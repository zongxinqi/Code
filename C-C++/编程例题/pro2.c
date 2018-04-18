// 17.处理二维数组的函数.c: 定义控制台应用程序的入口点。
//
#include<stdio.h>
#include<stdlib.h>
#define ROWS 3
#define COLS 4

void sum_rows(int ar[][COLS], int rows);
void sum_cols(int[][COLS], int);           //省略形参名，没问题
int sum2d(int(*ar)[COLS], int rows);       //另一张语法

int main(void)
{
	int junk[ROWS][COLS] = {
		{2,4,6,8},
		{3,5,7,9},
		{12,10,8,6}
	};
	int i;
    int *ar = junk[ROWS][COLS];
//	sum_rows(junk, ROWS);
for(i = 0;i < ROWS;i++)
{
	printf("row %d: sum = %d\n", i,sum2d((*ar)[COLS],i) );
}
	sum_cols(junk, ROWS);

	system("pause");
    return 0;
}

void sum_rows(int ar[][COLS], int rows) {
	int r;
	int c;
	int tot;

	for (r = 0; r < rows; r++) {
		tot = 0;
		for (c = 0; c < COLS; c++) {
			tot += ar[r][c];
		}
		printf("row %d: sum = %d\n", r, tot);
	}
}

void sum_cols(int ar[][COLS], int rows) {
	int r;
	int c;
	int tot;

	for (c = 0; c < COLS; c++) {
		tot = 0;
		for (r = 0; r < rows; r++) {
			tot += ar[r][c];
		}
		printf("col %d: sum = %d\n", c, tot);
	}
}

int sum2d(int(*ar)[COLS], int rows) {
	int r;
	int c;
	int tot=0;

	for (r = 0; r < rows; r++) {
		for (c = 0; c < COLS; c++) {
			tot += ar[r][c];
		}
	}

	return tot;
}
