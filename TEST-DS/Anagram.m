//
//  Anagram.m
//  test
//
//  Created by Rameshwar Jadhav on 05/03/17.
//  Copyright © 2017 Rameshwar Jadhav. All rights reserved.
//

#import "Anagram.h"

@implementation Anagram
- (instancetype)init
{
    self = [super init];
    if (self) {
       
    }
    return self;
}

-(void)findAnagrams{
    NSArray *temp = @[@"pear",
                      @"amleth",
                      @"dormitory",
                      @"tinsel",
                      @"dirty room",
                      @"hamlet",
                      @"listen",
                      @"silnet"];
    NSMutableArray *result = [NSMutableArray array];
    for (int i=0; i<temp.count; i++) {
        NSString *str=[temp objectAtIndex:i];
        if (str.length>0) {
            [result addObject:[self anagramsForWord:str inArray:temp]];
        }
    }
    NSSet *set = [[NSSet alloc]initWithArray:result];
    result = [[set allObjects]mutableCopy];
    for (int j=0; j<result.count; j++) {
        NSArray *sorted = [[result objectAtIndex:j]sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
        NSString *tempStr= [sorted componentsJoinedByString:@","];
        [result replaceObjectAtIndex:j withObject:tempStr];
    }
   
    NSLog(@"%@",[result sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)]);
}

-(NSArray*)anagramsForWord:(NSString*)word inArray:(NSArray*)strArr{
    NSMutableArray *temp = [NSMutableArray array];
    for (NSString *s1 in strArr) {
        if ([[self charCountInString:s1]isEqualToDictionary:[self charCountInString:word]]) {
            [temp addObject:s1];
        }
    }
    return temp;
}


-(NSDictionary*)charCountInString:(NSString*)str{
    NSMutableDictionary *charInfo = [NSMutableDictionary dictionary];
    NSString *strWoSp = [[str stringByReplacingOccurrencesOfString:@" " withString:@""]lowercaseString];
    for (int j=0; j<strWoSp.length; j++) {
        NSString *charStr = [NSString stringWithFormat:@"%C", [strWoSp characterAtIndex:j]];
        int cnt = 1;
        if ([charInfo objectForKey:charStr]) {
            cnt = [[charInfo objectForKey:charStr]intValue]+1;
        }
        [charInfo setObject:[NSNumber numberWithInt:cnt] forKey:charStr];
    }
    return  charInfo;
}
@end
