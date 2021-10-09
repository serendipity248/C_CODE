#define _CRT_SECURE_NO_WARNINGS


////malloc����ԭ��
//void* malloc(size_t sz);

////free����ԭ��
//void free(void* ptr);

////calloc����ԭ��
//void* calloc(size_t num, size_t size);

////realloc����ԭ��
//void* realloc(void* ptr, size_t size);


//# include <stdio.h>
//# include <stdlib.h>
//# include <malloc.h>
//
//int main(void)
//{
//	int* p = NULL;
//	p = (int*)malloc(20); //malloc���ص���void*����Ҫǿת����Ҫ������
//	//ʹ��
//	if (p == NULL)
//	{
//		printf("����ʧ��");
//	}
//	else
//	{
//		for (int i = 0; i < 10; i++)
//		{
//
//			*(p+i) = i; 
//		}
//	}
//	//ʹ����֮����Ҫ�ͷ�
//	free(p);
//	p = NULL; //�ͷ��˲��������ڣ��óɿ�ָ�룬��ֹ���Ұָ��
//	return 0;
//}


//# include <stdio.h>
//# include <stdlib.h>
//
//int main(void)
//{
//	int* p = NULL;
//	p = calloc(10, sizeof(int)); //Ϊ10��int�ֽڴ�С��Ԫ�ط����ڴ�ռ�
//	if (p == NULL)
//	{
//		printf("����ʧ��\n");
//	}
//	else
//	{
//		//ʹ��
//		for (int i = 0; i < 10; i++)
//		{
//			//���ڴ�ռ��ÿһ���ֽڶ���ʼ��Ϊ0,���Ի��ӡ10��0
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
		printf("�ڴ濪��ʧ�ܣ�\n");
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	//��p��ָ����ڴ�ռ��С��������30�ֽ�
	int* pf = (int*)realloc(p, 30);
	if (pf != NULL)
	{
		for (int i = 10; i < 20; i++)
		{
			*(pf + i) = i;
			printf("%d ", *(pf + i));
		}
	}
	//�ͷ�
	free(pf);
	pf = NULL;
	return 0;
}