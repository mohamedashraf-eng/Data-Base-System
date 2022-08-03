/**
 * @headerfile Queue.h
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
 * @brief Struct for queue.
 *
*/
#pragma pack(1) /** @note packing set to 1 byte*/
struct Queue
{
    /** @defgroup Queue aramaters */
    struct dllNode *Front;
    struct dllNode *Rear;
    uint32_t QueueSize;
};

/* 
--------------------------------------------------------------------------------------------------
!-                                     FUNCTIONS IMPLEMENTATION                                  -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
struct Queue *Queue_Create(void);
void Queue_Destroy(struct Queue *); /** @todo IMPLEMENT */

/** @defgroup insertion functions */
error_type Queue_enqueue(struct Queue *, struct PersonData *);
error_type Queue_dequeue(struct Queue *);
 

/** @defgroup sub functions */
static struct dllNode *Queue_Front(struct Queue *);
static error_type Queue_IsEmpty(struct Queue *);
static uint32_t Queue_Size(struct Queue *);
static error_type Queue_Validity(struct Queue *);
