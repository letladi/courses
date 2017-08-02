var locate = function() {  
	navigator.geolocation.getCurrentPosition(function(pos) {
		const { latitude, longitude } = pos.coords
		console.log('got the location', latitude, longitude)
		// display the map
		const mapURL = `https://www.google.com/maps/@?api=1&map_action=map&query=${latitude},${longitude}`
		window.location = mapURL
	}, function(err) {
		console.log('an error ocurred')
		const $errorDisplay = document.querySelector('#error')
		$errorDisplay.innerHTML = err.toString()
	}, {
  enableHighAccuracy: true,
  timeout: 5000,
  maximumAge: 0
})


};
