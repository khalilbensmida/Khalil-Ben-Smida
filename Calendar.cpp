#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char year1[31][12][100];
char year2[31][12][100];
char year3[31][12][100];
char year4[31][12][100];
char year5[31][12][100];

void clrscr()
{
    system("@cls||clear");           // to clear the screen when needed
}

void calendar() /* displays a calendar of a specific month and a year*/
{
char *month_name[]={" ","January","February","March","April","May","June","July","August","September","October","November","December"};    // a pointer will be needed to point on an other array of month index with every month name
int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};            //number of days in every month (february is supposedly to be 28 if it's not a leap year)
	
int day,month,year,code,x,y,z,cmonth;

do{
 printf("Enter a valid month index:\n");
 scanf("%d",&cmonth);                                     // read the value of a month
} while ((cmonth<1) || (cmonth>12));

do{
 printf("Enter a valid year index: \n");
 scanf("%d", &year);                                  // read the value of year
} while (year<0);

 x=(year-1.)/4.0;
 y=(year-1.)/100.;
 z=(year-1.)/400.;
 code=(year+x-y+z)%7;     // a formula to check the first day of a given year ( knowing that the first day would be 0 as sunday and 6 as saturday )
 
 if(year%4==0&&year%100!=0||year%400==0) //check if it's a leap year
 
  days[2]=29;   // if it's a leap year it would change the last day of february to 29
 else
  days[2]=28;    // else it'd leave it 28
  
  
 month=cmonth;      //crushes the value of cmonth on month to use its index without changing its value
 
 for(month=1;month<=12;month++)    //starts counting from the first month to the last one
 {
  if(month==cmonth)               //checks if the months and the value of their index are the same as the counter works
  {
  	clrscr();
   printf("\n----------------------------------\n");
   printf("            %s %d\n",month_name[month],year);        // displays the names of the given month and year 
   printf("----------------------------------");
   printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );              // dispalys the days of the week as follows
   for(day=1; day<=1+code*5; day++)   //
   {
    printf(" ");
   }
   for(day=1;day<=days[month];day++)
   {
    printf("%2d",day);
    if((day+code)%7>0)            
     printf("   ");             //if the first week day reappears it would leave a space
    else
     printf("\n ");             //if the first week day doesn't reappear it would create a new line to continue arranging the index of every day of the month
   }
  }
  code=(code+days[month])%7;         // after incrementing code in every instruction it would devide by the number of week days to see the remainder and affect it to the following month
 }
}





void add(char year1[31][12][100],char year2[31][12][100],char year3[31][12][100],char year4[31][12][100],char year5[31][12][100])
{ 
int test=0,d,m,y,x;         // the test value initialized at 0 to test the existence of other events on a specific date
char s[100];
char p='*';                 //initialize the value of p at '*'
do{
 printf("Enter an event name\n");
 getchar();
 gets(s);
} while (strlen(s)>99);   // the length of the event name should not exceed 100
  do{
	printf("Enter a valid day index \n");
	scanf("%d",&d);
}while((d<1)||(d>31));
 
 do{
  printf("Enter a valid month index \n");                         // Enter a date to add an event
 scanf("%d",&m);
} while ((m<1) || (m>12));
 	
 do {
	printf("Enter a valid year [2019-2023] \n");
	scanf("%d",&y);
} while ((y<2019) || (y>2023));
 
  
if (y==2019){
	if (year1[d][m][0]==p){
 		strcpy(year1[d][m],s);
 		test=1;
 	}
}
else if(y==2020){
 	if (year2[d][m][0]==p){
		strcpy(year2[d][m],s);
		test=1;
	}
	
}
else if (y==2021){
	if (year3[d][m][0]==p){
 		strcpy(year3[d][m],s);                            //it will store the name of the event in a matrix named after the specific year
 		test=1;                                              // it will increment the test value to 1
 	}
}
else if (y==2022){
	if (year4[d][m][0]==p){
 		strcpy(year4[d][m],s);
 		test=1;
 	}
}
else if (y==2023){
	if (year5[d][m][0]==p){
 		strcpy(year5[d][m],s);
 		test=1;
	}
}
if (test==1)
	printf("The event ''%s'' successfuly added \n",s);                   // if test was incremented then the event was added and will print a message as follows
else 
	printf("This date already has an event\n");                           // if test could not be incremented and stucks at 0 it then there's an existing event on the same date 
 
}



void modify(char year1[31][12][100],char year2[31][12][100],char year3[31][12][100],char year4[31][12][100],char year5[31][12][100])


{ char s[100]; 
int y,m,d;

do {
printf("Enter a valid day index to modify \n");
scanf("%d",&d);
} while ((d<1) || (d>31));

do {
printf("Enter a valid month index to modify \n");                               // Enter a date to modify an existing event
scanf("%d",&m);
} while ((m<1) || (m>12));

do {
printf("Enter a valid year index to modify \n ");
scanf("%d",&y);
} while ((y<2019) || (y>2023));

printf("Enter a new event name \n");
getchar();
gets(s);

if (y==2019)
 	{ strcpy(year1[d][m],s);
	  }
 else if(y==2020)
 		{ strcpy(year2[d][m],s);
	 }
 else if (y==2021)
 		{ strcpy(year3[d][m],s);                                                  //it will store the new name of the event in a matrix named after the specific year
	 }
 else if (y==2022)
 	{ strcpy(year4[d][m],s);
	 }	
 else if (y==2023)
 		{ strcpy(year5[d][m],s);
	 }
printf("Your event was successfuly modified to ''%s''\n",s);

}

void Delete(char year1[31][12][100],char year2[31][12][100],char year3[31][12][100],char year4[31][12][100],char year5[31][12][100])
{ int x,y,m,d; 

char s[2];           
s[0]='\0';                 // create a new short string and reset its value to "" so we would crash it on an old value

printf("\nEnter a date of an event you want to delete \n");

  do{
	printf("\nEnter a valid day index to delete its event \n");
	scanf("%d",&d);
}while((d<1)||(d>31));
 
 do{
  printf("\nEnter a valid month index to delete its event \n");                          // Enter a date to delete an existing event
 scanf("%d",&m);
} while ((m<1) || (m>12));
 	
 do {
	printf("\nEnter a valid year [2019-2023] to delete its event \n");
	scanf("%d",&y);
} while ((y<2019) || (y>2023));
	


if (y==2019)
 	{ strcpy(year1[d][m],s);
	  }
 else if(y==2020)
 		{ strcpy(year2[d][m],s);
	 }
 else if (y==2021)
 		{ strcpy(year3[d][m],s);                              // It will reset the new value of the event name  as we crash it on the specific year matric to NULL ('\0')
	 }
 else if (y==2022)
 	{ strcpy(year4[d][m],s);
	 }	
 else if (y==2023)
 		{ strcpy(year5[d][m],s);
	 }
	
printf("Your event was deleted successfuly \n",s);	

}

void list(char year1[31][12][100],char year2[31][12][100],char year3[31][12][100],char year4[31][12][100],char year5[31][12][100])
{

int x,i,m,y;
x=0;     //set a counter x at 0 to count the exisiting events

do{	
printf("Enter a valid month index to list all its existing events\n");                                   //Enter a date to list its existing events
 scanf("%d",&m);
} while ((m<1) || (m>12));

do{
	printf("Enter a valid year index [2019-2023] \n");                      
	scanf("%d",&y);
} while ((y<2019) || (y>2023));
 
if (y==2019)
 	{ for(i=1;i<=31;i++)
 		{ if(strlen(year1[i][m])>1)
 			{
			 
	    	printf(" %d/%d/%d : \n",i,m,y);
	 		puts(year1[i][m]);
	 		x++;
	 		}
		 }
	}
 else
 {
  if(y==2020)
 		{ for(i=1;i<=31;i++)
 		{
		if  (strlen(year2[i][m])>1)
		{
		
 			printf(" %d/%d/%d :  \n",i,m,y);	
		  	puts(year2[i][m]);
		  		x++;
		  }
	 }
	 }
 else
 {
  if (y==2021)
 		{ 
		 for(i=1;i<=31;i++)
 			{
			if  (strlen(year3[i][m])>1)
			{
			
 			printf(" %d/%d/%d : \n",i,m,y);
		 	x++;
		  	puts(year3[i][m]);
	 		} }
	 	}
 else
 {
 if (y==2022)
 	{ for(i=1;i<=31;i++)
 		{
		if  (strlen(year4[i][m])>1)
		{
		
 			printf(" %d/%d/%d : \n",i,m,y);
		  		x++;
		  	puts(year4[i][m]);
		} }
	 }	
 else 
 {
 if (y==2023)
 		{ for(i=1;i<=31;i++)
 		{
		if  (strlen(year5[i][m])>1)
		{
 		printf(" %d/%d/%d :  \n",i,m,y);
 			x++;
		 puts(year5[i][m]);
		}
	 	} }
	 }
	 }
}
}
if (x==0)             //if the counter doesn't find any event in a specific date it will send a message as follows 
printf("There are no available events to show \n");
}


void menu()
{
printf(" This project is done by :\n \n");
printf("*******        Ahmed Khalil Ben Smida       *******\n\n");
printf ("\n");
printf("           ******* Event Calendar ******* \n\n");
printf("1.Create a calendar\n");                                                                               // Use the function menu to display a menu as it appears
printf("2.Add an event to your calendar	\n");
printf("3.Modify an event in your calendar \n");
printf("4.Delete an event from your calendar \n");	
printf("5.List of all events of a given month\n");	
}


main()
{
int x,y;
int year,month;
int i,j;
char s[2];
s[0]='*';



for (i=0;i<=31;i++)
	{ for (j=0;j<=12;j++)
		strcpy(year1[i][j],s);
	}
	
for (i=0;i<=31;i++)
	{ for (j=0;j<=12;j++)
		strcpy(year2[i][j],s);
	}for (i=0;i<=31;i++)
	{ for (j=0;j<=12;j++)
		strcpy(year3[i][j],s);                                   // s[0} was initialized at '*' and crushed on every year  
	}for (i=0;i<=31;i++)
	{ for (j=0;j<=12;j++)
		strcpy(year4[i][j],s);
	}
	for (i=0;i<=31;i++)
	{ for (j=0;j<=12;j++)
		strcpy(year5[i][j],s);
	}
	
		
menu(); // it calls the function menu to show it for the user

do{
 printf("\nPlease enter a number between 1 and 5 \n");
	scanf("%d",&x);	
} while ((x<1) || (x>5));                      //won't accept a choice less than 1 and greater than 5

switch(x){
   case 1:	clrscr();calendar();break;
	case 2: clrscr();add(year1,year2,year3,year4,year5);break;
	case 3: clrscr();modify(year1,year2,year3,year4,year5);break;
	case 4: clrscr();Delete(year1,year2,year3,year4,year5); break;       // clear the screen after every choice to get a better looking menu
	case 5: clrscr();list(year1,year2,year3,year4,year5); break;		
		}
printf("\n\n----------------------------------\n\n");
printf("Do you want to perform another action?\n");
do{
	printf ("\n1=Yes 2=No\n");
scanf("%d",&y);
} while ((y!=1) && (y!=2));         // won't accept other choice than 1 or 2


while(y==1)
{	
clrscr(); //clears the screen before the upcoming treatment

menu();   // recalls the function menu to show it to the user

do{
 printf("\nEnter a number between 1 and 5 \n");
	scanf("%d",&x);	
} while ((x<1) || (x>5));                      //won't accept a choice less than 1 and greater than 5

switch(x)
{
	case 1: clrscr();calendar();break;
	case 2: clrscr();add(year1,year2,year3,year4,year5);break;
	case 3: clrscr();modify(year1,year2,year3,year4,year5);break;             // clear the screen after every choice to get a better looking menu 
	case 4: clrscr();Delete(year1,year2,year3,year4,year5); break;
	case 5: clrscr();list(year1,year2,year3,year4,year5); break;			
}
printf("\n\n----------------------------------\n\n");
printf("\nDo you want to perform another action?\n");
do{
printf ("\n1=Yes 2=No\n");
scanf("%d",&y);
} while ((y!=1) && (y!=2));        // won't accept other choice than 1 or 2
}
if(y==2)
printf("\nExiting your program... \n\n          See you next time! ");
}
