#include "queue.h"

// ---------------------------------

/**
 * @fn static node_t* node_create( void *data)
 * @brief 큐를 구성하는 노드 구조체를 생성하는 함수 
 * @param data 노드가 가질 사용자 데이터 
 * @return 생성된 노드 구조체 
 */
static node_t* node_create( void *data){
    node_t* node = ( node_t*)malloc( sizeof( node_t));
    if( node == NULL){
        printf("    | ! Queue : Failed to create node object in node_create!\n");
        return OBJECT_ERR;
    }

    memset( node, '\0', sizeof( node));

    node->next = NULL;
    node->data = data;
    return node;
}

/**
 * @fn static void node_destroy( node_t *target)
 * @brief 생성된 노드 구조체를 삭제하는 함수 
 * @param target 삭제할 노드 구조체 
 * @return void
 */
static void node_destroy( node_t *target){
    if( target){
        target->next = NULL;
        target->data = NULL;
        free( target);
    }
    else{
        printf("    | ! Queue : Failed to call target object in node_destroy!\n");
        return OBJECT_ERR;
    }
}

// ------------------------------------

/**
 * @fn queue_t* queue_create()
 * @brief 큐 구조체를 생성하는 함수 
 * @return 생성된 큐 구조체
 */
queue_t* queue_create(){
    queue_t *queue = ( queue_t*)malloc( sizeof( queue_t));
    if( queue == NULL){
        printf("    | ! Queue : Failed to create queue object in queue_create!\n");
        return OBJECT_ERR;
    }

    queue->front = queue->rear = NULL;

    queue->length = 0;

    return queue;
}

/**
 * @fn void queue_destroy( queue_t *queue)
 * @brief 큐 구조체를 삭제하는 함수 
 * @param queue 삭제할 큐 구조체 
 * @return void
 */
void queue_destroy( queue_t *queue){
    if( queue){
        node_t *temp_node = queue->front;
        node_t *rear = queue->rear;

        int i;
        for( i = 0; i < queue->length; i++){
            queue_dequeue( queue);
        }

        memset( queue, '\0', sizeof( queue));
        free( queue);
    }
    else{
        printf("    | ! Queue : Failed to call object in queue_destroy\n");
        return OBJECT_ERR;
    }
}

/**
 * @fn int queue_enqueue( queue_t *queue, void *data)
 * @brief 큐의 제일 뒤에 데이터를 추가하는 함수 
 * @param queue 데이터를 추가할 큐 구조체 
 * @param data 추가할 사용자 데이터 
 * @return int 에러 열거형 참고 
 */
int queue_enqueue( queue_t *queue, void *data){
    if( queue){
        node_t *newnode = node_create( data);

        if( queue->rear == NULL){
            queue->front = queue->rear = newnode;
        }
        else{
            queue->rear->next = newnode;
            queue->rear = newnode;
        }
        queue->length++;

        return NORMAL;
    }
    else{
        printf("    | ! Queue : Failed to call object in queue_enqueue\n");
        return OBJECT_ERR;
    }
}

/**
 * @fn int queue_dequeue( queue_t *queue)
 * @brief 큐에서 제일 앞 데이터를 삭제하는 함수 
 * @param queue 데이터를 삭제할 큐 구조체 
 * @return 에러 열거형 참고 
 */
int queue_dequeue( queue_t *queue){
    if( queue){
        node_t *front = queue->front;
        node_t *rear = queue->rear;
        node_t *temp_node = queue->front;
        
        if( front == NULL){
            return IS_EMPTY;
        }
        else{
            front = front->next;

            if( front = NULL){
                rear = NULL;
            }

            node_destroy( temp_node);

            queue->length--;

            return NORMAL;
        }
    }
    else{
        printf("    | ! Queue : Failed to call object in queue_dequeue\n");
        return OBJECT_ERR;
    }
}

/**
 * @fn void* queue_get_front_data( queue_t *queue)
 * @brief 큐의 제일 앞 노드의 데이터를 반환해주는 함수 
 * @param queue 데이터를 반환받을 큐 
 * @return void
 */
void* queue_get_front_data( queue_t *queue){
    if( queue){
        node_t *front = queue->front;
        
        if( front == NULL){
            printf(" front is NULL\n");
            return IS_EMPTY;
        }
        else{
            return front->data;
        }
    }
    else{
        printf("    | ! Queue : Failed to call object in queue_get_front_data\n");
        return OBJECT_ERR;
    }
}

/**
 * @fn int queue_get_length( queue_t *queue)
 * @brief 큐의 길이를 반환하는 함수
 * @param queue 길이를 반환받을 큐
 * @return 에러 열거형 참고 
 */
int queue_get_length( queue_t *queue){
    if( queue){
        return queue->length;
    }
    else{
        printf("    | ! Queue : Failed to call object in queue_get_length\n");
        return OBJECT_ERR;
    }
}

        
