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
		for (int index = 0; index < len - 1; index++)
		{
			for (int index1 = 0; index1 < len - index - 1; index1++)
			{
				if (students[index1].score > students[index1 + 1].score)
				{
					temp = students[index1];
					students[index1] = students[index1 + 1];
					students[index1 + 1] = temp;

				}
			}
		}
		int index1 = len - K;
		int count = 0;
		//struct student *arr;
		//arr = *&students;
		if (K > len)
		{
			return &students;
		}
		/*while (count < K)
		{
			arr = students[index1];
			index1++;
			count++;
			//return arr;

		}*/
	}
}