int collatz_conjecture(int input)
{
    if(input % 2 == 0)
        return input / 2;
    
    else
        return 3 * input + 1;
}

int test_collatz_conjecture(int input, int max_iter)
{
    int counter = 0;
    while(input != 1 && counter < max_iter)
    {
        input = collatz_conjecture(input);
        counter = counter + 1;
    }
    
    if(counter == max_iter && input != 1)
        return -1;

    return counter;
}