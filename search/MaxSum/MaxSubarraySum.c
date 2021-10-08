#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long max_sum(
    unsigned long *partial_sums,
    unsigned long *dest,
    unsigned length,
    unsigned long target)
{
    if (length < 2)
        return (*dest = *partial_sums);

    unsigned
        lower_len = length >> 1,
        upper_len = length - lower_len;

    unsigned long
        lower[lower_len],
        upper[upper_len],
        max_left = max_sum(partial_sums, lower, lower_len, target),
        max_right = max_sum(&partial_sums[lower_len], upper, upper_len, target),
        max = max_left > max_right ? max_left : max_right;

    unsigned lesser = 0, greater = 0;

    while (lesser < lower_len && greater < upper_len)
        if (upper[greater] < lower[lesser])
        {
            *dest = upper[greater++];
            unsigned long other_max = (*dest++ - lower[lesser]) + target;
            if (other_max > max)
                max = other_max;
        }
        else
            *dest++ = lower[lesser++];

    memcpy(dest, &lower[lesser], (lower_len - lesser) * sizeof(*dest));
    memcpy(&dest[lower_len - lesser], &upper[greater], (upper_len - greater) * sizeof(*dest));

    return max;
}

int main()
{
    unsigned length;
    unsigned long test_case, limit, index;
    static unsigned long
        items[100000],
        buffer[100001] = {[0] = 0},
        *partial_sums = &buffer[1];

    for (scanf("%lu", &test_case); test_case--;)
    {
        scanf("%u", &length);
        scanf("%lu", &limit);

        for (index = 0; index < length; index++)
        {
            scanf("%lu", &items[index]);
            items[index] %= limit;
            partial_sums[index] = (items[index] + partial_sums[index - 1ULL]) % limit;
        }

        static unsigned long ordered[100000];
        unsigned long max = max_sum(partial_sums, ordered, length, limit);
        printf("%lu\n", max);
    }
    return 0;
}
