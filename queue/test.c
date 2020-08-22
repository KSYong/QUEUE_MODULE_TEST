#include "queue.h"

/**
 * @fn int main( int argc, char **argv)
 * @brief queue 모듈을 테스트하는 메인 함수
 * @return 에러 열거형 참고 
 */
int main( int argc, char **argv){
    printf("*** @ queue test @ ***\n\n");

    int rv;
    queue_t *queue;

    queue = queue_create();
    if( queue == NULL){
        printf("    | ! Failed to create queue object!\n");
        return OBJECT_ERR;
    }
    else{
        printf("    | @ Success to create queue object\n");
    }

    rv = queue_enqueue( queue, 1);
    if( rv < NORMAL){
        printf("    | ! Failed to enqueue!\n");
        return rv;
    }
    else{
        printf("    | @ Success to enqueue! (data : 1)\n");
    }

    rv = queue_is_empty( queue);
    if( rv){
        printf("    | ! Failed to determine empty or not\n");
        return IS_EMPTY;
    }
    else{
        printf("    | @ Success to determine is_empty (queue is not empty)\n");
    }

    rv = queue_get_front_data( queue);
    if( rv < NORMAL){
        printf("    | ! Failed to get front data\n");
        return rv;
    }
    else{
        printf("    | @ Success to get front data! (data : %d)\n", (int)rv);
    }

    rv = queue_dequeue( queue);
    if( rv < NORMAL){
        printf("    | ! Failed to dequeue!\n");
        return rv;
    }
    else{
        printf("    | @ Success to dequeue!\n");
    }

    rv = queue_is_empty( queue);
    if( !rv){
        printf("    | ! Failed to determine empty or not\n");
        return IS_EMPTY;
    }
    else{
        printf("    | @ Success to determine is_empty (queue is empty)\n");
    }
    
    queue_destroy( queue);
    
    printf("\n@@@@ test complete @@@@\n\n");
}




