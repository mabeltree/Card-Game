//
//  ViewController.h
//  CardGames
//
//  Created by Szeto, Mabel on 2/27/20.
//  Copyright © 2020 Szeto, Mabel. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "Control.h"

#define SUIT_CNT 4
#define SYMBOL_CNT 13
#define DECK_CNT 52

@interface SJController : UIViewController

{
    CARD *cards;
    CARD *chand1;
    CARD *hand2;
    CARD *chand3;
    CARD *chand4;
}

//if i end up doing the swipe thing instead of place
@property (nonatomic) CGPoint firstPoint;
@property (nonatomic) CGPoint lastPoint;

@property (strong, nonatomic) IBOutlet UIImageView *pile;

@property (strong, nonatomic) IBOutlet UIImageView *tutplayer1deck;
@property (strong, nonatomic) IBOutlet UIImageView *tutplayer2deck;

@property (strong, nonatomic) IBOutlet UIImageView *player1deck;
@property (strong, nonatomic) IBOutlet UIImageView *player2deck;
@property (strong, nonatomic) IBOutlet UIImageView *player3deck;
@property (strong, nonatomic) IBOutlet UIImageView *player4deck;

@property (strong, nonatomic) IBOutlet UILabel *player1count;
@property (strong, nonatomic) IBOutlet UILabel *player2count;
@property (strong, nonatomic) IBOutlet UILabel *player3count;
@property (strong, nonatomic) IBOutlet UILabel *player4count;
@property (strong, nonatomic) IBOutlet UILabel *pilecount;

@property (strong, nonatomic) IBOutlet UIButton *slapXPile;
@property (strong, nonatomic) IBOutlet UIButton *placeXPile;

@property (strong, nonatomic) IBOutlet UILabel *gameMarquee;



@property (strong, nonatomic) NSTimer *cycleTimer;
@property (strong, nonatomic) NSTimer *marqueeTimer;

@property (strong, nonatomic) NSTimer *gameTimer;


@end
