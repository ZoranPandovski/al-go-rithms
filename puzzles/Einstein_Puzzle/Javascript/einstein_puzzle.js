const startTime = Date.now();
function generatePermutations(dictionary) {
  const results = [];
  const permute = (array, position) => {
    if (position === array.length - 1) {
      results.push(array);
    } else {
      for (let i = position; i < array.length; i++) {
        const swap = array[position];
        array.splice(position, 1, array[i]);
        array.splice(i, 1, swap);
        permute(array.slice(), (position + 1));
      }
    }
  };
  permute(dictionary, 0);
  return results;
};

const colors = generatePermutations(['red', 'white', 'green', 'yellow', 'blue']);
const drinks = generatePermutations(['tea', 'coffee', 'milk', 'beer', 'water']);
const smokes = generatePermutations(['Pall Mall', 'Dunhill', 'Blends', 'Bluemasters', 'Prince']);
const pets = generatePermutations(['dogs', 'birds', 'cats', 'fish', 'horse']);
const nationalities = generatePermutations(['Brit', 'Swede', 'Dane', 'Norwegian', 'German']);

function print(color, drink, smoke, pet, nationality) {
  console.log('------');
  [0, 1, 2, 3, 4].forEach(index => {
    console.log('House %s: The %s lives in a %s house, drinks %s, smokes %s, and has %s.',
      index + 1, nationality[index], color[index], drink[index], smoke[index], pet[index]);
  })
  console.log('------');
}

const reasons = {};


let n = 0;
function inc(reason) {
  reasons[reason] = (reasons[reason] || 0) + 1;
}


nationalities.forEach(nationality => {
  // 9. The Norwegian lives in the first house.
  if (nationality[0] !== 'Norwegian') {
    return inc('9. The Norwegian lives in the first house.');
  }
  smokes.forEach(smoke => {
    pets.forEach(pet => {
      // 11. The owner who keeps the horse lives next to the one who smokes Dunhill.
      if (smoke[pet.indexOf('horse') - 1] !== 'Dunhill' && smoke[pet.indexOf('horse') + 1] !== 'Dunhill') {
        return inc('11. The owner who keeps the horse lives next to the one who smokes Dunhill.');
      }
      // 2. The Swede keeps dogs as pets.
      if (pet[nationality.indexOf('Swede')] !== 'dogs') {
        return inc('2. The Swede keeps dogs as pets.');
      }
      // 10. The owner who smokes Blends lives next to the one who keeps cats.
      if (pet[smoke.indexOf('Blends') - 1] !== 'cats' && pet[smoke.indexOf('Blends') + 1] !== 'cats') {
        return inc('10. The owner who smokes Blends lives next to the one who keeps cats.');
      }
      // 6. The owner who smokes Pall Mall rears birds.
      if (pet[smoke.indexOf('Pall Mall')] !== 'birds') {
        return inc('6. The owner who smokes Pall Mall rears birds.');
      }
      drinks.forEach(drink => {
        // 8. The owner living in the center house drinks milk.
        if (drink[2] !== 'milk') {
          return inc('8. The owner living in the center house drinks milk.');
        }
        colors.forEach(color => {
          // 1. The Brit lives in the red house.
          if (color[nationality.indexOf('Brit')] !== 'red') {
            return inc('1. The Brit lives in the red house.');
          }
          // 3. The Dane drinks tea.
          if (drink[nationality.indexOf('Dane')] !== 'tea') {
            return inc('3. The Dane drinks tea.');
          }
          // 4. The green house is on the immediate left of the white house.
          if (color[color.indexOf('green') + 1] !== 'white') {
            return inc('4. The green house is on the immediate left of the white house.');
          }
          // 5. The green house's owner drinks coffee.
          if (drink[color.indexOf('green')] !== 'coffee') {
            return inc('5. The green house\'s owner drinks coffee.');
          }
          // 7. The owner of the yellow house smokes Dunhill.
          if (smoke[color.indexOf('yellow')] !== 'Dunhill') {
            return inc('7. The owner of the yellow house smokes Dunhill.');
          }
          // 12. The owner who smokes Bluemasters drinks beer.
          if (drink[smoke.indexOf('Bluemasters')] !== 'beer') {
            return inc('12. The owner who smokes Bluemasters drinks beer.');
          }
          // 13. The German smokes Prince.
          if (smoke[nationality.indexOf('German')] !== 'Prince') {
            return inc('13. The German smokes Prince.');
          }
          // 14. The Norwegian lives next to the blue house.
          if (color[nationality.indexOf('Norwegian') - 1] !== 'blue' &&
            color[nationality.indexOf('Norwegian') + 1] !== 'blue') {
            return inc('14. The Norwegian lives next to the blue house.');
          }
          // 15. The owner who smokes Blends lives next to the one who drinks water.
          if (drink[smoke.indexOf('Blends') - 1] !== 'water' &&
            drink[smoke.indexOf('Blends') + 1] !== 'water') {
            return inc('15. The owner who smokes Blends lives next to the one who drinks water.');
          }

          print(color, drink, smoke, pet, nationality);
        });
      });
    });
  });
});

// Print reasons
let total = 0;
const totalTime = Date.now() - startTime;
Object
  .keys(reasons)
  .sort((a, b) => reasons[b] - reasons[a]) // reverse order (highest first)
  .forEach(reason => {
    total += reasons[reason];
    console.log(reasons[reason], reason);
  });
console.log('--------\n%d total nodes tested. (%d%% of total space)  %s seconds', total, (100 * total / Math.pow(120, 5)).toPrecision(3), totalTime / 1000);
