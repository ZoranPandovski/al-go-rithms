var buttons = document.getElementsByClassName("button");
var display = document.getElementById("display");
var display2 = document.getElementById("display2");

var operand1 = 0, operand2 = null, operator = null;

function isOperator(value) {
    return value == "+" || value == "-" || value == "*" || value == "/";
}

for (var i = 0; i < buttons.length; i++) {
    buttons[i].addEventListener('click', function () {
        var value = this.getAttribute('data-value');
        var text = display.textContent.trim();

        if (isOperator(value)) {
            operator = value;
            operand1 = parseFloat(text);
            display.textContent = "";
            display2.textContent = operand1 + "" + operator;
        }
        else if (value == "ac") {
            display.textContent = "";
            display2.textContent = "A/C"
        }
        else if (value == "sign") {
            operand1 = parseFloat(text);
            operand1 = operand1 * (-1);
            display.textContent = operand1;
        }
        else if (value == ".") {
            if (text.length && !text.includes('.')) {
                display.textContent = text + '.';
            }
        }
        else if (value == "%") {
            operand1 = parseFloat(text);
            operand1 /= 100;
            display.textContent = operand1;
        }
        else if (value == "=") {
            operand2 = parseFloat(text);
            var result = eval(operand1 + ' ' + operator + ' ' + operand2);
            if (result) {
                display.textContent = result;
                display2.textContent = operand1 + ' ' + operator + ' ' + operand2 + " = " + result;
                operand1 = result;
                operand2 = null;
                operator = null;
            }
        }
        else {
            display.textContent += value;
            display2.textContent = "";
        }
    });
}