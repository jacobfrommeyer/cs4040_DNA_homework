#include <iostream>
#include <fstream>

using namespace std;

bool validGene(int k, string geneA, string geneB);
void lcs(int k, string geneA, string geneB);

int main(int argc, char **argv)
{
    //cout << "Hello world" << endl;

    ifstream file;
    int k;
    string geneA, geneB;
    
    //Reads in file as given in command line argument
    file.open(argv[1]);
    file >> k;
    file >> geneA;
    file >> geneB;

    cout << endl << "K: " << k << endl;
    cout << "Gene A: " << geneA << endl;
    cout << "Gene B: " << geneB << endl << endl;

    if(validGene(k, geneA, geneB) == true)
    {
        lcs(k, geneA, geneB);
    }
    else
    {
        return 1;
    }
    

    return 0;
}

bool validGene(int k, string geneA, string geneB)
{
    //cout << geneA.length() << " " << geneB.length() << endl;
    if(geneA.length() % k == 0 && geneB.length() % k == 0)
    {
        cout << "valid genes" << endl;
        return true;
    }
    else
    {
        cout << "gene length does not match k" << endl;
        return false;
    }
    
}

void lcs(int k, string geneA, string geneB)
{
    cout << "calc lcs here" << endl;
}