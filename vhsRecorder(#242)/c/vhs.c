//VHS scheduling program written by Christopher Katsaras
#include <stdio.h>

int main()
{
	int i;
	int numberOfShows;
	int numberOfWatch = 1;
	int showTimes[100][2]; //Hard coded in a max size of 100 shows
	int canWatchTimes[100][2];

	printf("Welcome to the VHS recording scheduler\n");
	printf("Please input the number of television shows on the schedule (i.e 5)\n");

	scanf("%d",&numberOfShows); //Scans in # of shows available to record

	printf("Now enter your shows one at a time in the following format 1230 1320 and hit Enter\n");
	printf("*PLEASE ENSURE TIME IS ENTERED IN MILITARY TIME!\n");

	for(i=0;i<numberOfShows;i++)
	{
		printf("INPUT SHOW %d:\n",i+1);
		scanf("%d %d",&showTimes[i][0],&showTimes[i][1]);
	}

	canWatchTimes[0][0] = showTimes[0][0]; //Sets the first show as able to watch because by default it cannot conflict
	canWatchTimes[0][1] = showTimes[0][1];
	for(i=1;i<numberOfShows;i++)
	{
		if(showTimes[i][0] >= canWatchTimes[numberOfWatch-1][1])
		{
			canWatchTimes[numberOfWatch][0] = showTimes[i][0];
			canWatchTimes[numberOfWatch][1] = showTimes[i][1];
			numberOfWatch++;
		}
	}

	printf("# of shows you can watch = %d!\n",numberOfWatch);
	for(i=0;i<numberOfWatch;i++)
	{
		printf("%d %d\n",canWatchTimes[i][0],canWatchTimes[i][1]); //Prints list of shows you are able to watch
	}

	return 0;
}