#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess, attempts, maxAttempts;
    int choice, playAgain = 1;

    srand(time(0));

    while(playAgain == 1) {

        printf("\n===== Number Guessing Game =====\n");
        printf("Select Difficulty Level:\n");
        printf("1. Easy (1-50, 10 attempts)\n");
        printf("2. Medium (1-100, 7 attempts)\n");
        printf("3. Hard (1-200, 5 attempts)\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        int range;

        if(choice == 1) {
            range = 50;
            maxAttempts = 10;
        }
        else if(choice == 2) {
            range = 100;
            maxAttempts = 7;
        }
        else {
            range = 200;
            maxAttempts = 5;
        }

        randomNumber = rand() % range + 1;

        printf("Guess the number between 1 and %d\n", range);

        for(attempts = 1; attempts <= maxAttempts; attempts++) {

            printf("Attempt %d: Enter guess: ", attempts);
            scanf("%d", &guess);

            if(guess > randomNumber) {
                printf("High number!\n");
            }
            else if(guess < randomNumber) {
                printf("Low number!\n");
            }
            else {
                printf("🎉 Correct! You guessed it in %d attempts.\n", attempts);
                break;
            }
        }

        if(guess != randomNumber) {
            printf("❌ Game Over! The number was %d\n", randomNumber);
        }

        printf("Play again? (1 = Yes / 0 = No): ");
        scanf("%d", &playAgain);
    }

    printf("Thanks for playing!\n");

    return 0;
}
