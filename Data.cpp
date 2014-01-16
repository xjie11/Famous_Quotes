#include "Class_create.h"
using namespace std;

void startUp();
int maxNumberofQuotes (vector<int> a);
void customCreate ();
void ClearScreen();
void mainScreen();
void saveFile();

int main(int argc, char *argv[]){

    extern vector< vector<string> > quotes(1, vector<string>(1));
    extern int countrow=0;
    extern vector<int> countquote(1,0);
    startUp();
    mainScreen();
    return 0;
}
