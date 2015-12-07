/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	if (students->name == NULL || len < 1 || K < 1)
		return NULL;
	else
	{
		struct student temp;
		for (int index = 0; index < len; index++)
		{
			for (int index1 = index + 1; index1 < len; index1++)
			{
				if (students[index].score > students[index1].score)
				{
					temp = students[index1];
					students[index1] = students[index];
					students[index] = temp;

				}
			}
		}
		if (K > len)
		{
			struct student **result = (struct student**)malloc(len*sizeof(struct student));
			for (int index = 0; index < len; index++)
				result[index] = &students[index];

			return result;
		}
		else
		{
			int count = 0;
			struct student **result = (struct student **)malloc(K*sizeof(struct student));
			for (int index = len - K; index < len; index++)
			{
				result[count] = &students[index];
				count++;
			}
			return result;
		}
	}
}
