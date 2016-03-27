import java.util.ArrayList;
import java.util.Scanner;

public class scheduler {
	
	static ArrayList<show> shows = new ArrayList<show>();
	static ArrayList<show> canWatchShows = new ArrayList<show>();
	static int i;
	static int showNum;
	static int canWatchNum = 1;
	static int startScan;
	static int endScan;
	static String nameScan;
	public static void main (String[] args) 
	{
		System.out.println("Welcome to the VHS Schdeuler");
		System.out.println("Please input the number of shows available");

		Scanner scanner = new Scanner(System.in);
		showNum = scanner.nextInt();
		
		for(i=0;i<showNum;i++)
		{
			shows.add(new show(i));
			System.out.println("Please enter the start time of show: "+(i+1));
			startScan = scanner.nextInt();
			shows.get(i).startTime = startScan;
			
			System.out.println("Please enter the end time of show: "+(i+1));
			endScan = scanner.nextInt();
			shows.get(i).endTime = endScan;
			scanner.nextLine();
			System.out.println("Please enter the name of show: "+(i+1));
			nameScan = scanner.nextLine();
			shows.get(i).name = nameScan;
			
		}
		
		System.out.println("LIST OF SHOWS:");
		for(i=0;i<showNum;i++)
		{
			System.out.printf("%d %d %s\n",shows.get(i).startTime, shows.get(i).endTime , shows.get(i).name);
		}
		
		canWatchShows.add(new show(0));
		canWatchShows.get(0).startTime = shows.get(0).startTime;
		canWatchShows.get(0).endTime = shows.get(0).endTime;
		canWatchShows.get(0).name = shows.get(0).name;
		
		for(i=1;i<showNum;i++)
		{
			if(shows.get(i).startTime >= canWatchShows.get(canWatchNum-1).endTime)
			{
				canWatchShows.add(new show(i));
				canWatchShows.get(canWatchNum).startTime = shows.get(i).startTime;
				canWatchShows.get(canWatchNum).endTime = shows.get(i).endTime;
				canWatchShows.get(canWatchNum).name = shows.get(i).name;
				canWatchNum++;
			}
		}
		
		System.out.println("SHOWS YOU CAN WATCH:");
		for(i=0;i<canWatchNum;i++)
		{
			System.out.printf("%d %d %s\n",canWatchShows.get(i).startTime, canWatchShows.get(i).endTime , canWatchShows.get(i).name);
		}
		
	}

}
