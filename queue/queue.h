#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "../common/common.h"

/// @struct node_t
/// @brief 큐의 노드 역할을 수행할 노드 구조체 
typedef struct node_s node_t;
struct node_s{
    /// 사용자 데이터 
    void* data;
    /// 이전 노드 
    struct node_s *prev;
    /// 다음 노드 
    struct node_s *next;
};

/// @struct queue_t
/// @brief 이중 연결 리스트로 구현될 큐 구조체 
typedef struct queue_s queue_t;
struct queue_s{
    /// 큐의 맨 앞 노드 (더미)
    node_t front[ 1];
    /// 큐의 맨 뒤 노드 (더미)
    node_t rear[ 1];
    /// 큐의 길이 
    int count;
};

queue_t* queue_create();
void queue_destroy( queue_t *queue);
int queue_enqueue( queue_t *queue, void* data);
int queue_dequeue( queue_t *queue);
void* queue_get_front_data( queue_t *queue);
int queue_is_empty( queue_t *queue);
int queue_get_length( queue_t *queue);

#endif
