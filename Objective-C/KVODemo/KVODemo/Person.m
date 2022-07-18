//
//  Person.m
//  KVODemo
//
//  Created by ricardooli on 2022/3/6.
//

#import "Person.h"

@implementation Person

- (void)setAge:(int)age {
    NSLog(@"setAge:");
    _age = age;
}

- (void)willChangeValueForKey:(NSString *)key {
    NSLog(@"willChangeValueForKey: - begin");
    [super willChangeValueForKey:key];
    NSLog(@"willChangeValueForKey: - end");
}

- (void)didChangeValueForKey:(NSString *)key {
    NSLog(@"didChangeValueForKey: - begin");
    [super didChangeValueForKey:key];
    NSLog(@"didChangeValueForKey: - end");
}

@end
