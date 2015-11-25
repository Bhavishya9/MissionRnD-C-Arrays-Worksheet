/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	if (students->name==NULL|| len <1)
		return NULL;
	else
	{
		struct student temp;
		for (int index = 0; index < len-1; index++)
		{
			for (int index1 = 0; index1 < len - index - 1; index1++)
			{
				if (students[index1].score < students[index1 + 1].score)
				{
					temp = students[index1];
					students[index1] = students[index1 + 1];
					students[index1 + 1] = temp;

				}
			}
		}
	}
}