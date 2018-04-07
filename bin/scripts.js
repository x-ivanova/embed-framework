/*$('#button').click(function(){
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

$('#checkbox').on('change', function(){ 
        $.ajax({
        url: 'http://0.0.0.0:8080/check/',
        type: 'GET',
        success: function(results) { 
            if (results == 0) {
                $('#resp-check').html('False');
            } else {
                $('#resp-check').html('True');
            }
            
        }
    });
    
})

$('#text').click(function(){
    $.ajax({
        url: 'http://0.0.0.0:8080/text/',
        type: 'GET',
        success: function(results) { 
            $('#resp-text').html(results);
        }
    });
}); */

// $(document).ready(function() {
//     $('[clickhandler]').each(function() {
//         var test = $('[clickhandler]').attr("clickhandler");

//         $('[clickhandler]').click(function() {
//             var url = 'http://0.0.0.0:8080/make/?count=' + test;
//             $("#resp-numb").text(test);
//             $.ajax({
//                 url: url,
//                 type: 'GET',
//                 success: function(results) {
//                     $('#resp-text').html(results);
//                 }
//             });
//         });
//     });
// });

function getAllElementsWithAttribute(attribute)
{
  var matchingElements = [];
  var allElements = document.getElementsByTagName('button');
  for (var i = 0, n = allElements.length; i < n; i++)
  {
    if (allElements[i].getAttribute(attribute) !== null)
    {
      matchingElements.push(allElements[i]);
    }
  }
  return matchingElements;
}


$(document).ready(function() {
    $.ajax({
        url: 'http://0.0.0.0:8080/get/',
        type: 'GET',
        success: function(results) { 
            $('#resp-numb').html(results);
            $('#reset').attr("clickhandler",-results);
        }
    });
    mas = getAllElementsWithAttribute('clickHandler');

    for(var i = 0; i < mas.length; i++){
        var something = mas[i].getAttribute('clickHandler');
        var k = [];
        k[i] = '[clickHandler="' + something + '"]';
        console.log(something, k[i]);
        $(k[i]).click(function(x){
            return function (){
            $.ajax({
                url: 'http://0.0.0.0:8080/make/?count=' + mas[x].getAttribute('clickHandler'),
                type: 'GET',
                success: function(results) { 
                    $('#resp-numb').html(results);
                }
            });
        };
    }(i));

    }
});
