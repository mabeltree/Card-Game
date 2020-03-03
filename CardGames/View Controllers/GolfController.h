//
//  GolfController.m
//  UIlab
//
//  Created by Szeto, Mabel on 1/15/20.
//  Copyright © 2020 Mabel Szeto. All rights reserved.
//

#import "GolfController.h"
#include "calculator.h"

@implementation GolfController
@synthesize hole, ball, rsidewall, lsidewall, tsidewall, bsidewall, midwall, tmidwall, bmidwall, ballVelocityX, water, waterr, waterl, bridgersidewall, bridgelsidewall, ballVelocityY, portalbegin, portalend;


- (void)viewDidLoad {
  [super viewDidLoad];
  // changes hole image to be circular
  self.hole.layer.cornerRadius = .5*self.hole.layer.frame.size.height; // this rounds the conored of the image view making the hole a perfect circle
  self.hole.layer.masksToBounds = YES; //this applys the transformation

  [super viewDidLoad];
  // changes ball image to be circular
  self.ball.layer.cornerRadius = .5*self.ball.layer.frame.size.height; // this rounds the conored of the image view making the hole a perfect circle
  self.ball.layer.masksToBounds = YES; //this applys the transformation
    
    [super viewDidLoad];
    // changes beginning portal image to be circular
    self.portalbegin.layer.cornerRadius = .5*self.portalbegin.layer.frame.size.height; // this rounds the conored of the image view making the hole a perfect circle
    self.portalbegin.layer.masksToBounds = YES; //this applys the transformation

    [super viewDidLoad];
    // changes water image to be circular
    self.water.layer.cornerRadius = .5*self.water.layer.frame.size.height; // this rounds the conored of the image view making the hole a perfect circle
    self.water.layer.masksToBounds = YES; //this applys the transformation
    
    [super viewDidLoad];
    // makes the next level button invisible at the start
    self.level.alpha = 0;

}
- (IBAction)reset:(id)sender {
      NSLog(@"reset");
    self.ball.alpha = 1;
    self.ball.center = CGPointMake(self.origin.center.x, self.origin.center.y);
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
  NSLog(@"touches Began");
  UITouch *touch = [touches anyObject];
  // turn user interaction off as swipe begins
  [self.view setUserInteractionEnabled:NO];
   
  // store point a touch began
  self.firstPoint = [touch locationInView:self.view];
   
}

/**
* Automatic action that occus when user releases at end of swipe
*/
-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
  NSLog(@"touches Ended");
   
  UITouch *touch = [touches anyObject];
   
  // store point a touch end
  self.lastPoint = [touch locationInView:self.view];
   
  // logic to calculate swipevector as distance between touch began and touch end
  CGPoint swipeVector = CGPointMake(self.lastPoint.x - self.firstPoint.x, self.lastPoint.y - self.firstPoint.y);
   
  // velocity of ball based off of swipe
  self.ballVelocityX = speedScale * swipeVector.x;
  self.ballVelocityY = speedScale * swipeVector.y;
   
  // move ball occurs multiple times at this sampling rate, until friction causes ball to stop
  self.gameTimer = [NSTimer scheduledTimerWithTimeInterval:.05 target:self selector:@selector(moveBall) userInfo:nil repeats:YES];
}

/**
* Changes center of ball, which is connected to outlet, this is called recursively by timer
*/
-(void)moveBall {
  // simulates friction by reducing velocity
  self.ballVelocityX = speedDamping * self.ballVelocityX;
  self.ballVelocityY = speedDamping * self.ballVelocityY;
   
  // this is the ball move
  self.ball.center = CGPointMake(self.ball.center.x + self.ballVelocityX, self.ball.center.y + self.ballVelocityY);
   
  // logic to calculate if ball and hole collide
  if (CGRectIntersectsRect(self.ball.frame, self.hole.frame)) {
    [self.gameTimer invalidate];
    [self.view setUserInteractionEnabled:YES];
    self.ball.center = CGPointMake(self.hole.center.x, self.hole.center.y);
    self.ball.alpha = 0.5; // this changes the opacity to 50%
  //self.level.alpha = 1; makes the next level button show up
      self.level.alpha = 1;
  }
   // logic to calculate if ball falls into the water
   if (CGRectIntersectsRect(self.ball.frame, self.water.frame)) {
     [self.gameTimer invalidate];
     [self.view setUserInteractionEnabled:YES];
     self.ball.center = CGPointMake(self.water.center.x, self.water.center.y);
     self.ball.alpha = 0; // this changes the opacity to 50%
   }
    if (CGRectIntersectsRect(self.ball.frame, self.waterl.frame)) {
     [self.gameTimer invalidate];
     [self.view setUserInteractionEnabled:YES];
     self.ball.center = CGPointMake(self.water.center.x, self.water.center.y);
     self.ball.alpha = 0; // this changes the opacity to 50%
   }
    if (CGRectIntersectsRect(self.ball.frame, self.waterr.frame)) {
      [self.gameTimer invalidate];
      [self.view setUserInteractionEnabled:YES];
      self.ball.center = CGPointMake(self.water.center.x, self.water.center.y);
      self.ball.alpha = 0; // this changes the opacity to 50%
    }
    // logic to calculate if ball enters portal
    if (CGRectIntersectsRect(self.ball.frame, self.portalbegin.frame)) {
      [self.view setUserInteractionEnabled:YES];
      self.ball.center = CGPointMake(self.portalend.center.x, self.portalend.center.y);
    }
    /* logic to calculate if ball enters portal
    if (CGRectIntersectsRect(self.ball.frame, self.portalend.frame)) {
      [self.view setUserInteractionEnabled:YES];
      self.ball.center = CGPointMake(self.portalbegin.center.x, self.portalbegin.center.y);
    }
    */
//right, left, top, and bottom side walls in place
  if(CGRectIntersectsRect(self.ball.frame, self.rsidewall.frame)) {
  // simulates friction by reducing velocity
   self.ballVelocityX = (-1) * speedDamping * self.ballVelocityX;
   self.ballVelocityY = (1) * speedDamping * self.ballVelocityY;
  }
 if(CGRectIntersectsRect(self.ball.frame, self.lsidewall.frame)) {
 // simulates friction by reducing velocity
   self.ballVelocityX = (-1) * speedDamping * self.ballVelocityX;
   self.ballVelocityY = (1) * speedDamping * self.ballVelocityY;
  }
    if(CGRectIntersectsRect(self.ball.frame, self.tsidewall.frame)) {
    // simulates friction by reducing velocity
      self.ballVelocityX = (1) * speedDamping * self.ballVelocityX;
      self.ballVelocityY = (-1) * speedDamping * self.ballVelocityY;
     }
    if(CGRectIntersectsRect(self.ball.frame, self.bsidewall.frame)) {
    // simulates friction by reducing velocity
      self.ballVelocityX = (1) * speedDamping * self.ballVelocityX;
      self.ballVelocityY = (-1) * speedDamping * self.ballVelocityY;
     }
    if(CGRectIntersectsRect(self.ball.frame, self.midwall.frame)) {
    // simulates friction by reducing velocity
      self.ballVelocityX = (-1) * speedDamping * self.ballVelocityX;
      self.ballVelocityY = (-1) * speedDamping * self.ballVelocityY;
    }
    if(CGRectIntersectsRect(self.ball.frame, self.tmidwall.frame)) {
    // simulates friction by reducing velocity
      self.ballVelocityX = (-1) * speedDamping * self.ballVelocityX;
      self.ballVelocityY = (-1) * speedDamping * self.ballVelocityY;
    }
    if(CGRectIntersectsRect(self.ball.frame, self.bmidwall.frame)) {
    // simulates friction by reducing velocity
      self.ballVelocityX = (-1) * speedDamping * self.ballVelocityX;
      self.ballVelocityY = (-1) * speedDamping * self.ballVelocityY;
    }
    if(CGRectIntersectsRect(self.ball.frame, self.bridgersidewall.frame)) {
    // simulates friction by reducing velocity
      self.ballVelocityX = (-1) * speedDamping * self.ballVelocityX;
      self.ballVelocityY = (-1) * speedDamping * self.ballVelocityY;
    }
    if(CGRectIntersectsRect(self.ball.frame, self.bridgelsidewall.frame)) {
    // simulates friction by reducing velocity
      self.ballVelocityX = (-1) * speedDamping * self.ballVelocityX;
      self.ballVelocityY = (-1) * speedDamping * self.ballVelocityY;
    }
    
  // if ball slows/stops turn off game timer and turn user interaction back on
 if(fabs(self.ballVelocityX) < stopSpeed && fabs(self.ballVelocityY) < stopSpeed) {
 [self.gameTimer invalidate];
 [self.view setUserInteractionEnabled:YES];
 }
}


    //[self.gameTimer invalidate];
    //[self.view setUserInteractionEnabled:YES];
    // puts ball back into the start position


@end

