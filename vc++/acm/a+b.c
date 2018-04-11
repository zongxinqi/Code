#include<stdio.h>
#include<string.h>
#define M 10000
#define kk -48//0字符的ASCII值是48
/*取lengA和lengB大的那个*/
int maxl(int a,int b)
{
	return a>b?a:b;
}
/*化字符为数字*/
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
/*把A和B字符串的顺序逆序排列?*/
		for(i=0;i<(A+1)/2;i++)
		{
			if(i==A-1-i) break;//?排除共奇数位个大数的影响??
			a[i]+=a[A-1-i];
			a[A-1-i]=a[i]-a[A-1-i];
			a[i]-=a[A-1-i];
		}
		for(i=0;i<(B+1)/2;i++)
		{
			if(i==B-1-i) break;//?排除共奇数位个大数的影响??
			b[i]+=b[B-1-i];
			b[B-1-i]=b[i]-b[B-1-i];
			b[i]-=b[B-1-i];
		} 
		/*加运算*/
		Maxl=maxl(A,B);
		for(i=0,c=0;i<=Maxl;i++)
		{
			an=zz(a[i]);
			bn=zz(b[i]);
			if(an==kk) an=0;// 排除初始化中0字符的影响;
			if(bn==kk) bn=0;// 排除初始化中0字符的影响;
			hh=an+bn+c;
			sum[i]=hh%10;
			c=hh/10;
		}
		/*最后一位若大于0就先输出*/
		if(sum[Maxl]>0) printf("%d",sum[Maxl]);
		/*逆序打印sum[]?*/
		for(i=Maxl-1;i>=0;i--)
		{
			printf("%d",sum[i]);
		}
		printf("\n");
	}
	return 0;
}
