//
//  UIViewController+KeyboardAdditions.h
//
//  Copyright (c) 2015 Andrew Podkovyrin <podkovyrin@gmail.com>
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <UIKit/UIKit.h>


#pragma mark - Protocol

/**
 @name The Keyboard Additions protocol.
 */
@protocol KAKeyboardAdditions <NSObject>

/**
 Notifies the view controller that the keyboard will show or hide with specified parameters. This method is called before keyboard animation.
 
 @param height The height of keyboard.
 @param animationDuration The duration of keyboard animation.
 @param animationCurve The animation curve.
 */
- (void)ka_keyboardWillShowOrHideWithHeight:(CGFloat)height
                          animationDuration:(NSTimeInterval)animationDuration
                             animationCurve:(UIViewAnimationCurve)animationCurve;

/**
 The keyboard animation. This method is called inside UIView animation block with the same animation parameters as keyboard animation.
 
 @param height The height of keyboard.
 @param animationDuration The duration of keyboard animation.
 @param animationCurve The animation curve.
 */
- (void)ka_keyboardShowOrHideAnimationWithHeight:(CGFloat)height
                               animationDuration:(NSTimeInterval)animationDuration
                                  animationCurve:(UIViewAnimationCurve)animationCurve;

/**
 Notifies the view controller that the keyboard animation finished. This method is called after keyboard animation.
 
 @param height The height of keyboard.
 */
- (void)ka_keyboardShowOrHideAnimationDidFinishedWithHeight:(CGFloat)height;

@end


#pragma mark - Category

/**
 @name The UIViewController keyboard additions category.
 */
@interface UIViewController (KeyboardAdditions) <KAKeyboardAdditions>

///----------------------------------------------------------------------------
/// @name State Properties
///----------------------------------------------------------------------------

/**
 YES if keyboard height is > 0.
 */
@property (nonatomic, readonly) BOOL ka_isKeyboardPresented;

/**
 The height of keyboard.
 @note Extracted from `UIKeyboardFrameEndUserInfoKey` on show or sets to 0 on hide.
 */
@property (nonatomic, readonly) CGFloat ka_keyboardHeight;

///----------------------------------------------------------------------------
/// @name Notification Handling
///----------------------------------------------------------------------------

/**
 Starts observing for `UIKeyboardWillShowNotification` and `UIKeyboardWillHideNotification` notifications.
 
 @discussion It is recommended to call this method in `-viewWillAppear:`.
 */
- (void)ka_startObservingKeyboardNotifications;

/**
 Stops observing for `UIKeyboardWillShowNotification` and `UIKeyboardWillHideNotification` notifications.
 
 @discussion It is recommended to call this method in `-viewWillDisappear:`.
 */
- (void)ka_stopObservingKeyboardNotifications;

@end
