/**
 * @brief Find the least common multiple bettween integers x and y
 * You will need the Greatest Common Divisor Function
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int LCM(int x, int y)
{
    return ((x*y)/GCD(x, y));
}
