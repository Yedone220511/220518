#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = { 'a', 'b', 'c' };
//	printf("%d\n", sizeof(arr1)); //所占空间为4个字节（含\0有4个元素，每个元素类型为char，占1个字节)
//	printf("%d\n", sizeof(arr2)); //所占空间为3个字节（没有\0）
//	printf("%d\n", strlen(arr1)); //字符串长度为3（\0不计算长度）
//	printf("%d\n", strlen(arr2)); //随机值，因为strlen是要计算到\0前一位，但arr2里没有\0
//	return 0;
//}





//int main()
//{
//	char arr[] = "abcdef";
//	int i = 0;
//  int len=strlen(arr)
//	for (i = 0; i < len; i++)
//	{
//		printf("%c\n", arr[i]);
//	}
//	printf("%d\n", 'h');
//	return 0;
//}





//int main() //研究一维数组里元素是怎么存储的
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]); //计算元素个数
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]); //打印出每个元素的地址，结果为16进制，相邻两个直接相差4，因为每个整型元素占4个字节，说明数组里的元素是连续相邻存储起来的
//	}
//	return 0;
//}





//二维数组：
//int main()
//{
//	//int arr[3][4] = { {1，2，3}，{4，5} }; //创建一个3行4列的数组，第一行为1，2，3，0，第二行为4，5，0，0，第三行都为0
//	//int arr[][] = { {}.{} }; // [][]这里行可以省略，列不能省略，如果都省略，{}里要用{}表明有几列
//	int arr[3][4] = { {1,2,3}, {4,5} };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);  
//		}
//		printf("\n"); //每一行结束换行
//	}
//	return 0;
//}





//int main() //研究二维数组里的元素是怎么存储的
//{
//	int arr[3][4] = { {1,2,3}, {4,5} };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%p ", &arr[i][j]); //打印每个元素的地址，结果为16进制每个元素是连续存储的，存储完第一行再存储第二行
//		}
//		printf("\n"); //每一行结束换行
//	}
//	return 0;
//}





//注意：把数组传入函数做参数，不能在函数内部计算数组元素的个数，要先把元素个数算出来，再以参数形式传进函数使用
//void bubble_sort(int arr[], int sz) //通过函数把数组的元素排序，从小到大
//{
//	int i = 0;
//	int k = 0;
//	for (k = 1; k < sz; k++)
//	{
//		int flag = 1; //每一趟走之前先把flag设置为1，如果第一趟过程中发生里交换，flag变为0
//		for (i = 0; i < sz-k; i++) //为什么设置i<sz-k，第k趟结束，最后k个数已经排好顺序了，只要排到sz-k之前就好了
//		{
//			if (arr[i] > arr[i+1])
//			{
//				int n = arr[i];
//				arr[i] = arr[i+1];
//				arr[i+1] = n;
//				flag = 0; 
//			}
//		}
//		if (flag == 1) //每走一趟，如果flag还是1，说明没有发生交换，顺序本就是达标的，那就不必走第二趟，直接跳出
//		{
//			break;
//		}
//	}
//	
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int a = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (a = 0; a < sz; a++)
//	{
//		printf("%d ", arr[a]);
//	}
//	return 0;
//}




//除了下面2个特例之外，数组名都表示首元素的地址
//1. sizeof(数组名)，这里的数组名表示整个数组
//2. &数组名，这里的数组名表示整个数组
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	printf("%p\n", arr);     //取出的是首元素的地址
	printf("%p\n", arr+1);
	printf("%p\n", &arr[0]); //取出的也是首元素的地址
	printf("%p\n", &arr[0]+1); //打印出来跟上面的+1是一样的
	printf("%p\n", &arr); //取出的是整个数组的地址，跟上面是一样的，说明整个数组的地址跟首元素的地址的值是相等的
	printf("%p\n", &arr+1); //打印出来跟上面的+1就不一致了，实际是整个数组结束之后的地址
	return 0;
}