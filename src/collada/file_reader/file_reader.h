#ifndef NALI_FILEREADER_H
#define NALI_FILEREADER_H

char file_reader_match(FILE *file_ptr, const char *mchar_ptr[], size_t size);
char **file_reader_char_ptr(FILE *file_ptr, const char *f_char_ptr, const char *e_char_ptr, char **char_ptr, uint32_t *size);
float *file_reader_float(FILE *file_ptr, const char *e_char_ptr, float *float_ptr, uint32_t *size);
int *file_reader_int(FILE *file_ptr, const char *e_char_ptr, int *int_ptr, uint32_t *size);
BoneData *file_reader_node(FILE *file_ptr, BoneData *bonedata, uint32_t *size);

#endif