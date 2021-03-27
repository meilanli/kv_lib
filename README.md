#kv_lib

## 1、介绍
	1.动态链表结构的Key-Value数据库
	2.key在数据库中必须唯一，value可以相同
	3.存储位置:RAM
	4.扩展使用:key、value都可以用来存储指针
	5.依赖: 内存管理(malloc,free)

## 2、配置kv_lib.h:
	配置malloc和free函数
	配置数据类型
	
## 3、接口API:
	kv_lib_set	设置键值，没有则新增
	kv_lib_get	获取键值
	kv_lib_del	删除键值
	kv_lib_get_num	获取键值对数量