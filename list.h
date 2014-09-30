/* 
 * File:   list.h
 * Author: prakbans
 *
 * Created on September 21, 2014, 10:39 AM
 */

#ifndef LIST_H
#define	LIST_H

#ifdef	__cplusplus
extern "C" {
#endif

    // a common function used to free malloc'd objects
    typedef void (*freeFunction)(void *);

    typedef enum {
        FALSE, TRUE
    } boolean;
    
    typedef boolean(*listIterator)(void *);

    typedef struct _listNode {
        void *data;
        struct _listNode *next;
    } listNode;

    typedef struct {
        int logicalLength;
        int elementSize;
        listNode *head;
        listNode *tail;
        freeFunction freeFn;
    } list;
    
    void list_new(list *list, int elementSize, freeFunction freeFn);
    void list_destroy(list *list);
    void list_prepend(list *list, void *element);
    void list_append(list *list, void *element);
    int list_size(list *list);
    void list_for_each(list *list, listIterator iterator);
    void list_head(list *list, void *element, boolean removeFromList);
    void list_tail(list *list, void *element);

#ifdef	__cplusplus
}
#endif

#endif	/* LIST_H */

