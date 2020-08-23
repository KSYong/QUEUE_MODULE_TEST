#include "queue.h"

// --------------------------------------------

/**
 * @fn static node_t* node_create( void* data)
 * @brief node 객체를 생성하는 함수
 * @return 생성된 node 객체
 * @param data 생성될 node 객체 안의 사용자 data
 */
static node_t* node_create( void* data){
    node_t *node = ( node_t*)malloc( sizeof( node_t));
    if( node == NULL){
        printf("    | ! Queue : Failed to create node object in node_create!\n");
        return OBJECT_ERR;
    }

    memset( node, '\0', sizeof( node));

    node->prev = NULL;
    node->next = NULL;
    node->data = data;
    return node;
}

/**
 * @fn static void node_destroy( node_t *target){
 * @brief node 객체를 삭제하는 함수 
 * @return void
 * @param target 삭제할 node 객체
 */
static void node_destroy( node_t *target){
    if( target){
        target->prev = NULL;
        target->next = NULL;
        target->data = NULL;
        free( target);
    }
    else{
        printf("    | ! Queue : Failed to call target object in node_destroy!\n");
        return OBJECT_ERR;
    }
}

// -------------------------------------------

/**
 * @fn queue_t* queue_create()
 * @brief 큐 객체를 생성하는 함수
 * @return 생성된 큐 객체
 */
queue_t* queue_create(){
    queue_t *queue = ( queue_t*)malloc( sizeof( queue_t));
    if( queue == NULL){
        printf("    | ! Queue : Failed to create queue object in queue_create!\n");
        return OBJECT_ERR;
    }

    queue->front->data = NULL;
    queue->front->prev = NULL;
    queue->front->next = queue->rear;

    queue->rear->data = NULL;
    queue->rear->prev = queue->front;
    queue->rear->next = NULL;

    queue->length = 0;

    return queue;
}

/**
 * @fn void queue_destroy( queue_t *queue)
 * @brief 생성된 큐 객체를 삭제하는 함수
 * @return void
 * @param queue 삭제할 큐 객체 
 */
void queue_destroy( queue_t *queue){
    if( queue){
        node_t *temp_node = queue->front;
        node_t *rear = queue->rear;

        while( temp_node != rear){
            queue_dequeue( queue);
            temp_node = temp_node->next;
        }

        memset( queue, '\0', sizeof( queue));
        free( queue);
    }
    else{
        printf("    | ! Queue : Object call failed in queue_destroy\n");
        return OBJECT_ERR;
    }
}

/**
 * @fn int queue_enqueue( queue_t *queue, void* data)
 * @brief 큐에 새로운 데이터를 enqueue 하는 함수
 * @return 에러 열거형 참고
 * @param queue 새로운 데이터를 enqueue 할 큐 객체
 * @param data 추가할 새로운 사용자 데이터 
 */
int queue_enqueue( queue_t *queue, void* data){
    if( queue){
        node_t *newnode = node_create( data);
        node_t *front = queue->front;
        node_t *rear = queue->rear;

        if( queue_is_empty(queue)){
            front->next = newnode;
            rear->prev = newnode;

            newnode->prev = front;
            newnode->next = rear;
        }
        else{
            node_t* temp_node = rear->prev;

            temp_node->next = newnode;
            rear->prev = newnode;

            newnode->prev = temp_node;
            newnode->next = rear;
        }
        queue->length++;
    }
    else{
        printf("    | ! Queue : Object call failed in queue_enqueue\n");
        return OBJECT_ERR;
    }
}

/**
 * @fn int queue_dequeue( queue_t *queue)
 * @brief 큐에서 자료를 dequeue하는 함수 
 * @return 에러 열거형 참고
 * @param queue 자료를 dequeue할 큐 객체 
 */
int queue_dequeue( queue_t *queue){
    if( queue){
        node_t *front = queue->front;
        node_t *rear = queue->rear;
        node_t *temp_node = queue->front->next;

        if ( queue_is_empty( queue)){
            printf("    | ! Queue: Error : queue is empty! can't dequeue\n");
            return IS_EMPTY;
        }

        front->next = temp_node->next;
        temp_node->next->prev = front;

        temp_node->next = NULL;
        temp_node->prev = NULL;

        free( temp_node);

        queue->length--;

        printf("    | @ Queue : Dequeue success!\n");
    }
    else{
        printf("    | ! Queue : Object call failed in queue_dequeue\n");
        return OBJECT_ERR;
    }
}

/**
 * @fn int queue_get_front_data( queue_t *queue)
 * @brief 큐에서 가장 앞의(front) 자료를 가져오는 함수
 * @return 에러 열거형 참고
 * @param queue 자료를 가져올 큐 객체 
 */
void* queue_get_front_data( queue_t *queue){
    if( queue){
        return queue->front->next->data;
    }
    else{
        printf("    | ! Queue : Object call failed in queue_get_front_data\n");
        return OBJECT_ERR;
    }
}


/**
 * @fn int queue_is_empty( queue_t *queue)
 * @brief 큐가 비어있는지 확인하는 함수
 * @return 큐가 비어있다면 참, 그렇지 않다면 거짓을 반환한다
 * @param queue 비어있음을 판단할 큐 객체
 */
int queue_is_empty( queue_t *queue){
    if( queue){
        return queue->length == 0;
    }
    else{
        printf("    | ! Queue : Object call failed in queue_is_empty\n");
        return OBJECT_ERR;
    }
}

/**
 * @fn int queue_get_length( queue_t *queue)
 * @brief 큐의 길이를 반환하는 함수 
 * @return 큐의 길이 
 * @param queue 길이를 반환할 큐 객체 
 */
int queue_get_length( queue_t *queue){
    if( queue){
        return queue->length;
    }
    else{
        printf("    | ! Queue : Object call failed in queue_get_length\n");
        return OBJECT_ERR;
    }
}
