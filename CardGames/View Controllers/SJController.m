//
//  ViewController.m
//  CardGames
//
//  Created by Szeto, Mabel on 2/27/20.
//  Copyright © 2020 Szeto, Mabel. All rights reserved.
//

#import "SJController.h"
#include <math.h>
//#include "Control.h"


@implementation SJController
@synthesize pile, player1deck, player2deck, player3deck, player4deck;
@synthesize player1count, player2count, player3count, player4count, pilecount;
@synthesize slapXPile, placeXPile;
@synthesize cycleTimer;

- (void)viewDidLoad {
    [super viewDidLoad];

    freedeck(cards); // check of second time run, free/release any remaining residual deck
    cards = createdeck();       // new deck
    shuffledeck(cards);         // shuffle

    [super viewDidLoad];  //this rotates the cards
    player1deck.transform = CGAffineTransformMakeRotation(0); //0 radians
    player2deck.transform = CGAffineTransformMakeRotation(0);
    //player3deck.transform = CGAffineTransformMakeRotation(M_PI/2); //the rotations are in radians
    //player4deck.transform = CGAffineTransformMakeRotation(M_PI/2);
}

// The method touchesBegan stops demo mode and transition to game
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    NSLog(@"touches Began");
    freedeck(cards);            // free demo deck
    cards = createdeck();       // start new deck
    shuffledeck(cards);         // shuffle
    
    // user interaction mode begins, stop autonomous cycle
    [self.cycleTimer invalidate];
}

//deal the shuffled cards to each player
//start the game with plyer one
-(void)startCards {
//counters are initialized once
 int pilecount = 0;                // autonmous card counter
    int player1count = 0;
    int player2count = 0;
    int player3count = 0;
    int player4count = 0;

//make an array for dealing the cards
    int playercount[] = {0,0,0,0};
    

// autonomous control
    
long c = pilecount % DECK_CNT;
player1count = player1count == 0 ? DECK_CNT/4 : player1count;
player2count = player2count == 0 ? DECK_CNT/4 : player2count;
player3count = player3count == 0 ? DECK_CNT/4 : player3count;
player4count = player4count == 0 ? DECK_CNT/4 : player4count;

// current card
NSString *cId = [NSString stringWithFormat:@"%s.png" , cards[c].cImage] ;

// switch between player and computer cards, when computer card is played game logic begins
if ((c % 2)==0) {
    // play card into the pile
    [pile setImage:[UIImage imageNamed:cId]];
    // decrement player card counter
    player1count = [NSString stringWithFormat:@"%d" , --player1count];
    
} else {
    // play computer card in war zone
    [pile setImage:[UIImage imageNamed:cId]];
    // decrement computer card counter
    player2count = [NSString stringWithFormat:@"%d" , --player2count];
    
    // find previous card image
    NSString *pId = [NSString stringWithFormat:@"%s.png" , cards[c-1].cImage] ;
}
}

-(void)buildHands {
    //sets up different hands for the palyer and computer(s)
    freedeck(cards);            // free demo deck
    cards = createdeck();       // start new deck
    shuffledeck(cards);         // shuffle
    
    chand1 = createDeck1;
  /*
   [self freeHands];
  player1count = createhand(DECK_CNT);
    player2count = createhand(DECK_CNT);
    player3count = createhand(DECK_CNT);
    player4count = createhand(DECK_CNT);
    for (int cardIndex = 0, pIndex = 0, cIndex1 = 0, cIndex3 = 0, cIndex4 = 0; cardIndex < DECK_CNT;cardIndex++)
    {
        if ((cardIndex % 4)==0) {
            player1deck(&player[pIndex], cards[cardIndex]);
            pIndex++;
        }
        else{
            player2deck(&computer[cIndex1], cards[cardIndex]);
            cIndex1++;
        }
    }
    */
}
     
- (IBAction)slap:(id)sender{
//when pile is slaped with a jack on it, transfer pile to the player, update the pile and player count
//    slapXPile = [NSString stringWithFormat:@"%d" , slapPile() ];
    
//when pile is slaped but it is not a jack on top, player burns a card by giving it to the previous player, update the pile and player count
}
    /*
     - (IBAction)reverse:(id)sender {
     const char *cInput = [input.text UTF8String];
     long inputLength = input.text.length;
     // Method 1 - Array method
     revXArray.text = [NSString stringWithFormat:@"%s" , revArray((char*)cInput, inputLength) ];
     */

- (IBAction)place:(id)sender {
//transfers a card from the player 2 deck to the pile
    //maybe do swipe instead of place for the card
  //  placeXPile = [NSString stringWithFormat:@"%s" , placePile() ];

}

@end

/* Mr. M's code
 #import "CardController.h"

 @implementation CardController

 @synthesize firstPoint, lastPoint;
 @synthesize computerDeck, computerWarPlay, computerWins1, computerWins2, computerDeckCnt, computerDeckWinsCnt;
 @synthesize playerDeck, playerWarPlay, playerWins1, playerWins2, playerDeckCnt, playerDeckWinsCnt;
 @synthesize gameMarquee;
//Prepare for the game, draw fun demo screen

 - (void)viewDidLoad {
     [super viewDidLoad];

     freedeck(cards);            // check of second time run, free/release any remaining residual deck
     cards = createdeck();       // new deck
     shuffledeck(cards);         // shuffle
     
     // marquee message setup
     self.marqueeTimer = [NSTimer scheduledTimerWithTimeInterval:.10 target:self selector:@selector(marqueeScroll) userInfo:nil repeats:YES];

     // autonomous game timer (preview)
     self.cycleTimer = [NSTimer scheduledTimerWithTimeInterval:.50 target:self selector:@selector(autonomousCards) userInfo:nil repeats:YES];
 }

 
// Automomous cards provides preview of game
 -(void)autonomousCards {
     // statics are initialized once
     static int counter = 0;                // autonmous card counter
     static int counterCompDeck = 0;
     static int counterPlayDeck = 0;
     
     // autonomous control
     long c = counter % DECK_CNT;
     counterCompDeck = counterCompDeck == 0 ? DECK_CNT/2 : counterCompDeck;
     counterPlayDeck = counterPlayDeck == 0 ? DECK_CNT/2 : counterPlayDeck;
     
     // current card
     NSString *cId = [NSString stringWithFormat:@"%s.png" , cards[c].cImage] ;
     
     // switch between player and computer cards, when computer card is played game logic begins
     if ((c % 2)==0) {
         // play player card in war zone
         [playerWarPlay setImage:[UIImage imageNamed:cId]];
         // decrement player card counter
         playerDeckCnt.text = [NSString stringWithFormat:@"%d" , --counterPlayDeck];
         
     } else {
         // play computer card in war zone
         [computerWarPlay setImage:[UIImage imageNamed:cId]];
         // decrement computer card counter
         computerDeckCnt.text = [NSString stringWithFormat:@"%d" , --counterCompDeck];
         
         // find previous card image
         NSString *pId = [NSString stringWithFormat:@"%s.png" , cards[c-1].cImage] ;
         
         // compare winner, account for Ace as high
         int computerValue = cards[c].symbol == Ace ? SYMBOL_CNT : cards[c].value;
         int playerValue = cards[c-1].symbol == Ace ? SYMBOL_CNT : cards[c-1].value;
         if (computerValue > playerValue)    // determine winner
         {
             [computerWins1 setImage:[UIImage imageNamed:pId]];          // computer winnings
             [computerWins2 setImage:[UIImage imageNamed:cId]];
             computerDeckWinsCnt.text = [NSString stringWithFormat:@"%d", computerDeckWinsCnt.text.intValue+2];
         } else {
             [playerWins1 setImage:[UIImage imageNamed:pId]];            // player winnings
             [playerWins2 setImage:[UIImage imageNamed:cId]];
             playerDeckWinsCnt.text = [NSString stringWithFormat:@"%d", playerDeckWinsCnt.text.intValue+2];
         }
     }
     counter++;
 }

 //Scrolling message provides instruction how to transition from Demo to Playing game

 -(void)marqueeScroll {
     // statics are initialized once
     static NSString *marqueMsg=@".......  Tap on screen to start your own game of war .......";
     static NSInteger start = 0;
     static NSInteger len = 0;
     static NSInteger len2 = 0;

     if (len < marqueMsg.length) {
         self.gameMarquee.textAlignment = NSTextAlignmentRight;
         gameMarquee.text =  [marqueMsg substringWithRange:NSMakeRange(start, len++)];
         len2 = len;
     } else if (start < marqueMsg.length){
         self.gameMarquee.textAlignment = NSTextAlignmentLeft;
         gameMarquee.text =  [marqueMsg substringWithRange:NSMakeRange(++start, --len2)];
     } else {
         start = 0; len = 0;
     }
 }

// The method touchesBegan stops demo mode and transition to game
 - (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
     NSLog(@"touches Began");
     
     freedeck(cards);            // free demo deck
     cards = createdeck();       // start new deck
     shuffledeck(cards);         // shuffle
     
     // user interaction mode begins, stop autonomous cycle
     [self.marqueeTimer invalidate];
     [self.cycleTimer invalidate];
     
     // hide marquee message
     gameMarquee.alpha = 0;

     // grab touch
     UITouch *touch = [touches anyObject];
     
     // turn user interaction off as swipe begins
     [self.view setUserInteractionEnabled:NO];
     
     // store point a touch began
     self.firstPoint = [touch locationInView:self.view];

 }

//Not really used YET
 -(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
     NSLog(@"touches Ended");
     
     UITouch *touch = [touches anyObject];
     
     // store point a touch end
     self.lastPoint = [touch locationInView:self.view];
     
     // logic to calculate swipevector as distance between touch began and touch end
     CGPoint swipeVector = CGPointMake(self.lastPoint.x - self.firstPoint.x, self.lastPoint.y - self.firstPoint.y);
     
     NSLog(@"%f,%f", swipeVector.x, swipeVector.y);
     
     [self.view setUserInteractionEnabled:YES];
 }


 @end


 */
