#include <iostream>
#include "list.h"

using namespace std;

class Object{
    private:
        string name;
        int id;
        string detail;


    public:
        Object(){
            name = "";
            id = 0;
            detail = "";
        }

        Object(string name, int id, string detail){
            this->name = name;
            this->id = id;
            this->detail = detail;
        }

        string getName(){
            return this->name;
        }

        int getID(){
            return this->id;
        }

        string getDetail(){
            return this->detail;
        }
};

class Database{
    private:
        List <Object> Obj;

    public:
        void displayObject(Object X){
            cout<<"\tName: "<<X.getName()<<endl;
            cout<<"\tID: "<<X.getID()<<endl;
            cout<<"\tDetail: "<<X.getDetail()<<endl;
        }

        void queryName(string name){
            for(int i = 0; i < Obj.size(); i++){
                if (Obj[i].getName() == name){
                    displayObject(Obj[i]);
                }
            }
        }

        void queryID(int id){
            for(int i = 0; i < Obj.size(); i++){
                if (Obj[i].getID() == id){
                    displayObject(Obj[i]);
                }
            }
        }

        void post(Object X){
            Obj.append(X);
        }

        void post(Object * X){
            Obj.append(*X);
        }

};


int main()
{

    Database db;

    cout <<"Welcome to the scuff database. We can do a bunch of stuff by following the instructions below"<<endl;
    
    while(true){
        int choice;
        string name;
        int id;
        string detail;
        int menu;

        cout<<"Select one of the choices below"<<endl;
        cout<<"\t1. Insert into the database"<<endl;
        cout<<"\t2. Query the database for Object"<<endl;
        cout<<"\t3. Exit the program"<<endl;
        cout<<"Your choice -> ";
        cin>>menu;

        if (menu == 1){
            cout<<"Enter your name: ";
            cin>>name;
            cout<<"Enter your id: ";
            cin>>id;
            cout<<"Enter your detail: ";
            cin >> detail;
            db.post(new Object(name, id, detail));
        }else if (menu == 2){
            cout<<"Select one query method from the choices.\n\t1. Query by name: "<<endl;
            cout<<"\t2. Query by id: "<<endl;
            cout<<"Your choice -> ";
            cin>>choice;
            if (choice == 1){
                cout<<"Enter the name: ";
                cin >> name;
                db.queryName(name);
            }else if (choice == 2){
                cout<<"Enter the ID: ";
                cin>> id;
                db.queryID(id);
            }else{
                cout<<"Invalid query argument"<<endl;
            }
        }else if (menu == 3){

        }else{

        }

    cout<<"\n"<<endl;
    }


    // List<int> test;
    // test.append(123);
    // test.append(2);
    // test.append(3);
    // test.append(2454);
    // test.append(4);

    // // append random number in the list
    // for (int i = 0; i < 100; i++){
    //     test.append(rand() % 100);
    // }

    // test.items();
    // test.sort();
    // test.size();
    // test.items();


   
}
