#include "queue.h"

int main( int argc, char **argv){
    printf("*** @@ Queue Test @@ ***\n\n");

    int rv;
    queue_t *queue;

    queue = queue_create();
    if( queue == NULL){
        printf("    | ! Failed to create queue obejct!\n");
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
        printf("    | @ Success to enqueue\n");
    }

    rv = queue_get_front_data( queue);
    if( rv < NORMAL){
        printf("    | ! Failed to get front data, (rv : %d)\n", rv);
        return rv;
    }
    else{
        printf("    | @ Success to get front data! (data : %d)\n", rv);
    }

    rv = queue_get_length( queue);
    if( rv < NORMAL){
        printf("    | ! Failed to get queue length\n");
        return rv;
    }
    else{
        printf("    | @ Success to get queue length1 ( length : %d)\n", rv);
    }
    
    rv = queue_dequeue( queue);
    if( rv < NORMAL){
        printf("    | ! Failed to dqueue!\n");
        return rv;
    }
    else{
        printf("    | @ Success to dequeue\n");
    }

    queue_destroy( queue);

    printf("\n*** @@ test complete! @@@\n\n");
}

