#include "LinkedList.h"


//interne Hilfsfunktionen
LLNode *getListLastNode(LinkedList *list) {
    if (!list) return NULL;
    LLNode *runner = list->first;
    while (runner->next != NULL) {
        runner = runner->next;
    }
    return runner;
}

LLNode *getListNode(LinkedList *list, int index) {
    LLNode *runner = list->first;
    int i = 0;
    if (index + 1 > list->length || index < 0 || list == NULL) {
        return NULL;
    }
    for (i = 0; i < index; i++) {
        runner = runner->next;
    }
    if(LLIST_DEBUG_MODE>1) printf("getListNode returned index %d\n", i);
    return runner;
}

LLNode * newEmptyNode(){
    LLNode *new_node;
    new_node = malloc(sizeof(LLNode));
    new_node->data = NULL;
    new_node->next = NULL;
}



int addListItem(LinkedList *list, void *data) {
    if(LLIST_DEBUG_MODE>1) printf("addListItem on enter: length: %d\n", list->length);
    LLNode *new_node;
    LLNode *old_node;

    if (data == NULL || list == NULL) {
        if(LLIST_DEBUG_MODE>1) printf("addListItem:(data == NULL || list == NULL) \n");
        return -1;
    } else {
        new_node = newEmptyNode();
        new_node->data = data;


        if (list->first == NULL) {
            list->first = new_node;
        } else {
            old_node = getListLastNode(list);
            if(old_node) {
                old_node->next = new_node;
            } else {
                if(LLIST_DEBUG_MODE) printf("addListItem: unrecoverable error, list inconsistency\n");
                return -2;
            }
        }
        list->length += 1;
        if(LLIST_DEBUG_MODE>1) printf("addListItem item, new length: %d\n", list->length);
        return 0;
    }
}

int removeListItem(LinkedList *list, int index) {
    LLNode *node_to_delete, *previous, *following;
    node_to_delete = previous = following = NULL;

    if (index + 1 > list->length || index < 0 || list == NULL || list->length == 0) {
        if(LLIST_DEBUG_MODE) printf("removeListItem Error (index + 1 > list->length || index < 0 || list == NULL || list->length == 0)\n");
        return -1;
    }
    node_to_delete = getListNode(list, index);
    previous = getListNode(list, index - 1); //liefert NULL falls index==0 (hiesse header wird geloescht)
    following = node_to_delete->next;

    //free(node_to_delete->data); //liste legt daten nicht an, sollte nich free'n
    free(node_to_delete);
    if (previous) previous->next = following; //falls previous existiert (header zB hat keinen); klappt auch fuer following == NULL (beim letzten)
    if (index==0) list->first = following; //listen-eintrag fuer erstes element korrigieren falls geloescht
    list->length -= 1;
    return 0;
}

/* int getListLength(LinkedList* list){
 *     return list->length;
 * }
 */

void *getListData(LinkedList *list, int index) {
    LLNode* node = getListNode(list, index);
    if(node==NULL) return NULL; //falls node leer ist, kann nicht auf node->data zugreifen
    return node->data;
}

