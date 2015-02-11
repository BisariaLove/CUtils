//
//  graycode.c
//  
//
//  Created by Love Bisaria on 2/2/15.
//
//

#include <stdio.h>
int gray_code(int byte1, int byte2);

int main(){
    int n1, n2;
    printf("enter the numbers\n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    int retval = gray_code(n1, n2);
    
    if(retval == 1){
        printf("Bytes are gray code\n");
    }
    else{
        printf("Bytes are not gray code\n");
    }
}

int gray_code(int byte1, int byte2){
    
    int k = byte1^byte2;
    
    int and = k&(k-1);
    
    if(and == 0){
        
        return 1;
    }
    return 0;
}