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
Shortest Job First (SJF) Scheduling Algorithm :
        -> CRITERIA : "Brust Time"
        -> MODEL : Non-preemptive (fully completion of a task before new task)
*/


int main ()
{

    int process_no, temp, Firts_arraival, index, i, j ;
    float avg_tat=0, avg_wt=0, t_tat=0, t_wt=0 ;

    cout<<"How many processes? : " ;
    cin>>process_no ;

    int Process[process_no+2], Arrival_time[process_no+2], Brust_Time[process_no+2], Completion_Time[process_no+2], TurnAround_Time[process_no+2], Waiting_Time[process_no+2] ;

    cout<<"Enter Process Sequence : " ;
    for(i=0; i<process_no; i++)
        cin>>Process[i] ;

    cout<<"Enter Arrival Time : " ;
    for(i=0; i<process_no; i++)
        cin>>Arrival_time[i] ;

    cout<<"Enter Brust Time : " ;
    for(i=0; i<process_no; i++)
        cin>>Brust_Time[i] ;

    for(i=0; i<process_no; i++)
    {
        for(j=i+1; j<process_no; j++)
        {
            if(Brust_Time[i]>Brust_Time[j])
            {
                swap(Process[i], Process[j]) ;
                swap(Arrival_time[i], Arrival_time[j]) ;
                swap(Brust_Time[i], Brust_Time[j]) ;
            }
        }
    }

    Firts_arraival = Arrival_time[0] ;
    for(i=0; i<process_no; i++)
    {
        if(Firts_arraival>Arrival_time[i])
        {
            Firts_arraival = Arrival_time[i] ;
            index = i ;                          ///  index of  1st arrived process
        }
    }

    temp = Firts_arraival ;                              ///  arrival time of 1st arrived process
    Completion_Time[index] = temp + Brust_Time[index] ;
    temp = Completion_Time[index] ;

    for(i=0; i<process_no; i++)
    {
        if(i != index)
        {
            Completion_Time[i] = temp  + Brust_Time[i] ;
            temp = Completion_Time[i] ;
        }
    }

    cout<<"Process No\t\tArrival Time\t\t  Brust Time\t\tTurnAround Time\t\tWaiting Time \n" ;
    for(i=0; i<process_no; i++)
    {
        TurnAround_Time[i] = Completion_Time[i] - Arrival_time[i] ;
        t_tat += TurnAround_Time[i] ;
        Waiting_Time[i] = TurnAround_Time[i] - Brust_Time[i] ;
        t_wt += Waiting_Time[i] ;

        cout<<"    P["<<Process[i]<<"]\t\t\t"<<Arrival_time[i]<<"\t\t\t"<<Brust_Time[i]<<"\t\t\t"<<TurnAround_Time[i]<<"\t\t\t"<<Waiting_Time[i]<<endl ;
    }

    avg_tat = t_tat/process_no ;
    avg_wt = t_wt/process_no ;
    cout<<"\nAvarage TurnAroung Time : "<<avg_tat<<endl ;
    cout<<"Avarage Waiting Time : "<<avg_wt<<endl ;


    return 0 ;
}
