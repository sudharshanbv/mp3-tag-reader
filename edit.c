#include <stdio.h>
#include <string.h>
#include "tag.h"
#include "types.h"

void edit_func(int operation_type, TagReader *mp3)
{

char ch;
int edit_choice;
char edit_buffer[100];

do
		{

			fseek(mp3->fptr_mp3, 0, SEEK_SET);

			printf("\nChoose the editing option\n1.Title\n2.Album\n3.Artist\n4.Track\n5.Year\n6.Composer\n7.Genre\n8.Comments\n");
			printf("Enter your choice: ");
			scanf("%d", &edit_choice);

			switch (edit_choice)
			{

				case 1:
					{
						read_tag(operation_type, edit_choice, mp3);
						fseek(mp3->fptr_output, ftell(mp3->fptr_mp3), SEEK_SET);
						printf("Enter the string less than / equal to %d characters: ", mp3->num - 1);
						scanf("\n%[^\n]", edit_buffer);

						if (strlen(edit_buffer) > (mp3->num - 1))
						{
							printf("More than %d characters entered.Edit failed!!!", mp3->num - 1);
							continue;
						}
						fwrite(edit_buffer, 1, strlen(edit_buffer) + 1, mp3->fptr_output);
					}
					break;

				case 2:
					{

						read_tag(operation_type, edit_choice, mp3);
						fseek(mp3->fptr_output, ftell(mp3->fptr_mp3), SEEK_SET);
						printf("Enter the string less than / equal to %d characters: ", mp3->num - 1);
						scanf("\n%[^\n]", edit_buffer);
						if (strlen(edit_buffer) > mp3->num - 1)
						{
							printf("More than %d characters entered.Edit failed!!!", mp3->num - 1);
							continue;
						}

						fwrite(edit_buffer, 1, strlen(edit_buffer) + 1, mp3->fptr_output);
					}
					break;

				case 3:
					{

						read_tag(operation_type, edit_choice, mp3);
						fseek(mp3->fptr_output, ftell(mp3->fptr_mp3), SEEK_SET);
						printf("Enter the string less than / equal to %d characters: ", mp3->num - 1);
						scanf("\n%[^\n]", edit_buffer);
						if (strlen(edit_buffer) > mp3->num - 1)
						{
							printf("More than %d characters entered.Edit failed!!!", mp3->num - 1);
							continue;
						}

						fwrite(edit_buffer, 1, strlen(edit_buffer) + 1, mp3->fptr_output);
					}
					break;

				case 4:
					{

						read_tag(operation_type, edit_choice, mp3);
						fseek(mp3->fptr_output, ftell(mp3->fptr_mp3), SEEK_SET);
						printf("Enter the string less than / equal to %d characters: ", mp3->num - 1);
						scanf("\n%[^\n]", edit_buffer);
						if (strlen(edit_buffer) > mp3->num - 1)
						{
							printf("More than %d characters entered.Edit failed!!!", mp3->num - 1);
							continue;
						}

						fwrite(edit_buffer, 1, strlen(edit_buffer), mp3->fptr_output);
					}
					break;

				case 5:
					{

						read_tag(operation_type, edit_choice, mp3);
						fseek(mp3->fptr_output, ftell(mp3->fptr_mp3), SEEK_SET);
						printf("Enter the string less than / equal to %d characters: ", mp3->num - 1);
						scanf("\n%[^\n]", edit_buffer);
						if (strlen(edit_buffer) > mp3->num - 1)
						{
							printf("More than %d characters entered.Edit failed!!!", mp3->num - 1);
							continue;
						}

						fwrite(edit_buffer, 1, strlen(edit_buffer), mp3->fptr_output);
					}
					break;

				case 6:
					{

						read_tag(operation_type, edit_choice, mp3);
						fseek(mp3->fptr_output, ftell(mp3->fptr_mp3), SEEK_SET);
						printf("Enter the string less than / equal to %d characters: ", mp3->num - 1);
						scanf("\n%[^\n]", edit_buffer);
						if (strlen(edit_buffer) > mp3->num - 1)
						{
							printf("More than %d characters entered.Edit failed!!!", mp3->num - 1);
							continue;
						}

						fwrite(edit_buffer, 1, strlen(edit_buffer), mp3->fptr_output);
					}
					break;

				case 7:
					{

						read_tag(operation_type, edit_choice, mp3);
						fseek(mp3->fptr_output, ftell(mp3->fptr_mp3), SEEK_SET);
						printf("Enter the string less than / equal to %d characters: ", mp3->num - 1);
						scanf("\n%[^\n]", edit_buffer);
						if (strlen(edit_buffer) > mp3->num - 1)
						{
							printf("More than %d characters entered.Edit failed!!!", mp3->num - 1);
							continue;
						}

						fwrite(edit_buffer, 1, strlen(edit_buffer) + 1, mp3->fptr_output);
					}
					break;

				case 8:
					{

						read_tag(operation_type, edit_choice, mp3);
						fseek(mp3->fptr_output, ftell(mp3->fptr_mp3), SEEK_SET);
						printf("Enter the string less than / equal to %d characters: ", mp3->num - 1);
						scanf("\n%[^\n]", edit_buffer);
						if (strlen(edit_buffer) > mp3->num - 1)
						{
							printf("More than %d characters entered.Edit failed!!!", mp3->num - 1);
							continue;
						}

						fwrite(edit_buffer, 1, strlen(edit_buffer) + 1, mp3->fptr_output);
					}
					break;

				case 9:
					{

						read_tag(operation_type, edit_choice, mp3);
						fseek(mp3->fptr_output, ftell(mp3->fptr_mp3), SEEK_SET);
						printf("Enter the string less than / equal to %d characters: ", mp3->num - 1);
						scanf("\n%[^\n]", edit_buffer);
						if (strlen(edit_buffer) > mp3->num - 1)
						{
							printf("More than %d characters entered.Edit failed!!!", mp3->num - 1);
							continue;
						}

						fwrite(edit_buffer, 1, strlen(edit_buffer), mp3->fptr_output);
					}
					break;

			}
			printf("\nDO you want to continue editing?(y/n)\n\nEnter your choice:  ");
			scanf("\n%[^\n]", &ch);
		} while (ch == 'y' || ch == 'Y');
}
