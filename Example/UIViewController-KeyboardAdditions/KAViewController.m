//
//  KAViewController.m
//  UIViewController-KeyboardAdditions
//
//  Created by Andrew Podkovyrin on 02/03/2015.
//  Copyright (c) 2014 Andrew Podkovyrin. All rights reserved.
//

#import "KAViewController.h"
#import <UIViewController-KeyboardAdditions/UIViewController+KeyboardAdditions.h>

@interface KAViewController ()

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *containerViewBottomConstraint;

@end

@implementation KAViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    // register to keyboard notifications
    [self ka_startObservingKeyboardNotifications];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    // unregister from keyboard notifications
    [self ka_stopObservingKeyboardNotifications];
}

#pragma mark - KAKeyboardAdditions

- (void)ka_keyboardWillShowOrHideWithHeight:(CGFloat)height
                          animationDuration:(NSTimeInterval)animationDuration
                             animationCurve:(UIViewAnimationCurve)animationCurve {
    
    NSLog(@"Will %@ with height = %f, duration = %f",
              self.ka_isKeyboardPresented ? @"show" : @"hide",
              height,
              animationDuration);
}

- (void)ka_keyboardShowOrHideAnimationWithHeight:(CGFloat)height
                               animationDuration:(NSTimeInterval)animationDuration
                                  animationCurve:(UIViewAnimationCurve)animationCurve {
    
    self.containerViewBottomConstraint.constant = height;
    [self.view layoutIfNeeded];
}

- (void)ka_keyboardShowOrHideAnimationDidFinishedWithHeight:(CGFloat)height {
    
    NSLog(@"Animation finished with height = %f", height);
}

#pragma mark - UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return YES;
}

@end
