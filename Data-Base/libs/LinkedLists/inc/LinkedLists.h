/**
 * @headerfile LinkedLists.h
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) Wx Belkasy Software 2022
 * 
 */

/** @def Excute the head only one time */
#pragma once

/* 
--------------------------------------------------------------------------------------------------
!-                                     LIBRARIES INCLUDED                                        -
--------------------------------------------------------------------------------------------------
*/

#include "..\..\..\inc\Global.h"
#include "..\inc\Person.h"
#include "..\..\inc\ErrorHandler.h"

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
 * @brief Doubly Linked List Node Main Parameters 
 *
*/
#pragma pack(1) /** @note packing set to 1 byte*/
struct dllNode
{
    /** @defgroup Data */
    struct PersonData *personData;

    /** @defgroup Node Variables */
    struct dllNode *dllNodeNext;
    struct dllNode *dllNodePrev;
};

/* 
--------------------------------------------------------------------------------------------------
!-                                     FUNCTIONS DECLARATION                                     -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
struct dllNode *dllNode_Create(struct PersonData *);

/** @defgroup insertion functions */
error_type dllNode_Append(struct dllNode **, struct PersonData *);
error_type dllNode_Push(struct dllNode **, struct PersonData *);

/** @defgroup private functions */
static error_type dllNode_validity(void *);
static error_type dll_Print(struct dllNode *);