.pragma library

function now() {
    var    currentdate = new Date();
    return currentdate.getDate() + "/"
        + (currentdate.getMonth()+1)  + "/"
         + currentdate.getFullYear() + "  "
         + currentdate.getHours() + ":"
         + currentdate.getMinutes() + ":"
         + currentdate.getSeconds() + "."
         + currentdate.getMilliseconds();
}

function log(msg) {
    console.log(now() + " @ " + msg)
}

function isNumber(i) {
    return !isNaN(i && i !== true ? Number(i) : parseFloat(i)) && [Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY].indexOf(i) === -1;
}
