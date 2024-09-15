#include<stdio.h>
#include<stdlib.h>
//#include<process.h>

struct node{
        int info;
        struct node* next;
};
typedef struct node* Node;

Node insert_front(int item, Node first){
    Node temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info = item;
    temp->next = first;
    printf("Element %d added succesfully!\n",item);
    return temp;
}

Node insert_rear(int item,Node first){
    Node temp = (struct node*)malloc(sizeof(struct node));
    temp->info= item;
    temp->next =NULL;
    
    if(first==NULL) {
        return temp;
    }
    
    Node recur = first;
    while(recur->next!= NULL){
        recur = recur->next;
    }
    recur->next =temp;
    return first;
}

Node delete_front(Node first){
    if(first == NULL){
        printf("The list is empty");
        return first;
    }
    Node temp;
    temp = first;
    temp = first->next;
    free(first);
    return temp;
}

void display(Node first){
    Node temp;
    temp = first;
    if(first == NULL){
        printf("List is empty!\n");
    }

    printf("The contents of the singly linked lists are:\t");
    
    
    while(temp!=NULL){
        printf(" %d ",temp->info);
        temp=temp->next;
    }
    printf("\n");
    
}

Node delete_rear(Node first){
    Node cur = first;
    Node prev = NULL;
    if(first == NULL){
        printf("The list is empty!\n"); return first;
    }
    if(first->next == NULL){
        free(first);
        return NULL;
    }
    while(cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }
    free(cur);
    prev->next = NULL;
    return first;
}


int main(){
    Node first = NULL;
    
    int item,choice;
    
    while(1){
        printf("Enter your choice : \n (1) Enter front  (2)Delete front (3)Enter rear (4)delete rear (5)Display  (6)Exit- \n\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element:");
                        scanf("%d",&item);
                        first = insert_front(item,first);
                        break;
            
            case 2: first = delete_front(first);
                    break;
            case 3: printf("Enter the element:");
                        scanf("%d",&item);
                        first = insert_rear(item,first);
                        break;
            case 4: first = delete_rear(first);
                    break;
        
            case 5: display(first);
                    break;
                    
            case 6: exit(0);
        }
    }
    return 0;
}














