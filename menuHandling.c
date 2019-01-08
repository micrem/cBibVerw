//
// Created by user64 on 23/12/2018.
//

#include "menuHandling.h"
#include <stdint.h>

int readLine (char *buf, char *inputText) {
    int charBuffer;
    if (inputText != NULL)
        printf ("%s", inputText); //Text Eingabeaufforderung

    //liesst maximal MAXSTRINGSIZE-1 chars ein (inklusive '\n') und terminiert Buffer mit '\0'
    //(also MAXSTRINGSIZE-2 verwertbare chars)
    if (fgets(buf, MAXSTRINGSIZE, stdin) == NULL)
        return BIBL_ERROR; //keine Eingabe

    // Falls Eingabe zu lang (=vorletztes Zeichen nicht '\n'), Eingabebuffer leeren
    if (buf[strlen(buf)-1] != '\n') {
        while (((charBuffer = getchar()) != '\n') && (charBuffer != EOF)){}
        //return BIBL_ERROR;
    }

    // String zur Sicherheit abschliessen
    buf[strlen(buf)-1] = '\0';
    return BIBL_SUCCESS;
}


int readInputString(char *buffer, char *inputText) {
    if (buffer==NULL) return BIBL_ERROR;
    //sscanf(" %[^\n]s", buffer);
    if (DEBUG_MODE) printf("\n(eingabe:%s)", buffer);
    return BIBL_SUCCESS;
}

int readInputInteger(int *intPtr, char *inputText) {
    long int tempInput;
    if (intPtr==NULL) return BIBL_ERROR;
    char buffer[FILENAME_MAX];
    readLine(buffer, *inputText);
    strtol(buffer, "%d", &tempInput);
    if (tempInput>INT32_MAX || tempInput < INT32_MIN)
        return BIBL_ERROR;
    if (DEBUG_MODE)
        printf("\n(eingabe:%ld)", tempInput);
    return BIBL_SUCCESS;
}


int readInputLong( long long* longlongPtr, char *inputText) {
    char buffer[FILENAME_MAX];
    long long tempInput;
    strtoll("%lld",longlongPtr);
    tempInput = strtoll(buffer, NULL, 10);
    if (DEBUG_MODE) printf("\n(eingabe:%lld)", tempInput);
    return BIBL_SUCCESS;
}


/*
//VERALTET
int readLineSafe(char *buffer){
    //FUNKTIONIERT NICHT wie erwartet
    int inputChar;
    int i=0;
    for (i=0;i<MAXSTRINGSIZE;i++) buffer[i]='\0'; //explizite Initialisierung
    //char buffer[MAXSTRINGSIZE]='\0';
    //32 - 126: gueltige ASCII-Schriftzeichen
    printf(">");
    i=1; //Counter gibt Stelle an (nicht Index)
    inputChar = getc(stdin);

    while( inputChar!='\n' && inputChar!=EOF && i<MAXSTRINGSIZE ) //letztes Zeichen im buffer bleibt '\0' (bzw. 0)
    {
        if ((char)inputChar>=32 && (char)inputChar<=126) {
            buffer[i-1]=(char) inputChar;
        }
        else{
            printf("\nungueltiges Zeichen (ASCII-Dezimalwert:%d), bitte Eingabe wiederholen:\n%s",inputChar, buffer);
        }
        if (DEBUG_MODE>1) printf("%c", inputChar);
        inputChar = getc(stdin);
        i++;
    }

    return BIBL_SUCCESS;
}
 */