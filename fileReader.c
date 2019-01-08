//
// Created by user64 on 02/01/2019.
//

#include "fileReader.h"

int example () {
    FILE *fp;
    char str[60];

    /* opening file for reading */
    fp = fopen("file.txt" , "r");
    if(fp == NULL) {
        perror("Error opening file");
        return(-1);
    }
    if( fgets (str, 60, fp)!=NULL ) {
        /* writing content to stdout */
        puts(str);
    }
    fclose(fp);

    return(0);
}