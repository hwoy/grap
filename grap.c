#include "grap.h"

char GRAP_VERSION_STRING[] = "1.36";
int GRAP_VERSION_MAJOR = 1;
int GRAP_VERSION_MINOR = 36;

#ifdef ANSI
int
grapstring (const char *str, char sep, int maxcount, int blength, void *buff)
{
  unsigned int i, j, k;
  if ((!str) || (!buff) || (maxcount < 1) || (blength < 2))
    {
      return (-3);
    }

  for (i = 0, j = 0, k = 0; str[i]; i++)
    {				/*for */
      if (str[i] != sep)
	{			/*if */
	  if (k >= (blength - 1))
	    {
	      return -2;
	    }
	  *(char *) ((char *) buff + j * blength + k++) = str[i];

	  if (!str[i + 1])
	    {
	      *(char *) ((char *) buff + (j++) * blength + k) = 0;
	    }


	}			/*end if */

      else if (str[i] == sep)
	{


	  *(char *) ((char *) buff + (j++) * blength + k) = 0;
	  k = 0;

	  if (!str[i + 1])
	    {
	      *(char *) ((char *) buff + (j++) * blength) = 0;
	    }


	}


      if (j > maxcount)
	{
	  return -1;
	}
    }				/*end for */

  return j;
}

int
grapstring2 (const char *str, char sep, int maxcount, int blength, void *buff)
{
  unsigned int i, j, k;
  if ((!str) || (!buff) || (maxcount < 1) || (blength < 2))
    {
      return (-3);
    }

  for (i = 0, j = 0, k = 0; str[i]; i++)
    {				/*for */
      if (str[i] != sep)
	{			/*if */
	  if (k >= (blength - 1))
	    {
	      return -2;
	    }
	  *(char *) ((char *) buff + j * blength + k++) = str[i];

	  if (!str[i + 1])
	    {
	      *(char *) ((char *) buff + (j++) * blength + k++) = 0;
	    }
	  else if (str[i + 1] == sep)
	    {
	      *(char *) ((char *) buff + (j++) * blength + k) = 0;
	      k = 0;
	    }

	}			/*end if */
      if (j > maxcount)
	{
	  return -1;
	}


    }				/*end for */

  return j;
}

#else
int
grapstring (const char *str, char sep, int maxcount, int blength,
	    char buff[maxcount][blength])
{
  unsigned int i, j, k;
  if ((!str) || (!buff) || (maxcount < 1) || (blength < 2))
    {
      return (-3);
    }

  for (i = 0, j = 0, k = 0; str[i]; i++)
    {				/*for */

      if (str[i] != sep)
	{			/*if */
	  if (k >= (blength - 1))
	    {
	      return -2;
	    }
	  buff[j][k++] = str[i];
	  if (!str[i + 1])
	    {
	      buff[j++][k] = 0;
	    }


	}			/*end if */

      else if (str[i] == sep)
	{

	  buff[j++][k] = 0;
	  k = 0;

	  if (!str[i + 1])
	    {
	      buff[j++][0] = 0;
	    }


	}


      if (j > maxcount)
	{
	  return -1;
	}

    }				/*end for */



  return j;
}


int
grapstring2 (const char *str, char sep, int maxcount, int blength,
	     char buff[maxcount][blength])
{
  unsigned int i, j, k;
  if ((!str) || (!buff) || (maxcount < 1) || (blength < 2))
    {
      return (-3);
    }

  for (i = 0, j = 0, k = 0; str[i]; i++)
    {				/*for */
      if (str[i] != sep)
	{			/*if */
	  if (k >= (blength - 1))
	    {
	      return -2;
	    }
	  buff[j][k++] = str[i];

	  if (!str[i + 1])
	    {
	      buff[j++][k++] = 0;
	    }
	  else if (str[i + 1] == sep)
	    {
	      buff[j++][k] = 0;
	      k = 0;
	    }

	}			/*end if */
      if (j > maxcount)
	{
	  return -1;
	}

    }				/*end for */



  return j;
}

#endif

int
cutnl (char *str, char ch)
{
  int i;
  if (!str)
    {
      return 0;
    }
  for (i = 0; str[i]; i++)
    {
      if ((str[i] == 10) || (str[i] == 13))
	{
	  str[i] = ch;
	}
    }
  return 1;
}


char *
cutcharbe (char *str, char ch)
{

  int i, j;
  if (!str)
    {
      return ((char *) 0);
    }
  for (j = 0; str[j] == ch; j++)
    {
    }

  i = 0;
  while (str[i++])
    {
    }

  while (str[--i] == ch)
    {
    }
  str[i] = 0;

  return str + j;
}

