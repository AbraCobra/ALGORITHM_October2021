#include <TXLib.h>
#include <stdio.h>
#include <assert.h>

void Fill_Array  (int data[], int size, int step);
void Print_Array (int data[], int size, const char title[]);
void Cyclic_left_shift  (int data[], int size);
void Cyclic_right_shift (int data[], int size);

int main ()
    {
    int data [20] = {};

    Fill_Array  (data, 20, 1);
    Print_Array (data, 20, "Original   massive");

    Cyclic_right_shift (data, 20);
    printf ("\n");
    Print_Array (data, 20, "Cyclic right shift");
    printf ("\n");

    Cyclic_left_shift  (data, 20); //return massive into initial state

    Cyclic_left_shift  (data, 20);
    Print_Array (data, 20, "Cyclic  left shift");
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
    }

void Cyclic_left_shift (int data[], int size)
    {
    int temp = data[0];

    for (int i = 0; i < size - 1; i ++)
        {
        assert (0 <= i && i < size);
        assert (0 <= (i + 1) && (i + 1) < size);

        data[i] = data [i + 1];
        }

    data [size - 1] = temp;
    }

void Cyclic_right_shift (int data[], int size)
    {
    int temp = data[size - 1];

    for (int i = size - 1; i > 0; --i)
        {
        assert (0 <= i && i < size);
        assert (0 <= (i - 1) && (i - 1) < size);

        data[i] = data [i - 1];
        }

    data [0] = temp;
    }

void Print_Array (int data[], int size, const char title[])
    {
    $y; printf ("\n%s:  ", title);
    for (int i = 0; i < size; i ++)
        {
        $g; printf ("%02d", data[i]);
        $r; printf (",");
        }
    }

