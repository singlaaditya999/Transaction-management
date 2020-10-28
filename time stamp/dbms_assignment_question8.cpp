#include<bits/stdc++.h>
using namespace std;

void check(int rw,int t_num,int ab,clock_t* ts,int** ts_ab,int ** prev_ts_ab){
	if(rw==2){
		int read_ts=ts_ab[ab-1][0];
		int write_ts=ts_ab[ab-1][1];
		if(read_ts>ts[t_num-1] || write_ts>ts[t_num-1]){
			cout<<"Request is rejected and T"<<t_num<<" will have to rollback. These transactions are also rolling back.";
			if(read_ts>ts[t_num-1]) ts_ab[ab-1][0]=prev_ts_ab[ab-1][0];
			if(write_ts>ts[t_num-1])ts_ab[ab-1][1]=prev_ts_ab[ab-1][1];
		}else{
			cout<<"Write request is granted";
			prev_ts_ab[ab-1][1]=ts_ab[ab-1][1];
			ts_ab[ab-1][1]=ts[t_num-1];
		}
	}
	else if(rw==1){
		int write_ts=ts_ab[ab-1][1];
		if(write_ts>ts[t_num-1]){
			cout<<"Request is rejected and T"<<t_num<<" will have to roll back. These transactions are also rolling back.";
//			ts_ab[ab-1][0]=prev_ts_ab[ab-1][0];
			ts_ab[ab-1][1]=prev_ts_ab[ab-1][1];
		}else{
			cout<<"Read request is granted";
			prev_ts_ab[ab-1][0]=ts_ab[ab-1][0];
			ts_ab[ab-1][0]=max(ts_ab[ab-1][0],(int)ts[t_num-1]);
		}
	}
	return;
}

void pause(){
	for(int i=0;i<10000000;i++);
	return;
}

int main(){
	clock_t* ts=new clock_t[3];
	pause();
	ts[0]=clock();
	pause();
	ts[1]=clock();
	pause();
	ts[3]=clock();
	int **ts_ab=new int*[2];			// 0for a, 1 for b and  0 for read time stamp, 1 for write time stamp
	for(int i=0;i<2;i++){
		ts_ab[i]=new int[2];
		for(int j=0;j<2;j++){
			ts_ab[i][j]=0;
		}
	}
	int **prev_ts_ab=new int*[2];			// 0for a, 1 for b and  0 for read time stamp, 1 for write time stamp
	for(int i=0;i<2;i++){
		prev_ts_ab[i]=new int[2];
		for(int j=0;j<2;j++){
			prev_ts_ab[i][j]=0;
		}
	}
	char exit='n';
	while(exit=='n'){
		cout<<"Enter options\n";
		cout<<"Request for 1.Read 2.Write:(Enter 1,2)";
		int c_type;
		cin>>c_type;
		cout<<"		by transaction 1.T1, 2.T2, 3.T3:(Enter 1,2,3) ";
		int transaction_number;
		cin>>transaction_number;
		cout<<"		on item 1.A, 2.B:(Enter 1,2)";
		int data_item;
		cin>>data_item;
		pause();
//		ts_ab[data_item-1][c_type-1]=ts[transaction_number-1];
		check(c_type,transaction_number,data_item,ts,ts_ab,prev_ts_ab);
		cout<<"\nWant to exit?(y/n):";
		cin>>exit;
		cout<<endl;
	}
	
	return 0;
}
