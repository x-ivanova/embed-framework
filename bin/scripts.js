var BASE_URL = "http://0.0.0.0:8080"


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
        url: BASE_URL + '/get/',
        async: false,
        type: 'GET',
        success:function(data) {
            result = data;
        }
    })
    return result;
}

function onResponse(x, string) {
    eval(string)
}

function clickHandler(){
    chElements = getAllElementsByAttribute('clickable');
    for (var i = 0; i < chElements.length; i ++){
        chElements[i].click(function(x) {
            return function() {
            $.ajax({
                url: BASE_URL + '/' + chElements[x].attr('handler') + '/',
                type: 'GET',
                success: function (results) {
                    if (chElements[x].attr('onResponse')) {
                        onResponse(results, chElements[x].attr('onResponse'));
                    }
                }
            });
        }
        }(i));
    }
}

function check() {
    var checkAttr = $('input[type="checkbox"]').attr('handler');
    if (js[checkAttr] == 1) {
        $('input[type="checkbox"]').attr("checked", "checked");
    }
    var selectkAttr = $('input[type="range"]').attr('handler');
    $('input[type="range"]').attr("value", js[selectkAttr]);
}



function update(handler){
    js = getRequest();
    orElements = getAllElementsByAttribute('onResponse');
    for (var i = 0; i < orElements.length; i++){
        onResponseAttribute = orElements[i].attr('onResponse');
        onResponse(js[orElements[i].attr(handler)], onResponseAttribute);
    }
    check();
}

$(document).ready(function() {
    update('handler');
    clickHandler();
});