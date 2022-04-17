//===========================================================================//
//               Library of some sortings:                                   //
// Bubble_sort_Array, Insertion_Sort, Selection_Sort, Shell_Sort, Quick_Sort //
//===========================================================================//


const int  WIDTH_WINDOW        = 970;
const int  HEIGHT_WINDOW       = 820;
const int  WIDTH_BUTTON        = 240;
const int  HEIGHT_BUTTON       = 50;

void Fill_Array                 (int data[], int current_size);
void Print_Array_Common         (int data[], int current_size, char title []);
void Insertion_Sort             (int data[], int current_size);
void Selection_Sort             (int data[], int current_size);
void Bubble_sort_Array          (int data[], int current_size);
void Shell_Sort                 (int data[], int current_size);
void Quick_Sort                 (int data[], int start, int current_size);
void Graphics_Draw_Comparison   (int compares, int current_size, COLORREF color);
void Graphics_Draw_Swap         (int swaps,    int current_size, COLORREF color);
int randInt                     (int a, int b);


int randInt (int a, int b)
    {
    return a + rand()%(b - a + 1);
    }


void Shell_Sort (int data[], int current_size)
    {
    int step = current_size/2;
    int compares = 0;
    int swaps = 0;

    while (step > 0)
        {
        for (int i = 0; i < (current_size - step); i ++)
            {
            assert (0 <= i && i < current_size - step);
            int j = i;
            compares +=1;
            while ((j >= 0) && (data[j] > data[j + step]))
                {
                int temp = data[j];
                data[j] = data[j + step];
                data[j + step] = temp;
                j = j - 1;
                swaps +=1;
                }
            }
        step = step/2;
        }
    Graphics_Draw_Comparison  (compares, current_size, RGB(0, 240, 0));
    Graphics_Draw_Swap        (swaps,    current_size, RGB(0, 240, 0));
    }


void Selection_Sort (int data[], int current_size)
    {
    int compares = 0;
    int swaps = 0;
    int temp = 0;
    for (int i = 0; i < current_size; i ++)
        {
        assert (0 <= i && i < current_size);
        int min_index = i;
        for (int j = i + 1; j < current_size; j ++)
            {
            assert (i + 1 <= j && j < current_size);
            compares += 1;
            if ( data[j] < data[min_index] )
                {
                min_index = j;
                swaps += 1;
                }
            }
        temp = data[i];
        data[i] = data[min_index];
        data[min_index] = temp;
        }
    Graphics_Draw_Comparison  (compares, current_size, RGB(255, 128, 128));
    Graphics_Draw_Swap        (swaps,    current_size, RGB(255, 128, 128));
    }


void Insertion_Sort (int data[], int current_size)
    {
    int compares = 0;
    int swaps = 0;
    for (int i = 1; i < current_size; i ++)
        {
        assert (1 <= i && i < current_size);
        int new_elem = data[i];
        int j = i - 1;

        while ((j >= 0) && (data[j] > new_elem))
            {
            compares += 1;
            data[j + 1] = data [j];
            swaps += 1;
            j = j - 1;

            }
        data[j + 1] = new_elem;
        }
    Graphics_Draw_Comparison  (compares, current_size, RGB(255, 89, 255));
    Graphics_Draw_Swap        (swaps,    current_size, RGB(255, 89, 255));
    }


void Bubble_sort_Array(int data[], int current_size)
    {
    int compares = 0;
    int swaps = 0;
    for (int i = 0; i < current_size; i ++)
        {
        assert (0 <= i && i < current_size);
        for (int j = current_size - 1; j >= i; j --)
            {
            assert (current_size - 1 >= j && j >= i);
            compares += 1;
            if (data[j] > data [j + 1])
                {
                swaps += 1;
                int tmp = data[j];
                data[j] = data [j + 1];
                data [j + 1] = tmp;
                }
            }
        }
    Graphics_Draw_Comparison  (compares, current_size, RGB(34, 145, 255));
    Graphics_Draw_Swap        (swaps,    current_size, RGB(34, 145, 255));
    }


void Quick_Sort (int data[], int start,  int current_size)
    {
    int compares = 0;
    int swaps = 0;
    if (start >= current_size) return;
    int left = start, right = current_size;
    int x = data[randInt (start, current_size)];

    while (left <= right)
        {
        while (data[left] < x)  left ++;
        while (data[right] > x) right --;
        compares += 1;
        if (left <= right)
            {
            int temp = data[left];
            data[left] =  data[right];
            data[right] = temp;
            left ++;
            right --;
            swaps += 1;
            }
        }
    Quick_Sort (data, start, right);
    Quick_Sort (data, left, current_size);
    Graphics_Draw_Comparison  (compares, current_size, RGB(255, 255, 0));
    Graphics_Draw_Swap        (swaps,    current_size, RGB(255, 255, 0));
    }


void Print_Array_Common (int data[], int current_size, char title [])
    {
    $y; printf ("\n%s", title);
    for (int i = 0; i < current_size; i ++)
            {
            $y; printf ("[%2d] =", i);
            $g; printf ("%3d", data[i]);
            if (i < current_size - 1) {$c; printf (", ");}
            }
    printf ("\n");
    }

void Fill_Array (int data[], int current_size)
    {
    srand(time(NULL));
    for (int i = 0; i < current_size; i += 1)
        {
        assert (0 <= i && i < current_size);
        data[i] = rand()%15 + 7;
        }
    }

void Graphics_Draw_Comparison (int compares, int current_size, COLORREF color)
    {
    int prev_x = 90;
    int prev_y = 390;
    txSetColor (color, 2);
    txSetFillColor (color);
    txCircle (prev_x + current_size*4.9, prev_y - compares/18, 3);
    }

void Graphics_Draw_Swap(int swaps, int current_size, COLORREF color)
    {
    int prev_x = 90;
    int prev_y = 760;
    txSetColor (color, 2);
    txSetFillColor (color);
    txCircle(prev_x + current_size*4.9, prev_y - swaps/18, 3);
    }
