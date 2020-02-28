//
//  cards.c
//  CardGames
//
//  Created by Szeto, Mabel on 2/27/20.
//  Copyright © 2020 Szeto, Mabel. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "Control.h"


/**
* Creates a deck of cards and returns point to the deck (CARD *) on the heap.  Memory is allocated during execution using malloc and persists beyond lifetime of funcion
*
* param  void
* @return CARD *
*/
CARD * createdeck()
{
    CARD *card;

    /* Initial memory allocation */
    card = (CARD *)malloc(sizeof(CARD) * DECK_CNT); // Intro to memory allocation, makes an array the size of the deck
    
    //this is how the cards are named/identified
    for(int suit = Clubs; suit <= Spades; suit++) {         // basically, starts at clubs and adds 1 to suit until gets through spades, Clubs Diamonds, Hearts, Spades
        char cardSuffix = (*suitStrings[suit]);      // make cardSuffix as 1st letter of suit
        
        for(int symbol = Ace; symbol <= King; symbol++ ) {  // basically, starts at ace and adds 1 to cards until gets through king. Ace, Two, Three ..., Queen, King
            int index = (suit * SYMBOL_CNT) + symbol;       // index equals: 0...12, 13...25, 26...38, 39...51
            card[index].cID = index + 1;
            card[index].value = symbol + 1;
            card[index].suit = suit;
            card[index].symbol = symbol;
            
            // Is card Red or Black
            switch (suit) {
                case Hearts: //if hearts or diamonds then it is red
                case Diamonds:
                    card[index].color = Red;
                    break;
                default:
                    card[index].color = Black; // all other suits default to black
            }
            
            // add cImage  to correspond to Assets.xcassets
            sprintf( card[index].cImage,"%c%d", cardSuffix, (symbol + 1) );
        }
    }
    return card;
}

CARD * chand1() //this is to make the different hands/decks
{
    CARD *card; // same as the CARD c[n] which tells us we are an array the size of n
    card = (CARD *)malloc(sizeof(CARD) * DECK_CNT); // Intro to memory allocation, makes
    
    for (int i = 0; i < DECK_CNT; i++){
        card[i].cID = -1; //the -1 is to fill the empty spaces in the array to let us know how many actual cards are in their deck
    }
    return card;
 }


/**
* Shuffles deck of cards
*
* param  CARD *
* return void
*/
void shuffledeck(CARD *card)
{
    // Shuffle cards
    CARD swap[1];
    for (int i = 0; i < DECK_CNT; i++) {        // goes through deck one time
        int r;
        while ( (r = rand() % DECK_CNT) == i);  // repeat if r = i, don't swap with itself
        
        // swap logic
        swap[0] = card[i];        // current saved to swap
        card[i] = card[r];        // current changed with random
        card[r] = swap[0];        // random changed with swap
    }
}
/**
* Console test program to deal deck of cards and display to console
*
* param  CARD *
* return void
*/
 CARD * createDeck1()
 {
     CARD *cards;

     /* Initial memory allocation */
     cards = (CARD *)malloc(sizeof(CARD) * PLAY1_CNT);         // Intro to memory allocatin
     //card = (CARD *)malloc(sizeof(CARD) * PYRMD_ROWS);
     return cards;
         
     }

/**
* Console test program to deal deck of cards and display to console
*
* param  CARD *
* return void
*/
void dealdeck(CARD *card)
{
    // Deal deck to two players
    CARD player1[DECK_CNT/2];               // half deck array for each player
    CARD player2[DECK_CNT/2];
    for (int i = 0, index = 0; i < DECK_CNT; i++)    // deal half deck to each
    {
        if ( (i % 2) == 0 ) {
            player1[index] = card[i];       // card to player1
            printf("%5s %5s of %-8s %d %d %s",
                   colorStrings[player1[index].color],
                   symbolStrings[player1[index].symbol], suitStrings[player1[index].suit],
                   player1[index].cID, player1[index].value, player1[index].cImage);
            
        } else {
            player2[index] = card[i];     // card to player2
            printf("\t\t\t");
            printf("%5s %5s of %-8s %d %d %s",
                   colorStrings[player2[index].color],
                   symbolStrings[player2[index].symbol], suitStrings[player2[index].suit],
                   player2[index].cID, player2[index].value, player2[index].cImage);
            printf("\n");
            index++;

        }

    }
    
}

/**
* Removes allocated deck (CARD *) from heap and stores in deep memory
*
* param  CARD *
* return void
*/
void freedeck(CARD *card)
{
    if (card != NULL)
        free(card);
}

void cards()
{
    // Setup 52 cards
    CARD card[DECK_CNT];
    for(int suit = Clubs; suit <= Spades; suit++)
    {     // Clubs, Diamonds, Hearts, Spades
        for(int symbol = Ace; symbol <= King; symbol++ )
        { // Ace, Two, Three ..., Queen, King
            int index = (suit * SYMBOL_CNT) + symbol;    // index equals: 0...12, 13...25, 26...38, 39...51
            card[index].cID = index + 1;
            card[index].value = symbol + 1;
            card[index].suit = suit;
            card[index].symbol = symbol;
        }
    }
    
    /*
     void hand()
    {
       //set it equal to the deck?
        }
   */
    // Shuffle cards
    CARD swap[1];
    for (int i = 0; i < DECK_CNT; i++) {    // traverse through deck one time
        int r;
        while ( (r = rand() % DECK_CNT) == i); // repeat if r = i, don't swap with itself
     
        // swap logic
        swap[0] = card[i];    // current saved to swap
        card[i] = card[r];    // current changed with random
        card[r] = swap[0];    // random changed with swap
    }
   
    // Deal deck to two players
    CARD player1[DECK_CNT/2];        // half deck array for each player
    CARD player2[DECK_CNT/2];
    for (int i = 0; i < DECK_CNT/2; i++)  // deal half deck to each
    {
        int index = i * 2;
        player1[index] = card[index];    // card to player1
        player2[index] = card[index+1];   // card to player2
     
        // Two column print out
        printf("%5s of %-8s %d %d",
               symbolStrings[player1[index].symbol], suitStrings[player1[index].suit],
               player1[index].cID, player1[index].value);
     
        printf("\t\t");
        printf("%5s of %-8s %d %d",
               symbolStrings[player2[index].symbol], suitStrings[player2[index].suit],
               player2[index].cID, player2[index].value);
        printf("\n");
    }

}
    
void winner (){
      //Enter code to announce win when someone gets to 52
  }


/**
* Creates a deck of cards and returns point to the deck (CARD *) on the heap.  Memory is allocated during execution using malloc and persists beyond lifetime of funciont
*
* param  void
* @return CARD *
*/

/**
* Creates a player hand
* param  void
* @return CARD *
*/
CARD * createhand(int size)
{
    CARD *hand;
    
    /* Initial memory allocation */
    // CARD cards[52];
    hand = (CARD *)malloc(sizeof(CARD) * size);         // Intro to memory allocatin
    
    for (int i = 0; i < size; i++) {
        hand[i].cID = -1;                               // Use -1 to signify position in hand is empty
    }
        
    return hand;
}

/**
* Copies data elements
* param  void
*/
void card2handcp(CARD *hand, CARD deck)
{
    /*  This will do the following
    h->cID = c->cID;
    h->value = c->value;
    h->suit = c->suit;
    h->symbol = c->symbol;
    h->color = c->color;
    strcpy(h->cImage, c->cImage);
     */
    *hand = deck;
#ifdef CARDLOGGING
    printf("copy to show hand: %s is same as card: %s\n", hand->cImage, hand->cImage);
#endif
}
