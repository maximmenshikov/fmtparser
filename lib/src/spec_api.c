#include <stdlib.h>
#include <string.h>
#include "fmt_parser.h"
#include "fmt_bool.h"
#include "fmt_spec.h"
#include "fmt_status.h"
#include "fmt_spec_api.h"

/* See the description in fmt_spec_api.h */
fmt_spec *
fmt_spec_alloc(void)
{
   fmt_spec *spec = malloc(sizeof(fmt_spec));

   return spec;
}

/* See the description in fmt_spec_api.h */
void
fmt_spec_free(fmt_spec *spec)
{
   free(spec);
}

/* See the description in fmt_spec_api.h */
char **
fmt_str_alloc(char *str)
{
   char **ptr = malloc(sizeof(char **));

   *ptr = strdup(str);
   return ptr;
}

/* See the description in fmt_spec_api.h */
void
fmt_str_free(char **str_ptr)
{
   if (str_ptr != NULL)
      free(*str_ptr);
   free(str_ptr);
}

/* See the description in fmt_spec_api.h */
int32_t
fmt_spec_get_start_position(fmt_spec *spec, fmt_char **str)
{
   return spec->str_start - (*str);
}

/* See the description in fmt_spec_api.h */
int32_t
fmt_spec_get_end_position(fmt_spec *spec, fmt_char **str)
{
   return spec->str_end - (*str);
}

/* See the description in fmt_spec_api.h */
uint32_t
fmt_spec_get_kind(fmt_spec *spec)
{
   return spec->kind;
}

/* See the description in fmt_spec_api.h */
uint32_t
fmt_spec_get_parameter(fmt_spec *spec)
{
   return spec->parameter;
}

/* See the description in fmt_spec_api.h */
uint32_t
fmt_spec_get_width(fmt_spec *spec)
{
   return spec->width;
}

/* See the description in fmt_spec_api.h */
uint32_t
fmt_spec_get_precision(fmt_spec *spec)
{
   return spec->precision;
}

/* See the description in fmt_spec_api.h */
uint32_t
fmt_spec_get_length(fmt_spec *spec)
{
   return spec->len;
}

/* See the description in fmt_spec_api.h */
uint32_t
fmt_spec_get_type(fmt_spec *spec)
{
   return spec->type;
}

/* See the description in fmt_spec_api.h */
fmt_bool
fmt_spec_get_flag(fmt_spec *spec, fmt_flag flag)
{
   switch (flag)
   {
      case FMT_FLAG_LEFT_ALIGN:
         return spec->flags.left_align;
      case FMT_FLAG_PREPEND_PLUS:
         return spec->flags.prepend_plus;
      case FMT_FLAG_PREPEND_SPACE:
         return spec->flags.prepend_space;
      case FMT_FLAG_PREPEND_ZERO:
         return spec->flags.prepend_zero;
      case FMT_FLAG_THOUSANDS_GROUPING:
         return spec->flags.thousands_grouping;
      case FMT_FLAG_ALTERNATE:
         return spec->flags.alternate;
      default:
         return FMT_FALSE;
   }
}
