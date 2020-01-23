#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>>board, int row, int col) 
{ 
    int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < 8; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
void printchess(vector<vector<int>>a)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int checkNo(vector<vector<int>>v)
{
    int count=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(v[i][j]==1)
            count++;
        }
    }
    return count;
}
int checkcol(vector<vector<int>>v)
{
    int maxi=-1;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(v[i][j]==1)
            {
                maxi=max(j,maxi);
            }
        }
    }
    return maxi+1;
}
int main()
{
    vector<vector<int>>a(8, vector<int>(8, 0));
    queue<vector<vector<int>>>q;
    q.push(a);
    while(!q.empty())
    {
      vector<vector<int>>v;
      v=q.front();
      q.pop();
      int checkno=checkNo(v);
      if(checkno==8){
         printchess(v);
         cout<<endl;}
         else
         {
             int alreadyexist=checkcol(v);
             for(int i=0;i<8;i++)
             {
               if(isSafe(v,i,alreadyexist)==true)
               {
                   v[i][alreadyexist]=1;
                   q.push(v);
               }
               v[i][alreadyexist]=0;
             }
             
         }
         

    
    }
  //  printchess(a);

    return 0;
}