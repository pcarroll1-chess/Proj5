#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Variables
    ifstream inputFile ("s1.txt");
    int nColumns = 4; // n x m allocation matrix
    int mRows = 4;    // n x m allocation matrix
    int n; // number of processes: n
    int m; // number of resource types: m
    string line;
    int number;
    int matrix_Allocation [4][4] = {0};
    int matrix_Max [4][4] = {0};
    int matrix_Available_Vector [4] = {0};
    int matrix_Request_Vector [4] = {0};
    int matrix_Need [4][4] = {0};
    int matrix_Available [4][4] = {0};

    // Read in in file
    // [] need to check against command line arg
    if (!inputFile.is_open()){return -1;}
    else
    {

        // Read in # of processes
        inputFile >> n;
        // Read in # of resources
        inputFile >> m;

        // Read in Allocation Matrix
        for (int i = 0; i <= 4 ; ++i) {
            inputFile >> matrix_Allocation [i][0];
            inputFile >> matrix_Allocation [i][1];
            inputFile >> matrix_Allocation [i][2];
            inputFile >> matrix_Allocation [i][3];
        }


        // Display Allocation Matrix
        cout << "The Allocation Matrix is... Before Max\n";
        cout <<"   A B C D\n";
        for (int i = 0; i <= 4 ; ++i) {
            cout << i << ": "
                 << matrix_Allocation[i][0] << " "
                 << matrix_Allocation[i][1] << " "
                 << matrix_Allocation[i][2] << " "
                 << matrix_Allocation[i][3] << "\n";
        }
        cout << "\n";

        // Read in Max Matrix
        for (int i = 0; i <= 4 ; ++i) {
            inputFile >> matrix_Max [i][0];
            inputFile >> matrix_Max [i][1];
            inputFile >> matrix_Max [i][2];
            inputFile >> matrix_Max [i][3];
        }
        // Display Allocation Matrix
        cout << "The Allocation Matrix is... After Max\n";
        cout <<"   A B C D\n";
        for (int i = 0; i <= 4 ; ++i) {
            cout << i << ": "
                 << matrix_Allocation[i][0] << " "
                 << matrix_Allocation[i][1] << " "
                 << matrix_Allocation[i][2] << " "
                 << matrix_Allocation[i][3] << "\n";
        }
        cout << "\n";


        // Calculate the Need Matrix
        for (int i = 0; i <= 4 ; ++i) {
            matrix_Need[i][0] = matrix_Max [i][0] - matrix_Allocation [i][0];
            matrix_Need[i][1] = matrix_Max [i][1] - matrix_Allocation [i][1];
            matrix_Need[i][2] = matrix_Max [i][2] - matrix_Allocation [i][2];
            matrix_Need[i][3] = matrix_Max [i][3] - matrix_Allocation [i][3];
        }


    }

    // Display # Processes
    cout << "There are " << n << " processes in the system\n\n";

    // Display # Resource Type
    cout << "There are " << m << " resource  types\n\n";

    // Display Allocation Matrix
    cout << "The Allocation Matrix is...\n";
    cout <<"   A B C D\n";
    for (int i = 0; i <= 4 ; ++i) {
        cout << i << ": "
             << matrix_Allocation[i][0] << " "
             << matrix_Allocation[i][1] << " "
             << matrix_Allocation[i][2] << " "
             << matrix_Allocation[i][3] << "\n";
    }
    cout << "\n";

    // Display Max Matrix
    cout << "The Max Matrix is...\n";
    cout <<"   A B C D\n";
    for (int i = 0; i <= 4 ; ++i) {
        cout << i << ": "
             << matrix_Max[i][0] << " "
             << matrix_Max[i][1] << " "
             << matrix_Max[i][2] << " "
             << matrix_Max[i][3] << "\n";
    }
    cout << "\n";
    // Display Need Matrix
    cout << "The Need Matrix is...\n";
    cout <<"   A B C D\n";
    for (int i = 0; i <= 4 ; ++i) {
        cout << i << ": "
        << matrix_Need[i][0] << " "
        << matrix_Need[i][1] << " "
        << matrix_Need[i][2] << " "
        << matrix_Need[i][3] << "\n";
    }


    inputFile.close();
    return 0;
}
