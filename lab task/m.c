#include <stdio.h>
#include <stdbool.h>


int plength;


void print_gantt_chart(int[], int[], int, int);
void calculate_avg(int[], int[], int, int, int[], int[]);
void main(void) {

    int pavt[200];
    int pbt[200];

    printf("Enter Total # Of Process: ");
    scanf("%d", &plength);

   for (int i=0;i<plength;i++)
    {
        printf("--- PROCESS #%d ----\n", i+1);
        printf("Enter Arrival Time: ");
        scanf("%d,",&pavt[i]);
        printf("Enter Burst Time: ");
        scanf("%d,",&pbt[i]);
    }


    for (int i=plength;i<plength*2;i++) {
        pbt[i] = pbt[i-plength];
    }
    //Calculate total Burst time.
    int tbt;
    for (int i=0;i<plength;i++)
    {
        tbt = tbt + pbt[i];
    }
    int burst;
    int gcp[20];
    int gcv[20];
    int previous=0;
    int gcpos = 0;

    while (burst!=tbt+1) {
            //Check for all process
             int active=0;
            int activepbt=pbt[0];
           if (pbt[0]==0)
           {
                int j=0;
                bool finished = true;
            while(finished)
            {
                if (pbt[j]!=0)
                {
                    finished=false;
                    break;
                }
                j++;
            }
            active=j;
            activepbt = pbt[j];
           }
            for (int i=0;i<plength;i++) {
                if ((pbt[i] < activepbt) && (burst>=pavt[i]) && (pbt[i]!=0)) {
                    active = i;
                    activepbt = pbt[i];
                }
            }

           if (previous!=active) {
                    gcp[gcpos] = previous;
                    gcv[gcpos] = burst;
                    gcpos++;

           }
                    pbt[active]--;
                    previous = active;
                    burst++;
            }

            pbt[plength]++;

            print_gantt_chart(gcp, gcv, gcpos, tbt);
           calculate_avg(gcp, gcv, gcpos, tbt, pavt, pbt);
    }

void print_gantt_chart(int gcp[], int gcv[], int gcpos, int tbt) {
            printf("\n\n---------- GANTT CHART -----------\n\n");
            for (int i=0;i<gcpos*8;i++)
            {
             printf("-");
            }
            printf("\n");
                for (int i=0;i<gcpos;i++)
            {
                    printf("|P%d\t", (gcp[i]+1));
            }
             printf("|");
            printf("\n");
            for (int i=0;i<gcpos*8;i++)
            {
             printf("-");
            }
            printf("\n");
            printf("0\t");
            for (int i=0;i<gcpos;i++) {
                printf(" %d\t", gcv[i]);
            }
            printf("\n");
        }

        void calculate_avg(int gcp[], int gcv[], int gcpos, int tbt, int pavt[], int pbt[] ) {
                //turn around time
                int turn_around[plength];
                int waiting_time[plength];
                for (int i=0;i<plength;i++)
                {
                    int findgcp=0;
                    for (int j=0;j<gcpos;j++)
                    {
                        if (gcp[j]==i) {
                                findgcp = j;
                        }
                    }
                    turn_around[i] = gcv[findgcp]-pavt[i];
                    waiting_time[i] = turn_around[i] - pbt[plength+i];
                }
                printf("\n\n-----------  TURN AROUND TIME -----------\n");
                double avgtat,avgwt;
                avgtat=avgwt=0;
                for (int i=0;i<plength;i++)
                {
                    printf("Process#%d:\t%d\n", i+1,turn_around[i]);
                    avgtat+=turn_around[i];
                }
                    printf("\nAverage Turn Around Time: %.2f",avgtat/plength);
                printf("\n-----------  WAITING TIME -----------\n");
                for (int i=0;i<plength;i++)
                {
                    printf("Process#%d:\t%d\n", i+1,waiting_time[i]);
                    avgwt+=waiting_time[i];
                }
                printf("\nAverage Waiting Time: %.2f",avgwt/plength);


        }
