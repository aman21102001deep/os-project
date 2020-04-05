#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include<fcntl.h>

int main()
{
int q,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int LM[10],Z,j,arr[10],m[10],ae[10],B=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf(" Non-Preemtitive Shortest Job First Scheduling\n");
printf("\nEnter the Number of processes in Queue :");
scanf("%d",&n);

for(q=0;q<n;q++)
{
        
        printf("\nFor P%d\n",q+1);
	label:
        printf("Arrival time:");
        scanf("%d",&arr[q]);
	if (arr[q]==0)
	{
		printf("\n Arrival time should not be zero!!!! Re-enter the correct arrival time \n");
		goto label;
	}	
        LM[q]=arr[q]*2;
        printf("Burst Time:%d\n",LM[q]);
        printf("----------------------------------------");
}

for(q=0;q<n;q++)
{
	for(j=0;j<n;j++)
	{
		if(arr[q]<arr[j])
		{
			Z=p[j];
			p[j]=p[q];
			p[q]=Z;
			Z=arr[j];
			arr[j]=arr[q];
			arr[q]=Z;
			Z=LM[j];
			LM[j]=LM[q];
			LM[q]=Z;
		}
	}
}



for(j=0;j<n;j++)
{
	btime=btime+LM[j];
	min=LM[k];
		for(q=k;q<n;q++)
			{
			if (btime>=arr[q] && LM[q]>min)
				{
					Z=p[k];
					p[k]=p[q];
					p[q]=Z;
					Z=arr[k];
					arr[k]=arr[q];
					arr[q]=Z;
					Z=LM[k];
					LM[k]=LM[q];
					LM[q]=Z;
				}
			}
	k++;
}

m[0]=0;
for(q=1;q<n;q++)
{
		m[q]=0;
			m[q]+=LM[j];
		wsum+=m[q];
}

wavg=(wsum/n);
	for(q=0;q<n;q++)
	{
	B=B+LM[q];
	ae[q]=B-arr[q];
	tsum=tsum+ae[q];
	}

tavg=(tsum/n);

printf("\n RESULT:-");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(q=0;q<n;q++)
{
	printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[q],LM[q],arr[q],m[q],ae[q]);
}

printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f\n",tavg);
return 0;
}
