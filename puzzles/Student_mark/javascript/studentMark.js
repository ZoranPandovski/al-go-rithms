(function(){
"use strict"

const studentMark = function(day, numStudents) {
    if (day >= numStudents){
        return numStudents;
    } else {
        return day;
    }

}

module.exports = studentMark;

})();  