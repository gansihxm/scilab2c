/*
**  -*- C -*-
**
** ssigna.c
** Made by  Bruno JOFRET <bruno.jofret@inria.fr>
**
** Started on  Fri Sep  7 17:30:57 2007 bruno
** Last update Fri Sep  7 17:35:32 2007 bruno
**
** Copyright INRIA 2007
*/

#include "sign.h"

int ssigna(float *in, int size) {
  int i = 0;
  int sign = 1;

  /* FIXME : Does it what it's supposed to do ? */
  for (i = 0 ; i < size ; ++i) {
    sign = sign * ssigns(in[i]);
  }
  return sign;
}