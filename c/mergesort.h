#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int b[], int c[], int m, int n);
void mergesort(int key[], int n);
void wrt(int key[], int sz);

#endif