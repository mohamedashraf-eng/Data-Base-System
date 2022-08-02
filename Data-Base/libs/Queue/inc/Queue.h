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

#include "..\..\..\inc\Global.h"
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
void Queue_Destroy(struct Queue *);

/** @defgroup insertion functions */
error_type Queue_enqueue(struct Queue *, struct PersonData *);
struct PersonData *Queue_dequeue(struct Queue *);
 

/** @defgroup sub functions */
static struct dllNode *Queue_Front(struct Queue *);
static error_type Queue_IsEmpty(struct Queue *);
static uint32_t Queue_Size(struct Queue *);
static error_type Queue_Validity(struct Queue *);