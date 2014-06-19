#include <stdio.h>
#include "grap.h"

#define SIZE 1024


static char buff[SIZE + 1], gr[50][50];

int
main (int argc, char *argv[])
{
  FILE *bfp;
  int i, j;
  if (argc != 2)
    {
      fprintf (stderr, "USAGE: grap filename\n");
      return (1);
    }
  if (!(bfp = fopen (argv[1], "r")))
    {
      perror (argv[1]);
      return (1);
    }
  buff[0] = 0;
  while (fgets (buff, SIZE, bfp))
    {
      cutnl (buff, 0);
      i = grapstring (cutcharbe (buff, 0x20), ':', 10, 50, gr);
      if (i > 0)
	{

	  j = 0;
	  while (j < i)
	    {
	      printf ("%d=%s ", j + 1, &gr[j][0]);
	      j++;
	    }
	  putchar ('\n');
	}
      else if (i < 0)
	{
	  printf ("error\n");
	  return (1);
	}
      buff[0] = 0;
    }

  fclose (bfp);
  printf ("\n\nUsing GrapString Library version %s\n", GRAP_VERSION_STRING);
  return (0);

}

