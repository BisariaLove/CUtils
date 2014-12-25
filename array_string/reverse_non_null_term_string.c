//
//  reverse_non_null_term_string.c
//  
//
//  Created by Love Bisaria on 12/18/14.
//
//

#include "../include/reverse_non_null_term_string.h"

int main(){
    
    char str[MAXARRAYSIZE] ;
    int i = 0;
   /* str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = 'd';
    str[4] = 'e'; */
    
    while (i < 26){
        str[i] = 'a' + i;
        i++;
    }

    printf("String before reversal..!!\n%s\n",str);
    
    reverse(str);
    
    printf("Reversed String..!!\n%s\n", str);
    
    return 0;
}

void reverse(char *str){
    
    printf("Processing..!!\n");
    
    char *end = NULL;
    char temp;
    end  = str;
    
    while (*end) {
        ++end;
    }
    
    --end;
    
    while (str < end) {
        temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
    
}