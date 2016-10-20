<!DOCTYPE html>
<html lang="fr">
<head>

  <title>Hercome</title>
  <meta charset="utf-8">  
  <link rel="stylesheet" href="style.css">
  <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
          <!-- Appelle du script de base jQuery -->
<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
 <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
<script type="text/javascript">
$(document).ready(function() {

    // effet fondu en entrée à l'ouverture de la page
    $('#popo').fadeIn(3000);

    // effet fondu en sortie de la page entière par un clique sur un bouton
    $('#le-bouton-à-cliquer').click(function(event) {
    event.preventDefault();
    newLocation = this.href;
    $('body').fadeOut(1200, newpage);
    });
    function newpage() {
    window.location = newLocation;
    }
});
</script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script>
  $(document).ready(function() {
    $('.js-scrollTo').on('click', function() { // Au clic sur un élément
      var page = $(this).attr('href'); // Page cible
      var speed = 750; // Durée de l'animation (en ms)
      $('html, body').animate( { scrollTop: $(page).offset().top }, speed ); // Go
      return false;
    });
  });
</script>

</head>

<body>

<!-- MENU SITE WEB --> 

    <?php 
	include("menu.php"); 
	?> 
  <!-- PAGE PRINCIPALE --> 
 


      
</body>

</html>

