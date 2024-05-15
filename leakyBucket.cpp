#include<iostream>
#include<unistd.h>
using namespace std;

void doLeakyBucket(int &noOfQueries, int &incomingPacketSize, int &outFlowRate, int bucketSize){
	if(incomingPacketSize > bucketSize){
		cout<<"Bucket size overload"<<endl;
	}
	
	int storage = 0, storageLeft = 0;
	
	for(int i=0; i<noOfQueries; i++){
		storageLeft = bucketSize-storage;
		
		if(storageLeft >= incomingPacketSize){
			storage += incomingPacketSize;
			cout<<"Bucket size of "<<storage<<" is full"<<endl;
			storage -= outFlowRate;
		}
		else{
			int t = incomingPacketSize-storageLeft;
			cout<<"Bucket is short of "<<t<<" size, wait for "<<t<<" seconds"<<endl;
			storage -= t;
			sleep(t);
		}
	}
}

int main()
{
	int noOfQueries, incomingPacketSize, outFlowRate, bucketSize;
	cout<<"Enter the number of queries needs to be performed"<<endl;
	cin>>noOfQueries;
	
	cout<<"Enter the incoming packet size"<<endl;
	cin>>incomingPacketSize;
	
	cout<<"Enter the outFlowRate"<<endl;
	cin>>outFlowRate;
	
	cout<<"Enter the bucketSize"<<endl;
	cin>>bucketSize;
	
	doLeakyBucket(noOfQueries, incomingPacketSize, outFlowRate, bucketSize);

	return 0;
}
