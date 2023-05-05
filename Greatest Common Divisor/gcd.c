/**
* @brief Find the greatest common divisor (GCD) between two non-negative integers.
* Don't use x = 0 and y = 0 at the same time! At least one of the variables has to have a positive value.
* 
* @param int x
* @param int y 
* 
* @return GCD(x, y)
*/
int GCD(int x, int y)
{
    int greatest, smallest;

    if (x > y)
    {
        greatest = x;
        smallest = y;
    }
    else
    {
        smallest = x;
        greatest = y;
    }

    if (smallest == 0) return greatest;

    else GCD(smallest, greatest%smallest);
}