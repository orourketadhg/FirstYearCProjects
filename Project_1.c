/* Program of a maths game.
 *
 * Menu displays after every  menu option completed.
 *
 * Enter option 1 to choose rounds, maximum of 5 rounds.
 *
 * Enter option 2 To play game, option 1 has to be completed first.
 * option 2 plays as many rounds as selected in option 1.
 *
 * option 3 displays amount of correct and incorrect answer, option 2 has to be completed first.
 * Option 3 resets after option 2 chosen again.
 *
 * option 4 terminates application.
 *
 * Author: Tadhg O'Rourke
 * Last Edited: 09/11/2017
 * IDE: Clion 2017.2.3
 * */

#include <stdio.h>

//Symbolic Names
#define TRUE 1
#define FALSE 0
#define END 4

int main() {

    //declare Variables
    int Menu_Option;
    int Round_Number_Selected;
    int Answers_Correct;
    int Answers_Incorrect;
    int Played;
    int Rounds;
    int Enable_Play;
    int Answer;
    int Correct_Answer;

    //initialisation of variables
    Menu_Option = 0;
    Round_Number_Selected = FALSE;
    Answers_Correct = 0;
    Answers_Incorrect = 0;
    Played = 0;
    Rounds = 0;
    Enable_Play = FALSE;
    Answer = 0;


    //Check for option 4
    while ( Menu_Option != END ){

        //Menu

        printf("\n=============================Quiz=============================\n");
        printf("--------------------------------------------------------------\n");
        printf("|                                                            |\n");
        printf("|     1. Choose Number of Rounds                             |\n");
        printf("|     2. Play Quiz                                           |\n");
        printf("|     3. Score                                               |\n");
        printf("|     4. Exit                                                |\n");
        printf("|                                                            |\n");
        printf("--------------------------------------------------------------\n\n");

        //First input
        printf("Enter choice: \n");
        scanf("%d", &Menu_Option);

        //Menu Options

        //Check for emu input to be 1, 2, 3 or 4
        if (Menu_Option > 0 && Menu_Option < 5) {



            //If option 1, Choose round number
            if(Menu_Option == 1){


                while ( Enable_Play == FALSE ){

                    //enter number of rounds chosen to play
                    printf("\nHow many round you you want to play?\nThe maximum you can play is 5!\n");
                    scanf("%d", &Rounds);

                    //Error Check for Number of rounds
                    if(Rounds > 0 && Rounds < 6){
                        printf("\nYou have chosen to play %d rounds\n", Rounds);

                        Enable_Play = TRUE;

                    }//end if
                    else{
                        printf("\nInvalid input\n");
                    }//end else

                }//end while

                //end do

                //Round number selected
                Round_Number_Selected = TRUE;

            }//end if option 1


                // GAME


            //If option 2 and round number previously selected, play game
            if(Menu_Option == 2 && Round_Number_Selected == TRUE){

                //Reset number of correct and incorrect answers
                Answers_Correct = 0;
                Answers_Incorrect = 0;

                    //Questions

                // 1 rounds chosen
                if ( Rounds > 0 ) {

                    printf("\nQuestion 1: 1 + 2 = ?\n");
                    scanf("%d", &Answer);

                    Correct_Answer = 1 + 2;

                    if ( Correct_Answer == Answer ) {
                        printf("\nYou entered: %d - Correct!! Well Done", Answer);

                        //Add one to Correct_Answers
                        Answers_Correct++;

                    }//end if round 1
                    else{
                        printf("\nYou entered: %d - Wrong !!\nThe correct answer: %d\n", Answer, Correct_Answer);

                        //Add one to Incorrect_Answer
                        Answers_Incorrect++;

                    }//end else round 1

                    //Round 2

                    // 2 rounds chosen
                    if ( Rounds > 1 ) {

                        printf("\nQuestion 2: 2 + 3 = ?\n");
                        scanf("%d", &Answer);

                        Correct_Answer = 2 + 3;

                        if ( Answer == Correct_Answer ) {
                            printf("\nYou entered: %d - Correct!! Well Done\n", Answer);

                            //Add one to Correct_Answers
                            Answers_Correct++;

                        }//end if round 2
                        else{
                            printf("\nYou entered: %d - Wrong !!\nThe correct answer: %d\n", Answer, Correct_Answer);

                            //Add one to Incorrect_Answer
                            Answers_Incorrect++;

                        }//end else round 2

                            // Round 3

                        // 3 rounds chosen
                        if ( Rounds > 2 ) {

                            printf("\nQuestion 3: 3 + 4 = ?\n");
                            scanf("%d", &Answer);

                            Correct_Answer = 3 + 4;

                            if ( Answer == Correct_Answer ) {
                                printf("\nYou entered: %d - Correct!! Well Done\n", Answer);

                                //Add one to Correct_Answers
                                Answers_Correct++;

                            }//end if round 3
                            else{
                                printf("\nYou entered: %d - Wrong !!\nThe correct answer: %d\n", Answer, Correct_Answer);

                                //Add one to Incorrect_Answer
                                Answers_Incorrect++;

                            }//end else round 3

                                //Round 4

                            // 4 rounds chosen
                            if ( Rounds > 3 ) {

                                printf("\nQuestion 4: 4 + 5 = ?\n");
                                scanf("%d", &Answer);

                                Correct_Answer = 4 + 5;

                                if ( Answer == Correct_Answer ) {
                                    printf("\nYou entered: %d - Correct!! Well Done\n", Answer);

                                    //Add one to Correct_Answers
                                    Answers_Correct++;

                                }//end if round 4
                                else{
                                    printf("\nYou entered: %d - Wrong !!\nThe correct answer: %d\n", Answer, Correct_Answer);

                                    //Add one to Incorrect_Answer
                                    Answers_Incorrect++;

                                }//end else round 4

                                    //Round 5

                                // 5 rounds chosen
                                if ( Rounds > 4 ) {

                                    printf("\nQuestion 5: 5 + 6 = ?\n");
                                    scanf("%d", &Answer);

                                    Correct_Answer = 5 + 6;

                                    if ( Answer == Correct_Answer ) {
                                        printf("\nYou entered: %d - Correct!! Well Done\n", Answer);

                                        //Add one to Correct_Answers
                                        Answers_Correct++;

                                    }//end if round 5
                                    else{
                                        printf("\nYou entered: %d - Wrong !!\nThe correct answer: %d\n", Answer, Correct_Answer);

                                        //Add one to Incorrect_Answer
                                        Answers_Incorrect++;

                                    }//end else round 5

                                }//end if round chosen 5

                            }//end if round chosen 4

                        }//end if round chosen 3

                    }//end if round chosen 2

                }//end if round chosen 1

                //Game has been played
                Played = TRUE;

            }//end if option 2 Play


                //END GAME


            //if option 2 and rounds not selected
            if ( Menu_Option == 2 && Round_Number_Selected == FALSE ) {
                printf("\nYou must choose The number of rounds first\n");

            }//end if option 2 Rounds not chosen



            //If option 3 and game played, display correct and incorrect awnsers;
            if( Menu_Option == 3 && Played == TRUE ){
                printf("\nYou got %d answers correct\n", Answers_Correct);
                printf("You got %d answers incorrect\n", Answers_Incorrect);

            }//end if option 3 Game played



            if ( Menu_Option == 3 && Played == FALSE ) {
                printf("\nYou have to play first\n");

            }//end else option 3 Game not Played



            //if option 4, end game
            if( Menu_Option == END ){
                printf("\nEnding Game, Thank you for playing\n");

            }//end if option 4



        }// end if for menu select
        else {
            printf("\nInvalid Input\n");

        }//end else for menu select

    }//end while

    return 0;

}//end main
