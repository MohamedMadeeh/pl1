#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info {
char name[50];
int id,qu;

}; //DONE
void insertBook( struct info *information, int numberofbooks) {

FILE *pointerToBooks=fopen("books.txt","a");

   if(pointerToBooks!=NULL){
fflush(stdin);
printf("Enter book name :  ");
gets(information[numberofbooks].name);


printf("\n Enter book ID : ");
scanf("%d",&information[numberofbooks].id);


printf("Enter book quantity : ");
scanf("%d",&information[numberofbooks].qu);

fprintf(pointerToBooks,"\n %s %d %d",information[numberofbooks].name,information[numberofbooks].id,information[numberofbooks].qu);



}
  else{
   printf("ERROR IN OPINING FILE");
   }

fclose(pointerToBooks);


} // Display all books unsorted

void DisplayAllUNSORTED(struct info *information,int size){

for(int u=0;u<size;u++){
   printf("BOOK NAME :%s ID:%d quantity:%d \n",information[u].name,information[u].id,information[u].qu);

}
} //DONE
int searchBYid(struct info *information,int size ,int id,int u){

for(;u<size;u++){
if(information[u].id==id){fflush(stdin);


   printf("BOOK NAME :%s ID:%d quantity:%d \n",information[u].name,information[u].id,information[u].qu);
return 0 ;
}
if(information[u].id!=id){u++;
return searchBYid(information,size,id,u);
}

} printf("ID NOT FOUND \n");

}
void searchbyname(struct info *information,char * bookname,int size,int low){


 struct info h;
 for(int i=0;i<size-1;i++){

 int res = strcmp(information[i].name,information[i+1].name) ;

if(res>0){
h=information[i+1];
information[i+1]=information[i];
information[i]=h;

 }
 }






while(low<=size){ int mid=(size+low)/2;
 int res = strcmp(information[mid].name,bookname) ;
if(res==0){
   printf("BOOK NAME :%s ID:%d quantity:%d \n",information[mid].name,information[mid].id,information[mid].qu);
return ;

}

if(res>0){
 size= mid - 1;
}
if(res<0){
  low= mid + 1;
}
}
printf(" NOT FOUND \n");


}
void sortingbyname(struct info *information,int size){



 struct info h;
 for(int i=0;i<size-1;i++){

 int res = strcmp(information[i].name,information[i+1].name) ;

if(res>0){
h=information[i+1];
information[i+1]=information[i];
information[i]=h;

 }
 }

for(int g=0;g<size;g++){
   printf("BOOK NAME :%s ID:%d quantity:%d \n",information[g].name,information[g].id,information[g].qu);

}
 }//end of sorting by name


void deletebookbyid(struct info *information,int size){
int id;
struct info f[20];


printf("Enter id for deleting:");
scanf("%d",&id);
for(int i=0;i<size;i++){
if (information[i].id==id){
for(int a=i;a<size;a++){
information[a]=information[a+1];
}
}
}

FILE *pointerToBooks=fopen("books","w");

   if(pointerToBooks!=NULL){

for(int i=0;i<size-1;i++){
fprintf(pointerToBooks,"%s %d %d \n",information[i].name,information[i].id,information[i].qu);
}
printf("book deleted \n");




}
  else{
   printf("ERROR IN OPINING FILE");
   }
   fclose(pointerToBooks);

}
int main()
{
struct info information [20]; // struct  name
int i =0;
int numberOFbooks=4;
int choose; // user choice
char another; // if he want another operation
int id;
char book[50]; // in search by name function

FILE *pointerToBooks=fopen("books.txt","r");

   if(pointerToBooks!=NULL){

while(!feof(pointerToBooks)){
  fscanf(pointerToBooks,"%s %d %d",information[i].name,&information[i].id,&information[i].qu);

   i++;
}
}
  else{
   printf("ERROR IN OPINING FILE");
   }
  do{
   printf("choose the number of whatever you want\n 1- insert a book \n 2-Delet a book by id\n 3- search a book by id \n 4- searh a book by name\n 5- Display all books sorted by name \n 6- Display all books unsorted\n number of choice: ");
   scanf("%d", &choose);
   switch(choose){
   case 1 :
    insertBook(information,numberOFbooks);

    break;
    case 2: deletebookbyid(information,numberOFbooks);
    break;
    case 3:

printf("Enter book ID : ");
scanf("%d",&id);
int u=0;
searchBYid(information,numberOFbooks,id,u);
break;
case 4:
printf("ENTER BOOK NAME \n");
scanf("%s",book);
searchbyname(information,book,numberOFbooks,0);
break;
case 5: sortingbyname(information, numberOFbooks);
break;
case 6: DisplayAllUNSORTED(information,numberOFbooks);
break;
   }
   printf("do you want to perform any addition operator [y/n]\n");
   scanf("%s",&another);
   } while(another=='y'||another=='Y');
fclose(pointerToBooks);//end of programe
    return 0;
}

