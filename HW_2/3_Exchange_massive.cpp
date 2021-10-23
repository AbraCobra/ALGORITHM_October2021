#include <TXLib.h>
#include <stdio.h>
#include <assert.h>

void Fill_Array  (int data[], int size, int step);
void Print_Array (int data[], int size, const char title[]);


int main ()
    {
    int data [20] = {};

    Fill_Array  (data, 20, 1);
    Print_Array (data, 20, "Exchange of places");

    printf ("\n");
    return 0;
    }

void Fill_Array (int data[], int size, int step)
    {
    for (int i = 0; i < size; i += step)
        {
        assert (0 <= i && i < size);
        data[i] = i;
        }
    for (int i = 0; i < size - 1; i += 2)
        {
        assert (0 <= i && i < size);
        assert (0 <= (i + 1) && (i + 1) < size);

        int temp = data [i];
        data[i] = data [i + 1];
        data [i + 1] = temp;
        }
    }
void Print_Array (int data[], int size, const char title[])
    {
    $y; printf ("\n%s: ", title);
    for (int i = 0; i < size; i ++)
        {
        $g; printf ("%02d", data[i]);
        $r; printf (",");
        }
    }

