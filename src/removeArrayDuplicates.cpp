/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len < 1)
		return NULL;
	else
	{
		int freq[10] = { 0 };
		int flag = 0, flag1 = 0;
		for (int index = 0; index < len-1; index++)
		{
			if (Arr[index] < Arr[index + 1])
				flag = 1;
			else if (Arr[index]>Arr[index + 1])
				flag = 2;
			else
				flag = 0;
			if (flag != 0)
				break;
		}
		if (flag == 1)
		{
			for (int index = 0; index < len - 1; index++)
			{
				if (Arr[index] <= Arr[index + 1])
					continue;
				else
				{
					flag1 = 1;
					break;
				}
			}
		}
		else if (flag==2)
		{
			for (int index = 0; index < len - 1; index++)
			{
				if (Arr[index] >= Arr[index + 1])
					continue;
				else
				{
					flag1 = 1;
					break;
				}
			}
		}
		if (flag1 == 1)
		{
			for (int index = 0; index < len; index++)
			{
				if (freq[Arr[index]] != 0)
				{
					Arr[index] = NULL;
				}
				else
					freq[Arr[index]] = 1;
			}
			int index1 = 0, index2 = len - 1;
			while (1)
			{
				while (Arr[index2] == NULL)
				{
					index2--;
				}
				while (Arr[index1] != NULL)
				{
					index1++;
				}
				if (index1 < index2)
				{
					int temp = Arr[index1];
					Arr[index1] = Arr[index2];
					Arr[index2] = temp;
				}
				else
					break;
			}
		}
		else
		{
			int index1 = 0;
			for (int index = 0; index < len; index++)
			{
				freq[Arr[index]]++;
			}
			for (int index = 0; index < 10; index++)
			{
				if (freq[index] != 0)
				{
					Arr[index1] = index;
					index1++;
				}

			}
		}

	}
}
