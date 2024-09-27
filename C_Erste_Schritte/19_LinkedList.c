// =====================================================================================
// LinkedList.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

// ===========================================================================================
// Includes

#include <stdio.h>
#include <stdlib.h>  // malloc, free
#include <crtdbg.h>

// =====================================================================================
// Types

// rekursive Definition
struct ListItem
{
    int              m_value;
    struct ListItem* m_next;   // Adresse: 4/8 Bytes // "rekursiv"
};

struct LinkedList
{
    struct ListItem* m_root;  
    size_t           m_count;
};

// =====================================================================================
// Function Prototypes

void    addHead(struct LinkedList* list, int value);
void    addHeadEx(struct LinkedList* list, int value);

void    addTail(struct LinkedList* list, int value);

int     insert(struct LinkedList* list, int value, size_t pos);

int     contains(struct LinkedList* list, int value);
int     removeAt(struct LinkedList* list, size_t pos);
void    concat(struct LinkedList* list1, struct LinkedList* list2);
void    freeListfreeList(struct LinkedList* list);
void    freeListEx(struct LinkedList* list);
void    freeListRecursive(struct ListItem* item);
void    printList(struct LinkedList* list);
void    printItem(struct ListItem* item);
size_t  size(struct LinkedList* list);
int     isEmpty(struct LinkedList* list);

// =====================================================================================
// Implementation

static size_t size(struct LinkedList* list) {
    return list->m_count;
}

static int isEmpty(struct LinkedList* list) {
    return (list->m_count == 0) ? 1 : 0;
}

static void addHead(struct LinkedList* list, int value)
{
    // create a new node
    struct ListItem* item = (struct ListItem*)malloc(sizeof(struct ListItem));
    if (item == (struct ListItem*)0) {
        return;
    }

    item->m_value = value;
    item->m_next = (struct ListItem*)0;

    if (list->m_root == (struct ListItem*)0)
    {
        list->m_root = item;
    }
    else
    {
        item->m_next = list->m_root;
        list->m_root = item;
    }

    list->m_count++;
}

static void addHeadEx(struct LinkedList* list, int value)
{
    // create a new node
    struct ListItem* item = (struct ListItem*)malloc(sizeof(struct ListItem));
    if (item == (struct ListItem*)0) {
        return;
    }

    // setup node
    item->m_value = value;
    item->m_next = list->m_root;

    // update list
    list->m_root = item;
    list->m_count++;
}

static void addTail(struct LinkedList* list, int value)
{
    // create a new node
    struct ListItem* item = (struct ListItem*)malloc(sizeof(struct ListItem));
    if (item == (struct ListItem*)0) {
        return;
    }

    item->m_value = value;
    item->m_next = (struct ListItem*)0;

    if (list->m_root == (struct ListItem*)0)
    {
        list->m_root = item;
    }
    else
    {
        // search end of list
        struct ListItem* last = list->m_root;
        while (last->m_next != (struct ListItem*)0) {
            last = last->m_next;
        }

        // append node
        last->m_next = item;
    }

    list->m_count++;
}

static int insert(struct LinkedList* list, int value, size_t pos)
{
    // verify params
    if (pos > list->m_count) {
        return 0;
    }

    // create a new node
    struct ListItem* item = (struct ListItem*)malloc(sizeof(struct ListItem));
    if (item == (struct ListItem*)0) {
        return 0;
    }

    item->m_value = value;

    if (pos == 0)
    {
        item->m_next = list->m_root;
        list->m_root = item;
    }
    else // pos >= 1
    {
        struct ListItem* current = list->m_root;
        while (pos - 1 != 0)
        {
            current = current->m_next;
            pos--;
        }

        item->m_next = current->m_next;
        current->m_next = item;
    }

    list->m_count++;
    return 1;
}

int contains(struct LinkedList* list, int value)
{
    struct ListItem* item = list->m_root;

    while (item != (struct ListItem*)0)
    {
        if (item->m_value == value) {
            return 1;
        }

        item = item->m_next;
    }

    return 0;
}

int  removeAt(struct LinkedList* list, size_t pos)
{
    // verify params
    if (list->m_count == 0 || pos >= list->m_count) {
        return 0;
    }

    if (pos == 0)
    {
        struct ListItem* tmp = list->m_root;
        list->m_root = list->m_root->m_next;
        free(tmp);
    }
    else // pos >= 1
    {
        struct ListItem* current = list->m_root;
        struct ListItem* prev = NULL;

        while (pos != 0)
        {
            prev = current;
            current = current->m_next;
            pos--;
        }

        // 'current' has to be removed,
        // connect previous and following nodes
        prev->m_next = current->m_next;
        free(current);
    }

    list->m_count--;
    return 1;
}

void concat(struct LinkedList* list1, struct LinkedList* list2)
{
    if (list1->m_root == (struct ListItem*)0) {
        // first list is empty
        list1->m_root = list2->m_root;

        // reset second list
        list2->m_root = (struct ListItem*)0;
        list2->m_count = 0;
    }
    else {
        // search end of first list
        struct ListItem* item = list1->m_root;
        struct ListItem* prev = NULL;

        while (item != (struct ListItem*)0)
        {
            prev = item;
            item = item->m_next;
        }

        // 'prev' points to last node of first list
        prev->m_next = list2->m_root;

        // adjust node counter of first list
        list1->m_count += list2->m_count;

        // reset second list
        list2->m_root = (struct ListItem*)0;
        list2->m_count = 0;
    }
}

void freeList(struct LinkedList* list) {

    struct ListItem* next = list->m_root;
    struct ListItem* prev;

    while (next != (struct ListItem*)0) {

        prev = next;
        next = next->m_next;
        free(prev);
    }
}

void freeListEx(struct LinkedList* list)
{
    struct ListItem* item = list->m_root;

    freeListRecursive(item);
}

void freeListRecursive(struct ListItem* item) {

    if (item->m_next != (struct ListItem*)0)
    {
        freeListRecursive(item->m_next);
    }

    free(item);
}

static void printItem(struct ListItem* item)
{
    printf("%d", item->m_value);
}

static void printList(struct LinkedList* list)
{
    struct ListItem* item = list->m_root;

    printf("[");

    while (item != (struct ListItem*)0)
    {
        if (item != list->m_root) {
            printf(",");
        }

        printItem(item);

        item = item->m_next;
    }

    printf("] (%zu elements)\n", list->m_count);
}

// =====================================================================================
// application

static void exercise_linked_list_01()
{
    // testing 'addHead' and 'addTail'

    struct LinkedList list = { (struct ListItem*)0, 0 };

    for (int i = 0; i < 5; i++) {
        addHead(&list, 2 * i);
    }
    printList(&list);

    for (int i = 0; i < 5; i++) {
        addTail(&list, 20 * i);
    }
    printList(&list);

    freeList(&list);
}

static void exercise_linked_list_02()
{
    // testing 'insert'

    struct LinkedList list = { (struct ListItem*)0, 0 };

    insert(&list, 3, 0);
    insert(&list, 2, 0);
    insert(&list, 1, 0);
    printList(&list);

    insert(&list, 4, 3);
    printList(&list);

    freeList(&list);
}

static void exercise_linked_list_03()
{
    // testing 'removeAt'

    struct LinkedList list = { (struct ListItem*)0, 0 };

    // test 'insert'
    insert(&list, 5, 0);
    insert(&list, 4, 0);
    insert(&list, 3, 0);
    insert(&list, 2, 0);
    insert(&list, 1, 0);
    printList(&list);

    removeAt(&list, 4);
    printList(&list);

    removeAt(&list, 3);
    printList(&list);

    removeAt(&list, 2);
    printList(&list);

    removeAt(&list, 1);
    printList(&list);

    removeAt(&list, 0);
    printList(&list);

    freeList(&list);
}

static void exercise_linked_list_04()
{
    // testing 'contains'

    struct LinkedList list = { (struct ListItem*)0, 0 };

    // test 'insert'
    insert(&list, 5, 0);
    insert(&list, 4, 0);
    insert(&list, 3, 0);
    insert(&list, 2, 0);
    insert(&list, 1, 0);
    printList(&list);

    for (int i = 0; i < 7; ++i) {
        printf("Contains %d:  %d\n", i, contains(&list, i));
    }

    freeList(&list);
}

static void exercise_linked_list_05()
{
    // testing 'size' and 'isEmpty'

    struct LinkedList list = { (struct ListItem*)0, 0 };

    for (int i = 0; i < 6; ++i) {

        printList(&list);

        printf("\nsize: %zu - isEmpty: %d\n", size(&list), isEmpty(&list));

        insert(&list, 5 - i, 0);
    }

    freeList(&list);
}

static void exercise_linked_list_06()
{
    // testing 'concat'

    struct LinkedList first = { (struct ListItem*)0, 0 };
    struct LinkedList second = { (struct ListItem*)0, 0 };

    concat(&first, &second);
    printList(&first);

    addTail(&first, 1);
    addTail(&second, 10);
    printList(&first);
    printList(&second);

    concat(&first, &second);
    printList(&first);
    printList(&second);

    addTail(&second, 20);
    addTail(&second, 21);
    addTail(&second, 22);

    concat(&first, &second);
    printList(&first);
    printList(&second);

    freeList(&first);
    freeList(&second);

}

void exercise_linked_list()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    exercise_linked_list_01();
    exercise_linked_list_02();
    exercise_linked_list_03();
    exercise_linked_list_04();
    exercise_linked_list_05();
    exercise_linked_list_06();
}

// =====================================================================================
// End-of-File
// =====================================================================================

//    void Reverse();                 // reverse list

//    // comparison operators
//    friend bool operator== (const LinkedList&, const LinkedList&);
//    friend bool operator!= (const LinkedList&, const LinkedList&);