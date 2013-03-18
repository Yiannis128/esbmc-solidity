////Coefficients of a filter with limit cycle, |H|=2.0
#include <digitalfilter.h>

float a[] = { 1.0000f, -0.5f };
float b[] = { 1.0000f };
int k = 2; int l = 4;
int Na = 2; int Nb = 1;
float max = 1.0f; float min = -1.0f;
int xsize = 6;

int main(void) {
  overflow(a,b,k,l, Na, Nb, max, min, xsize);
//  limitCycle(a,b,k,l, Na, Nb, max, min, xsize);
//  timing(a,b,k,l, Na, Nb, max, min, xsize);
  return 0;
}

