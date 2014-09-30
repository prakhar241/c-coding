/* 
 * File:   bsearch.h
 * Author: prakbans
 *
 * Created on September 21, 2014, 2:14 PM
 */

#ifndef BSEARCH_H
#define	BSEARCH_H


#ifdef	__cplusplus
extern "C" {
#endif
#include<stddef.h>
    
    void *binarySearch(const void *key, const void *base, size_t num, size_t size,
            int (*cmp)(const void *key, const void *elt));


#ifdef	__cplusplus
}
#endif

#endif	/* BSEARCH_H */

