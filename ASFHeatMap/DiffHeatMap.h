//
//  DiffHeatMap.h
//  ASFHeatMap
//
//  Created by Andre Santana Ferreira on 15/03/17.
//  Copyright © 2017 Andre. All rights reserved.
//

#import "Heatmap.h"

@interface DiffHeatMap : Heatmap

- (void)setBeforeData:(NSDictionary *)before
            afterData:(NSDictionary *)after;

@end
