int divide(int dividend, int divisor) {
    // Handle overflow edge case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; 
    }

    // Determine the sign of the result
    int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

    // Work with positive values for simplicity
    long long absDividend = llabs((long long) dividend);
    long long absDivisor = llabs((long long) divisor);

    long long quotient = 0;

    // Subtract the divisor from the dividend using bitwise shifts
    while (absDividend >= absDivisor) {
        long long tempDivisor = absDivisor;
        long long multiple = 1;
        while (absDividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
            multiple <<= 1;
        }
        absDividend -= tempDivisor;
        quotient += multiple;
    }

    // Apply the sign to the result
    return (int) (sign * quotient);
}
