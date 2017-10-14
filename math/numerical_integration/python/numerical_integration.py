def integrate(func, lower_limit, upper_limit, step):
	integral = 0

	half_step = step / 2

	cur_val = lower_limit

	while cur_val < upper_limit:
		cur_val += half_step

		integral += func(cur_val) * step

		cur_val += half_step
		
	return integral