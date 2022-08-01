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
 * @brief Struct containg the data that will be stored in data base.
 *
*/
struct PersonData
{   
    /** @defgroup System Variables */
    /** @brief Parsed as string */

    const uint64_t SystemID;
    const uint32_t SystemSalt;
    
    /** @defgroup Person Variables */
    /** @brief Parsed as string */

    const uint8_t *PersonFirstName;
    const uint8_t *PersonLastName;
    const uint8_t *PersonAge;
    const uint8_t *PersonEmail;
    const uint8_t *PersonPassword;
    const uint8_t *PersonPhoneNumber;
    const uint8_t *PersonJobTitle;
    const uint8_t *PersonSalary;
    const uint8_t *PersonWorkHours;
};

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