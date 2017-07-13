

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tag.h"
#include "types.h"

/*check operation type*/
OperationType check_operation_type(int argc, char *argv[], TagReader *mp3)
{

	/*if options are entered through command line arguments*/
	if (argc > 1)
	{

		/*if read*/
		if (argc == 3)
		{

			if (strcmp(argv[1], "-r") == 0)
			{

				/*if file extension is ".mp3"*/
				if (strstr(argv[2], ".mp3"))
				{
					mp3->name_mp3 = argv[2];
					return t_read;
				}

				/*do error handling*/
				else
				{
					printf("Error!!!Invalid file extension. Use .mp3 only.\n");
					return t_unsupported;
				}
			}

			/*do error handling*/
			else
			{
				printf("Error!!!Invalid usage of command line options.\n");
				printf("Usage Example: To Read Tags: ./a.out -r <source_fname.mp3>\n");
				printf("Usage Example: To Edit Tags: ./a.out -e <source_fname.mp3> <output_fname.mp3>\n");
				return t_unsupported;
			} 
		}

		/*if edit*/
		else if (argc == 4)
		{

			if (strcmp(argv[1], "-e") == 0)
			{

				/*if file extension is ".mp3"*/
				if ((strstr(argv[2], ".mp3")) && (strstr(argv[3], ".mp3")))
				{
					mp3->name_mp3 = argv[2];
					mp3->output_fname = argv[3];
					return t_edit;
				}

				/*do error handling*/
				else
				{
					printf("Error!!!Invalid file extension. Use .mp3 only.\n");
					return t_unsupported;
				}
			}

			/*do error handling*/
			else
			{
				printf("Error!!!Invalid usage of command line options.\n");
				printf("Usage Example: To Read Tags: ./a.out -r <source_fname.mp3>\n");
				printf("Usage Example: To Edit Tags: ./a.out -e <source_fname.mp3> <output_fname.mp3>\n");
				return t_unsupported;
			} 
		}

		/*do error handling*/
		else
		{
			printf("Error!!!Invalid usage of command line options.\n");
			printf("Usage Example: To Read Tags: ./a.out -r <source_fname.mp3>\n");
			printf("Usage Example: To Edit Tags: ./a.out -e <source_fname.mp3> <output_fname.mp3>\n");
			return t_unsupported;
		}
	}

	/*if no command line arguments are present*/	
	else
	{
		int choice;

		/*reading the operation type from the user*/
		printf("Choose the operation type\n1.Read\t2.Edit\n\nEnter the operation type: ");
		scanf("%d", &choice);

		switch (choice)
		{

			/*read case*/
			case 1:
				{

					/*reading the source file name*/
					mp3->name_mp3 = malloc(40);
					printf("Enter the source file name: ");
					scanf("\n%[^\n]", mp3->name_mp3);

					/*checking for ".mp3" file extension*/
					if (strstr(mp3->name_mp3, ".mp3"))
					{
						return t_read;
					}

					/*do error handling*/
					else
					{
						printf("Error!!!Invalid file extension. Use .mp3 only.\n");
						return t_unsupported;
					}
				}
				break;

				/*edit case*/
			case 2:
				{

					/*reading the source file name*/
					mp3->name_mp3 = malloc(40);
					printf("Enter the source file name: ");
					scanf("\n%[^\n]", mp3->name_mp3);

					/*checking for ".mp3" file extension of source file*/
					if (strstr(mp3->name_mp3, ".mp3"))
					{

						/*reading the output file name*/
						mp3->output_fname = malloc(40);
						printf("Enter the output file name: ");
						scanf("\n%[^\n]", mp3->output_fname);

						/*checking for ".mp3" file extension of output file*/
						if (strstr(mp3->output_fname, ".mp3"))
						{
							return t_edit;
						}

						/*do error handling*/
						else
						{
							printf("Error!!!Invalid file extension. Use .mp3 only.\n");
							return t_unsupported;
						}
					}

					/*do error handling*/
					else
					{
						printf("Error!!!Invalid file extension. Use .mp3 only.\n");
						return t_unsupported;
					}

				}
				break;

			default:
				{
					printf("Error!!!Invalid choice.\n");
					return t_unsupported;
				}
		}
	}
}
/*------------------------------------------------------------------------------------------------------------------------------*/

/*open files*/
Status open_files(int operation_type, TagReader *mp3)
{

	/*if read operation*/
	if (operation_type == t_read)
	{

		/*open source file*/
		if (mp3->fptr_mp3 = fopen(mp3->name_mp3, "r"))
		{
			if (mp3->fptr_image = fopen("image.jpg", "w+"))
			{
				return t_success;
			}
			else
			{

				printf("Error!!! %s file could not be opened\n", "image.jpg");
				return t_failure;
			}
		}

		/*do error handling*/
		else
		{
			printf("Error!!! %s file could not be opened\n", mp3->name_mp3);
			return t_failure;
		}
	}

	/*if edit operation*/
	else
	{

		/*open source file*/
		if (mp3->fptr_mp3 = fopen(mp3->name_mp3, "r"))
		{

			/*open output file*/
			if (mp3->fptr_output = fopen(mp3->output_fname, "w+"))
			{
				return t_success;
			}

			/*do error handling*/
			else
			{
				printf("Error!!! %s file could not be opened\n", mp3->output_fname);
				return t_failure;
			}
		}

		/*do error handling*/
		else
		{
			printf("Error!!! %s file could not be opened\n", mp3->name_mp3);
			return t_failure;
		}

	}
}


/*------------------------------------------------------------------------------------------------------------------------------*/
/*read tag*/
Status read_tag(int operation_type, int case_no, TagReader *mp3)
{
	int flag = 0;


	while (feof(mp3->fptr_mp3) == 0)
	{

		fread(mp3->ch, 1, 1, mp3->fptr_mp3);

		/*checking for first letter of the tag*/
		if (mp3->ch[0] == 'T')
		{

			/*reading the next 3 letters of tag*/
			fread(mp3->tag, 1, 3, mp3->fptr_mp3);

			mp3->tag[3] = '\0';

			/*checking for next 3 letters of the tag*/
			if (strcmp(mp3->tag, "IT2") == 0)
			{
				get_tag_size(mp3);

				if ((operation_type == t_edit) && (case_no == 1))
				{
					break;
				}

				fread(mp3->title, 1, mp3->num - 1, mp3->fptr_mp3);
				mp3->title[mp3->num - 1] = '\0';
				continue;

			}
			if (strcmp(mp3->tag, "ALB") == 0)
			{
				get_tag_size(mp3);
				if ((operation_type == t_edit) && (case_no == 2))
				{
					break;
				}

				fread(mp3->album_name, 1, mp3->num - 1, mp3->fptr_mp3);
				mp3->album_name[mp3->num - 1] = '\0';
				continue;

			}
			if (strcmp(mp3->tag, "PE1") == 0)
			{
				get_tag_size(mp3);
				if ((operation_type == t_edit) && (case_no == 3))
				{
					break;
				}

				fread(mp3->artist_name, 1, mp3->num - 1, mp3->fptr_mp3);
				mp3->artist_name[mp3->num - 1] = '\0';
				continue;

			}
			if (strcmp(mp3->tag, "YER") == 0)
			{
				get_tag_size(mp3);
				if ((operation_type == t_edit) && (case_no == 5))
				{
					break;
				}

				fread(mp3->year, 1, mp3->num - 1, mp3->fptr_mp3);
				mp3->year[mp3->num - 1] = '\0';
				continue;

			}
			if (strcmp(mp3->tag, "COM") == 0)
			{
				get_tag_size(mp3);
				if ((operation_type == t_edit) && (case_no == 6))
				{
					break;
				}

				fread(mp3->composer, 1, mp3->num - 1, mp3->fptr_mp3);
				mp3->composer[mp3->num - 1] = '\0';
				continue;

			}
			if ((strcmp(mp3->tag, "CON") == 0) && (flag == 0))
			{
				flag = 1;
				get_tag_size(mp3);
				if ((operation_type == t_edit) && (case_no == 7))
				{
					break;
				}

				fread(mp3->genre, 1, mp3->num - 1, mp3->fptr_mp3);
				mp3->genre[mp3->num - 1] = '\0';
				continue;

			}

			if (strcmp(mp3->tag, "LEN") == 0)
			{
				get_tag_size(mp3);

				fread(mp3->track_len, 1, mp3->num - 1, mp3->fptr_mp3);
				mp3->track_len[mp3->num - 1] = '\0';
				continue;

			}
			if (strcmp(mp3->tag, "RCK") == 0)
			{
				get_tag_size(mp3);
				if ((operation_type == t_edit) && (case_no == 4))
				{
					break;
				}

				fread(mp3->track_num, 1, mp3->num - 1, mp3->fptr_mp3);
				mp3->track_num[mp3->num - 1] = '\0';
				continue;

			}
		}

		if (mp3->ch[0] == 'C')
		{


			fread(mp3->tag, 1, 3, mp3->fptr_mp3);

			mp3->tag[3] = '\0';
			if (strcmp(mp3->tag, "OMM") == 0)

			{
				get_tag_size(mp3);
				if ((operation_type == t_edit) && (case_no == 8))
				{
					break;
				}

				fread(mp3->comments, 1, mp3->num - 1, mp3->fptr_mp3);
				mp3->comments[mp3->num - 1] = '\0';
				continue;

			}
		}
						if (mp3->ch[0] == 'A')
						{

						fread(mp3->tag, 1, 3, mp3->fptr_mp3);

						mp3->tag[3] = '\0';
						if (strcmp(mp3->tag, "PIC") == 0)
						{
						get_tag_size(mp3);
						fseek(mp3->fptr_mp3, 21, SEEK_CUR);
						fread(mp3->attached_pic, 1, mp3->num - 1 - 21, mp3->fptr_mp3);
						fwrite(mp3->attached_pic, 1, mp3->num - 1 - 21, mp3->fptr_image);
						mp3->attached_pic[mp3->num - 1] = '\0';
						continue;

						}
						}
	}
}
/*------------------------------------------------------------------------------------------------------------------------------*/
/*get size of tag*/
Status get_tag_size(TagReader *mp3)
{

	int idx;

	mp3->num = 0;

	fread(mp3->size, 1, 4, mp3->fptr_mp3);

	for (idx = 1; idx <= 4; idx++)
	{
		mp3->num = mp3->num | ((mp3->size[4 - idx]) << (((idx - 1) * 8)));
	}

	fseek(mp3->fptr_mp3, 3, SEEK_CUR);
}

/*------------------------------------------------------------------------------------------------------------------------------*/
/*findind the size of file*/
void mp3_size(TagReader *mp3)
{

	fseek(mp3->fptr_mp3, 0, SEEK_END);

	mp3->mp3_size = ftell(mp3->fptr_mp3) / 1000000.0;
}

/*------------------------------------------------------------------------------------------------------------------------------*/
/*printing tags*/
void print_tags(TagReader *mp3)
{

	printf("\n\n");
	printf(KGRN"%-10s\t"KNRM"[%.2f MB]\n", mp3->name_mp3, mp3->mp3_size);
	printf(KCYN"-----------------------------------------------------------------------\n");
	printf(KMAG"%-10s"KNRM" %s\n", "Time", mp3->track_len);
	printf(KCYN"-----------------------------------------------------------------------\n");
	printf(KMAG"%-10s: " KNRM"%s\n", "Title", mp3->title);
	printf(KMAG"%-10s: " KNRM"%s\n", "Album", mp3->album_name);
	printf(KMAG"%-10s: " KNRM"%s\n", "Artist", mp3->artist_name);
	printf(KMAG"%-10s: " KNRM"%s\n", "Composer", mp3->composer);
	printf(KMAG"%-10s: " KNRM"%s\n", "Year", mp3->year);
	printf(KMAG"%-10s: " KNRM"%s\n", "Track", mp3->track_num);
	printf(KMAG"%-10s: " KNRM"%s\n", "Genre", mp3->genre);
	printf(KMAG"%-10s: " KNRM"%s\n", "Comment", mp3->comments);
	printf("\n\n");

}


/*------------------------------------------------------------------------------------------------------------------------------*/
/*copy source file*/
Status copy_mp3(TagReader *mp3)
{

	char buffer[1024];
	int bytes_read;

	while (feof(mp3->fptr_mp3) == 0)
	{

		bytes_read = fread(buffer, 1, 1000, mp3->fptr_mp3);
		fwrite(buffer, 1, bytes_read, mp3->fptr_output);

	}

	fseek(mp3->fptr_mp3, 0, SEEK_SET);
	fseek(mp3->fptr_output, 0, SEEK_SET);

}

/*------------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------------------------------------------*/
