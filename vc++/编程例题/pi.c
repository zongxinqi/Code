#include<stdio.h>
#include<math.h>
int main()
{
	int sign=1;
	double pi=0,term=1,n=1;
	while(fabs(term)>=1e-8)
	{
		pi=pi+term;
		n=n+2;
		sign=-sign;
		term=sign/n;
	}
	pi=pi*4;
	printf("pi=%10.8f",pi);/*����pi�Ĺ����У����ս����ǰ��λ��������ȷ�ģ�
	�뱣����С��λ���޹أ�������С��λ����ʱ������ļ�λС�����ǲ�׼ȷ��ԭ���Ǿ��Ȳ�����
	����fabs(term)��Χ������С���õ�������Ҳ��Խ��Խ׼ȷ��*/ 
	return 0;
	
}
