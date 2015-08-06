#include <stdio.h>
#include <time.h> // standard time() function and data type time_t
/*
	Guess the magic number
	Author: Riyadh Al Nur
	Date Modified: 05/10/2010
*/
void welcome(); // prototype for welcome function

const int LOW = 0;
const int HIGH = 1000;

int main()
{
	int mnum = 45, gnum, tries = 0, score = 100; // declare integer variables
	//time_t seconds;
	FILE *hscore;

	//time(&seconds);
	//srand((unsigned int) seconds);

	//mnum = rand() % (HIGH - LOW + 1) + LOW;

	welcome(); // display welcome message

	do {
		printf("Enter your guess: ");
		scanf("%d", &gnum); // get the input number
		tries++; // increment the total number of times tried

		if(gnum == mnum) { // if guess is equal to the magic number
			printf("You've guessed the right number\n");
			printf("Number of tries: %d\n", tries); // show number of times tried
			if(score < 100) { // if score less than 100 than increment score by 1
				score++;
			}
			else { // if answer right on first guess than keep the score unchanged
				score = 100;
			}
			printf("Score: %d\n", score); // show final score
			printf("Game Over!");
			hscore = fopen("score.txt", "w");
			fprintf(hscore, "HIGH SCORES\n");
			fprintf(hscore, "Score: %d\n", score);

			fclose(hscore);

		}
		else { // if guess is not equal to the magic number
			printf("You've guessed the wrong number.\n");
			if(gnum > mnum) printf("Your guess is too high\n"); // check if guessed number is greater than magic number
			else printf("Your guess is too low\n"); // check if guessed number is less than magic number
			printf("Number of tries: %d\n", tries); // show number of times tried
			score--; // decrement score by 1 for the wrong answer
			printf("Score: %d\n", score); // show score
		}
	} while(gnum != mnum); // keep running program until user has the right guess

	return 0; // return a no error value
}

void welcome() { // begin welcome function
	printf("****************************");
	printf("*  Guess the magic number  *");
	printf("*  Hint: 0-1000            *");
	printf("****************************");
}
