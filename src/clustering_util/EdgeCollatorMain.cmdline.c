/*
  File autogenerated by gengetopt version 2.19.1
  generated with the following command:
  gengetopt --file-name=EdgeCollatorMain.cmdline  

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getopt.h"

#include "EdgeCollatorMain.cmdline.h"

const char *gengetopt_args_info_purpose = "Collate all edges between clusters into one thick edge averaging all possible \nthin edges.\nAn input edge in the format `I J dist W` per input line, where I J are valid \ncluster IDs (i.e. after the last round of clustering), dist is the distance \n(dissimilarity) between children clusters I' and J' of I and J respectively \n(possibly I, J themselves), and W which is the weight (integer) of the edge \nbetween I' and J'. W :=  size(I') * size(J'), where size are the cluster sizes.";

const char *gengetopt_args_info_usage = "Usage: edge_collator [OPTIONS]...";

const char *gengetopt_args_info_description = "";

const char *gengetopt_args_info_help[] = {
  "  -h, --help                  Print help and exit",
  "  -V, --version               Print version and exit",
  "  -s, --sizes-file=STRING     Output file for sizes computed from tree",
  "  -t, --tree-file=filename    Filename containing the tree",
  "  -x, --missing-val=distance  The defualt weight for missing edges  \n                                (default=`100')",
  "This is the value used when computing the distances from a new born cluster \nwhen one of the averaged edges is missing.",
    0
};

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required, const char *additional_error);


static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->sizes_file_given = 0 ;
  args_info->tree_file_given = 0 ;
  args_info->missing_val_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  args_info->sizes_file_arg = NULL;
  args_info->sizes_file_orig = NULL;
  args_info->tree_file_arg = NULL;
  args_info->tree_file_orig = NULL;
  args_info->missing_val_arg = 100;
  args_info->missing_val_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{
  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->sizes_file_help = gengetopt_args_info_help[2] ;
  args_info->tree_file_help = gengetopt_args_info_help[3] ;
  args_info->missing_val_help = gengetopt_args_info_help[4] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n", CMDLINE_PARSER_PACKAGE, CMDLINE_PARSER_VERSION);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  printf("\n%s\n\n", gengetopt_args_info_usage);

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n", gengetopt_args_info_description);

  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);
}

static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  
  if (args_info->sizes_file_arg)
    {
      free (args_info->sizes_file_arg); /* free previous argument */
      args_info->sizes_file_arg = 0;
    }
  if (args_info->sizes_file_orig)
    {
      free (args_info->sizes_file_orig); /* free previous argument */
      args_info->sizes_file_orig = 0;
    }
  if (args_info->tree_file_arg)
    {
      free (args_info->tree_file_arg); /* free previous argument */
      args_info->tree_file_arg = 0;
    }
  if (args_info->tree_file_orig)
    {
      free (args_info->tree_file_orig); /* free previous argument */
      args_info->tree_file_orig = 0;
    }
  if (args_info->missing_val_orig)
    {
      free (args_info->missing_val_orig); /* free previous argument */
      args_info->missing_val_orig = 0;
    }
  
  clear_given (args_info);
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  if (args_info->help_given) {
    fprintf(outfile, "%s\n", "help");
  }
  if (args_info->version_given) {
    fprintf(outfile, "%s\n", "version");
  }
  if (args_info->sizes_file_given) {
    if (args_info->sizes_file_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "sizes-file", args_info->sizes_file_orig);
    } else {
      fprintf(outfile, "%s\n", "sizes-file");
    }
  }
  if (args_info->tree_file_given) {
    if (args_info->tree_file_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "tree-file", args_info->tree_file_orig);
    } else {
      fprintf(outfile, "%s\n", "tree-file");
    }
  }
  if (args_info->missing_val_given) {
    if (args_info->missing_val_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "missing-val", args_info->missing_val_orig);
    } else {
      fprintf(outfile, "%s\n", "missing-val");
    }
  }
  
  fclose (outfile);

  i = EXIT_SUCCESS;
  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}


/* gengetopt_strdup() */
/* strdup.c replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = NULL;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser2 (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;

  result = cmdline_parser_internal (argc, argv, args_info, override, initialize, check_required, NULL);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  return EXIT_SUCCESS;
}

int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error = 0;
  struct gengetopt_args_info local_args_info;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = 1;
  optopt = '?';

  while (1)
    {
      int option_index = 0;
      char *stop_char;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "sizes-file",	1, NULL, 's' },
        { "tree-file",	1, NULL, 't' },
        { "missing-val",	1, NULL, 'x' },
        { NULL,	0, NULL, 0 }
      };

      stop_char = 0;
      c = getopt_long (argc, argv, "hVs:t:x:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 's':	/* Output file for sizes computed from tree.  */
          if (local_args_info.sizes_file_given)
            {
              fprintf (stderr, "%s: `--sizes-file' (`-s') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->sizes_file_given && ! override)
            continue;
          local_args_info.sizes_file_given = 1;
          args_info->sizes_file_given = 1;
          if (args_info->sizes_file_arg)
            free (args_info->sizes_file_arg); /* free previous string */
          args_info->sizes_file_arg = gengetopt_strdup (optarg);
          if (args_info->sizes_file_orig)
            free (args_info->sizes_file_orig); /* free previous string */
          args_info->sizes_file_orig = gengetopt_strdup (optarg);
          break;

        case 't':	/* Filename containing the tree.  */
          if (local_args_info.tree_file_given)
            {
              fprintf (stderr, "%s: `--tree-file' (`-t') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->tree_file_given && ! override)
            continue;
          local_args_info.tree_file_given = 1;
          args_info->tree_file_given = 1;
          if (args_info->tree_file_arg)
            free (args_info->tree_file_arg); /* free previous string */
          args_info->tree_file_arg = gengetopt_strdup (optarg);
          if (args_info->tree_file_orig)
            free (args_info->tree_file_orig); /* free previous string */
          args_info->tree_file_orig = gengetopt_strdup (optarg);
          break;

        case 'x':	/* The defualt weight for missing edges.  */
          if (local_args_info.missing_val_given)
            {
              fprintf (stderr, "%s: `--missing-val' (`-x') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->missing_val_given && ! override)
            continue;
          local_args_info.missing_val_given = 1;
          args_info->missing_val_given = 1;
          args_info->missing_val_arg = (float)strtod (optarg, &stop_char);
          if (!(stop_char && *stop_char == '\0')) {
            fprintf(stderr, "%s: invalid numeric value: %s\n", argv[0], optarg);
            goto failure;
          }
          if (args_info->missing_val_orig)
            free (args_info->missing_val_orig); /* free previous string */
          args_info->missing_val_orig = gengetopt_strdup (optarg);
          break;


        case 0:	/* Long option with no short option */
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */




  cmdline_parser_release (&local_args_info);

  if ( error )
    return (EXIT_FAILURE);

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}