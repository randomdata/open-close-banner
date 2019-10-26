// set your channel id here
var channel_id = CHANNEL_ID
// set your channel's read api key here if necessary
var api_key = 'KEY';


function update(){
// get the data from thingspeak
$.getJSON('https://api.thingspeak.com/channels/' + channel_id + '/feed/last.json?api_key=' + api_key, function(data) {
    // Debugging
    console.log(data);
    
    // get the data point
    state = data.field1;

    // if there is a data point display it
    if (state > 0) {
    $("#status_div").removeClass("closed").addClass("open");
    $("#status_div").text("OPEN");
    }else{
    $("#status_div").removeClass("open").addClass("closed");
    $("#status_div").text("CLOSED");
    }
});
}

$(function(){
    update();
    setInterval(update,3000);
});