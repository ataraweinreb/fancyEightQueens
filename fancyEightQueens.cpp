

#include<iostream>
#include <cmath>
using namespace std; 

//Row and diag test to see if we can place our queens safely (same as 1d queens)
bool check(int a[], int n){
	for (int i=0; i<n; i++){
		if ((a[i]==a[n]) || (n-i==abs(a[n]-a[i]))){//row and diag test
			return false;
		}
	}
	return true;//test passed, you can place queen
}
void print(int b[], int cap){//prints the 1d array as a board
	static int numSolutions=1;
	cout << "Solution #" << numSolutions++ << ": " << endl;
 	int i,j,k,l;
 	typedef char box[5][7];//makes a type of a box thats 5x7
 	box bb,wb,*board[8][8];//declares a blackbox, a whitebox and a board
 	for(i=0;i<5;i++){
 		for( j=0;j<7;j++){
			wb[i][j]=' ';//white boxes have spaces
 			bb[i][j]=char(219);//black line character
 		}
 	}
	static box wq = { //white queen box
		{char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
        {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
        {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
        {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
        {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
	static box bq = { //black queen box
		{' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
        {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
        {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
        {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
        {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };
	
	for(i=0;i<8;i++){
 		for(j=0;j<8;j++){
 			if((i+j)%2==0){//if the row plus the colum are even, then...
 		 		board[i][j]=&wb;//make it a white box
 		 	} else { //if its odd
 		 		board[i][j]=&bb;//make a black box
 		 	}
 		}
	}
	for (i=0; i<8; i++){
		for (j=0; j<8; j++){
			if (b[i]==j){//if there is a queen is a white box
				if ((i+j)%2==0){
					board[j][i]=&bq;//place a black queen
				} else { //if not then...
					board[j][i]=&wq;//place a white queen on the board
				}
			}
		}
	}
 // print the board using the pointers
 	cout<<" ";
 	for(i=0;i<7*8;i++){
 		cout << '_';
 	}
 	cout<<endl;
 // now print the board
for(i=0;i<8;i++)
 	for(k=0;k<5;k++){
	 cout << " " << char(179); //left border
 	for(j=0;j<8;j++)
 		for(l=0;l<7;l++)
 			cout<<(*board[i][j])[k][l];
 	cout << char(179) << endl; 
 	}
 //print lower border
 cout << " ";
 for(i=0;i<7*8;i++)
 	cout << char(196);
 cout << endl;
}
int main(){
int q[8]={0};//initialize 1D array board to 0
int c=0;//columns
while (c>=0){
	c++;//increment the columns
	if (c==8){//if you reaches the end of the columns
		print(q, 8);//print your board
			c--;//backtrack to find more answers!
	} else {
			q[c]=-1; //start at the top of the rows
	}
	while (c>=0){
		q[c]++;//increment rows
		if (q[c]==8){
			c--;//if you went through all the rows and were not able to place the queens then backtrack
		} else{
			if (check(q, c)){ //see if you can place a queen by calling the row and diagnol tests
					break;
			}
		}
	}
}
}

