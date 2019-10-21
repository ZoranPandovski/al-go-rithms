const greatestDigitInNumber = n => n.toString().split('').reduce((max, current) => max = max < current ? current : max , 0);
