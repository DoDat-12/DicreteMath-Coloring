#include <stdio.h>
#include <string.h>

int main()
{
	int numOfVertices, numOfEdges;
	// Read File
	FILE *fptr;
	fptr = fopen("DoThi01.txt", "r");
	fscanf(fptr, "%d", &numOfVertices);
	fscanf(fptr, "%d", &numOfEdges);
	int tree[2][numOfEdges + 1];
	for (int i = 1; i <= numOfEdges; i++)
	{
		fscanf(fptr, "%d", &tree[0][i]);
		fscanf(fptr, "%d", &tree[1][i]);
	}
	fclose(fptr);

	// Degree Counting Each Label
	int degree[numOfVertices + 1] = {0};
	for (int i = 1; i <= numOfVertices; i++)
	{
		for (int j = 1; j <= numOfEdges; j++)
		{
			if (tree[0][j] == i || tree[1][j] == i)
				degree[i] += 1;
		}
	}
	// Numbered Each Label
	int STT[numOfVertices + 1] = {0};
	int count = 0;
	for (int i = numOfEdges; i >= 1; i--)
	{
		for (int j = 1; j <= numOfVertices; j++)
		{
			if (degree[j] == i && STT[j] == 0)
			{
				STT[j] = count + 1;
				count += 1;
			}
		}
	}

	// Painting Tree
	char colorList[10][100] = {"green", "red", "yellow", "blue", "purple", "gray", "pink", "orange", "cyan", "brown"};
	char colorLabel[numOfVertices + 1][100];
	int colored[numOfVertices + 1] = {0};

	for (int i = 1; i <= numOfVertices; i++)
	{
		for (int j = 1; j <= numOfVertices; j++)
		{
			if (STT[j] == i)
			{
				int a = 0;
				for (int k = 1; k <= numOfEdges; k++)
				{
					if (tree[0][k] == j && colored[tree[1][k]] != 0 && strcmp(colorList[a], colorLabel[tree[1][k]]) == 0)
						a += 1;
					if (tree[1][k] == j && colored[tree[0][k]] != 0 && strcmp(colorList[a], colorLabel[tree[0][k]]) == 0)
						a += 1;
				}
				strcpy(colorLabel[j], colorList[a]);
				colored[j] = 1;
			}
		}
	}
	// Print File
	FILE *fileDot;
	fileDot = fopen("DoThiDaToMau.dot", "w");
	fputs("graph dothi\n {\n", fileDot);
	for (int b = 1; b <= numOfVertices; b++)
	{
		fprintf(fileDot, "%d [fillcolor=%s, style=filled];\n", b, colorLabel[b]);
	}
	for (int c = 1; c <= numOfEdges; c++)
	{
		fprintf(fileDot, "%d -- %d;\n", tree[0][c], tree[1][c]);
	}
	fputs("}", fileDot);
	fclose(fileDot);
	return 0;
}
