
#include <iostream>
using namespace std;

struct Frame
{
    int seq_no;
    char data[50];
};

int main()
{
    int n;
    Frame buffer[50], temp;

    cout << "Enter the number of frames: ";
    cin >> n;

    cout << "\nEnter frames in random arrival order:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Frame " << i + 1 << " -> Enter sequence number: ";
        cin >> buffer[i].seq_no;

        cout << "Frame " << i + 1 << " -> Enter frame data: ";
        cin >> buffer[i].data;
    }

    cout << "\n--- Frames Received in Buffer (Random Order) ---\n";

    for (int i = 0; i < n; i++)
        cout << "Seq No: " << buffer[i].seq_no
             << " | Data: " << buffer[i].data << endl;

    // Insertion Sort
    for (int i = 1; i < n; i++)
    {
        temp = buffer[i];
        int j = i - 1;

        while (j >= 0 && buffer[j].seq_no > temp.seq_no)
        {
            buffer[j + 1] = buffer[j];
            j--;
        }

        buffer[j + 1] = temp;
    }

    cout << "\n--- Frames After Sorting (Sequential Order) ---\n";

    for (int i = 0; i < n; i++)
        cout << "Seq No: " << buffer[i].seq_no
             << " | Data: " << buffer[i].data << endl;

    return 0;
}

// Enter the number of frames: 3

// Enter frames in random arrival order:
// Frame 1 -> Enter sequence number: 3
// Frame 1 -> Enter frame data: Hello
// Frame 2 -> Enter sequence number: 1
// Frame 2 -> Enter frame data: Welcome
// Frame 3 -> Enter sequence number: 2
// Frame 3 -> Enter frame data: Network