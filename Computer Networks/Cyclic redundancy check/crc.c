#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int * modulo(int arr1[],int arr2[],int a,int d,int g);
int * encode(int arr1[],int arr2[],int a,int d,int g);
int * decode(int arr1[],int arr2[],int a,int d,int g);
int * main()
{
 int *en=malloc(sizeof(10));
 int *de=malloc(sizeof(10));
 int D[10],D1[10],G[10],G1[10],d,bits,g,i,j,a,tem;
 clrscr();
 printf("Enter the size of the data");
 scanf("%d",&d);
 printf("Enter the size of the generator");
 scanf("%d",&g);
 printf("Enter the data");
 for(i=0; i<d; i++)
 {
  scanf("%d",&D[i]);
 }
 for(j=0; j<d; j++)
 {
  D1[j]=D[j];
 }
 printf("Enter the generator");
 for(i=0; i<g; i++)
 {
 scanf("%d",&G[i]);
 }
 for(j=0; j<g; j++)
 {
   G1[j]=G[j];
 }
 bits=g-1;
 a=d+bits;
 en=encode(D,G,a,d,g);
 for(i=d; i<a; i++)
 {
   tem=i;
   for(j=0; j<g; j++)
   {
     D1[tem]=en[j+1];
     tem=tem+1;
   }
   break;
 }
 printf("\n");
 de=decode(D1,G1,a,d,g);
 getch();
 return 0;
 }

 int * encode(int D[],int G[],int a,int d,int g)
 {
   int *num=malloc(sizeof(10));
   int i,j;
   for(i=d; i<a; i++)
   {
     D[i]=0;
   }
  num = modulo(D,G,a,d,g);
  printf("\nAfter encoding:");
  for(i=0; i<g; i++)
  {
   printf("%d",num[i]);
  }

   return num;
}

 int * decode(int D1[],int G1[],int a,int d,int g)
 {
  int *res=malloc(sizeof(10));
  int i,j,k=0;
  res=modulo(D1,G1,a,d,g);
  printf("\nAfter decoding:");
  for(i=0; i<g; i++)
  {
    printf("%d",res[i]);
  }
  for(i=0; i<g; i++)
  {
    if(res[i]==1)
    {
      k++;
    }
  }
  if(k>0)
  {
    printf("\nThere is error in the message");
  }
  else
  {
   printf("\nThere is no error in the message");
  }
  return 0;
}


int *modulo(int D[],int G[],int a,int d,int g)
{
  int i,j,k,temp,b=a-1;
  int *rem=malloc(sizeof(10));
  for(i=0; i<d; i++)
 {
  temp=i;
  if(D[i]==1 && b>0)
  {
   for(j=0; j<g; j++)
   {
    if(D[temp]==G[j])
    {
      D[temp]=0;
      rem[j]=0;
    }
    else
    {
     D[temp]=1;
     rem[j]=1;
    }
    temp=temp+1;
   }
   b=b-1;
  }
}
 return rem;
}
