#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/// @enum ERROR
/// @brief 각종 프로그램 에러들의 열거형
enum ERROR{
    NORMAL = 0,
    OBJECT_ERR = -1,
    IS_EMPTY = -2,
    UNKNOWN = -9
};

#endif
