#ifndef NALI_GRAPHICREADER_H
#define NALI_GRAPHICREADER_H

uint32_t graphic_reader_count(const char* char_ptr, const char c_char);
void graphic_reader_sanitize(char* char_ptr);
void graphic_reader_makeBones(collada_Source* collada_source_ptr);
void graphic_reader_mix(collada_Source* collada_source_ptr);
void graphic_reader_fixAnimation(collada_Source* collada_source_ptr);

#endif
