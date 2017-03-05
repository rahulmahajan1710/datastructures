#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#import <Foundation/Foundation.h>
#import "Anagram.h"

int l,m,Row,Col,mat[300][300]={ {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9,  10, 11, 12},
    {13, 14, 15, 16}  };

void rotation(int l, int m, int Row, int Col)
{
    int si,sj,i,j,t,f;
    si = l;
    sj = m;
    
    t = mat[l][m];
    
    for(i=l+1;i<=Row;i++)
    {
        f = mat[i][m];
        mat[i][m] = t;
        t = f;
    }
    l++;
    for(i=m+1;i<=Col;i++)
    {
        f = mat[Row][i];
        mat[Row][i] = t;
        t = f;
    }
    m++;
    if(l-1 < Row)
    {
        for(i=Row-1;i>=l-1;i--)
        {
            f = mat[i][Col];
            mat[i][Col] = t;
            t = f;
        }
    }
    Col--;
    if(m-1 < Col)
    {
        for(i=Col;i>=m;i--)
        {
            f = mat[l-1][i];
            mat[l-1][i] = t;
            t = f;
        }
    }
    Row--;
    mat[si][sj] = t;
    return;
}


int main()
{
    
    //Delta -encoding
    int esc = -128;
    int a[] = {25626 ,25757 ,24367 ,24267 ,16 ,100 ,2 ,7277};
    int prev = a[0];
    NSMutableArray *res = [NSMutableArray array];
    [res addObject:[NSString stringWithFormat:@"%d",prev]];
    for (int i=1; i<8; i++) {
        int diff = a[i] - prev;
        if (abs(diff)>127) {
            [res addObject:[NSString stringWithFormat:@"%d",esc]];
        }
        [res addObject:[NSString stringWithFormat:@"%d",diff]];
        prev = a[i];
    }
    NSString *str = [res componentsJoinedByString:@" "];
    printf("%s",[str cStringUsingEncoding:NSUTF8StringEncoding]);
    //  25626 -128 131 -128 -1390 -100 -128 -24251 84 -98 -128 7275
    //  25626 -128 131 -128 -1390 -100 -128 -24251 84 -98 -128 7275
    
    //-------------------------------------//


    //Polygon finder-------//
    NSArray *values = @[@"36 30 36 30",
                        @"15 15 15 15",
                        @"46 96 90 100",
                        @"86 86 86 86",
                        @"100 200 100 200",
                        @"-100 200 -100 200"];
    
    int sq=0,rect=0,other=0;
    for (NSString *str in values) {
        NSArray *lenghts = [str componentsSeparatedByString:@" "];
        int a = [[lenghts objectAtIndex:0]intValue];
        int b = [[lenghts objectAtIndex:1]intValue];
        int c = [[lenghts objectAtIndex:2]intValue];
        int d = [[lenghts objectAtIndex:3]intValue];
        
        if (0 >= MIN(MIN(a, b), MIN(c, d))) {
            other++;
        }
        else if((a==b) && (b==c) && (c==d)){
            sq++;
        }
        else if((a==c) && (b==d)){
            rect++;
        }
        else{
            other++;
        }
    }
    printf("%d %d %d",sq,rect,other);
    
    //--------------------------------------------------//
    

    
    
    
    //Array Analyser-----------------//
    
    
    
    
    //--------------------------------------------------//
    
    
    //Anagram-----------------//
    
    Anagram *ang = [[Anagram alloc]init];
    [ang findAnagrams];
    //--------------------------------------------------//

    /*
    int r,c,k,i,j;
   // scanf("%d%d%d",&r,&c,&k);
    int f,K;
//    for(i=0;i<r;i++)
//    {
//        for(j=0;j<c;j++)
//        {
//            scanf("%d",&mat[i][j]);
//        }
//    }
    r= c = 4;
    k = 1;
    
    l = 0;
    m = 0;
    Row = r-1;
    Col = c-1;
    while(l < Row && m < Col)
    {
        int rot = 2*(Row-l)+2*(Col-m);
        f = k%rot;
        for(i=1;i<=f;i++)
        {
            rotation(l,m,Row,Col);
        }
        l++;
        m++;
        Row--;
        Col--;
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
     */
    return 0;
}
