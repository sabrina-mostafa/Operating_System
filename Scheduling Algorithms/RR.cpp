///  ~~~~~Bismillah'hir Rah'maanir Rahim~~~~~  ///

/*  "  Allah(SWT) blesses with knowledge whom he wants. "   */
/*  " Indeed with Hardship, comes Ease. "    */


///         Originator : Sabrina Mostafa
///         Dept. Of CSE
///         International Islamic University Chittagong




#include<bits/stdc++.h>
using namespace std ;

#define   FastRead      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   ULL               unsigned long long
#define   LL                  long long
#define   ST                  string
#define   F                    first
#define   S                    second
#define   PB                 push_back
#define   MP                make_pair
#define   pi                   acos(-1.0)
#define   NL                 "\n"
#define    _                    " "

int dx4 [ ] = {-1,   0,   0,  +1} ;
int dy4 [ ] = { 0,  -1,  +1,  0} ;
int dx [ ] = {-1,  -1,  -1,   0,   0,  +1,  +1,  +1} ;
int dy [ ] = {-1,   0,  +1,  -1,  +1,  -1,   0,  +1} ;





/*
Round Robin (RR) Scheduling Algorithm :
        -> CRITERIA : " Time Quantum "
        -> MODEL : Preemptive (Completion of a task only equal to timeQuantum unit of time)
        -> Context Switching happens.
*/



/// This Code works properly only when the Arrival Time is sequential :(

int main ()
{
    int count=0, temp ;

    int process_no, i, j, timeQuantum, Execution_Time=0 ;
    float avg_tat=0, avg_wt=0, t_tat=0, t_wt=0 ;

    cout<<"How many processes? : " ;
    cin>>process_no ;

    int Process[process_no+2], Arrival_time[process_no+2], Brust_Time[process_no+2], rem_b[process_no+2] ;
    int Completion_Time[process_no+2], TurnAround_Time[process_no+2], Waiting_Time[process_no+2] ;

    cout<<"Enter Process Sequence : " ;
    for(i=0; i<process_no; i++)
        cin>>Process[i] ;

    cout<<"Enter Arrival Time : " ;
    for(i=0; i<process_no; i++)
        cin>>Arrival_time[i] ;

    cout<<"Enter Brust Time : " ;
    for(i=0; i<process_no; i++)
    {
        cin>>Brust_Time[i] ;
        rem_b[i] = Brust_Time[i] ;                   // For calculating remaining Brust Time
    }

    cout<<"Enter Quantum time : " ;
    cin>>timeQuantum ;

    for(i=0; i<process_no; i++)
    {
        for(j=i+1; j<process_no; j++)
        {
            if(Arrival_time[i]>Arrival_time[j])
            {
                swap(Process[i], Process[j]) ;
                swap(Arrival_time[i], Arrival_time[j]) ;
                swap(Brust_Time[i], Brust_Time[j]) ;
                swap(rem_b[i], rem_b[j]) ;
            }
        }
    }

    while(1)
    {
        //count=0 ;
        for(i=0, count=0; i<process_no; i++)
        {
            temp  = timeQuantum ;
            if(rem_b[i]==0)
            {
                count++ ;
                continue ;
            }
            if(rem_b[i] > timeQuantum)
            {
                rem_b[i] -= timeQuantum ;           //  process will only work = timeQuantum Unit
            }
            else
            {
                if(rem_b[i] >= 0)
                {
                    temp = rem_b[i] ;
                    rem_b[i]=0 ;
                }
            }

            Execution_Time += temp ;            //  or Completion Time
            Completion_Time[i] =  Execution_Time ;
        }
        if(count == process_no)
            break ;
    }
    cout<<"Completion Time : \n" ;
    for(i=0; i<process_no; i++)
    {
        cout<<" P["<<Process[i]<<"] = "<<Completion_Time[i]<<endl ;
        TurnAround_Time[i] = Completion_Time[i] - Arrival_time[i] ;
    }

    cout<<"Process No\t\t Arrival Time \t\t Brust Time \t\t TurnAround Time \t\t waiting Time\n" ;
    for(i=0; i<process_no; i++)
    {
        t_tat +=TurnAround_Time[i] ;
        Waiting_Time[i] = TurnAround_Time[i] - Brust_Time[i] ;
        t_wt += Waiting_Time[i] ;
        cout<<" P["<<Process[i]<<"]\t\t\t\t"<<Arrival_time[i]<<"\t\t\t"<<Brust_Time[i]<<"\t\t\t"<<TurnAround_Time[i]<<"\t\t\t\t"<<Waiting_Time[i]<<endl ;
    }

    avg_tat = t_tat/process_no ;
    avg_wt = t_wt/process_no ;
    cout<<"\nAvarage TurnAroung Time : "<<avg_tat<<endl ;
    cout<<"AvarageWaiting Time : "<<avg_wt<<endl ;


    return 0 ;
}


/*
Sample :
How many processes? : 4
Enter Process Sequence : 1 2 3 4
Enter Arrival Time : 0 1 2 3
Enter Brust Time : 5 4 2 1
Enter Quantum time : 2
*/
