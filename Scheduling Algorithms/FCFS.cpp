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
First Come First Serve (FCFS) Scheduling Algorithm :
        -> FIFO
        -> MODEL : Non-preemptive (fully completion of one task before new task)
*/


int main ()
{

    int process_no, i ;

    cout<<"How many processes? : " ;
    cin>>process_no ;

    int Arrival_time[process_no+2], Brust_Time[process_no+2], Completion_Time[process_no+2], Waiting_Time[process_no+2], TurnAround_Time[process_no+2] ;

    cout<<"Get input of Arrival and Brust Time of each process at the same time :\n" ;
    for(i=1; i<=process_no; i++)
            cin>>Arrival_time[i]>>Brust_Time[i] ;

    Completion_Time[0] = 0 ;
    for(i=1; i<=process_no; i++)
    {
            int Idle_Time = 0 ;
            if(Completion_Time[i-1]<Arrival_time[i])
            {
                    Idle_Time = Arrival_time[i] - Completion_Time[i-1] ;
            }

            Completion_Time[i] = Completion_Time[i-1] + Brust_Time[i] + Idle_Time ;

            TurnAround_Time[i] = Completion_Time[i] - Arrival_time[i] ;         // process ta system e jotkkhn sthayi chilo

            Waiting_Time[i] = TurnAround_Time[i] - Brust_Time[i] ;
    }
    
    for(i=1; i<=process_no; i++)
            cout<<"Completion Time["<<i<<"] = "<<Completion_Time[i]<<endl ;
            cout<<endl ;

        for(i=1; i<=process_no; i++)
            cout<<"Turn Around Time["<<i<<"] = "<<TurnAround_Time[i]<<endl ;
            cout<<endl ;

        for(i=1; i<=process_no; i++)
            cout<<"Waiting Time["<<i<<"] = "<<Waiting_Time[i]<<endl ;


        return 0 ;
}
