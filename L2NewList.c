#include <stdio.h>

#define MAX_SIZE 100

int* double_array(int* A, int end); //implement this later!

void insert(int* A, int data, int position, int* endptr);

void rem(int* A, int position, int* endptr);

void write(int* A, int data, int i);

void read(int* A, int i);

void print_arr(int* A, int end);

int main(){
    int A[MAX_SIZE];    
    int end = -1;
    int code;
    do{
        printf("\nOPCODES: 1.insert(Data,Pos)\t2. rem(Pos)\t3. count\t 4. Write/Read(index)\n5. Print array\t6. Exit\n");
        scanf("%d",&code);
        switch(code){
            case 1:{
                int data, pos;
                scanf("%d %d",&data,&pos);
                insert(A, data, pos,&end);//end++ inside function only
                break;
            }
            case 2:{
                int pos;
                scanf("%d",&pos);
                rem(A,pos,&end);//end-- inside function only
                break;
            }
            case 3:{
                printf("Size of array is: %d\n",end+1);
                break;
            }
            case 4:{
                int sub_op;
                printf("0-write/1-read: ");
                scanf("%d",&sub_op);

                if (sub_op==0){
                    int data,i;
                    printf("Enter data and index to write at: ");
                    scanf("%d %d",&data,&i);
                    write(A, data, i);//variables can have same names in diff scopes? uses most local one?
                }
                else if (sub_op==1){
                    int i;
                    printf("Enter index to read from: ");
                    scanf("%d",&i);
                    read(A,i);
                }
                break;
            }
            case 5:{
                print_arr(A,end);
                break;
            }
            case 6:{
                break;
            }

        }
    }while(code!=6);
    return 0;

}

void insert(int* A, int data, int pos, int* end){
    int j = (*end)++;
    while(j>=pos){
        A[j+1]=A[j];
        j--;
    }
    A[pos]=data;
}

void rem(int* A, int pos, int* endptr){
    while(pos+1<=*endptr){
        A[pos]=A[pos+1];
        pos++;
    }
    (*endptr)--;
}

void write(int* A, int data, int i){
    A[i]=data;
}

void read(int* A, int i){
    printf("%d\n",A[i]);
}

void print_arr(int* A, int end){
    if (end<0){
        printf("Array size is 0. Nothing to print.\n");
    }
    else{
        for (int i=0;i<=end;i++){
            printf("%d ",A[i]);
        }
        printf("\n");
    }
}