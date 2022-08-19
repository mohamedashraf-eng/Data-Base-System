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

/* 
--------------------------------------------------------------------------------------------------
!-                                     LIBRARIES INCLUDED                                        -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup std libraries */
#include "global.h"

/* 
--------------------------------------------------------------------------------------------------
!-                                   ERROR_HANDLER SECTION                                       -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
/**
 * @brief Function to take action to all error codes.
 * 
 */
void error_action(void)
{
    /** @todo implement */


}/** @end error_action */

/** @defgroup sub functions */
/**
 * @brief Error function that check the dynamic memory allocation validity.
 * 
 * @param heap_pointer 
 * @return error_t 
 */
error_t dma_validity(void *heap_pointer)
{
    /** @def assert the state */
    assert( (heap_pointer != NULL) );

    /* Check if the pointer is null */
    if( (heap_pointer == NULL) )
    {
        return FAILURE; /** @todo change to its error code */
    }
    else
    {
        return SUCCESS; /** @todo change to its error code */
    }
}/** @end dma_validity */

/**
 * @brief Error function that check the method validity.
 * 
 * @param method_pointer 
 * @return error_t 
 */
error_t method_validity(void *method_pointer)
{
    /** @def assert the state */
    assert( (method_pointer != NULL) );

    /* Check if the pointer is null */
    if( (method_pointer == NULL) )
    {
        return FAILURE; /** @todo change to its error code */
    }
    else
    {
        return SUCCESS; /** @todo change to its error code */
    }
}/** @end method_validity */

/**
 * @brief Error function that check the data validity.
 * 
 * @param data_pointer 
 * @return error_t 
 */
error_t data_validity(void *data_pointer)
{
    /** @def assert the state */
    assert( (data_pointer != NULL) );

    /* Check if the pointer is null */
    if( (data_pointer == NULL) )
    {
        return FAILURE; /** @todo change to its error code */
    }
    else
    {
        return SUCCESS; /** @todo change to its error code */
    }
}/** @end data_validity */

/**
 * @brief Error function that check the data validity.
 * 
 * @param data_pointer 
 * @return error_t 
 */
error_t dp_validity(void *dp_pointer)
{
    /** @def assert the state */ 
    assert( (dp_pointer != NULL) );

    /* Check if the pointer is null */
    if( (dp_pointer == NULL) )
    {
        return FAILURE; /** @todo change to its error coWSWde */
    }
    else
    {
        return SUCCESS; /** @todo change to its error code */
    }
}/** @end data_validity */

/* 
--------------------------------------------------------------------------------------------------
!-                                     NODES SECTION                                             -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */

/**
 * @brief Function to create - initalize queue thread.
 * 
 * @return struct queue* 
 */
struct queue *queue_create(void)
{
    /* Allocate queue in heap memory */
    struct queue *myqueue = (struct queue *) malloc(sizeof(struct queue));

    /* error handle */
    dma_validity(myqueue);

    /* Set queue parameters */
    myqueue->front = NULL;
    myqueue->rear  = NULL;
    myqueue->size  = 0;

    /* return the queue */
    return myqueue;
}/** @end queue_create */

/**
 * @brief Function to create - initalize stack thread.
 * 
 * @return struct stack* 
 */
struct stack *stack_create(void)
{
    /* Allocate queue in heap memory */
    struct stack *mystack = (struct stack *) malloc(sizeof(struct stack));

    /* error handle */
    dma_validity(mystack);

    /* Set queue parameters */
    mystack->top    = NULL;
    mystack->bottom = NULL;
    mystack->size   = 0;

    /* return the stack */
    return mystack;
}/** @end stack_create */

/**
 * @brief Function to create - initalize tree thread.
 * 
 * @return struct tree* 
 */
struct tree *tree_create(void)
{
    /* Allocate queue in heap memory */
    struct tree *mytree = (struct tree *) malloc(sizeof(struct tree));

    /* error handle */
    dma_validity(mytree);

    /* Set queue parameters */
    mytree->left  = NULL;
    mytree->right = NULL;
    mytree->size  = 0;

    /* return the stack */
    return mytree;
}/** @end tree_create */


/**
 * @brief Function to create - initalize tree thread.
 * 
 * @return list_t* 
 */
list_t *list_create(void)
{
    /* Allocate queue in heap memory */
    list_t *mylist = (list_t *) malloc(sizeof(list_t));

   /* error handle */
    dma_validity(mylist);

    /* Set list parameters */
    mylist->head  = NULL;
    mylist->tail  = NULL;
    mylist->size  = 0;

    /* return the stack */
    return mylist;
}/** @end list_create*/

/**
 * @brief Functino to create - initialize hash table.
 *
*/  
hash_t *hashtable_create(const uint16_t size)
{
    /* Allocate queue in heap memory */
    hash_t *newtable = (hash_t *) malloc(sizeof(hash_t));

    /* error handle */
    dma_validity(newtable);

    /** assign the maxsize */
    newtable->maxsize = size;

    /* Initalize the hash table */
    /* Create array of pointers to stack_t */
    newtable->list_table = (list_t **) malloc(sizeof(list_t *) * newtable->maxsize);

    /* Create stacks */
    int i;
    for(i = 0; (i < (newtable->maxsize)); i++)
    {
        /* Allocate stack */
        newtable->list_table[i] = list_create();
    }
    
    /* return the table */
    return newtable;
}/** @end hashtable_create */

/**
 * 
 * @brief Function to create node and insert data.
 * 
 * @return struct llnode* 
 */
struct llnode *node_create(union data *data)
{
    /* Error handler */
    data_validity(data);

    /* Allocate node in heap memory */
    struct llnode *newnode = (struct llnode *) malloc(sizeof(struct llnode));

    /* Error handler */
    dma_validity(newnode);

    /* Initalize node parameters */
    newnode->data = data;
    newnode->next = NULL;
    newnode->previous = NULL;

    /* return the node */
    return newnode;
}/** @end node_create */

/* 
--------------------------------------------------------------------------------------------------
!-                                     STACK SECTION                                             -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
/**
 * @brief Function to insert new data inside threaded stack. 
 * 
 * @param mystack 
 * @return error_t 
 */
error_t push(struct stack *mystack, union data *data)
{
    /* Error handler */
    method_validity(mystack);
    data_validity(data);

    /* check if the stack is empty or not */
    if( (stack_isempty(mystack)) )
    {
        /* Create & Intalize new node */
        struct llnode *newnode = node_create(data);
        
        /* make top and bottom point to the first node */
        mystack->top = newnode;
        mystack->bottom  = newnode;
        mystack->size += 1;

        /* Return code */
        return SUCCESS;
    }
    else
    {
        /* Create & Intalize new node */
        struct llnode *newnode = node_create(data);
        
        /* make the previous top point to the next new node */
        mystack->top->next = newnode;
    
        /* make the new node as current top (last added node) */
        mystack->top = newnode;

        mystack->size += 1;

        /* Return code */
        return SUCCESS;
    }

}/** @end enstack */

/**
 * @brief Function to remove exist data inside threaded stack.
 * 
 * @param mystack 
 * @return error_t 
 */
union data *pop(struct stack *mystack)
{
    /* Error handler */
    method_validity(mystack);

    /* check if the stack is empty or not */
    if( (stack_isempty(mystack)) )
    {
        /* Return code */
        return FAILURE;
    }
    else;

    /* Temporary variable to store the current top node */
    union data *temporary = mystack->top->data;

    /* Make the second added node as current top */
    mystack->top = mystack->top->next;

    mystack->size -= 1;

    /* return the popped data */
    return temporary;
}/** @end enstack */

/** @defgroup sub functions */

static uint8_t stack_isempty(struct stack *mystack)
{
    /* Erro handler */
    method_validity(mystack);

    if( (mystack->size == 0) )
    {
        /* return true */
        return 1;
    }
    else
    {
        /* return false */
        return 0;
    }
}/** @end stack_isempty */

/**
 * @brief Function to get the top of threaded stack.
 * 
 * @param mystack 
 * @return llnode* 
 */
static struct llnode *top(struct stack *mystack)
{
    /* Error handler */
    method_validity(mystack);

    if( (stack_isempty(mystack)) )
    {
        return NULL;
    }
    else
    {
        return ( (mystack->top) );
    }
}/** @end top */

/**
 * @brief Function to get the stack_size of threaded stack.
 * 
 * @param mystack 
 * @return uint16_t 
 */
static uint16_t stack_size(struct stack *mystack)
{
    /* Error handler */
    method_validity(mystack);

    if( (mystack->size <= 0) )
    {
        return 0;
    }
    else
    {
        return ( (mystack->size) );
    }
}/** @end stack_size */

/* 
--------------------------------------------------------------------------------------------------
!-                                     QUEUE SECTION                                             -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */

/**
 * @brief Function to insert new data inside threaded queue. 
 * 
 * @param myqueue 
 * @return error_t 
 */
error_t enqueue(struct queue *myqueue, union data *data)
{
    /* Error handler */
    method_validity(myqueue);
    data_validity(data);

    /* check if the queue is empty or not */
    if( (queue_isempty(myqueue)) )
    {
        /* Create & Intalize new node */
        struct llnode *newnode = node_create(data);
        
        /* make front and rear point to the first node */
        myqueue->front = newnode;
        myqueue->rear  = newnode;
        myqueue->size += 1;

        /* Return code */
        return SUCCESS;
    }
    else
    {
        /* Create & Intalize new node */
        struct llnode *newnode = node_create(data);
        
        /* make the previous rear point to the next new node */
        myqueue->rear->next = newnode;
        /* make the new node as current rear (last added node) */
        myqueue->rear = newnode;

        myqueue->size += 1;

        /* Return code */
        return SUCCESS;
    }
}/** @end enqueue */

/**
 * @brief Function to remove exist data inside threaded queue.
 * 
 * @param myqueue 
 * @return error_t 
 */
data_t *dequeue(queue_t *myqueue)
{
    /* Error handler */
    method_validity(myqueue);

    /* check if the queue is empty or not */
    if( (queue_isempty(myqueue)) )
    {
        /* Return code */
        return FAILURE;
    }
    else;

    /* Temporary variable to store the current front node */
    node_t *temporary = myqueue->front;

    /* Make the second added node as current front */
    myqueue->front = myqueue->front->next;
    
    myqueue->size -= 1;

    return (temporary->data);
}/** @end enqueue */

/** @defgroup sub functions */

static uint8_t queue_isempty(struct queue *myqueue)
{
    /* Error handling */
    method_validity(myqueue);

    if( (queue_size(myqueue) == 0) )
    {
        /* return true */
        return 1;
    }
    else
    {
        /* return false */
        return 0;
    }
}/** @end queue_isempty */

/**
 * @brief Function to get the front of threaded queue.
 * 
 * @param myqueue 
 * @return llnode* 
 */
static struct llnode *front(struct queue *myqueue)
{
    /* Error handler */
    method_validity(myqueue);

    if( (queue_isempty(myqueue)) )
    {
        return 0;
    }
    else
    {
        return ( (myqueue->front) );
    }
}/** @end front */

/**
 * @brief Function to get the size of threaded queue.
 * 
 * @param myqueue 
 * @return uint16_t 
 */
static uint16_t queue_size(struct queue *myqueue)
{
    /* Error handler */
    method_validity(myqueue);

    if( (myqueue->size <= 0) )
    {
        return 0;
    }
    else
    {
        return ( (myqueue->size) );
    }
}/** @end queue_size */

/* 
--------------------------------------------------------------------------------------------------
!-                                     LINKED LIST SECTION                                       -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
/**
 * @brief Function to append data in list.
 * 
 * @return error_t 
 */
error_t list_append(list_t *mylist, data_t *mydata)
{
    /* Error handler */
    data_validity(mydata);
    method_validity(mylist);

    /* Create & Intalize new node */
    node_t *newnode = node_create(mydata);

    if( (list_isempty(mylist)) )
    {
        /* Set list parameters */
        mylist->head = newnode;
        mylist->tail = newnode;
        mylist->size += 1;

        /* return type */
        return SUCCESS;
    }
    else
    {
        /* let the last tail node next point to the new node */
        mylist->tail->next = newnode;
        /* let the newnode previous point to the its previous node (tail) */
        newnode->previous = mylist->tail;
        /* let the tail points to the newnode */
        mylist->tail = newnode;

        mylist->size += 1;

        /* return type */
        return SUCCESS;  
    }
}/** @end list_append */

/**
 * @brief Function to push data in list.
 * 
 * @return error_t 
 */
error_t list_push(list_t *mylist, data_t *mydata)
{
    /* Error handler */
    data_validity(mydata);
    method_validity(mylist);
    
    if( (list_isempty(mylist)) )
    {
        /* Create & Intalize new node */
        node_t *newnode = node_create(mydata);

        /* Set list parameters */
        mylist->head = newnode;
        mylist->tail = newnode;
        mylist->size += 1;

        /* return type */
        return SUCCESS;
    }
    else
    {
        /* Create & Intalize new node */
        node_t *newnode = node_create(mydata);

        /* let the newnode next points to the previous head node */
        newnode->next = mylist->head;
        /* let the previous of last head node points to the current head node */
        mylist->head->previous = newnode;
        /* let the newnode be the current head node */
        mylist->head = newnode;
        
        mylist->size += 1;
    }

    /* return type */
    return SUCCESS;
}/** @end list_push */

/**
 * @brief Function to remove specific node in a list.
 *
 * @param
 *
 * @return     The error.
 */
error_t list_remove_node(list_t *mylist, uint32_t sysid)
{
    /* Error handler */
    method_validity(mylist);

    if( (list_isempty(mylist)) )
    {
        return FAILURE;
    }
    else;

    /* Iterate till find the required sysid */
    uint8_t found_flag = 0;
    while( (mylist->head != NULL) )
    {
        if( (mylist->head->data->PersonData->SystemID == sysid) )
        {
            found_flag = 1;
            break;
        }
        else;

        mylist->head = mylist->head->next;
    }

    if( (found_flag) )
    {
        node_t *temp = mylist->head;

        /* Exhange the linkage */
        mylist->head->previous->next = mylist->head->next;
        mylist->head->next->previous = mylist->head->previous;

        /* Free the node */
        free(temp);
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}/** @end list_remove_node */

/** @defgroup sub functions */

/**
 * @brief Function to get list tail.
 * 
 * @param mylist 
 * @return struct llnode* 
 */
static struct llnode *tail(list_t *mylist)
{
    /* Error handler */
    method_validity(mylist);
    
    if( !(list_isempty(mylist)) )
    {
        return (mylist->tail);
    }
    else
    {
        return NULL;
    }
}/** @end list_isempty */

/**
 * @brief Functino to check if list is empty.
 * 
 * @param mylist 
 * @return uint8_t 
 */
static uint8_t list_isempty(list_t *mylist)
{
    /* Error handler */
    method_validity(mylist);

    if( (list_size(mylist) == 0) )
    {
        /* return true */
        return 1;
    }
    else
    {
        /* return false */
        return 0;
    } 
}/** @end list_isempty */

/**
 * @brief Funcion to get size of list.
 *
 * @param mylist
 * @return uint16_t
 */
static uint16_t list_size(list_t *mylist)
{
    /* Error handler */
    method_validity(mylist);

    if( (mylist->size <= 0) )
    {
        return 0;
    }
    else
    {
        return (mylist->size);
    }

}/** @end list_isempty */

/* 
--------------------------------------------------------------------------------------------------
!-                                      HASH SECTION                                             -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
/**
 * @brief Function to insert new data inside hash table.
 *
 * @param hash_t *
 * @param data_t *
 * @param hashfunction_t
 *
 * @return error_r
 */
error_t hashtable_insert(hash_t *mytable, data_t *mydata)
{
    /* Error handler */
    dp_validity(mytable);
    data_validity(mydata);

    /* Get the hash number */
    const uint32_t hashnumber = division_method(mydata->PersonData->SystemSalt);

    /* Insert inisde its eqv list */
    list_t *current_list = (mytable->list_table[hashnumber]);
    list_append(current_list, mydata);

    /* return type */
    return SUCCESS;
}/** @end hashtable_insert */

/**
 * @brief Function to insert new data inside hash table.
 *
 * @param mytable
 * @param mydata
 * @param SysID
 * @param myhashfunction
 * @return error_t
 */
error_t hashtable_remove(hash_t *mytable, const uint16_t SysSalt)
{
    /* Error handler */
    dp_validity(mytable);

    /* Get the hash number */
    const uint32_t hashnumber = division_method(SysSalt);

    /** @todo implement the removing algorithm */

    /* return type */
    return SUCCESS;
}/** @end hashtable_remove */



/**
 * @brief Function to search inside hashtable list.
 * @return return data.
 */
static person_t *hashlist_search(hash_t *hashtable)
{
    /* Error handler */
    dp_validity(hashtable);
    
        /* Get hash number */
    uint16_t SystemID  = 0, 
             SystemSalt = 0;

    uint8_t found_flag = 0;

    printf("\n Enter System ID, System Salt");
    printf("\n [>]: "); scanf("%d", &SystemID);
    printf(" [>]: ");   scanf("%d", &SystemSalt);

    /* Get the list number */
    const uint16_t hash = division_method(SystemSalt);

    /* Search for the patient inside the list */ /** @todo change the mechanism */
    list_t *current_list = hashtable->list_table[hash];

    while( (current_list->head != NULL) )
    {
        /* If the System ID Found */
        if( (current_list->head->data->PersonData->SystemID) == SystemID)
        { found_flag = 1; break; }
        else;

        current_list->head = current_list->head->next;
    }

    if( (found_flag == 1) )
    {
        return ( (current_list->head->data->PersonData) );
    }
    else
    {
        return NULL;
    }
}/** @end hashlist_search */


/** @defgroup hash functions */
/**
 * @brief Function to generate hashing using division method.
 * 
 * @return uint32_t 
 */
static uint32_t division_method(const uint16_t SysSalt)
{
    /* Error handler
    data_validity(data);
    */

    uint32_t hashing = 0;
/*
    uint32_t firstname_sum = 0, 
             lastname_sum  = 0;
    
    const uint16_t firstname_len = strlen(data->PersonData->PersonFirstName);
    const uint16_t lastname_len  = strlen(data->PersonData->PersonLastName);

    int i;*/
    /* Calculating the first name sum
    for(i = 0; (i < firstname_len); i++)
    { firstname_sum += data->PersonData->PersonFirstName[i]; }
    */
    /* Calculating the last name sum
    for(i = 0; (i < lastname_len); i++)
    { lastname_sum += data->PersonData->PersonLastName[i]; }
    */
    /* hashing
    hashing = ((firstname_sum + lastname_sum) + (data->PersonData->SystemSalt)) % (HASH_TABLE_SIZE-1);
*/

    hashing = (KEY%SysSalt) % (HASH_TABLE_SIZE);
    /* return the hash code */     /* limit the hashing number */
    return ( hashing );
}/** @end division_method */

/**
 * @brief Function to generate hashing using mid square method. 
 * 
 * @param data 
 * @return uint32_t 
 */
static uint32_t mid_square(data_t *data)
{
    /* Error handler */
    data_validity(data);


}/** @end mid_square */

/**
 * @brief Functinon to generate hashing using digit folding method.
 * 
 * @param data 
 * @return uint32_t 
 */
static uint32_t digit_folding(data_t *data)
{
    /* Error handler */
    data_validity(data);


}/** @end digit_folding */

/*
--------------------------------------------------------------------------------------------------
!-                                      Data Processing SECTION                                  -
--------------------------------------------------------------------------------------------------
*/


/*
--------------------------------------------------------------------------------------------------
!-                                      User Interface SECTION                                   -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */

/**
 * @brief Function to get the input data from user.
 *
 * @return data_t
 */
person_t *user_persondata_get(data_t *data)
{
    data->PersonData = (person_t *) malloc(sizeof(person_t));
    dma_validity((data->PersonData));

    //data_initalize((data->PersonData)); // Initalize the data to its default value.

    /* Get the data from user */
    char firstname[MAX_INPUT_SIZE],
         lastname[MAX_INPUT_SIZE],
         email[MAX_INPUT_SIZE],
         password[MAX_INPUT_SIZE],
         phonenumber[MAX_INPUT_SIZE],
         jobtitle[MAX_INPUT_SIZE],
         age[MAX_INPUT_SIZE],
         salary[MAX_INPUT_SIZE],
         workhours[MAX_INPUT_SIZE];

    printf("\n First name: ");
    scanf("%s", firstname);

    printf("\n Last name: ");
    scanf("%s", lastname);

    printf("\n Age: ");
    scanf("%s", &age);

    printf("\n Email: ");
    scanf("%s", email);

    printf("\n Password: ");
    scanf("%s", password);

    printf("\n Phone number: ");
    scanf("%s", phonenumber);

    printf("\n Job title: ");
    scanf("%s", jobtitle);

    printf("\n Salary: ");
    scanf("%s", &salary);

    printf("\n Working hours: ");
    scanf("%s", &workhours);

    /* Allocate the data */
    data->PersonData->PersonFirstName   = (char *) malloc(sizeof(char) * strlen(firstname));
    data->PersonData->PersonLastName    = (char *) malloc(sizeof(char) * strlen(lastname));
    data->PersonData->PersonEmail       = (char *) malloc(sizeof(char) * strlen(email));
    data->PersonData->PersonPassword    = (char *) malloc(sizeof(char) * strlen(password));
    data->PersonData->PersonPhoneNumber = (char *) malloc(sizeof(char) * strlen(phonenumber));
    data->PersonData->PersonJobTitle    = (char *) malloc(sizeof(char) * strlen(jobtitle));
    data->PersonData->PersonAge         = (char *) malloc(sizeof(char) * strlen(age));
    data->PersonData->PersonSalary      = (char *) malloc(sizeof(char) * strlen(salary));
    data->PersonData->PersonWorkHours   = (char *) malloc(sizeof(char) * strlen(workhours));
    /* Set the data */
    strcpy( (data->PersonData->PersonFirstName),    (firstname)   );
    strcpy( (data->PersonData->PersonLastName),     (lastname)    );
    strcpy( (data->PersonData->PersonEmail),        (email)       );
    strcpy( (data->PersonData->PersonPassword),     (password)    );
    strcpy( (data->PersonData->PersonPhoneNumber),  (phonenumber) );
    strcpy( (data->PersonData->PersonJobTitle),     (jobtitle)    );
    strcpy( (data->PersonData->PersonAge),          (age)         );
    strcpy( (data->PersonData->PersonSalary),       (salary)      );
    strcpy( (data->PersonData->PersonWorkHours),    (workhours)   );

    /* return the data */
    return (data->PersonData);
}/** @end user_data_get */

/** @defgroup sub functions */

/**
 * @brief Function to initalzie the data.
 *
 * @param data
 *
 * @return error_t
 */
static error_t data_initalize(person_t *data)
{
    /* Error*/
    data_validity(data);

    /* Set default values for data */
    data->SystemID          = 0;
    data->SystemSalt        = 0;
    data->PersonFirstName   = NULL;
    data->PersonLastName    = NULL;
    data->PersonAge         = NULL;
    data->PersonPassword    = NULL;
    data->PersonPhoneNumber = NULL;
    data->PersonJobTitle    = NULL;
    data->PersonSalary      = NULL;
    data->PersonWorkHours   = NULL;

    return SUCCESS;
}/** @end data_initalize */


/**
 * @brief Function to handle the user interface.
 *
 * @return error_t
 */
error_t user_gui(void)
{
    /* Start with the main menu */
    menu_main();
}/** @end menu_gui */

/**
 * @brief Function for main menu gui.
 *
 * @return error_t
 */
static error_t menu_main(void)
{
    while(1)
    {
        system("cls");

        printf("\t |***********************************************************************| \n");
        printf("\t |*                     CLINIC MANAGEMENT SYSTEM                        *| \n");
        printf("\t |***********************************************************************| \n");

        char mode_select = 0;
        printf("\n Choose system mode: ");
        printf("\n 1. Admin mode. \
                \n 2. User mode    \
                \n 3. Exit. ");
        printf("\n [>]: ");
        scanf(" %c", &mode_select);

        /* Check if exit is pressed */
        if( (mode_select == '3') )
        { 
            menu_exit(); 
            return SUCCESS;
        }
        else;

        /* Create new hashtable */
        hash_t *hashtable = hashtable_create(HASH_TABLE_SIZE);

        // Switch between modes.
        switch(mode_select)
        {
            /* Admin mode */
            case '1':   system("cls"); // Clear screen.

                        uint32_t admin_pw = 0;
                        uint8_t flag_correct = 0;
                        uint8_t counter = 3;

                        printf("\n To enter the adminstrator menu, Please enter the password");
                        while( (1) )
                        {   
                            printf("\n Wrong password. Remaning chances: %d", counter);
                            printf("\n [>]: "); scanf("%d", &admin_pw);
                            
                            if( (admin_pw == ADMIN_PW) )
                            {
                                flag_correct = 1;
                                break;
                            }
                            else
                            {
                                if( (counter <= 1) )
                                {
                                    flag_correct = 0;
                                    break;
                                }
                                else;

                                counter--; 
                            }
                        } /* Check if flag is correct */
                        if( !(flag_correct == 1) )
                        { break; }
                        else;

                        menu_admin(hashtable); // Admin Menu GUI
                        /** @todo add error_handler */
                        break;

            /* User mode */
            case '2':   system("cls"); // Clear screen.

                        menu_user(hashtable); // User Menu GUI
                        /** @todo add error_handler */
                        break;


            default:    printf("\n Invalid input. \n");
        }//end switch.
    }//end while.

    return SUCCESS;
}/** @end menu_main */

/**
 * @brief Function for admin menu gui.
 *
 * @return error_t
 */
static error_t menu_admin(hash_t *hashtable)
{
    /* Erro handler */
    dp_validity(hashtable);

    while(1)
    {
        system("cls");

        printf("\t |***********************************************************************|\n");
        printf("\t |*                           ADMIN MODE                                *|\n");
        printf("\t |***********************************************************************|\n");

        char mode_select = 0;
        printf("\n Choose system mode: ");
        printf("\n 1. Add new patient record.       \
                \n 2. Edit patient record.           \
                \n 3. Reserve a slot with the doctor. \
                \n 4. Cancel reservation.              \
                \n 5. Exit.");
        printf("\n [>]: ");
        scanf(" %c", &mode_select);

        if( (mode_select == '5') )
        { return SUCCESS; }
        else;

        // Switch between modes.
        switch(mode_select)
        {
            /* Add new patient record */
            case '1':   /** @todo build the mechanism */
                        patient_add(hashtable);
                        break;
            /* Edit patient record */
            case '2':   /** @todo build the mechanism */
                        patient_edit(hashtable);
                        break;
            /* Reserve a slot with the doctor */
            case '3':   /** @todo build the mechanism */
                        patient_reserve(hashtable);
                        break;
            /* Cancel reservation */
            case '4':   /** @todo build the mechanism */
                        patient_cancel(hashtable);
                        break;
            default:
                        printf("\n Invalid input. \n");
        }// end switch.
    }// end while.
}/** @end menu_admin */

/**
 * @brief Function for user menu gui.
 *
 * @return error_t
 */
static error_t menu_user(hash_t *hashtable)
{
    /* Erro handler */
    dp_validity(hashtable);

    while(1)
    {
        system("cls");

        printf("\t |***********************************************************************|\n");
        printf("\t |*                            USER MODE                                *|\n");
        printf("\t |***********************************************************************|\n");

        char mode_select = 0;
        printf("\n Choose system mode: ");
        printf("\n 1. View patient record.     \
                \n 2. View today's reservation. \
                \n 3. Exit.");
        printf("\n [>]: ");
        scanf(" %c", &mode_select);

        if( (mode_select == '3') )
        { return SUCCESS; }
        else;

        // Switch between modes.
        switch(mode_select)
        {
            /* View patient record.*/
            case '1':   patient_record(hashtable);
                        break;

            /* View today's reservation */
            case '2':   patient_reservations(hashtable);
                        break;

            default:
                        printf("\n Invalid input. \n");
        }
    }// end while.
    return SUCCESS;
}/** @end menu_user */

/**
 * @brief Functino to display the exit menu. 
 * 
 * @return error_t 
 */
static error_t menu_exit(void)
{
    system("cls");
    system("COLOR 0A");

    printf("\n Thanks for using.");
    printf("\n Coder: Mohamed Ashraf Wx");

    return SUCCESS;
}/** @end menu_exit */

/**
 * @brief Function to add new patient.
 * 
 * @return error_t 
 */
static error_t patient_add(hash_t *hashtable)
{
    /* Erro handler */
    dp_validity(hashtable);

    system("cls");

    printf("\t |***********************************************************************|\n");
    printf("\t |*                            PATIENT ADD                              *|\n");
    printf("\t |***********************************************************************|\n");

    /* Define global system id */
    static uint16_t Global_ID = 0;

    /* Get patient data */ /** @todo change the mechanism */
    data_t   *data = (data_t *) malloc(sizeof(data_t)); 
    person_t *patient_data = user_persondata_get(data);

    patient_data->SystemID   = (Global_ID);
    patient_data->SystemSalt = ( (10) + (Global_ID) ); /** @todo change the salt algorithm */

    printf("\n SysID:   %d", patient_data->SystemID);
    printf("\n SysSalt: %d", patient_data->SystemSalt);

    Global_ID++; // Increase the IDs

    /* Add the new patient to the hashtable */
    hashtable_insert(hashtable, data);
    
    printf("\n Patient added successfully. \n");

    sleep(1);

    /* return success */
    return SUCCESS;
}/** @end patient_add */

/**
 * @brief Functino to edit patient.
 * 
 * @return error_t 
 */
static error_t patient_edit(hash_t *hashtable)
{
    /* Erro handler */
    dp_validity(hashtable);

    while(1)
    {
        system("cls");

        printf("\t |***********************************************************************|\n");
        printf("\t |*                            PATIENT EDIT                             *|\n");
        printf("\t |***********************************************************************|\n");

        person_t *patient_to_edit = hashlist_search(hashtable);
        if( (patient_to_edit == NULL) )
        {
            printf("\n patient not found.");
            sleep(1);
            return FAILURE;
        }
        else;

        char switch_mode = 0;

        if( (patient_to_edit == NULL) )
        {
            printf("\n Patient not found. \n");
            sleep(1);

            return FAILURE;
        }
        else 
        { system("cls"); }

        printf("\n What do you want to edit.");
        printf("\n 0. First Name \
                \n 1. Last Name   \
                \n 2. Age          \
                \n 3. Email         \
                \n 4. Password       \
                \n 5. Phone Number    \
                \n 6. Job Title        \
                \n 7. Salary            \
                \n 8. Work hours.        \
                \n 9. Exit");          
        printf("\n [>]: "); scanf(" %c", &switch_mode);

        if( (switch_mode == '9') )
        { return SUCCESS; }
        else;

        switch( (switch_mode) )
        {
            case '0':
                        printf("\n Enter new first name: "); 
                        printf("\n [>]: "); scanf("%s", (patient_to_edit->PersonFirstName));
                        printf("\n First name edit successfully. \n");
                        sleep(1);

                        return SUCCESS;
            case '1': 
                        printf("\n Enter new last name: "); 
                        printf("\n [>]: "); scanf("%s", (patient_to_edit->PersonLastName));
                        printf("\n Last name edit successfully. \n");
                        sleep(1);

                        return SUCCESS;
            case '2':   
                        printf("\n Enter new age: "); 
                        printf("\n [>]: "); scanf("%s", (patient_to_edit->PersonAge));
                        printf("\n Age edit successfully. \n");
                        sleep(1);

                        return SUCCESS;
            case '3':
                        printf("\n Enter new email: "); 
                        printf("\n [>]: "); scanf("%s", (patient_to_edit->PersonEmail));
                        printf("\n Email edit successfully. \n");
                        sleep(1);

                        return SUCCESS;
            case '4':       
                        printf("\n Enter new password: "); 
                        printf("\n [>]: "); scanf("%s", (patient_to_edit->PersonPassword));
                        printf("\nPassword edit successfully. \n");
                        sleep(1);

                        return SUCCESS;
            case '5':
                        printf("\n Enter new phone number: "); 
                        printf("\n [>]: "); scanf("%s", (patient_to_edit->PersonPhoneNumber));
                        printf("\n Phone number edit successfully. \n");
                        sleep(1);

                        return SUCCESS;
            case '6':
                        printf("\n Enter new job title: "); 
                        printf("\n [>]: "); scanf("%s", (patient_to_edit->PersonJobTitle));
                        printf("\n Job title edit successfully. \n");
                        sleep(1);

                        return SUCCESS;
            case '7':
                        printf("\n Enter new salary: "); 
                        printf("\n [>]: "); scanf("%s", (patient_to_edit->PersonSalary));
                        printf("\n Salary edit successfully. \n");
                        sleep(1);

                        return SUCCESS;
            case '8':
                        printf("\n Enter new working hours: "); 
                        printf("\n [>]: "); scanf("%s", (patient_to_edit->PersonWorkHours));
                        printf("Working hours edit successfully. \n");
                        sleep(1);

                        return SUCCESS;

            default: printf("\n Invalid input.");
        }//end switch.
    }// end while.

    return SUCCESS;
}/** @end patient_edit */   

/**
 * @brief Functino to reserve a slot.
 * 
 * @return error_t 
 */
static error_t patient_reserve(hash_t *hashtable)
{
    /* Erro handler */
    dp_validity(hashtable);

    system("cls");

    printf("\t |***********************************************************************|\n");
    printf("\t |*                           PATIENT RESERVE                           *|\n");
    printf("\t |***********************************************************************|\n");

    person_t *patient_to_edit = hashlist_search(hashtable);
    if( (patient_to_edit == NULL) )
    {
        printf("\n patient not found.");
        sleep(1);
        return FAILURE;
    }
    else;

    /* Avaliable slots */
    const char *slots_lookuptable[NUM_OF_SLOTS] = {SLOT_1, SLOT_2, SLOT_3, SLOT_4, SLOT_5};
    static uint8_t slots_flag[NUM_OF_SLOTS] = {0,0,0,0,0};

    uint32_t user_input;
    uint8_t counter = 0;

    while(1)
    {
        system("cls");

        printf("\n The available slots: ");

        uint8_t i;
        for(i = 0; i < NUM_OF_SLOTS; i++)
        {
            printf("\n %d. %s", counter++, slots_lookuptable[i]);

            if( (slots_flag[i]) )
            {
                printf("\t X");
            }
            else;
        }
        printf("\n [>]: "); scanf("%d", &user_input);

       if( !(slots_flag[user_input]) )
        {
            slots_flag[user_input] = 1;

            patient_to_edit->reserved_slot = user_input;
            patient_to_edit->FLAG_Doctor_Reserved = 1;

            printf("\n Reservation done.");
            sleep(1);

            return SUCCESS;
        }
        else
        {
            printf("\n Invalid slot.");
            sleep(1);
            return FAILURE;
        }
    }
}/** @end patient_reserve */

/**
 * @brief Functino to cancel a reservation.
 * 
 * @return error_t 
 */
static error_t patient_cancel(hash_t *hashtable)
{
    /* Erro handler */
    dp_validity(hashtable);

    system("cls");

    printf("\t |***********************************************************************|\n");
    printf("\t |*                       PATIENT RESERVATION CANCEL                    *|\n");
    printf("\t |***********************************************************************|\n");

    person_t *patient_to_edit = hashlist_search(hashtable);
    if( (patient_to_edit == NULL) )
    {
        printf("\n patient not found.");
        sleep(1);
        return FAILURE;
    }
    else;

    patient_to_edit->FLAG_Doctor_Reserved = 0;

    printf("\n Reservation canceling done.");
    sleep(1);

    return SUCCESS;
}/** @end patient_cancel */

/**
 * @brief Function to view the pateient record.
 * 
 * @return error_t 
 */
static error_t patient_record(hash_t *hashtable)
{
    /* Erro handler */
    dp_validity(hashtable);

    system("cls");

    printf("\t |***********************************************************************|\n");
    printf("\t |*                           PATIENT RECORD                            *|\n");
    printf("\t |***********************************************************************|\n");

    uint32_t counter = 0;
    uint32_t patient_counter = 0;

    while(counter < 20)
    {
        while(hashtable->list_table[counter]->head != NULL)
        {
            person_t *curent_person = hashtable->list_table[counter]->head->data->PersonData;

            printf("\n [%d] Patient_ID: %d", patient_counter, curent_person->SystemID);
            printf("\n [%d] Patient_FirstName: %s", patient_counter, curent_person->PersonFirstName);
            printf("\n [%d] Patient_LastName: %s", patient_counter, curent_person->PersonLastName);
            printf("\n [%d] Patient_Age: %s", patient_counter, curent_person->PersonAge);
            printf("\n [%d] Patient_Email: %s", patient_counter, curent_person->PersonEmail);
            printf("\n [%d] Patient_Password: %s", patient_counter, curent_person->PersonPassword);
            printf("\n [%d] Patient_PhoneNumber: %s", patient_counter, curent_person->PersonPhoneNumber);
            printf("\n [%d] Patient_JobTitle: %s", patient_counter, curent_person->PersonJobTitle);
            printf("\n [%d] Patient_Salary: %s", patient_counter, curent_person->PersonSalary);
            printf("\n [%d] Patient_WorkHours: %s", patient_counter, curent_person->PersonWorkHours);
            printf("\n [%d] Patient_ReserveFlag: %d", patient_counter, curent_person->FLAG_Doctor_Reserved);
            printf("\n [%d] Patient_Slot: %d", patient_counter, curent_person->PersonWorkHours);

            patient_counter++;
            hashtable->list_table[counter]->head = hashtable->list_table[counter]->head->next;
        }
        printf("\n");
        counter++;
    }

    return SUCCESS;
}/** @end patient_record */

/**
 * @brief Function to view the today reservations.
 * 
 * @return error_t 
 */
static error_t patient_reservations(hash_t *hashtable)
{
    /* Erro handler */
    dp_validity(hashtable);

    system("cls");

    printf("\t |***********************************************************************|\n");
    printf("\t |*                          PATIENT RESERVATIONS                       *|\n");
    printf("\t |***********************************************************************|\n");

    uint32_t counter = 0;

    printf("\n today's's reservations \n");

    while(counter < hashtable->maxsize)
    {
        while(hashtable->list_table[counter]->head != NULL)
        {
            person_t *curent_person = hashtable->list_table[counter]->head->data->PersonData;

            if( (curent_person->FLAG_Doctor_Reserved) )
            {
                printf("\n Person_SystemID: %d -- Reservation slot: %s", curent_person->SystemID,
                                                                         curent_person->reserved_slot);

                hashtable->list_table[counter]->head = hashtable->list_table[counter]->head->next;
            }
        }
        printf("\n");
        counter++;
    }

    return SUCCESS;
}/** @end patient_reservations */
