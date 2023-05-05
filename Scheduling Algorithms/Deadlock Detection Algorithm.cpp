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






// *****        Deadlock Detection Algorithm    *****


int main ()
{
    int process_no, resource_no, i, j ;
    cout<<"How many processes? : " ;
    cin>>process_no ;
    cout<<"How many resources? : " ;
    cin>>resource_no ;

    int Allocation[process_no+2][resource_no+2], Request[process_no+2][resource_no+2] ;
    int Availability[resource_no+2] ;
    vector<int>safe_Seq ;

    cout<<"\nEnter Allocation : \n" ;
    for(i=1; i<=process_no; i++)
    {
        cout<<"For process ["<<i<<"] : " ;
        for(j=1; j<=resource_no; j++)
            cin>>Allocation[i][j] ;
    }

    cout<<"\nEnter Process Request : \n" ;
    for(i=1; i<=process_no; i++)
    {
        cout<<"For process ["<<i<<"] : " ;
        for(j=1; j<=resource_no; j++)
            cin>>Request[i][j] ;
    }

    cout<<"\nEnter current Availability : \n" ;
    for(i=1; i<=resource_no; i++)
    {
        cout<<"For resource ["<<i<<"] : " ;
        cin>>Availability[i] ;
    }


    bool mark_done[process_no+2] ;                      // for marking the already executed processes
    memset(mark_done, 0, sizeof(mark_done)) ;

    int unsafe_cnt=0 ;
    while(1)
    {
        for(i=1; i<=process_no; i++)
        {
            if(mark_done[i]==1)
                continue ;

            bool flag=0 ;
            for(j=1; j<=resource_no; j++)
            {
                if(Request[i][j]>Availability[j])
                {
                    flag = 1 ;
                    unsafe_cnt++ ;
                    break ;
                }
            }
            if(flag==0)
            {
                safe_Seq.push_back(i) ;
                mark_done[i] = 1 ;
                for(j=1; j<=resource_no; j++)
                {
                    Availability[j] += Allocation[i][j] ;       // releasing previous allocations of executed processes
                }
            }
        }
        if(safe_Seq.size()==process_no || unsafe_cnt>process_no)
            break ;
    }
    if(unsafe_cnt<=process_no && (safe_Seq.size()==process_no) )
    {
        int c=0 ;
        cout<<"\nThe Safe Sequence is :\n" ;
        for(auto i : safe_Seq)
        {
            c++ ;
            cout<<"P["<<i<<"]" ;
            if(c<safe_Seq.size())cout<<"-->" ;
        }
        cout<<NL ;
    }
    else
        cout<<"\nDEADLOCK DETECTED !!\n" ;

    return 0 ;
}


/*
Sample I/O :

How many processes? : 5
How many resources? : 3

Enter Allocation :
For process [1] : 0 1 0
For process [2] : 2 0 0
For process [3] : 3 0 3
For process [4] : 2 1 1
For process [5] : 0 0 2

Enter Process Request :
For process [1] : 0 0 0
For process [2] : 2 0 2
For process [3] : 0 0 0
For process [4] : 1 0 0
For process [5] : 0 0 2

Enter current Availability :
For resource [1] : 0
For resource [2] : 0
For resource [3] : 0

The Safe Sequence is :
P[1]-->P[3]-->P[4]-->P[5]-->P[2]


 ***** TO DETECT DEADLOACK *****
        make Process Request of
        Process[3] = 0 0 1

*/
