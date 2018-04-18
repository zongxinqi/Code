#include<stdio.h>
int main()
{
	int data1,data2;
	char op;
	printf("please enter the expression:");
	scanf("%d%c%d",&data1,&op,&data2);
	switch (op) /*根据输入的运算符确定执行的运算*/ 
	{
		case'+':
			printf("%d+%d=%d\n",data1,data2,data1+data2);
			break; /*执行完某个分支后，一般要用break语句跳出switch结构                                      */ 
			case'-':
				printf("%d-%d=%d\n",data1,data1,data1-data2);
				break;
				case'*':
					printf("%d*%d=%d\n",data1,data2,data1*data2);
					break;
					case'/':
				    if (0==data2) /*为避免0作除数，检验是否为0*/ 
						printf("devision by zero!\n");
					else
						printf("%d/%d=%d\n",data1,data2,data1/data2);
						break;
						default: /*处理非法运算符，或在以上定义之外的*/ 
						printf("invalid operator !\n");
						return 0;
				
	}
}
