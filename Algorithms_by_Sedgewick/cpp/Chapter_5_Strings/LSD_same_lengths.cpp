#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> s;
const int R = 256;

void sort(int W)
{
    // W: compare string based on leading W characters
    int l = s.size();
    vector<string> aux = s;
    for ( int d = W - 1; d >= 0; d -- )
    {            
        // create a cnt[] for each comparison
        // use prefix sum to calculate each character's frequency, so cnt[0] is always 0
        int cnt[R + 1] = {0};
        for ( int i = 0; i < l; i ++ )
        {
            // frequency of each character
            // use character's value plus 1 as index of cnt[]
            cnt[s[i][d] - 'a' + 1] ++ ;
        }
        
        // convert cnt[] to contain starting indexes of each character's value
        for ( int i = 1; i <= R + 1; i ++ )
        {
            cnt[i] += cnt[i - 1];
        }

        // create aux based on the order of d-th digit
        for ( int i = 0; i < l; i ++ )
        {
            aux[cnt[s[i][d] - 'a'] ++ ] = s[i];
        }

        // move string from aux back to s
        for ( int i = 0; i < l; i ++ ) s[i] = aux[i];
    }
}

int main()
{
    int n, W;
    cin >> n >> W;
    for ( int i = 0; i < n; i ++ ) 
    {   
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }

    sort(W);
    for ( int i = 0; i < s.size(); i ++ ) cout << s[i] << endl;

    return 0;
}
