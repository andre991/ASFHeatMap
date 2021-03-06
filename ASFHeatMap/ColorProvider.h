//
//  ColorProvider.h
//  ASFHeatMap
//
//  Created by Andre Santana Ferreira on 15/03/17.
//  Copyright © 2017 Andre. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// These affect the transparency of the heatmap
// Colder areas will be more transparent
// Currently the alpha is a two piece linear function of the value
// Play with the pivot point and max alpha to affect the look of the heatmap

// This number should be between 0 and 1
static const CGFloat kSBAlphaPivotX = 0.333;

// This number should be between 0 and MAX_ALPHA
static const CGFloat kSBAlphaPivotY = 0.5;

// This number should be between 0 and 1
static const CGFloat kSBMaxAlpha = 0.85;

@interface ColorProvider : NSObject

- (void)colorForValue:(double)value
                  red:(CGFloat *)red
                green:(CGFloat *)green
                 blue:(CGFloat *)blue
                alpha:(CGFloat *)alpha;
@end
