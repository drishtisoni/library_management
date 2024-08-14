#include <iostream>
#include<fstream>
using namespace std;
class library
{
    string id,name,author,search;
    fstream file;
    public:
    void showbooks();
    void extractbooks();
    void addbooks();
}obj;
int main()
{
    char ch;
    while(true)
    {
    cout<<"------------------------"<<endl;
    cout<<"1-SHOW ALL THE BOOKS"<<endl;
    cout<<"2-EXTRACT BOOKS"<<endl;
    cout<<"3-ADD BOOKS"<<endl;
    cout<<"4-EXIT"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Enter Your Choice"<<endl;
    cin>>ch;
    switch(ch)
    {
        case '1':
        cin.ignore();   //as we have used getline function
        obj.showbooks();
        break;
        case '2':
        cin.ignore();   
        obj.extractbooks();
        break;
        case '3':
        cin.ignore();   
        obj.addbooks();
        break;
        case '4':
        return 0;
        default:
        cout<<"Entered choice is invalid";
        
    }
    }//while(ch!=0);
    return 0;
}
void library:: addbooks()
{
    cout<<"\n Enter Book ID ::";
    getline(cin,id);                                   //getline func is used to include whitespace text as well
    cout<<" Enter Book Name ::";
    getline(cin,name);
    cout<<"Enter Book Author name ::";
    getline(cin,author);
    
    file.open("bookdata.txt",ios :: out | ios :: app);  //app=append mode 
    file<<id<<""<<name<<""<<author<<endl;
    file.close();
    
}
void library:: showbooks()
{
    file.open("bookdata.txt" , ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    cout<<"\n\n";
    cout<<"\t\t BOOK ID \t\t\t BOOK NAME \t\t\t AUTHOR's NAME"<<endl;
      while(!file.eof())                                   //eof=end of file function
      {
          cout<<"\t\t "<<id<<"\t\t\t "<<name<<"\t\t\t "<<author<<endl;
           getline(file,id,'*');
           getline(file,name,'*');
           getline(file,author,'\n');
      }
      file.close();
}
void library:: extractbooks()
{
    showbooks();
    cout<<"\n ENTER BOOK ID ::";
    getline(cin,search);
    file.open("bookdata.txt" , ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    cout<<"\n\n";
    cout<<"\t\t BOOK ID \t\t\t BOOK NAME \t\t\t AUTHOR's NAME"<<endl;
    while(!file.eof())                                 
    {
        if(search == id)
        {
             cout<<"\t\t "<<id<<"\t\t\t "<<name<<"\t\t\t "<<author<<endl;
             cout<<"Book Extracted Successfully";
        }
         getline(file,id,'*');
         getline(file,name,'*');
         getline(file,author,'\n'); 
    }
    file.close();
}
