//
//  Control.h
//  CardGames
//
//  Created by Szeto, Mabel on 2/27/20.
//  Copyright © 2020 Szeto, Mabel. All rights reserved.


#ifndef Control_h
#define Control_h
#include <math.h>
#include <stdio.h>
#include <string.h>

// Classic C style defines for Operator control
#define WORDS_TO_LINE_SIZE 1000
#define BUFFER_SIZE 80
#define FILE_BUFFER_SIZE 1050
#define LINE_BUFFER_SIZE 500

// cards
#define SUIT_CNT 4
#define SYMBOL_CNT 13
#define DECK_CNT 52

#define PLAY1_CNT 52
#define PLAY2_CNT 52
#define PLAY3_CNT 52
#define PLAY4_CNT 52
#define PILE_CNT 52
static char *colorStrings[] = {"Red", "Black"};
static char *suitStrings[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
static char *symbolStrings[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

typedef enum {Red, Black} COLOR_TYPE;
typedef enum {Clubs, Diamonds, Hearts, Spades} SUIT_TYPE;
typedef enum {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King} SYMBOL_TYPE;

typedef struct card {
    int cID; // unique ID of card (1 to 52 on conventional deck)
    int value; // 1, 2, ... 13, used to determine rank in games
    COLOR_TYPE color; // Red or Black
    SUIT_TYPE suit; // Clubs, Diamonds, Hearts, Spaces
    SYMBOL_TYPE symbol; // Ace, Two, ... King
    char cImage[20];
} CARD;
CARD * createdeck(void);
CARD * createDeck1(void);

CARD * chand1(void);
CARD * hand2(void);
CARD * chand3(void);
CARD * chand4(void);
/*
COMPH1 *chand1;
HAND2 *hand2;
COMPH1 *chand3;
COMPH1 *chand4;
*/

void shuffledeck(CARD *c);
void dealdeck(CARD *c);
void freedeck(CARD *c);

void pointertest(void);
void structuretest(void);

void card2handcp(CARD *hand, CARD deck);
CARD * createhand(int size);


/* Classic C style defines for Operator control
 was supposed to be for the switch statement fo the shorthand
#define you 0
#define You 1
#define to 2
#define To 3
#define and 4
#define And 5
#define FOR 6 //for
#define For 7
*/

#endif /* calculator_h */
