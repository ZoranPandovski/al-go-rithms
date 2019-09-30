const fahrenheit = prompt('Enter Fahrenheit value:');

const fahrenheitToCelsius = (number) => {
    return ((number - 32) * 5/9).toFixed(1);
}

document.write(`${fahrenheit} Fahrenheit is ${fahrenheitToCelsius(fahrenheit)} Celsius.`);