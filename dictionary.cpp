#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
int main(){
	int letterpos=0,var=0,query,i,ans;
	string line,word,meaning;
	ifstream myfile,myfile1;
	ofstream outfile,outfile1;
	while(1){
	cout<<"1.New Entry\n2.Search\n3.Quit\nEnter your choice: ";
	cin>>query;
	if(query==1){
	
	cout<<"Enter the new word you want to add to the dictionary: ";
	cin>>word;
	cout<<"Enter the meaning of the word: ";
	cin.ignore();  //used before getline is called.if not used the string, "meaning" contains only a endline charecter.
	getline (std::cin,meaning);
	myfile.open("Vocabulary.txt");
	outfile.open("Copy.txt");
	while(getline(myfile,line)){
		if(line[letterpos]-'0' < word[letterpos]-'0'){
			outfile<<line<<"\n";
		}
		else if(line[letterpos]-'0'==word[letterpos]-'0'){
			outfile<<line<<"\n";
			if(var==0){
			 	outfile<<word<<"-"<<meaning<<"\n";
				var=1;
			}
		}
		else{
			if(var==0){
			 	outfile<<word<<"-"<<meaning<<"\n";
				var=1;
			}
			outfile<<line<<"\n";
		}
	}
	if(var==0){
		outfile<<word<<"-"<<meaning<<"\n";
		var=1;
	}
	myfile.close();
	outfile.close();
	remove("Vocabulary.txt");
	rename("Copy.txt","Vocabulary.txt");
}
else if(query==2){
	cout<<"Enter the word you want to search: ";
	cin>>word;
	myfile.open("Vocabulary.txt");
	ans=0;
	while(getline(myfile,line)){
		i=0;
		string check;
		while(line[i]!='-'){
			
			i=i+1;
		}
		check.append(line,0,i);
		if(!check.compare(word)){
			ans=1;
			cout<<line<<endl;
			break;
		}
	}
	myfile.close();
	if(ans==0){
		cout<<"Sorry! this word isn't present in the dictionary."<<endl;
	}
}
else{
	break;
}
}
	return 0;
}