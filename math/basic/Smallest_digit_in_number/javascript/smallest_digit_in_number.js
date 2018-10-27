const smallestDigitInNumber = n => n.toString().split('').reduce((min, current) => min = min > current ? current : min, 9);
