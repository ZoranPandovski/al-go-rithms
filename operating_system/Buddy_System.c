#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
struct BuddyNode{//create a buddy tree node
  int size;//size of the node(memory size)
  int RIsallocated;//Right child allocation status
  int LIsallocated;//left child allocation status
  int processId;//process id of the stored process
  int processSize;//size of the process which is stored
  struct BuddyNode *left,*right;//pointer to the right and left child
};
struct BuddyNode* new_node(int val){//for any node instead of creating a node and assigning values each time use this function
//this will create a node and intialize the values to it
  struct BuddyNode* new_node=(struct BuddyNode*)malloc(sizeof(struct BuddyNode));
  new_node->right=NULL;
  new_node->left=NULL;
  new_node->size=val;
  new_node->processSize=0;
  new_node->processId=0;
  new_node->RIsallocated=0;
  new_node->LIsallocated=0;
}
int delete(struct BuddyNode** roo,int processID){
//for deleteing any process from the buddy tree
  int res;
  struct BuddyNode* root=*roo;//maintain a pointer to the root
  if(root->left==NULL&&root->right==NULL){//process should be in leaf nodes only
    if(root->processId==processID){
      printf("found\n");
      root->RIsallocated=0;//reset all the values as intail values of a node
      root->LIsallocated=0;
      root->processSize=0;
      root->processId=0;
      return 1;//return 1 that is for successfully deleted
    }
    else{
      return 0;
    }
  }
  res=delete(&root->left,processID);//otherwise find at the left part of the tree 
  if(res==1){//if found then check if the buddy means nearest same level node is also free if free then delete those nodes
  // root->left=NULL;
    if(root->right->LIsallocated==0&&root->right->RIsallocated==0&&root->right->left==NULL&&root->right->right==NULL){
      root->LIsallocated=0;
      root->RIsallocated=0;
      root->right=NULL;
      root->left=NULL;
      return 1;//return 1 for successful deletion
    }
  }
  res=delete(&root->right,processID);//if not found in the left part find in right part
  if(res==1){//if found then check if its brother node (buddy node ) is free or not if free then delete both
  //  root->right=NULL;
    if(root->left->LIsallocated==0&&root->left->RIsallocated==0&&root->left->left==NULL&&root->left->right==NULL){
      root->LIsallocated=0;
      root->RIsallocated=0;
      root->right=NULL;
      root->left=NULL;
      return 1;
    }
  }
  return 0;
}
int BuddyAllocation(struct BuddyNode** root,int process,int processId,int actualSize){
  struct BuddyNode* temp=*root;//assign temp to root of the buddy tree
  int flag;
  struct BuddyNode* new=NULL;//new node to null
//actaul size is nearest power of two of the process size
  if(temp->size<actualSize){// if the available space is less than the required one then error
    printf("Insufficient space Sorry!!!\n");
    return 0;
  }
  else if(temp->size==actualSize){
    if((temp->left==NULL)&&(temp->right==NULL)){//the processess are only allocted at the leafs of the buddy tree
      temp->size=actualSize;
      temp->processId=processId;
      temp->processSize=process;
      temp->RIsallocated=1;
      temp->LIsallocated=1;
      return 1;//return 1 for successfull insertion
    }
    else{
      return 0;
    }
  }
  else{//if not leaf size
    if(temp->LIsallocated==0){//if left child is not allocated
        if(temp->left==NULL){//if left child is not there
          temp->left=new_node((int)(temp->size/2));//create left and right nodes of size parentsize/2
          temp->right=new_node((int)(temp->size/2));
          flag=BuddyAllocation(&temp->left,process,processId,actualSize);//and make a recursive call on left part of the newly created part
          if(temp->left->LIsallocated==1 && temp->left->RIsallocated==1){//if left part's left and right child is allocated then left child allocation status is also one
            temp->LIsallocated=1;
          }
          if(flag==1){
            return 1;
          }
        }
        else{//if left part is there 
          flag=BuddyAllocation(&temp->left,process,processId,actualSize);//insert in left part of tree
          if(temp->left->LIsallocated==1&&temp->left->RIsallocated==1){
            temp->LIsallocated=1;
          }
          if(flag==1){
            return 1;
          }
        }
    }
    if(temp->RIsallocated==0){//if right part is not allocated 
      flag=BuddyAllocation(&temp->right,process,processId,actualSize);//insert at the right of the tree
      if(temp->right->LIsallocated==1 && temp->right->RIsallocated==1){
        temp->RIsallocated=1;
      }
      if(flag==1){
        return 1;
      }
    }
  return 0;
}
}
void printtree(struct BuddyNode *root){
  if(root->left==NULL&&root->right==NULL){
    printf("%d\t%d\t\t%d\t\t%d\t%d\n",root->size,root->processSize,root->processId,root->LIsallocated,root->RIsallocated);
  }
  else{
    printtree(root->left);
    printtree(root->right);
  }
}
int main(){
  int memorysize;
  printf("enter the size of the main memory(in power of two )\n");
  scanf("%d",&memorysize);
  int flag1=0;
  //int processId=0;
  struct BuddyNode *root=new_node(memorysize);
  int choice=0;
  while(choice!=4){
    printf("Enter your choice\n1.Add process\n2.Delete process\n3.print processess\n4.exit\n\n");
    scanf("%d",&choice);
    printf("####################################################\n");
    switch (choice) {
      case 1:{
        int processSize;
        int processId;
        printf("Enter process Size\n");
        scanf("%d",&processSize);
       printf("Enter process ID\n");
        scanf("%d",&processId);
        int actualSize;
        int x=1;
        int nearestpower=0;
        while(x<processSize){
          x=x*2;
          nearestpower+=1;
        }
        actualSize=x;
        printf("the actual size is %d\n",actualSize);
        flag1=BuddyAllocation(&root,processSize,processId,actualSize);
        if(flag1==1){
          processId+=1;
          printf("SIZE\tProcessSIZE\tPROCESSID\tLEFT\tRIGHT\t\n");
          printtree(root);

        }
        else{
          printf("Insufficent space\n");
        }
        break;
      }
      case 2:{
        printf("Enter process Id to delete the process\n");
        int pid;
        scanf("%d",&pid);
        delete(&root,pid);
        break;
      }
      case 3:{
        printf("printing the tree with buddy\n");
        printtree(root);
        break;
      }
      case 4:{
        printf("Exiting ............\n");
        exit(0);
        break;
      }
      default:{
        printf("Error Invalid choice\n");
        //exit(0);
        break;
      }
    }
  }

  return 0;
}
