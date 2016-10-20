<!DOCTYPE html>
<html lang="fr">
<head>

  <title>Hercome</title>
  <meta charset="utf-8">  
  <link rel="stylesheet" href="style.css">
  <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
<link rel="icon" type="image/png" href="favicon.png" />
   <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
          <!-- Appelle du script de base jQuery -->
<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
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
<script>
$( document ).ready(function() {
    // DOM ready

    // Test data
    /*
     * To test the script you should discomment the function
     * testLocalStorageData and refresh the page. The function
     * will load some test data and the loadProfile
     * will do the changes in the UI
     */
    // testLocalStorageData();
    // Load profile if it exits
    loadProfile();
});

/**
 * Function that gets the data of the profile in case
 * thar it has already saved in localstorage. Only the
 * UI will be update in case that all data is available
 *
 * A not existing key in localstorage return null
 *
 */
function getLocalProfile(callback){
    var profileImgSrc      = localStorage.getItem("PROFILE_IMG_SRC");
    var profileName        = localStorage.getItem("PROFILE_NAME");
    var profileReAuthEmail = localStorage.getItem("PROFILE_REAUTH_EMAIL");

    if(profileName !== null
            && profileReAuthEmail !== null
            && profileImgSrc !== null) {
        callback(profileImgSrc, profileName, profileReAuthEmail);
    }
}

/**
 * Main function that load the profile if exists
 * in localstorage
 */
function loadProfile() {
    if(!supportsHTML5Storage()) { return false; }
    // we have to provide to the callback the basic
    // information to set the profile
    getLocalProfile(function(profileImgSrc, profileName, profileReAuthEmail) {
        //changes in the UI
        $("#profile-img").attr("src",profileImgSrc);
        $("#profile-name").html(profileName);
        $("#reauth-email").html(profileReAuthEmail);
        $("#inputEmail").hide();
        $("#remember").hide();
    });
}

/**
 * function that checks if the browser supports HTML5
 * local storage
 *
 * @returns {boolean}
 */
function supportsHTML5Storage() {
    try {
        return 'localStorage' in window && window['localStorage'] !== null;
    } catch (e) {
        return false;
    }
}

/**
 * Test data. This data will be safe by the web app
 * in the first successful login of a auth user.
 * To Test the scripts, delete the localstorage data
 * and comment this call.
 *
 * @returns {boolean}
 */
function testLocalStorageData() {
    if(!supportsHTML5Storage()) { return false; }
    localStorage.setItem("PROFILE_IMG_SRC", "//lh3.googleusercontent.com/-6V8xOA6M7BA/AAAAAAAAAAI/AAAAAAAAAAA/rzlHcD0KYwo/photo.jpg?sz=120" );
    localStorage.setItem("PROFILE_NAME", "César Izquierdo Tello");
    localStorage.setItem("PROFILE_REAUTH_EMAIL", "oneaccount@gmail.com");
}
</script>
</head>

<body>

<!-- MENU SITE WEB --> 

    <?php 
	include("menu.php"); 
	?> 
  <!-- PAGE PRINCIPALE --> 
 
 
<div class="mainpage">

<div id="partie0" class="logo-pageprincipal">
	<div id="popo" >
		<img  src="logo4.png" class="logo4" />
	</div>

	<div class="banner" style="background-image: linear-gradient(-225deg, rgba(0,101,168,0.6) 0%, rgba(0,36,61,0.6) 50%), url('background.jpg');">
	  <div class="banner-content">
		  <h1>Notre devoir , votre bien être au quotidien</h1>
		  <a href="#partie2" class="js-scrollTo"><img href="#partie1" src="arrow.png" class="banner-arrow" /></a>  
	  </div>
	</div>
 </div>

<div id="partie2" class="logo-pageprincipal">

	<table id="#section1">
		<tr>
			<th class="bleue"><img  src="group.png" class="logo4" /></th>
			<th class="black"><a href="#partie0" class="js-scrollTo"><img style=" -webkit-transform: rotate(180deg); margin-bottom:1px; " href="#partie0" src="arrow.png" class="banner-arrow" /></a>  </th>
		</tr>

	</table>
</div>

</div>
      
</body>

</html>

