#ifndef _ARGS_H_
#define _ARGS_H_
#include <stdbool.h>
#include <stdio.h>
#include "image.h"

typedef enum {
  ASC_MOD_BLOCKS = 0,
  ASC_MOD_BRAILLE = 1,
  ASC_MOD_GRADIENT = 2,
  ASC_MOD_BRUTEFORCE = 3,
  ASC_MOD_ENDL = 4
} asc_mode_t;

typedef enum {
  ASC_FMT_ANSI = 0,
  ASC_FMT_HTML = 1,
  ASC_FMT_JSON = 2,
  ASC_FMT_ENDL = 3
} asc_format_t;

typedef enum {
  ASC_STL_BLACKWHITE = 0,
  ASC_STL_ANSI_VGA = 1,
  ASC_STL_ANSI_XTERM = 2,
  ASC_STL_ANSI_DISCORD = 3,
  ASC_STL_256COLOR = 4,
  ASC_STL_TRUECOLOR = 5,
  ASC_STL_PALETTE = 6,
  ASC_STL_ENDL = 7
} asc_style_t;

typedef struct {
  char *input_filename;
  char *output_filename;
  char *palette_filename;
  int width;
  int height;
  asc_format_t out_format;
  asc_style_t out_style;
  asc_mode_t mode;
  bool dither;
  bool verbose;
  char *charset;
} asc_args_t;

typedef struct {
  asc_args_t args;
  image_t *source_image;
  image_t *image;
  palette_t *palette;
  FILE *out_file;
} asc_state_t;

void usage(int argc, char **argv);
int parse_args(int argc, char **argv, asc_args_t *args);
int prepare_state(int argc, char **argv, asc_args_t args, asc_state_t *state);

#endif