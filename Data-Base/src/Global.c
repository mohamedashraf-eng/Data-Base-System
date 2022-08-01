/**
 * @file Global.c
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief soruce file file that contains all needed global for the project.
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

#include "Global.h"

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

/**
 * @brief Function to check wether the dynamic memory allocation like
 *        "malloc-calloc" is valid or not (returned NULL)
 * 
 * @param passed_pointer (void *)
 * @return Nothing.
 */
void dma_validity(void *passed_pointer)
{
    if( (passed_pointer) == NULL)
    {
        /** Error Handling Algorithm */
        fprintf(stderr, "malloc failed: NULL");
        

        /** @return terminate: FAILURE INDICATION */
        exit(1);
    }
    else
    {
        /** @return nothing: SUCESSFUL INDICATION*/
        return;
    }    

#ifdef DUEBG
    /** Strict exit */
    //static_assert((passed_pointer != NULL), "ERROR: malloc failed.");
#endif
} /** @end dma_validity */



