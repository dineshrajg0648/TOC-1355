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
    	if (input[i] !='a' && input[i] !='b')
    	{
    		printf("you entreded the input : ");
    		break;
		}
    }
    char str[100];
    int len=strlen(input);
    if (input[0]=='b' && input[length-1] =='a' && input[i] != '0' && input[i] != '1')
    {
    	printf("accepted");
	}
	else
	{
		printf("not accepted");
	}
    return 0;
}
