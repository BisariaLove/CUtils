//
//  check_vowels.c
//  
//
//  Created by Love Bisaria on 2/2/15.
//
//

#include <stdio.h>
#include <string.h>
int count_vowel(char *str);

int main(){
    
    char str[1024] = "\0";
    printf("Enter the String\n");
    fgets(str,1024,stdin);
    int count = count_vowel(str);
    printf("Total Vowel count: %d\n",count);
    
    return 0;
}

int count_vowel(char *str){
    int len = strlen(str), count = 0;
    
    for (int i=0; i<len ; i++) {
        
        switch(str[i]){
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U': count++;
                      printf("The string contains: %c\n",str[i]);
                      break;
        }
        
    }
    
    return count;
    
}