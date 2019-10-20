/* Using the JavaScript language, have the function ClosestEnemyII(strArr) read the matrix of numbers stored in strArr which will be a 2D matrix that contains only the integers 1, 0, or 2. Then from the position in the matrix where a 1 is, return the number of spaces either left, right, down, or up you must move to reach an enemy which is represented by a 2. You are able to wrap around one side of the matrix to the other as well. For example: if strArr is ["0000", "1000", "0002", "0002"] then this looks like the following:

0 0 0 0 1 0 0 0 0 0 0 2 0 0 0 2

For this input your program should return 2 because the closest enemy (2) is 2 spaces away from the 1 by moving left to wrap to the other side and then moving down once. The array will contain any number of 0's and 2's, but only a single 1. It may not contain any 2's at all as well, where in that case your program should return a 0.

Test Cases
Input:"000", "100", "200" Output:1

Input:"0000", "2010", "0000", "2002" Output:2 */

function ClosestEnemyII(strArr){
  let player = [];
  let ennemy = [];
  let distance = 0;
  let arrLength = strArr[0].length;
  let arrWidth = strArr.length;

  for(let i = 0; i < strArr.length; i++){
    let ligne = strArr[i].split("");
    for(let j = 0; j < ligne.length; j++){
      if(ligne[j] == 1){
        player.push(j, i);
      }else if(ligne[j] == 2){
        ennemy.push(j, i);
      }
    }
  }

  for(let i = 0; i < ennemy.length; i+=2){
    let newDistance = 0;
    if(Math.abs(player[0] - ennemy[i]) < arrLength / 2){
      newDistance = Math.abs(player[0] - ennemy[i]);
    }else{
      newDistance = arrLength - Math.abs(player[0] - ennemy[i]);
    }

    if(Math.abs(player[1] - ennemy[i+1]) < arrWidth / 2){
      newDistance += Math.abs(player[1] - ennemy[i+1]);
    }else{
      newDistance += arrWidth - Math.abs(player[0] - ennemy[i]);
    }

    if(distance == 0 || newDistance < distance){
      distance = newDistance;
    }
  }
  return distance;
}

ClosestEnemyII(["0000", "1000", "0002", "0002"]);
ClosestEnemyII(["0000", "2010", "0000", "2002"]);
