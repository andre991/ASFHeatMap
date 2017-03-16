//
//  DiffHeatMap.m
//  ASFHeatMap
//
//  Created by Andre Santana Ferreira on 15/03/17.
//  Copyright © 2017 Andre. All rights reserved.
//

#import "DiffHeatMap.h"
#import "DiffColorProvider.h"

@interface DiffHeatMap ()
@property double maxValue;
@property double zoomedOutMax;
@property NSDictionary *pointsWithHeat;
@property CLLocationCoordinate2D center;
@property MKMapRect boundingRect;
@end

@implementation DiffHeatMap


@synthesize maxValue, pointsWithHeat = _pointsWithHeat;
@synthesize zoomedOutMax;
@synthesize center, boundingRect;

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.colorProvider = [DiffColorProvider new];
    }
    
    return self;
}

- (void)setBeforeData:(NSDictionary *)before
            afterData:(NSDictionary *)after
{
    self.maxValue = 0;
    
    NSMutableDictionary *newHeatMapData = [NSMutableDictionary new];
    for (NSValue *mapPointValue in [before allKeys]) {
        newHeatMapData[mapPointValue] = @(-1 * [before[mapPointValue] doubleValue]);
    }
    
    for (NSValue *mapPointValue in [after allKeys]) {
        if (newHeatMapData[mapPointValue]) {
            double beforeValue = [newHeatMapData[mapPointValue] doubleValue];
            double afterValue = [after[mapPointValue] doubleValue];
            newHeatMapData[mapPointValue] = @(beforeValue + afterValue);
        } else {
            newHeatMapData[mapPointValue] = after[mapPointValue];
        }
    }
    
    [super setData:newHeatMapData];
}


@end
