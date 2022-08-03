/**
 * @file Stack.c
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) Wx Software 2022
 * 
 */

/* 
--------------------------------------------------------------------------------------------------
!-                                     LIBRARIES INCLUDED                                        -
--------------------------------------------------------------------------------------------------
*/

#include "../inc/Stack.h"

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

/** @defgroup main functuions */
/**
 * @brief Function to create Stack
 * @param void
 * @return Stack struct
*/
struct Stack *Stack_Create(void)
{
    /* Create the heap memory for the Stack struct */
    struct Stack *NewStack = (struct Stack *) malloc(sizeof(struct Stack));
    /** @todo ADD DMA VALIDITY */

    /* Initalize Stack parameters */
    NewStack->Top = NULL;
    NewStack->Btm = NULL;
    NewStack->StackSize = 0;

    /* Return the new Stack*/
    return NewStack;
}/** @end Stack_Create*/

/**
 * @brief Function to create Stack
 * @param void
 * @return void
*/
void Stack_Destroy(struct Stack *Stack)
{
    /** @todo IMPLEMENT */

} /** @end Stack_Destroy*/

/** @defgroup insertion functions */
/**
 * @brief Function
 * @param Stack struct
 * @param Data struct
 * @return error_type
*/
error_type Stack_Push(struct Stack *Stack, struct PersonData *data)
{
    /* Error handling */
    if( !(Stack_Validity) )
    {
        /* RET_TYPE */
        exit(-1); /** @todo ADD ERROR_CODE */
    }   
    else;

    /* Check the data if valid or not */
    dma_validity(data);

    /* Check wether the Stack is empty or not */
    if ( (Stack_IsEmpty) ) /* If Stack is empty*/
    {
        /* Create new node */
        struct dllNode *dllNodeNew = dllNode_Create(data);
        Stack->Top = dllNodeNew;
        Stack->Btm  = dllNodeNew;
        Stack->StackSize += 1;

        /* RET_TYPE */
        return 1; /** @todo ADD ERROR_CODE */
    }    
    else     /* If Stack isn't empty */
    {
        /* Create new node */
        struct dllNode *dllNodeNew = dllNode_Create(data);

        /* O(1) Inserting */
        Stack->Top->dllNodeNext = dllNodeNew; // Let the init node point to the new node as next.
        dllNodeNew->dllNodePrev = Stack->Top; // Let the new node prev node as its previous.
        Stack->Top = dllNodeNew; // Let the top be the latest element.

        Stack->StackSize += 1;

        /* RET_TYPE */
        return 1; /** @todo ADD ERROR_CODE */
    }    
}/** @end Stack_enStack */


/**
 * @brief Function
 * @param Stack
 * @return error_type
*/
struct PersonData *Stack_Pop(struct Stack *Stack)
{
    /* Error handling */
    if( !(Stack_Validity) )
    {
        /* RET_TYPE */
        exit(-1); /** @todo ADD ERROR_CODE */
    }   
    else;

    /* Check wether the Stack is empty or not */
    if ( (Stack_IsEmpty) ) /* If Stack is empty*/
    {
        /* RET_TYPE */
        return 0; /** @todo ADD ERROR_CODE */
    }    
    else     /* If Stack isn't empty */
    {
        /* Temp variable to store the current Top */
        struct dllNode *temp = Stack->Top; 
        
        /* Move the Top to the next node */
        Stack->Top = Stack->Top->dllNodePrev;

        /* Check if the Stack is now empty */
        if( (Stack == NULL) )
        {
            /* Set the Btm to NULL */
            Stack->Btm = NULL;
        }

        /* Temporary storage for the current top person data */
        struct PersonData *pData = Stack->Top->personData; /** @todo to be changed */
        
        /* Free the previous top node */
        free(temp);

        Stack->StackSize -= 1; /* Decrease size by one */

        /* RET_TYPE */
        return pData; /** @todo ADD ERROR_CODE */
    }  
}/** @end Stack_deStack */

/** @defgroup sub functions */
/**
 * @brief Function to get the Top of the Stack
 * @param Stack struct
 * @return Stack Top node address
*/
static struct dllNode *Stack_Top(struct Stack *Stack)
{
    Stack_Validity(Stack);

    return (Stack->Top);
}/** @end Stack_Top*/

/**
 * @brief Function to check wether Stack is empty or not.
 * @param Stack struct
 * @return Stack size
*/
static uint32_t Stack_Size(struct Stack *Stack)
{
    if( (Stack_IsEmpty(Stack)) )
    {
        return 0;
    }
    else
    {
        return (Stack->StackSize);
    }

}/** @end Stack_IsEmpty */

/**
 * @brief Function to check wether Stack is empty or not.
 * @param Stack struct
 * @return boolean value. 
*/
static error_type Stack_IsEmpty(struct Stack *Stack)
{
    if( (Stack == NULL) )
    {
        /* RET_TYPE */
        return 0; /** @todo ADD ERROR_CODE */
    }
    else
    {
        return 1; /** @todo ADD ERROR_CODE */
    }
}/** @end Stack_IsEmpty */

/**
 * @brief Function to check Validity of the Stack.
 * @param Stack struct
 * @return error_type
*/
static error_type Stack_Validity(struct Stack *Stack)
{
        if( (Stack == NULL) )
    {
        /* RET_TYPE */
        return 0; /** @todo ADD ERROR_CODE */
    }
    else
    {
        return 1; /** @todo ADD ERROR_CODE */
    }
}/** @end Stack_Validity */