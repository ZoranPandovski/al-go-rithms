function Dictionary(){
	this.add = add;
	this.datastore = new Array();
	this.find = find;
	this.remove = remove;
	this.showAll = showAll;
}

function add(key, value){
	this.datastore[key] = value;
}
function find(key){
	return this.datastore[key];
}
function remove(key){
	delete this.datastore[key];
}
function showAll(){
	for each (var key in Object.keys(this.datastore)){
		console.log(key + " -> "+this.datastore[key]);
	}
}

var pbook = new Dictionary();
pbook.add("Mike", "34434");
pbook.add("Andy", "3545");

console.log("andy: " + pbook.find("Andy"));
pbook.remove("Andy");
pbook.showAll();

