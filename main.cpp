#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Variables
    ifstream inputFile ("s1.txt");
    int nColumns = 4; // n x m allocation matrix
    int mRows = 5;    // n x m allocation matrix
    int n; // number of processes: n
    int m; // number of resource types: m
    char trash;
    int matrix_Allocation [5][4] = {0};
    int matrix_Max [5][4] = {0};
    int matrix_Available_Vector [4] = {0};
    int matrix_Request_Vector [4] = {0};
    int matrix_Need [5][4] = {0};
    int matrix_Available [4] = {0};

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
        for (int i = 0; i < n ; ++i) {
            inputFile >> matrix_Allocation [i][0];
            inputFile >> matrix_Allocation [i][1];
            inputFile >> matrix_Allocation [i][2];
            inputFile >> matrix_Allocation [i][3];
        }

        // Read in Max Matrix
        for (int i = 0; i < n ; ++i) {
            inputFile >> matrix_Max [i][0];
            inputFile >> matrix_Max [i][1];
            inputFile >> matrix_Max [i][2];
            inputFile >> matrix_Max [i][3];
        }

        // Calculate the Need Matrix
        for (int i = 0; i < n ; ++i) {
            matrix_Need[i][0] = matrix_Max [i][0] - matrix_Allocation [i][0];
            matrix_Need[i][1] = matrix_Max [i][1] - matrix_Allocation [i][1];
            matrix_Need[i][2] = matrix_Max [i][2] - matrix_Allocation [i][2];
            matrix_Need[i][3] = matrix_Max [i][3] - matrix_Allocation [i][3];
        }

        // Calculate the Available Vector
        for (int i = 0; i < m; ++i)
        {
            inputFile >> matrix_Available_Vector[i];
        }

        // Calculate the Request Vector
        inputFile >> trash;
        inputFile >> trash;
        for (int i = 0; i < m; ++i)
        {
            inputFile >> matrix_Request_Vector[i];
        }


    }

    // Display # Processes
    cout << "There are " << n << " processes in the system\n\n";

    // Display # Resource Type
    cout << "There are " << m << " resource  types\n\n";

    // Display Allocation Matrix
    cout << "The Allocation Matrix is...\n";
    cout <<"   A B C D\n";
    for (int i = 0; i < n ; ++i) {
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
    for (int i = 0; i < n ; ++i) {
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
    for (int i = 0; i < n ; ++i) {
        cout << i << ": "
             << matrix_Need[i][0] << " "
             << matrix_Need[i][1] << " "
             << matrix_Need[i][2] << " "
             << matrix_Need[i][3] << "\n";
    }
    cout << endl;

    // Display Available Vector
    cout << "The Available Vector is...\n";
    cout <<"   A B C D\n";
    for (int i = 0; i < 1; ++i) {
        cout << i+1 << ": ";
        for (int i = 0; i < m; ++i) {
            cout << matrix_Available_Vector[i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Check the State
    bool safe = true;
    for (int i = 0; i < m; ++i) {
        for (int b = 0; b < n; ++b) {
            if (matrix_Need[m][n] < 0)
                safe = false;
        }
    }
    if (safe)
    {
        cout << "THE SYSTEM IS IN A SAFE STATE!\n";
    }
    else
    {
        cout << "THE SYSTEM IS NOT IN A SAFE STATE!\n";
        return 0;
    }

    // Display Request Vector
    cout << "The Request Vector is...\n";
    cout <<"   A B C D\n";
    for (int i = 0; i < 1; ++i) {
        cout << i+1 << ": ";
        for (int i = 0; i < m; ++i) {
            cout << matrix_Request_Vector[i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Check if Request can be granted
    for (int i = 0; i < m; ++i)
    {
        if (
                (matrix_Available_Vector[i] - matrix_Request_Vector[i]) < 0
            )
        {
            cout << "THE REQUEST CANNOT BE GRANTED!";
            return 0;
        }
    }
    cout << "THE REQUEST CAN BE GRANTED!\n";

    cout << "The Available Vector is...\n";

    // Calculate the new Available Vector
    for ( int i = 0; i < n; ++i) {
        matrix_Available[i] =  matrix_Available_Vector[i] - matrix_Request_Vector[i];
    }

    // Display the new Available Vector
    cout <<"A B C D\n";
    for ( int i = 0; i < m; ++i) {
         cout << matrix_Available[i] << " ";
    }


    inputFile.close();
    return 0;
}
