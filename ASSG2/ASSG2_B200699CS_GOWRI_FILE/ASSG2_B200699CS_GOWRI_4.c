#include<stdio.h>
void InsertionSortAs (int *B)
{
  int i=0, temp, k, j=0;
   while (B[i] < 9900)
    {
      j++;
      i++;
    }

  
  for (i = 1; i < j; i++)
    {
      temp = B[i];
      k = i - 1;
      while (temp < B[k] && k >= 0)
	{
	  B[k + 1] = B[k];
	  k--;
	}
      B[k + 1] = temp;

    }
}

void InsertionSortDs (int *C)
{
  int i = 0, temp, j, k=0;
  while (C[i] < 9900)
    {
      k++;
      i++;
    }
 
  for (i = 1; i < k; i++)
    {
      temp = C[i];
      j = i - 1;
      while (temp < C[j] && j >= 0)
	{
	  C[j + 1] = C[j];
	  j--;
	}
      C[j + 1] = temp;

    }
 int D[k];
 for(i=0;i<k;i++)
 {D[i]=C[k-1-i];}
  for(i=0;i<k;i++)
 {C[i]=D[i];}
}

void Print (int A[])
{
  int n;
  scanf ("%d", &n);
  int i, j = 0, k = 0;
  if (n % 2 == 0)
    {
      j = n / 2;
      k = n / 2;
    }
  else
    {
      k = n / 2;
      j = (n / 2) + 1;
    }
    j+=1;k+=1;
  int B[j], C[k];

  int x = 0, y = 0, junk = 9900;
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &A[i]);
      if (i % 2 == 0)
	{
	  B[x] = A[i];
	  x++;
	}
      else
	{
	  C[y] = A[i];
	  y++;
	}
    }
  for (i = x; i < j; i++)
    {
      B[i] = junk;
      junk++;
    }
  for (i = y; i < k; i++)
    {
      C[i] = junk;
      junk++;
    }
  
  InsertionSortAs (B);
  InsertionSortDs (C);
  for (i = 0; i < x; i++)
    {
      printf ("%d ", B[i]);
    }
  printf ("\n");
  for (i = 0; i < y; i++)
    {
      printf ("%d ", C[i]);
    }
}

int
main ()
{
  int X[1000];


  Print (X);

  return 0;
}
