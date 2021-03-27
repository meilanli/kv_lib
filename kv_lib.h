#ifndef __KV_LIB_H
#define __KV_LIB_H
#include "stddef.h"
#include "stdint.h"

//-------------config-start-----------//
#define KV_LIB_COUNT_EN       1     //使能键值对计数

#include "mem_heap.h"
#define kv_malloc(size)       heap_malloc(size) //分配内存
#define kv_free(p)            heap_free(p)      //释放内存
#define KV_NULL               NULL      //空指针

#define key_size_t            uint32_t      //键类型
#define value_size_t          uint32_t      //值类型

#define kv_uint8_t            uint8_t
#define kv_uint16_t           uint16_t
#define kv_uint32_t           uint32_t
//-------------config--end-----------//

typedef enum
{
    KV_SUCCESS=0,   //成功
    KV_ERROR=-1,    //错误
    KV_NO_MEMORY=-2,    //内存分配失败
    KV_NO_KEY=-3,       //没有这个键
}KvEnum;

//设置键值，没有则新增
KvEnum kv_lib_set(key_size_t key, value_size_t value);

//获取键值
KvEnum kv_lib_get(key_size_t key, value_size_t *value);

//删除键值
KvEnum kv_lib_del(key_size_t key);

//不能存在相同key，所以没有单独新增键值的接口

#if KV_LIB_COUNT_EN
//获取键值对数量
kv_uint32_t kv_lib_get_num(void);
#endif

#endif
