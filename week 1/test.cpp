#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
string process_ln(string line);

int main(){
    ifstream infile;
    ofstream outfile;
    infile.open("C-large-practice.in");
    outfile.open("C-large-practice-result.in");

    int i=0,n=1;
    int N;
    string line;
    vector<string> all;

    infile>>N;  //number of test cases
    while(i<N+1){
        if(i<1){
        getline(infile,line);
        i++;
    }
    else{
      string result;
      getline(infile,line);
      result = process_ln(line);
      all.push_back(result);
      outfile<<"Case #"<<n<<": "<<all[i-1]<<endl;
     n++,i++;
    }
}
return 0;
}

string process_ln(string line){
    int j;
    char letter;
    vector<string> val,temp;
    vector<char> v;
    string keep;

for(j=0; j<line.length(); j++)
    v.push_back(line[j]);

for(int i=0; i<j; i++){
switch(v[i]){
    case ' ': val.push_back("0"); temp.push_back("0"); break;
    case 'a': val.push_back("2"); temp.push_back("2"); break;
    case 'b': val.push_back("2"); temp.push_back("22"); break;
    case 'c': val.push_back("2"); temp.push_back("222"); break;
    case 'd': val.push_back("3"); temp.push_back("3"); break;
    case 'e': val.push_back("3"); temp.push_back("33"); break;
    case 'f': val.push_back("3"); temp.push_back("333"); break;
    case 'g': val.push_back("4"); temp.push_back("4"); break;
    case 'h': val.push_back("4"); temp.push_back("44"); break;
    case 'i': val.push_back("4"); temp.push_back("444"); break;
    case 'j': val.push_back("5"); temp.push_back("5"); break;
    case 'k': val.push_back("5"); temp.push_back("55"); break;
    case 'l': val.push_back("5"); temp.push_back("555"); break;
    case 'm': val.push_back("6"); temp.push_back("6"); break;
    case 'n': val.push_back("6"); temp.push_back("66"); break;
    case 'o': val.push_back("6"); temp.push_back("666"); break;
    case 'p': val.push_back("7"); temp.push_back("7"); break;
    case 'q': val.push_back("7"); temp.push_back("77"); break;
    case 'r': val.push_back("7"); temp.push_back("777"); break;
    case 's': val.push_back("7"); temp.push_back("7777"); break;
    case 't': val.push_back("8"); temp.push_back("8"); break;
    case 'u': val.push_back("8"); temp.push_back("88"); break;
    case 'v': val.push_back("8"); temp.push_back("888"); break;
    case 'w': val.push_back("9"); temp.push_back("9"); break;
    case 'x': val.push_back("9"); temp.push_back("99"); break;
    case 'y': val.push_back("9"); temp.push_back("999"); break;
    case 'z': val.push_back("9"); temp.push_back("9999"); break;
    default : break;
      }//end switch
  if(i>0 && val[i]==val[i-1])
     keep +=" ";
  keep += temp[i];
   }//end for loop
   return keep;
}//end process_ln  #include <stdio.h>

