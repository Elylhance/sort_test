// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

extern "C"
{
	/* �����㷨 */
#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
#define SORT_DATA_LENGTH  200000
	int rand_data[SORT_DATA_LENGTH] = { 0 };
	int sorted_data[SORT_DATA_LENGTH] = { 0 };

	void generate_input_rand_data()
	{
		srand((unsigned)time(NULL));
		for (int i = 0; i < SORT_DATA_LENGTH; i++)
		{
			rand_data[i] = rand() % 100000;
		}
	}

	void print_data(int* data, int length)
	{
		for (int i = 0; i < length; i++)
			printf("%5d", data[i]);
		printf("\n");
	}

	//ð������
	void bubble_sort()
	{
		int i, j, tmp;
		printf("Bubble data:");
		generate_input_rand_data();
		//print_data(rand_data, SORT_DATA_LENGTH);
		for (i = 0; i < SORT_DATA_LENGTH - 1; i++)
		{
			for (j = 0; j < SORT_DATA_LENGTH - i - 1; j++)
			{
				if (rand_data[j] > rand_data[j + 1])
				{
					tmp = rand_data[j];
					rand_data[j] = rand_data[j + 1];
					rand_data[j + 1] = tmp;
				}
			}
		}
		printf("Softed data:");
		//print_data(rand_data, SORT_DATA_LENGTH);
	}
	//��������
	void insert_sort()
	{
		int i, j, tmp;
		printf("Insert data:");
		generate_input_rand_data();
		//print_data(rand_data, SORT_DATA_LENGTH);
		//rand_data
		for (i = 1; i < SORT_DATA_LENGTH; i++)
		{
			tmp = rand_data[i];
			j = i;
			while (j > 0 && tmp < rand_data[j - 1])
			{
				rand_data[j] = rand_data[j - 1];
				rand_data[j - 1] = tmp;
				tmp = rand_data[--j];
			}
		}
		printf("Softed data:");
		//print_data(rand_data, SORT_DATA_LENGTH);
	}
	//�۰루���ַ�����������:
	//�������һ�������в�������A�����ҵ�����A���ڵ�λ�ã��ٽ�����A�������������Ųһ��λ�ã��ٲ���A
	void binary_insertion_sort()
	{
		int i, j, tmp, low, high, mid;
		printf("Bin-insert data:");
		generate_input_rand_data();
		//print_data(rand_data, SORT_DATA_LENGTH);
		//rand_data
		for (i = 1; i < SORT_DATA_LENGTH; i++)
		{
			tmp = rand_data[i];
			j = i;
			low = 0; high = i;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (rand_data[i] > rand_data[mid])
					low = mid + 1;
				else
					high = mid - 1;
			}

			tmp = rand_data[i];
			for (j = i; j > low; j--)
			{
				rand_data[j] = rand_data[j - 1];
			}
			rand_data[low] = tmp;
		}
		printf("Softed data:");
		//print_data(rand_data, SORT_DATA_LENGTH);
	}
	//** ��������--�ݹ鷨
	void quick_sort_recu(int* num, int low, int high)
	{
		int tmp, start, end;
		if (low < high)	//�ݹ�������������һ�֣���ʼ���ؽ��
		{
			tmp = num[low];		//ȡ����һ��Ԫ�أ��ճ�λ��A
			start = low;
			end = high;
			while (low < high)
			{
				while (low < high && num[high] >= tmp) high--;	//������ұȵ�һ��Ԫ��С��ֵ���ŵ�λ��A�����ճ�һ��λ��B...���������һ��С��ֵ����C...
				num[low] = num[high];
				while (low < high && num[low] <= tmp) low++;    //˳����ұȵ�һ��Ԫ�ش��ֵ���ŵ�λ��B���ճ�λ��C...
				num[high] = num[low];
			}
			num[low] = tmp;//��ʱlow����high.�ѵ�һ��Ԫ�ط����λ��
			//�ݹ������С��tmp�����ݣ�start��low-1��ִ�����ϲ���
			quick_sort_recu(num, start, low - 1);
			//�ݹ�����д���tmp�����ݣ�low + 1��end��ִ�����ϲ���
			quick_sort_recu(num, low + 1, end);
		}
	}
	void quick_sort()
	{
		printf("Fast sort data:");
		generate_input_rand_data();
		//print_data(rand_data, SORT_DATA_LENGTH);
		//sort
		quick_sort_recu(rand_data, 0, SORT_DATA_LENGTH - 1);

		printf("sort data:");
		//print_data(rand_data, SORT_DATA_LENGTH);
	}
	//�鲢����
	void MergeArray(int* input, int start, int mid, int end, int* output)/* 2����������ϲ� */
	{
		/* 
		num[start...mid];
		num[mid+1...end];
		*/
		int i = 0, j = start;
		int mid_t = mid + 1;
		int k;
		while (start <= mid && mid_t <= end)
		{
			if (input[start] <= input[mid_t])
				output[i++] = input[start++];
			else
				output[i++] = input[mid_t++];
		}
		while (start <= mid)
			output[i++] = input[start++];
		while (mid_t <= end)
			output[i++] = input[mid_t++];
		
		for (k = 0;k < i; k++)
		{
			input[j++] = output[k];
		}
	}
	void MergerSort(int* input, int start,int end, int* output)
	{
		int mid = 0;
		if (start < end)
		{
			mid = (start + end) / 2;
			MergerSort(input, start, mid, output);
			MergerSort(input, mid+1, end, output);
			MergeArray(input, start, mid, end, output);
		}
	}
	void merger_sort(void)
	{
		printf("Merger sort data:");
		generate_input_rand_data();
		//print_data(rand_data, SORT_DATA_LENGTH);
		MergerSort(rand_data, 0, SORT_DATA_LENGTH - 1, sorted_data);

		printf("sort data:");
		//print_data(rand_data, SORT_DATA_LENGTH);
	}
}

void main(int argc, void** argv)
{
	int t1, t2;
	t1 = clock();
	bubble_sort();
	t2 = clock();
	printf("spent time: %d\n", t2 - t1);

	t1 = clock();
	insert_sort();
	t2 = clock();
	printf("spent time: %d\n", t2 - t1);

	t1 = clock();
	binary_insertion_sort();
	t2 = clock();
	printf("spent time: %d\n", t2 - t1);

	t1 = clock();
	quick_sort();
	t2 = clock();
	printf("spent time: %d\n", t2 - t1);

	t1 = clock();
	merger_sort();
	t2 = clock();
	printf("spent time: %d\n", t2 - t1);
	return;
}


