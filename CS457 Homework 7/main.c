//
//  main.c
//  CS457 Homework 7
//
//  Created by Josh Collins on 11/7/17.
//  Copyright © 2017 Josh Collins. All rights reserved.
//
//  This program will determine what normal form a database is
//  based off of dependencies in relationships using a linked list structure
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct keys {
    char *name;
    struct keys *next;
} Keys;

typedef struct dependencies {
    char *left;
    char *right;
    struct dependencies *next;
} Dependencies;

Keys *newKey(char *n, Keys* key)    {
    Keys *newKey = malloc(sizeof(Keys));
    newKey->name = n;
    newKey->next = key;
    return newKey;
}

Dependencies *newDependency(char *l,char *r, Dependencies *n)   {
    Dependencies *newD = malloc(sizeof(Dependencies));
    newD->left = l;
    newD->right = r;
    newD->next = n;
    return newD;
}

char *getKeyName(Keys *k)   {
    return k->name;
}

Keys *getNextKey(Keys *k)   {
    return k->next;
}

void setKeyName(Keys *k, char *s)  {
    k->name = s;
}

void setKeyNext(Keys *k, Keys *nextKey) {
    k->next = nextKey;
}

char *getLeftD(Dependencies *d) {
    return d->left;
}

char *getRightD(Dependencies *d)    {
    return d->right;
}

Dependencies *getNextD(Dependencies *d) {
    return d->next;
}

void setDLeft(Dependencies *d,char *l)  {
    d->left = l;
}

void setDRight(Dependencies *d, char *r)    {
    d->right = r;
}

void setDNext(Dependencies *d, Dependencies *n) {
    d->next = n;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char *delimiterCharacters = " ";
    char buffer[BUFFER_SIZE];
    char *lastToken;
    
    
    FILE *fp1 = fopen("HW7in.txt", "r");
    FILE *fp2 = fopen("HW7jjcollins2.txt", "w");
    char ch;
    
    if( fp1 == NULL )    {
        fprintf( stderr, "Unable to open file HW7in.txt for reading. \n");
    }
 
    
    ch = getc(fp1);
    while(!feof(fp1)) {
        putc(ch, fp2);
        ch = getc(fp1);
        if(ch == " ")   {
            fgets(buffer, BUFFER_SIZE, fp1);
            lastToken = strtok( buffer, delimiterCharacters );
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
