//#pragma once

#include <iostream>
#include <ctime>
#include <string.h>
#include <map>

using namespace std;

//FUNCTION DECLARATION
void PlayGame();
void GetBullsAndCows( string Guess , string Word , int *BullPointer , int *CowPointer );
string GetValidGuess( int WordLength );
bool AskToPlayAgain();
bool CheckIfValid( string Guess, int WordLength );
bool IsLowerCase( string Guess );
bool IsIsogram( string Guess );

class BullAndCowGame //copy and paste when compiling to remove warning: -std=c++11
{
private:
    //LIST of all WORDS
    const string HiddenWordArr[10] = { "myth", "duck", "verb", "gasp", "jinx", "wolf",  "black", "fight", "jumpy", "drown" };
public:
    //GENERATE SEED
    BullAndCowGame() { srand( time( NULL ) ); };
    //GET WORD at RANDOM from hidden word LIST
    string getHiddenWord() { return HiddenWordArr[rand() % 10]; };
};
//CLASS INITILIAZTION
BullAndCowGame Game;






int main() 
{

    //WELCOME message
    cout 
        << endl << endl 
        << "Welcome to Bull Cow Game!" 
        << endl
        << "Can you guess the secret isogram?"
        << endl << endl
    ;

    bool bPlayAgain;

    //LOOP PLAY until player is done
    do {  

        //PLAY single LEVEL
        PlayGame();

        bPlayAgain = AskToPlayAgain();
        
    } 
    while( bPlayAgain );

    return 0;
    
}



void PlayGame()
{

    //GENERATE WORD and DECLARE all VARIABLES that will be used
    string HiddenWord = Game.getHiddenWord();
    string PlayerValidGuess = "";

    int WordLength = HiddenWord.length();
    int Lives = HiddenWord.length() + 2;// TODO: Make a TMAP for lives
    int Bulls = 0;
    int Cows = 0;
    int *BullPointer = &Bulls;
    int *CowPointer = &Cows;

    cout 
        << endl << endl << endl << endl << endl
        << "Can you guess the " << WordLength << " letter isogram?"
        << endl << endl
    ;

    //LOOP till NO LIVES or CORRECT GUESS
    while( Lives != 0 && Bulls < WordLength )
    {

        cout
            << "Lives: " << Lives
            << endl << endl
        ;

        PlayerValidGuess = GetValidGuess( WordLength );

        GetBullsAndCows( PlayerValidGuess , HiddenWord , BullPointer , CowPointer );

        cout
            << "You got " << Bulls << " Bulls and " << Cows << " Cows..."
            << endl << endl
        ;
        
        Lives--;

    }

    cout 
        << "The word was: " << HiddenWord 
        << endl << endl
    ;

    //CHECK if PLAYER has WON game
    if( Bulls == WordLength ) { cout << "YOU WIN!"; }
    else { cout << "You Lose... Try Again..."; }
    cout << endl << endl;
    
}



bool AskToPlayAgain() 
{

    string PlayerInput = "";

    cout 
        << endl
        << "Would you like to play again? (y/n)" 
        << endl
    ;    
    
    getline( cin , PlayerInput );

    if( PlayerInput == "y" || PlayerInput == "Y") 
    { 
        cout << endl << endl;
        return  true; 
    }
    
    cout << endl << endl;
    return  false; 

}



string GetValidGuess( int WordLength ) 
{

    string Guess = "";
    bool bIsValid = false;

    //LOOP till player inputs VALID GUESS
    while( !bIsValid ) 
    {
        cout 
            << "Enter your guess..."
            << endl
        ; 
        getline( cin , Guess );

        bIsValid = CheckIfValid( Guess, WordLength );
    }

    return Guess;

}




bool CheckIfValid( string Guess, int WordLength )
{

    //CHECK if LETTERS are UPPERCASE, REPEATED, or if GUESS is wrong LENGTH
    if( !IsLowerCase( Guess ) )
    {
        cout 
            << "Your guess needs to be all lowercase..."
            << endl << endl
        ; 
        return false;
    }
    if( !IsIsogram( Guess ) )
    {
        cout 
            << "Your guess cannot have repeating letters..."
            << endl << endl
        ;
        return false;
    }
    if( Guess.length() != WordLength )
    {
        cout 
            << "Your guess needs to have " << WordLength << " letters..."
            << endl << endl
        ;
        return false;
    }

    return true;

}



bool IsLowerCase( string Guess )
{

    //LOOP till all LETTERS CHECKED to see if LOWERCASE
    for( int guessPlace = 0; guessPlace < Guess.length() ; guessPlace++ )
    {
        if( islower( Guess[ guessPlace ] ) == 0 ) { return false; }        
    }
    return true;

}



bool IsIsogram( string Guess )
{

    //LETTERS that have been SEEN will be STORED here
    map<char, bool> SeenLetters;
        
    for( int guessPlace = 0 ; guessPlace < Guess.length() ; guessPlace++ )
    {   
        //CHECK if LETTER was SEEN already, then this will be TRUE
        if ( SeenLetters[ Guess[ guessPlace ] ] )
        {
            return false;
        }
        //once LETTER is SEEN if it is called again it will be MAPPED as TRUE
        SeenLetters[ Guess[ guessPlace ] ] = true; 
    }
    return true;

}



void GetBullsAndCows( string Guess , string Word , int *BullPointer , int *CowPointer )
{

    int BullCount;
    int CowCount;

    //LOOP through all LETTERS of GUESS and hidden WORD
    for( int guessPlace = 0 ; guessPlace < Guess.length() ; guessPlace++ )
    {
        for( int wordPlace = 0 ; wordPlace < Word.length() ; wordPlace++ )
        {
            //CHECK if SAME PLACE and SAME LETTER
            if( guessPlace == wordPlace && Guess[ guessPlace ] == Word[ wordPlace ] )
            { BullCount++; }
            //else CHECK if SAME LETTER
            else if ( Guess[ guessPlace ] == Word[ wordPlace ] )
            { CowCount++; }                 
        }
    }
    //SET VALUE of BULLS and COWS by pointing to PLAYGAME() instance of VARIABLES
    *BullPointer = BullCount;
    *CowPointer = CowCount;                

}