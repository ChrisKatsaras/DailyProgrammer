//Game of threes written by Christopher Katsaras
#include <stdio.h>

int main()
{
	int number;

	printf("Please input your number\n");
	scanf("%d",&number);

	while(number != 1)
	{
		if(number % 3 == 0)
		{
			printf("%d 0\n",number);
			number /= 3;
		}
		else if(number % 3 == 1)
		{
			printf("%d -1\n",number);
			number -= 1;
			number /=3;
		}
		else
		{
			printf("%d 1\n",number);
			number += 1;
			number /= 3;
		}

	}
	printf("%d\n",number);


	return 0;
}