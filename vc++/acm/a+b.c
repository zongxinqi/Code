#include<stdio.h>
#include<string.h>
#define M 10000
#define kk -48//0�ַ���ASCIIֵ��48
/*ȡlengA��lengB����Ǹ�*/
int maxl(int a,int b)
{
	return a>b?a:b;
}
/*���ַ�Ϊ����*/
int zz(char c)
{
	return c-'0';
}
int main() 
{ 
	char a[M],b[M];
	int A,B,Maxl,c,hh,sum[M],i,an,bn;
	memset(a,0,sizeof(a)); 
	memset(b,0,sizeof(b));
	while(~scanf("%s%s",&a,&b))
	{
		A=strlen(a);
		B=strlen(b);
		printf("A=%d B=%d\n",A,B);
/*��A��B�ַ�����˳����������?*/
		for(i=0;i<(A+1)/2;i++)
		{
			if(i==A-1-i) break;//?�ų�������λ��������Ӱ��??
			a[i]+=a[A-1-i];
			a[A-1-i]=a[i]-a[A-1-i];
			a[i]-=a[A-1-i];
		}
		for(i=0;i<(B+1)/2;i++)
		{
			if(i==B-1-i) break;//?�ų�������λ��������Ӱ��??
			b[i]+=b[B-1-i];
			b[B-1-i]=b[i]-b[B-1-i];
			b[i]-=b[B-1-i];
		} 
		/*������*/
		Maxl=maxl(A,B);
		for(i=0,c=0;i<=Maxl;i++)
		{
			an=zz(a[i]);
			bn=zz(b[i]);
			if(an==kk) an=0;// �ų���ʼ����0�ַ���Ӱ��;
			if(bn==kk) bn=0;// �ų���ʼ����0�ַ���Ӱ��;
			hh=an+bn+c;
			sum[i]=hh%10;
			c=hh/10;
		}
		/*���һλ������0�������*/
		if(sum[Maxl]>0) printf("%d",sum[Maxl]);
		/*�����ӡsum[]?*/
		for(i=Maxl-1;i>=0;i--)
		{
			printf("%d",sum[i]);
		}
		printf("\n");
	}
	return 0;
}
