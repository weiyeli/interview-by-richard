//
//  ViewController.m
//  WebDemo
//
//  Created by ricardooli on 2022/2/28.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    NSURL *url = [NSURL URLWithString:@"https://www.baidu.com"];
    NSLog(@"%@", [[url pathComponents] lastObject]);
}


@end
