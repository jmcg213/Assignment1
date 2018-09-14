#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<math.h>
#include<cmath>
#include<random>
#include"DNA.h"
using namespace std;

DNAstrings::DNAstrings() //defualt constructor
{

}
DNAstrings::DNAstrings(string file) //constructor to initialize all variables
{
    inputFile = file;
    fileExsists = true;
    lineCount = 0;
    lengthSum = 0;
    countA = 0;
    countT= 0;
    countC = 0;
    countG = 0;
    totalCount = 0;
    countAA = 0;
    countAT = 0;
    countAC = 0;
    countAG = 0;
    countTA = 0;
    countTT = 0;
    countTC = 0;
    countTG = 0;
    countCA = 0;
    countCT = 0;
    countCC = 0;
    countCG = 0;
    countGA = 0;
    countGT = 0;
    countGC = 0;
    countGG = 0;
    totalBigram = 0;
    dnaOutput = "";
}
DNAstrings::~DNAstrings() //destructor
{
    cout << "Program ended" << endl;
}
int DNAstrings::fileLines(string inputFile) //method to count file lines
{
    string line;
    ifstream input(inputFile);
    while(getline(input, line))
    {
        lineCount++;
    }
    return lineCount;
}
double DNAstrings::computeSum(string inputFile) //computes sum of lines
{
    string line;
    ifstream input(inputFile);
    while(getline(input, line))
    {
        lengthSum += line.size();
    }
    return lengthSum;
}
double DNAstrings::computeMean(string inputFile) //computes mean of line lengths
{
    ifstream input(inputFile);
    return computeSum(inputFile)/(fileLines(inputFile));
}
double DNAstrings::computeVariance(string inputFile) //computes variance of line lengths
{
    ifstream input;
    input.open(inputFile);
    return sqrt(computeSum(inputFile) - computeMean(inputFile));
}
double DNAstrings::computeStdDev(string inputFile) //computes Standard deviation of line lengths
{
    ifstream input;
    input.open(inputFile);
    return sqrt(computeVariance(inputFile));
}
void DNAstrings::probability(string inputFile) //calculates all nucleotide and bigram probabilities
{
    ifstream input(inputFile);
    string line;
    while(getline(input, line))
    {
        char prevChar = ' ';
        for(char curChar : line)
        {
            curChar = toupper(curChar);
            if(curChar == 'A')
            {
                countA++;
                totalCount++;
                if(prevChar == 'A')
                {
                    countAA++;
                    totalBigram++;
                }
                else if(prevChar == 'T')
                {
                    countAT++;
                    totalBigram++;
                }
                else if(prevChar == 'C')
                {
                    countAC++;
                    totalBigram++;
                }
                else if(prevChar == 'G')
                {
                    countAG++;
                    totalBigram++;
                }
            }
            else if(curChar == 'T')
            {
                countT++;
                totalCount++;
                if(prevChar == 'A')
                {
                    countTA++;
                    totalBigram++;
                }
                else if(prevChar == 'T')
                {
                    countTT++;
                    totalBigram++;
                }
                else if(prevChar == 'C')
                {
                    countTC++;
                    totalBigram++;
                }
                else if(prevChar == 'G')
                {
                    countTG++;
                    totalBigram++;
                }
            }
            else if(curChar == 'C')
            {
                countC++;
                totalCount++;
                if(prevChar == 'A')
                {
                    countCA++;
                    totalBigram++;
                }
                else if(prevChar == 'T')
                {
                    countCT++;
                    totalBigram++;
                }
                else if(prevChar == 'C')
                {
                    countCC++;
                    totalBigram++;
                }
                else if(prevChar == 'G')
                {
                    countCG++;
                    totalBigram++;
                }
            }
            else if(curChar == 'G')
            {
                countG++;
                totalCount++;
                if(prevChar == 'A')
                {
                    countGA++;
                    totalBigram++;
                }
                else if(prevChar == 'T')
                {
                    countGT++;
                    totalBigram++;
                }
                else if(prevChar == 'C')
                {
                    countGC++;
                    totalBigram++;
                }
                else if(prevChar == 'G')
                {
                    countGG++;
                    totalBigram++;
                }
            }
            prevChar = curChar;
        }
    }
    probabilityA = (countA == 0) ? 0.0 : ((double)countA/totalCount) * 100.0;
    probabilityC = (countC == 0) ? 0.0 : ((double)countC/totalCount) * 100.0;
    probabilityT = (countT == 0) ? 0.0 : ((double)countT/totalCount) * 100.0;
    probabilityG = (countG == 0) ? 0.0 : ((double)countG/totalCount) * 100.0;
    probabilityAA = (countAA == 0) ? 0.0 : ((double)countAA/totalBigram) * 100.0;
    probabilityAT = (countAT == 0) ? 0.0 : ((double)countAT/totalBigram) * 100.0;
    probabilityAC = (countAC == 0) ? 0.0 : ((double)countAC/totalBigram) * 100.0;
    probabilityAG = (countAG == 0) ? 0.0 : ((double)countAG/totalBigram) * 100.0;
    probabilityTA = (countTA == 0) ? 0.0 : ((double)countTA/totalBigram) * 100.0;
    probabilityTT = (countTT == 0) ? 0.0 : ((double)countTT/totalBigram) * 100.0;
    probabilityTC = (countTC == 0) ? 0.0 : ((double)countTC/totalBigram) * 100.0;
    probabilityTG = (countTG == 0) ? 0.0 : ((double)countTG/totalBigram) * 100.0;
    probabilityCA = (countCA == 0) ? 0.0 : ((double)countCA/totalBigram) * 100.0;
    probabilityCT = (countCT == 0) ? 0.0 : ((double)countCT/totalBigram) * 100.0;
    probabilityCC = (countCC == 0) ? 0.0 : ((double)countCC/totalBigram) * 100.0;
    probabilityCG = (countCG == 0) ? 0.0 : ((double)countCG/totalBigram) * 100.0;
    probabilityGA = (countGA == 0) ? 0.0 : ((double)countGA/totalBigram) * 100.0;
    probabilityGT = (countGT == 0) ? 0.0 : ((double)countGT/totalBigram) * 100.0;
    probabilityGC = (countGC == 0) ? 0.0 : ((double)countGC/totalBigram) * 100.0;
    probabilityGG = (countGG == 0) ? 0.0 : ((double)countGG/totalBigram) * 100.0;
}
string DNAstrings::createDNAstrings(string inputFile) //creates 1000 DNA strings
{
    stringstream text;
    for(int i = 0; i < 1000; i++)
    {
        double a = (double)rand() / (double)RAND_MAX;
        double b = (double)rand() / (double)RAND_MAX;
        double boxMuller = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
        double randLength = (computeStdDev(inputFile)*(boxMuller)) + computeMean(inputFile);
        string randomDNAStrings = "";
        for(int j = 0; j < randLength; j++)
        {
            double randProb = (double)(rand() % 10000)/100;
            if(randProb <= getProbA())
            {
                randomDNAStrings += 'A';
            }
            else if(randProb <= (getProbA() + getProbT()))
            {
                randomDNAStrings += 'T';
            }
            else if(randProb <= (getProbA() + getProbT() + getProbC()))
            {
                randomDNAStrings += 'C';
            }
            else
            {
                randomDNAStrings += 'G';
            }
        }
        randomDNAStrings += "\n";
        dnaOutput += randomDNAStrings;
    }
    text << dnaOutput << endl;
    return text.str();
}
//Getters to access probabilities from the main.cpp
double DNAstrings::getProbA()
{
    return probabilityA;
}
double DNAstrings::getProbT()
{
    return probabilityT;
}
double DNAstrings::getProbC()
{
    return probabilityC;
}
double DNAstrings::getProbG()
{
    return probabilityG;
}
double DNAstrings::getProbAA()
{
    return probabilityAA;
}
double DNAstrings::getProbAT()
{
    return probabilityAT;
}
double DNAstrings::getProbAC()
{
    return probabilityAC;
}
double DNAstrings::getProbAG()
{
    return probabilityAG;
}
double DNAstrings::getProbTA()
{
    return probabilityTA;
}
double DNAstrings::getProbTT()
{
    return probabilityTT;
}
double DNAstrings::getProbTC()
{
    return probabilityTC;
}
double DNAstrings::getProbTG()
{
    return probabilityTG;
}
double DNAstrings::getProbCA()
{
    return probabilityCA;
}
double DNAstrings::getProbCT()
{
    return probabilityCT;
}
double DNAstrings::getProbCC()
{
    return probabilityCC;
}
double DNAstrings::getProbCG()
{
    return probabilityCG;
}
double DNAstrings::getProbGA()
{
    return probabilityGA;
}
double DNAstrings::getProbGT()
{
    return probabilityGT;
}
double DNAstrings::getProbGC()
{
    return probabilityGC;
}
double DNAstrings::getProbGG()
{
    return probabilityGG;
}




