//
//  GolfController.m
//  CardGames
//
//  Created by Szeto, Mabel on 3/2/20.
//  Copyright © 2020 Szeto, Mabel. All rights reserved.
//

#import <UIKit/UIKit.h>

// These values simulate speed and friction
#define speedScale 0.20
#define speedDamping 0.90  // friction rate
#define stopSpeed 5.0

@interface GolfController : UIViewController
@property (strong, nonatomic) IBOutlet UIImageView *hole;
@property (strong, nonatomic) IBOutlet UIImageView *ball;

@property (strong, nonatomic) IBOutlet UIImageView *wall;
@property (strong, nonatomic) IBOutlet UIImageView *rsidewall;
@property (strong, nonatomic) IBOutlet UIImageView *lsidewall;
@property (strong, nonatomic) IBOutlet UIImageView *tsidewall;
@property (strong, nonatomic) IBOutlet UIImageView *bsidewall;
@property (strong, nonatomic) IBOutlet UIImageView *midwall;
@property (strong, nonatomic) IBOutlet UIImageView *tmidwall;
@property (strong, nonatomic) IBOutlet UIImageView *bmidwall;
@property (strong, nonatomic) IBOutlet UIImageView *water;
@property (strong, nonatomic) IBOutlet UIImageView *waterr;
@property (strong, nonatomic) IBOutlet UIImageView *waterl;
@property (strong, nonatomic) IBOutlet UIImageView *bridgersidewall;
@property (strong, nonatomic) IBOutlet UIImageView *bridgelsidewall;
@property (strong, nonatomic) IBOutlet UIImageView *portalbegin;
@property (strong, nonatomic) IBOutlet UIImageView *portalend;
@property (strong, nonatomic) IBOutlet UIButton *level;
@property (strong, nonatomic) IBOutlet UILabel *origin;





@property (nonatomic) CGPoint firstPoint;
@property (nonatomic) CGPoint lastPoint;
@property (nonatomic) float ballVelocityX;
@property (nonatomic) float ballVelocityY;

@property (strong, nonatomic) NSTimer *gameTimer;

@end

/* GolfController_h

Drag Outlets into GameController.h.
Right Click Open your h file in a new window.  Ctr-drag storyboard hole and ball to your .h file
Name them ball and hole.

*/

