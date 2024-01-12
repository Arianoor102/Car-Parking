#include <iostream>
#include <fstream>
using namespace std;

class Parking{ //Parent class
	
 protected:
  int amount, count, two, three, four; //Data members initialization
 public:
  
  Parking(){ //Constructor
   amount = 0;
            count =0;
            two = 0;
            three =0;
            four = 0;
  }
  
  void Delet(){ //Deletion function the will delete all record
   amount = 0;
   count = 0;
   two = 0;
   three = 0;
   four = 0;
   cout<<"******************************"<<endl;
   cout<<"All record deleted-----"<<endl;
   cout<<"******************************"<<endl;
        }
        
        void feedback(){ //Feedback function that will ask for feedback and rating
      string fb;
      float r;
   cout<<"What is your feedback?\n";
   cin>>fb;
   cout<<"Rate our parking system out of 5! "<<endl;
   cin>>r;
   if(r>5){
    cout<<"Invalid input!"<<endl;
   }
  }
  
  void backupData(){ //Basic file handling that will store data in a file named as Backup
         fstream b;
          b.open("Backup", ios::out);
          if (b.is_open()) {
                b<<"Total amount of charges : "<<amount<<endl;
                b<<"Total number of vehicles parked :"<<count<<endl;
                b<<"Total number of two wheeler parked : "<<two<<endl;
                b<<"Total number of three wheeler parked : "<<three<<endl;
                b<<"Total number of four wheeler parked :" <<four<<endl;
             b.close();
            }
        }
            
        ~Parking(){ //Destuctor that will prompt a thankyou message
         cout<<"\n\n\n\t\t__________________________"<<endl;
         cout<<"\t\t|\t\t\t |"<<endl;
         cout<<"\t\t|\t\t\t |"<<endl;
         cout<<"\t\t|\t\t\t |"<<endl;
         cout<<"\t\t|\tThankyou!\t |"<<endl;
         cout<<"\t\t|\t\t\t |"<<endl;
         cout<<"\t\t|\t\t\t |"<<endl;
         cout<<"\t\t|_________________________|"<<endl;
  }

};
class TwoWheel: virtual public Parking{ //Child class 
//keyword virtual is used here to avoid from ambiguity
 public:
  void t_wheel(){ // for two wheeler
   system("cls");
   if(count<=50){
    two++;
                amount = amount +100;
                count = count +1;
                cout<<"******************-----Two Wheeler-----******************"<<endl;
                cout<<"A new TwoWheeler has parked"<<endl;
                cout<<"Total number of vehicles = "<<count<<endl;
                cout<<"Now free space = "<<50-(two + three + four)<<endl;
                cout<<"*******************************************"<<endl;
   }
   else{
    cout<<"Sorry! parking is full"<<endl;
   }
  }
};
class ThreeWheel: virtual public Parking{
 public:
  void th_wheel(){ // for three wheeler
   if(count<=50){
    three++;
                amount = amount + 200;
                count = count + 1;
                cout<<"******************-----Three Wheeler-----******************"<<endl;
                cout<<"A new ThreeWheeler has parked"<<endl;
                cout<<"Total number of vehicles = "<<count<<endl;
                cout<<"Now free space = "<<50-(two + three + four)<<endl;
                cout<<"*******************************************"<<endl;
   }
   else{
    cout<<"Sorry! parking is full"<<endl;
   }
  }
};
class FourWheel: virtual public Parking{
 public:
  void f_wheel(){ // for four wheeler
   if(count<=50){
    four++;
                amount = amount + 300;
                count = count + 1;
                cout<<"******************-----Four Wheeler-----******************"<<endl;
                cout<<"A new ThreeWheeler has parked"<<endl;
                cout<<"Total number of vehicles = "<<count<<endl;
                cout<<"Now free space = "<<50-(two + three + four)<<endl;
                cout<<"*******************************************"<<endl;
   }
   else{
    cout<<"Sorry! parking is full"<<endl;
   }
  }
};
class ShowRecord: public TwoWheel , public ThreeWheel , public FourWheel{
    public:
        void show(){
         cout<<"*********************************************"<<endl;
            cout<<"Total amount of charges : "<<amount<<endl;
            cout<<"Total number of vehicles parked :"<<count<<endl;
            cout<<"Total number of two wheeler parked : "<<two<<endl;
            cout<<"Total number of three wheeler parked : "<<three<<endl;
            cout<<"Total number of four wheeler parked :" <<four<<endl;
            cout<<"************************************************"<<endl;
        }
};
int main(){
 int u_input;
    ShowRecord s;
    s.backupData();
    cout<<"___ ___ ___ __ ___ ___ _____ ____ "<<endl;system("color 01");
    cout<<"| \\ /\\ | \\| / | |\\ | / \\ /___ \\ / /___ | | |\\ /| "<<endl;system("color 04");
    cout<<"|__| /__\\ |__/|/ | | \\ | | __ \\ \\ / \\ | |--- | \\ / | "<<endl;system("color 0D");
    cout<<"| / \\| \\| \\ _|_ | \\| \\__| ___/ | ___/ | |___ | \\/ | "<<endl;system("color 0B");

    cout<<"\n\nNumber of vehicles limit = 50 "<<endl;system("color 0D");
    cout<<"TWO Wheeler parking charges(Bikes) \t = 100"<<endl;system("color 0A");
    cout<<"THREE Wheeler parking charges(Rickshaws) = 200"<<endl;system("color C7");
    cout<<"FOUR Wheeler parking charges(Cars) \t = 300"<<endl;system("color 0B");
while(1){
    cout<<"\n--------------*****Choose our service*****--------------"<<endl;
    cout<<"\nPress 1 for Two Wheeler (Bikes)"<<endl;
    cout<<"Press 2 for Three Wheeler (Rickshaws)"<<endl;
    cout<<"Press 3 for Four Wheeler (Cars)"<<endl;
    cout<<"Press 4 for show the record"<<endl;
    cout<<"Press 5 for delete the record"<<endl;
    cout<<"Press 6 for feedback"<<endl;
    cout<<"Press 7 for exit"<<endl;
    cout<<"**********************************************"<<endl;
    cin>>u_input;
    switch(u_input){
        case 1:
         system("cls");
            system("color C7");
            s.t_wheel();
            break;

        case 2:
            system("cls");
            system("color F6");
            s.th_wheel();
            break;
        
        case 3:
            system("cls");
            system("color B5");
            s.f_wheel();
            break;

        case 4:
            system("cls");
            system("color E5");
      s.show();
            break;
            
        case 5:
         system("cls");
         s.Delet();
         break;
         
  case 6:
         system("cls");
         s.feedback();
         break;
         
        case 7:
         system("cls");
         s.~Parking();
            exit(0);
            system("color 7");
            break;
default:
{
    system("cls");
    cout<<"******************************************"<<endl;
    cout<<"WRONG INPUT"<<endl;
    cout<<"*******************************************"<<endl;
}
}
}
return 0;
}
