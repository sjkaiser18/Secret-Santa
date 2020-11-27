#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <time.h>   
#include <algorithm>
#include <fstream>

using namespace std;

    vector<pair<string,string>> matches; 
    
int in_family(string value){
    
    vector <string> p_and_m={"Sarah","Nathan","Erin"};
    vector <string> b_and_b={"Morgan","Wes"};
    vector <string> tk_and_s={"Justin","Trevor"};
    vector <string> c_and_j={"Avery"};
    vector <string> kc_and_d={"Koia","Lana"};
    vector <string> s={"Madison"};
    
    auto val_1 = find(p_and_m.begin(), p_and_m.end(), value);
    if(val_1 != p_and_m.end()){
        return 1; //p_and_m
    }
    auto val_2 = std::find(b_and_b.begin(), b_and_b.end(), value);
     if(val_2 != b_and_b.end()){
        return 2; //b_and_b
    }
    auto val_3 = std::find(tk_and_s.begin(), tk_and_s.end(), value);
    if(val_3 != tk_and_s.end()){
        return 3; //tk_and_s
    }
    
    auto val_4 = std::find(c_and_j.begin(), c_and_j.end(), value);
    if(val_4 != c_and_j.end()){
        return 4; //c_and_j
    }
    auto val_5 = std::find(kc_and_d.begin(), kc_and_d.end(), value);
    if(val_5 != kc_and_d.end()){
        return 5; //kc_and_d
    }
    auto val_6=std::find(s.begin(), s.end(), value); 
    if(val_6 != s.end()){
        return 6; //s
    }
    
    
}

int main()
{
    
    srand (time(NULL));
    
    // string p_and_m[]={"Sarah","Nathan","Erin"};
    // string b_and_b[]={"Morgan","Wes"};
    // string tk_and_s[]={"Justin","Trevor"};
    // string c_and_j[]={"Avery"};
    // string kc_and_d[]={"Koia","Lana"};
    // string s[]={"Madison"};
    
    vector <string> cousins_1={"Sarah","Nathan","Erin","Morgan",
                    "Wes","Justin","Trevor","Avery",
                    "Koia","Lana","Madison"};
                    
    vector <string> cousins_2={"Sarah","Nathan","Erin","Morgan",
                    "Wes","Justin","Trevor","Avery",
                    "Koia","Lana","Madison"};
    
    string gifter;
    string giftee;
    
    while(cousins_1.size()>1 && cousins_2.size()>1){
        gifter=cousins_1.at(rand()%cousins_1.size());
        cout<<"Gifter 1: "<<gifter<<endl;
        
        giftee=cousins_2.at(rand()%cousins_2.size());
        
        if(gifter.compare(giftee)!=0){
            cout<<"Not the same person"<<endl;     
            int in_family_1=in_family(giftee);
            int in_family_2=in_family(gifter);
            
            if(in_family_1!=in_family_2){
                
                matches.push_back(std::make_pair(gifter,giftee));
            
                auto itr_1 = std::find(cousins_1.begin(), cousins_1.end(), gifter);

                //remove both values from their respective arrays
                if (itr_1 != cousins_1.end()){
                    cousins_1.erase(itr_1);
                } 
                
                auto itr_2 = std::find(cousins_2.begin(), cousins_2.end(), giftee);
                if (itr_2 != cousins_2.end()){
                    cousins_2.erase(itr_2);
                } 
            }//not in the same family
            else{
                cout<<"Same immedeiate family, skip!"<<endl;
            }//in the same family
                
            }//not the same person
            
            
    }//end of while loop
    
    ofstream outfile;
                outfile.open("cousins_secret_santa.txt");
                
                outfile<<"Cousins Secret Santa List (Shhh) !"<<endl;
                
                for(int j=0;j<matches.size();j++){
                outfile<<matches.at(j).first<<" has "<<matches.at(j).second<<endl;
                }
                
    return 0;
}