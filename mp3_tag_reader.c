#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tag.h"
#include "types.h"


int main(int argc, char *argv[])
{

	TagReader mp3;

	int operation_type;
	int status;

	if ((operation_type = check_operation_type(argc, argv, &mp3)) == t_unsupported)
	{
		return 1;
	}


	if ((status = open_files(operation_type, &mp3)) == t_failure)
	{
		return 2;
	}


	if (operation_type == t_read)
	{

		read_tag(operation_type, 0, &mp3);

		mp3_size(&mp3); 

		print_tags(&mp3);
		return 0;

	}

	if (operation_type = t_edit)
	{

		copy_mp3(&mp3);
		edit_func(operation_type, &mp3);
	}

	if (operation_type == t_read)
	{
		fclose(mp3.fptr_mp3);
	}

	else
	{

		fclose(mp3.fptr_mp3);
		fclose(mp3.fptr_output);
	}

return 0;
}
