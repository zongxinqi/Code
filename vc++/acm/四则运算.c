#include<stdio.h>
int main()
{
	int data1,data2;
	char op;
	printf("please enter the expression:");
	scanf("%d%c%d",&data1,&op,&data2);
	switch (op) /*��������������ȷ��ִ�е�����*/ 
	{
		case'+':
			printf("%d+%d=%d\n",data1,data2,data1+data2);
			break; /*ִ����ĳ����֧��һ��Ҫ��break�������switch�ṹ                                      */ 
			case'-':
				printf("%d-%d=%d\n",data1,data1,data1-data2);
				break;
				case'*':
					printf("%d*%d=%d\n",data1,data2,data1*data2);
					break;
					case'/':
				    if (0==data2) /*Ϊ����0�������������Ƿ�Ϊ0*/ 
						printf("devision by zero!\n");
					else
						printf("%d/%d=%d\n",data1,data2,data1/data2);
						break;
						default: /*����Ƿ���������������϶���֮���*/ 
						printf("invalid operator !\n");
						return 0;
				
	}
}
