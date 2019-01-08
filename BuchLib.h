#ifndef BUCH_H_INCLUDED
#define BUCH_H_INCLUDED

#include <string.h>

#include "menuHandling.h"
#include "LinkedList.h"
#include "BuchLibSettings.h"

typedef struct Buch Buch;

typedef struct Bibliothek Bibliothek;

typedef struct Ausleiher Ausleiher;


struct Bibliothek {
    LinkedList BuecherListe;
};

struct Ausleiher {
    char name[MAXSTRINGSIZE];
};

struct Buch {
    long long ISBN;
    char Buchtitel[MAXSTRINGSIZE];
    char Buchautor[MAXSTRINGSIZE];
    int AnzahlExemplare;
    LinkedList ListeAusleiher;
};


int addBuch(Bibliothek* bibliothek, Buch* buch);
int checkInBuch(Buch *buch, const char* ausleiherName);
int checkOutBuch(Buch *buch, const char* ausleiherName);

int printBuch(Buch* buch);
int printBibliothek(Bibliothek* bibliothek);

int getAusleiherIndexByName(LinkedList* ListeAusleiher, const char* ausleiherName);

Buch* newEmptyBuch();
Bibliothek* newEmptyBibliothek();
Ausleiher* newEmptyAusleiher();

//findBuch?

#endif // BUCH_H_INCLUDED
