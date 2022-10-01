var Node = function(data){
  this.data=data;
  this.next=null;
}
  
var LinkedList = function(){
  this.next=null
}
  
LinkedList.prototype.addNode = function(value){
  var ref= this;
  while(ref.next != null){
    ref = ref.next
  };
  ref.next = new Node(value)
}

LinkedList.prototype.findNode = function(value){
  var ref= this.next;
  while(ref != null){
    if(ref.data == value){
      return ref
    }
    ref = ref.next
  };

  return null
}

LinkedList.prototype.removeNode = function(value){
  var ref= this.next,
      prev = this,
      next = null;
  while(ref != null){
    if(ref.data == value){
      next = ref.next;
      prev.next = next;
      return true;
    }
    prev = ref;
    ref = ref.next;
  };

  return false
}

var ll =new LinkedList();

//ll.addNode(new Node(10));

var submit =document.getElementsByClassName('js-submit')[0];

var find =document.getElementsByClassName('js-find')[0];

var remove =document.getElementsByClassName('js-remove')[0];

var nodeList = document.getElementsByClassName('node-list')[0];

submit.addEventListener('click',function(e){
  ll.addNode(document.getElementsByClassName('value')[0].value);
  renderView();
})

remove.addEventListener('click',function(e){
  ll.removeNode(document.getElementsByClassName('value')[0].value);
  renderView();
})

find.addEventListener('click',function(e){
  var value = document.getElementsByClassName('value')[0].value;
  if(ll.findNode(value) != null){
    _zoom(document.getElementsByClassName(value),true);
    setTimeout(function(){
      _zoom(document.getElementsByClassName(value),false);
    },1500)
  }

})

function _zoom(ref,flag){
  if(flag) {
    console.log(ref)
    for (i in ref){
      if(typeof ref[i] == 'object'){
        ref[i].classList.add('zoom')
      }
    }
  } else {
    for (i in ref){
      if(typeof ref[i] == 'object'){
        ref[i].classList.remove('zoom')
      }
    }0
  }
}
function renderView(){
  var str = '',
      ref = ll,
      counter=0;
  nodeList.innerHTML = '';
  while(ref.next !== null){
    nodeList.appendChild(createNode(ref.next.data,counter));
        counter++;
    ref = ref.next;
  }
  
  function createNode(value,counter){
    var container = document.createElement('div'),
        dataElement = document.createElement('span');
    
    container.className="node";
    dataElement.innerHTML = value;
   
    dataElement.style.background = getColor(value,counter)
    container.appendChild(dataElement);
    dataElement.className=value;
    return container
  }
  function getColor(value,counter){
    value = 255 - Number(value)%255;
    switch (value%3){
      case 0:
          return 'rgb('+value+','+value+',0)';
      case 1:
        return 'rgb('+value+',0,'+value+')';
      default:
        return 'rgb(0,'+value+','+value+')';
    }
  }
}
