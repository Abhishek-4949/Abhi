/*
Develop a Program in C for the following:
---------------------------------------------------------------------------------------------------
a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent
7 days of a week. Each Element of the array is a structure having three fields. The first
field is the name of the Day (A dynamically allocated String), The second field is the
date of the Day (A integer), the third field is the description of the activity for a
particular day (A dynamically allocated String).
---------------------------------------------------------------------------------------------------
Develop a Program in C for the following:
b) Write functions create(), read() and display(); to create the calendar, to read the data
from the keyboard and to print weeks activity details report on screen.
---------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_DAYS_IN_WEEK 7
// Structure to represent a day
typedef struct
{
	char *acDayName;
	int iDate;
	char *acActivity;
	} DAYTYPE;
    void fnDispCal (DAYTYPE *);
	void fnReadCal (DAYTYPE *);
	void fnFreeCal (DAYTYPE *);
	DAYTYPE *fnCreateCal();
	
	int main()
	{// Create the calendar
	DAYTYPE *weeklyCalendar = fnCreateCal();
	// Read data from the keyboard
	fnReadCal (weeklyCalendar);
	//display the week activity details 
	fnDispCal(weeklyCalendar);
	// Free allocated memory 
	fnFreeCal (weeklyCalendar);
	return 0;
}
DAYTYPE *fnCreateCal ()
{
    DAYTYPE *calendar = (DAYTYPE *)malloc( NUM_DAYS_IN_WEEK *sizeof(DAYTYPE));
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++)
    {
        calendar[i].acDayName = NULL; 
        calendar[i].iDate = 0;
        calendar[i].acActivity = NULL;
    }
    return calendar;
}
void fnReadCal (DAYTYPE *calendar)
{
    char cChoice;
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++)
    {
        printf("Do you want to enter details for day %d [Y/N]: ", i + 1);
        scanf("%c", &cChoice);
        getchar();
        if (tolower(cChoice) == 'n')
            continue;
        
        char nameBuffer[50];
        printf("Day Name: ");
        scanf("%[^\n]", &nameBuffer);
        calendar[i].acDayName = strdup (nameBuffer); // Dynamically allocate and copy the string
        
        printf("Date: ");
        scanf("%d", &calendar[i].iDate);
        
        char activityBuffer[100];
        printf("Activity: ");
        scanf("%s", &activityBuffer); // Read the entire line including spaces
        calendar[i].acActivity = strdup (activityBuffer);
        
        printf("\n");
        getchar(); //remove trailing enter character in input buffer
    }
}
void fnDispCal (DAYTYPE *calendar)
{
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++)
    {
        printf("Day %d:\n", i + 1);
        if (calendar[i].iDate == 0)
        {
            printf("No Activity\n\n");
            continue;
        }
        printf(" Day Name: %s\n", calendar[i].acDayName);
        printf(" Date: %d\n", calendar [i].iDate);
        printf(" Activity: %s\n\n", calendar[i].acActivity);
    }
}
void fnFreeCal (DAYTYPE *calendar)
{
for(int i = 0; i < NUM_DAYS_IN_WEEK; i++)
    {
        free (calendar[i].acDayName);
        free (calendar[i].acActivity);

    }
free(calendar);
}