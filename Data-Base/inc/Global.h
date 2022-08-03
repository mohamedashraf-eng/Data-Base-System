/**
 * @headerfile Global.h
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief header file that contains all needed global for the project.
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

/** @defgroup standard include */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/** @defgroup user include */
#include "../libs/LinkedLists/inc/LinkedLists.h"
#include "../libs/Queue/inc/Queue.h"
#include "../libs/Stack/inc/Stack.h"
#include "../libs/Logs/inc/Logs.h"
#include "../libs/Hashing/inc/Hashing.h"
#include "../libs/Stringer/inc/Stringer.h"
#include "../libs/UserInterface/inc/UserInterface.h"

/* 
--------------------------------------------------------------------------------------------------
!-                                     MACROS DECLARED                                           -
--------------------------------------------------------------------------------------------------
*/

//#define ERROR_EXIT_CODES    ((const uint8_t) 1U)

/**
 * @brief Macro defined function for developing error handeling.
 *        This macro function prints the {function name, line number, file name, error type}
 */
#define error_case(ERROR_TYPE) \
({fprintf(stderr, "ERROR (File: %s -- Function: %s -- Line: %d -- Type: %s)", \
                          __FILE__, __func__, __LINE__, ERROR_TYPE);}) 

/**
 * @brief Macro defined function for developing exception case handeling.
 *        This function terminates the program with specific error code.
 * @note The returned error code is used for problem diagnostics.
 */
//#define exit_code(ERROR_CODE) ({ fprintf(stderr, "ERROR_EXIT_CODE: %d", ERROR_CODE); })

/** @brief Macro defined function for developing unimplemented indicator */
#define UNIMPLEMENTED ({ printf("\n THIS MODULE NOT IMPLEMENTED YET."); exit(-1); })

/*
--------------------------------------------------------------------------------------------------
!-                                     STRUCTS DECLARED                                          -
--------------------------------------------------------------------------------------------------
*/


/* 
--------------------------------------------------------------------------------------------------
!-                                     FUNCTIONS DECLARED                                        -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup global functions */
void dma_validity(void *);

