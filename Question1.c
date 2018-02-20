
#include<stdio.h>

// global variable defining the number of entries the file contains
#define NUM 100

// creating structure for date
struct date
{
	int day;
	int month;
	int year;

};

// creating structure for name
struct contact
{
	char first[15];
	char last[15];
};

// creating an array of structures for both date and contact
struct date dates[NUM];				// The array will have NUM number of elements
struct contact names[NUM];

void loadContacts(){};

int main()
{

	// calling function to load contacts
	loadContacts();

	// obtaining the names of the contact with age between 18 to 25 (both inclusive)
	// using for loop to go through each contact
	int i = 0;

	int currYear = 2018;
	int age;

	for(i = 0; i < NUM; i++)
	{
		// get the age by subtracting the current year with the year on the structure
		age = currYear - dates[i].year;

		// check to see if its in range
		if(age >= 18 && age <= 25)
		{
			// if so print in the format specified
			printf("%c. %s, %d\n", names[i].first[0], names[i].last, age);
		}
	}

	return 0;
}

void loadContacts()
{
	// initalizing counter variable to keep track of number of data read
	int count = 0;

	// temp char variable to store the -
	char temp;

	// start getting info from the file
	FILE *file = fopen("contacts.txt", "rt");			// opening the file for reading

	// error handling for files
	if (file == 0)
	{
		// file cannot be opened to generate error
		printf("Cannot open input file\n");
	}

	// as long as its not end of file keep reading
	while(fscanf(file, "%s %s %d %c %d %c %d\n", &names[count].first, &names[count].last, &dates[count].day, &temp, &dates[count].month, &temp, &dates[count].year) > 1)
	{
		// increment the counter
		count++;
	}

	printf("Contacts loaded successfully. \n\n");

}

