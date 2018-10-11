
char fname[10][10], name[10], j = 0,i;
int search(){
  for (i = 0 ; i < 10 ; i++) {

    if(strcmp(name, fname[i]) == 0) {
      return i;
      break;
    }
  }
  return -1;
}

void single() {

  printf("\n\nOPTIONS\n");
  printf(" 1.Create\n" );
  printf(" 2.Delete\n" );
  printf(" 3.Show\n");
  printf(" 4.Search\n");
  printf(" 0.Exit\n");
  printf("\tCHOOSE :");
  int opt;
  scanf("%d", &opt);

  switch (opt) {
    case 1:
      printf("File Name :" );
      scanf("%s", name);
      if( search() == -1) {
        strcpy(fname[j], name);
        j++;
        printf("File Added\n" );
      }
      else
        printf("File already present\n");

      break;
    case 2:
      printf("File Name :" );
      scanf("%s", name);
      if( search() == -1) {
        printf("File Not Found\n" );
      }
      else {
        printf("File Deleted\n");
        strcpy(fname[search()], "");
      }
      break;

    case 3:

      for (i = 0 ; i < 10 ; i++) {
        printf("%s\t",fname[i]);
      }
      break;

    case 4:
    printf("File Name :" );
    scanf("%s", name);
    if( search() == -1) {
      printf("File Not Found\n" );
    }
    else
      printf("File Found\n");
    break;
    case 0: exit(0);break;
    default: printf("Invalid option!! TRY AGAIN\n" ); single();break;
  }
  single();
}
