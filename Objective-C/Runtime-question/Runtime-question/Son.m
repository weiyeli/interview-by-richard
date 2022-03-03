//
//  Son.m
//  Runtime-question
//
//  Created by ricardooli on 2022/2/13.
//

#import "Son.h"
#import "Father.h"

@implementation Son

- (id)init {
    self = [super init];
    if (self) {
        NSLog(@"%@", NSStringFromClass([self class]));
        NSLog(@"%@", NSStringFromClass([super class]));
    }
    return self;
}

@end
