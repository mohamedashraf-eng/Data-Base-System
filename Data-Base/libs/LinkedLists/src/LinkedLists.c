/**
 * @file LinkedLists.c
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) Wx Belkasy Software 2022
 * 
 */

/* 
--------------------------------------------------------------------------------------------------
!-                                     LIBRARIES INCLUDED                                        -
--------------------------------------------------------------------------------------------------
*/

#include "../inc/LinkedLists.h"

/* 
--------------------------------------------------------------------------------------------------
!-                                     MACROS DECLARED                                           -
--------------------------------------------------------------------------------------------------
*/



/* 
--------------------------------------------------------------------------------------------------
!-                                     GLOBAL VARIABLES DECLARED                                 -
--------------------------------------------------------------------------------------------------
*/


/* 
--------------------------------------------------------------------------------------------------
!-                                     STRUCTS DECLARED                                          -
--------------------------------------------------------------------------------------------------
*/


/* 
--------------------------------------------------------------------------------------------------
!-                                     FUNCTIONS IMPLEMENTATION                                  -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
/**
 * @brief  Functino to create double linked list.
 * @param  PersonData*   (Data to be added to the new node)
 * @return Base address of the first node (Pointer to struct)
*/
struct dllNode *dllNode_Create(struct PersonData *Data)
{
    /* Create new node of type struct in heap */
    struct dllNode *dllNodeNew = (struct dllNode *) malloc(sizeof(struct dllNode));

    /* Check the malloc validity */
    dma_validity(dllNodeNew);
    dma_validity(Data);

    /* Initalize the node parameters */
    dllNodeNew->dllNodeNext = NULL;
    dllNodeNew->dllNodePrev = NULL;
    dllNodeNew->personData  = Data;
    
    /* Return the created node address */
    return dllNodeNew;

} /** @end dllNode_Create */

/** @defgroup insertion functions */
/**
 * @brief Function to insert at last of list.
 * @param PersonData*   (Data to be added to the new node)
 * @param dllNode*      (Head of the list)
 * @return error_type   (Reutrning an error code)
*/
error_type dllNode_Append(struct dllNode **dllNodeHead, struct PersonData *Data)
{
    /* Checking the passed list's head */
    /* Make sure the list isn't empty */
    if( !(dllNode_validity(*dllNodeHead)) )
    {
        /* Error Handler Function */
        /** @todo TO BE CHANGED */
        exit(-1);  /* Exit For Now */
    }
    else; /* Keep going (Do Nothing) */

    /* Check the data if valid */
    dma_validity(Data);

    /* Allocting memory for the new node*/
    struct dllNode *dllNodeNew = dllNode_Create(Data);

    /* Link the nodes */
    struct dllNode *dllNodeTemp = *dllNodeHead; /* Reducing redability complexity */

    while( (dllNodeTemp->dllNodeNext != NULL) ) /* Iterate till the last node */
    {
        dllNodeTemp = dllNodeTemp->dllNodeNext;
    }
    
    /* Link the new node with the old last node */ 
    dllNodeTemp->dllNodeNext = dllNodeNew;  // NextPtr => NextNode.
    dllNodeNew->dllNodePrev  = dllNodeTemp; // PrevPtr => PrevNode.

    /* Return RET_CODE */
    return 1;  /** @todo ADD ERROR_CODE */
}/** @end dllNode_Append */

/**
 * @brief Function to insert at start of list.
 * @param PersonData*   (Data to be added to the new node)
 * @param dllNode*      (Head of the list)
 * @return error_type   (Reutrning an error code)
*/
error_type dllNode_Push(struct dllNode **dllNodeHead, struct PersonData *Data)
{
    /* Checking the passed list's head */
    /* Make sure the list isn't empty */
    if( !(dllNode_validity(*dllNodeHead)) )
    {
        /* Error Handler Function */
        /** @todo TO BE CHANGED */
        exit(-1);  /* Exit For Now */
    }
    else; /* Keep going (Do Nothing) */

    /* Check the data if valid */
    dma_validity(Data); /** @note TO BE CHANGED */

    /* Allocting memory for the new node*/
    struct dllNode *dllNodeNew = dllNode_Create(Data);
    
    /* Link the new node with the list */
    dllNodeNew->dllNodeNext = (*dllNodeHead); // New Node point the previous first node.
    
    (*dllNodeHead)->dllNodePrev = dllNodeNew; // Previous first node point the new first node (The new Node)

    (*dllNodeHead) = dllNodeNew; // Make the new node as new head node.

    /* Return RET_CODE */
    return 1;  /** @todo ADD ERROR_CODE */
}/** @end dllNode_Push */


/** @defgroup private functions */
/**
 * @brief Function to check the validity of passed pointer
 * @param dllNode_pointer.
 * @return error_type indicates the state.
*/
 static error_type dllNode_validity(void *dllNode_pointer)
 {
    /* Check the pointer */
    if( (dllNode_pointer == NULL) )
    {
        /** @todo TO BE CHANGED */
        /* For now */
        /* Return specific ERROR_CODE*/
        return 0; /** @todo ADD ERROR_CODE */
        
    }
    else
    {
        return 1; /** @todo ADD ERROR_CODE */
    }
 } /** @end dllNode_validity */