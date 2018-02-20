
#include<stdio.h>
#include<string.h>



int main(){
	// variable to store the word that the user enters
	char word[15];

	// variable to store the value that the user enters
	int value;

	// ask user to enter the word and value
	printf("Enter a word: ");
	scanf("%s", &word);

	printf("Enter a number: ");
	scanf("%d", &value);

	// check to see if value is more than 26, if so using modulus operator to wrap the value so that the alphabet is not exceeded
	if(value > 26)
	{
		value = value % 26;
	}

	// now go through each letter in the word and move each letter forward by the specified value
	int i = 0;

	char c;			// character to store each converted letter

	printf("Encrypted text: ");

	for(i = 0; i < strlen(word); i++)
	{
		// adding the value to the current character in the word
		c = word[i] + value;

		// check to see if it is upper case and if it has exceeded Z
		if(word[i] >= 65 && word[i] <= 90)
		{
			if(c > 90)
			{
				// we need to subtract 26 to rotate it around
				c = c - 26;
			}
		}

		// check to see if it is lower case and if it has exceeded z
		if(word[i] >= 97  && word[i] <= 122)
		{
			if (c > 122)
			{
				c = c - 26;
			}
		}

		// print the letter
		printf("%c", c);
	}


	return 0;
}



