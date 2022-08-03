/**
 * @file main.c
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief main execute unit for the program.
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) Wx Software 2022
 * 
 */

#include "inc/Global.h"

/** @note testing */
struct dllFunctions dll = {.create = &dllNode_Create, .append = &dllNode_Append, .push = &dllNode_Push};


/**
 * @brief main entry point for the program.
 * 
 * @return int 
 */
int main(void)
{
    struct PersonData person = {.SystemID = 1332};

    struct dllNode *list = dllNode_Create(&person);

    dll.append(&list, &person);

    printf("\n Data: %d", list->personData->SystemID);

    
    return 0;
}
