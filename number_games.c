#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int choice, ch;
    int gamesPlayed = 0, toolsUsed = 0;

    /* Guessing game */
    int secret, guess, attempts, won;
    char again;

    /* Multiplication table and patterns */
    int tableNum, limit, rows, i, j;
    char showGrid;

    /* Number analyzer */
    long long num, temp, digit, digitSum, reversed, factorial, d;
    int isPrime;

    /* Calculator */
    double a, b, result;
    char op, cont;
    int validOp;

    srand((unsigned int)time(NULL));

    /* Main menu loop: repeats until Exit */
    do
    {
        printf("\n===== NUMBER GAMES SUITE =====\n");
        printf("1. Number Guessing Game\n");
        printf("2. Multiplication Table\n");
        printf("3. Pattern Printer\n");
        printf("4. Number Analyzer\n");
        printf("5. Simple Calculator\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        int status = scanf("%d", &choice);
        if (status == EOF)
        {
            choice = 6;
        }
        else if (status != 1)
        {
            choice = 0; /* non-numeric input */
        }
        while ((ch = getchar()) != '\n' && ch != EOF)
            ; /* clear leftover input */

        switch (choice)
        {
        case 1: /* ---------- Number Guessing Game ---------- */
        {
            do
            {
                secret = rand() % 100 + 1;
                attempts = 0;
                won = 0;
                printf("\nI picked a number from 1 to 100. You have 7 attempts.\n");

                while (attempts < 7)
                {
                    printf("Attempt %d of 7 - enter your guess: ", attempts + 1);
                    if (scanf("%d", &guess) != 1)
                    {
                        while ((ch = getchar()) != '\n' && ch != EOF)
                            ;
                        printf("Please enter a whole number.\n");
                        continue; /* does not use up an attempt */
                    }
                    if (guess < 1 || guess > 100)
                    {
                        printf("Guess must be between 1 and 100.\n");
                        continue; /* does not use up an attempt */
                    }

                    attempts++;
                    if (guess == secret)
                    {
                        won = 1;
                        break;
                    }
                    else if (guess > secret)
                    {
                        printf("Too high\n");
                    }
                    else
                    {
                        printf("Too low\n");
                    }
                }

                if (won)
                {
                    printf("You win! It took you %d attempt(s).\n", attempts);
                }
                else
                {
                    printf("You lose! The number was %d.\n", secret);
                }
                gamesPlayed++;

                printf("Play again? (y/n): ");
                scanf(" %c", &again);
            } while (again == 'y' || again == 'Y');
            break;
        }

        case 2: /* ---------- Multiplication Table ---------- */
        {
            printf("Enter a number: ");
            if (scanf("%d", &tableNum) != 1)
            {
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Invalid input.\n");
                break;
            }
            printf("Enter the limit (e.g. 12): ");
            if (scanf("%d", &limit) != 1 || limit < 1)
            {
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Invalid limit.\n");
                break;
            }

            printf("\nMultiplication table for %d:\n", tableNum);
            for (i = 1; i <= limit; i++)
            {
                printf("%d x %d = %d\n", tableNum, i, tableNum * i);
            }

            printf("\nPrint a full table grid from 1 to %d? (y/n): ", tableNum);
            scanf(" %c", &showGrid);
            if ((showGrid == 'y' || showGrid == 'Y') && tableNum >= 1)
            {
                /* Nested loops: rows and columns of the grid */
                for (i = 1; i <= tableNum; i++)
                {
                    for (j = 1; j <= tableNum; j++)
                    {
                        printf("%5d", i * j);
                    }
                    printf("\n");
                }
            }
            toolsUsed++;
            break;
        }

        case 3: /* ---------- Pattern Printer ---------- */
        {
            printf("Enter number of rows (1 to 10): ");
            if (scanf("%d", &rows) != 1 || rows < 1 || rows > 10)
            {
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Rows must be between 1 and 10.\n");
                break;
            }

            /* Right triangle of stars */
            printf("\nRight triangle:\n");
            for (i = 1; i <= rows; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }

            /* Inverted triangle */
            printf("\nInverted triangle:\n");
            for (i = rows; i >= 1; i--)
            {
                for (j = 1; j <= i; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }

            /* Number pyramid */
            printf("\nNumber pyramid:\n");
            for (i = 1; i <= rows; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    printf("%d ", j);
                }
                printf("\n");
            }
            toolsUsed++;
            break;
        }

        case 4: /* ---------- Number Analyzer ---------- */
        {
            printf("Enter a positive integer: ");
            if (scanf("%lld", &num) != 1 || num <= 0)
            {
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Please enter a positive integer.\n");
                break;
            }

            /* Digit sum and reverse: peel digits with % 10 and / 10 */
            temp = num;
            digitSum = 0;
            reversed = 0;
            while (temp > 0)
            {
                digit = temp % 10;
                digitSum += digit;
                reversed = reversed * 10 + digit;
                temp /= 10;
            }
            printf("Sum of digits: %lld\n", digitSum);
            printf("Reversed: %lld\n", reversed);

            if (reversed == num)
            {
                printf("%lld is a palindrome.\n", num);
            }
            else
            {
                printf("%lld is not a palindrome.\n", num);
            }

            /* Prime check: test divisors up to the square root */
            isPrime = (num >= 2);
            for (d = 2; d * d <= num; d++)
            {
                if (num % d == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime)
            {
                printf("%lld is prime.\n", num);
            }
            else
            {
                printf("%lld is not prime.\n", num);
            }

            /* Factorial only for 12 or less */
            if (num <= 12)
            {
                factorial = 1;
                for (d = 2; d <= num; d++)
                {
                    factorial *= d;
                }
                printf("Factorial: %lld\n", factorial);
            }
            else
            {
                printf("Warning: factorial is only shown for numbers 12 or less.\n");
            }
            toolsUsed++;
            break;
        }

        case 5: /* ---------- Simple Calculator ---------- */
        {
            do
            {
                printf("Enter first number: ");
                if (scanf("%lf", &a) != 1)
                {
                    while ((ch = getchar()) != '\n' && ch != EOF)
                        ;
                    printf("Invalid number.\n");
                    break;
                }
                printf("Enter operator (+ - * / %%): ");
                scanf(" %c", &op);
                printf("Enter second number: ");
                if (scanf("%lf", &b) != 1)
                {
                    while ((ch = getchar()) != '\n' && ch != EOF)
                        ;
                    printf("Invalid number.\n");
                    break;
                }

                validOp = 1;
                result = 0;
                switch (op)
                {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0)
                    {
                        printf("Error: cannot divide by zero.\n");
                        validOp = 0;
                    }
                    else
                    {
                        result = a / b;
                    }
                    break;
                case '%':
                    if ((long long)b == 0)
                    {
                        printf("Error: cannot take modulus by zero.\n");
                        validOp = 0;
                    }
                    else
                    {
                        result = (double)((long long)a % (long long)b);
                    }
                    break;
                default:
                    printf("Invalid operator.\n");
                    validOp = 0;
                    break;
                }

                if (validOp)
                {
                    printf("Result: %.2f\n", result);
                }

                printf("Continue? (y/n): ");
                scanf(" %c", &cont);
            } while (cont != 'n' && cont != 'N');
            toolsUsed++;
            break;
        }

        case 6: /* ---------- Exit ---------- */
            printf("\nThank you for playing!\n");
            printf("Guessing games played: %d\n", gamesPlayed);
            printf("Tools used: %d\n", toolsUsed);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 6);

    return 0;
}
