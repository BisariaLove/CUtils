//
//  find_unique_characters.c
//  CTCI - QUESTION - 1.1
//
//  Created by Love Bisaria on 12/18/14.
//
//

#include <stdio.h>
#include <string.h>
#define MAXARRAYSIZE  300

int isUniqueChar2(char *str);

int main(){
    
    char str[MAXARRAYSIZE];
    
    printf("Enter the String..!!\n");
    scanf("%s" , str);
    
    int result = isUniqueChar2(str);
    
    if(result == 0)
        printf("String doesnot have all unique characters..!!\n");
    else
        printf("String has all the characters unique..!!\n");
    
    return 0;
}

int isUniqueChar2(char *str){
    
    printf("Proessing..!!\n");
    
    if(strlen(str) > 256) return 0;
    
    int char_set[256] , len , value;
    len = strlen(str);
    
    for (int i=0; i<len; i++ ) {
        
        value = str[i];
        
        if(char_set[value]){
            return 0;
        }
        
        char_set[value] = 1;
    }
    
    return 1;
}
