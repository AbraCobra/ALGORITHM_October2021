#include "TXLib.h"
#include <assert.h>

void Fill_Array  (int data[], int size, int step);
void Print_Array (int data[], int size, int step);



int main ()
    {
    int data [21] = {};
    Fill_Array  (data, 21, 1);
    Print_Array (data, 21, 1);

    printf ("\n");
    return 0;
    }

void Fill_Array (int data[], int size, int step)
    {
    for (int i = 0; i < size; i += step)
        {
        assert (0 <= i && i < size);
        if (i%3 == 0) data[i] = 1;
        if (i%3 == 1) data[i] = 2;
        if (i%3 == 2) data[i] = 3;
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
