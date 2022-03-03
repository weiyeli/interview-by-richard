//
//  ViewController.m
//  Runtime-question
//
//  Created by ricardooli on 2022/2/13.
//

#import "ViewController.h"
#import "Son.h"
#import "Sark.h"
#import "NSObject+Sark.h"

// 题目来自于：https://halfrost.com/objc_runtime_isa_class/
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    // 1.下面代码输出什么？
//    Son *son __unused = [[Son alloc] init];
//    
//    // 2.下面代码的结果？
//    BOOL res1 = [(id)[NSObject class] isKindOfClass:[NSObject class]];
//    BOOL res2 = [(id)[NSObject class] isMemberOfClass:[NSObject class]];
//    BOOL res3 = [(id)[Son class] isKindOfClass:[Son class]];
//    BOOL res4 = [(id)[Son class] isMemberOfClass:[Son class]];
//    NSLog(@"res1 is: %d", res1);
//    NSLog(@"res2 is: %d", res2);
//    NSLog(@"res3 is: %d", res3);
//    NSLog(@"res4 is: %d", res4);
    
    // 3.下面的代码会？Compile Error/ Runtime Crash/ NSLog... ?
//    id cls = [Sark class];
//    void *obj = &cls;
//    [(__bridge id)obj speak];
    
    // 4.下面的代码会？Compile Error/ Runtime Crash/ NSLog... ?
//    [NSObject foo];
//    [[NSObject new] foo];
}


@end
