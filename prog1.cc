/******************************************************************* 
*  \file    prog1.cc
*  \brief   project 1 longest common substring finder
*                                                                     
*  Author:      Jacob Frommeyer
*  Email:       jf335914@ohio.edu
*                                                                    
*  Description: This program finds the longest common substring
*               between two genes.                  
*                                                                    
*  Date:        11/20/20
*                                                                    
*******************************************************************/

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
    ifstream file; //Stores file content
    int k;  //Length of each gene
    string geneA;   //Contains all of geneA
    string geneB;   //Contains all of geneB
    string longSubString;   //Contains the final longest common substring
    
    //Reads in file as given in command line argument
    file.open(argv[1]);
    file >> k;
    file >> geneA;
    file >> geneB;

    if(validGene(k, geneA, geneB) == true)  //Checks to see if the genes are divisible by k
    {
        longSubString = lcs(k, geneA, geneB);   //Stores longest common

        int numGenes = longSubString.length() / k;  //Finds number of genes in the longest common subsequence
        
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
    if(geneA.length() % k == 0 && geneB.length() % k == 0)  //Checks to see if the length of each gene is divisible by k, determines if the genes are of a valid length
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
    const int lenGeneA = geneA.length();    //Stores the length of geneA
    const int lenGeneB = geneB.length();    //Stores the length of geneB
    string comSubString;    //Stores the common substring as its being found

    int itteration = 0; //Initializes itteration at 0

    for(int i = 0; i < lenGeneA; i = i + k)     //Itterates through the first gene string
    {
        for(int j = itteration; j < lenGeneB; j = j + k)    //Itterates through the second gene string
        {
            if(compGene(i, j, k, geneA, geneB) == true)     //Calls compGene to determine if the subsequences between the two genes match
            {
                comSubString = comSubString + geneA.substr(i, k); //Adds geneA's subsequence gene to the current running common subsequence
                itteration = j + k;     //Itterates second gene past last found common subsequence
                break;  //Itterates through geneA again
            }
            else
            {
                continue;   //Continues to itterate through geneB
            }
        }
    }
    return comSubString;    //Returns the longest common subsequence found
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
    string temp1 = geneA.substr(geneASubStart, k);  //Temporary value to hold the current subsequence of geneA
    string temp2 = geneB.substr(geneBSubStart, k);  //Temporary value to hold the current subsequence of geneB

    temp1 = sort(k, temp1); //Sorts the geneA temp variable
    temp2 = sort(k, temp2); //Sorts the geneB temp variable

    if(temp1 == temp2)  //Returns true if the temp variables contain the same characters
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
    bool swapped;   //modification to optimize bubble sort prevents running past further than neccessary

    for(int i = 0; i < k - 1; i++)
    {
        swapped = false; //Determines if value has been swapped or not
        for(int j = 0; j < k - i - 1; j++)
        {
            if(substring[j] > substring[j+1])
            {
                swap(substring[j], substring[j+1]); //Swaps the substring characters
                swapped = true; //Marks a swap value
            }
        }
        if(swapped == false)
        {
            break;  //Returns to main loop if the variables have been swapped
        }
    }
    return substring;   //Returns the sorted substring
}