const sleepSort = (unsortedArray) => {
  unsortedArray.forEach(value => {
    setTimeout(() => {
      console.log(value);
    }, value * 100);
  })
}

const array = [2, 7, 1, 5, 8, 9, 1];
sleepSort(array);
