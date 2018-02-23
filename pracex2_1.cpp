#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

bool hasDuplicate(string [], int);

int main(){	
	string fileList[] = {"data1.txt","data2.txt","data3.txt","data4.txt","data5.txt","data6.txt"}; 
	ifstream fin;
	for(int fileId = 0; fileId < 6; fileId++){
		fin.open( fileList[fileId].c_str());
		string textline;
		getline(fin,textline);
		int N = atoi(textline.c_str()); //<< Correct the code here to get the number of names given in the first line.
		
		//cout << N << "\n";
		/*for(int i =0; i<N-1; i++){
			cout << textline[i] << "\n";
		}*/
		
		string name[N];
		for(int i = 0; i < N; i++){	
			getline(fin,name[i]); //<< Correct the codes in this loop to get names and store it in an array.
		}
		fin.close(); 
		
		if(hasDuplicate(name,N)) cout << fileList[fileId] << " = Duplicate\n";
		else cout << fileList[fileId] << " = Unique\n";
	}
	return 0;
}

bool hasDuplicate(string d[], int n){

	for(int j = 0; j<n; j++){
		for(int k = j+1; k<n; k++){
			 if(d[j] == d[k]){
			 	return true;
			 }	
		}
	} 
	return false; //<< Correct the codes in this function to check duplicate names in an array.                            
}

//"C\\Users\\lab314-41\\Downloads\\"
