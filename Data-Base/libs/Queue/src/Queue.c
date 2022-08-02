/**
 * @file Queue.c
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

#include "../inc/Queue.h"

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
 * @brief Function to create queue
 * @param void
 * @return Queue struct
*/
struct Queue *Queue_Create(void)
{
    /* Create the heap memory for the queue struct */
    struct Queue *NewQueue = (struct Queue *) malloc(sizeof(struct Queue));

    /* Initalize queue parameters */
    NewQueue->Front = NULL;
    NewQueue->Rear = NULL;
    NewQueue->QueueSize = 0;

    /* Return the new queue*/
    return NewQueue;
}/** @end Queue_Create*/

/**
 * @brief Function to create queue
 * @param void
 * @return Queue struct
*/
void Queue_Destroy(struct Queue *queue)
{
    

} /** @end Queue_Destroy*/

/** @defgroup insertion functions */
/**
 * @brief Function
 * @param Queue struct
 * @param Data struct
 * @return error_type
*/
error_type Queue_enqueue(struct Queue *queue, struct PersonData *data)
{
    /* Error handling */
    if( !(Queue_Validity) )
    {
        /* RET_TYPE */
        exit(-1); /** @todo ADD ERROR_CODE */
    }   
    else;

    /* Check the data if valid or not */
    dma_validity(data);

    /* Check wether the queue is empty or not */
    if ( (Queue_IsEmpty) ) /* If queue is empty*/
    {
        /* Create new node */
        struct dllNode *dllNodeNew = dllNode_Create(data);
        queue->Front = dllNodeNew;
        queue->Rear  = dllNodeNew;
        queue->QueueSize += 1;

        /* RET_TYPE */
        return 1; /** @todo ADD ERROR_CODE */
    }    
    else     /* If queue isn't empty */
    {
        /* Create new node */
        struct dllNode *dllNodeNew = dllNode_Create(data);

        /* O(1) Inserting */
        queue->Rear->dllNodeNext = dllNodeNew;
        dllNodeNew->dllNodePrev  = queue->Rear; /** @todo to be optimizied */
        queue->Rear = dllNodeNew;
        queue->QueueSize += 1;
    
        /* RET_TYPE */
        return 1; /** @todo ADD ERROR_CODE */
    }    
}/** @end Queue_enqueue */


/**
 * @brief Function
 * @param Queue
 * @return
*/
struct PersonData *Queue_dequeue(struct Queue *queue)
{


}/** @end Queue_dequeue */

/** @defgroup sub functions */
/**
 * @brief Function to get the front of the queue
 * @param Queue struct
 * @return Queue front node address
*/
static struct dllNode *Queue_Front(struct Queue *queue)
{
    Queue_Validity(queue);

    return (queue->front);
}/** @end Queue_Front*/

/**
 * @brief Function to check wether queue is empty or not.
 * @param Queue struct
 * @return Queue size
*/
static uint32_t Queue_Size(struct Queue *queue)
{
    if( (Queue_IsEmpty(queue)) )
    {
        return 0;
    }
    else
    {
        return (queue->QueueSize);
    }

}/** @end Queue_IsEmpty */

/**
 * @brief Function to check wether queue is empty or not.
 * @param Queue struct
 * @return boolean value.
*/
static error_type Queue_IsEmpty(struct Queue *queue)
{
    if( (queue == NULL) )
    {
        /* RET_TYPE */
        return 0; /** @todo ADD ERROR_CODE */
    }
    else
    {
        return 1; /** @todo ADD ERROR_CODE */
    }
}/** @end Queue_IsEmpty */

/**
 * @brief Function to check Validity of the queue.
 * @param Queue struct
 * @return error_type
*/
static error_type Queue_Validity(struct Queue *queue)
{
        if( (queue == NULL) )
    {
        /* RET_TYPE */
        return 0; /** @todo ADD ERROR_CODE */
    }
    else
    {
        return 1; /** @todo ADD ERROR_CODE */
    }
}/** @end Queue_Validity */