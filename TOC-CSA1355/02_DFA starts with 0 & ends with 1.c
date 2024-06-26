#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main() {
    char input[100];
     printf("Enter a string: \n");
    scanf("%s", input);
    int length = strlen(input);
    int i;
    for (i=0;i<=length;i++){
    	if (input[i] !='0' && input[i] !='1')
    	{
    		printf("you entreded the wrong input \n");
    		break;
		}
    }
    char str[100];
    int len=strlen(input);
    if (input[0]=='0' && input[length-1] =='1' && input[i] != 'a' && input[i] != 'b')
    {
    	printf("accepted");
	}
	else
	{
		printf("not accepted");
	}
    return 0;
}
