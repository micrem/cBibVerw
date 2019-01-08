#include "BuchLib.h"

Buch* newEmptyBuch(){
    Buch * newBuch = malloc(sizeof(Buch));
    strcpy(newBuch->Buchtitel, "");
    strcpy(newBuch->Buchautor, "");
    newBuch->ISBN=0;
    newBuch->AnzahlExemplare=0;
    newBuch->ListeAusleiher.length=0;
    newBuch->ListeAusleiher.first=NULL;
}

Bibliothek* newEmptyBibliothek(){
    Bibliothek * newBibliothek = malloc(sizeof(Bibliothek));
    newBibliothek->BuecherListe.first=NULL;
    newBibliothek->BuecherListe.length=0;
}

Ausleiher* newEmptyAusleiher(){
    Ausleiher * newAusleiher = malloc(sizeof(Ausleiher));
    strcpy(newAusleiher->name, "");
    return newAusleiher;
}


int addBuch(Bibliothek* bibliothek, Buch* buch) {
    if (!buch || ! bibliothek) return -1;
    return addListItem(&(bibliothek->BuecherListe), buch);
}

int checkInBuch(Buch *buch, const char* ausleiherName) {
    if (!buch ) return -1;
    if (buch->AnzahlExemplare == 0 || buch->ListeAusleiher.length==0) return -1; //buch hat keine exemplare, man kann nichts zurueckgeben
    int ausleiherIndex = getAusleiherIndexByName(&(buch->ListeAusleiher),ausleiherName);
    if (ausleiherIndex<0) {printf("checkInBuch: BIBL_ERROR got index<0 by 'getAusleiherIndexByName'"); return -1;}
    Ausleiher* ptrAusleiherToRemove =  getListData(&(buch->ListeAusleiher), ausleiherIndex);
    free(ptrAusleiherToRemove);
    removeListItem(&(buch->ListeAusleiher),ausleiherIndex);
    return 0;
}

int checkOutBuch(Buch *buch, const char* ausleiherName) {
    if(!buch) return -1;
    if(buch->ListeAusleiher.length == buch->AnzahlExemplare) return 1;
    Ausleiher* new_ausleiher = newEmptyAusleiher();
    strncpy(new_ausleiher->name, ausleiherName, MAXSTRINGSIZE);
    new_ausleiher->name[MAXSTRINGSIZE-1]='\0';
    addListItem(&(buch->ListeAusleiher), new_ausleiher);
    return 0;
}

int printBuch(Buch *buch) {
    if (!buch ) return -1;
    printf("Titel: '%s'\n", buch->Buchtitel);
    printf("Autor: '%s'\n", buch->Buchautor);
    printf("ISBN: %lld\n", buch->ISBN);
    printf("Exemplare: %d\n", buch->AnzahlExemplare);
    printf("Ausleiher:\n");
    for (int i=0; i<buch->ListeAusleiher.length; i++){
        printf("\t%s\n",getListData(&(buch->ListeAusleiher),i ));
    }
    printf("\n");
    return 0;
}

int printBibliothek(Bibliothek *bibliothek) {
    if (!bibliothek ) return -1;
    for (int i=0; i<bibliothek->BuecherListe.length; i++){
        printBuch(getListData(&(bibliothek->BuecherListe),i));
    }
    return 0;
}

int getAusleiherIndexByName(LinkedList* ListeAusleiher, const char* ausleiherName){
    for (int i=0; i<ListeAusleiher->length; i++){
        if (!strcmp(getListData(ListeAusleiher,i),ausleiherName)) return i;
    }
    return -1;
}

//!ErrorHasOccured() ??!??! HandleError();