#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//COT 4400 Brandon Yates, Colin Good, Uchenna Chima
int main()
{
    int n, r, c, iterations;
    ifstream file;
    file.open("input.txt");
    ofstream out;
    out.open("output.txt");
    
    //open file
    if(file.is_open())
    {
        //initialize array
        vector<vector<vector<int> > > arr (10001,vector<vector<int> >(101,vector <int>(101,-1)));
        
        //reads first line of document, how many times you must run code.
        file >> iterations;           
        while(!file.eof())
        {
            file >> n >> r >> c;

            if(arr[n][r][c] != -1) //memoization check
            {
                arr[n][r][c] = arr[n][r][c];
            }
            else
            {
                for(int i = 0; i <= n; i++)//num chocs
                {
                    
                    for(int j = 0; j <= r; j++)//num rows
                    {
                        for(int k = 0; k <= c; k++)//num cols
                        {
                            
                            if(arr[i][j][k] != -1) //memoization check
                            {
                                continue;
                            }

                            else if (i == j*k || (j == 1 && i < k) || (i == 0 && j*k > 0))
                            {
                                arr[i][j][k] = 1;
                            }

                            else if (i > (j * k))
                            {
                                arr[i][j][k] = 0;
                            }

                            else
                            {
                                int sum = 0;
                                for(int e = 1; e <= k; e++)
                                {
                                    if(i-e >= 0)
                                        sum += arr[i-e][j-1][e];
                                }
                                
                                arr[i][j][k] = sum;
                            }
                        }
                    }
                }
            }

            out << arr[n][r][c] << endl;
        }
        file.close();
    }
    else 
        cout << "ERROR: COULD NOT OPEN FILE";
    out.close();
    return 0;
    
}
