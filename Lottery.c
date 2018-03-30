#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define BUFFER_SIZE 1024 


void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 

 
void shuffle ( int arr[], int n )
{
    
    srand ( time(NULL) );
 
    
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
 
        swap(&arr[i], &arr[j]);
    }
}


int main() 
{ 
    char buffer[BUFFER_SIZE];
    char *record, *line;
    int i = 0, j = 0;
    FILE *fstream = fopen("Input-1.txt", "r");
    if (fstream == NULL)
    {
        printf("\n file opening failed ");
        return -1;
    }
    int time_quantum = atoi(fgets(buffer, sizeof(buffer), fstream));
    int totalTickets = atoi(fgets(buffer, sizeof(buffer), fstream));
   // printf("%d\n%d\n",quantum,totalTickets);

    int count,n,time,remain,flag=0; 
  int wait_time=0,turnaround_time=0,at[50],bt[50],rt[50]; 
 
  int idx = 0;
  int tk[totalTickets];
  int idx2=0;
    while ((line = fgets(buffer, sizeof(buffer), fstream)) != NULL)
    {
        record = strtok(line, ",");
        int i;
        int pid;
        int arrivalTime;
        int burstTime;
        int tickets;
        for (i = 0; record != NULL; ++i)
        {
            if (i == 0)
                pid = atoi(record);
            if (i == 1)
                arrivalTime = atoi(record);
            if (i == 2)
                burstTime = atoi(record);
            if (i == 3)
                tickets = atoi(record);

            record = strtok(NULL, ",");
        }

    at[idx]=arrivalTime;
    bt[idx]=burstTime;
    rt[idx]=bt[idx];
    for(int l=0;l<tickets;l++)
        tk[idx2++]=pid;
    
    idx++;



    }
    n=idx;
    remain=n; 



shuffle(tk,totalTickets);



 time =0 ;
for(int i=0;i<totalTickets;i++){
    int pid = tk[i]-1;
    if(rt[pid]<=0)continue;
    if(rt[pid]>0){
        printf("Time %d : P %d Entering quantum \n",time,pid+1);
    }
    if(rt[pid]<=time_quantum){

        time+=rt[pid];
        wait_time+=time-at[pid]-bt[pid]; 
        turnaround_time+=time-at[pid]; 
        rt[pid]=0;
    }else{
        rt[pid]-=time_quantum;
        time+=time_quantum;
    }


}
printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f\n",turnaround_time*1.0/n); 



  return 0; 
}
