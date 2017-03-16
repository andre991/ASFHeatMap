//
//  Heatmap.h
//  ASFHeatMap
//
//  Created by Andre Santana Ferreira on 15/03/17.
//  Copyright © 2017 Andre. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

static const CGFloat kSBMapRectPadding = 100000;
static const int kSBZoomZeroDimension = 256;
static const int kSBMapKitPoints = 536870912;
static const int kSBZoomLevels = 20;

// Alterable constant to change look of heat map
static const int kSBScalePower = 4;

// Alterable constant to trade off accuracy with performance
// Increase for big data sets which draw slowly
static const int kSBScreenPointsPerBucket = 10;

@class ColorProvider;

@interface Heatmap : NSObject<MKOverlay>

- (NSDictionary *)mapPointsWithHeatInMapRect:(MKMapRect)rect
                                     atScale:(MKZoomScale)scale;
- (MKMapRect)boundingMapRect;
- (void)setData:(NSDictionary *)newHeatMapData;

@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

@property (strong, nonatomic) ColorProvider *colorProvider;

@property (nonatomic, readonly) double maxValue;
@property (readonly) double zoomedOutMax;
@property (nonatomic, readonly) NSDictionary *pointsWithHeat;
@property (readonly) CLLocationCoordinate2D center;
@property (readonly) MKMapRect boundingRect;

@end
