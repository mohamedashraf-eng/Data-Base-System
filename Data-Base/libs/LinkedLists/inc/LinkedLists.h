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
struct dllNode
{
    /** @defgroup Node Variables */

    struct dllNode *dllNodeNext;
    struct dllNode *dllNodePrev;

    /** @defgroup Data */

    struct PersonData *personData;
};

/* 
--------------------------------------------------------------------------------------------------
!-                                     FUNCTIONS DECLARATION                                     -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
struct dllNode *dllNode_Create(struct PersonData *);

/** @defgroup insertion functions */
const uint16_t dllNode_Append(struct dllNode **, struct PersonData *);
const uint16_t dllNode_Push(struct dllNode **, struct PersonData *);

/** @defgroup private functions */
static const uint16_t dllNode_validity(void *);