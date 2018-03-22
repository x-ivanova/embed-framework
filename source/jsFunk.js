$('#button').click(function(){
    $.ajax({
        url: 'http://0.0.0.0:8080/make/',
        type: 'GET',
        success: function(results) { 
            $('#resp-numb').html(results);
        }
    });
});

$(document).ready(function(){
	$.ajax({
        url: 'http://0.0.0.0:8080/get/',
        type: 'GET',
        success: function(results) { 
            $('#resp-numb').html(results);
        }
    });
});