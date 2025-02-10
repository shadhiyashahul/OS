#include<stdio.h>
#include<string.h>
typedef struct process
{
 int pid,at,bt,ct,tt,wt;
}sjf;
void getprocess(sjf p[100],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("enter the p_id:\t");
  scanf("%d",&p[i].pid);
  printf("enter the at:\t");
  scanf("%d",&p[i].at);
  printf("enter the bt:\t");
  scanf("%d",&p[i].bt);
 }
}
void sort_at(sjf p[100],int n)
{
 int i,j;
 sjf temp;
 for(int i=0;i<n-1;i++)
 {
 for(int j=0;j<n-i-1;j++)
 {
 if(p[j].at>p[j+1].at)
 {
  temp=p[j];
  p[j]=p[j+1];
  p[j+1]=temp;
 }
 }
 }
}

void sort_bt(sjf p[100],int n)
{
 int i,j;
 sjf temp;
 for(int i=0;i<n-1;i++)
 {
 for(int j=0;j<n-i-1;j++)
 {
 if(p[j].bt>p[j+1].bt)
 {
 temp=p[j];
 p[j]=p[j+1];
 p[j+1]=temp;
 }
 }
 }
}
void complete(sjf p[100],int n)
 {
 int i, t = 0, completed = 0, min_idx;
 int is_completed[100] = {0};
 while(completed < n)
 {
  min_idx = -1;
  for(i= 0; i < n; i++)
  {
  if(!is_completed[i] && p[i].at <= t)
  { 
  if(min_idx == -1 || p[i].bt < p[min_idx].bt)
  {
  min_idx = i;
  }
  }
  }
 if(min_idx == -1)
  {
   t++;
  continue;
  }
  t += p[min_idx].bt;
  p[min_idx].ct = t; 
  p[min_idx].tt = p[min_idx].ct - p[min_idx].at;  
  p[min_idx].wt = p[min_idx].tt - p[min_idx].bt;  
 is_completed[min_idx] = 1;  
 completed++;
 }
}
void tt(sjf p[100],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  p[i].tt=p[i].ct-p[i].at;
 }
}
void wt(sjf p[100],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  p[i].wt=p[i].tt-p[i].bt;
 }
}

void display(sjf p[100],int n)
{
 int i;
 printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTT\t\tWT\n");
 for(i=0;i<n;i++)
 {
  printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
 }
}
void gantt(sjf p[100],int n)
{
 int i,t=0;
 printf("Gantt Chart:\n");
 for (i=0;i<n;i++)
 {
  if (t<p[i].at) 
  {
   printf("| IDLE ");
   t = p[i].at;
  }
  printf("|P%d",p[i].pid);
  t+=p[i].bt;
 }
  printf("|\n");
  printf("0");
  t=0;
  for(i=0;i<n;i++)
  {
   if(t<p[i].at)
   {
    t=p[i].at;
    printf("%d",t);
   }
    t+=p[i].bt;
    printf("%d",t);
  }
  printf("\n");
}
int main()
{
 sjf p[100];
 int n,i;
 float avgtt=0,avgwt=0;
 printf("Enter the no: of process");
 scanf("%d",&n);
 getprocess(p,n);
 sort_at(p,n);
 sort_bt(p,n);
 complete(p,n);
 tt(p,n);
 wt(p,n);
 gantt(p,n);
 display(p,n);
 for(i=0;i<n;i++)
 {
  avgtt+=p[i].tt;
  avgwt+=p[i].wt;
 }
 printf("\n The average turnaround time is%f",avgtt/n);
 printf("\n The average waiting time is %f",avgwt/n);
 return 0;
}
 
 









