#include<bits/stdc++.h>
using namespace std;

int check_shared(int ** lock_table,int d){
	for(int i=0;i<6;i++){
		if(lock_table[i][d]==1){
			return i;
		}
	}
	return -1;
}

int check_exclusive(int ** lock_table,int d){
	for(int i=0;i<6;i++){
		if(lock_table[i][d]==2){
			return i;
		}
	}
	return -1;
}

void update_lock_table(int lock_type,char data_item,int t_num,int ** lock_table,bool * isGrowing,string * T,int * isGrowing_num){
	int t=t_num-1,d=data_item-'A';
	if(lock_table[t][d]==-1){
		cout<<data_item<<" is not accessible from T"<<t_num<<endl;
		return;
	}
	int ex,ex2;
	switch(lock_type){
		case 1:
			if(lock_table[t][d]==1)break;
			ex=check_exclusive(lock_table,d);
			if(ex!=-1){
				cout<<"Request not granted. T"<<ex+1<<"has exclusive lock";
			}
			else if(!isGrowing[t]){
				cout<<"Request not granted. T"<<t_num<<"is in sinking phase";
			}else{
				cout<<"Request granted.";
				lock_table[t][d]=1;
				isGrowing_num[t]++;
				if(isGrowing_num[t]==T[t].length()){
					isGrowing[t]=false;
				}
			}break;
		case 2:
			if(lock_table[t][d]==2) break;
			ex=check_exclusive(lock_table,d);
			if(ex!=-1){
				cout<<"Request not granted. T"<<ex+1<<"has exclusive lock";
			}
			ex2=check_shared(lock_table,d);
			if(ex2!=-1){
				cout<<"Request not granted. T"<<ex2+1<<"has shared lock";
			}
			else if(!isGrowing[t]){
				cout<<"Request not granted. T"<<t_num<<"is in sinking phase";
			}else{
				cout<<"Request granted.";
				lock_table[t][d]=2;
				isGrowing_num[t]++;
				if(isGrowing_num[t]==T[t].length()){
					isGrowing[t]=false;
				}
			}break;
		case 3:
			if(isGrowing[t]){
				cout<<"Request not granted. T"<<t_num<<" is in growing phase";
			}else if(lock_table[t][d]==0){
				cout<<"Already unlocked";
			}else{
				cout<<"Request granted";
				lock_table[t][d]=0;
			}break;
	}
	return;
}

int main(){
	int ** lock_table=new int*[6];
	for(int i=0;i<6;i++){
		lock_table[i]=new int[5];
		for(int j=0;j<5;j++){
			lock_table[i][j]=-1;
		}
	}
	string * T=new string[6];
	T[0]="ABC";
	T[1]="ABCDE";
	T[2]="BCDE";
	T[3]="ABCD";
	T[4]="ABCDE";
	T[5]="A";
	for(int i=0;i<6;i++){
		for(int j=0;j<T[i].length();j++){
			lock_table[i][T[i][j]-'A']=0;
		}
	}
	bool * isGrowing=new bool[6];
	for(int i=0;i<6;i++){
		isGrowing[i]=true;
	}
	
	int * isGrowing_num=new int[6];
	for(int i=0;i<6;i++){
		isGrowing_num[i]=0;
	}
	
	char exit='n';
	while(exit=='n'){
		cout<<"Enter options\n";
		cout<<"Request for 1.shared lock 2.exclusive lock 3.unlock:(Enter 1,2,3)";
		int lock_type;
		cin>>lock_type;
		cout<<"		on item A,B,C,D,E:(Enter A,B,C,D,E)";
		char data_item;
		cin>>data_item;
		cout<<"		by transaction 1.T1, 2.T2, 3.T3, 4.T4, 5.T5, 6.T6:(Enter 1,2,3,4,5,6) ";
		int transaction_number;
		cin>>transaction_number;
		
		update_lock_table(lock_type,data_item,transaction_number,lock_table,isGrowing,T,isGrowing_num);
		
		cout<<"\nWant to exit?(y/n):";
		cin>>exit;
		cout<<endl;
	}
	return 0;
}
