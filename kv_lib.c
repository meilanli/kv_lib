/*
*2020-12-24		meilanli
*/
#include "kv_lib.h"

struct KeyValueLibStruct
{
  key_size_t key;
  value_size_t value;
  struct KeyValueLibStruct *next;
};

#if KV_LIB_COUNT_EN
static kv_uint32_t s_kv_num=0;
#endif
static struct KeyValueLibStruct *s_kv_head = KV_NULL;

//设置键值，没有则新增
KvEnum kv_lib_set(key_size_t key, value_size_t value)
{
    struct KeyValueLibStruct *p_kv,*prev;
    
    //如果kv数据库没有建立
    if(s_kv_head == KV_NULL)
    {
        s_kv_head = kv_malloc(sizeof(struct KeyValueLibStruct));
        if( s_kv_head == KV_NULL )
        {
            return KV_NO_MEMORY;
        }
        s_kv_head->key = key;
        s_kv_head->value = value;
        s_kv_head->next = KV_NULL;
        #if KV_LIB_COUNT_EN
        s_kv_num++;
        #endif
        return KV_SUCCESS;
    }
    
    //查找对应键值
    p_kv = s_kv_head;
    while(p_kv)
    {
        if( p_kv->key == key )
        {
            p_kv->value = value;
            return KV_SUCCESS;
        }
        prev = p_kv;
        p_kv = prev->next;
    }
    
    //没有找到，尾部新增键值
    prev->next = kv_malloc(sizeof(struct KeyValueLibStruct));
    if( prev->next == KV_NULL )
    {
        return KV_NO_MEMORY;
    }
    prev->next->key = key;
    prev->next->value = value;
    prev->next->next = KV_NULL;
    #if KV_LIB_COUNT_EN
    s_kv_num++;
    #endif
    return KV_SUCCESS;
}

//获取键值
KvEnum kv_lib_get(key_size_t key, value_size_t *value)
{
    struct KeyValueLibStruct *p_kv;

    //查找对应键值
    p_kv = s_kv_head;
    while(p_kv)
    {
        if( p_kv->key == key )
        {
            *value = p_kv->value;
            return KV_SUCCESS;
        }
        p_kv = p_kv->next;
    }
    
    //没有找到
    return KV_NO_KEY;
}

//删除键值
KvEnum kv_lib_del(key_size_t key)
{
    struct KeyValueLibStruct *p_kv,*prev;

    //查找对应键值
    p_kv = s_kv_head;
    prev = s_kv_head;
    
    while(p_kv)
    {
        if( p_kv->key == key )
        {
            if( p_kv == s_kv_head )
            {
                s_kv_head = p_kv->next;
            }
            else
            {
                prev->next = p_kv->next;
            }
            kv_free(p_kv);
            #if KV_LIB_COUNT_EN
            s_kv_num--;
            #endif
            return KV_SUCCESS;
        }
        prev = p_kv;
        p_kv = p_kv->next;
    }
    
    //没有找到
    return KV_NO_KEY;
}

#if KV_LIB_COUNT_EN
kv_uint32_t kv_lib_get_num(void)
{
    return s_kv_num;
}
#endif
