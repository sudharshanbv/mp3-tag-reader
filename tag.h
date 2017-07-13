

#ifndef TAG_H
#define TAG_H

#define KGRN "\x1B[32m"
#define KNRM "\x1B[0m"
#define KMAG "\x1B[36m"
#define KCYN "\x1B[33m"

#include "types.h"
#include "tag.h"


typedef struct mp3_tag_reader
{

	char *name_mp3;
	FILE *fptr_mp3;

        char *output_fname;
        FILE *fptr_output;

        FILE *fptr_image;

	char ch[1];
	char tag[4];
        unsigned char size[4];

	char album_name[100];
	char artist_name[100];
	char title[100];
	char year[100];
	char track_num[100];
	char composer[100];
	char comments[100];
	char attached_pic[5000];
	char genre[100];
	char track_len[100];

	unsigned int num;
	float mp3_size;
} TagReader;

/*check operation type*/
OperationType check_operation_type(int argc, char *argv[], TagReader *mp3);

/*open files*/
Status open_files(int operation_type, TagReader *mp3);

/*read tag*/
Status read_tag(int operation_type, int case_no, TagReader *mp3);

/*get tag size*/
Status get_tag_size(TagReader *mp3);

/*get mp3 size*/
void mp3_size(TagReader *mp3); 

/*print tags*/
void print_tags(TagReader *mp3);

/*copy mp3*/
Status copy_mp3(TagReader *mp3);

/*edit function*/
void edit_func(int operation_type, TagReader *mp3);
#endif
