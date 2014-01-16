#include "Class_create.h"
using namespace std;

void ClearScreen()
    {
    cout << string( 30, '\n' );
    }

int maxNumberofQuotes (vector<int> a){
    int big=0;
    for (int i=0; i<a.size(); i++){
        if (a[i]>big){
            big=a[i];
        }
    }
    return big+1;
}

void startUp(){
    ifstream myfile("quotes.txt");

        while (!cin.eof()){
            while (quotes[countrow][countquote[countrow]]!="#end"){
                getline(cin, quotes[countrow][countquote[countrow]++]);
                quotes.resize(countrow+1, vector<string>(maxNumberofQuotes(countquote)+1));
            }
            countrow++;
            quotes.resize(countrow+1, vector<string>(maxNumberofQuotes(countquote)+1));
            countquote.resize(countrow+1);
            countquote[countrow]=0;
        }
    myfile.close();
}

void customCreate (){

    cout<<"Please input the name of the speaker: "<<endl;
    getline(cin, quotes[countrow++][countquote[countrow]++]);
    countquote.resize(countrow+1);
    quotes.resize(countrow+1, vector<string>(maxNumberofQuotes(countquote)+1));

    cout<<"Please input the quote: "<<endl;
    getline(cin, quotes[countrow][countquote[countrow]++]);
    countquote.resize(countrow+1);
    quotes.resize(countrow+1, vector<string>(maxNumberofQuotes(countquote)+1));
}

void mainScreen(){
    char answer;
    cout<< "What would you like to do?"<<endl<<"Display Quotes (Q)"<<endl<<"Create Custom Quote (C)"
        <<"Guess that name (G)"<<endl<<"Save (S)"<<endl<<"Exit (E)"<<endl;
    cin>>answer;
    if (answer!='Q'||answer!='C'||answer!='G'||answer!='S'||answer!='E'||answer!='q'||answer!='c'||answer!='g'||answer!='s'||answer!='e'){
        cout<<"Try Again!"<<endl;
        ClearScreen();
        mainScreen();
    }
    switch(answer){
        case 'Q':
        case 'q':
            //display quotes
            break;
        case 'C':
        case 'c':
            customCreate();
            break;
        case 'G':
        case 'g':
            //Guess that name
            break;
        case 'S':
        case 's':
            //write the file to "quotes.txt"
            break;
        default:
            exit (0);
            break;
    }

}

void saveFile(){
    ofstream myfile ("quotes.txt");

    for (int k=0; k<=countrow; k++){
        quotes[k][countquote[k]+1]="#end";
    }

    for (int i=0; i<=countrow; i++){
        for (int j=0; j<=countquote[countrow]+1; j++){
            myfile<<quotes[i][j]<<endl;
        }
    }

}


