#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    cout << "ConteDevel Corporation\n\nInput matrix size:\n";
    int n;
    cin >> n;
    vector <vector <long int> > m(n, vector <long int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Input " << i + 1 << " -> " << j + 1 << endl;
            cin >> m[i][j];
            if(m[i][j] == 0) {
                m[i][j] = 1073741823;
            }
        }
    }

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(m[i][j] > (m[i][k] + m[k][j])) {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }

    cout << "Path:" << endl;

    cout << "   ";
    for(int i = 0; i < n; i++) {
        cout << setw(6) << i+1;
    }
    cout << endl << "   " ;
    for(int i = 0; i < n; i++) {
        cout << "------";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(2) << i+1 << "|";
        for (int j = 0; j < n; j++) {
            if(i == j || m[i][j] > 1003741823) {
                cout << setw(6) << "x";
                continue;
            }
            cout << setw(6) << m[i][j];
        }
        cout << endl;
    }
    return 0;
}

