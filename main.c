#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BuchLib.h"



int main() {

char buf[MAXSTRINGSIZE];

if (!readLine(buf,"Eingabe:"))
    printf(">%s",buf);


return 0;

Bibliothek* bib = newEmptyBibliothek();
Buch* buecher[3];
Ausleiher* ausl[3];

for(int i = 0;i<3; i++){
    buecher[i]=newEmptyBuch();
    ausl[i]=newEmptyAusleiher();
}

for(int i = 0;i<3; i++) {
    buecher[i]->ISBN=i*12345;
    sprintf(buecher[i]->Buchautor, "AutorNr%d!",i+1);
    sprintf(buecher[i]->Buchtitel, "TitelNr%d!",i+1);
    buecher[i]->AnzahlExemplare=1+i*2;
    addBuch(bib, buecher[i]);
}

printBibliothek(bib);

printf("checkOutBuch %d\n", checkOutBuch(getListData(&(bib->BuecherListe),1),"Salahaddin"));

printBuch(getListData(&(bib->BuecherListe),1));

printf("checkInBuch %d\n",checkInBuch( getListData(&(bib->BuecherListe),1),"Salahaddin"));

printBuch(getListData(&(bib->BuecherListe),1));

do {
    int input_menu;
    printf("\n1) buch hinzufuegen \n2) buch ausleihen \n3) buch zurueckgeben \n4) bibliothek ausdrucken\n5) beenden\n");
    printf("Bitte menupunkt auswaehlen: ");
    input_menu = readInputInteger(NULL);
    switch (input_menu){
        case 1:{
            Buch* newBuch = newEmptyBuch();
            char buffer[MAXSTRINGSIZE];
            printf("\nBitte Titel eingeben: ");
            readInputString(buffer);
            strcpy(newBuch->Buchtitel, buffer );
            printf("\nBitte Autor eingeben: ");
            readInputString(buffer);
            strcpy(newBuch->Buchautor, buffer);
            printf("\nBitte ISBN eingeben: ");
            newBuch->ISBN= readInputLong(0);
            printf("\nBitte Exemplaranzahl eingeben: ");
            newBuch->AnzahlExemplare= readInputInteger(NULL);
            printf(addBuch(bib, newBuch) ? "\nFehler beim Buch Anlegen!" : "Buch angelegt!\n");
            break;}
        case 2:{
            printf("\nBitte Buchindex zum Ausleihen eingeben: ");
            Buch* buch = getListData(&(bib->BuecherListe),(int) readInputInteger(NULL));
            printBuch(buch);
            printf("\nBitte Ausleihernamen eingeben: ");
            char buffer[MAXSTRINGSIZE];
            readInputString(buffer);
            printf(checkOutBuch( buch, buffer)?"\nFehler beim Ausleihen!": "Buch ausgeliehen!\n");}
            break;
        case 3:
        {   printf("\nBitte Buchindex zum Wiedergeben eingeben: ");
            Buch* buch = getListData(&(bib->BuecherListe),(int) readInputInteger(NULL));
            printBuch(buch);
            printf("\nBitte Ausleihernamen eingeben: ");
            char buffer[MAXSTRINGSIZE];
            readInputString(buffer);
            printf(checkInBuch( buch, buffer)?"\nFehler beim Wiedergeben!": "Buch wiedergegeben!\n");}
            break;
        case 4:
            printf("Bibliothek:\n");
            printBibliothek(bib);
            break;
        case 5:
            return 0;


        default:
            printf("Auswahl nicht erkannt\n");
            continue;
    }
} while ("false");


/*
    LinkedList list = {NULL, 0};
    LinkedList *listPtr = &list;

    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));
    *data1=11;
    *data2=22;
    *data3=33;

    printf("%d\n",sizeof(LLNode));

    printf("addListItem:%d\n",addListItem( listPtr, data1 ));
    printf("addListItem:%d\n",addListItem( listPtr, data2 ));
    printf("addListItem:%d\n",addListItem( listPtr, data3 ));
    printf("\n");

    for (int i=0; i< list.length;i++ ){
        printf("%d:%d\n",i,*(int*)getListData(listPtr,i));
    };
*/




    return 0;
}
