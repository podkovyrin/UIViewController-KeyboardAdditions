# UIViewController-KeyboardAdditions

[![Version](https://img.shields.io/cocoapods/v/UIViewController-KeyboardAdditions.svg?style=flat)](http://cocoadocs.org/docsets/UIViewController-KeyboardAdditions)
[![License](https://img.shields.io/cocoapods/l/UIViewController-KeyboardAdditions.svg?style=flat)](http://cocoadocs.org/docsets/UIViewController-KeyboardAdditions)
[![Platform](https://img.shields.io/cocoapods/p/UIViewController-KeyboardAdditions.svg?style=flat)](http://cocoadocs.org/docsets/UIViewController-KeyboardAdditions)

## Swift Version

For Swift compatible version check out [Keyboardy](https://github.com/podkovyrin/Keyboardy)

## Description

`UIViewController+KeyboardAdditions` category simplifies keyboard handling logic by extending UIViewController class with several simple methods.
Supports both AutoLayout and `frame`-based animations.

<img src="https://raw.github.com/podkovyrin/UIViewController-KeyboardAdditions/master/demo.gif" alt="UIViewController-KeyboardAdditions Demo GIF" style="display:block; margin: 10px auto 30px auto; align:center"/>

## Usage

1. Import category `#import <UIViewController-KeyboardAdditions/UIViewController+KeyboardAdditions.h>`

2. Register to keyboard notifications in `-viewWillAppear:`:
```obj-c
[self ka_startObservingKeyboardNotifications];
```

3. Unregister from notifications in `-viewWillDisappear:`:
```obj-c
[self ka_stopObservingKeyboardNotifications];
```

4. Perform any layout with same animation options as keybord:

```obj-c
- (void)ka_keyboardShowOrHideAnimationWithHeight:(CGFloat)height
                               animationDuration:(NSTimeInterval)animationDuration
                                  animationCurve:(UIViewAnimationCurve)animationCurve {

    self.containerViewBottomConstraint.constant = height;
    [self.view layoutIfNeeded];
}
```

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Installation

UIViewController-KeyboardAdditions is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

    pod "UIViewController-KeyboardAdditions"

## Author

Andrew Podkovyrin, podkovyrin@gmail.com

## License

UIViewController-KeyboardAdditions is available under the MIT license. See the LICENSE file for more info.

