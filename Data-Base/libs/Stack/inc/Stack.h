/**
 * @headerfile Stack.h
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) Wx Software 2022
 * 
 */

/** @def Excute the head only one time */
#pragma once

/* 
--------------------------------------------------------------------------------------------------
!-                                     LIBRARIES INCLUDED                                        -
--------------------------------------------------------------------------------------------------
*/

#include "..\..\..\Assets\inc\ErrorHandler.h"
#include "..\..\..\Assets\inc\STDLIBs.h"
#include "..\..\Linkedlists\inc\Linkedlists.h"

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

/** 
 * @brief Struct for Stack.
 *
*/
#pragma pack(1) /** @note packing set to 1 byte*/
struct Stack
{
    /** @defgroup Stack aramaters */
    struct dllNode *Top;
    struct dllNode *Btm;
    uint32_t StackSize;
};

/* 
--------------------------------------------------------------------------------------------------
!-                                     FUNCTIONS IMPLEMENTATION                                  -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
struct Stack *Stack_Create(void);
void Stack_Destroy(struct Stack *); /** @todo IMPLEMENT */

/** @defgroup insertion functions */
error_type Stack_Push(struct Stack *, struct PersonData *);
struct PersonData *Stack_Pop(struct Stack *);
 
/** @defgroup sub functions */
static struct dllNode *Stack_Front(struct Stack *);
static error_type Stack_IsEmpty(struct Stack *);
static uint32_t Stack_Size(struct Stack *);
static error_type Stack_Validity(struct Stack *);


