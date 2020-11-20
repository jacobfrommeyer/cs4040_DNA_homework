#include <iostream>
#include <fstream>

using namespace std;

//Function declarations
bool validGene(int k, string geneA, string geneB);
string lcs(int k, string geneA, string geneB);
bool compGene(int i, int j, int k, string geneA, string geneB);
string sort(int k, string substring);

int main(int argc, char **argv)
{
    ifstream file;
    int k;
    string geneA, geneB, longSubString;
    
    //Reads in file as given in command line argument
    file.open(argv[1]);
    file >> k;
    file >> geneA;
    file >> geneB;

    if(validGene(k, geneA, geneB) == true)  //Checks to see if the genes are divisible by k
    {
        longSubString = lcs(k, geneA, geneB);

        int numGenes = longSubString.length() / k;
        
        cout << endl << "Number of genes: " << numGenes << endl;    //Prints out the total number of genes in the subsequence
        cout << "Longest common subsequence: " << longSubString << endl;    //Prints out the longest common subsequence
    }
    else
    {
        return 1;   //Gives error if genes are not divisible by k
    }
    

    return 0;
}

/******************************************************************
 *                                                                  
 *  Function:   validGene
 *                                                                  
 *  Purpose:    determines if the length of the k and both geneA and geneB
 *              are divisible by each other.                                  
 *                                                                  
 *  Parameters: @param k - Length of each gene
 *              @param geneA - The first gene as a string
 *              @param geneB - The second gene as a string
 *
 * Member/Global Variables: none
 *
 * Pre Conditions: variables k, geneA, and geneB are all valid
 *
 * Post Conditions: returns true or false if the gene lengths are
 *                  valid in relation to k
 *
 * Calls:       none
 *                                                                  
 *******************************************************************/
bool validGene(int k, string geneA, string geneB)
{
    //cout << geneA.length() << " " << geneB.length() << endl;
    if(geneA.length() % k == 0 && geneB.length() % k == 0)
    {
        //cout << "valid genes" << endl << endl;
        return true;
    }
    else
    {
        //cout << "gene length does not match k" << endl << endl;
        return false;
    }
    
}

/******************************************************************
 *                                                                  
 *  Function:   lcs
 *                                                                  
 *  Purpose:    determins the longest common subsequence for two genes                                  
 *                                                                  
 *  Parameters: @param k - Length of each gene
 *              @param geneA - The first gene as a string
 *              @param geneB - The second gene as a string
 *
 *              @return - The longest common subsequence for the given
 *                         two genes. 
 *
 * Member/Global Variables: none
 *
 * Pre Conditions: variables k, geneA, and geneB are all valid
 *
 * Post Conditions: returns the longest common substring between geneA
 *                  and geneB
 *
 * Calls:       function compGene
 *                                                                  
 *******************************************************************/
string lcs(int k, string geneA, string geneB)
{
    const int lenGeneA = geneA.length();
    const int lenGeneB = geneB.length();
    string comSubString;

    int itteration = 0;

    for(int i = 0; i < lenGeneA; i = i + k)
    {
        //cout << "i: " << i << endl;
        for(int j = itteration; j < lenGeneB; j = j + k)
        {
            //cout << "j: " << j << endl;
            if(compGene(i, j, k, geneA, geneB) == true)
            {
                //cout << "genes match" << endl;
                comSubString = comSubString + geneA.substr(i, k); 
                //cout << "common substring: " << comSubString << endl;
                itteration = j + k;
                break;
            }
            else
            {
                //cout << "genes dont match" << endl;
                continue;
            }
        }
    }
    return comSubString;
}

/******************************************************************
 *                                                                  
 *  Function:   compGene
 *                                                                  
 *  Purpose:    compares the characters in two substrings from a gene
 *              to determine if they contain the same characters.
 *                                                    
 *  Parameters: @param geneASubStart - Starting point in the substring
 *                                     for the first gene 
 * 
 *              @param geneBSubStart - Starting point in the substring
 *                                     for the second gene
 *
 *              @return - true or false if the given two genes are equal
 *
 * Member/Global Variables: none
 *
 * Pre Conditions: geneASubStart and geneBSubStart are within the length
 *                  of the total gene length.  K, geneA, and geneB are all
 *                  valid values.
 *
 * Post Conditions: returns true or false depending on if the two gene
 *                  subsequences are equal to each other
 *
 * Calls:       function sort
 *                                                                  
 *******************************************************************/
bool compGene(int geneASubStart, int geneBSubStart, int k, string geneA, string geneB)
{
    string temp1 = geneA.substr(geneASubStart, k);
    string temp2 = geneB.substr(geneBSubStart, k);

    temp1 = sort(k, temp1);
    temp2 = sort(k, temp2);

    //cout << "temp1: " << temp1 << " temp2: " << temp2 << endl;

    if(temp1 == temp2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/******************************************************************
 *                                                                  
 *  Function:   sort
 *                                                                  
 *  Purpose:    Sorts a string using bubble sort.                               
 *                                                                  
 *  Parameters: @param k - length of each gene
 *              @param substring - the string to be sorted
 *
 *              @return - returns the sorted string
 *
 * Member/Global Variables: none
 *
 * Pre Conditions: variables k and substring are valid
 *
 * Post Conditions: returns the a substring that is sorted 
 *
 * Calls:       none
 *                                                                  
 *******************************************************************/
string sort(int k, string substring)
{
    bool swapped;

    for(int i = 0; i < k - 1; i++)
    {
        swapped = false;
        for(int j = 0; j < k - i - 1; j++)
        {
            if(substring[j] > substring[j+1])
            {
                swap(substring[j], substring[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
        {
            break;
        }
    }
    return substring;
}