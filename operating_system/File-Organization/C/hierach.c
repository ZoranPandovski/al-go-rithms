#define KGRN  "\x1B[32m"
#define KNRM  "\x1B[0m"

struct dir {
  char fname[10][10];
  struct dir *subdir[10];
  char dname[10][10];
  int lastf, lastd;
  struct dir *prev;
}*root = NULL, *current,*ptr;
char location[10][10],name[10];
int lastLoc = 0;

void pwd() {
  printf("\nAddress : ");
  for(i = 0; i <= lastLoc ; i++)
    printf("/%s",location[i]);
  printf("\n");
}

void directory();
int dirSearch(struct dir *loc){
  for (i = 0 ; i < 10 ; i++) {

    if(strcmp(name, loc -> dname[i]) == 0) {
      return i;
      break;
    }
  }
  return -1;
}

int fileSearch(struct dir *loc){
  for (i = 0 ; i < 10 ; i++) {

    if(strcmp(name, loc -> fname[i]) == 0) {
      return i;
      break;
    }
  }
  return -1;
}

// Memory allocation and preparation
struct dir *alloc(struct dir *loc){
  struct dir *temp;
  temp = (struct dir*) malloc (sizeof(struct dir));
  temp -> lastf = 0;
  temp -> lastd = 0;
  temp -> prev = loc;
  return temp;
}

void hierarichal() {
  if(root == NULL) {
    root = (struct dir*) malloc (sizeof(struct dir));
    root -> lastf = 0;
    root -> lastd = 0;
    root -> prev = NULL;
    current = root;
  }
  directory();
}




void directory() {
  while (1) {
    system("clear");
    pwd();
    printf(" 1.MKDIR\n" );
    printf(" 2.RMDIR\n" );
    printf(" 3.TOUCH\n");
    printf(" 4.RM\n");
    printf(" 5.ls\n");
    printf(" 6.Search\n");
    printf(" 7.CD\n");
    printf(" 8.CD ..\n");
    printf(" 0.Exit\n");
    printf("\tCHOOSE :");
    int opt,i;
    scanf("%d", &opt);

    switch (opt) {
      case 1:
        printf("Directory Name :");
        scanf("%s", name);
        if(dirSearch(current) == -1) {
          ptr = alloc(current);
          strcpy(current -> dname[current -> lastd], name);
          current -> subdir[current -> lastd] = ptr;
          current -> lastd++;
          printf("MKDIR Success\n");
        }
        else
          printf("Directory already present\n" );
        break;

      case 2:
        printf("Directory Name :");
        scanf("%s", name);
        if(dirSearch(current) != -1) {
          i = dirSearch(current);
          free(current -> subdir[i]);
          strcpy(current -> dname[i], "");
          printf("Deleted\n");
        }
        else
          printf("Directory not found\n" );
        break;

      case 3:
        printf("File Name :");
        scanf("%s", name);
        if(fileSearch(current) == -1) {
          strcpy(current -> fname[current -> lastf], name);
          current -> lastf++;
          printf("TOUCH Success\n");
        }
        else
          printf("File already present\n" );
        break;

      case 4:
        printf("File Name :");
        scanf("%s", name);
        if(fileSearch(current) != -1) {
          i = fileSearch(current);
          strcpy(current -> fname[i], "");
          printf("Deleted\n");
        }
        else
          printf("File Not Found\n" );
        break;

        case 5:
          printf("Folders :\n");
          for (i = 0 ; i < current -> lastd ; i++) {
            printf("%s%s%s\t",KGRN,current->dname[i],KNRM);
          }
          printf("Files :\n");
          for (i = 0 ; i < current -> lastf ; i++) {
            printf("%s\t",current->fname[i]);
          }
          break;

        case 6:
          printf("Under Construction\n");
          break;

        case 7:
          printf("Directory Name :");
          scanf("%s", name);
          if(dirSearch(current) != -1) {
            i = dirSearch(current);
            printf("%d",i);
            strcpy(location[lastLoc], current -> dname[i]);
            lastLoc++;
            current = current -> subdir[i];
          }
          else
            printf("No Such Dir\n" );
          break;
        case 8:
          if( current -> prev != NULL ) {
            current = current -> prev;
            lastLoc--;
          }
          break;
        case 0:exit(0);break;
        default: printf("Bro WTF u Just Entered\n");
    }
  }
}
