#include <stdio.h>
#include <conio.h>
#define DAYS 366
#define SUMMER 94
#define WINTER 91


/*Calculates average for 2020*/
double average(double a[])
{
	double sum, avg;
	sum = 0;
	for(int i=0 ; i < DAYS; ++i)													/*When i is less than 366*/
	{
		sum += a[i];																/*Add cells in array together*/
	}
	avg = sum/DAYS;																	/*Sum of all array/366*/
	
	return(avg);
}

/*Calculates average for 2019*/
double average2019(double a[])
{
	double sum, avg;
	sum = 0;
	for(int i=0 ; i < 365; ++i)														/*When i is less than 365*/
	{
		sum += a[i];																/*Add cells in array together*/
	}
	avg = sum/365;																	/*Sum of all array/365*/
	
	return(avg);
}

/*Calculates the coldest temperature of the lake*/
double coldday(double lake[])
{
	double c;
	c = lake[0];			
	
	for (int i=0; i<DAYS; i++)														/*Will repeat 366 times*/
		{
		
		if (c >= lake[i])															/*If value is smaller than the current coldest*/					
			c = lake[i]; 															/*New coldest*/
		
		}

	return(c);
}

/*Calculates the warmest temperature of the lake*/
double warmday(double lake[])
{
	double w;
	w = lake[0];			
	
	for (int i=0; i<DAYS; i++)														/*Will repeat 366 times*/
		{
		
		if (w <= lake[i])															/*If value is greater than the current warmer*/					
			w = lake[i]; 															/*New warmer*/
		

		}

	return(w);
}

/*Calculates the dates which the coldest temperature of the lake occurred*/
void colddate(double lake[])														
{
	int endday[12] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	int month[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int d[DAYS];																	/*Will keep the dates at which coldest dates occur*/
	int n = 0;
	double c;
	c = lake[0];			
	
	for (int i=0; i<DAYS; i++)														/*Will repeat 366 times*/
		{
		
		if (c >= lake[i])															/*If value is smaller than the current coldest*/					
			c = lake[i]; 															/*New coldest*/
		
		}
	
	for (int i=0; i<DAYS; i++)
	{	
		
		if(c == lake[i])															/*If there is a day that has the equal temperature of the coldest day*/
			{
			d[n] = i+1;																/*Stores coldest days. Since i (days) starts at 0, a 1 must be added in order for days to be in a range of 1 to 366*/
			n += 1;							
			}
	}
	
	for(int i = 0; i < n; i++)														/*Goes through array of coldest days*/
	{

		for(int j = 11; j >= 0; j--)												/*Goes through array of months*/
		{
			
			if(d[i] < endday[0])													/*If the day at the coldest in is january*/
			{
				printf("%02d/%02d\n", d[i], month[0]);								/*Print date and month*/
				break;																/*Stops loop*/
			}
			if(d[i] > endday[j])													/*If the day is > endpoint of month*/ 
			{		
			printf("%02d/%02d\n", d[i]-endday[j], month[j+1]);						/*Substracts endpoint of previous month to the days and prints the date and current month*/
			break;																	/*Stops loop*/
			}
		}		
	}
}

/*Calculates the dates which the warmest temperature of the lake occurred*/
void warmdate(double lake[])														
{
	int endday[12] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	int month[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int d[DAYS];																	/*Will keep the dates at which warmer dates occur*/
	int n = 0;
	double w;
	w = lake[0];			
	
	for (int i=0; i<DAYS; i++)														/*Will repeat 366 times*/
		{
		
		if (w <= lake[i])															/*If value is greater than the current warmest*/					
			w = lake[i]; 															/*New warmest*/
		
		}
	
	for (int i=0; i<DAYS; i++)
	{	
		
		if(w == lake[i])															/*If there is a day that has the equal temperature of the warmest day*/
			{
			d[n] = i+1;																/*Stores warmest days. Since i (days) starts at 0, a 1 must be added in order for days to be in a range of 1 to 366*/
			n += 1;
			}
	}
	
	for(int i = 0; i < n; i++)														/*Goes through array of warmest days*/
	{

		for(int j = 11; j >= 0; j--)												/*Goes through array of months*/
		{
			
			if(d[i] < endday[0])													/*If the day at the warmest in is january*/
			{
				printf("%02d/%02d\n", d[i], month[0]);								/*Print date and month*/
				break;																/*Stops loop*/
			}
			if(d[i] > endday[j])													/*If the day is > endpoint of month*/ 
			{		
			printf("%02d/%02d\n", d[i]-endday[j], month[j+1]);						/*Substracts endpoint of previous month to the days and prints the date and current month*/
			break;																	/*Stops loop*/
			}
		}		
	}
}

/*Calculates average temperature in summer*/
double summeravg(double a[])
{
	double sum, avg;
	sum = 0;
	for(int i=172; i < 266; ++i)													/*172 to 265 (period of summer)*/
	{	
		sum += a[i-1];																/*At array 172, it will actually add temperature at day 173 from the table. Thus, substracted by 1*/
	}
	avg = sum/SUMMER;																/*Sum of all cells / 94*/ 
	
	return(avg);
}

/*Calculates average temperature in winter*/
double winteravg(double a[])
{
	double sum, avg;
	sum = 0;
	for(int i=1; i < 80; ++i)														/*1 to 79 (first winter period)*/
	{	
		sum += a[i-1];																/*At array 1, it will actually add temperature at day 2 from the table. Thus, substracted by 1*/
	}
	
	for (int i=355; i<367; i++)														/*355 to 366 (second winter period)*/
	{	
		sum += a[i-1];																/*At array 355, it will actually add temperature at day 356 from the table. Thus, substracted by 1*/
	}
	avg = sum/WINTER;																/*Sum of all cells / 91*/ 
	
	return(avg);
}

/*Organizes temperatures from warmest to coldest*/
void warmtocold(double a[])
{
   int i, j;		
   double temp;																		/*Temporary variable*/													
   
   for (i = 0; i < 6; ++i)															/*from 0 to 5*/
   {
      for (j = i + 1; j < 6; ++j)													/*from 1 to 5*/
      {
         if (a[i] < a[j])															/*If the "previous cell" is less than the "next cell"*/
         {
            temp = a[i];															/*Put "previous cell" in temporary variable*/
            a[i] = a[j];															/*Place value of "next cell" into the "previous cell"*/
            a[j] = temp;															/*Put value of temporary variable ("previous cell's" value) in "next cell"*/
         }
      }
   }
}

/*Finds amount of days at which you can swim comformably (above 20 degrees)*/

int swim(double lake[])
{
	int d = 0;
	
	for (int i=0; i < DAYS; i++)
	{
		if(lake[i] > 20)															/*If the temperature is greater than 20*/			
			d += 1;																	/*Add days*/
	}
	return(d);	
	
}

/*Find amount of days at which water freezes (below 0 degrees)*/
int frozen(double lake[])
{
	int d = 0;
	
	for (int i=0; i < DAYS; i++)
	{
		if(lake[i] < 0)																/*If the temperature is less than 0*/	
			d += 1;																	/*Add days*/
	}
	return(d);	
	
}

/*Prints out the table required for Question 9*/
void table (double avg2019[], double avg2020[], double avgt2019, double avgt)
{
	char name[6][100] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St. Clair"};
	printf("_____________________________________________\n");
	printf(" Lakes        |    2019    |      2020\n");
	printf("_____________________________________________\n");
	for(int i = 0; i < 6; i++)
	{
		
		printf("%-14s| %10.2lf | %9.2lf\n",name[i], avg2019[i], avg2020[i]);		
	}
	printf("______________________________________________\n");
	printf("Total Average | %10.2lf | %9.2lf             \n", avgt2019, avgt);
}



	/*Note - Thourghout the codes, you will see the following pattern:
	
	Sup is in cell 0
	Mich is in cell 1
	Huron is in cell 2
	Erie is in cell 3
	Ont is in cell 4
	StClr is in cell 5

	This will be the order in which lakes are placed in the arrays when needed.*/

int
main(void)
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////       QUESTION 1      ////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	printf("Question 1\n\n");
	
	/*Important variables*/
	int year, day;
	double sup[DAYS], mich[DAYS], huron[DAYS], erie[DAYS], ont[DAYS], stclr[DAYS];		/*Array with temperatures of each lake*/
	double all[DAYS];																	/*Adds all temperatures*/
	double avg[6], avgt;																/*Average array*/
	
	/*Extra/Helpful variables*/	
	
	double sum = 0;
	int i = 0;
	
	FILE*in;
	in = fopen("2020.dat", "r");														/*Name of the file. "r" means that it will only read the file*/
	
	
	while(fscanf(in, "%d %d %lf %lf %lf %lf %lf %lf", &year, &day, &sup[i], &mich[i], &huron[i], &erie[i], &ont[i], &stclr[i]) != EOF)      /*While the file doesn't reach the end of file*/
		i++;

	/*Average temperature for each lake*/
	avg[0] = average(sup);																/*Average Temperature of Superior will be stored in cell 0*/
	avg[1] = average(mich);																/*Average Temperature of Michigan will be stored in cell 1*/			
	avg[2] = average(huron);															/*Average Temperature of Huron will be stored in cell 2*/
	avg[3] = average(erie);																/*Average Temperature of Erie will be stored in cell 3*/
	avg[4] = average(ont);																/*Average Temperature of Ontario will be stored in cell 4*/
	avg[5] = average(stclr);															/*Average Temperature of St. Clair will be stored in cell 5*/
	
	/*For total average*/
	for(i = 0; i < DAYS; i++)
	{
		all[i] += sup[i] + mich[i] + huron[i] + erie[i] + ont[i] + stclr[i]; 			/*Adds EVERY temperature together*/
	}
	
	for(int i=0 ; i < DAYS; ++i)														/*While i is less than 366*/											
	{
		sum += all[i];																	/*Add cells in aray together*/
	}															
	
	avgt = sum/(DAYS*6);																/*Total average*/
		
	/*Printing averages*/
	printf("Average temperature in Lake Superior:  %10.2lf C\n", avg[0]);
	printf("Average temperature in Lake Michigan:  %10.2lf C\n", avg[1]);
	printf("Average temperature in Lake Huron:     %10.2lf C\n", avg[2]);
	printf("Average temperature in Lake Erie:      %10.2lf C\n", avg[3]);
	printf("Average temperature in Lake Ontario:   %10.2lf C\n", avg[4]);
	printf("Average temperature in Lake St. Clair: %10.2lf C\n", avg[5]);

	/*Printing total average*/
	printf("Average temperature of all lakes combined: %6.2lf C\n", avgt);
	
	printf("-------------------------------------------------------------------------------------------------");
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////       QUESTION 2      ////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	printf("\nQuestion 2\n\n");
	/*Important Variables*/
	double coldavg, warmavg;															/*Cold & warm average*/
	char name[6][100] = {"Superior", "Michigan", "Huron", "Erie", "Ont", "St. Clair"};	/*Following the order previously mentioned*/
	coldavg = avg[0];
	warmavg = avg[0];
	
	/*Finding coldest lake based on average*/ 
	for(int i=0; i < 6; i++)															/*The maximum average array we want is from 0-5, thus i must be less than 6
																						  in order for this to be achieved*/
	{
		if (coldavg >= avg[i])															/*If the coldest average is greater than the average value*/
			coldavg = avg[i];															/*The average becomes the coldest average*/	
	}
	
	for (i=0; i < 6; i++)
	{
		if (coldavg == avg[i])															/*If the coldest average == average value*/	 
			printf("Lake %s has the coldest average temperature. \n", name[i]);			/*Print the name of the lake that has the value*/
	}

	/*Finding hottest lake based on average*/
	for(int i=0; i < 6; i++)															/*The array has 6 cells in total, thus, there is no avg[6]*/ 
	{
		if (warmavg <= avg[i])															/*If the warmest average is lesst than the average value*/							
			warmavg = avg[i];															/*The average becomes the warmest average*/
	}
	
	for (i=0; i < 6; i++)
	{
		if (warmavg == avg[i])															/*If the warmest average == average value*/
			printf("Lake %s has the hottest average temperature. \n\n", name[i]);		/*Print the name of the lake that has the value*/
	}
	
	/*Finding lakes whose average temperature is above total average*/
	printf("The following lakes have an average temperature above the overall average:\n");
	for (i=0; i < 6; i++)
	{
		if (avg[i] > avgt)																/*If the value of the lake is greater than the total average*/
			printf("%s\n", name[i]);													/*Print the name of the lake*/
	}
	printf("\n");
	
	/*Finding lakes whose temperature is below overall average*/
	printf("The following lakes have an average temperature below the overall average:\n");
	for (i=0; i < 6; i++)
	{
		if(avg[i] < avgt)																/*If the value of the lake is less than the toal average*/
			printf("%s\n", name[i]);													/*Print the name of the lake*/
	}
	
	printf("-------------------------------------------------------------------------------------------------");
	
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////       QUESTION 3      ////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	printf("\nQuestion 3\n\n");
	
	/*Important Variables*/
	double cold[6];
	double warm[6];
	
	/*Assign values to the variables*/
	cold[0] = coldday(sup);
	cold[1] = coldday(mich);
	cold[2] = coldday(huron);
	cold[3] = coldday(erie);
	cold[4] = coldday(ont);
	cold[5] = coldday(stclr);
	
	warm[0] = warmday(sup);
	warm[1] = warmday(mich);
	warm[2] = warmday(huron);
	warm[3] = warmday(erie);
	warm[4] = warmday(ont);
	warm[5] = warmday(stclr);
	
	/*Printing coldest dates for each lake*/
	printf("Days with the coldest temperature in Lake Superior (%.2lf C):\n", cold[0]);	
	colddate(sup);	
	printf("\n");
	printf("Days with the coldest temperature in Lake Michigan (%.2lf C):\n", cold[1]);
	colddate(mich);
	printf("\n");
	printf("Days with the coldest temperature in Lake Huron (%.2lf C):\n", cold[2]);
	colddate(huron);
	printf("\n");
	printf("Days with the coldest temperature in Lake Erie (%.2lf C):\n", cold[3]);
	colddate(erie);
	printf("\n");
	printf("Days with the coldest temperature in Lake Ontario(%.2lf C):\n", cold[4]);
	colddate(ont);
	printf("\n");
	printf("Days with the coldest temperature in Lake St.CLair (%.2lf C):\n", cold[5]);
	colddate(stclr);
	printf("\n");
	
	/*Printing warmest dates for each lake*/	
	printf("Days with the warmest temperature in Lake Superior (%.2lf C):\n", warm[0]);
	warmdate(sup);
	printf("\n");
	printf("Days with the warmest temperature in Lake Michigan (%.2lf C):\n", warm[1]);
	warmdate(mich);
	printf("\n");
	printf("Days with the warmest temperature in Lake Huron (%.2lf C):\n", warm[2]);
	warmdate(huron);
	printf("\n");
	printf("Days with the warmest temperature in Lake Erie (%.2lf C):\n", warm[3]);	
	warmdate(erie);
	printf("\n");
	printf("Days with the warmest temperature in Lake Ontario (%.2lf C):\n", warm[4]);	
	warmdate(ont);
	printf("\n");
	printf("Days with the warmest temperature in Lake St.CLair (%.2lf C):\n", warm[5]);	
	warmdate(stclr);
	
	printf("-------------------------------------------------------------------------------------------------");
		
			
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////       QUESTION 4      ////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	printf("\nQuestion 4\n\n");
	
	/*Important variables*/
	double w = warm[0];																	/*w will be overall warmest*/
	double c = cold[0];																	/*c will be overall coldest*/
	
	
	/*For Warmest lake*/ 
	for (int i=0; i < 6; ++i)															/*Reminder: from 0 to 5, since it has only six cell, beginning from zero*/
	{
		if(w <= warm[i])																/*If current warm is less than warmest temperature from lake*/
			w = warm[i];																/*Warmest temperature becomes current warm*/
	}
	
	/*For coldest lake*/
	for (int i=0; i < 6; ++i)
	{
		if(c >= cold[i])																/*If current cold is greater than coldest temperature from lake*/
			c = cold[i];																/*Coldest temperature becomes current cold*/
	}
	
	for(int i=0; i < 6; ++i)
	{
		/*Name of the lake with warmest temperature*/
		if(w == warm[i])																/*If overall warmest == temperature from lake*/
		{
			printf("%s had the overall warmest temperature (%.2lf C), which occurred in the following days:\n", name[i], w); /*Prints out the name of the lake with that temperature*/

			/*Finding warmest dates for previously mentioned lake*/
			if (i == 0)
				warmdate(sup);
			
			if (i == 1)
				warmdate(mich);
			
			if (i == 2)
				warmdate(huron);

			if (i == 3)
				warmdate(erie);
			
			if (i == 4)
				warmdate(ont);
				
			if (i == 5)
				warmdate(stclr);
			printf("\n");
		}
		
		/*Name of the lake with coldest temperature*/
		if(c == cold[i])																/*If overall coldest == temperature from lake*/
		{
			printf("%s had the overall coldest temperature (%.2lf C), which occurred in the following days:\n", name[i], c); /*Prints out the name of the lake with that temperature*/
			
			/*Finding coldest dates for previously mentioned lake*/
			if (i == 0)
				colddate(sup);
			
			if (i == 1)
				colddate(mich);
			
			if (i == 2)
				colddate(huron);

			if (i == 3)
				colddate(erie);
			
			if (i == 4)
				colddate(ont);
				
			if (i == 5)
				colddate(stclr);
		}
	}
	
	printf("-------------------------------------------------------------------------------------------------");
	
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////       QUESTION 5      ////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	printf("\nQuestion 5\n\n");
	
	/*Important Variables*/
	double summer[6], summerorg[6];																/*summerorg means: summer organized*/
	
	/*Summer Average*/
	summer[0] = summeravg(sup);
	summer[1] = summeravg(mich);
	summer[2] = summeravg(huron);
	summer[3] = summeravg(erie);
	summer[4] = summeravg(ont);
	summer[5] = summeravg(stclr);
	
	for(i = 0; i < 6; i++)
		summerorg[i] = summer[i];																/*Temperatures from summer array are also given to summer organized*/

	/*Sorting temperatures from warmest to coldest*/
	warmtocold(summerorg);
	
	printf("In the summer period, the lakes have the following average temperature (from warmest to coldest)\n");
	
	for(i = 0; i < 6; i++)																		/*For summerorg array*/
		{
			for(int j = 0; j < 6; j++)															/*For summer array*/
			{
				if (summerorg[i] == summer[j])													/*For every cell in summerorg array, it will check with the summer array*/ 
					{
						if (j == 0)																/*If both coincide at 0*/
							printf("Lake Superior: %.2lf C\n", summerorg[i]);						/*According to the order mentioned at the beginning, Superior is always at cell 0. 
																								  Same pattern with the others*/
						if (j == 1)																/*If both coincide at 1*/
							printf("Lake Michigan: %.2lf C\n", summerorg[i]);						
				
						if (j == 2)																/*If both coincide at 2*/
							printf("Lake Huron: %.2lf C\n", summerorg[i]);
										
						if (j == 3)																/*If both coincide at 3*/
							printf("Lake Erie: %.2lf C\n", summerorg[i]);
									
						if (j == 4)																/*If both coincide at 4*/
							printf("Lake Ontario: %.2lf C\n", summerorg[i]);
							
						if (j == 5)																/*If both coincide at 5*/
							printf("Lake St. Clair: %.2lf C\n", summerorg[i]);															
			
					}
			
			}
		}
		
	printf("-------------------------------------------------------------------------------------------------");
	
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////       QUESTION 6      ////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	
	printf("\nQuestion 6\n\n");
		
	/*Important Variables*/
	double winter[6], winterorg[6];																/*winterorg means: winter organized*/
	
	/*Winter Average*/
	winter[0] = winteravg(sup);
	winter[1] = winteravg(mich);
	winter[2] = winteravg(huron);
	winter[3] = winteravg(erie);
	winter[4] = winteravg(ont);
	winter[5] = winteravg(stclr);
	
	for(i = 0; i < 6; i++)
		winterorg[i] = winter[i];																/*Temperatures from winter array are also given to winter organized*/

	/*Sorting temperatures from warmest to coldest*/
	warmtocold(winterorg);
	
	printf("In the winter period, the lakes have the following average temperature (from warmest to coldest)\n");
		
	for(i = 0; i < 6; i++)																		/*For winterorg array*/
		{
			for(int j = 0; j < 6; j++)															/*For winter array*/
			{
				if (winterorg[i] == winter[j])													/*For every cell in winterorg array, it will check with the winter array*/ 
					{
						if (j == 0)																/*If both coincide at 0*/
							printf("Lake Superior: %.2lf C\n", winterorg[i]);	
							
						if (j == 1)																/*If both coincide at 1*/
							printf("Lake Michigan: %.2lf C\n", winterorg[i]);						
				
						if (j == 2)																/*If both coincide at 2*/
							printf("Lake Huron: %.2lf C\n", winterorg[i]);
										
						if (j == 3)																/*If both coincide at 3*/
							printf("Lake Erie: %.2lf C\n", winterorg[i]);
									
						if (j == 4)																/*If both coincide at 4*/
							printf("Lake Ontario: %.2lf C\n", winterorg[i]);
							
						if (j == 5)																/*If both coincide at 5*/
							printf("Lake St. Clair: %.2lf C\n", winterorg[i]);															
			
					}
			
			}
		}

	printf("-------------------------------------------------------------------------------------------------");
	
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////       QUESTION 7      ////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	
	
	printf("\nQuestion 7\n\n");
	/*Imporant variables*/
	int comfort[6];
	
	/*Places in a cell the number of days in which each lake has a comfortable temperature*/ 
	comfort[0] = swim(sup);
	comfort[1] = swim(mich);
	comfort[2] = swim(huron);
	comfort[3] = swim(erie);
	comfort[4] = swim(ont);
	comfort[5] = swim(stclr);
	
	printf("Amounf of days with temperature above 20 C in Lake Superior:     %d\n", comfort[0]);
	printf("Amounf of days with temperature above 20 C in in Lake Michigan:  %d\n", comfort[1]);
	printf("Amounf of days with temperature above 20 C in in Lake Huron:     %d\n", comfort[2]);
	printf("Amounf of days with temperature above 20 C in in Lake Erie:      %d\n", comfort[3]);
	printf("Amounf of days with temperature above 20 C in in Lake Ontario:   %d\n", comfort[4]);
	printf("Amounf of days with temperature above 20 C in in Lake St. Clair: %d\n", comfort[5]);

	printf("-------------------------------------------------------------------------------------------------");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////       QUESTION 8      ////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	printf("\nQuestion 8\n\n");

	/*Main variables*/
	int freeze[6];

	/*Places in a cell the number of days in which each lake has a freezing temperature*/ 
	freeze[0] = frozen(sup);
	freeze[1] = frozen(mich);
	freeze[2] = frozen(huron);
	freeze[3] = frozen(erie);
	freeze[4] = frozen(ont);
	freeze[5] = frozen(stclr);
	
	printf("Amounf of days with temperature below 0 degrees in Lake Superior:     %d\n", freeze[0]);
	printf("Amounf of days with temperature below 0 degrees in Lake Michigan:     %d\n", freeze[1]);
	printf("Amounf of days with temperature below 0 degrees in Lake Huron:        %d\n", freeze[2]);
	printf("Amounf of days with temperature below 0 degrees in Lake Erie:         %d\n", freeze[3]);
	printf("Amounf of days with temperature below 0 degrees in Lake Ontario:      %d\n", freeze[4]);
	printf("Amounf of days with temperature below 0 degrees in in Lake St. Clair: %d\n", freeze[5]);

	printf("-------------------------------------------------------------------------------------------------");
	
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////       QUESTION 9      ////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	
	printf("\nQuestion 9\n\n");
	
	/*Important variables*/
	int year2019, day2019;
	double sup2019[DAYS], mich2019[DAYS], huron2019[DAYS], erie2019[DAYS], ont2019[DAYS], stclr2019[DAYS];		/*Array with temperatures of each lake from 2019*/
	double avg2019[6], avgt2019;																				/*Average array*/
	double all2019[DAYS];																		/*All the temperatures from 2019 added together*/
		
	/*Extra/Helpful variables*/																		
	sum = 0;																				
	i = 0;
	
	FILE*in2019;	
	in2019 = fopen("2019.dat", "r");															/*Name of the file. "r" means that it will only read the file*/
	
	
	while(fscanf(in2019, "%d %d %lf %lf %lf %lf %lf %lf", &year2019, &day2019, &sup2019[i], &mich2019[i], &huron2019[i], &erie2019[i], &ont2019[i], &stclr2019[i]) != EOF)      /*While the file doesn't reach the end of file*/
		i++;


	/*Average temperature for each lake (same process as in question 1)*/
	avg2019[0] = average2019(sup2019);
	avg2019[1] = average2019(mich2019);			
	avg2019[2] = average2019(huron2019);
	avg2019[3] = average2019(erie2019);
	avg2019[4] = average2019(ont2019);
	avg2019[5] = average2019(stclr2019);
	
	/*For total average*/
	for(i = 0; i < DAYS; i++)
	{
		all2019[i] += sup2019[i] + mich2019[i] + huron2019[i] + erie2019[i] + ont2019[i] + stclr2019[i]; 				/*Adds EVERY temperature together*/
	}
	
	for(int i=0; i < 365; ++i)																	/*When i is less than 365. Note: 2019 only had 365 days, not 366.*/											
	{
		sum += all2019[i];																		/*Adds cells in aray together*/
	}
	avgt2019 = sum/(365*6);																		/*Addition of all the temperatures/(365*6). Multiplied by 6 since there are six lakes*/


	printf("The following table shows the average temperature for each of the lakes in two different years:\n\n");
	table(avg2019, avg, avgt2019, avgt);

	printf("-------------------------------------------------------------------------------------------------");
	
	return(0);
}
