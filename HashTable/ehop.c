/*
 * ehop.c
 *
 *
 * Created by Love Bisaria on 2/20/15.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Hashtable Implementation in c
 */

#include "uthash.h"

/* 
 * Structure to be stored as Value in Key:Value pair. 
 */

typedef struct my_struct{
    unsigned int id;
    char header_name[1024];
    unsigned int count;
    UT_hash_handle hh;
}Hash_Entry;

Hash_Entry *hash_table = NULL;

/* 
 * Robert Sedgewick's algorithm to calulate hash for a given string 
 */

unsigned int generate_hash(char* str, unsigned int len){
    unsigned int result = 0;
    unsigned int b      = 378551;
    unsigned int a      = 63689;
    unsigned int i      = 0;
    
    for(i=0 ; i<len ; str++, i++){
        result = result*a + (*str);
        a = a*b;
    }
    
    return result;
}

/*
 * Function update_entry(...), updates the entries in HashTable
 * using the following rules:
 * it searches for new_id(hash for the new string)
 * a) if found, it increments the count variable by one.
 * b) if not found, it creates a new entry in the hash table
 *    with the id as new_id, header_name as the new sring 
 *    and count as one.
 */

void update_entry(unsigned int new_id, char *name, unsigned int count){
    Hash_Entry *entry;
    
    HASH_FIND_INT(hash_table, &new_id, entry);
    if(NULL == entry){
        entry = (Hash_Entry*) malloc (sizeof(Hash_Entry));
        entry->id = new_id;
        strcpy(entry->header_name, name);
        entry->count = 1;
        HASH_ADD_INT( hash_table, id, entry );
    }else{
        entry->count = entry->count+1;
    }
    
}

/*
 * The function print_table() function prints the values of the complete
 *  HashTable in the order they wer entered.
 */

void print_table(){
    Hash_Entry *entry = hash_table;
    for( ; entry != NULL ; entry = (Hash_Entry*)entry->hh.next){
        fprintf(stdout, "%s: %u\n", entry->header_name, entry->count);
    }
}

/*
 * The function print_headers(...) takes as input the h_name
 * and prints the count for the header name.
 * If the passed argument is not present in the HashTable,
 * an error message is displayed.
 */

void print_headers(char *h_name){
    
    Hash_Entry *entry;
    unsigned int new_id = generate_hash(h_name, strlen(h_name));
    
    HASH_FIND_INT(hash_table, &new_id, entry);
    if(entry != NULL){
        fprintf(stdout, "%s: %d\n", entry->header_name, entry->count);
    }else{
        fprintf(stderr, "Header Value not found..!!\n");
        
    }
    
}

/*
 * The main() function, does the following:
 * a) reads from file(I have given the file name as sample.txt).
 * b) extracts the header name from each line of the file.
 * c) calls update_entry(...) for each entry.
 * d) Asks the user to input the names of header
 *    for which they want the count.
 * e) calls print_headers(...) to print the count.
 */

int main(){
    FILE *fp;
    char str[60], h_name[1024];
    char *token = NULL;
    
    int count, i;
    
    fp = fopen("sample.txt" , "r");
    if(fp == NULL) {
        perror("Error opening file"
               );
        return(-1);
    }
    while( fgets (str, 1024, fp)!=NULL ) {
        token = strtok(str, ":");
        update_entry(generate_hash(token, strlen(token)), token, 1);
    }
    
    
    fprintf(stdout, "Printing the headers:-\n");
    
    //print_table();
    
    fprintf(stdout, "Please enter the count of headers to be printed:\n");
    fscanf(stdin, "%u", &count);
     
    for (i=0 ; i<count ; i++) {
        fscanf(stdin, "%s", h_name);
        print_headers(h_name);
    }

    
    return 0;
}
