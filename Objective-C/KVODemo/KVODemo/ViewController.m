//
//  ViewController.m
//  KVODemo
//
//  Created by ricardooli on 2022/3/6.
//

#import "ViewController.h"
#import "Person.h"
@import ObjectiveC.runtime;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    Person *p1 = [[Person alloc] init];
    Person *p2 = [[Person alloc] init];
    p1.age = 1;
    p1.age = 2;
    p2.age = 1;
    
    // 通过methodForSelector找到方法实现的地址
    NSLog(@"添加KVO监听之前: p1=%p, p2=%p", [p1 methodForSelector:@selector(setAge:)], [p2 methodForSelector:@selector(setAge:)]);
    
    // self监听p1的age属性
    NSKeyValueObservingOptions options = NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld;
    
    [p1 addObserver:self forKeyPath:@"age" options:options context:nil];
    p1.age = 1;
    
    [self printMethods: object_getClass(p2)];
    [self printMethods: object_getClass(p1)];
    
    NSLog(@"添加KVO监听之后: p1=%p, p2=%p", [p1 methodForSelector:@selector(setAge:)], [p2 methodForSelector:@selector(setAge:)]);
    
    [p1 removeObserver:self forKeyPath:@"age"];
}

- (void)observeValueForKeyPath:(nullable NSString *)keyPath ofObject:(nullable id)object change:(nullable NSDictionary<NSKeyValueChangeKey, id> *)change context:(nullable void *)context {
    NSLog(@"监听到 %@ 的 %@ 改变了 %@ ", object, keyPath, change);
}

- (void)printMethods:(Class)cls {
    unsigned int count;
    Method *methods = class_copyMethodList(cls, &count);
    NSMutableString *methodNames = [NSMutableString string];
    [methodNames appendFormat:@"%@ - ", cls];
    
    for (int i = 0; i < count; i++) {
        Method method = methods[i];
        NSString *methodName = NSStringFromSelector(method_getName(method));
        [methodNames appendString:methodName];
        [methodNames appendString:@" "];
    }
    
    NSLog(@"%@", methodNames);
    free(methods);
}

@end
