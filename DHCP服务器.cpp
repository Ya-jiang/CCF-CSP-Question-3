#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int MAX=1e4+5;

int N,Tdef,Tmax,Tmin,n,outDate[MAX],state[MAX];
string H,host[MAX];

int main(){
	cin>>N>>Tdef>>Tmax>>Tmin>>H;
	cin>>n;
	for(int i=1;i<=N;i++) state[i]=1;
	for(int i=1;i<=n;i++){
		int t,ip,valid;
		string send,rece,type;
		cin>>t>>send>>rece>>type>>ip>>valid;
		if(rece!=H && rece!="*" && type!="REQ") continue;
		if(type!="DIS" && type!="REQ") continue;
		if(rece=="*" && type!="DIS") continue;
		if(rece==H && type=="DIS") continue;
		for(int i=1;i<=N;i++){
			if(outDate[i]<=t){
				if(state[i]==2){
					state[i]=1;host[i]="";outDate[i]=0;
				}
				else if(state[i]==3){
					state[i]=4;outDate[i]=0;
				}
			}
		}
		if(type=="DIS"){
			int IP=-1;
			for(int i=1;i<=N;i++){
				if(host[i]==send){
					IP=i;break;
				}
			}
			if(IP==-1){
				for(int i=1;i<=N;i++){
					if(state[i]==1){
						IP=i;break;
					}
				}
			}
			if(IP==-1){
				for(int i=1;i<=N;i++){
					if(state[i]==4){
						IP=i;break;
					}
				}
			}
			if(IP==-1) continue;
			state[IP]=2,host[IP]=send;
			if(valid==0) valid=t+Tdef;
			else if(valid-t<=Tmin) valid=t+Tmin;
			else if(valid-t>=Tmax) valid=t+Tmax;
			outDate[IP]=valid;
			cout<<H<<" "<<send<<" "<<"OFR "<<IP<<" "<<valid<<endl;
		}
		if(type=="REQ"){
			if(rece!=H){
				for(int i=1;i<=N;i++){
					if(host[i]==send){
						if(state[i]==2){
							state[i]=1;
							host[i]="";
							outDate[i]=0;
						}
					}
				}
				continue;
			}
			if(ip>=1 && ip<=N && host[ip]==send){
				state[ip]=3;
				if(valid==0) valid=t+Tdef;
				else if(valid-t<=Tmin) valid=t+Tmin;
				else if(valid-t>=Tmax) valid=t+Tmax;
				outDate[ip]=valid;
				cout<<H<<" "<<send<<" "<<"ACK "<<ip<<" "<<valid<<endl;
			}
			else{
				cout<<H<<" "<<send<<" "<<"NAK "<<ip<<" "<<0<<endl;
			}
		}
	}
	return 0;
}
/*
4 5 10 5 dhcp
16
1 a * DIS 0 0
2 a dhcp REQ 1 0
3 b a DIS 0 0
4 b * DIS 3 0
5 b * REQ 2 12
6 b dhcp REQ 2 12
7 c * DIS 0 11
8 c dhcp REQ 3 11
9 d * DIS 0 0
10 d dhcp REQ 4 20
11 a dhcp REQ 1 20
12 c dhcp REQ 3 20
13 e * DIS 0 0
14 e dhcp REQ 2 0
15 b dhcp REQ 2 25
16 b * DIS 0 0
*/
