import 'https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js'

$(() =>
{
	$('.search_bar').keyup(function ()
	{
		const result = $(this).val();

		if (result != '')
		{
			$.ajax({
				url:      "/scripts_php/livesearch.php",
				method:   "post",
				data:     {query: result},
				dataType: "text",

				success: (data) =>
				{
					$('.search_results').html(data).show();
				}
			});
		}
		else
		{
			$('.search_results').hide().html('');
		}
	});
});


