# Stable Matching Problem

Problem

Consider m men and n women. Each man has a preference list where he gives priority to each woman, similarly each woman has a preference list. The problem here is to find a stable matching amongst all m men and n women. By stable matching, we mean that there is no 'instability' in the matching. Consider two pairs (m, w) and (m', w'). Instability can arise in following 2 cases:
a. m is higher on preference list of w' as compared to m' and w' is higher on preference list of m as compared to w.
b. m' is higher on preference list of w as compared to m and w is higher on preference list of m' as compared to w'.

Solution

Gale Shapley Algorithm

while (some man 'm' is free and hasn't proposed to every woman)
	Choose such a man 'm'
	w = 1st woman in preference list of man 'm' whom he hasn't proposed
	if (w is free)
		(m, w) are engaged
	else if (w is engaged but prefers m over her current partner m')
		(m, w) are engaged
		m' is free
	else
		w rejects m