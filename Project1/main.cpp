#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    string filename;
    ifstream cmdFile, dataFile;

    cout << "Enter name of command file: ";
    cin >> filename;
    cout << endl;
    cmdFile.open(filename);

    if(!cmdFile)
    {
        cout << "ERROR: Command file not found.\n";
             return 5;
    }

    double sum = 0;
    int numcount = 0, commandcount = 0;

    string command;
    while (cmdFile >> command)
    {
        commandcount++;

        if(command == "OPEN")
        {

            double num, skipnum=0;
            int skipcount=0;

            while(dataFile >> num)
            {
                skipcount++;
                skipnum+=num;
                cout <<  "Skipping " << num << endl;
            }
            if (skipcount > 0)
            {
                cout << "Skipped " << skipcount << " numbers for a total of " << skipnum << ".\n";
            }

            dataFile.close();

            cmdFile>>filename;
            dataFile.open(filename);
            if(!dataFile)
            {
                cout << "ERROR: Data file not found.\n";
                return 5;
            }

            cout <<  filename << " successfully opened.\n";
        }
        else if(command == "ADD")
        {
            int sumcount,accsumcount=0;
            double num,addsum=0;
            cmdFile >> sumcount;
            if(sumcount<0)
            {
                cout << "ERROR: Invalid amount.\n";
            }
            else
            {
                for(int i=0; i<sumcount&& dataFile >> num; i++)
                {
                    addsum+= num;
                    numcount++;
                    accsumcount++;
                }
                cout << accsumcount << " numbers totaling " << addsum << " added to the sum.\n";
                sum+=addsum;
            }

        }
        else if(command == "SUB")
        {

            int sumcount,accsumcount=0;
            double num,addsum=0;
            cmdFile >> sumcount;
            if(sumcount<0)
            {
                cout << "ERROR: Invalid amount.\n";
            }
            else
            {
                for(int i=0; i<sumcount&& dataFile >> num; i++)
                {
                    addsum+= num;
                    numcount++;
                    accsumcount++;
                }
                cout << accsumcount << " numbers totaling " << addsum << " subtracted from the sum.\n";
                sum-=addsum;
            }

        }
        else if(command == "REPORT")
        {
            string report;
            cmdFile >> report;
            if(report == "AVERAGE")
            {
                if(numcount > 0)
                {
                    cout << "Current average: " << sum/numcount << ".\n";
                }
                else
                {
                    cout << "ERROR: No numbers have been read in.\n";
                }
            }
            else if(report == "SUM")
            {
                cout << "Current sum: "<< sum << ".\n";
            }
            else if (report == "COUNT")
            {
                cout << "Current count: " << numcount << ".\n";
            }
            else if (report == "COMMANDS")
            {
                cout << "Current commands processed: " << commandcount << ".\n";
            }
            else
            {
                cout << "ERROR: Invalid report type.\n";
            }
        }
        else if(command == "QUIT")
        {
            cout << "Quitting...\n";
            break;
        }
        else
        {
            cout << "ERROR: Invalid command.\n";
            commandcount--;
        }

    }
    if (numcount == 0)
    {
        cout << "ERROR: No numbers have been read in.\n";
        return 5;
    }
    cout << "\nFinal average: " << sum/numcount << ".\n";
    cout << "Final sum: " << sum << ".\n";
    cout << "Final count: " << numcount<< ".\n";
    cout << "Total commands processed: " << commandcount<< ".\n";

    return 0;
}
