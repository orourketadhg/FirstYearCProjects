/*  Assignment 2 : Lotto game to check a set of numbers entered against a the winning numbers
 *
 *      option 1: Enter 6 numbers (1 - 42) none to be repeated.
 *      option 2: Display the entered numbers.
 *      option 3: Sort contents of array in increasing order
 *      option 4: Compare lotto numbers with winning numbers
 *      option 5: Display the frequency of the entered numbers
 *      option 6: exit the program
 *
 *      Extra : option 2 - 5 only available after option 1 completed
 *      Extra : Return to the menu after each option chosen
 *      Extra : Use ONLY pointer notation to access array elements
 *
 * Author: Tadhg O'Rourke
 * Date: 20/02/2018
 * IDE: CLion 2017.3.3
 */

#include <stdio.h>
#include <stdlib.h>

#define LOTTOSIZE 6
#define BONUS 42

//prototypes
int Game();
int * EnterNum(int[]);
void DisplayNum(int[]);
int * SortNum(int[]);
void TestNum(int[]);
int * UpdateFreq(int[], int[]);
void DisplayFreq(int[]);
int ExitProgram();

//Main - Loop through game until exit condition is met
int main() {

    int exit = 1;

    //main menu Loop
    do {

        //Implement Game(void) from which will display the menu and choose what the user can do
        exit = Game();

        //only end if the returned number from is greater than 0 (1 will be returned)
    } while (exit != 0 );
    //end main do while

    return 0;
}//end main

//Main menu
int Game() {

    //Arrays
    static int lotto[LOTTOSIZE] = {0};
    static int FrequencyTable[BONUS] = {0};

    //Variables and pointers
    int *LottoPtr;
    int *FreqPtr;
    static int Enable = 0;
    int Exit = 1;
    char input = 0;

    LottoPtr = lotto;
    FreqPtr = FrequencyTable;

    //print menu after each option chosen
    printf("\n|=======================================================|");
    printf("\n|                                                       |");
    printf("\n|                      Lotto Menu                       |");
    printf("\n|                                                       |");
    printf("\n| Enter 1-6 to choose an option                         |");
    printf("\n| Option 1: Enter Numbers                               |");
    printf("\n| Option 2: Display Numbers                             |");
    printf("\n| Option 3: Sort Numbers                                |");
    printf("\n| Option 4: Test Numbers                                |");
    printf("\n| Option 5: Display frequency of chosen numbers         |");
    printf("\n| Option 6: Exit program                                |");
    printf("\n|                                                       |");
    printf("\n|=======================================================|\n");
    printf("\n");

    //menu input
    scanf("%1s", &input);

    switch (input) {

        //Enter numbers
        case '1' : {

            //implement EnterNum(int[]) to enter the users 6 numbers and check if they meet requirements
            LottoPtr = EnterNum(lotto);

            //implement UpdateFreq(int[], int[]) which will update the frequency table containing how many times you have entered a number
            FreqPtr = UpdateFreq(lotto, FrequencyTable);

            Enable = 1;

            break;
        }//end Game switch case 1


            //Display Numbers
        case '2' : {
            if (Enable == 1) {

                //implement DisplayNum(int[]) to display the users entered numbers
                DisplayNum(lotto);

            }//end if option 2 enable
            else {
                printf("\nYou have to enter your lotto numbers first\n");

            }//end main case else option 2

            break;

        }//end Game switch case 2


            //sort
        case '3' : {
            if (Enable == 1) {
                //Implement SortNum(int[]) to sort the users entered numbers
                LottoPtr = SortNum(lotto);

            }//end if option 3 enable
            else {
                printf("\nYou have to enter your lotto numbers first\n");

            }//end main case else option 3

            break;

        }//end Game switch case 3


            //Test Numbers
        case '4' : {
            if (Enable == 1) {
                //Implement TestNum(int[]) to check if you are a winner
                TestNum(lotto);

            }//end if option 4 enable
            else {
                printf("\nYou have to enter your lotto numbers first\n");

            }//end main case else option 4

            break;

        }//end Game switch case 4


            //Display Frequency
        case '5' : {
            if (Enable == 1) {
                //Implement DisplayFreq(int[]) to display the Frequency Table
                DisplayFreq(FrequencyTable);

            }//end if option 5 enable
            else {
                printf("\nYou have to enter your lotto numbers first\n");

            }//end main case else option 5

            break;

        }//end Game switch case 5


            //Exit Program
        case '6' : {

            //Implement ExitProgram(void) to allow the user to Exit the Game
            Exit = ExitProgram();

            break;

        }//end Game switch case 6


        default: {


        }

    }//end Game switch

    return Exit;

}//end Game


//User enters numbers
int * EnterNum(int chosenNumbers[]) {

    int Temp;

    //reset numbers to 0
    for (int k = 0; k < LOTTOSIZE; ++k) {
        *(chosenNumbers + k) = 0;
    }//end EnterNum for Reset Numbers

    printf("\nEnter the Numbers you wish to play with: \n");

    //loop through array to enter and check
    for (int i = 0; i < LOTTOSIZE; i++) {
        scanf("%d", &(*(chosenNumbers + i)) );

        Temp = i;

        //checks if between 1 and 42
        if ( (*(chosenNumbers + i)) >= 1 && (*(chosenNumbers + i)) <= 42) {

            for (int j = 0; j < LOTTOSIZE; j++) {

                //check if number has been used before, Skips current element
                if ( ( (*(chosenNumbers + Temp)) == (*(chosenNumbers + j)) ) && (Temp != j) ) {

                    printf("\nYou entered that number before, please enter a different number\n");
                    //goes back so the invalid element can be overwritten
                    i--;

                }//end EnterNum if Used before

            }//end EnterNum for enter next number

        }//end EnterNum if between 1 and 42
        else {
            printf("\nYou must enter a number between 1 and 42\n");
            i--;

        }//end EnterNum if not between 1 and 42
        
    }//end EnterNum for read in new numbers;
    
    return chosenNumbers;
    
}//end EnterNum


//Display users chosen numbers
void DisplayNum(int LottoNumbers[]) {
    printf("\nYour chosen lotto numbers are: ");

    //Loop through LottoNumbers array to Display
    for (int i = 0; i < LOTTOSIZE; i++) {

        //displays the elements with the final element not having a ',' after
        if (i == 5) {
            printf("%d", *(LottoNumbers + i) );

        }//end DisplayNum if print last element
        else {
            printf("%d, ", *(LottoNumbers + i) );

        }//end DisplayNum else print elements

    }//end DisplayName for display LottoNumbers

}//end DisplayNum


//Sort numbers using Bubble Sort
int * SortNum(int LottoNumbers[]) {

    int Temp;

    for (int i = 0; i < LOTTOSIZE - 1; i++) {

        for (int j = 0; j < (LOTTOSIZE - i - 1); ++j) {

            if( (*(LottoNumbers + j)) > (*(LottoNumbers + j + 1)) ) {

                //Swaps elements
                Temp = *(LottoNumbers + j);
                *(LottoNumbers + j) = *(LottoNumbers + j + 1);
                *(LottoNumbers + j + 1) = Temp;

            }//end SortNum if next number less than swap

        }//end SortNum for inner

    }//end SortNum for outer

    //return sorted Array
    return LottoNumbers;

}//end SortNum


//Test chosen numbers against Winning Numbers
void TestNum(int TestArray[]){
    int WinningNums[LOTTOSIZE] = {1, 3, 5, 7, 9, 11};
    int MatchedNum = 0;
    int MatchedBonus = 0;

    //Loop through 1 - 42 against the chosen numbers
    for (int i = 0; i < LOTTOSIZE; i++) {

        for (int j = 0; j < LOTTOSIZE; j++) {

            //increment if a non bonus number is matched
            if ( (*(TestArray + j)) == (*(WinningNums + i)) ) {
                MatchedNum++;

            }//end TestNum if winning Num

            //increment if the bonus number is matched
            if ( (*(TestArray + j)) == 42) {
                MatchedBonus = 1;

            }//end TestNum if winning Num is 42

        }//end TestNum for check if TestArray[j] is part of Winning numbers

    }//end TestNum for run through winning numbers

    //matched 3 and bonus number
    if (MatchedNum == 3 && MatchedBonus == 1) {
        printf("\nYou won a cinema ticket!");

    }//end TestNum if matched 3 plus bonus
    else {

        //matched 4 numbers
        if (MatchedNum == 4 && MatchedBonus == 0) {
            printf("\nYou won a night out!");

        }//end TestNum if matched 4
        else {

            //matched 4 and bonus number
            if (MatchedNum == 4 && MatchedBonus == 1) {
                printf("\nYou won a weekend away!");

            }//end TestNum if matched 4 plus bonus
            else {

                //matched 5 numbers
                if (MatchedNum == 5 && MatchedBonus == 0) {
                    printf("\nYou won a holiday!");

                }//end TestNum if matched 5
                else {

                    //matched 5 and bonus number
                    if (MatchedNum == 5 && MatchedBonus == 1) {
                        printf("\nYou won a new car!");

                    }//end TestNum if matched 5 plus bonus
                    else {

                        //matched 6 numbers
                        if (MatchedNum == 6) {
                            printf("\nYou won the jackpot!");

                        }//end TestNum if matched 6
                        else {

                            //matched 3 or less and not the bonus
                            if (MatchedNum < 3) {
                                printf("\nNot enough of your numbers matched, Sorry.");

                            }//end TestNum if matched not enough

                        }//end TestNum else matched 6

                    }//end TestNum else matched 5 plus Bonus

                }//end TestNum else matched 5

            }//end TestNum else matched 4 plus Bonus

        }//end TestNum else matched 4

    }//end TestNum else matched 3 plus Bonus

}//end TestNum


//Calculate and display the frequency of all used numbers
int * UpdateFreq(int UsedNumbers[], int FreqTable[]) {

    //loop through 1 - 42 against each entered number and increment the element by one each time it has been entered
    for (int i = 0; i < LOTTOSIZE; i++) {

        for (int j = 0; j < BONUS; j++) {

            //if a number has been input, increase that element number by 1
            if ( (*(UsedNumbers + i)) == (j + 1) ) {

                //increment
                (*(FreqTable + j))++;

            }//end UpdateFreq if Number used

        }//end UpdateFreq for cycle each number in chosen number

    }//end UpdateFreq for cycle each possible entry

    //return Frequency table
    return FreqTable;

}//end UpdateFreq


//Display Frequency Table
void DisplayFreq(int FreqTable[]) {

    //loops through the Frequency and if a a number has been entered it will print that number with how many times it has been used
    for (int k = 0; k < BONUS; k++) {

        if ( (*(FreqTable + k)) != 0 ) {
            printf("\nYou Have used %d %d times", (k + 1), (*(FreqTable + k)) );

        }//end DisplayFreq if number used display

    }//end DisplayFreq for cycle each possible number to display

    printf("\n");

}//end DisplayFreq


//Exit Program
int ExitProgram() {
    char exit;

    printf("\nAre you sure you want to exit the lotto? (y/n)?\n");

    scanf("%1s", &exit);

    //if the user wishes to exit put 'y' or 'n' if they done, otherwise(invalid input) return to menu
    switch (exit) {

        //if yes exit
        case 'y' : {
            printf("Thanks for playing!\n");

            return 0;


        }//ExitProgram switch case y

        //if yes dont exit
        case 'n' : {
            return 1;


        }//ExitProgram switch case n

        //if invalid input return to menu
        default: {
            printf("\ninvalid input!");

            break;

        }//end ExitProgram default

    }//end ExitProgram switch

}//end ExitProgram
