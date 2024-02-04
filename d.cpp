#include <iostream>
#include <ctime>
using namespace std;
void dispg(char (&s)[9]){
    cout<<"    |    |     \n";
    cout<<"  "<<s[0]<<" | "<<s[1]<<"  | "<<s[2]<<"  \n";
    cout<<"____|____|_____\n";
    cout<<"    |    |     \n";
    cout<<"  "<<s[3]<<" | "<<s[4]<<"  | "<<s[5]<<"  \n";
    cout<<"____|____|_____\n";
    cout<<"    |    |     \n";
    cout<<"  "<<s[6]<<" | "<<s[7]<<"  | "<<s[8]<<"  \n";
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    }
    
    
void usmove(char (&s)[9], char us) {
    int num;
    while (true) {
        cout << "Enter Grid Number (1-9): ";
        cin >> num;
        if (s[num - 1] == ' ' && num < 10 && num > 0) {
            s[num - 1] = us;
            break;
        }
    }
}

    

void compmove(char(&s)[9],char sy){
    int num;
    srand(time(0));
    while(true){
        num=rand()%9;
        if(s[num]==' '){
            s[num]=sy;
            break;
        }
    }
}
bool checkwin(char (&s)[], char sy, char us){
    if(s[0]==s[1]&&s[1]==s[2]&&s[0]!=' '){
        s[0]==us?cout<<"YOU WIN":cout<<"YOU LOSE";
        return true;
        
    }
    else if(s[3]==s[4]&&s[4]==s[5]&&s[3]!=' '){
        s[3]==us?cout<<"YOU WIN":cout<<"YOU LOSE";
        return true;
    }
    else if(s[2]==s[5]&&s[5]==s[8]&&s[2]!=' '){
        s[2]==us?cout<<"YOU WIN":cout<<"YOU LOSE";
        return true;
    }
    else if(s[0]==s[3]&&s[3]==s[6]&&s[0]!=' '){
        s[0]==us?cout<<"YOU WIN":cout<<"YOU LOSE";
        return true;
    }
    else if(s[1]==s[4]&&s[4]==s[7]&&s[1]!=' '){
        s[1]==us?cout<<"YOU WIN":cout<<"YOU LOSE";
        return true;
    }
    else if(s[6]==s[7]&&s[7]==s[8]&&s[6]!=' '){
        s[6]==us?cout<<"YOU WIN":cout<<"YOU LOSE";
        return true;
        
        
    }
    else if(s[0]==s[4]&&s[4]==s[8]&&s[0]!=' '){
        s[0]==us?cout<<"YOU WIN":cout<<"YOU LOSE";
        return true;
        
    }
    else if(s[2]==s[4]&&s[4]==s[6]&&s[2]!=' '){
        s[2]==us?cout<<"YOU WIN":cout<<"YOU LOSE";
        return true;
        
    }
    else{
        return false;
    }
    return true;
}
bool checktie(char (&s)[9]){
    for (int i=0;i<9;i++){
        if(s[i]==' '){
            return false;
            

        }
    }
    cout<<"ITS A TIE\n";
    return true;
}
int main(){
    char s[9]={ ' ',' ',' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
    char us='X';
    char sy='O';
    bool running=true;
    while(running){
        usmove(s,us);
        dispg(s);
        if(checkwin(s,sy,us)){
            running=false;
            break;

        }
        if(checktie(s)){
            running=false;
            break;

        }
        compmove(s,sy);
        dispg(s);
        if(checkwin(s,sy,us)){
            running=false;
            break;
            
        }
        if(checktie(s)){
            running=false;
            break;

        }


        
    }
}
