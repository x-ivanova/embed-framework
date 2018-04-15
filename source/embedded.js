BASE_URL = "http://192.168.0.6:8080";

MAIN_HANDLER = 'handler';
CLICKABLE_HANDLER = 'clickable';
CHANGEABLE_HANDLER = 'changeable';
ONRESPONSE_HANDLER = 'onResponse';

GET_PATH = '/get/';
SET_PATH = '/set/?';


function getAllElementsByAttribute(atrribute){
    var massiv = [];
    $('[' + atrribute +']').each(function(index, value) {
        massiv.push($(this));
    });
    return massiv;
}

function getRequest(){
    var result;
    $.ajax({
        url: BASE_URL + GET_PATH,
        async: false,
        type: 'GET',
        success:function(data) {
            result = data;
        }
    });
    return result;
}

function onResponse(x, string) {
    eval(string)
}

function clickHandler(){
    var chElements = getAllElementsByAttribute(CLICKABLE_HANDLER);
    for (var i = 0; i < chElements.length; i ++){
        chElements[i].click(function(x) {
            return function() {
            $.ajax({
                url: BASE_URL + '/' + chElements[x].attr(MAIN_HANDLER) + '/',
                type: 'GET',
                success: function (results) {
                    if (chElements[x].attr(ONRESPONSE_HANDLER)) onResponse(results, chElements[x].attr(ONRESPONSE_HANDLER));
                }
            });
        }
        }(i));
    }
}

function changeHandler(){
    var chElements = getAllElementsByAttribute(CHANGEABLE_HANDLER);
    for (var i = 0; i < chElements.length; i ++){
        chElements[i].change(function(x) {
            return function() {
                $.ajax({
                    url: BASE_URL + SET_PATH + chElements[x].attr(MAIN_HANDLER) + '=' + chElements[x].val(),
                    type: 'GET',
                    success: function (results) {
                        if (chElements[x].attr(ONRESPONSE_HANDLER)) onResponse(results, chElements[x].attr(ONRESPONSE_HANDLER));
                    }
                });
            }
        }(i));
    }
}


function fillInside(js) {
    if (js[$('input[type="checkbox"]').attr('handler')] == 1) $('input[type="checkbox"]').attr("checked", "checked")
    $('input[type="range"]').val(js[$('input[type="range"]').attr(MAIN_HANDLER)]);
    $('input[type="text"]').val(js[$('input[type="text"]').attr(MAIN_HANDLER)]);
    $('select').val(js[$('select').attr(MAIN_HANDLER)]);
}

function fillOutside(js) {
    var orElements = getAllElementsByAttribute(ONRESPONSE_HANDLER);
    for (var i = 0; i < orElements.length; i++) onResponse(js[orElements[i].attr(MAIN_HANDLER)], orElements[i].attr(ONRESPONSE_HANDLER));
}


function update(){
    var js = getRequest();
    //fillOutside(js);
    fillInside(js);
}

$(document).ready(function() {
    update();
    clickHandler();
    changeHandler();
});