//
// Created by user64 on 23/12/2018.
//

#ifndef MENUHANDLING_H_INCLUDED
#define MENUHANDLING_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BuchLibSettings.h"

int readInputString(char *buffer, char *inputText);
int readInputLong( long long* longlongPtr, char *inputText);
int readInputInteger(int *intPtr, char *inputText);
int readLine ( char *buf, char *inputText);

#endif //MENUHANDLING_H_INCLUDED
