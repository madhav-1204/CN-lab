// Go-Back-N ARQ
#include <iostream>
using namespace std;

int main()
{
    int totalFrames, windowSize, lostFrame;

    cout << "Enter Total Number of Frames: ";
    cin >> totalFrames;

    cout << "Enter Window Size: ";
    cin >> windowSize;

    cout << "Enter Lost Frame Number (-1 if no loss): ";
    cin >> lostFrame;

    int i = 0;

    while (i < totalFrames)
    {
        cout << "\n----- Sender Side -----\n\n";
        cout << "Sending Window:\n";

        for (int j = i; j < i + windowSize && j < totalFrames; j++)
            cout << "Frame " << j << " Sent\n";

        cout << "\n----- Receiver Side -----\n";

        if (lostFrame >= i && lostFrame < i + windowSize)
        {
            for (int j = i; j < lostFrame; j++)
            {
                cout << "Frame " << j << " Received\n";
                cout << "ACK " << j << " Sent\n";
            }

            cout << "Frame " << lostFrame << " Lost\n";

            for (int j = lostFrame + 1; j < i + windowSize && j < totalFrames; j++)
                cout << "Frame " << j << " Discarded (Out of Order)\n";

            cout << "\nTimeout Occurred\n";
            cout << "Go-Back-N Retransmission Begins\n\n";

            for (int j = lostFrame; j < i + windowSize && j < totalFrames; j++)
            {
                cout << "Retransmitting Frame " << j << "\n";
                cout << "Frame " << j << " Received\n";
                cout << "ACK " << j << " Sent\n";
            }

            i += windowSize;
            lostFrame = -1;
        }
        else
        {
            for (int j = i; j < i + windowSize && j < totalFrames; j++)
            {
                cout << "Frame " << j << " Received\n";
                cout << "ACK " << j << " Sent\n";
            }

            i += windowSize;
        }
    }

    cout << "\nAll Frames Successfully Transmitted.\n";

    return 0;
}


// Enter Total Number of Frames: 5
// Enter Window Size: 3
// Enter Lost Frame Number (-1 if no loss): 1