package;

class LinkedListTest {
    static function main() {

        var list = new LinkedList<String>();

        trace(list.length == 0);
        trace(list.isEmpty());
        trace(list.first == null);
        trace(list.last == null);

        list.append('world');
        list.prepend('my');
        list.prepend('hello');

        trace(list.length == 3);
        trace(!list.isEmpty());
        trace(list.first == 'hello');
        trace(list.last == 'world');
        trace(list.getItemAt(1) == 'my');
        trace(list.remove('my'));
        trace(!list.remove('not my'));
        trace(list.length == 2);
        trace(list.remove('hello'));
        trace(list.remove('world'));
        trace(list.length == 0);

        list.append('world');
        list.prepend('hello');

        trace(list.getItemAt(0), list.getItemAt(1));
        list.clear();
        trace(list.isEmpty());

        list.append('hello');
        list.append('world');
        trace(list.shift() == 'hello');
        trace(list.shift() == 'world');
        trace(list.first == null, list.last == null);
        
        var list = new LinkedList<SomeStruct>();
        list.append({prop: 'foo'});
        list.append({prop: 'bar'});
        list.iterate(function(item, ind) { item.prop = item.prop.toUpperCase(); });
        trace(list.getItemAt(0).prop == 'FOO', list.getItemAt(1).prop == 'BAR');
    }
}

typedef SomeStruct = {
    var prop:String;
}
