#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    printf("Input your gragh-matrix size:\n");
    int n;
    cin >> n;

    printf("Input your matrix:\n");

    vector<vector<bool> > m(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++) {
        getchar();
        for(int j = 0; j < n; j++) {
            char tmp = getchar();
            if(tmp != '0') {
                m[i][j] = true;
            }
        }
    }

    if(n < 3) {
        switch(n) {
        case 1:
            if(m[0][0]) {
                cout << "Graph is not planar!\n" << endl;
                return 0;
            }
            cout << "Graph is planar!\n" << endl;
            return 0;
        case 2:
            if((m[0][1] || m[1][0]) && (!m[0][0] && !m[1][1])) {
                cout << "Graph is planar!\n" << endl;
                return 0;
            }
            else {
                cout << "Graph is not planar!\n" << endl;
                return 0;
            }
        }
    }

    int e = 0;

    bool contin = true;

    for(int i = 0; i < n; i++) {
        if(!contin) {
            break;
        }

        for(int j = i; j < n; j++) {
            if((i == j) && (m[i][j])) {
                cout << "Graph is not planar!\n" << endl;
                return 0;
            }

            if(m[i][j] || m[j][i]) {
                e++;
            }
        }
    }

    if(e <= (3*n - 6)) {
        cout << "Graph is planar!\n" << endl;
    }

    return 0;
}

