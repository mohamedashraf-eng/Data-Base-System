/**
 * @headerfile nodes.h
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

/** @defgroup std libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <assert.h>

/* 
--------------------------------------------------------------------------------------------------
!-                                   ERROR_HANDLER SECTION                                       -
--------------------------------------------------------------------------------------------------
*/

#define ERROR_FUNCTIONS ((const uint8_t) 3)

/** @def return error code type */
typedef const uint16_t error_t;

/** @def standard error function format */
//typedef error_t (*error_func) (void *);


/** @def basic enum error codes */
enum ERROR_CODES 
{
    DEAD = -2,
    EXCEPTION = -1,
    FAILURE,
    SUCCESS
};

/** @defgroup main functions */
void error_action(void);

/** @defgroup sub functions */
error_t dma_validity(void *);
error_t method_validity(void *);
error_t dp_validity(void *);
error_t data_validity(void *);

/* 
--------------------------------------------------------------------------------------------------
!-                                     NODES SECTION                                             -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup data structs */
/**
 * @brief struct to store the person data variables.
 * 
 */
#pragma pack(1) /** @note packing set to 1 byte*/
struct person
{   
    /** @defgroup System Variables */
    /** @brief Parsed as numerical */
    uint32_t SystemID;
    uint32_t SystemSalt;
    
    /** @defgroup Person Variables */
    /** @brief Parsed as string */
    char *PersonFirstName;
    char *PersonLastName;
    char *PersonAge;
    char *PersonEmail;
    char *PersonPassword;
    char *PersonPhoneNumber;
    char *PersonJobTitle;
    char *PersonSalary;
    char *PersonWorkHours;

    /** @todo ADD THINGS */
    /** @defgroup Person Flag Variables */
    /** @brief Parsed as numerical */ /** @note True/False */
    uint8_t Doctor_Reserved;

}; typedef struct person person_t;

/**
 * @brief union to system data selector.
 * 
 */
union data
{
    /** @def customer data */
    person_t *PersonData;

    /** @def product data */
    /** @todo to be cooded */
    // struct product *ProductData; 
}; typedef union data data_t;

/** @defgroup methods structs */
/** 
 * @brief struct to store the linked-list node parameters.
 * 
*/
struct llnode
{
    /** @defgroup Single Linked-List */
    struct llnode *next;
    union  data   *data;

    /** @defgroup Doubly Linked-List */
    struct llnode *previous;
}; typedef struct llnode node_t;

/** 
 * @brief struct to store the queue node parameters.
 * 
*/
struct queue
{
    struct llnode *front;
    struct llnode *rear;
    uint16_t size;
}; typedef struct queue queue_t;

/** 
 * @brief struct to store the stack node parameters.
 * 
*/
struct stack
{
    struct llnode *top;
    struct llnode *bottom;
    uint16_t size;
}; typedef struct stack stack_t;

/** 
 * @brief struct to store the tree node parameters.
 * 
*/
struct tree
{
    struct llnode *left; 
    struct llnode *right;
    uint16_t size;
}; typedef struct tree tree_t;

/**
 * @brief struct to store the hash table parameters.
 * 
*/
struct linkedlist
{
    struct llnode *head;
    struct llnode *tail;
    uint16_t size;
}; typedef struct linkedlist list_t;

/**
 * @brief struct to store the hash table parameters.
 * 
*/
struct HashTable
{
    list_t **list_table;

    //queue_t **queued_table;
    uint16_t maxsize;
}; typedef struct HashTable hash_t;

/** @defgroup main functions */
queue_t *queue_create(void);
stack_t *stack_create(void);
tree_t  *tree_create(void);
list_t  *list_create(void);

/** @defgroup sub functions */
struct llnode *node_create(union data *);

/* 
--------------------------------------------------------------------------------------------------
!-                                     STACK SECTION                                             -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
error_t push(struct stack *, union data *);
data_t *pop(struct stack *);

/** @defgroup sub functions */
static struct llnode *top(struct stack *);
static uint16_t stack_size(struct stack *);
static uint8_t stack_isempty(struct stack *);


/* 
--------------------------------------------------------------------------------------------------
!-                                     QUEUE SECTION                                             -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
error_t enqueue(struct queue *, union data *);
data_t *dequeue(struct queue *);

/** @defgroup sub functions */
static struct llnode *front(struct queue *);
static uint16_t queue_size(struct queue *);
static uint8_t queue_isempty(struct queue *);

/* 
--------------------------------------------------------------------------------------------------
!-                                     LINKED LIST SECTION                                       -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
error_t list_append(list_t *, data_t *);
error_t list_push(list_t *, data_t *);
//error_t list_removefirst(list_t *);
//error_t list_removelast(list_t *);

/** @defgroup sub functions */
static struct llnode *tail(list_t *);
static uint16_t list_size(list_t*);
static uint8_t list_isempty(list_t *);

/* 
--------------------------------------------------------------------------------------------------
!-                                      HASH SECTION                                             -
--------------------------------------------------------------------------------------------------
*/

#define KEY             ((const uint16_t) (1332))
#define HASH_TABLE_SIZE ((const uint8_t)  (20)  )

typedef uint32_t (*hashfunction_t) (data_t *);

/** @defgroup main functions */
error_t hashtable_insert(hash_t *, data_t *);
error_t hashtable_remove(hash_t *, const uint16_t );

/** @defgroup hash table */
hash_t  *hashtable_create(const uint16_t );
static person_t *hashlist_search(hash_t *);

/** @defgroup hash functions */
static uint32_t division_method(const uint16_t );
static uint32_t mid_square(data_t *);
static uint32_t digit_folding(data_t *);

/*
--------------------------------------------------------------------------------------------------
!-                                      Data Processing SECTION                                  -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */

/** @defgroup sub functions */

/*
--------------------------------------------------------------------------------------------------
!-                                      User Interface SECTION                                   -
--------------------------------------------------------------------------------------------------
*/

#define MAX_INPUT_SIZE ((const uint8_t ) (100))
#define ADMIN_PW ((const uint32_t) (1234))

/** @defgroup main functions */
error_t  user_gui(void);
person_t *user_persondata_get(data_t *);

/** @defgroup sub functions */
static error_t menu_main(void);
static error_t menu_admin(hash_t *);
static error_t menu_user(hash_t *);
static error_t menu_exit(void);

static error_t data_initalize(person_t *);
static error_t patient_add(hash_t *);
static error_t patient_edit(hash_t *);
static error_t patient_reserve(hash_t *);
static error_t patient_cancel(hash_t *);
static error_t patient_record(hash_t *);
static error_t patient_reservations(hash_t *);

