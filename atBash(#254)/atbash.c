#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
	int len;
	int k;
	int i;
	char letter;
	char * string;
	
	for(k=1;k<argc;k++)
	{	
		string = argv[k];
		len = strlen(argv[k]);
		for(i=0;i<len;i++)
		{
			if(isupper(string[i]) != 0)
			{
				letter = string[i];
				letter = 'Z'-(letter - 'A');
				printf("%c",letter);
			}
			else
			{
				letter = string[i];
				letter = 'z'-(letter - 'a');
				printf("%c",letter);
			}	
		}
		printf(" ");
	}	
	printf("\n");
	return 0;
}