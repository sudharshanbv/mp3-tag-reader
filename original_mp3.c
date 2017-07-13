

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mp3
{

	char *name_mp3;
	FILE *fptr_mp3;

}mp3;

int main()
{

	mp3.name_mp3 = malloc(40);
	printf("Enter the file name: ");
	scanf("\n%[^\n]", mp3.name_mp3);

	mp3.fptr_mp3 = fopen(mp3.name_mp3, "r");

	if (mp3.fptr_mp3 == NULL)
	{
		printf("File cannot be opened\n");
	}

	char ch;
	char buff[4];
	char buff1[200];
	char size[4];
	int num = 0;
	int idx;

	while (feof(mp3.fptr_mp3) == 0)
	{
		fread(&ch, 1, 1, mp3.fptr_mp3);

		if (ch == 'T')
		{

			fread(buff, 1, 3, mp3.fptr_mp3);

			buff[3] = '\0';

			if (strcmp(buff, "ALB") == 0)
			{
				fread(size, 1, 4, mp3.fptr_mp3);

				for (idx = 1; idx <= 4; idx++)
				{
					num = num | ((size[4 - idx]) << (((idx - 1) * 8)));
				}

printf("size = %d\n", num);
				fseek(mp3.fptr_mp3, 3, SEEK_CUR);
				fread(buff1, 1, num, mp3.fptr_mp3);
				buff1[num] = '\0';
				printf("\nTALB : %s\n\n", buff1);
				break;
			}

			//else
			//	fseek(mp3.fptr_mp3, -3, SEEK_CUR);

		}


	}
}
