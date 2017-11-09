//
//  main.c
//  CS457 Homework 7
//
//  Created by Josh Collins on 11/7/17.
//  Copyright © 2017 Josh Collins. All rights reserved.
//
//  This program will determine what normal form a database is
//  based off of dependencies in relationships
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    FILE *fp1 = fopen("HW7in.txt", "r");
    FILE *fp2 = fopen("HW7jjcollins2.txt", "w");
    char ch;
    
    
    ch = getc(fp1);
    while(!feof(fp1)) {
        putc(ch, fp2);
        ch = getc(fp1);
    }
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
