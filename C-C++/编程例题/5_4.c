#include<stdio.h>
#include<math.h>
int main()
{
	int x,n;
	float s;
	printf("please input x,n:",&x,&n);
	scanf("%d,%d",&x,&n);
    switch(n) /*��switch���������Ķ��֧����*/
    {
    	case 1:
    	printf("s=%f\n",x*pow(1.0225,1));
        break;
    	case 2:
    		printf("s=%f\n",x*pow(1.0243,2));
    	break;
    		case 3:
    			printf("s=%f\n",x*pow(1.0270,3));
    		break;
    			case 5:
    				printf("s=%f\n",x*pow(1.0288,5));
    				break;
    			case 8:
    				printf("s=%f\n",x*pow(1.0300,8));
					break;
				default:
					printf("invalid number!\n");
	}
    return 0;
}

