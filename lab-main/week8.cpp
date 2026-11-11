// Leaky bucket algorithm

#include <iostream>
using namespace std;

int main()
{
    int bucketSize, outputRate;
    int packets[100] = {0};
    int seconds = 0, choice;
    int remaining = 0, dropped, sent, incoming;

    cout << "\nEnter Bucket Size: ";
    cin >> bucketSize;

    cout << "Enter Output Rate: ";
    cin >> outputRate;

    do
    {
        cout << "\nEnter number of packets coming at second "
             << seconds + 1 << ": ";
        cin >> packets[seconds];
        seconds++;

        cout << "Enter 1 to continue or 0 to quit: ";
        cin >> choice;

    } while (choice == 1 && seconds < 100);

    cout << "\nSecond\tReceived\tSent\tDropped\tRemained\n";
    cout << "---------------------------\n";

    for (int i = 0; remaining > 0 || i < seconds; i++)
    {
        incoming = (i < seconds) ? packets[i] : 0;

        if (incoming + remaining > bucketSize)
        {
            dropped = incoming + remaining - bucketSize;
            remaining = bucketSize;
        }
        else
        {
            dropped = 0;
            remaining += incoming;
        }

        sent = (remaining < outputRate) ? remaining : outputRate;
        remaining -= sent;

        cout << i + 1 << "\t" << incoming << "\t\t"
             << sent << "\t" << dropped << "\t"
             << remaining << endl;
    }

    return 0;
}


// Enter Bucket Size: 10
// Enter Output Rate: 4

// Enter number of packets coming at second 1: 6
// Enter 1 to continue or 0 to quit: 1

// Enter number of packets coming at second 2: 8
// Enter 1 to continue or 0 to quit: 1

// Enter number of packets coming at second 3: 3
// Enter 1 to continue or 0 to quit: 0