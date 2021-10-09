#define _CRT_SECURE_NO_WARNINGS


////malloc函数原型
//void* malloc(size_t sz);

////free函数原型
//void free(void* ptr);

////calloc函数原型
//void* calloc(size_t num, size_t size);

////realloc函数原型
//void* realloc(void* ptr, size_t size);


//# include <stdio.h>
//# include <stdlib.h>
//# include <malloc.h>
//
//int main(void)
//{
//	int* p = NULL;
//	p = (int*)malloc(20); //malloc返回的是void*，需要强转成需要的类型
//	//使用
//	if (p == NULL)
//	{
//		printf("开辟失败");
//	}
//	else
//	{
//		for (int i = 0; i < 10; i++)
//		{
//
//			*(p+i) = i; 
//		}
//	}
//	//使用完之后需要释放
//	free(p);
//	p = NULL; //释放了并不代表不在，置成空指针，防止变成野指针
//	return 0;
//}


//# include <stdio.h>
//# include <stdlib.h>
//
//int main(void)
//{
//	int* p = NULL;
//	p = calloc(10, sizeof(int)); //为10个int字节大小的元素分配内存空间
//	if (p == NULL)
//	{
//		printf("开辟失败\n");
//	}
//	else
//	{
//		//使用
//		for (int i = 0; i < 10; i++)
//		{
//			//将内存空间的每一个字节都初始化为0,所以会打印10个0
//			printf("%d ", *(p + i));
//		}
//
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}



# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

int main(void)
{
	int* p = NULL;
	p = (int*)malloc(10);
	if (p == NULL)
	{
		printf("内存开辟失败！\n");
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	//将p所指向的内存空间大小，调整到30字节
	int* pf = (int*)realloc(p, 30);
	if (pf != NULL)
	{
		for (int i = 10; i < 20; i++)
		{
			*(pf + i) = i;
			printf("%d ", *(pf + i));
		}
	}
	//释放
	free(pf);
	pf = NULL;
	return 0;
}