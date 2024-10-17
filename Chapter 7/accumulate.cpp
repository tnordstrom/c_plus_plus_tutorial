/* Tony Nordstrom */
/* October 17 02024 */
/* Chapter 7 quiz question 3 */

int accumulate(int x)
{
	static int sum { 0 };
	
	sum += x;
	
	return sum;
}

#endif

/* question 3b */

// Two shortcomings:
// 1. Can't reset the accumulator
// 2. Can't support multiple accumulators
