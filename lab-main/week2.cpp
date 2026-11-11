//CRC code

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, divisor, temp, remainder;

    cout << "enter data : ";
    cin >> data;

    cout << "enter divisor : ";
    cin >> divisor;

    int n = data.length();
    int m = divisor.length();

    temp = data + string(m - 1, '0');

    for (int i = 0; i < n; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < m; j++)
            {
                temp[i + j] =
                    (temp[i + j] - '0') ^ (divisor[j] - '0') + '0';
            }
        }
    }

    remainder = temp.substr(n, m - 1);

    cout << "\n CRC Remainder :" << remainder;
    cout << "\n Transmitted codeword:" << data << remainder;

    return 0;
}


// enter data : 1101011011
// enter divisor : 10011

//  CRC Remainder :1110
//  Transmitted codeword:11010110111110