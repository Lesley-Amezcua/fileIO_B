//Name: Lesley Amezcua
//Date: October 22, 2015
//Description: FileIO_B

#include <iostream> //cin cout
#include <fstream> //fin fout
#include <string> 
#include <cstdlib> //exit()
#include <iomanip> //setw()
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
        
    string firstName, lastName, highest_Score;
    
    char fileName[12];
    
    double s1, s2, s3, s4, s5, s6, avg, high_Avg = 0, sum = 0;
    
    cout << "Enter the file name: " << endl;
    cin >> fileName;
    
    fin.open(fileName);
    fout.open("results.txt");
    
    if(fin.fail())
    {
        cout << "Error opening stream" << endl;
        exit(1);
    }
    if(fout.fail())
    {
        cout << "Error opening stream" << endl;
        exit(1);
    }
    
    while(fin >> firstName >> lastName >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
    {
        // sets 2 numbers after decimal
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(1);
        //moves left
        fout.setf(ios::left);
        
        avg = (s1 + s2 + s3 + s4 + s5) / 5.0;
        
        //highest average
        if(avg > high_Avg)
        {
            high_Avg = avg;
            
            highest_Score = firstName + " " + lastName;
        }
        
        //shows first name, last name, scores 1 - 6, average
        fout << setw(10) << firstName << setw(12) << lastName << setw(8) << s1 << setw(8) << s2 
             << setw(8) << s3 << setw(8) << s4 << setw(8) << s5 
             << " Average: ";
             
        fout.precision(2);
        
        fout << setw(8) << avg << endl;
    }

    fout << endl << "Highest score: " << highest_Score;
    
    fin.close();
    fout.close();


    return 0;
}
