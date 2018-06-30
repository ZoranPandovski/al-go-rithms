var rows, cols;
var w = 40;

var grid = [];
var current;
var stack = [];

function setup() {
	var cnv = createCanvas(600, 600);

	//centering the canvas
	let x = (windowWidth - width) / 2;
	let y = (windowHeight - height) / 2;
	cnv.position(x, y);

	cols = floor(width/w);
	rows = floor(height/w);

	//frameRate(5);

	for (var j = 0; j < rows; ++j) {
		for (var i = 0; i < cols; ++i) {
			var cell = new Cell(i, j);
			grid.push(cell);
		}
	}
	current = grid[0];
}

function draw() {
	background(51);
	for (var i = 0; i < grid.length; ++i) {
		grid[i].show();
	}
	current.visited = true;
	current.highlight();

//STEP - 1: Choose randomly one of the unvisited neighbours
	var next = current.checkNeighbors();

	if (next) {
		next.visited = true;

//STEP - 2: Push the current cell to the stack (for backtracking)
		stack.push(current);

//STEP - 3 : Remove the wall between the current cell and the chosen cell
		removeWalls(current, next);

//STEP - 4 : Make the chosen cell the current cell and mark it as visited
		current = next;
	} else if (stack.length > 0) {       // Else if stack is not empty
		var cell = stack.pop();			//  Pop a cell from the stack
		current = cell;				   //   Make it the current cell
	}
}

function index(i, j) {	//help you to find the index of cell as they are in 1D.
	if (i < 0 || j < 0 || i > cols - 1 || j > rows - 1) {
		return -1;
	}

	return i + j * cols;
}

function Cell(i, j) {
	this.i = i;
	this.j = j;
	this.walls = [true, true, true, true];  //top, right, bottom, left. (box)
	this.visited = false;

	this.highlight = function() {
		var x = this.i * w;
		var y = this.j * w;
		noStroke();
		fill(0, 255, 0, 80);
		rect(x, y, w, w);
	}

	this.checkNeighbors = function() {
		var neighbors = [];
		var top 	= grid[index(i, j - 1)];
		var right   = grid[index(i + 1, j)];
		var bottom  = grid[index(i, j + 1)];
		var left    = grid[index(i - 1, j)];

		if (top && !top.visited) {
			neighbors.push(top);
		}

		if (right && !right.visited) {
			neighbors.push(right);
		}
		if (bottom && !bottom.visited) {
			neighbors.push(bottom);
		}
		if (left && !left.visited) {
			neighbors.push(left);
		}

		if (neighbors.length > 0) {
			var r = floor(random(0, neighbors.length));
			return neighbors[r];
		} else {
			return undefined;
		}
	}

	this.show = function() {
		var x = this.i * w;
		var y = this.j * w;
		stroke(255);
		if (this.walls[0]) {
			line(x, y, x + w, y);
		}
		if (this.walls[1]) {
			line(x + w, y, x + w, y + w);
		}
		if (this.walls[2]) {
			line(x + w, y + w, x, y + w);
		}
		if (this.walls[3]) {
			line(x, y + w, x, y);
		}

		if (this.visited) {
			noStroke();
			fill(204, 153, 0, 100);
			rect(x, y, w, w);	//create rectangle
		}	
	}
}

function removeWalls(a, b) {
	var x = a.i - b.i;
	if (x === 1) {
		a.walls[3] = false;
		b.walls[1] = false;
	} else if (x === -1) {
		a.walls[1] = false;
		b.walls[3] = false;
	}

	var y = a.j - b.j;
	if (y === 1) {
		a.walls[0] = false;
		b.walls[2] = false;
	} else if (y === -1) {
		a.walls[2] = false;
		b.walls[0] = false;
	}
}