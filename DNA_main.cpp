#include<iostream>
#include<fstream>
#include<string>
#include"DNA.h"
using namespace std;

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        //Taking in input file
        string inputFileName = argv[1];
        DNAstrings dna;
        dna.probability(inputFileName);
        ofstream myfile;
        //Block to write all information to the .out file
        myfile.open("jackmcgrath.out");
        myfile << "Jack McGrath\n";
        myfile << "2298796\n\n";
        myfile << "Sum of DNA string lengths: " << dna.computeSum(inputFileName) << "\n";
        myfile << "Mean of DNA string lengths: " << dna.computeMean(inputFileName) << "\n";
        myfile << "Variance of DNA string lengths: " << dna.computeVariance(inputFileName) << "\n";
        myfile << "Standard Deviation of DNA string lengths: " << dna.computeStdDev(inputFileName) << "\n\n";
        myfile << "Relative probability of nucleotide A: " << dna.getProbA() << "%\n";
        myfile << "Relative probability of nucleotide T: " << dna.getProbT() << "%\n";
        myfile << "Relative probability of nucleotide C: " << dna.getProbC() << "%\n";
        myfile << "Relative probability of nucleotide G: " << dna.getProbG() << "%\n\n";
        myfile << "Relative probability of nucleotide bigram AA: " << dna.getProbAA() << "%\n";
        myfile << "Relative probability of nucleotide bigram AT: " << dna.getProbAT() << "%\n";
        myfile << "Relative probability of nucleotide bigram AC: " << dna.getProbAC() << "%\n";
        myfile << "Relative probability of nucleotide bigram AG: " << dna.getProbAG() << "%\n";
        myfile << "Relative probability of nucleotide bigram TA: " << dna.getProbTA() << "%\n";
        myfile << "Relative probability of nucleotide bigram TT: " << dna.getProbTT() << "%\n";
        myfile << "Relative probability of nucleotide bigram TC: " << dna.getProbTC() << "%\n";
        myfile << "Relative probability of nucleotide bigram TG: " << dna.getProbTG() << "%\n";
        myfile << "Relative probability of nucleotide bigram CA: " << dna.getProbCA() << "%\n";
        myfile << "Relative probability of nucleotide bigram CT: " << dna.getProbCT() << "%\n";
        myfile << "Relative probability of nucleotide bigram CC: " << dna.getProbCC() << "%\n";
        myfile << "Relative probability of nucleotide bigram CG: " << dna.getProbCG() << "%\n";
        myfile << "Relative probability of nucleotide bigram GA: " << dna.getProbGA() << "%\n";
        myfile << "Relative probability of nucleotide bigram GT: " << dna.getProbGT() << "%\n";
        myfile << "Relative probability of nucleotide bigram GC: " << dna.getProbGC() << "%\n";
        myfile << "Relative probability of nucleotide bigram GG: " << dna.getProbGG() << "%\n";
        myfile << "1000 DNA strings: \n" << dna.createDNAstrings(inputFileName);
        myfile.close();
        return 0;
    }
    else
    {
        cout << "Invalid Entry" << endl;
    }
}