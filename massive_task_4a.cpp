#include "TXLib.h"
#include <assert.h>

void Fill_Array  (int data[], int size, int step, int start);
void Print_Array (int data[], int size, int step);



int main ()
    {
    int data [20] = {};

    Fill_Array  (data, 20, 1, 0);
    Print_Array (data, 20, 1);

    printf ("\n");
    return 0;
    }

void Fill_Array (int data[], int size, int step, int start)
    {
    for (int i = 0; i < size/2; ++i)
        {
        assert (0 <= i && i < size);
        data[i] = start + 1;
        start = data[i];
        data[size - 1 - i] = start + 1;
        start = data[size - 1 - i];
        }
    }

void Print_Array (int data[], int size, int step)
    {
    for (int i = 0; i < size; i += step)
        {
        assert (0 <= i && i < size);
        $g; printf ("%2d", data[i]);

        if (i < size - 1) {$r; printf (", ");}

        }
    }
