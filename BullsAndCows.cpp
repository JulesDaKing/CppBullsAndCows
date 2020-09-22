#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;

int main() 
{

    //WELCOME message
    cout 
        << endl << endl 
        << "Welcome to Bull Cow Game!" 
        << endl << endl
    ;


    //GAME PLAN:
    /*

        MAIN FUNCTION:

        Main Game Loop()
            Initialization
            + Word = getHiddenWord()
            + Lives = getLives()
            + WordGuessed = false
            + WordLength = Word.length
            + Bulls = 0
            + Bulls pointer
            + Cows = 0
            + Cows pointer
            Print Word Clues
            while (lives !== 0 and word not guessed) 
            {
                getValidGuess()
                getBullsAndCows()//Compare Input to Word
                print Bulls and Cows
                if (bulls == word.length) return true
                lives--
            }
            return false
        Print End Screen
        Ask if player wants to play again
        if (True)  --  doesnt have to be recursion can be while loop
            call Main Game Loop()

        ADDITIONAL FUNCTIONS: Seperate file BullsAndCowsFunctions.h and .cpp

        enum class EWordList??
            words
        
        EWordList getHiddenWord() {
            Word == enum(srand(time()) % EWordList.size??)
            return Word
        }
        
        void getBullsAndCows(Guess, Word, WordSize, Bull Pointer, Cow Pointer)
        {
            loop till all letters of guess checked (x)
                loop till all letter of word checked (y)
                while (match == false & WordPlace <= WordSize)
                    if ( x == y && Guess(x) == Word(y) )
                    BullCount ++
                    else if (Guess (x) == Word(y))
                    CowCount ++
                    else
                    y++
                x++
            int &Bulls == BullCount
            int &Cows == CowCount
        }

        getValidGuess
        {
            string Guess
            bool isValid == false
            while (isValid == false)
            {
                cin guess
                isValid = checkValidity
            }
            return Guess
        }

        bool checkValidity(Guess, Word)
        {
            if (!IsLowerCase(guess))
                cout "Your guess is not all lowercase"
                return false
            if (!IsIsogram(guess))
                cout "Your guess is not an isogram"
                return false
            if (Guess.length !== Word.length)
                cout "Your guess is not the correct length"
                return false
            return true
        }
            
        IsLowerCase(guess)
            loop till word is checked
                if word[x] != isLower(word[x])
                    return false
            return true

        IsIsogram(guess)
            TMAP<char, bool> letterCheck;
            loop till word is checked
                if lettercheck[word[x]]
                    return false
                lettercheck[word[x]] = true
            return true
    */

    cout << endl << endl;

    return 0;
    
}