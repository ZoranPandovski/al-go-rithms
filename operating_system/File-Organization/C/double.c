struct file {
  char fname[10][10];
}*ind[10];

char uname[10][10];
int lastf[10]={0,0,0,0,0,0,0,0,0,0};


int usearch(){
  for (i = 0 ; i < 10 ; i++) {

    if(strcmp(name, uname[i]) == 0) {
      return i;
      break;
    }
  }
  return -1;
}
int fsearch(int currentuser){
  for (i = 0 ; i < 10 ; i++) {

    if(strcmp(name, ind[currentuser]->fname[i]) == 0) {
      return i;
      break;
    }
  }
  return -1;
}
void user(int currentuser){
  printf("\n\nUser %s\n",uname[currentuser]);

  printf(" 1.Create\n" );
  printf(" 2.Delete\n" );
  printf(" 3.Show\n");
  printf(" 4.Search\n");
  printf(" 0.Exit\n");
  printf("\tCHOOSE :");
  int opt,exit = 0;
  scanf("%d", &opt);

  switch (opt) {
    case 1:
      printf("File Name :" );
      scanf("%s", name);
      if( fsearch(currentuser) == -1) {

        strcpy(ind[currentuser]->fname[lastf[currentuser]], name);
        lastf[currentuser]++;
        printf("File Added\n" );
      }
      else
        printf("File already present\n");

      break;
    case 2:
      printf("File Name :" );
      scanf("%s", name);
      if( fsearch(currentuser) == -1) {
        printf("File Not Found\n" );
      }
      else {
        printf("File Deleted\n");
        strcpy(ind[currentuser]->fname[fsearch(currentuser)], "");
      }
      break;

    case 3:

      for (i = 0 ; i < 10 ; i++) {
        printf("%s\t",ind[currentuser]->fname[i]);
      }
      break;

    case 4:
    printf("File Name :" );
    scanf("%s", name);
    if( fsearch(currentuser) == -1) {
      printf("File Not Found\n" );
    }
    else
      printf("File Found\n");
    break;
    case 0: exit = 1; break;
    default: printf("Invalid option!! TRY AGAIN\n" ); user(currentuser);break;
  }
  if (exit != 1)
    user(currentuser);
}
int lastu=0;
void two(){
  int currentuser = -1;
  printf("\n\nOPTIONS\n");
  printf(" 1.Create User\n" );
  printf(" 2.Change User\n" );
  printf(" 3.Show Users\n" );
  printf(" 0.Exit\n");
  printf("\tCHOOSE :");
  int opt;
  int i;

  scanf("%d", &opt);

  switch (opt) {
    case 1:
    printf(" Name :" );
    scanf("%s", name);
    if( usearch() == -1) {
      strcpy(uname[lastu], name);
      ind[lastu] = (struct file*) malloc (sizeof(struct file));
      lastu++;
      printf("User Added\n" );
    }
    else
      printf("User already present\n");

    break;
    case 2:
      printf("User Name : " );
      scanf("%s", name);
      if( usearch() != -1) {
        currentuser = usearch();
        user(currentuser);
      }
      else
        printf("User Not found\n");

    break;
    case 3:
      for( i = 0 ; i < 10 ; i++ ) {
        printf("%s\t",uname[i]);
      }
      printf("\n" );
      break;
    case 0: exit(0);break;
      default: printf("Invalid option!! TRY AGAIN\n" ); two();break;
  }
  two();

}
