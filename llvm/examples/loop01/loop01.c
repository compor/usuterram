
void foo() {
  int i = -1;
  int j = 0;
  int k = 3;

  for(j = 0; j < 5; j++)
    for(i = 0; i < 5; i++)
      for(k = 0; k < 5; k++)
        i + j + k;

  for(i = 0; i < 10; i++)
    i;

  for(j = 0; j < 5; j++)
    for(i = 0; i < 5; i++)
      i + j;
}

