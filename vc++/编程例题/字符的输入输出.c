#include<stdio.h>
 int main ()
 {
 	char ch;
 	printf("Press a key and then press Enter:");
 	ch=getchar(); /*�Ӽ�������һ���ַ������س����������룬���ַ����������ch*/
	ch=ch+32;  /*����д��ĸת��ΪСд��ĸ*/
	printf("%c,%d\n",ch,ch); /*�ֱ��������Ch�е��ַ�����ASCII��ֵ*/
    putchar('\n'); /*���һ���س����п��Ʒ�*/
    
  }  
