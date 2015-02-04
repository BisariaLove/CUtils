//
//  check_rotation.c
//  
//
//  Created by Love Bisaria on 2/2/15.
//
//

#include <stdio.h>
#include <string.h>
int is_rotation(char *s1, char *s2);

int main(){
    char s1[100] = "waterbottle";
    char s2[50] = "erbottlewat";
    
    int retval = is_rotation(s1, s2);
    if(retval == 1){
        printf("Strings are Rotated\n");
    }
    else{
        printf("Strings are not rotated\n");
    }
    
    return 0;
    
}

int is_rotation(char *s1, char *s2){
    
    int len = strlen(s1);
    char *c = NULL;
    
    char temp[100]  = "\0";
    strcpy(temp, s1);
   
    if((0 != len)&& (len == strlen(s2))){
        
        strcat(temp, s1);
        
        c = strstr(temp, s2);
        
        if(NULL != c){
            return 1;
        }
    }
    
    return -1;
    
}
