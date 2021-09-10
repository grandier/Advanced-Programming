#include <stdio.h>  
#include <stdlib.h>
   
// Kemas Rafly Omar Thoriq 2006577422

struct node{  
    int data;  
    char *s;
    int urutan;
    struct node *next;  
};      
   
struct node *head, *tail = NULL;  
 
void addNode(char *s, int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->s = s;
    newNode->next = NULL;  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    }  
}  
   
void sortList() {  
    //Node current will point to head  
    struct node *current = head, *index = NULL;  
    int temp;  
    char temp1[100];
          
    if(head == NULL) {  
        return;  
    }  
    else {  
        while(current != NULL) {  
                  
            index = current->next;  
                
            while(index != NULL) {  
                    
                if(current->data < index->data) {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                        
                    strcpy(temp1,current->s);
            		strcpy(current->s,index->s);
            		strcpy(index->s,temp1);
                }
				else if(current->data == index->data && strcmpi(current->s,index->s)>0) {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                        
                    strcpy(temp1,current->s);
            		strcpy(current->s,index->s);
            		strcpy(index->s,temp1);
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }  
}  

void display() {    
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    while(current != NULL) {  
        printf("%s ", current->s);
        printf("%d \n", current->data);  
        current = current->next;  
    }  
    printf("\n");  
} 

void search(){
	int cek;
	printf("\nSearching...\n");
	printf ("\nMasukkan rank: ");
	scanf ("%d", &cek);
	
	struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    } 
	while(current != NULL) { 
		if(cek == current->urutan){
			printf("%s dengan gaji %d", current->s, current->data); 
			break;
		}
		else{
			current = current->next;
		}
    }  
}

void traverseList()
{
    struct node *temp;
	int i=1;
    // Return if list is empty 
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    
    temp = head;
    while(temp != NULL)
    {
        temp->urutan = i;
        i++;
        temp = temp->next;                 
    }
}
      
int main()  
{  
	int k, i, j, temp1, cek, quit;
	char str[100][25], temp2[100];;
	int gaji[100];

    printf ("Masukkan jumlah karyawan: ");
	scanf ("%d", &k);
	
	for (i=0;i<k;i++){
		scanf("%s", &str[i]);
		scanf("%d", &gaji[i]);
	}
	
	for(i=0;i<k;i++){
		addNode(str[i], gaji[i]);  
	}
      
    //Displaying original list  
    printf("\n\nOriginal list: \n");  
    display();  
      
    //Sorting list  
    sortList();  
      
    //Displaying sorted list  
    printf("\nSorted list: \n");  
    display(); 
	
	traverseList();
	do{
		search();
		printf("\n\nJika tidak ingin lanjut searching tekan -1, jika iya masukan angka berapa saja: ");	
		scanf("%d", &quit);
	}while(quit != -1);

    return 0;  
}  
