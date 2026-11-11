
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b = "01111110";

    cout << "Enter input frame (0's and 1's): ";
    cin >> a;

    int count = 0;

    for (int i = 0; i < a.length(); i++)
    {
        b += a[i];

        if (a[i] == '1')
        {
            count++;

            if (count == 5)
            {
                b += '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    b += "01111110";

    cout << "After stuffing, the frame is: " << endl;
    cout << b << endl;

    return 0;
}


// Enter input frame (0's and 1's): 1111101111110

// After stuffing, the frame is:
// 011111100111110011111001101111110



#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, frame = "flag";

    cout << "Enter the input string: ";
    getline(cin, data);

    cout << "\nEntered input = " << data << endl;

    for (int i = 0; i < data.length();)
    {
        if (data.substr(i, 4) == "flag")
        {
            frame += "escflag";
            i += 4;
        }
        else if (data.substr(i, 3) == "esc")
        {
            frame += "escesc";
            i += 3;
        }
        else
        {
            frame += data[i];
            i++;
        }
    }

    frame += "flag";

    cout << "\nString after stuffing  = " << frame << endl;

    return 0;
}


// Enter the input string: ABCflagXYZ

// Entered input = ABCflagXYZ

// String after stuffing  = flagABCescflagXYZflag
