//
//  string_compress.c
//  CTCI - Question - 1.5
//
//  Created by Love Bisaria on 12/19/14.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void compressBad(char *str , char *newStr);

int main(){
    
    char str[300]  , newStr[300];
    
    printf("Enter the String..!!\n");
    scanf("%s" , str);
    
    compressBad(str , newStr);
    
    printf("New String is:__%s__\n" , newStr);
    
    return 0 ;
}

void compressBad(char *str , char *newStr){
    
    int k =0;
    
    char last = *str ;
    int count = 1;
    char cnt[300];
    
    for (int  i=1 ; i<strlen(str); i++) {

        if( *(str+i) == last ){
            count++ ;
            
        }else{
            
            *(newStr + (k)) = last;
            cnt
            //*(newStr + (k+1)) = cnt;
            k += 2;
           
            last = *(str+i);
            count = 1;
        }
    }
    
}