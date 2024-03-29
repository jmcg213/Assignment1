#include<iostream>
#include<string>
using namespace std;

class DNAstrings
{
    public:
        string inputFile;
        string dnaOutput;
        bool fileExsists;
        int lineCount = 0;
        int lengthSum = 0;
        int countA = 0;
        int countT = 0;
        int countC = 0;
        int countG = 0;
        int countAA = 0;
        int countAT = 0;
        int countAC = 0;
        int countAG = 0;
        int countTA = 0;
        int countTT = 0;
        int countTC = 0;
        int countTG = 0;
        int countCA = 0;
        int countCT = 0;
        int countCC = 0;
        int countCG = 0;
        int countGA = 0;
        int countGT = 0;
        int countGC = 0;
        int countGG = 0;
        int totalBigram = 0;
        int totalCount = 0;
        double probabilityA;
        double probabilityT;
        double probabilityC;
        double probabilityG;
        double probabilityAA;
        double probabilityAT;
        double probabilityAC;
        double probabilityAG;
        double probabilityTA;
        double probabilityTT;
        double probabilityTC;
        double probabilityTG;
        double probabilityCA;
        double probabilityCT;
        double probabilityCC;
        double probabilityCG;
        double probabilityGA;
        double probabilityGT;
        double probabilityGC;
        double probabilityGG;
        DNAstrings();
        DNAstrings(string file);
        ~DNAstrings();
        int fileLines(string inputFile);
        double getProbA();
        double getProbT();
        double getProbC();
        double getProbG();
        double getProbAA();
        double getProbAT();
        double getProbAC();
        double getProbAG();
        double getProbTA();
        double getProbTT();
        double getProbTC();
        double getProbTG();
        double getProbCA();
        double getProbCT();
        double getProbCC();
        double getProbCG();
        double getProbGA();
        double getProbGT();
        double getProbGC();
        double getProbGG();
        double computeSum(string inputFile);
        double computeMean(string inputFile);
        double computeVariance(string inputFile);
        double computeStdDev(string inputFile);
        void probability(string inputFile);
        string createDNAstrings(string inputFile);
};

