#ifndef __KV_LIB_H
#define __KV_LIB_H
#include "stddef.h"
#include "stdint.h"

//-------------config-start-----------//
#define KV_LIB_COUNT_EN       1     //ʹ�ܼ�ֵ�Լ���

#include "mem_heap.h"
#define kv_malloc(size)       heap_malloc(size) //�����ڴ�
#define kv_free(p)            heap_free(p)      //�ͷ��ڴ�
#define KV_NULL               NULL      //��ָ��

#define key_size_t            uint32_t      //������
#define value_size_t          uint32_t      //ֵ����

#define kv_uint8_t            uint8_t
#define kv_uint16_t           uint16_t
#define kv_uint32_t           uint32_t
//-------------config--end-----------//

typedef enum
{
    KV_SUCCESS=0,   //�ɹ�
    KV_ERROR=-1,    //����
    KV_NO_MEMORY=-2,    //�ڴ����ʧ��
    KV_NO_KEY=-3,       //û�������
}KvEnum;

//���ü�ֵ��û��������
KvEnum kv_lib_set(key_size_t key, value_size_t value);

//��ȡ��ֵ
KvEnum kv_lib_get(key_size_t key, value_size_t *value);

//ɾ����ֵ
KvEnum kv_lib_del(key_size_t key);

//���ܴ�����ͬkey������û�е���������ֵ�Ľӿ�

#if KV_LIB_COUNT_EN
//��ȡ��ֵ������
kv_uint32_t kv_lib_get_num(void);
#endif

#endif
